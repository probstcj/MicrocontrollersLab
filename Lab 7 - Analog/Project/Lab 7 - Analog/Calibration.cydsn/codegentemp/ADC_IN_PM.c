/*******************************************************************************
* File Name: ADC_IN.c  
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
#include "ADC_IN.h"

static ADC_IN_BACKUP_STRUCT  ADC_IN_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: ADC_IN_Sleep
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
*  \snippet ADC_IN_SUT.c usage_ADC_IN_Sleep_Wakeup
*******************************************************************************/
void ADC_IN_Sleep(void)
{
    #if defined(ADC_IN__PC)
        ADC_IN_backup.pcState = ADC_IN_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            ADC_IN_backup.usbState = ADC_IN_CR1_REG;
            ADC_IN_USB_POWER_REG |= ADC_IN_USBIO_ENTER_SLEEP;
            ADC_IN_CR1_REG &= ADC_IN_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ADC_IN__SIO)
        ADC_IN_backup.sioState = ADC_IN_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        ADC_IN_SIO_REG &= (uint32)(~ADC_IN_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: ADC_IN_Wakeup
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
*  Refer to ADC_IN_Sleep() for an example usage.
*******************************************************************************/
void ADC_IN_Wakeup(void)
{
    #if defined(ADC_IN__PC)
        ADC_IN_PC = ADC_IN_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            ADC_IN_USB_POWER_REG &= ADC_IN_USBIO_EXIT_SLEEP_PH1;
            ADC_IN_CR1_REG = ADC_IN_backup.usbState;
            ADC_IN_USB_POWER_REG &= ADC_IN_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ADC_IN__SIO)
        ADC_IN_SIO_REG = ADC_IN_backup.sioState;
    #endif
}


/* [] END OF FILE */
