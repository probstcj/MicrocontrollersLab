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

volatile int enc_flag = 0;
volatile int btn_flag = 0;

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
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
    0x10,
    0x11,0x12,0x13,0x14,0x15,0x16,
    0x17,
    0x1C,
    0x1D
};

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

void writeToSpi(uint8* writeBuf, int writeBytes, uint8 regAddr){
    writeBuf[0] = 0b00100000 /*Write to reg*/ | regAddr; /*Reg to write*/
    SPI_SpiUartClearRxBuffer();
    SPI_SpiUartPutArray(writeBuf, writeBytes);
    while(SPI_SpiIsBusBusy() == 0);
    while(SPI_SpiIsBusBusy() == 1);
}

void processMessage(){
    uint8 writeBuf[32];
    
    volatile uint32 readArray[6];
    
    writeBuf[0] = 0b01100001 /*Write to reg*/;
    SPI_SpiUartClearRxBuffer();
    SPI_SpiUartPutArray(writeBuf, 17);
    while(SPI_SpiIsBusBusy() == 0);
    while(SPI_SpiIsBusBusy() == 1);
    for(int i = 0; i < 6; i++){
        readArray[i] = SPI_SpiUartReadRxData();
    }
    SPI_SpiUartClearRxBuffer();
    writeBuf[1] = 0x00 | (0x00 | 0x40 | 0x00);
    writeToSpi(writeBuf, 2, radio.Status);
    switch(readArray[1]){
        case 'R': 
            if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                //PWM_WriteCompare();
                PWM_Start();
                PWM_SEL_Write(0);
                volatile int b = 0;
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(0);
            }
            break;
        case 'G': 
            if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                //PWM_WriteCompare();
                PWM_Start();
                PWM_SEL_Write(1);
                volatile int b = 0;
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(1);
            }
            break;
        case 'B': 
            if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                //PWM_WriteCompare();
                PWM_Start();
                PWM_SEL_Write(2);
                volatile int b = 0;
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(2);
            }
            break;
        case 'Y': 
            if(readArray[5] == 0x00000000){
                volatile uint32 bright = (readArray[3]-0x30)*10 + (readArray[4]-0x30);
                PWM_WriteCompare(bright-1);
                //PWM_WriteCompare();
                PWM_Start();
                PWM_SEL_Write(3);
                volatile int b = 0;
            }
            else{
                PWM_WriteCompare(99);
                PWM_Start();
                PWM_SEL_Write(3);
            }
            break;
    }
    volatile uint8 a = 0;
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
    spiWrBuf[1] = 0x00 | (0x00 | 0x00 | 0x20 | 0x00 | 0x03);
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
    
    // Put the NRF24 in receiver mode again
    Receiver();
    
    return error;
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
    
    for(;;){
        /********************************************************************* 
        This block of code selects the target group.
             The encoder is used to cycle through the
             13 possible groups until the button is pressed
        *********************************************************************/
        
        target = 0; //Initialize target group to 0
        
        // Here we wait for the button to be pressed
        while (btn_flag == 0){
            if (NRF24_IRQ_Read() == 0){
                // There's a message for us!
                // XXX:TODO Get the message and set the right LED with
                //          the correct duty cycle
                volatile int a = 1;
                processMessage();
            }
            
            //XXX: TODO Get encoder direction and update LCD with
            //     group number
            
            
        }
        btn_flag = 0;
        
        
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
            }
            
            //XXX: TODO Get encoder direction and update LCD with
            //     correct color            
        }
        btn_flag = 0;
        
        /********************************************************************* 
        This block of code selects the target LED brigthness/PWM duty cycle.
             The encoder is used to cycle down to 0 and up to 100,
             incrementing or decrementing once per click, until the
             button is pressed.
        *********************************************************************/              
        brightness = 50;
        while(btn_flag == 0){
            if (NRF24_IRQ_Read() == 0){
                // There's a message for us!
                // XXX:TODO Get the message and set the right LED with
                //          the correct duty cycle
                processMessage();
            }
            
            //XXX: TODO Get encoder direction and update LCD with
            //     correct brightness value                
        }
        btn_flag = 0;
        
        // Now that we have valid input, send it to the target group.
        SendMessage(command, target);
        
    }
}

/* [] END OF FILE */
