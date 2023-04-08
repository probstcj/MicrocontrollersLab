/*******************************************************************************
* File Name: NRF24_CE.c  
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
#include "NRF24_CE.h"

static NRF24_CE_BACKUP_STRUCT  NRF24_CE_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: NRF24_CE_Sleep
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
*  \snippet NRF24_CE_SUT.c usage_NRF24_CE_Sleep_Wakeup
*******************************************************************************/
void NRF24_CE_Sleep(void)
{
    #if defined(NRF24_CE__PC)
        NRF24_CE_backup.pcState = NRF24_CE_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            NRF24_CE_backup.usbState = NRF24_CE_CR1_REG;
            NRF24_CE_USB_POWER_REG |= NRF24_CE_USBIO_ENTER_SLEEP;
            NRF24_CE_CR1_REG &= NRF24_CE_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(NRF24_CE__SIO)
        NRF24_CE_backup.sioState = NRF24_CE_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        NRF24_CE_SIO_REG &= (uint32)(~NRF24_CE_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: NRF24_CE_Wakeup
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
*  Refer to NRF24_CE_Sleep() for an example usage.
*******************************************************************************/
void NRF24_CE_Wakeup(void)
{
    #if defined(NRF24_CE__PC)
        NRF24_CE_PC = NRF24_CE_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            NRF24_CE_USB_POWER_REG &= NRF24_CE_USBIO_EXIT_SLEEP_PH1;
            NRF24_CE_CR1_REG = NRF24_CE_backup.usbState;
            NRF24_CE_USB_POWER_REG &= NRF24_CE_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(NRF24_CE__SIO)
        NRF24_CE_SIO_REG = NRF24_CE_backup.sioState;
    #endif
}


/* [] END OF FILE */
