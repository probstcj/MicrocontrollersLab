/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

static const uint32 accelAddr = 0x0F;
static const uint32 ramLowerAddr = 0x50;
static const uint32 ramUpperAddr = 0x51;
volatile int accelFlag = 0;

struct accelerometer{
    uint32 XOUT_L;
    uint32 XOUT_H;
    uint32 YOUT_L;
    uint32 YOUT_H;
    uint32 ZOUT_L;
    uint32 ZOUT_H;
    uint32 CtrlReg1;
    uint32 CtrlReg2;
    uint32 IntSrc2;
    uint32 IntRel;
    uint32 DataCtrlReg;
    uint32 WakeupThreshold;
    uint32 WakeupTimer;
    uint32 IntCtrlReg1;
    uint32 IntCtrlReg2;
    uint32 Test;
};
struct FRAM{
    uint32 XPOS;
    uint32 XNEG;
    uint32 YPOS;
    uint32 YNEG;
    uint32 ZPOS;
    uint32 ZNEG;
};

void readFromAddr(uint8* readBuf, int readBytes, uint32 devAddr, uint32 memAddr){
    uint8 wrBuf[1];
    wrBuf[0] = memAddr;
    I2C_I2CMasterWriteBuf(devAddr, wrBuf, 1, I2C_I2C_MODE_NO_STOP);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
    
    I2C_I2CMasterReadBuf(devAddr, readBuf, readBytes, I2C_I2C_MODE_REPEAT_START);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT));
    I2C_I2CMasterClearStatus();
    
}
void writeToAddr(uint8* writeBuf, int writeBytes, uint32 devAddr, uint32 memAddr){
    writeBuf[0] = memAddr;
    I2C_I2CMasterWriteBuf(devAddr, writeBuf, writeBytes, I2C_I2C_MODE_COMPLETE_XFER);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
}
void readFromRam(uint8* readBuf, int readBytes, uint32 devAddr, uint32 memAddr1, uint32 memAddr2){
    uint8 wrBuf[2];
    wrBuf[0] = memAddr1;
    wrBuf[1] = memAddr2;
    I2C_I2CMasterWriteBuf(devAddr, wrBuf, 2, I2C_I2C_MODE_NO_STOP);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
    
    I2C_I2CMasterReadBuf(devAddr, readBuf, readBytes, I2C_I2C_MODE_REPEAT_START);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT));
    I2C_I2CMasterClearStatus();
    
}
void writeToRam(uint8* writeBuf, int writeBytes, uint32 devAddr, uint32 memAddr1, uint32 memAddr2){
    writeBuf[0] = memAddr1;
    writeBuf[1] = memAddr2;
    I2C_I2CMasterWriteBuf(devAddr, writeBuf, writeBytes, I2C_I2C_MODE_COMPLETE_XFER);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
}
void clearRam(){
    uint8 wrBuf[8] = {0x12, 0x34};
    for(int i = 2; i > 8; i++){
        wrBuf[i] = 0x00; 
    }
    I2C_I2CMasterWriteBuf(ramLowerAddr, wrBuf, 8, I2C_I2C_MODE_COMPLETE_XFER);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
}

void readAccel(float* accelValues, struct accelerometer accel){
        uint8 rdBuf[4];
        readFromAddr(rdBuf, 1, accelAddr, accel.ZOUT_H);
        int8 z_hi = (int8)rdBuf[0];
        readFromAddr(rdBuf, 1, accelAddr, accel.ZOUT_L);
        int8 z_lo = (int8)rdBuf[0];
        accelValues[2] = (float)((float)8/((float)2048))*((z_hi*16) + (z_lo / 16));
        readFromAddr(rdBuf, 1, accelAddr, accel.XOUT_H);
        int8 x_hi = (int8)rdBuf[0];
        readFromAddr(rdBuf, 1, accelAddr, accel.XOUT_L);
        int8 x_lo = (int8)rdBuf[0];
        accelValues[0] = (float)((float)8/((float)2048))*((x_hi*16) + (x_lo / 16));
        readFromAddr(rdBuf, 1, accelAddr, accel.YOUT_H);
        int8 y_hi = (int8)rdBuf[0];
        readFromAddr(rdBuf, 1, accelAddr, accel.YOUT_L);
        int8 y_lo = (int8)rdBuf[0];
        accelValues[1] = (float)((float)8/((float)2048))*((y_hi*16) + (y_lo / 16));
}
void readAccelFram(uint8* read, struct FRAM ram){
    uint8 rdBuf[1];
    readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.XNEG);
    read[0] = rdBuf[0];
    readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.XPOS);
    read[1] = rdBuf[0];
    readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.YNEG);
    read[2] = rdBuf[0];
    readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.YPOS);
    read[3] = rdBuf[0];
    readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.ZNEG);
    read[4] = rdBuf[0];
    readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.ZPOS);
    read[5] = rdBuf[0];
}
int main(void)
{
    struct accelerometer accel = {
        0x06,
        0x07,
        0x08,
        0x09,
        0x0A,
        0x0B,
        0x1B,
        0x1D,
        0x17,
        0x1A,
        0x21,
        0x6A,
        0x29,
        0x1E,
        0x1F,
        0x0F
    };
    struct FRAM ram = {
        0x34,
        0x35,
        0x36,
        0x37,
        0x38,
        0x39
    };
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    I2C_Start();
//    // Turning on accel and setting settings
    uint8 wrBuf[2];
    wrBuf[1] = 0x00 | (0x00 | 0x40 | 0x20 | 0x10 | 0x00 | 0x02);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
//    // Set timer
    uint8 count = 10;
    wrBuf[1] = count;
    writeToAddr(wrBuf, 2, accelAddr, accel.WakeupTimer);
//    // Set threshold
    uint8 threshold = 4;
    wrBuf[1] = threshold*16;
    writeToAddr(wrBuf, 2, accelAddr, accel.WakeupThreshold);
    wrBuf[1] = 0x00 | (0x04);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg2);
    wrBuf[1] = 0x00 | (0x20 | 0x10 | 0x08 | 0x04 | 0x02 | 0x01);
    writeToAddr(wrBuf, 2, accelAddr, accel.IntCtrlReg2);
    wrBuf[1] = 0x00 | (0x20);
    writeToAddr(wrBuf, 2, accelAddr, accel.IntCtrlReg1);
    
    wrBuf[1] = 0x00 | (0x80 | 0x00 | 0x20 | 0x10 | 0x00 | 0x02);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
    wrBuf[1] = 0x00 | (0x01);
    writeToAddr(wrBuf, 2, accelAddr, accel.DataCtrlReg);
    
    volatile uint8 reg[6];
    uint8 rdBuf[1];
    readFromAddr(rdBuf, 1, accelAddr, accel.WakeupTimer);
    reg[0] = rdBuf[0];
    readFromAddr(rdBuf, 1, accelAddr, accel.CtrlReg1);
    reg[1] = rdBuf[0];
    readFromAddr(rdBuf, 1, accelAddr, accel.WakeupThreshold);
    reg[2] = rdBuf[0];
    readFromAddr(rdBuf, 1, accelAddr, accel.CtrlReg2);
    reg[3] = rdBuf[0];
    readFromAddr(rdBuf, 1, accelAddr, accel.DataCtrlReg);
    reg[4] = rdBuf[0];
    readFromAddr(rdBuf, 1, accelAddr, accel.IntCtrlReg1);
    reg[5] = rdBuf[0];
    
    CyDelay(12);
    readFromAddr(rdBuf, 1, accelAddr, accel.IntRel);
    CyDelay(12);
    
    // FRAM
    volatile uint8 read[6];
    uint8 wrBuf2[3];
    readAccelFram(read, ram);
    wrBuf2[2] = 0x90;
    writeToRam(wrBuf2, 3, ramLowerAddr, 0x12, ram.XNEG);
    //clearRam();
    readAccelFram(read, ram);
    
    ACCEL_ISR_Start();
    for(;;)
    {
        /* Place your application code here. */
        float accelVals[3];
        readAccel(accelVals, accel);
        volatile float x = accelVals[0];
        volatile float y = accelVals[1];
        volatile float z = accelVals[2];
        volatile int thing2 = 20;
        //CySysPmDeepSleep();
        if(accelFlag){
            accelFlag = 0;
            readAccel(accelVals, accel);
            volatile float x = accelVals[0];
            volatile float y = accelVals[1];
            volatile float z = accelVals[2];
        }
        readFromAddr(rdBuf, 1, accelAddr, accel.IntRel);
    }
}

/* [] END OF FILE */
