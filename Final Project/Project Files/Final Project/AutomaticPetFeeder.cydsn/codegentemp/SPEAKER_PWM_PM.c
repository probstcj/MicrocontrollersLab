/*******************************************************************************
* File Name: SPEAKER_PWM_PM.c
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

#include "SPEAKER_PWM.h"

static SPEAKER_PWM_BACKUP_STRUCT SPEAKER_PWM_backup;


/*******************************************************************************
* Function Name: SPEAKER_PWM_SaveConfig
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
void SPEAKER_PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: SPEAKER_PWM_Sleep
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
void SPEAKER_PWM_Sleep(void)
{
    if(0u != (SPEAKER_PWM_BLOCK_CONTROL_REG & SPEAKER_PWM_MASK))
    {
        SPEAKER_PWM_backup.enableState = 1u;
    }
    else
    {
        SPEAKER_PWM_backup.enableState = 0u;
    }

    SPEAKER_PWM_Stop();
    SPEAKER_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: SPEAKER_PWM_RestoreConfig
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
void SPEAKER_PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: SPEAKER_PWM_Wakeup
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
void SPEAKER_PWM_Wakeup(void)
{
    SPEAKER_PWM_RestoreConfig();

    if(0u != SPEAKER_PWM_backup.enableState)
    {
        SPEAKER_PWM_Enable();
    }
}


/* [] END OF FILE */
