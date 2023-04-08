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
#include <stdio.h>
#include "LiquidCrystal_I2C.h"

struct Time{
    uint8 hour;
    uint8 minute;
    char* AM;
};

struct Date{
    uint8 day;
    char* month;
    uint32 year;
};

const uint32 LCDAddr = 0x27;

/*
This function simply writes to any I2C device.
writeBuf will be the size of writeBytes and any data inside here will be written to the I2C bus.
writeBytes is the number of bytes written to the I2C bus.
    NOTE: The first byte of the writeBuf will be overwritten if it is stored, as it is the memory address being written. Make sure to start at 1 for the array and to add 1 to writeBytes to adjust for this.
devAddr is the I2C address that the microcontroller is talking to.
memAddr is the memory or register address that is inside the I2C device.
*/
void writeToAddr(uint8* writeBuf, int writeBytes, uint32 devAddr, uint32 memAddr){
    // Store the first byte as the memory address we are writing to.
    writeBuf[0] = memAddr;

    // Write the data to the device.
    I2C_I2CMasterWriteBuf(devAddr, writeBuf, writeBytes, I2C_I2C_MODE_COMPLETE_XFER);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();
}

void LCDInit(struct Time currTime, struct Time nextTime, struct Date currDate, struct Date nextDate){
    // First line time
    setCursor(0,0);
    char printString[21];
    snprintf(printString, 21, "%d:%.2d%s %s %d, %lu",currTime.hour, currTime.minute,currTime.AM, currDate.month,currDate.day, currDate.year);
    printString[20] = '\0';
    LCD_print(printString);
    setCursor(0,1);
    LCD_print("--------------------");
    setCursor(0,2);
    LCD_print("Time of Next Feed:");
    setCursor(0,3);
    snprintf(printString, 21, "%d:%.2d%s %s %d, %lu",nextTime.hour, nextTime.minute,nextTime.AM, nextDate.month,nextDate.day, nextDate.year);
    printString[20] = '\0';
    LCD_print(printString);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_Start();
    LiquidCrystal_I2C_init(LCDAddr, 20,4,0);
    LCDBegin();
    struct Time time = {12,45, "AM"};
    struct Date date = {31, "Mar",2023};
    struct Time nextTime = {6,00, "PM"};
    struct Date nextDate = {1, "Apr", 2023};
    LCDInit(time, nextTime, date, nextDate);
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        //CySysPmDeepSleep();
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
