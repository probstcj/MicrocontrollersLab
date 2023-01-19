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
int printChar(char print, int length){
    if(length == 16){
        length = 0;
        LCD_ClearDisplay();
    }
    LCD_WriteData(print);
    length++;
    return length;
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int x = 0;
    int length = 0;
    LCD_Start();
    LCD_ClearDisplay();
    for(;;)
    {
        // Works
        // Polling Process
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
        }
        // End Polling
        // Delay
        CyDelay(10);
        // Do whatever
        if(C0_Read() == 1){
            switch(x){
                case 1:
                    // Print 1 (0,0)
                    length = printChar('1', length);
                    break;
                case 2:
                    // Print 4 (0,1)
                    length = printChar('4',length);
                    break;
                case 3:
                    // Print 7 (0,2)
                    length = printChar('7',length);
                    break;
                case 0:
                    // Print * (0,3)
                    length = printChar('*',length);
                    break;
            }
        }
        else if(C1_Read() == 1){
            switch(x){
                case 1:
                    // Print 2 (1,0)
                    length = printChar('2',length);
                    break;
                case 2:
                    // Print 5 (1,1)
                    length = printChar('5',length);
                    break;
                case 3:
                    // Print 8 (1,2)
                    length = printChar('8',length);
                    break;
                case 0:
                    // Print 0 (1,3)
                    length = printChar('0',length);
                    break;
            }
        }
        else if(C2_Read() == 1){
            switch(x){
                case 1:
                    // Print 3 (2,0)
                    length = printChar('3',length);
                    break;
                case 2:
                    // Print 6 (2,1)
                    length = printChar('6',length);
                    break;
                case 3:
                    // Print 9 (2,2)
                    length = printChar('9',length);
                    break;
                case 0:
                    // Print # (2,3)
                    length = printChar('#',length);
                    break;
            }
        }
        else if(C3_Read() == 1){
            switch(x){
                case 1:
                    // Print A (3,0)
                    length = printChar('A',length);
                    break;
                case 2:
                    // Print B (3,1)
                    length = printChar('B',length);
                    break;
                case 3:
                    // Print C (3,2)
                    length = printChar('C',length);
                    break;
                case 0:
                    // Print D (3,3)
                    length = printChar('D',length);
                    break;
            }
        }
        // Check for release
        while(C0_Read() == 1 || C1_Read() == 1 || C2_Read() == 1 || C3_Read() == 1);
        // Restart
    }
}

/* [] END OF FILE */
