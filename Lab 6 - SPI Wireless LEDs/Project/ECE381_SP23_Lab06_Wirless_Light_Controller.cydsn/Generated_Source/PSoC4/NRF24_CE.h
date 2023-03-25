/*******************************************************************************
* File Name: NRF24_CE.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_NRF24_CE_H) /* Pins NRF24_CE_H */
#define CY_PINS_NRF24_CE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NRF24_CE_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} NRF24_CE_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   NRF24_CE_Read(void);
void    NRF24_CE_Write(uint8 value);
uint8   NRF24_CE_ReadDataReg(void);
#if defined(NRF24_CE__PC) || (CY_PSOC4_4200L) 
    void    NRF24_CE_SetDriveMode(uint8 mode);
#endif
void    NRF24_CE_SetInterruptMode(uint16 position, uint16 mode);
uint8   NRF24_CE_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void NRF24_CE_Sleep(void); 
void NRF24_CE_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(NRF24_CE__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define NRF24_CE_DRIVE_MODE_BITS        (3)
    #define NRF24_CE_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NRF24_CE_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the NRF24_CE_SetDriveMode() function.
         *  @{
         */
        #define NRF24_CE_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define NRF24_CE_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define NRF24_CE_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define NRF24_CE_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define NRF24_CE_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define NRF24_CE_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define NRF24_CE_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define NRF24_CE_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define NRF24_CE_MASK               NRF24_CE__MASK
#define NRF24_CE_SHIFT              NRF24_CE__SHIFT
#define NRF24_CE_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in NRF24_CE_SetInterruptMode() function.
     *  @{
     */
        #define NRF24_CE_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define NRF24_CE_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define NRF24_CE_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define NRF24_CE_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(NRF24_CE__SIO)
    #define NRF24_CE_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(NRF24_CE__PC) && (CY_PSOC4_4200L)
    #define NRF24_CE_USBIO_ENABLE               ((uint32)0x80000000u)
    #define NRF24_CE_USBIO_DISABLE              ((uint32)(~NRF24_CE_USBIO_ENABLE))
    #define NRF24_CE_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define NRF24_CE_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define NRF24_CE_USBIO_ENTER_SLEEP          ((uint32)((1u << NRF24_CE_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << NRF24_CE_USBIO_SUSPEND_DEL_SHIFT)))
    #define NRF24_CE_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << NRF24_CE_USBIO_SUSPEND_SHIFT)))
    #define NRF24_CE_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << NRF24_CE_USBIO_SUSPEND_DEL_SHIFT)))
    #define NRF24_CE_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(NRF24_CE__PC)
    /* Port Configuration */
    #define NRF24_CE_PC                 (* (reg32 *) NRF24_CE__PC)
#endif
/* Pin State */
#define NRF24_CE_PS                     (* (reg32 *) NRF24_CE__PS)
/* Data Register */
#define NRF24_CE_DR                     (* (reg32 *) NRF24_CE__DR)
/* Input Buffer Disable Override */
#define NRF24_CE_INP_DIS                (* (reg32 *) NRF24_CE__PC2)

/* Interrupt configuration Registers */
#define NRF24_CE_INTCFG                 (* (reg32 *) NRF24_CE__INTCFG)
#define NRF24_CE_INTSTAT                (* (reg32 *) NRF24_CE__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define NRF24_CE_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(NRF24_CE__SIO)
    #define NRF24_CE_SIO_REG            (* (reg32 *) NRF24_CE__SIO)
#endif /* (NRF24_CE__SIO_CFG) */

/* USBIO registers */
#if !defined(NRF24_CE__PC) && (CY_PSOC4_4200L)
    #define NRF24_CE_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define NRF24_CE_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define NRF24_CE_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define NRF24_CE_DRIVE_MODE_SHIFT       (0x00u)
#define NRF24_CE_DRIVE_MODE_MASK        (0x07u << NRF24_CE_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins NRF24_CE_H */


/* [] END OF FILE */
