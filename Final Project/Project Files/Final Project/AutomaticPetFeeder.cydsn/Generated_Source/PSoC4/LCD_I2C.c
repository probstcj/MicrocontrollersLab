/*******************************************************************************
* File Name: LCD_I2C.c
* Version 2.0
*
* Description:
*  This file provides source code for the CharLCD_I2C component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "LCD_I2C.h"

#if(CY_PSOC4)
	#include "I2C_LCD_PVT.h"
	#include "I2C_LCD_I2C_PVT.h"
#else
	#include "I2C_LCD.h"
	#include "I2C_LCD_PVT.h"
#endif /*PSOC4*/

/* Stores the state of conponent. Indicates wherewer component is 
* in enabled state or not.
*/
uint8 LCD_enableState = 0u;

uint8 LCD_initVar = 0u;


/*******************************************************************************
* Function Name: LCD_Init
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_Init(void) 
{
    /* INIT CODE */
    CyDelay(LCD_INIT_DELAY);									/* Delay 20 ms */
    LCD_WrtCntrlUpNib(LCD_DISPLAY_8_BIT_INIT);   	/* Selects 8-bit mode */
    CyDelay(LCD_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	LCD_WrtCntrlUpNib(LCD_DISPLAY_8_BIT_INIT);  	/* Selects 8-bit mode */
    CyDelay(LCD_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	LCD_WrtCntrlUpNib(LCD_DISPLAY_8_BIT_INIT);  	/* Selects 8-bit mode */
	CyDelay(LCD_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	LCD_WrtCntrlUpNib(LCD_DISPLAY_4_BIT_INIT);   	/* Selects 4-bit mode */
	CyDelay(LCD_INIT_UP_NIB_DELAY);								/* Delay 5 ms */

	LCD_WriteControl(LCD_DISPLAY_4_BIT_INIT);		/* Write 4-bit Mode 2x16 or 4x20 Char */
	CyDelay(LCD_INIT_CMD_DELAY);								/* Delay 5 ms */
    LCD_WriteControl(LCD_CLEAR_DISPLAY);			/* Clear LCD Screen */
	CyDelay(LCD_INIT_CMD_DELAY);								/* Delay 5 ms */
    LCD_WriteControl(LCD_CURSOR_AUTO_INCR_ON);		/* Incr Cursor One Space to Right After Writes */
	CyDelay(LCD_INIT_CMD_DELAY);								/* Delay 5 ms */
	LCD_WriteControl(LCD_DISPLAY_ON_CURSOR_OFF);	/* Display ON Cursor OFF */
 	CyDelay(LCD_INIT_CMD_DELAY);								/* Delay 5 ms */  
	
	#if(LCD_CUSTOM_CHAR_SET != LCD_NONE)
        LCD_LoadCustomFonts(LCD_customFonts);
    #endif /* LCD_CUSTOM_CHAR_SET != LCD_NONE */
}


/*******************************************************************************
* Function Name: LCD_Enable									   *
********************************************************************************
*
* Summary:
*  Turns on the display.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Theory:
*  This finction has no effect when it called first time as
*  LCD_Init() turns on the LCD.
*
*******************************************************************************/
void LCD_Enable(void) 
{
    LCD_DisplayOn();
    LCD_enableState = 1u;
}


/*******************************************************************************
* Function Name: LCD_Start
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*  If it was not the first call in this project then it just turns on the
*  display
*
*
* Parameters:
*  LCD_initVar - global variable.
*
* Return:
*  LCD_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_Start(void) 
{
    /* If not initialized then perform initialization */
    if(LCD_initVar == 0u)
    {
        LCD_Init();
        LCD_initVar = 1u;
    }

    /* Turn on the LCD */
    LCD_Enable();
}


/*******************************************************************************
* Function Name: LCD_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_Stop(void) 
{
    /* Calls LCD Off Macro */
    LCD_DisplayOff();
    LCD_enableState = 0u;
}


/*******************************************************************************
*  Function Name: LCD_Position
********************************************************************************
*
* Summary:
*  Moves active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:     Specific row of LCD module to be written
*  column:  Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays which use the 2X40 address mode.
*  This results in Row 2 offset from row one by 0x28.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void LCD_Position(uint8 row, uint8 column) 
{
    switch (row)
    {
        case (uint8)0:
            LCD_WriteControl(LCD_ROW_0_START + column);
            break;
        case (uint8) 1:
            LCD_WriteControl(LCD_ROW_1_START + column);
            break;
        case (uint8) 2:
            LCD_WriteControl(LCD_ROW_2_START + column);
            break;
        case (uint8) 3:
            LCD_WriteControl(LCD_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: LCD_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string:  pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_PrintString(char8 const string[]) 
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        LCD_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: LCD_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (_CUSTOM_0 through
*  _CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character:  character to be written to the LCD
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_PutChar(char8 character) 
{
    LCD_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: LCD_WriteData
********************************************************************************
*
* Summary:
*   Writes a DATA Command to the LCD by sending the Upper Nibble and
*   the Lower Nibble twice, once with the E input High and once with the 
*	E input Low with the the RS input held High and the RW input held Low 
*	while the K input or Back Light (BL) input is held High.
*
*******************************************************************************/	

void LCD_WriteData(uint8 dByte) 

{
    uint8 buffer[LCD_BUFFER_SIZE], UPPER_NIB, LOWER_NIB;
	uint8 BLH_EH_RWL_RSH, BLH_EL_RWL_RSH;
	
	UPPER_NIB = dByte & LCD_UPPER_NIB_MASK;
   	LOWER_NIB = (dByte & LCD_LOWER_NIB_MASK) << LCD_LOWER_NIB_SHIFT;
	
	BLH_EH_RWL_RSH = LCD_BLH + LCD_EH + LCD_RSH;
	BLH_EL_RWL_RSH = LCD_BLH + LCD_RSH;
	
	/* Initialize buffer with packet */
   
	buffer[LCD_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSH;
    buffer[LCD_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSH;
    buffer[LCD_PACKET_2_POS] = LOWER_NIB | BLH_EH_RWL_RSH;
    buffer[LCD_PACKET_3_POS] = LOWER_NIB | BLH_EL_RWL_RSH;
    
#if(CY_PSOC4)
	
	(void) I2C_LCD_I2CMasterWriteBuf(LCD_I2C_SLAVE_ADDR, buffer, LCD_PACKET_SIZE, \
                                  I2C_LCD_I2C_MODE_COMPLETE_XFER);

#else    
   	
	(void) I2C_LCD_MasterWriteBuf(LCD_I2C_SLAVE_ADDR, buffer, LCD_PACKET_SIZE, \
                                  I2C_LCD_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 

	CyDelayUs(LCD_DATA_DELAY_US);
}

/*******************************************************************************
*  Function Name: LCD_WriteControl
********************************************************************************
*
* Summary:
*   Writes a CONTROL Command to the LCD by sending the Upper Nibble and
*   the Lower Nibble twice, once with the E input High and once with the 
*	E input Low with the the RS and the RW input held Low while the
*	K input or Back Light (BL) input is held High.
*
*******************************************************************************/	

void LCD_WriteControl(uint8 cByte) 
{
    uint8 buffer[LCD_BUFFER_SIZE], UPPER_NIB, LOWER_NIB;
	uint8 BLH_EH_RWL_RSL, BLH_EL_RWL_RSL;
	
	UPPER_NIB = cByte & LCD_UPPER_NIB_MASK;
   	LOWER_NIB = (cByte & LCD_LOWER_NIB_MASK) << LCD_LOWER_NIB_SHIFT;
	
	BLH_EH_RWL_RSL = LCD_BLH + LCD_EH;
	BLH_EL_RWL_RSL = LCD_BLH;
	
	/* Initialize buffer with packet */
   
	buffer[LCD_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSL;
    buffer[LCD_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSL;
    buffer[LCD_PACKET_2_POS] = LOWER_NIB | BLH_EH_RWL_RSL;
    buffer[LCD_PACKET_3_POS] = LOWER_NIB | BLH_EL_RWL_RSL;
     
#if(CY_PSOC4)
	
	(void) I2C_LCD_I2CMasterWriteBuf(LCD_I2C_SLAVE_ADDR, buffer, LCD_PACKET_SIZE, \
                                  I2C_LCD_I2C_MODE_COMPLETE_XFER);
#else    
   	
	(void) I2C_LCD_MasterWriteBuf(LCD_I2C_SLAVE_ADDR, buffer, LCD_PACKET_SIZE, \
                                  I2C_LCD_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 

	CyDelayUs(LCD_CMD_DELAY_US);
}

/*******************************************************************************
*  Function Name: LCD_WrtCntrlUpNib
********************************************************************************
*
* Summary:
*   Writes a CONTROL Command to the LCD by sending only the UPPER NIBBLE twice,
*	once with the E input High and once with the E input Low with the RS input 
*	and RW input held Low while the K input or Back Light (BL) input is held High.
*
*******************************************************************************/
void LCD_WrtCntrlUpNib(uint8 cByte) 
{
    uint8 buffer[LCD_UPPER_NIB_BUFFER_SIZE], UPPER_NIB;
	uint8 BLH_EH_RWL_RSL, BLH_EL_RWL_RSL;
	
	UPPER_NIB = cByte & LCD_UPPER_NIB_MASK;
	
	BLH_EH_RWL_RSL = LCD_BLH + LCD_EH;
	BLH_EL_RWL_RSL = LCD_BLH;
	
	/* Initialize buffer with packet */
   
	buffer[LCD_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSL;
    buffer[LCD_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSL;
     
#if(CY_PSOC4)
	
	(void) I2C_LCD_I2CMasterWriteBuf(LCD_I2C_SLAVE_ADDR, buffer, LCD_UPPER_NIB_PACKET_SIZE, \
                                  I2C_LCD_I2C_MODE_COMPLETE_XFER);
	
#else    
   	
	(void) I2C_LCD_MasterWriteBuf(LCD_I2C_SLAVE_ADDR, buffer, LCD_UPPER_NIB_PACKET_SIZE, \
                                  I2C_LCD_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 
	
	CyDelayUs(LCD_CMD_DELAY_US);

}
/*******************************************************************************
* Function Name: LCD_IsReady
********************************************************************************
*
* Summary:
*  Polls LCD until the ready bit is set.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes pins to High-Z.
*
*******************************************************************************/
void LCD_IsReady(void) 
{
   
	CyDelay(1u);
	
}

#if(LCD_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: LCD_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void LCD_PrintInt8(uint8 value) 
    {
        static char8 const CYCODE LCD_hex[16u] = "0123456789ABCDEF";
        
        LCD_PutChar((char8) LCD_hex[value >> LCD_BYTE_UPPER_NIBBLE_SHIFT]);
        LCD_PutChar((char8) LCD_hex[value & LCD_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: LCD_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value:   The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void LCD_PrintInt16(uint16 value) 
    {
        LCD_PrintInt8((uint8)(value >> LCD_U16_UPPER_BYTE_SHIFT));
        LCD_PrintInt8((uint8)(value & LCD_U16_LOWER_BYTE_MASK));
    }


    /*******************************************************************************
    *  Function Name: LCD_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void LCD_PrintNumber(uint16 value) 
    {

        char8 number[LCD_NUMBER_OF_REMAINDERS];
        char8 temp[LCD_NUMBER_OF_REMAINDERS];

        uint8 digIndex = 0u;
        uint8 numDigits;

        /* Load these in reverse order */
        while(value >= LCD_TEN)
        {
            temp[digIndex] = (value % LCD_TEN) + '0';
            value /= LCD_TEN;
            digIndex++;
        }

        temp[digIndex] = (value % LCD_TEN) + '0';
        numDigits = digIndex;

        /* While index is greater than or equal to zero copy number
        * from temporary array to number[].
        */
        while (digIndex != 0u)
        {
            number[numDigits - digIndex] = temp[digIndex];
            digIndex--;
        }
        
        /* Copy last digit */
        number[numDigits] = temp[0u];

        /* Null Termination */
        number[numDigits + 1u] = (char8) '\0';

        /* Print out number */
        LCD_PrintString(&number[0u]);
    }

#endif /* LCD_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
