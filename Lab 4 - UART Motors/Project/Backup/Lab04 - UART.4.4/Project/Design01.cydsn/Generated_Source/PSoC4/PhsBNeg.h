/*******************************************************************************
* File Name: PhsBNeg.h  
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

#if !defined(CY_PINS_PhsBNeg_H) /* Pins PhsBNeg_H */
#define CY_PINS_PhsBNeg_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PhsBNeg_aliases.h"


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
} PhsBNeg_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PhsBNeg_Read(void);
void    PhsBNeg_Write(uint8 value);
uint8   PhsBNeg_ReadDataReg(void);
#if defined(PhsBNeg__PC) || (CY_PSOC4_4200L) 
    void    PhsBNeg_SetDriveMode(uint8 mode);
#endif
void    PhsBNeg_SetInterruptMode(uint16 position, uint16 mode);
uint8   PhsBNeg_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PhsBNeg_Sleep(void); 
void PhsBNeg_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PhsBNeg__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PhsBNeg_DRIVE_MODE_BITS        (3)
    #define PhsBNeg_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PhsBNeg_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PhsBNeg_SetDriveMode() function.
         *  @{
         */
        #define PhsBNeg_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PhsBNeg_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PhsBNeg_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PhsBNeg_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PhsBNeg_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PhsBNeg_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PhsBNeg_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PhsBNeg_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PhsBNeg_MASK               PhsBNeg__MASK
#define PhsBNeg_SHIFT              PhsBNeg__SHIFT
#define PhsBNeg_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PhsBNeg_SetInterruptMode() function.
     *  @{
     */
        #define PhsBNeg_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PhsBNeg_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PhsBNeg_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PhsBNeg_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PhsBNeg__SIO)
    #define PhsBNeg_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PhsBNeg__PC) && (CY_PSOC4_4200L)
    #define PhsBNeg_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PhsBNeg_USBIO_DISABLE              ((uint32)(~PhsBNeg_USBIO_ENABLE))
    #define PhsBNeg_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PhsBNeg_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PhsBNeg_USBIO_ENTER_SLEEP          ((uint32)((1u << PhsBNeg_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PhsBNeg_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsBNeg_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PhsBNeg_USBIO_SUSPEND_SHIFT)))
    #define PhsBNeg_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PhsBNeg_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsBNeg_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PhsBNeg__PC)
    /* Port Configuration */
    #define PhsBNeg_PC                 (* (reg32 *) PhsBNeg__PC)
#endif
/* Pin State */
#define PhsBNeg_PS                     (* (reg32 *) PhsBNeg__PS)
/* Data Register */
#define PhsBNeg_DR                     (* (reg32 *) PhsBNeg__DR)
/* Input Buffer Disable Override */
#define PhsBNeg_INP_DIS                (* (reg32 *) PhsBNeg__PC2)

/* Interrupt configuration Registers */
#define PhsBNeg_INTCFG                 (* (reg32 *) PhsBNeg__INTCFG)
#define PhsBNeg_INTSTAT                (* (reg32 *) PhsBNeg__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PhsBNeg_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PhsBNeg__SIO)
    #define PhsBNeg_SIO_REG            (* (reg32 *) PhsBNeg__SIO)
#endif /* (PhsBNeg__SIO_CFG) */

/* USBIO registers */
#if !defined(PhsBNeg__PC) && (CY_PSOC4_4200L)
    #define PhsBNeg_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PhsBNeg_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PhsBNeg_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PhsBNeg_DRIVE_MODE_SHIFT       (0x00u)
#define PhsBNeg_DRIVE_MODE_MASK        (0x07u << PhsBNeg_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PhsBNeg_H */


/* [] END OF FILE */
