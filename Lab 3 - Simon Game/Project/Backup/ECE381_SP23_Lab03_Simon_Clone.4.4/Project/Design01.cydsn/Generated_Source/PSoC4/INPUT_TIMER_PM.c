/*******************************************************************************
* File Name: INPUT_TIMER_PM.c
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

#include "INPUT_TIMER.h"

static INPUT_TIMER_BACKUP_STRUCT INPUT_TIMER_backup;


/*******************************************************************************
* Function Name: INPUT_TIMER_SaveConfig
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
void INPUT_TIMER_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: INPUT_TIMER_Sleep
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
void INPUT_TIMER_Sleep(void)
{
    if(0u != (INPUT_TIMER_BLOCK_CONTROL_REG & INPUT_TIMER_MASK))
    {
        INPUT_TIMER_backup.enableState = 1u;
    }
    else
    {
        INPUT_TIMER_backup.enableState = 0u;
    }

    INPUT_TIMER_Stop();
    INPUT_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_RestoreConfig
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
void INPUT_TIMER_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: INPUT_TIMER_Wakeup
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
void INPUT_TIMER_Wakeup(void)
{
    INPUT_TIMER_RestoreConfig();

    if(0u != INPUT_TIMER_backup.enableState)
    {
        INPUT_TIMER_Enable();
    }
}


/* [] END OF FILE */
