/*******************************************************************************
* File Name: RTC_COT_IN.h  
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

#if !defined(CY_PINS_RTC_COT_IN_H) /* Pins RTC_COT_IN_H */
#define CY_PINS_RTC_COT_IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RTC_COT_IN_aliases.h"


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
} RTC_COT_IN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   RTC_COT_IN_Read(void);
void    RTC_COT_IN_Write(uint8 value);
uint8   RTC_COT_IN_ReadDataReg(void);
#if defined(RTC_COT_IN__PC) || (CY_PSOC4_4200L) 
    void    RTC_COT_IN_SetDriveMode(uint8 mode);
#endif
void    RTC_COT_IN_SetInterruptMode(uint16 position, uint16 mode);
uint8   RTC_COT_IN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void RTC_COT_IN_Sleep(void); 
void RTC_COT_IN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(RTC_COT_IN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define RTC_COT_IN_DRIVE_MODE_BITS        (3)
    #define RTC_COT_IN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RTC_COT_IN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the RTC_COT_IN_SetDriveMode() function.
         *  @{
         */
        #define RTC_COT_IN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define RTC_COT_IN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define RTC_COT_IN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define RTC_COT_IN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define RTC_COT_IN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define RTC_COT_IN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define RTC_COT_IN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define RTC_COT_IN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define RTC_COT_IN_MASK               RTC_COT_IN__MASK
#define RTC_COT_IN_SHIFT              RTC_COT_IN__SHIFT
#define RTC_COT_IN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RTC_COT_IN_SetInterruptMode() function.
     *  @{
     */
        #define RTC_COT_IN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define RTC_COT_IN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define RTC_COT_IN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define RTC_COT_IN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(RTC_COT_IN__SIO)
    #define RTC_COT_IN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(RTC_COT_IN__PC) && (CY_PSOC4_4200L)
    #define RTC_COT_IN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define RTC_COT_IN_USBIO_DISABLE              ((uint32)(~RTC_COT_IN_USBIO_ENABLE))
    #define RTC_COT_IN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define RTC_COT_IN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define RTC_COT_IN_USBIO_ENTER_SLEEP          ((uint32)((1u << RTC_COT_IN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << RTC_COT_IN_USBIO_SUSPEND_DEL_SHIFT)))
    #define RTC_COT_IN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << RTC_COT_IN_USBIO_SUSPEND_SHIFT)))
    #define RTC_COT_IN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << RTC_COT_IN_USBIO_SUSPEND_DEL_SHIFT)))
    #define RTC_COT_IN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(RTC_COT_IN__PC)
    /* Port Configuration */
    #define RTC_COT_IN_PC                 (* (reg32 *) RTC_COT_IN__PC)
#endif
/* Pin State */
#define RTC_COT_IN_PS                     (* (reg32 *) RTC_COT_IN__PS)
/* Data Register */
#define RTC_COT_IN_DR                     (* (reg32 *) RTC_COT_IN__DR)
/* Input Buffer Disable Override */
#define RTC_COT_IN_INP_DIS                (* (reg32 *) RTC_COT_IN__PC2)

/* Interrupt configuration Registers */
#define RTC_COT_IN_INTCFG                 (* (reg32 *) RTC_COT_IN__INTCFG)
#define RTC_COT_IN_INTSTAT                (* (reg32 *) RTC_COT_IN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define RTC_COT_IN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(RTC_COT_IN__SIO)
    #define RTC_COT_IN_SIO_REG            (* (reg32 *) RTC_COT_IN__SIO)
#endif /* (RTC_COT_IN__SIO_CFG) */

/* USBIO registers */
#if !defined(RTC_COT_IN__PC) && (CY_PSOC4_4200L)
    #define RTC_COT_IN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define RTC_COT_IN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define RTC_COT_IN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define RTC_COT_IN_DRIVE_MODE_SHIFT       (0x00u)
#define RTC_COT_IN_DRIVE_MODE_MASK        (0x07u << RTC_COT_IN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins RTC_COT_IN_H */


/* [] END OF FILE */
