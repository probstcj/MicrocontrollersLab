/*******************************************************************************
* File Name: C0.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "C0.h"

static C0_BACKUP_STRUCT  C0_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: C0_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet C0_SUT.c usage_C0_Sleep_Wakeup
*******************************************************************************/
void C0_Sleep(void)
{
    #if defined(C0__PC)
        C0_backup.pcState = C0_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            C0_backup.usbState = C0_CR1_REG;
            C0_USB_POWER_REG |= C0_USBIO_ENTER_SLEEP;
            C0_CR1_REG &= C0_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(C0__SIO)
        C0_backup.sioState = C0_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        C0_SIO_REG &= (uint32)(~C0_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: C0_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to C0_Sleep() for an example usage.
*******************************************************************************/
void C0_Wakeup(void)
{
    #if defined(C0__PC)
        C0_PC = C0_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            C0_USB_POWER_REG &= C0_USBIO_EXIT_SLEEP_PH1;
            C0_CR1_REG = C0_backup.usbState;
            C0_USB_POWER_REG &= C0_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(C0__SIO)
        C0_SIO_REG = C0_backup.sioState;
    #endif
}


/* [] END OF FILE */
