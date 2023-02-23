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

// Interrupt flags and other variables needed
volatile int barSync;
volatile int buttonAsync;
volatile int encoderAsync;
volatile int encoderPos;
int movingDirection;

ENC_1;
int drawMovingBar(int position){
    // This will draw the moving bar that is based on the synchronous timer
    // Checks which direction it is moving in 0 = right, 1 = left
    if(movingDirection == 0){
        position++;
    }
    else{
        position--;
    }
    // Draw bar
    LCD_DrawHorizontalBG(1,0,16,position);
    // Checks position of bar, changes moving direction if needed
    if(position == 80 || position == 0){
        if(movingDirection == 0){
            movingDirection = 1;
        }
        else{
            movingDirection = 0;
        }
    }
    // Returns position to update in main
    return position;
}

void drawMovableBar(){
    // Draws bar based on encoder position, same as last
    LCD_DrawHorizontalBG(0,0,16,encoderPos);
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
    /*
    Write period of timer, we picked 12 because our timer frequency was
    1 KHz, so this would make the bar move one position every 12ms.
    The reason we wanted 12 ms, was because it goes 80 positions
    which is approximately 1 second to get to one side of the LCD.
    */
    LCD_Timer_WritePeriod(12);
    // Setting global variables to initial positions
    barSync = 0;
    buttonAsync = 0;
    movingDirection = 0;
    encoderAsync = 0;
    encoderPos = 0;
    // Set local variables for main
    int barPos = 0;
    int barMove = 1;
    // Enable interrupts
    CyGlobalIntEnable;
    // Print initial message on LCD (40x2 LCD)
    LCD_PrintString("Turn the dial,                          press button");
    for(;;)
    {
        /* Place your application code here. */
        // Synchronous timer for moving bar
        if(barSync == 1){
            // Reset flag
            barSync = 0;
            // Move bar forward if bar is supposed to be moving
            if(barMove != 1){
                barPos = drawMovingBar(barPos);
            }
        }
        // Asynchronous button interrupt for stopping bar
        if(buttonAsync == 1){
            // Reset flag
            buttonAsync = 0;
            // If bar is supposed to be moving, stop bar and decide
            if(barMove == 0){
                // Stop bar
                barMove = 1;
                // Clear display and print both bars
                LCD_ClearDisplay();
                barPos = drawMovingBar(barPos);
                drawMovableBar();
                // Half second delay in between bar print and string print
                CyDelay(500);
                // Clear display and print top bar and string
                LCD_ClearDisplay();
                drawMovableBar();
                // Decide if win or not
                if(barPos == encoderPos){
                    // Win
                    LCD_PrintString("                        Congratulations!");
                }
                else{
                    // Lose
                    LCD_PrintString("                        You suck!!!!!!!!");
                }
            }
            else{
                // If bar is not moving, start bar moving
                barMove = 0;
            }
            // Debounce button
            while(BTN_Read() != 0);
        }
        // Asynchronous encoder interrupt
        if(encoderAsync == 1){
            // Reset flag            
            encoderAsync = 0;
            // Draw bar
            drawMovableBar();
        }
    }
}

/* [] END OF FILE */
