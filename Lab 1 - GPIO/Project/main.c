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
                    // 0, 0 (Print 1)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('1');
                    length++;
                    break;
                case 2:
                    // 0, 1 (Print 4)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('4');
                    length++;
                    break;
                case 3:
                    // 0, 2 (Print 7)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('7');
                    length++;
                    break;
                case 0:
                    // 0, 3 (Print *)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('*');
                    length++;
                    break;
            }
        }
        else if(C1_Read() == 1){
            switch(x){
                case 1:
                    // 1, 0 (Print 2)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('2');
                    length++;
                    break;
                case 2:
                    // 1, 1 (Print 5)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('5');
                    length++;
                    break;
                case 3:
                    // 1, 2 (Print 8)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('8');
                    length++;
                    break;
                case 0:
                    // 1, 3 (Print 0)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('0');
                    length++;
                    break;
            }
        }
        else if(C2_Read() == 1){
            switch(x){
                case 1:
                    // 2, 0 (Print 3)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('3');
                    length++;
                    break;
                case 2:
                    // 2, 1 (Print 6)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('6');
                    length++;
                    break;
                case 3:
                    // 2, 2 (Print 9)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('9');
                    length++;
                    break;
                case 0:
                    // 2, 3 (Print #)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('#');
                    length++;
                    break;
            }
        }
        else if(C3_Read() == 1){
            switch(x){
                case 1:
                    // 3, 0 (Print A)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('A');
                    length++;
                    break;
                case 2:
                    // 3, 1 (Print B)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('B');
                    length++;
                    break;
                case 3:
                    // 3, 2 (Print C)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('C');
                    length++;
                    break;
                case 0:
                    // 3, 3 (Print D)
                    if(length == 16){
                        length = 0;
                        LCD_ClearDisplay();
                    }
                    LCD_WriteData('D');
                    length++;
                    break;
            }
        }
        // Check for release
        while(C0_Read() == 1 || C1_Read() == 1 || C2_Read() == 1 || C3_Read() == 1);
        // Restart
    }
}

/* [] END OF FILE */
