/*******************************************************************************
* File Name: PWM_SEL.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_SEL.h"

/* Check for removal by optimization */
#if !defined(PWM_SEL_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: PWM_SEL_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void PWM_SEL_Write(uint8 control) 
{
    PWM_SEL_Control = control;
}


/*******************************************************************************
* Function Name: PWM_SEL_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 PWM_SEL_Read(void) 
{
    return PWM_SEL_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
