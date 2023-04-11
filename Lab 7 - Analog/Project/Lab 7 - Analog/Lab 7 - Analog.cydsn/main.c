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

// Global variables for stuff
uint8 mode = 0;
volatile int buttonFlag;

/*
This function simply initializes temperature readings. 

Init mate?
*/
void tempInit/*Mate*/(){
    // Set 6:4 to 100 and 7 to 1
    ADC_SAR_CTRL_REG = (ADC_SAR_CTRL_REG & 0xFFFFFF0F) | 0x000000C0;
    // Set input to 0
    //ADC_SetChanMask(0x0000);
}
/*
This function simply initializes voltage readings. 

Init mate?
*/
void potInit/*Mate*/(){
    // Set 6:4 to 100 and 7 to 1
    //ADC_Stop();
    ADC_SAR_CTRL_REG = (ADC_SAR_CTRL_REG & 0xFFFFFF0F) | 0x000000E0;
    //ADC_Start();
    // Set input to 0
    //ADC_SetChanMask(0x0001);
}
/*
This function gets the temperature value from the ADC.

It returns the value in degrees celsius
*/
float getTempValue(){
    // Variable for voltage
    float Vout;
    // Starts the conversion in the ADC
    ADC_StartConvert();
    // Wait for ADC to stop
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    // Get result from channel 0
    int out = ADC_GetResult16(0);
    // Stop the ADC, saves power
    ADC_StopConvert();
    // Convert digital to voltage
    Vout = out * (2.048/4095);
    
    // (Vout - V0)/Tc = Ta
    return (Vout - .400)/(.0195);
}
/*
This converts value in celsius to value in farenheit

Returns value in farenheit
*/
float convertCtoF(float C){
    return (9/((float)5))*C + 32;
}
/*
This function selects the LED based on the temperature.

Blue for 75°F and under
Green for 75°F-80°F
Yellow for 80°F-85°F
Red for 85°F-212°F

Duty cycle goes linearly between these values.
*/
void selectTempLED(float temp){
    PWM_WritePeriod(1000);
    if(temp < 75.0){
        PWM_WriteCompare((int)((temp/75.0) * 1000));
        LED_SEL_Write(2);
    } else if(temp < 80.0) {
        PWM_WriteCompare((int)((temp-75.0)/(5.0) * 1000));
        LED_SEL_Write(1);
    } else if(temp < 85.0) {
        PWM_WriteCompare((int)((temp-80.0)/(5.0) * 1000));
        LED_SEL_Write(3);
    } else if(temp < 212.0) {
        PWM_WriteCompare((int)((temp-85.0)/(127.0) * 1000));
        LED_SEL_Write(0);
    }
}
/*
This function selects the LED based on the voltage.

Blue for 0.8V and under
Green for 0.8V-1.6V
Yellow for 1.6V-2.4V
Red for 2.4V-3.3V

Duty cycle goes linearly between these values.
*/
void selectVoltageLED(float voltage){
     PWM_WritePeriod(1000);
    if(voltage < 0.8){
        PWM_WriteCompare((int)((voltage/0.8) * 1000));
        LED_SEL_Write(2);
    } else if(voltage < 1.6) {
        PWM_WriteCompare((int)((voltage-0.8)/(0.8) * 1000));
        LED_SEL_Write(1);
    } else if(voltage < 2.4) {
        PWM_WriteCompare((int)((voltage-1.6)/(0.8) * 1000));
        LED_SEL_Write(3);
    } else if(voltage < 3.3) {
        PWM_WriteCompare((int)((voltage-2.4)/(0.9) * 1000));
        LED_SEL_Write(0);
    }
}
/*
This function gets the voltage value from the ADC.

It returns the value in volts
*/
float getVoltage(){
    // Variable for voltage
    float Vout;
    // Starts the conversion in the ADC
    ADC_StartConvert();
    // Wait for ADC to stop
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    // Get result from channel 1
    int out = ADC_GetResult16(1);
    // Stop the ADC, saves power
    ADC_StopConvert();
    // Converts digital value to voltage
    Vout = out * (3.3/4095);
    return Vout;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_Start();
    BTN_ISR_Start();
    LCD_Start();
    PWM_Start();
    
    tempInit/*Mate*/();
    for(;;)
    { 
        // Check for button interrupt
        if(buttonFlag == 1){
            // Clear flag
            buttonFlag = 0;
            // Change mode
            if(mode == 1){
                mode = 0;
                tempInit();
                CyDelay(100);
            } else {
                mode = 1;
                potInit();
                CyDelay(100);
            }
        }
        // Temperature mode
        if(mode ==  0){
            // Delay for refresh rate
            CyDelay(100);
            float temp = getTempValue();
            // Variables for LCD prints
            char topLine[16];
            char bottomLine[16];
            // Format the output
            snprintf(topLine, 16, "Temp: %.2f %cC", temp, 223);
            snprintf(bottomLine, 16, "      %.2f %cF",convertCtoF(temp), 223);
            // Clear display and print lines
            LCD_ClearDisplay();
            LCD_PrintString(topLine);
            LCD_Position(1,0);
            LCD_PrintString(bottomLine);
            // Select LED
            selectTempLED(convertCtoF(temp));
        }
        // Voltage mode
        else {
            // Refresh rate for LCD
            CyDelay(100);
            float voltage = getVoltage();
            // Variable for LCD printing
            char topLine[16];
            // Format print
            snprintf(topLine, 16, "Voltage: %.2f V", voltage);
            // Clear display, print string
            LCD_ClearDisplay();
            LCD_PrintString(topLine);
            // Select LED for voltage
            selectVoltageLED(voltage);
        }
        
       
    }
}

/* [] END OF FILE */
