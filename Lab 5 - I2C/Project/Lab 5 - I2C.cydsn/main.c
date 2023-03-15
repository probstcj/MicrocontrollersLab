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
volatile int buttonFlag = 0;

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
    uint32 Xint;
    uint32 Yint;
    uint32 Zint;
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
    uint8 wrBuf[3] = {0x00,0x00,0x00};
    
    I2C_I2CMasterWriteBuf(ramLowerAddr, wrBuf, 3, I2C_I2C_MODE_NO_STOP);
    
    for (int i = 3; i < 65537; i++){
        CyDelayUs(100);
        if(i%10000 == 0){
            LED_B_Write(1);
            LED_G_Write(1);
            LED_R_Write(0);
        }
        else if(i%10000 == 1000){
            LED_R_Write(1);
            LED_B_Write(1);
            LED_G_Write(0);
        }
        else if(i%10000 == 100){
            LED_G_Write(1);
            LED_R_Write(1);
            LED_B_Write(0);
        }
        uint8 wrBuf[1] = {0x00};
         I2C_I2CMasterWriteBuf(ramLowerAddr, wrBuf, 1, I2C_I2C_MODE_NO_STOP);
    }
    LED_R_Write(1);
    LED_G_Write(1);
    LED_B_Write(1);
    uint8 wrBuf2[1] = {0x00};
    I2C_I2CMasterWriteBuf(ramLowerAddr, wrBuf2, 1, I2C_I2C_MODE_REPEAT_START);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
    for(int i = 0; i < 6; i++){
        if(i%2 == 0){
            LED_R_Write(0);
            LED_G_Write(0);
            LED_B_Write(0);
        }
        else{
            LED_R_Write(1);
            LED_G_Write(1);
            LED_B_Write(1);
        }
        CyDelay(1000);
    }
}

//void readAccel(float* accelValues, struct accelerometer accel){
//        uint8 rdBuf[4];
//        readFromAddr(rdBuf, 1, accelAddr, accel.ZOUT_H);
//        int8 z_hi = (int8)rdBuf[0];
//        readFromAddr(rdBuf, 1, accelAddr, accel.ZOUT_L);
//        int8 z_lo = (int8)rdBuf[0];
//        accelValues[2] = (float)((float)8/((float)2048))*((z_hi*16) + (z_lo / 16));
//        readFromAddr(rdBuf, 1, accelAddr, accel.XOUT_H);
//        int8 x_hi = (int8)rdBuf[0];
//        readFromAddr(rdBuf, 1, accelAddr, accel.XOUT_L);
//        int8 x_lo = (int8)rdBuf[0];
//        accelValues[0] = (float)((float)8/((float)2048))*((x_hi*16) + (x_lo / 16));
//        readFromAddr(rdBuf, 1, accelAddr, accel.YOUT_H);
//        int8 y_hi = (int8)rdBuf[0];
//        readFromAddr(rdBuf, 1, accelAddr, accel.YOUT_L);
//        int8 y_lo = (int8)rdBuf[0];
//        accelValues[1] = (float)((float)8/((float)2048))*((y_hi*16) + (y_lo / 16));
//}
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
        0x36,
        0x38
    };
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    I2C_Start();
    LED_R_Write(1);
    LED_B_Write(1);
    LED_G_Write(1);
//    // Turning on accel and setting settings
    uint8 wrBuf[2];
    wrBuf[1] = 0x00 | (0x00 | 0x40 | 0x20 | 0x10 | 0x00 | 0x02);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
//    // Set timer
    uint8 count = 10;
    wrBuf[1] = count;
    writeToAddr(wrBuf, 2, accelAddr, accel.WakeupTimer);
//    // Set threshold
    uint8 threshold = 3;
    wrBuf[1] = threshold*16;
    writeToAddr(wrBuf, 2, accelAddr, accel.WakeupThreshold);
    wrBuf[1] = 0x00 | (0x04);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg2);
    wrBuf[1] = 0x00 | (0x20 | 0x10 | 0x08 | 0x04 | 0x02 | 0x01);
    writeToAddr(wrBuf, 2, accelAddr, accel.IntCtrlReg2);
    wrBuf[1] = 0x00 | (0x20 | 0x10);
    writeToAddr(wrBuf, 2, accelAddr, accel.IntCtrlReg1);
    
    wrBuf[1] = 0x00 | (0x80 | 0x00 | 0x00 | 0x10 | 0x00 | 0x02);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
    wrBuf[1] = 0x00 | (0x01);
    writeToAddr(wrBuf, 2, accelAddr, accel.DataCtrlReg);
    uint8 rdBuf[1];
    
    CyDelay(12);
    readFromAddr(rdBuf, 1, accelAddr, accel.IntRel);
    CyDelay(12);
    
    ACCEL_ISR_Start();
    TEST_ISR_Start();
    TEST_ISR_Enable();
    
    for(;;)
    {
        /* Place your application code here. */
        
        CySysPmDeepSleep();
        if(accelFlag){
            accelFlag = 0;
            uint8 rdBuf[1];
            readFromAddr(rdBuf, 1, accelAddr, accel.IntSrc2);
            uint8 reg = rdBuf[0];
            // Check for x
            if(reg&(0x10) || reg&(0x20)){
                uint8 wrBuf[3];
                wrBuf[2] = 0xFF;
                writeToRam(wrBuf,3, ramLowerAddr, 0x12, ram.Xint);
            }
            // Check for y
            if(reg&(0x08) || reg&(0x04)){
                uint8 wrBuf[3];
                wrBuf[2] = 0xFF;
                writeToRam(wrBuf,3, ramLowerAddr, 0x12, ram.Yint);
            }
            // Check for z
            if(reg&(0x02) || reg&(0x01)){
                uint8 wrBuf[3];
                wrBuf[2] = 0xFF;
                writeToRam(wrBuf,3, ramLowerAddr, 0x12, ram.Zint);
            }
            // Clear reg
            readFromAddr(rdBuf, 1, accelAddr, accel.IntRel);
        }
        if(buttonFlag == 2){
            LED_R_Write(0);
            LED_G_Write(0);
            LED_B_Write(0);
            while(TEST_Read() == 0);
            LED_R_Write(1);
            LED_G_Write(1);
            LED_B_Write(1);
            buttonFlag = 0;
            clearRam();
        }
        if(buttonFlag == 1){
            buttonFlag = 0;
            uint8 rdBuf[1];
            readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.Xint);
            uint8 xint = rdBuf[0];
            readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.Yint);
            uint8 yint = rdBuf[0];
            readFromRam(rdBuf, 1, ramLowerAddr, 0x12, ram.Zint);
            uint8 zint = rdBuf[0];
            if(xint == 0xFF){
                LED_R_Write(0);
                CyDelay(1000);
                LED_R_Write(1);
            }
            if(yint == 0xFF){
                LED_G_Write(0);
                CyDelay(1000);
                LED_G_Write(1);
            }
            if(zint == 0xFF){
                LED_B_Write(0);
                CyDelay(1000);
                LED_B_Write(1);
            }
            xint = 0;
            yint = 0;
            zint = 0;
        }
    }
}

/* [] END OF FILE */
