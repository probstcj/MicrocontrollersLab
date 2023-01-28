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

volatile int barSync;
volatile int buttonAsync;
volatile int encoderAsync;
volatile int encoderPos;
int movingDirection;


int drawMovingBar(int position){
    if(movingDirection == 0){
        position++;
    }
    else{
        position--;
    }
    LCD_DrawHorizontalBG(1,0,16,position);
    if(position == 80 || position == 0){
        if(movingDirection == 0){
            movingDirection = 1;
        }
        else{
            movingDirection = 0;
        }
    }
    return position;
}
int main(void)
{

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Start modules and timers
    LCD_Start();
    ENC_ISR_Start();
    BTN_ISR_Start();
    LCD_Timer_Start();
    LCD_Timer_ISR_Start();
    LCD_Timer_WritePeriod(12);
    barSync = 0;
    
    buttonAsync = 0;
    movingDirection = 0;
    int barPos = 0;
    int barMove = 0;
    encoderAsync = 0;
    encoderPos = 0;
    CyGlobalIntEnable;
    for(;;)
    {
        
        /* Place your application code here. */
        
        if(barSync == 1){
            barSync = 0;
            if(barMove != 1){
             //   barPos = drawMovingBar(barPos);
            }
            //LCD_DrawHorizontalBG(1,0,16,80);
            //LCD_ClearDisplay();
            //CyDelay(1000);
            //LCD_ClearDisplay();
        }
        else if(buttonAsync == 1){
            buttonAsync = 0;
            if(barMove == 0){
                barMove = 1;
            }
            else{
                barMove = 0;
            }
            while(BTN_Read() == 0);
        }
        else if(encoderAsync == 1){
            encoderAsync = 0; // resetting the flag
//            LCD_PrintNumber(encoderPos);
            
        }
        else{
           
            //CySysPmSleep();
        }
    }
}

/* [] END OF FILE */
