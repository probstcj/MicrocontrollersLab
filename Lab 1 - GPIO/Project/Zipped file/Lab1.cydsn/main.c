#include "project.h"
int printChar(char print, int lengthOfDisplay){
    if(lengthOfDisplay == 16){
        lengthOfDisplay = 0;
        LCD_ClearDisplay();
    }
    LCD_WriteData(print);
    lengthOfDisplay++;
    return lengthOfDisplay;
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int x = 0;
    int lengthOfDisplay = 0;
    LCD_Start();
    LCD_ClearDisplay();
    
    
    for(;;)
    {
        // Check for press - polling
        while(C0_Read() == 0 && C1_Read() == 0 && C2_Read() == 0 && C3_Read() == 0){
            switch(x){
                case 0:
                    R3_Write(0);
                    R0_Write(1);
                    x++;
                    break;
                case 1:
                    R0_Write(0);
                    R1_Write(1);
                    x++;
                    break;
                case 2:
                    R1_Write(0);
                    R2_Write(1);
                    x++;
                    break;
                case 3:
                    R2_Write(0);
                    R3_Write(1);
                    x=0;
                    break;
            }
        } // Breakout of polling loop after a keypad press
        
        
        // Delay for debouncing
        CyDelay(10);
        
        
        // Print whatever key is pressed, checking column by column.
        if(C0_Read() == 1){
            switch(x){
                case 1:
                    // Print 1 (0,0)
                    lengthOfDisplay = printChar('1', lengthOfDisplay);
                    break;
                case 2:
                    // Print 4 (1,0)
                    lengthOfDisplay = printChar('4',lengthOfDisplay);
                    break;
                case 3:
                    // Print 7 (2,0)
                    lengthOfDisplay = printChar('7',lengthOfDisplay);
                    break;
                case 0:
                    // Print * (3,0)
                    lengthOfDisplay = printChar('*',lengthOfDisplay);
                    break;
            }
        }
        else if(C1_Read() == 1){
            switch(x){
                case 1:
                    // Print 2 (0,1)
                    lengthOfDisplay = printChar('2',lengthOfDisplay);
                    break;
                case 2:
                    // Print 5 (1,1)
                    lengthOfDisplay = printChar('5',lengthOfDisplay);
                    break;
                case 3:
                    // Print 8 (2,1)
                    lengthOfDisplay = printChar('8',lengthOfDisplay);
                    break;
                case 0:
                    // Print 0 (3,1)
                    lengthOfDisplay = printChar('0',lengthOfDisplay);
                    break;
            }
        }
        else if(C2_Read() == 1){
            switch(x){
                case 1:
                    // Print 3 (0,2)
                    lengthOfDisplay = printChar('3',lengthOfDisplay);
                    break;
                case 2:
                    // Print 6 (1,2)
                    lengthOfDisplay = printChar('6',lengthOfDisplay);
                    break;
                case 3:
                    // Print 9 (2,2)
                    lengthOfDisplay = printChar('9',lengthOfDisplay);
                    break;
                case 0:
                    // Print # (3,2)
                    lengthOfDisplay = printChar('#',lengthOfDisplay);
                    break;
            }
        }
        else if(C3_Read() == 1){
            switch(x){
                case 1:
                    // Print A (0,3)
                    lengthOfDisplay = printChar('A',lengthOfDisplay);
                    break;
                case 2:
                    // Print B (1,3)
                    lengthOfDisplay = printChar('B',lengthOfDisplay);
                    break;
                case 3:
                    // Print C (2,3)
                    lengthOfDisplay = printChar('C',lengthOfDisplay);
                    break;
                case 0:
                    // Print D (3,3)
                    lengthOfDisplay = printChar('D',lengthOfDisplay);
                    break;
            }
        }
        // Check for release - polling
        while(C0_Read() == 1 || C1_Read() == 1 || C2_Read() == 1 || C3_Read() == 1);
        // Restart the infinite for loop
    }
}

/* [] END OF FILE */
