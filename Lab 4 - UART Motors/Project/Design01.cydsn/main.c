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

// Create a struct for a motor, with a variable for position
struct MTR{
    unsigned int position : 4;
};
// Initialize motor with position 1
struct MTR motor = {1};
// Initialize motor delay for 3000 microseconds
int motorDelay = 3000;
// Function for moving counter-clockwise
int MVCCW(struct MTR motor){
    // If motor position is at edge, reset, otherwise increment
    if(motor.position >= 4){
        motor.position = 1;
    }
    else{
        motor.position += 1;
    }
    // Write correct motor position
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
    // Delay defined by either default or RPM
    CyDelayUs(motorDelay);
    // Ground so motor doesn't get hot
    // Can change to where it only goes to ground only after all steps have been taken
    Motor_Write(0b0000);
    // Return position of motor
    return motor.position;
}
// Function for moving clockwise
int MVCW(struct MTR motor){
    // If motor is at edge, reset, if not, decrement
    if(motor.position <= 1){
        motor.position = 4;
    }
    else{
        motor.position -= 1;
    }
    // Write correct motor position
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
    // Delay
    CyDelayUs(motorDelay);
    // Ground so motor doesn't get hot
    Motor_Write(0b0000);
    // Return motor position
    return motor.position;
}
// Function that runs commands based on the letter given
void runCommand(char* command){
    // Run through the character array
    for(int i = 0; i < 16; i++){
        // Change speed (floating point)
        if(*(command+i) == 's' || *(command+i) == 'S'){
            // New character array for value
            char value[14] = {};
            // Store last index variable
            int lastIndex;
            // Loop through the array starting at 2
            for(int j = 2; j < 16; j++){
                // If null terminator, break and increment index by 2
                if(*(command+j) == '\0'){
                    lastIndex = j+2;
                    break;
                }
                // Store character into value array  
                value[j-2] = *(command + j);
            }
            // Convert string to a floating point
            float floatValue = atof(value);
            char out[16];
            // Convert floating point value back to string using formatting
            snprintf(out, sizeof(out),"%.3f",floatValue);
            // 2048 steps/rev
            // rev/min -> rev/us
            // rev/us -> us/step
            // (1/2048)*(1/rpm)*(6*10^7)
            // Calculate delay
            int delay = (int)((1/((float)2048))*(1/floatValue)*(6*10000000));
            // Store global variable
            motorDelay = delay;
            // Output "RPM: " to UART
            char output[56]={'R','P','M',':',' '};
            // Go through out array and store into output array
            for(int j = 0; j < lastIndex+1; j++){
                // If end of string, add 5 to last index and break
                if(out[j] == '\0'){
                    lastIndex = j+5;
                    break;
                }
                // Store out to output
                else{
                    output[j+5] = out[j];
                }
            }
            // Store " Delay: " into output, concantenated
            output[lastIndex++] = ' ';
            output[lastIndex++] = 'D';
            output[lastIndex++] = 'e';
            output[lastIndex++] = 'l';
            output[lastIndex++] = 'a';
            output[lastIndex++] = 'y';
            output[lastIndex++] = ':';
            output[lastIndex++] = ' ';
            // New array for next format
            char out2[16];
            // Format delay as a decimal formatted string
            snprintf(out2, sizeof(out2),"%d",motorDelay);
            // New index
            int lastIndex2;
            // Loop through out2 array
            for(int j = 0; j < 16; j++){
                // If end of string, add the lastIndex + where it is into lastIndex2
                if(out2[j] == '\0'){
                    lastIndex2 = j+lastIndex;
                    break;
                }
                // Store out2 into output
                else{
                    output[j+lastIndex] = out2[j];
                }
            }
            // Add units to the end and the carriage return
            output[lastIndex2++] = ' ';
            output[lastIndex2++] = 'u';
            output[lastIndex2++] = 's';
            output[lastIndex2++] = '\r';
            output[lastIndex2++] = '\n';
            output[lastIndex2++] = '\0';
            // Output to UART
            UART_UartPutString(output);
        }
        // Forward steps
        else if(*(command+i) == 'F' || *(command+i) == 'f'){
            // Increment by 2 to skip letters
            i +=2;
            // Initialize value
            long value = 0;
            // Go through array (this is basically atod() function)
            for(int j = i; j < 16;j++){
                // Store value as the current char value - 0x30 (takes numbers 0-9)
                int charVal = (int)(*(command+j)-0x30);
                // If any other character other than a number, break
                if(charVal < 0 || charVal > 10){
                    break;
                }
                // Add character value then multiply by 10 to go to next number
                else{
                    value += charVal;
                    value *= 10;
                }
            }
            // Divide by 10 to reverse the last character
            value /= 10;
            // Move motor clockwise based on number of steps given
            for (int i = 0; i < value; i++){
                 motor.position = MVCW(motor);
            }
            // Start new output array with "Num fwd: "
            char output[26] = {
                'N', 'u', 'm', ' ', 'f', 'w', 'd',':',' '
            };
            // Initialize power of 10
            int pow10 = 10;
            // Find remainder, if its the value, break, if not, increment power of 10
            // Finds order of value
            while(value%(int)pow10 != value){
                pow10*=10;
            }
            // Start index of output array
            int startIndex = 9;
            // If the power of 10 is 1, break
            while(pow10/10 != 0){
                // Decrement power of 10
                pow10/=10;
                // Store output array as character version of number
                output[startIndex++] = (value/(pow10))+0x30;
                // Subtract that number
                value -= value/(pow10)*pow10;
            }
            // End with carriage return and new line and null terminator
            output[startIndex] = '\r';
            output[startIndex+1] = '\n';
            output[startIndex+2] = '\0';
            // Output to UART
            UART_UartPutString(output);
        }
        // Backwards
        else if(*(command+i) == 'B' || *(command+i) == 'b'){
            // Increment by 2 to skip letters
            i +=2;
            // Initialize value
            long value = 0;
            for(int j = i; j < 16;j++){
                // Store value as the current char value - 0x30 (takes numbers 0-9)
                int charVal = (int)(*(command+j)-0x30);
                // If any other character other than a number, break
                if(charVal < 0 || charVal > 10){
                    break;
                }
                // Add character value then multiply by 10 to go to next number
                else{
                    value += charVal;
                    value *= 10;
                }
            }
            // Divide by 10 to reverse the last character
            value /= 10;
            // Move motor counter-clockwise based on number of steps given
            for (int i = 0; i < value; i++){
                 motor.position = MVCCW(motor);
            }
            // Initialize array as "Num bkwd: "
            char output[27] = {
                'N', 'u', 'm', ' ', 'b', 'k', 'w', 'd',':',' '
            };
            int pow10 = 10;
            while(value%(int)pow10 != value){
                pow10*=10;
            }
            // Create start index at 10
            int startIndex = 10;
            // If the power of 10 is 1, break
            while(pow10/10 != 0){
                // Decrement power of 10
                pow10/=10;
                // Store output array as character version of number
                output[startIndex++] = (value/(pow10))+0x30;
                // Subtract that number
                value -= value/(pow10)*pow10;
            }
            // Put end of string as carriage return, new line, and null terminator
            output[startIndex] = '\r';
            output[startIndex+1] = '\n';
            output[startIndex+2] = '\0';
            // Output UART
            UART_UartPutString(output);
            
        }
    }
    
    
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Start UART
    UART_Start();
    // Initialize UART
    UART_UartPutString("Type a command please.\r\n");
    // Initialize command array
    char command[17];
    // Initialize null terminator for string
    command[16] = '\0';
    // Initialize index for 0
    unsigned int index = 0;
    for(;;)
    {
        /* Place your application code here. */
        // Initialize input as nothing
        char input = 0;
        // Poll UART
        do{
            input = UART_UartGetChar();
        }
        while(input == 0);
        // Backspace character (0x7F)
        if(input == 0x7f){
            // If index is 0, play BEL
            if (index == 0){
                UART_UartPutChar(0x07);
            }
            else{
                // Backspace, replace with space, backspace again
                UART_UartPutChar('\b');
                UART_UartPutChar(' ');
                UART_UartPutChar('\b');
                // If the index is not 0 (not technically needed)
                // Replace command array at index and index-1 to null
                // Decrement index
                if(index != 0){
                    command[index] = '\0';
                    command[index-1] = '\0';
                    index--;
                }
            }
        }
        // Carriage return
        else if(input == 0x0D){
            // Output carriage return
            UART_UartPutString("\r\n");
            // Create pointer
            char* pointer = command;
            // Use run command
            runCommand(pointer);
            // Reset array
            for(int i = 0; i < 16; i++){
                command[i] = '\0';
            }
            // Null terminator
            command[16] = '\0';
            // Reset index
            index = 0;
        }
        else{
            // If index is over 16 (max character) output BEL
            if(index == 16){
                UART_UartPutChar(0x07);
            }
            // If index is not 16, store character
            else{
                UART_UartPutChar(input);
                command[index++] = input;
            }
        }
    }
}

/* [] END OF FILE */