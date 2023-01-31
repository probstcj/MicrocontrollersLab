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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int ix = 0;
    for(;;)
    {
        /* Place your application code here. */
        LED_B_Write(0);
        LED_R_Write(1);
        LED_G_Write(1);
        for(ix = 0; ix < 3000000; ix++);
        LED_B_Write(1);
        LED_G_Write(1);
        LED_R_Write(1);
        for(ix = 0; ix < 3000000; ix++);
        LED_R_Write(0);
        LED_G_Write(1);
        LED_B_Write(1);
        for(ix = 0; ix < 3000000; ix++);
        LED_B_Write(1);
        LED_G_Write(1);
        LED_R_Write(1);
        for(ix = 0; ix < 3000000; ix++);
        LED_G_Write(0);
        LED_B_Write(1);
        LED_R_Write(1);
        for(ix = 0; ix < 3000000; ix++);
        LED_B_Write(1);
        LED_G_Write(1);
        LED_R_Write(1);
        for(ix = 0; ix < 3000000; ix++);
    }
}

/* [] END OF FILE */
