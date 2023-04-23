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

struct MTR{
    unsigned int position : 4;
};
struct MTR motor = {1};
int motorDelay = 5000;
uint32 feedSteps = 500;

// Function for moving clockwise
int MVCW(struct MTR motor){
    // If motor is at edge, reset, if not, decrement
    if(motor.position <= 1){
        motor.position = 4;
    }
    else{
        motor.position -= 1;
    }
    // Write correct motor position
    switch(motor.position){
        case 4:
            // 1100 -> 1001
            Motor_Write(0x9);
            break;
        case 3:
            // 1001 -> 0011
            Motor_Write(0x3);
            break;
        case 2:
            // 0011 -> 0110
            Motor_Write(0x6);
            break;
        case 1:
            // 0110 -> 1100
            Motor_Write(0xC);
            break;
    }
    // Delay
    CyDelayUs(motorDelay);
    // Ground so motor doesn't get hot
    //Motor_Write(0b0000);
    // Return motor position
    return motor.position;
}

struct Time{
    uint8 hour;
    uint8 minute;
    uint8* AM;
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
struct FRAM{
    uint32 feedCounter;
    uint32 speakerToggle;
    uint32 LEDToggle;
    uint32 timesToFeed;
    
    uint32 feedStepsP1;
    uint32 feedStepsP2;
    uint32 feedStepsP3;
    uint32 feedStepsP4;
    
    uint32 feedTime1P1;
    uint32 feedTime1P2;
    uint32 feedTime1P3;
    
    uint32 feedTime2P1;
    uint32 feedTime2P2;
    uint32 feedTime2P3;
    
    uint32 feedTime3P1;
    uint32 feedTime3P2;
    uint32 feedTime3P3;
    
    uint32 feedTime4P1;
    uint32 feedTime4P2;
    uint32 feedTime4P3;
    
    uint32 feedTime5P1;
    uint32 feedTime5P2;
    uint32 feedTime5P3;
    
    uint32 feedTime6P1;
    uint32 feedTime6P2;
    uint32 feedTime6P3;
    
    uint32 feedTime7P1;
    uint32 feedTime7P2;
    uint32 feedTime7P3;
    
    uint32 feedTime8P1;
    uint32 feedTime8P2;
    uint32 feedTime8P3;
    
    uint32 feedTime9P1;
    uint32 feedTime9P2;
    uint32 feedTime9P3;
    
    uint32 feedTime10P1;
    uint32 feedTime10P2;
    uint32 feedTime10P3;
};

const struct FRAM ram = {
    0x00,
    0x02,
    0x04,
    0x06,
    
    0x08,0x0A,0x0C,0x0E,
    
    0x10,0x12,0x14,
    
    0x16,0x18,0x1A,
    
    0x1C,0x1E,0x20,
    
    0x22,0x24,0x26,
    
    0x28,0x2A,0x2C,
    
    0x2E,0x30,0x32,
    
    0x34,0x36,0x38,
    
    0x3A,0x3C,0x3E,
    
    0x40,0x42,0x44,
    
    0x46,0x48,0x4A
};

char* commands[6] = {
    "Set Global Time     ",
    "Change Feed Times   ",
    "Change Feed Amount  ",
    "Turn on/off LED's   ",
    "Turn on/off Speakers",
    "Exit                "
};
// Feed times
    // Amount of food
    // LED's
    // Speakers
    // Exit

const uint32 LCDAddr = 0x27;
const uint32 RTCAddr = 0x51;
const uint32 ramAddr = 0x52;

uint8 feedCounter = 0;
uint8 speakerToggle = 1;
uint8 LEDToggle = 1;

volatile uint8 buttonFlag = 0;
volatile uint8 encFlag = 0;
volatile uint8 encPos = 0;

uint8 timesToFeed = 0;
/*
This function simply reads from any I2C device.
readBuf will be the size of readBytes and any read data will be stored here..
readBytes is the number of bytes that the I2C is reading.
devAddr is the I2C address that the microcontroller is talking to.
memAddr is the memory or register address that is inside the I2C device.
*/
uint8 bcdToDec(uint8 value)
{
  return (uint8)((value / 16) * 10 + value % 16);
}

uint8 decToBcd(uint8 value){
  return (value / 10 * 16 + value % 10);
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

void saveToFRAM(){
    uint8 wrBuf[3];
    wrBuf[2] = feedCounter;
    writeToRam(wrBuf, 2, ramAddr,0x00,ram.feedCounter);
    wrBuf[2] = speakerToggle;
    writeToRam(wrBuf, 2, ramAddr,0x00,ram.speakerToggle);
    wrBuf[2] = LEDToggle;
    writeToRam(wrBuf, 2, ramAddr,0x00,ram.LEDToggle);
    wrBuf[2] = timesToFeed;
    writeToRam(wrBuf, 2, ramAddr,0x00,ram.timesToFeed);
    
    // 0010 1010 1010 1010
    // 1100 1110 1100 1011 (if divide by 256, you get first byte)
    // 1100 1110 1100 1011 1100 0101
}

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
    wrBuf[1] = 0x44;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Minutes);
    wrBuf[1] = 0x10;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Hours);
    wrBuf[1] = 0x16;
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
void exitLCD(){
    char printString[21];
    struct Time nextTime = feedTimes[feedCounter];
    uint8 day[1];
    readFromAddr(day,1,RTCAddr,rtc.Days);
    uint8 month[1];
    readFromAddr(month,1,RTCAddr,rtc.Century_Months);
    uint8 year[1];
    readFromAddr(year,1,RTCAddr,rtc.Years);
    struct Date nextDate = {bcdToDec(day[0]),months[bcdToDec(month[0])-1],bcdToDec(year[0])};
    setCursor(0,1);
    LCD_print("--------------------");
    setCursor(0,2);
    LCD_print("Time of Next Feed:  ");
    setCursor(0,3);
    snprintf(printString, 21, "%d:%.2d%s %s %d, 20%d ",nextTime.hour, nextTime.minute,nextTime.AM, nextDate.month,nextDate.day, nextDate.year);
    printString[20] = '\0';
    LCD_print(printString);
}
void FEEEEED(){
    for(int i = 0; i < feedSteps; i++){
        motor.position = MVCW(motor);
        
    }
    Motor_Write(0b0000);
    
    LED_PWM_WritePeriod(1000);
    LED_PWM_WriteCompare(1000);
    SPEAKER_PWM_Start();
    SPEAKER_PWM_WritePeriod(750);
    SPEAKER_PWM_WriteCompare(50);
    SPEAKER_PWM_Stop();
    for(int k = 0; k<8; k++){
        if(speakerToggle == 1){
            SPEAKER_PWM_Start();
        }
        if(LEDToggle == 1){
            LED_PWM_Start();
        }
        for(int i = 0; i<100; i++){
            for(int j = 0; j < 4; j++){
                LED_SEL_Write(j);
                CyDelay(1);
            }
        }
        LED_PWM_Stop();
        SPEAKER_PWM_Stop();
        CyDelay(300);
    }
}
void setGlobalTime(){
    clear();
    setCursor(0,0);
    LCD_print("Set Month");
    char printMessage[21];
    struct Time nextTime = feedTimes[feedCounter];
    uint8 day[1];
    readFromAddr(day,1,RTCAddr,rtc.Days);
    uint8 month[1];
    readFromAddr(month,1,RTCAddr,rtc.Century_Months);
    uint8 year[1];
    readFromAddr(year,1,RTCAddr,rtc.Years);
    struct Date currDate = {bcdToDec(day[0]),months[bcdToDec(month[0])-1],bcdToDec(year[0])};
    struct Date setDate;
    int currentIndex = bcdToDec(month[0])-1;
    setCursor(0,2);
    snprintf(printMessage,21,"%s %d, 20%d",currDate.month,currDate.day,currDate.year);
    LCD_print(printMessage);
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(currentIndex == 12){
                    currentIndex = 1;
                }
                else{
                    currentIndex++;
                }
            }
            else if(encPos == 2){
                if(currentIndex == 1){
                    currentIndex = 12;
                }
                else{
                    currentIndex--;
                }
            }
            setCursor(0,2);
            LCD_print(months[currentIndex-1]);
        }
    }
    uint8 numberMonth = currentIndex;
    setDate.month = months[currentIndex-1];
    buttonFlag = 0;
    setCursor(0,0);
    LCD_print("Set Day  ");
    currentIndex = currDate.day;
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(currentIndex == 31){
                    currentIndex = 1;
                }
                else{
                    currentIndex++;
                }
            }
            else if(encPos == 2){
                if(currentIndex == 1){
                    currentIndex = 31;
                }
                else{
                    currentIndex--;
                }
            }
            setCursor(4,2);
            char printDay[3];
            snprintf(printDay,3,"%02d",currentIndex);
            LCD_print(printDay);
        }
    }
    buttonFlag = 0;
    
    setDate.day = currentIndex;
    buttonFlag = 0;
    setCursor(0,0);
    LCD_print("Set Year");
    currentIndex = currDate.year;
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(currentIndex == 99){
                    currentIndex = 0;
                }
                else{
                    currentIndex++;
                }
            }
            else if(encPos == 2){
                if(currentIndex == 0){
                    currentIndex = 99;
                }
                else{
                    currentIndex--;
                }
            }
            setCursor(8,2);
            char printYear[5];
            snprintf(printYear,5,"20%02d",currentIndex);
            LCD_print(printYear);
        }
    }
    buttonFlag = 0;
    setDate.year = currentIndex;
    
    uint8 min[1];
    readFromAddr(min,1,RTCAddr,rtc.Minutes);
    uint8 hour[1];
    readFromAddr(hour,1,RTCAddr,rtc.Hours);
    struct Time updateTime;
    struct Time setTime;
    if(hour[0] > 0x12){
            volatile struct Time currTime = {bcdToDec(hour[0])-12,bcdToDec(min[0]),"PM"};
            updateTime = currTime;
        }
        else{
            volatile struct Time currTime = {bcdToDec(hour[0]),bcdToDec(min[0]),"AM"};
            updateTime = currTime;
    }
    setCursor(0,0);
    LCD_print("Set Hour");
    setCursor(0,2);
    snprintf(printMessage,21,"%d:%.2d%s        ",updateTime.hour,updateTime.minute,updateTime.AM);
    LCD_print(printMessage);
    currentIndex = updateTime.hour;
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(currentIndex == 12){
                    currentIndex = 1;
                }
                else{
                    currentIndex++;
                }
            }
            else if(encPos == 2){
                if(currentIndex == 1){
                    currentIndex = 12;
                }
                else{
                    currentIndex--;
                }
            }
            setCursor(0,2);
            char printHour[3];
            snprintf(printHour,3,"%02d",currentIndex);
            LCD_print(printHour);
            
        }
    }
    
    setTime.hour = currentIndex;
    buttonFlag = 0;
    setCursor(0,0);
    LCD_print("Set Minute");
    currentIndex = updateTime.minute;
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(currentIndex == 59){
                    currentIndex = 0;
                }
                else{
                    currentIndex++;
                }
            }
            else if(encPos == 2){
                if(currentIndex == 0){
                    currentIndex = 59;
                }
                else{
                    currentIndex--;
                }
            }
            setCursor(3,2);
            char printMinute[3];
            snprintf(printMinute,5,"%02d",currentIndex);
            LCD_print(printMinute);
        }
    }
    
    setTime.minute = currentIndex;
    buttonFlag = 0;
    setCursor(0,0);
    LCD_print("Set AM/PM    ");
    currentIndex = 0;
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(currentIndex == 0){
                currentIndex = 1;
            }
            else{
                currentIndex = 0;
            }
            setCursor(5,2);
            if(currentIndex == 0){
                LCD_print("AM");
            }
            else{
                LCD_print("PM");
            }
        }
    }
    buttonFlag = 0;
    if(currentIndex == 0){
        
    }
    else{
        setTime.hour = setTime.hour + 12;
    }
    
    uint8 wrBuf[2];
    wrBuf[1] = 0x00;
    writeToAddr(wrBuf,2,RTCAddr,rtc.VL_Sec);
    wrBuf[1] = decToBcd(setTime.minute);
    writeToAddr(wrBuf,2,RTCAddr,rtc.Minutes);
    wrBuf[1] = decToBcd(setTime.hour);
    writeToAddr(wrBuf,2,RTCAddr,rtc.Hours);
    wrBuf[1] = decToBcd(setDate.day);
    writeToAddr(wrBuf,2,RTCAddr,rtc.Days);
    wrBuf[1] = 0x06;
    writeToAddr(wrBuf,2,RTCAddr,rtc.Weekdays);
    wrBuf[1] = decToBcd(numberMonth);
    writeToAddr(wrBuf,2,RTCAddr,rtc.Century_Months);
    wrBuf[1] = decToBcd(setDate.year);
    writeToAddr(wrBuf,2,RTCAddr,rtc.Years);
    exitLCD();
    
}
void setFeedTimes(){
    clear();
    timesToFeed=0;
    setCursor(0,0);
    LCD_print("Set amount of times");
    setCursor(0,1);
    LCD_print("to feed");
    setCursor(0,2);
    char message[21];
    snprintf(message,21,"Number of feeds: %d",timesToFeed);
    message[20] = '\0';
    LCD_print(message);
    
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(timesToFeed == 10){
                    clear();
                    setCursor(0,0);
                    LCD_print("Your cat doesn't");
                    setCursor(0,1);
                    LCD_print("need to be fed more");
                    setCursor(0,2);
                    LCD_print("than 10 times.");
                    CyDelay(2000);
                    clear();
                    setCursor(0,0);
                    LCD_print("Set amount of times");
                    setCursor(0,1);
                    LCD_print("to feed");
                    setCursor(0,2);
                    snprintf(message,21,"Number of feeds: %d",timesToFeed);
                    message[20] = '\0';
                    LCD_print(message);
                }
                else{
                    timesToFeed++;
                }
            }
            else if(encPos == 2){
                if(timesToFeed == 0){
                }
                else{
                    timesToFeed--;
                }
            }
            setCursor(0,2);
            snprintf(message,21,"Number of feeds: %d ",timesToFeed);
            message[20] = '\0';
            LCD_print(message);
        }
    }
    buttonFlag = 0;
    clear();
    for(int i = 0; i < timesToFeed; i++){
        setCursor(0,0);
        snprintf(message,21,"Feed #%d",i+1);
        LCD_print(message);
        uint8 min[1];
        readFromAddr(min,1,RTCAddr,rtc.Minutes);
        uint8 hour[1];
        uint8 currentIndex = 0;
        readFromAddr(hour,1,RTCAddr,rtc.Hours);
        struct Time updateTime;
        struct Time setTime;
        if(hour[0] > 0x12){
                volatile struct Time currTime = {bcdToDec(hour[0])-12,bcdToDec(min[0]),"PM"};
                updateTime = currTime;
            }
            else{
                volatile struct Time currTime = {bcdToDec(hour[0]),bcdToDec(min[0]),"AM"};
                updateTime = currTime;
        }
        setCursor(0,1);
        LCD_print("Set Hour   ");
        setCursor(0,2);
        snprintf(message,21,"%02d:%02d%s        ",updateTime.hour,updateTime.minute,updateTime.AM);
        LCD_print(message);
        currentIndex = updateTime.hour;
        while(buttonFlag == 0){
            if(encFlag == 1){
                encFlag = 0;
                if(encPos == 1){
                    if(currentIndex == 12){
                        currentIndex = 1;
                    }
                    else{
                        currentIndex++;
                    }
                }
                else if(encPos == 2){
                    if(currentIndex == 1){
                        currentIndex = 12;
                    }
                    else{
                        currentIndex--;
                    }
                }
                setCursor(0,2);
                char printHour[21];
                snprintf(printHour,21,"%02d:%02d%s        ",currentIndex,updateTime.minute,updateTime.AM);
                LCD_print(printHour);
                
            }
        }
        
        setTime.hour = currentIndex;
        buttonFlag = 0;
        setCursor(0,1);
        LCD_print("Set Minute");
        currentIndex = updateTime.minute;
        while(buttonFlag == 0){
            if(encFlag == 1){
                encFlag = 0;
                if(encPos == 1){
                    if(currentIndex == 59){
                        currentIndex = 0;
                    }
                    else{
                        currentIndex++;
                    }
                }
                else if(encPos == 2){
                    if(currentIndex == 0){
                        currentIndex = 59;
                    }
                    else{
                        currentIndex--;
                    }
                }
                setCursor(0,2);
                char printMinute[21];
                snprintf(printMinute,21,"%02d:%02d%s        ",setTime.hour,currentIndex,updateTime.AM);
                LCD_print(printMinute);
            }
        }
        
        setTime.minute = currentIndex;
        buttonFlag = 0;
        setCursor(0,1);
        LCD_print("Set AM/PM    ");
        currentIndex = 0;
        while(buttonFlag == 0){
            if(encFlag == 1){
                encFlag = 0;
                if(currentIndex == 0){
                    currentIndex = 1;
                }
                else{
                    currentIndex = 0;
                }
                setCursor(5,2);
                if(currentIndex == 0){
                    LCD_print("AM");
                }
                else{
                    LCD_print("PM");
                }
            }
        }
        buttonFlag = 0;
        if(currentIndex == 0){
            setTime.AM = "PM";
        }
        else if(currentIndex == 1){
            setTime.AM = "AM";
        }
        feedTimes[i] = setTime;
    }
    exitLCD();
}
void setAmountOfFood(){
    clear();
    setCursor(0,0);
    LCD_print("Hold button to");
    setCursor(0,1);
    LCD_print("adjust amount of");
    setCursor(0,2);
    LCD_print("food. Release when");
    setCursor(0,3);
    LCD_print("satisfied.");
    while(buttonFlag == 0){}
    feedSteps = 0;
    buttonFlag = 0;
    while(BTN_Read() == 1){
        feedSteps++;
        motor.position = MVCW(motor);
    }
    
    Motor_Write(0b0000);
    buttonFlag = 0;
    exitLCD();
}
void toggleLEDs(){
    clear();
    setCursor(0,0);
    LCD_print("Turn knob to toggle");
    setCursor(0,2);
    if(LEDToggle == 0){
        LCD_print("Off");
    }
    else{
        LCD_print("On");
    }
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(LEDToggle == 0){
                   LEDToggle = 1;
                }
                else{
                    LEDToggle = 0;
                }
            }
            else if(encPos == 2){
                if(LEDToggle == 0){
                    LEDToggle = 1;
                }
                else{
                    LEDToggle = 0;
                }
            }
        }
        setCursor(0,2);
        if(LEDToggle == 0){
            LCD_print("Off");
        }
        else{
            LCD_print("On ");
        }
    }
    buttonFlag = 0;
    exitLCD();
}
void toggleSpeakers(){
    clear();
    setCursor(0,0);
    LCD_print("Turn knob to toggle");
    setCursor(0,2);
    if(speakerToggle == 0){
        LCD_print("Off");
    }
    else{
        LCD_print("On");
    }
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(speakerToggle == 0){
                   speakerToggle = 1;
                }
                else{
                    speakerToggle = 0;
                }
            }
            else if(encPos == 2){
                if(speakerToggle == 0){
                    speakerToggle = 1;
                }
                else{
                    speakerToggle = 0;
                }
            }
        }
        setCursor(0,2);
        if(speakerToggle == 0){
            LCD_print("Off");
        }
        else{
            LCD_print("On ");
        }
    }
    buttonFlag = 0;
    exitLCD();
}


void startSettings(){
    clear();
    uint8 choice = 0;
    setCursor(0,0);
    LCD_print("Button = Select");
    setCursor(0,1);
    LCD_print("Knob = Choice");
    setCursor(0,2);
    LCD_print("--------------------");
    // Clock Time
    setCursor(0,3);
    LCD_print("Set Global Time");
    CyDelay(1000);
    while(buttonFlag == 0){
        if(encFlag == 1){
            encFlag = 0;
            if(encPos == 1){
                if(choice == 5){
                    choice = 0;
                }
                else{
                    choice++;
                }
            }
            else if(encPos == 2){
                if(choice == 0){
                    choice = 5;
                }
                else{
                    choice--;
                }
            }
        }
        setCursor(0,3);
        LCD_print(commands[choice]);
    }
    buttonFlag = 0;
    switch(choice){
        case 0:
            setGlobalTime();
            break;
        case 1:
            setFeedTimes();
            break;
        case 2:
            setAmountOfFood();
            break;
        case 3:
            toggleLEDs();
            break;
        case 4:
            toggleSpeakers();
            break;
        case 5:
            // Done
            exitLCD();
            break;
        default:
            choice = 0;
            break;
    }
    return;
    // Feed times
    // Amount of food
    // LED's
    // Speakers
    // Exit
}



int main(void)
{
    BTN_ISR_Start();
    ENC_ISR_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_Start();
    LiquidCrystal_I2C_init(LCDAddr, 20,4,0);
    LCDBegin();
    //FEEEEED();
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
        if(hour[0] > 0x12){
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
            }
        }
        else if(feedCounter == 2){
            feedCounter = 0;
        }
        if(buttonFlag == 1){
            buttonFlag = 0;
            startSettings();
        }
        CyDelay(1000);
        
        //CySysPmDeepSleep();
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
