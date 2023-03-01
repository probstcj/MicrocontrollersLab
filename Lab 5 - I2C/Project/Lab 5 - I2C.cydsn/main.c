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

struct accelerometer{
    uint32 XOUT_L;
    uint32 XOUT_H;
    uint32 YOUT_L;
    uint32 YOUT_H;
    uint32 ZOUT_L;
    uint32 ZOUT_H;
    uint32 CtrlReg1;
    uint32 CtrlReg2;
    uint32 DataCtrlReg;
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
        0x21,
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
    // Turning on accel and setting settings
    uint8 wrBuf[2];
    wrBuf[1] = 0x00 | (0x80 | 0x00 | 0x20 | 0x10 | 0x00 | 0x02);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg1);
    wrBuf[1] = 0x00 | (0x04);
    writeToAddr(wrBuf, 2, accelAddr, accel.CtrlReg2);
    wrBuf[1] = 0x00 | (0x01);
    writeToAddr(wrBuf, 2, accelAddr, accel.DataCtrlReg);
    
    
    // Writing address
    uint8 rdBuf[4];
    readFromAddr(rdBuf, 1, accelAddr, accel.CtrlReg1);
    volatile uint8 test = rdBuf[0];
    
    
    for(;;)
    {
        /* Place your application code here. */
       
    }
}

/* [] END OF FILE */
