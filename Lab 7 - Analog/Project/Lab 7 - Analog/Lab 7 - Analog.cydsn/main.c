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
    char mess[16];
    Vout = out * (2.048/4095);
    // (Vout - V0)/Tc = Ta
    return (Vout - .400)/(.0195);
}

float convertCtoF(float C){
    return (9/((float)5))*C + 32;
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
        getTempValue();
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
