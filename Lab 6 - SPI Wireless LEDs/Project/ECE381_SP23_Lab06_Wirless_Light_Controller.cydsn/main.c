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

volatile int enc_flag = 0;
volatile int btn_flag = 0;
volatile int encPos = 0;

// Struct for keeping register addresses
struct radioAddr{
    uint8 CONFIG;
    uint8 EnhancedShockburst;
    uint8 EnabledRxAddr;
    uint8 SetupAW;
    uint8 SetupRetransmission;
    uint8 RFChannel;
    uint8 RFSetup;
    uint8 Status;
    uint8 ObserveTX;
    uint8 PowerDetector;
    uint8 RXAddr0;
    uint8 RXAddr1;
    uint8 RXAddr2;
    uint8 RXAddr3;
    uint8 RXAddr4;
    uint8 RXAddr5;
    uint8 TXAddr;
    uint8 RXPayload0;
    uint8 RXPayload1;
    uint8 RXPayload2;
    uint8 RXPayload3;
    uint8 RXPayload4;
    uint8 RXPayload5;
    uint8 FIFOStatus;
    uint8 DynamicPayloadLength;
    uint8 Features;
};

struct radioAddr radio = {
    0x00, // CONFIG
    0x01, // EnhancedShockburst
    0x02, // EnabledRxAddr
    0x03, // SetupAW
    0x04, // SetupRetransmission
    0x05, // RFChannel
    0x06, // RFSetup
    0x07, // Status
    0x08, // ObserveTX
    0x09, // PowerDetector
    0x0A,0x0B,0x0C,0x0D,0x0E,0x0F, // RXAddr0-5
    0x10, // TXAddr
    0x11,0x12,0x13,0x14,0x15,0x16, // RXPayload0-5
    0x17, // FIFOStatus
    0x1C, // DynamicPayloadLength
    0x1D  // Features
};

// Radio Addresses
const uint8 group_address[13][5] = {
    {0x11,0x11,0x11,0x11,0x11},
    {0x22,0x22,0x22,0x22,0x22},
    {0x33,0x33,0x33,0x33,0x33},
    {0x44,0x44,0x44,0x44,0x44},
    {0x55,0x55,0x55,0x55,0x55},
    {0x66,0x66,0x66,0x66,0x66},
    {0x77,0x77,0x77,0x77,0x77},
    {0x88,0x88,0x88,0x88,0x88}, // USE THIS ONE
    {0x99,0x99,0x99,0x99,0x99},
    {0xAA,0xAA,0xAA,0xAA,0xAA},
    {0xBB,0xBB,0xBB,0xBB,0xBB},
    {0xCC,0xCC,0xCC,0xCC,0xCC},
    {0xDD,0xDD,0xDD,0xDD,0xDD}
    
};

// Group Channels
const uint8 group_channel[13] = {
    0x10, //16
    0x18, //24
    0x20, //32
    0x28, //40
    0x30, //48
    0x38, //56
    0x40, //64
    0x48, //72 (USE THIS ONE)
    0x50, //80
    0x58, //88
    0x60, //96
    0x68, //102
    0x70  //110
};

/*
This function simply writes to the SPI bus
- Variables
    - writeBuf - buffer to write to bus
    - writeBytes - Number of bytes to write
    - regAddr - Register address to write to
*/
void writeToSpi(uint8* writeBuf, int writeBytes, uint8 regAddr){
    writeBuf[0] = 0b00100000 /*Write to reg*/ | regAddr; /*Reg to write*/
    SPI_SpiUartClearRxBuffer();
    SPI_SpiUartPutArray(writeBuf, writeBytes);
    while(SPI_SpiIsBusBusy() == 0);
    while(SPI_SpiIsBusBusy() == 1);
}
/*
This function processes the message once the radio interrupts the program. It requires no arguments
*/
void processMessage(){
    // SPI buffer
    uint8 writeBuf[32];
    
    // Buffer to read the data coming in
    volatile uint32 readArray[6];
    
    writeBuf[0] = 0b01100001 /*Get RX Payload*/;
    SPI_SpiUartClearRxBuffer();
    SPI_SpiUartPutArray(writeBuf, 17);
    while(SPI_SpiIsBusBusy() == 0);
    while(SPI_SpiIsBusBusy() == 1);
    // Read in data from buffer
    for(int i = 0; i < 6; i++){
        readArray[i] = SPI_SpiUartReadRxData();
    }
    SPI_SpiUartClearRxBuffer();
    // Clear status register
    writeBuf[1] = 0x00 | (0x00 | 0x40 | 0x00);
    writeToSpi(writeBuf, 2, radio.Status);
    SPI_SpiUartClearRxBuffer();
    // Process data
    switch(readArray[1]){
        case 'R': 
            // If less than 10
            if (readArray[4] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30);
                PWM_WriteCompare(bright);
                PWM_Start();
                PWM_SEL_Write(0);
            }
            // If less than 100
            else if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                PWM_Start();
                PWM_SEL_Write(0);
            }
            // If 100
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(0);
            }
            break;
        // Repeats for every case, see comments above
        case 'G': 
            if (readArray[4] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30);
                PWM_WriteCompare(bright);
                PWM_Start();
                PWM_SEL_Write(1);
            }
            else if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                PWM_Start();
                PWM_SEL_Write(1);
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(1);
            }
            break;
        case 'B': 
            if (readArray[4] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30);
                PWM_WriteCompare(bright);
                PWM_Start();
                PWM_SEL_Write(2);
            }
            else if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                PWM_Start();
                PWM_SEL_Write(2);
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(2);
            }
            break;
        case 'Y': 
            if (readArray[4] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30);
                PWM_WriteCompare(bright);
                PWM_Start();
                PWM_SEL_Write(3);
            }
            else if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                PWM_Start();
                PWM_SEL_Write(3);
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(3);
            }
            break;
    }
}
/*****************************************************************************

XXX: TODO Transmitter()

This function puts the NRF24 in TX mode. It should:
- Set 15 retransmissions with a 4000 us delay between each
- Set the data rate to 250 kbps at maximum power level
- Set the payload size to be fixed at 16 bytes
- Ensure auto-acknowledge is turned on for P0 & P1
- Ensure 2-byte CRCs for the auto-acknowledges
- Ensure the data pipes are on
- Ensure the NRF24 is in TX mode and powered up
- Set the correct RF channel based on the input group
- Set the correct TX_ADDR, RX_ADDR_P0, for the target group
- Clear the NRF24 status register

Inputs:
    - int group: An integer representing the group to which the message is
                 directed. This will be used to set the correct address
                 and channel.
               
Outputs:
    - None

*****************************************************************************/
void Transmitter(int group){
    uint8 spiWrBuf[32], spiRdBuf[32];
// - Set 15 retransmissions with a 4000 us delay between each
    spiWrBuf[1] = 0x00 | (0xF0 | 0x0F);
    writeToSpi(spiWrBuf, 2, radio.SetupRetransmission);
// - Set the data rate to 250 kbps at maximum power level
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x20 | 0x00 | 0x00 | 0x06);
    writeToSpi(spiWrBuf, 2, radio.RFSetup);
// - Set the payload size to be fixed at 16 bytes
    spiWrBuf[1] = 16;
    writeToSpi(spiWrBuf, 2, radio.RXPayload0);
    spiWrBuf[1] = 16;
    writeToSpi(spiWrBuf, 2, radio.RXPayload1);
// - Ensure auto-acknowledge is turned on for P0 & P1
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x02 | 0x01);
    writeToSpi(spiWrBuf, 2, radio.EnhancedShockburst);
// - Ensure 2-byte CRCs for the auto-acknowledges
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x08 | 0x04 | 0x00 | 0x00);
    writeToSpi(spiWrBuf, 2, radio.CONFIG);
// - Ensure the data pipes are on
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x02 | 0x01);
    writeToSpi(spiWrBuf, 2, radio.EnabledRxAddr);
// - Ensure the NRF24 is in TX mode and powered up
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x08 | 0x04 | 0x02 | 0x00);
    writeToSpi(spiWrBuf, 2, radio.CONFIG);
// - Set the correct RF channel based on the input group
    if(group < 0 || group > 12){}
    else{
        spiWrBuf[1] = group_channel[group];
        writeToSpi(spiWrBuf, 2, radio.RFChannel);
    }
// - Set the correct TX_ADDR, RX_ADDR_P0, for the target group
    for(int i = 0; i < 5; i++){
        spiWrBuf[i+1] = group_address[group][i];
    }
    writeToSpi(spiWrBuf, 6, radio.RXAddr0);
    
    for(int i = 0; i < 5; i++){
        spiWrBuf[i+1] = group_address[7][i];
    }
    writeToSpi(spiWrBuf, 6, radio.RXAddr1);
    
    for(int i = 0; i < 5; i++){
        spiWrBuf[i+1] = group_address[group][i];
    }
    writeToSpi(spiWrBuf, 6, radio.TXAddr);
    //- Clear the NRF24 status register
    spiWrBuf[1] = 0x00 | (0x00 | 0x40 | 0x20 | 0x10);
    writeToSpi(spiWrBuf, 2, radio.Status);
// - Clear the NRF24 status register
    spiWrBuf[1] = 0x00 | (0x00 | 0x40 | 0x20 | 0x10);
    writeToSpi(spiWrBuf, 2, radio.Status);
}

/*****************************************************************************

XXX: TODO Receiver()

This function puts the NRF24 in RX mode. It should:
- Set 15 retransmissions with a 4000 us delay between each
- Set the data rate to 250 kbps at maximum power level
- Set the payload size to be fixed at 16 bytes
- Ensure auto-acknowledge is turned on for P0 & P1
- Ensure 2-byte CRCs for the auto-acknowledges
- Ensure the data pipes are on
- Ensure the NRF24 is in RX mode and powered up
- Set the correct RF channel
- Set the correct TX_ADDR, RX_ADDR_P0, and RX_ADDR_P1
- Clear the NRF24 status register

Inputs:
    - None
               
Outputs:
    - None

*****************************************************************************/
void Receiver(void){
    uint8 spiWrBuf[32], spiRdBuf[32];
    //- Set 15 retransmissions with a 4000 us delay between each
    spiWrBuf[1] = 0x00 | (0xF0 | 0x0F);
    writeToSpi(spiWrBuf, 2, radio.SetupRetransmission);
    //- Set the data rate to 250 kbps at maximum power level
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x20 | 0x00 | 0x06);
    writeToSpi(spiWrBuf, 2, radio.RFSetup);
    //- Set the payload size to be fixed at 16 bytes
    spiWrBuf[1] = 16;
    writeToSpi(spiWrBuf, 2, radio.RXPayload0);
    spiWrBuf[1] = 16;
    writeToSpi(spiWrBuf, 2, radio.RXPayload1);
    //- Ensure auto-acknowledge is turned on for P0 & P1
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x02 | 0x01);
    writeToSpi(spiWrBuf, 2, radio.EnhancedShockburst);
    //- Ensure 2-byte CRCs for the auto-acknowledges
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x08 | 0x04 | 0x00 | 0x00);
    writeToSpi(spiWrBuf, 2, radio.CONFIG);
    //- Ensure the data pipes are on
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x02 | 0x01);
    writeToSpi(spiWrBuf, 2, radio.EnabledRxAddr);
    //- Ensure the NRF24 is in RX mode and powered up
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x00 | 0x00 | 0x08 | 0x04 | 0x02 | 0x01);
    writeToSpi(spiWrBuf, 2, radio.CONFIG);
    //- Set the correct RF channel
    spiWrBuf[1] = group_channel[7];
    writeToSpi(spiWrBuf, 2, radio.RFChannel);
    //- Set the correct TX_ADDR, RX_ADDR_P0, and RX_ADDR_P1
    for(int i = 0; i < 5; i++){
        spiWrBuf[i+1] = group_address[7][i];
    }
    writeToSpi(spiWrBuf, 6, radio.RXAddr0);
    for(int i = 0; i < 5; i++){
        spiWrBuf[i+1] = 0xC2;
    }
    writeToSpi(spiWrBuf, 6, radio.RXAddr1);
    for(int i = 0; i < 5; i++){
        spiWrBuf[i+1] = group_address[7][i];
    }
    writeToSpi(spiWrBuf, 6, radio.TXAddr);
    //- Clear the NRF24 status register
    spiWrBuf[1] = 0x00 | (0x00 | 0x40 | 0x20 | 0x10);
    writeToSpi(spiWrBuf, 2, radio.Status);
}

/*****************************************************************************

XXX: TODO SendMessage()

This function should send the input message to the target group.
It should:
    - Put the NRF24 in TX mode by calling the Transmitter() function
    - Transmit the message
    - Wait for IRQ to go low
    - Validate whether it was sent correclty using the STATUS register
    - Put the NRF24 back in Receive mode

Inputs:
    - uint8 * message: Where the 16 byte message is stored
    - int group: The target group that should receive the message
               
Outputs:
    - 0 if message is sent correctly
    - 1 if message isn't sent correctly

*****************************************************************************/
int SendMessage(uint8 * message, int group){
    int error = 0;
    
    // Put the NRF24 in transmitter mode  
    Transmitter(group);
    
    //XXX: TODO Send payload and check result
    uint8 spiWrBuf[32];
    uint8 writeBuf[32];
    
    volatile uint32 readArray[6];
    
    writeBuf[0] = 0b10100000 /*W_TX_PAYLOAD*/;
    uint8 count = 0;
    while(count <= 16 && *(message+count) != '\v'){
        writeBuf[1+count] = *(message+count);
        count++;
    }
    SPI_SpiUartClearRxBuffer();
    SPI_SpiUartPutArray(writeBuf, 17);
    while(SPI_SpiIsBusBusy() == 0);
    while(SPI_SpiIsBusBusy() == 1);
    CyDelay(6);
    
    writeBuf[0] = 0b000 |  /*Read from reg*/ radio.Status;
    SPI_SpiUartClearRxBuffer();
    SPI_SpiUartPutArray(writeBuf, 1);
    while(SPI_SpiIsBusBusy() == 0);
    while(SPI_SpiIsBusBusy() == 1);
    for(int i = 0; i < 1; i++){
        readArray[i] = SPI_SpiUartReadRxData();
    }
    SPI_SpiUartClearRxBuffer();
    uint8 TX_DS = readArray[0] & 0b00100000;
    uint8 MAX_RT = readArray[0] & 0b00010000;
    // Clear status reg
    spiWrBuf[1] = 0x00 | (0x00 | 0x40 | 0x20 | 0x10);
    writeToSpi(spiWrBuf, 2, radio.Status);
    if(TX_DS == 0){
        error = 1;
    }
    if (MAX_RT == 0){
        error = 2;
    }
    if(TX_DS == 0 && MAX_RT == 0){
        error = 3;
    }
//    else{
//        error = 0;
//    }
    // Put the NRF24 in receiver mode again
    Receiver();
    
    return error;
}

/* 
Ummm, this function does something special...
*/
void jam(){
    uint8 comm[6] = {' ', ' ', '1','0','0','\0'};
    while(1){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                switch(i){
                    case 0:
                        comm[0] = 'R';
                    break;
                    case 1:
                        comm[0] = 'G';
                    break;
                    case 2:
                        comm[0] = 'B';
                    break;
                    case 3:
                        comm[0] = 'Y';
                    break;
                }
                uint8 error = SendMessage(comm, j);
            }
        }
    }
}

int main(void){
    uint8 command[16];
    int target = 0;
    int brightness = 0;
    int color_sel = 0;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Start();
    SPI_Start();
    PWM_Start();
    PWM_WritePeriod(99); //Using a period of 99 gives an output rate of 1KHz
    PWM_WriteCompare(0); //It also maps perfectly to a 0-100 duty cycle!
    PWM_SEL_Write(0);
    ENC_ISR_Start();
    BTN_ISR_Start();
    NRF24_CE_Write(0);
    
    CyDelay(100);
    
    Receiver();
    NRF24_CE_Write(1);
    
    volatile int error = 0;
    for(;;){
        /********************************************************************* 
        This block of code selects the target group.
             The encoder is used to cycle through the
             13 possible groups until the button is pressed
        *********************************************************************/
        target = 0; //Initialize target group to 0
        //jam(); // Uncomment this line to mess with other groups :)
        char out1[11];
        out1[10] = '\0';
        LCD_ClearDisplay();
        LCD_PrintString("Target: 0");
        // Here we wait for the button to be pressed
        while (btn_flag == 0){
            if (NRF24_IRQ_Read() == 0){
                // There's a message for us!
                // XXX:TODO Get the message and set the right LED with
                //          the correct duty cycle
                processMessage();
            }
            
            //XXX: TODO Get encoder direction and update LCD with
            //     group number
            
             if(enc_flag){
                    if(encPos == 1){
                        if(target != 12){
                            target++;
                        }
                        else{
                            target = 0;
                        }
                    }
                    if(encPos == 2){
                        if(target != 0){
                            target--;
                        }
                        else{
                            target = 12;
                        }
                    }
                    encPos = 0;
                    enc_flag = 0;
                    snprintf(out1,sizeof(out1),"%d ",target);
                    LCD_Position(0,8);
                    LCD_PrintString(out1);
            }
        }
        btn_flag = 0;
        LCD_Position(1,0);
        LCD_PrintString("R");
        /********************************************************************* 
             This block of code selects the target LED color.
             The encoder is used to cycle through the
             R, G, B, or Y until the button is pressed
        *********************************************************************/        
        color_sel = 0;
        while(btn_flag == 0){
            if (NRF24_IRQ_Read() == 0){
                // There's a message for us!
                // XXX:TODO Get the message and set the right LED with
                //          the correct duty cycle
                processMessage();
            }
            
            //XXX: TODO Get encoder direction and update LCD with
            //     correct color   
            
            if(enc_flag){
                    if(encPos == 1){
                        if(color_sel != 3){
                            color_sel++;
                        }
                        else{
                            color_sel = 0;
                        }
                    }
                    if(encPos == 2){
                        if(color_sel != 0){
                            color_sel--;
                        }
                        else{
                            color_sel = 3;
                        }
                    }
                    encPos = 0;
                    enc_flag = 0;
                    switch(color_sel){
                        case 0: 
                            LCD_Position(1,0);
                            LCD_PrintString("R");
                            break;
                        case 1:
                            LCD_Position(1,0);
                            LCD_PrintString("G");
                            break;
                        case 2:
                            LCD_Position(1,0);
                            LCD_PrintString("B");
                            break;
                        case 3:
                            LCD_Position(1,0);
                            LCD_PrintString("Y");
                            break;
                    }
            }
        }
        btn_flag = 0;
        switch(color_sel){
            case 0: 
                command[0] = 'R';
                break;
            case 1:
                command[0] = 'G';
                break;
            case 2:
                command[0] = 'B';
                break;
            case 3:
                command[0] = 'Y';
                break;
        }
        /********************************************************************* 
        This block of code selects the target LED brigthness/PWM duty cycle.
             The encoder is used to cycle down to 0 and up to 100,
             incrementing or decrementing once per click, until the
             button is pressed.
        *********************************************************************/              
        brightness = 50;
        char out4[6];
        out4[5] = '\0';
        LCD_Position(1,2);
        snprintf(out4, 6, "%d", brightness);
        out4[5] = '\0';
        LCD_PrintString(out4);
        while(btn_flag == 0){
            if (NRF24_IRQ_Read() == 0){
                // There's a message for us!
                // XXX:TODO Get the message and set the right LED with
                //          the correct duty cycle
                processMessage();
            }
            
            //XXX: TODO Get encoder direction and update LCD with
            //     correct brightness value   
            
            if(enc_flag){
                    if(encPos == 1){
                        if(brightness == 100){
                        }
                        else{
                            brightness++;
                        }
                    }
                    if(encPos == 2){
                        if(brightness == 0){
                        }
                        else{
                            brightness--;
                        }
                    }
                    encPos = 0;
                    enc_flag = 0;
                    
                    //LCD_PrintString(out2);
                    LCD_Position(1,2);
                    snprintf(out4, 6, "%d  ", brightness);
                    out4[5] = '\0';
                    LCD_PrintString(out4);
            }
        }
        btn_flag = 0;
        snprintf(command, 6, "%c %d", command[0],brightness);
        command[5] = '\0';
        // Now that we have valid input, send it to the target group.
        error = SendMessage(command, target);
        if(error != 2){
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("Failed");
            LCD_Position(1,0);
            LCD_PrintString("Transmission!!");
            CyDelay(2000);
        }
        
    }
}

/* [] END OF FILE */
