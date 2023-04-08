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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_Start();
    IDAC_Start();
    UART_Start();
    ADC_StartConvert();
    char message[32];
    for(int i = 0x00; i < 0xFF; i++){
        IDAC_SetValue(i);
        CyDelay(10);
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        snprintf(message, 32, "%d,%d\n",i,ADC_GetResult16(0));
        message[31] = '\0';
        UART_UartPutString(message);
    }
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
