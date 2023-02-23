/*******************************************************************************
* File Name: PhsAPos.h  
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

#if !defined(CY_PINS_PhsAPos_H) /* Pins PhsAPos_H */
#define CY_PINS_PhsAPos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PhsAPos_aliases.h"


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
} PhsAPos_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PhsAPos_Read(void);
void    PhsAPos_Write(uint8 value);
uint8   PhsAPos_ReadDataReg(void);
#if defined(PhsAPos__PC) || (CY_PSOC4_4200L) 
    void    PhsAPos_SetDriveMode(uint8 mode);
#endif
void    PhsAPos_SetInterruptMode(uint16 position, uint16 mode);
uint8   PhsAPos_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PhsAPos_Sleep(void); 
void PhsAPos_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PhsAPos__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PhsAPos_DRIVE_MODE_BITS        (3)
    #define PhsAPos_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PhsAPos_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PhsAPos_SetDriveMode() function.
         *  @{
         */
        #define PhsAPos_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PhsAPos_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PhsAPos_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PhsAPos_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PhsAPos_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PhsAPos_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PhsAPos_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PhsAPos_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PhsAPos_MASK               PhsAPos__MASK
#define PhsAPos_SHIFT              PhsAPos__SHIFT
#define PhsAPos_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PhsAPos_SetInterruptMode() function.
     *  @{
     */
        #define PhsAPos_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PhsAPos_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PhsAPos_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PhsAPos_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PhsAPos__SIO)
    #define PhsAPos_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PhsAPos__PC) && (CY_PSOC4_4200L)
    #define PhsAPos_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PhsAPos_USBIO_DISABLE              ((uint32)(~PhsAPos_USBIO_ENABLE))
    #define PhsAPos_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PhsAPos_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PhsAPos_USBIO_ENTER_SLEEP          ((uint32)((1u << PhsAPos_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PhsAPos_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsAPos_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PhsAPos_USBIO_SUSPEND_SHIFT)))
    #define PhsAPos_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PhsAPos_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsAPos_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PhsAPos__PC)
    /* Port Configuration */
    #define PhsAPos_PC                 (* (reg32 *) PhsAPos__PC)
#endif
/* Pin State */
#define PhsAPos_PS                     (* (reg32 *) PhsAPos__PS)
/* Data Register */
#define PhsAPos_DR                     (* (reg32 *) PhsAPos__DR)
/* Input Buffer Disable Override */
#define PhsAPos_INP_DIS                (* (reg32 *) PhsAPos__PC2)

/* Interrupt configuration Registers */
#define PhsAPos_INTCFG                 (* (reg32 *) PhsAPos__INTCFG)
#define PhsAPos_INTSTAT                (* (reg32 *) PhsAPos__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PhsAPos_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PhsAPos__SIO)
    #define PhsAPos_SIO_REG            (* (reg32 *) PhsAPos__SIO)
#endif /* (PhsAPos__SIO_CFG) */

/* USBIO registers */
#if !defined(PhsAPos__PC) && (CY_PSOC4_4200L)
    #define PhsAPos_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PhsAPos_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PhsAPos_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PhsAPos_DRIVE_MODE_SHIFT       (0x00u)
#define PhsAPos_DRIVE_MODE_MASK        (0x07u << PhsAPos_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PhsAPos_H */


/* [] END OF FILE */
