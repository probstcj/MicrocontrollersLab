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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
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
        0x0F
    };
    struct FRAM ram = {
        0x01,
        0x02,
        0x03,
        0x04,
        0x05,
        0x06
    };
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    I2C_Start();
//    // Turning on accel and setting settings
    uint8 wrBuf[2];
//    wrBuf[1] = 0x00 | (0x00 | 0x00 | 0x20 | 0x10 | 0x00 | 0x02);
//    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
//    // Set timer
//    uint8 count = 10;
//    wrBuf[1] = count;
//    writeToAddr(wrBuf, 2, accelAddr, accel.WakeupTimer);
//    // Set threshold
//    uint8 threshold = 2;
//    wrBuf[1] = threshold*16;
//    writeToAddr(wrBuf, 2, accelAddr, accel.WakeupThreshold);
    
    wrBuf[1] = 0x00 | (0x80 | 0x00 | 0x20 | 0x10 | 0x00 | 0x02);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
    wrBuf[1] = 0x00 | (0x04);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg2);
    wrBuf[1] = 0x00 | (0x01);
    writeToAddr(wrBuf, 2, accelAddr, accel.DataCtrlReg);
    
    
    
    for(;;)
    {
        /* Place your application code here. */
//        float accelVals[3];
//        readAccel(accelVals, accel);
//        volatile float x = accelVals[0];
//        volatile float y = accelVals[1];
//        volatile float z = accelVals[2];
        volatile int thing2 = 20;
        CySysPmDeepSleep();
        if(accelFlag){
            volatile int thing = 20;
        }
       
    }
}

/* [] END OF FILE */
