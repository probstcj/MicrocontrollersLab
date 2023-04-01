/*******************************************************************************
* File Name: PhsBPos.c  
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
#include "PhsBPos.h"

static PhsBPos_BACKUP_STRUCT  PhsBPos_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: PhsBPos_Sleep
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
*  \snippet PhsBPos_SUT.c usage_PhsBPos_Sleep_Wakeup
*******************************************************************************/
void PhsBPos_Sleep(void)
{
    #if defined(PhsBPos__PC)
        PhsBPos_backup.pcState = PhsBPos_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            PhsBPos_backup.usbState = PhsBPos_CR1_REG;
            PhsBPos_USB_POWER_REG |= PhsBPos_USBIO_ENTER_SLEEP;
            PhsBPos_CR1_REG &= PhsBPos_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PhsBPos__SIO)
        PhsBPos_backup.sioState = PhsBPos_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        PhsBPos_SIO_REG &= (uint32)(~PhsBPos_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: PhsBPos_Wakeup
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
*  Refer to PhsBPos_Sleep() for an example usage.
*******************************************************************************/
void PhsBPos_Wakeup(void)
{
    #if defined(PhsBPos__PC)
        PhsBPos_PC = PhsBPos_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            PhsBPos_USB_POWER_REG &= PhsBPos_USBIO_EXIT_SLEEP_PH1;
            PhsBPos_CR1_REG = PhsBPos_backup.usbState;
            PhsBPos_USB_POWER_REG &= PhsBPos_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(PhsBPos__SIO)
        PhsBPos_SIO_REG = PhsBPos_backup.sioState;
    #endif
}


/* [] END OF FILE */
