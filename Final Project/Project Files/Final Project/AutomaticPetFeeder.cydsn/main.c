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
    uint8 year;
};
struct RTC{
    uint8 CtrlStat1;
    uint8 CtrlStat2;
    uint8 VL_Sec;
    uint8 Minutes;
    uint8 Hours;
    uint8 Days;
    uint8 Weekdays;
    uint8 Century_Months;
    uint8 Years;
    uint8 MinuteAlarm;
    uint8 HourAlarm;
    uint8 DayAlarm;
    uint8 WeekdayAlarm;
    uint8 CLKOUTControl;
    uint8 TimerControl;
    uint8 Timer;
};

struct RTC rtc = {
    0x00, //CtrlStat1
    0x01, //CtrlStat2
    0x02, //VL_Sec
    0x03, //Minutes
    0x04, //Hours
    0x05, //Days
    0x06, //Weekdays
    0x07, //Century_Months
    0x08, //Years
    0x09, //MinuteAlarm
    0x0A, //HourAlarm
    0x0B, //DayAlarm
    0x0C, //WeekdayAlarm
    0x0D, //CLKOUTControl
    0x0E, //TimerControl
    0x0F //Timer
};

const char* months[12] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"
};

struct Time feedTimes[10] = {
    {4,25,"PM"},
    {4,26,"PM"},
    {5,5,"PM"}
};


const uint32 LCDAddr = 0x27;
const uint32 RTCAddr = 0x51;
uint8 feedCounter = 0;
/*
This function simply reads from any I2C device.
readBuf will be the size of readBytes and any read data will be stored here..
readBytes is the number of bytes that the I2C is reading.
devAddr is the I2C address that the microcontroller is talking to.
memAddr is the memory or register address that is inside the I2C device.
*/
void readFromAddr(uint8* readBuf, int readBytes, uint32 devAddr, uint32 memAddr){
    // First write the memory address to the I2C bus.
    uint8 wrBuf[1];
    wrBuf[0] = memAddr;
    I2C_I2CMasterWriteBuf(devAddr, wrBuf, 1, I2C_I2C_MODE_NO_STOP);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
    I2C_I2CMasterClearStatus();

    // Then read the output from the I2C bus from that memory address.
    I2C_I2CMasterReadBuf(devAddr, readBuf, readBytes, I2C_I2C_MODE_REPEAT_START);
    while(!(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT));
    I2C_I2CMasterClearStatus();
}
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

void RTCInit(){
    uint8 wrBuf[2];
    wrBuf[1] = 0x00;
    writeToAddr(wrBuf,2,RTCAddr,rtc.VL_Sec);
    wrBuf[1] = 0x37;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Minutes);
    wrBuf[1] = 0x21;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Hours);
    wrBuf[1] = 0x09;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Days);
    wrBuf[1] = 0x06;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Weekdays);
    wrBuf[1] = 0x04;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Century_Months);
    wrBuf[1] = 0x23;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Years);
}

void LCDInit(struct Time currTime, struct Time nextTime, struct Date currDate, struct Date nextDate){
    // First line time
    setCursor(0,0);
    char printString[21];
    snprintf(printString, 21, "%d:%.2d%s %s %d, 20%d ",currTime.hour, currTime.minute,currTime.AM, currDate.month,currDate.day, currDate.year);
    printString[20] = '\0';
    LCD_print(printString);
    setCursor(0,1);
    LCD_print("--------------------");
    setCursor(0,2);
    LCD_print("Time of Next Feed:");
    setCursor(0,3);
    snprintf(printString, 21, "%d:%.2d%s %s %d, 20%d ",nextTime.hour, nextTime.minute,nextTime.AM, nextDate.month,nextDate.day, nextDate.year);
    printString[20] = '\0';
    LCD_print(printString);
}

void updateNextFeed(struct Time nextTime, struct Date nextDate){
    char printString[21];
    setCursor(0,2);
    LCD_print("Time of Next Feed:");
    setCursor(0,3);
    snprintf(printString, 21, "%d:%.2d%s %s %d, 20%d ",nextTime.hour, nextTime.minute,nextTime.AM, nextDate.month,nextDate.day, nextDate.year);
    printString[20] = '\0';
    LCD_print(printString);
}

void updateCurrTime(struct Time currTime, struct Date currDate){
    setCursor(0,0);
    char printString[21];
    snprintf(printString, 21, "%d:%.2d%s %s %d, 20%d ",currTime.hour, currTime.minute,currTime.AM, currDate.month,currDate.day, currDate.year);
    printString[20] = '\0';
    LCD_print(printString);
    setCursor(0,1);
}

void FEEEEED(){
    // Turn on motor
    // Set LED's
    // Set speakers
}


uint8 bcdToDec(uint8 value)
{
  return (uint8)((value / 16) * 10 + value % 16);
}

uint8 decToBcd(uint8 value){
  return (value / 10 * 16 + value % 10);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_Start();
    LiquidCrystal_I2C_init(LCDAddr, 20,4,0);
    LCDBegin();
    struct Time time = {12,45, "AM"};
    struct Date date = {31, "Mar",23};
    struct Time nextTime = {6,00, "PM"};
    struct Date nextDate = {1, "Apr", 23};
    LCDInit(time, nextTime, date, nextDate);
    uint8 wrBuf[2];
    wrBuf[1] = 0b0000000;
    writeToAddr(wrBuf,2,RTCAddr,rtc.CtrlStat1);
    wrBuf[1] = 0b0000000;
    writeToAddr(wrBuf,2,RTCAddr,rtc.CtrlStat2);
    //RTCInit();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        struct Time updateTime;
        
        uint8 sec[1];
        readFromAddr(sec,1,RTCAddr,rtc.VL_Sec);
        uint8 min[1];
        readFromAddr(min,1,RTCAddr,rtc.Minutes);
        uint8 hour[1];
        readFromAddr(hour,1,RTCAddr,rtc.Hours);
        uint8 day[1];
        readFromAddr(day,1,RTCAddr,rtc.Days);
        uint8 month[1];
        readFromAddr(month,1,RTCAddr,rtc.Century_Months);
        uint8 year[1];
        readFromAddr(year,1,RTCAddr,rtc.Years);
        if(hour[0] > 12){
            volatile struct Time currTime = {bcdToDec(hour[0])-12,bcdToDec(min[0]),"PM"};
            updateTime = currTime;
        }
        else{
            volatile struct Time currTime = {bcdToDec(hour[0]),bcdToDec(min[0]),"AM"};
            updateTime = currTime;
        }
        
        struct Date updateDate = {bcdToDec(day[0]),months[bcdToDec(month[0])-1],bcdToDec(year[0])};
        updateCurrTime(updateTime, updateDate);
        if(updateTime.hour == feedTimes[feedCounter].hour && updateTime.minute == feedTimes[feedCounter].minute && updateTime.AM == feedTimes[feedCounter].AM){
            if(feedCounter == 2 || strncmp(feedTimes[feedCounter+1].AM,"AM",2) != 0 || strncmp(feedTimes[feedCounter+1].AM,"AM",2) != 0){
                feedCounter++;
                updateNextFeed(feedTimes[feedCounter],updateDate);
                FEEEEED();
                volatile int a = 0;
            }
        }
        else if(feedCounter == 2){
            feedCounter = 0;
        }
        CyDelay(1000);
        
        //CySysPmDeepSleep();
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
