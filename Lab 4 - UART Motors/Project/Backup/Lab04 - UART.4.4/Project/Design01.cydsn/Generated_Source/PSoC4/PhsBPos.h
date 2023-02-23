/*******************************************************************************
* File Name: PhsBPos.h  
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

#if !defined(CY_PINS_PhsBPos_H) /* Pins PhsBPos_H */
#define CY_PINS_PhsBPos_H

#include "cytypes.h"
#include "cyfitter.h"
#include "PhsBPos_aliases.h"


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
} PhsBPos_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   PhsBPos_Read(void);
void    PhsBPos_Write(uint8 value);
uint8   PhsBPos_ReadDataReg(void);
#if defined(PhsBPos__PC) || (CY_PSOC4_4200L) 
    void    PhsBPos_SetDriveMode(uint8 mode);
#endif
void    PhsBPos_SetInterruptMode(uint16 position, uint16 mode);
uint8   PhsBPos_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void PhsBPos_Sleep(void); 
void PhsBPos_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(PhsBPos__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define PhsBPos_DRIVE_MODE_BITS        (3)
    #define PhsBPos_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - PhsBPos_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the PhsBPos_SetDriveMode() function.
         *  @{
         */
        #define PhsBPos_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define PhsBPos_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define PhsBPos_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define PhsBPos_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define PhsBPos_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define PhsBPos_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define PhsBPos_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define PhsBPos_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define PhsBPos_MASK               PhsBPos__MASK
#define PhsBPos_SHIFT              PhsBPos__SHIFT
#define PhsBPos_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PhsBPos_SetInterruptMode() function.
     *  @{
     */
        #define PhsBPos_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define PhsBPos_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define PhsBPos_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define PhsBPos_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(PhsBPos__SIO)
    #define PhsBPos_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(PhsBPos__PC) && (CY_PSOC4_4200L)
    #define PhsBPos_USBIO_ENABLE               ((uint32)0x80000000u)
    #define PhsBPos_USBIO_DISABLE              ((uint32)(~PhsBPos_USBIO_ENABLE))
    #define PhsBPos_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define PhsBPos_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define PhsBPos_USBIO_ENTER_SLEEP          ((uint32)((1u << PhsBPos_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << PhsBPos_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsBPos_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << PhsBPos_USBIO_SUSPEND_SHIFT)))
    #define PhsBPos_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << PhsBPos_USBIO_SUSPEND_DEL_SHIFT)))
    #define PhsBPos_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(PhsBPos__PC)
    /* Port Configuration */
    #define PhsBPos_PC                 (* (reg32 *) PhsBPos__PC)
#endif
/* Pin State */
#define PhsBPos_PS                     (* (reg32 *) PhsBPos__PS)
/* Data Register */
#define PhsBPos_DR                     (* (reg32 *) PhsBPos__DR)
/* Input Buffer Disable Override */
#define PhsBPos_INP_DIS                (* (reg32 *) PhsBPos__PC2)

/* Interrupt configuration Registers */
#define PhsBPos_INTCFG                 (* (reg32 *) PhsBPos__INTCFG)
#define PhsBPos_INTSTAT                (* (reg32 *) PhsBPos__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define PhsBPos_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(PhsBPos__SIO)
    #define PhsBPos_SIO_REG            (* (reg32 *) PhsBPos__SIO)
#endif /* (PhsBPos__SIO_CFG) */

/* USBIO registers */
#if !defined(PhsBPos__PC) && (CY_PSOC4_4200L)
    #define PhsBPos_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define PhsBPos_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define PhsBPos_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define PhsBPos_DRIVE_MODE_SHIFT       (0x00u)
#define PhsBPos_DRIVE_MODE_MASK        (0x07u << PhsBPos_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins PhsBPos_H */


/* [] END OF FILE */
