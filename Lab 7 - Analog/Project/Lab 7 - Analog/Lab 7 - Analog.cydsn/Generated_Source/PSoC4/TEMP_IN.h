/*******************************************************************************
* File Name: TEMP_IN.h  
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

#if !defined(CY_PINS_TEMP_IN_H) /* Pins TEMP_IN_H */
#define CY_PINS_TEMP_IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TEMP_IN_aliases.h"


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
} TEMP_IN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   TEMP_IN_Read(void);
void    TEMP_IN_Write(uint8 value);
uint8   TEMP_IN_ReadDataReg(void);
#if defined(TEMP_IN__PC) || (CY_PSOC4_4200L) 
    void    TEMP_IN_SetDriveMode(uint8 mode);
#endif
void    TEMP_IN_SetInterruptMode(uint16 position, uint16 mode);
uint8   TEMP_IN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void TEMP_IN_Sleep(void); 
void TEMP_IN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(TEMP_IN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define TEMP_IN_DRIVE_MODE_BITS        (3)
    #define TEMP_IN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TEMP_IN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the TEMP_IN_SetDriveMode() function.
         *  @{
         */
        #define TEMP_IN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define TEMP_IN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define TEMP_IN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define TEMP_IN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define TEMP_IN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define TEMP_IN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define TEMP_IN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define TEMP_IN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define TEMP_IN_MASK               TEMP_IN__MASK
#define TEMP_IN_SHIFT              TEMP_IN__SHIFT
#define TEMP_IN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TEMP_IN_SetInterruptMode() function.
     *  @{
     */
        #define TEMP_IN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define TEMP_IN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define TEMP_IN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define TEMP_IN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(TEMP_IN__SIO)
    #define TEMP_IN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(TEMP_IN__PC) && (CY_PSOC4_4200L)
    #define TEMP_IN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define TEMP_IN_USBIO_DISABLE              ((uint32)(~TEMP_IN_USBIO_ENABLE))
    #define TEMP_IN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define TEMP_IN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define TEMP_IN_USBIO_ENTER_SLEEP          ((uint32)((1u << TEMP_IN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << TEMP_IN_USBIO_SUSPEND_DEL_SHIFT)))
    #define TEMP_IN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << TEMP_IN_USBIO_SUSPEND_SHIFT)))
    #define TEMP_IN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << TEMP_IN_USBIO_SUSPEND_DEL_SHIFT)))
    #define TEMP_IN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(TEMP_IN__PC)
    /* Port Configuration */
    #define TEMP_IN_PC                 (* (reg32 *) TEMP_IN__PC)
#endif
/* Pin State */
#define TEMP_IN_PS                     (* (reg32 *) TEMP_IN__PS)
/* Data Register */
#define TEMP_IN_DR                     (* (reg32 *) TEMP_IN__DR)
/* Input Buffer Disable Override */
#define TEMP_IN_INP_DIS                (* (reg32 *) TEMP_IN__PC2)

/* Interrupt configuration Registers */
#define TEMP_IN_INTCFG                 (* (reg32 *) TEMP_IN__INTCFG)
#define TEMP_IN_INTSTAT                (* (reg32 *) TEMP_IN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define TEMP_IN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(TEMP_IN__SIO)
    #define TEMP_IN_SIO_REG            (* (reg32 *) TEMP_IN__SIO)
#endif /* (TEMP_IN__SIO_CFG) */

/* USBIO registers */
#if !defined(TEMP_IN__PC) && (CY_PSOC4_4200L)
    #define TEMP_IN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define TEMP_IN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define TEMP_IN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define TEMP_IN_DRIVE_MODE_SHIFT       (0x00u)
#define TEMP_IN_DRIVE_MODE_MASK        (0x07u << TEMP_IN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins TEMP_IN_H */


/* [] END OF FILE */
