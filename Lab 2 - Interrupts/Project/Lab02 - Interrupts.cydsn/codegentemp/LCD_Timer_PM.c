/*******************************************************************************
* File Name: LCD_Timer_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_Timer.h"

static LCD_Timer_BACKUP_STRUCT LCD_Timer_backup;


/*******************************************************************************
* Function Name: LCD_Timer_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LCD_Timer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: LCD_Timer_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LCD_Timer_Sleep(void)
{
    if(0u != (LCD_Timer_BLOCK_CONTROL_REG & LCD_Timer_MASK))
    {
        LCD_Timer_backup.enableState = 1u;
    }
    else
    {
        LCD_Timer_backup.enableState = 0u;
    }

    LCD_Timer_Stop();
    LCD_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: LCD_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LCD_Timer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: LCD_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LCD_Timer_Wakeup(void)
{
    LCD_Timer_RestoreConfig();

    if(0u != LCD_Timer_backup.enableState)
    {
        LCD_Timer_Enable();
    }
}


/* [] END OF FILE */
