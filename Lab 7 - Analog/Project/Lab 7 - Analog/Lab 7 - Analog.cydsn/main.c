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

uint8 mode = 0;
volatile int buttonFlag;


void tempInit/*Mate*/(){
    // Set 6:4 to 100 and 7 to 1
    ADC_SAR_CTRL_REG = (ADC_SAR_CTRL_REG | 0xC0);
    // Set input to 0
    //ADC_SetChanMask(0x0000);
}

void potInit/*Mate*/(){
    // Set 6:4 to 100 and 7 to 1
    ADC_SAR_CTRL_REG = (ADC_SAR_CTRL_REG | 0xE0);
    // Set input to 0
    //ADC_SetChanMask(0x0001);
}

float getTempValue(){
    float Vout;
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    int out = ADC_GetResult16(0);
    ADC_StopConvert();
    Vout = out * (2.048/4095);
    // (Vout - V0)/Tc = Ta
    return (Vout - .400)/(.0195);
}

float convertCtoF(float C){
    return (9/((float)5))*C + 32;
}

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

float getVoltage(){
    float Vout;
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    int out = ADC_GetResult16(1);
    ADC_StopConvert();
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
        if(buttonFlag == 1){
            buttonFlag = 0;
            if(mode == 1){
                mode = 0;
            } else {
                mode = 1;
            }
        }
        if(mode ==  0){
            tempInit();
            CyDelay(100);
            float temp = getTempValue();
            char topLine[16];
            char bottomLine[16];
            snprintf(topLine, 16, "Temp: %.2f %cC", temp, 223);
            snprintf(bottomLine, 16, "      %.2f %cF",convertCtoF(temp), 223);
            LCD_ClearDisplay();
            LCD_PrintString(topLine);
            LCD_Position(1,0);
            LCD_PrintString(bottomLine);
            selectTempLED(convertCtoF(temp));
        } else {
            potInit();
            CyDelay(100);
            float voltage = getVoltage();
            char topLine[16];
            snprintf(topLine, 16, "Voltage: %.2f V", voltage);
            LCD_ClearDisplay();
            LCD_PrintString(topLine);
            selectVoltageLED(voltage);
        }
        
       
    }
}

/* [] END OF FILE */
