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
#include <stdio.h>
#include <stdlib.h>
struct MTR{
        unsigned int position : 4;
};
struct MTR motor = {1};
int motorDelay = 3000;
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
    CyDelayUs(motorDelay);
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
    CyDelayUs(motorDelay);
    Motor_Write(0b0000);
    return motor.position;
}
void runCommand(char* command){
    
    for(int i = 0; i < 16; i++){
        if(*(command+i) == 's' || *(command+i) == 'S'){
            char value[14] = {};
            int lastIndex;
            for(int j = 2; j < 16; j++){
                if(*(command+j) == '\0'){
                    lastIndex = j+2;
                    
                    break;
                }
                value[j-2] = *(command + j);
            }
            float floatValue = atof(value);
            char out[16];
            snprintf(out, sizeof(out),"%.3f",floatValue);
            // 2048 steps/rev
            // rev/min -> rev/us
            // rev/us -> us/step
            // (1/2048)*(1/rpm)*(6*10^7)
            int delay = (int)((1/((float)2048))*(1/floatValue)*(6*10000000));
            motorDelay = delay;
            char output[56]={'R','P','M',':',' '};
            for(int j = 0; j < lastIndex+1; j++){
                if(out[j] == '\0'){
                    lastIndex = j+5;
                    break;
                }
                else{
                    output[j+5] = out[j];
                }
            }
            output[lastIndex++] = ' ';
            output[lastIndex++] = 'D';
            output[lastIndex++] = 'e';
            output[lastIndex++] = 'l';
            output[lastIndex++] = 'a';
            output[lastIndex++] = 'y';
            output[lastIndex++] = ':';
            output[lastIndex++] = ' ';
            char out2[16];
            snprintf(out2, sizeof(out2),"%d",motorDelay);
            int lastIndex2;
            for(int j = 0; j < 16; j++){
                if(out2[j] == '\0'){
                    lastIndex2 = j+lastIndex;
                    break;
                }
                else{
                    output[j+lastIndex] = out2[j];
                }
            }
            output[lastIndex2++] = ' ';
            output[lastIndex2++] = 'u';
            output[lastIndex2++] = 's';
            output[lastIndex2++] = '\r';
            output[lastIndex2++] = '\n';
            output[lastIndex2++] = '\0';
            UART_UartPutString(output);
        }
        else if(*(command+i) == 'F' || *(command+i) == 'f'){
            i +=2;
            long value = 0;
            for(int j = i; j < 16;j++){
                // s 19216.8123
                int charVal = (int)(*(command+j)-0x30);
                if(charVal < 0 || charVal > 10){
                    break;
                }
                else{
                    value += charVal;
                    value *= 10;
                }
            }
            value /= 10;
            for (int i = 0; i < value; i++){
                 motor.position = MVCW(motor);
            }
            char output[26] = {
                'N', 'u', 'm', ' ', 'f', 'w', 'd',':',' '
            };
            int pow10 = 10;
            while(value%(int)pow10 != value){
                pow10*=10;
            }
            int startIndex = 9;
            while(pow10/10 != 0){
                pow10/=10;
                output[startIndex++] = (value/(pow10))+0x30;
                //UART_UartPutChar(value/(pow10)+0x30);
                value -= value/(pow10)*pow10;
            }
            output[startIndex] = '\r';
            output[startIndex+1] = '\n';
            output[startIndex+2] = '\0';
            UART_UartPutString(output);
            
        }
        else if(*(command+i) == 'B' || *(command+i) == 'b'){
            i +=2;
            long value = 0;
            for(int j = i; j < 16;j++){
                // s 19216.8123
                int charVal = (int)(*(command+j)-0x30);
                if(charVal < 0 || charVal > 10){
                    break;
                }
                else{
                    value += charVal;
                    value *= 10;
                }
            }
            value /= 10;
            for (int i = 0; i < value; i++){
                 motor.position = MVCCW(motor);
            }
            char output[27] = {
                'N', 'u', 'm', ' ', 'b', 'k', 'w', 'd',':',' '
            };
            int pow10 = 10;
            while(value%(int)pow10 != value){
                pow10*=10;
            }
            int startIndex = 10;
            while(pow10/10 != 0){
                pow10/=10;
                output[startIndex++] = (value/(pow10))+0x30;
                //UART_UartPutChar(value/(pow10)+0x30);
                value -= value/(pow10)*pow10;
            }
            output[startIndex] = '\r';
            output[startIndex+1] = '\n';
            output[startIndex+2] = '\0';
            UART_UartPutString(output);
            
        }
    }
    
    
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
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