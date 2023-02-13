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
#include <string.h>
struct MTR{
        unsigned int position : 4;
};
int MVCCW(struct MTR motor){
    if(motor.position >= 4){
        motor.position = 1;
    }
    else{
        motor.position += 1;
    }
    switch(motor.position){
        case 1:
            // 0011 -> 1001
            Motor_Write(0x9);
            break;
        case 2:
            // 1001 -> 1100
            Motor_Write(0xC);
            break;
        case 3:
            // 1100 -> 0110
            Motor_Write(0x6);
            break;
        case 4:
            // 0110 -> 0011
            Motor_Write(0x3);
            break;
    }
    CyDelayUs(3000);
    Motor_Write(0b0000);
    return motor.position;
}
int MVCW(struct MTR motor){
    if(motor.position <= 1){
        motor.position = 4;
    }
    else{
        motor.position -= 1;
    }
    switch(motor.position){
        case 4:
            // 1100 -> 1001
            Motor_Write(0x9);
            break;
        case 3:
            // 1001 -> 0011
            Motor_Write(0x3);
            break;
        case 2:
            // 0011 -> 0110
            Motor_Write(0x6);
            break;
        case 1:
            // 0110 -> 1100
            Motor_Write(0xC);
            break;
    }
    CyDelayUs(3000);
    Motor_Write(0b0000);
    return motor.position;
}
void runCommand(char* command){
    
    for(int i = 0; i < 16; i++){
        if(*(command+i) == 's' || *(command+i) == 'S'){
            i +=2;
            char value[16];
            value[15] = '\0';
            for(int j = i; j < 16;i++){
                value[j] = *(command + j);
            }
            double floatvalue = atof(value);
        }
    }
    
    
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    struct MTR motor = {1};
    UART_Start();
    UART_UartPutString("Type a command please.\r\n");
    char command[17];
    command[16] = '\0';
    unsigned int index = 0;
    for(;;)
    {
        /* Place your application code here. */
        char input = 0;
        do{
            input = UART_UartGetChar();
            
        CyDelay(5);
        motor.position = MVCW(motor);
        }
        while(input == 0);
        if(input == 0x7f){
            if (index == 0){
                UART_UartPutChar(0x07);
            }
            else{
                UART_UartPutChar('\b');
                UART_UartPutChar(' ');
                UART_UartPutChar('\b');
                if(index != 0){
                    command[index] = '\0';
                    command[index-1] = '\0';
                    index--;
                }
            }
        }
        else if(input == 0x0D){
            UART_UartPutString("\r\n");
            char* pointer = command;
            runCommand(pointer);
            for(int i = 0; i < 16; i++){
                command[i] = '\0';
            }
            command[16] = '\0';
            index = 0;
        }
        else{
            if(index == 16){
                UART_UartPutChar(0x07);
            }
            else{
                UART_UartPutChar(input);
                command[index++] = input;
            }
        }
    }
}

/* [] END OF FILE */
