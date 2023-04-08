/*******************************************************************************
* File Name: PhsANeg.h  
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

#if !defined(CY_PINS_PhsANeg_H) /* Pins PhsANeg_H */
#define CY_PINS_PhsANeg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PhsANeg_aliases.h"


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
} PhsANeg_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PhsANeg_Read(void);
void    PhsANeg_Write(uint8 value);
uint8   PhsANeg_ReadDataReg(void);
#if defined(PhsANeg__PC) || (CY_PSOC4_4200L) 
    void    PhsANeg_SetDriveMode(uint8 mode);
#endif
void    PhsANeg_SetInterruptMode(uint16 position, uint16 mode);
uint8   PhsANeg_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PhsANeg_Sleep(void); 
void PhsANeg_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PhsANeg__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PhsANeg_DRIVE_MODE_BITS        (3)
    #define PhsANeg_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PhsANeg_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PhsANeg_SetDriveMode() function.
         *  @{
         */
        #define PhsANeg_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PhsANeg_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PhsANeg_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PhsANeg_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PhsANeg_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PhsANeg_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PhsANeg_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PhsANeg_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PhsANeg_MASK               PhsANeg__MASK
#define PhsANeg_SHIFT              PhsANeg__SHIFT
#define PhsANeg_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PhsANeg_SetInterruptMode() function.
     *  @{
     */
        #define PhsANeg_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PhsANeg_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PhsANeg_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PhsANeg_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PhsANeg__SIO)
    #define PhsANeg_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PhsANeg__PC) && (CY_PSOC4_4200L)
    #define PhsANeg_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PhsANeg_USBIO_DISABLE              ((uint32)(~PhsANeg_USBIO_ENABLE))
    #define PhsANeg_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PhsANeg_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PhsANeg_USBIO_ENTER_SLEEP          ((uint32)((1u << PhsANeg_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PhsANeg_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsANeg_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PhsANeg_USBIO_SUSPEND_SHIFT)))
    #define PhsANeg_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PhsANeg_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsANeg_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PhsANeg__PC)
    /* Port Configuration */
    #define PhsANeg_PC                 (* (reg32 *) PhsANeg__PC)
#endif
/* Pin State */
#define PhsANeg_PS                     (* (reg32 *) PhsANeg__PS)
/* Data Register */
#define PhsANeg_DR                     (* (reg32 *) PhsANeg__DR)
/* Input Buffer Disable Override */
#define PhsANeg_INP_DIS                (* (reg32 *) PhsANeg__PC2)

/* Interrupt configuration Registers */
#define PhsANeg_INTCFG                 (* (reg32 *) PhsANeg__INTCFG)
#define PhsANeg_INTSTAT                (* (reg32 *) PhsANeg__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PhsANeg_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PhsANeg__SIO)
    #define PhsANeg_SIO_REG            (* (reg32 *) PhsANeg__SIO)
#endif /* (PhsANeg__SIO_CFG) */

/* USBIO registers */
#if !defined(PhsANeg__PC) && (CY_PSOC4_4200L)
    #define PhsANeg_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PhsANeg_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PhsANeg_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PhsANeg_DRIVE_MODE_SHIFT       (0x00u)
#define PhsANeg_DRIVE_MODE_MASK        (0x07u << PhsANeg_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PhsANeg_H */


/* [] END OF FILE */
