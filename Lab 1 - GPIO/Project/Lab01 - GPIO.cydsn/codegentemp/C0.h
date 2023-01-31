/*******************************************************************************
* File Name: C0.h  
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

#if !defined(CY_PINS_C0_H) /* Pins C0_H */
#define CY_PINS_C0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "C0_aliases.h"


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
} C0_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   C0_Read(void);
void    C0_Write(uint8 value);
uint8   C0_ReadDataReg(void);
#if defined(C0__PC) || (CY_PSOC4_4200L) 
    void    C0_SetDriveMode(uint8 mode);
#endif
void    C0_SetInterruptMode(uint16 position, uint16 mode);
uint8   C0_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void C0_Sleep(void); 
void C0_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(C0__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define C0_DRIVE_MODE_BITS        (3)
    #define C0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - C0_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the C0_SetDriveMode() function.
         *  @{
         */
        #define C0_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define C0_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define C0_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define C0_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define C0_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define C0_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define C0_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define C0_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define C0_MASK               C0__MASK
#define C0_SHIFT              C0__SHIFT
#define C0_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C0_SetInterruptMode() function.
     *  @{
     */
        #define C0_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define C0_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define C0_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define C0_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(C0__SIO)
    #define C0_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(C0__PC) && (CY_PSOC4_4200L)
    #define C0_USBIO_ENABLE               ((uint32)0x80000000u)
    #define C0_USBIO_DISABLE              ((uint32)(~C0_USBIO_ENABLE))
    #define C0_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define C0_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define C0_USBIO_ENTER_SLEEP          ((uint32)((1u << C0_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << C0_USBIO_SUSPEND_DEL_SHIFT)))
    #define C0_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << C0_USBIO_SUSPEND_SHIFT)))
    #define C0_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << C0_USBIO_SUSPEND_DEL_SHIFT)))
    #define C0_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(C0__PC)
    /* Port Configuration */
    #define C0_PC                 (* (reg32 *) C0__PC)
#endif
/* Pin State */
#define C0_PS                     (* (reg32 *) C0__PS)
/* Data Register */
#define C0_DR                     (* (reg32 *) C0__DR)
/* Input Buffer Disable Override */
#define C0_INP_DIS                (* (reg32 *) C0__PC2)

/* Interrupt configuration Registers */
#define C0_INTCFG                 (* (reg32 *) C0__INTCFG)
#define C0_INTSTAT                (* (reg32 *) C0__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define C0_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(C0__SIO)
    #define C0_SIO_REG            (* (reg32 *) C0__SIO)
#endif /* (C0__SIO_CFG) */

/* USBIO registers */
#if !defined(C0__PC) && (CY_PSOC4_4200L)
    #define C0_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define C0_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define C0_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define C0_DRIVE_MODE_SHIFT       (0x00u)
#define C0_DRIVE_MODE_MASK        (0x07u << C0_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins C0_H */


/* [] END OF FILE */
