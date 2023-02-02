/*******************************************************************************
* File Name: BTN.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BTN_ALIASES_H) /* Pins BTN_ALIASES_H */
#define CY_PINS_BTN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BTN_0			(BTN__0__PC)
#define BTN_0_PS		(BTN__0__PS)
#define BTN_0_PC		(BTN__0__PC)
#define BTN_0_DR		(BTN__0__DR)
#define BTN_0_SHIFT	(BTN__0__SHIFT)
#define BTN_0_INTR	((uint16)((uint16)0x0003u << (BTN__0__SHIFT*2u)))

#define BTN_1			(BTN__1__PC)
#define BTN_1_PS		(BTN__1__PS)
#define BTN_1_PC		(BTN__1__PC)
#define BTN_1_DR		(BTN__1__DR)
#define BTN_1_SHIFT	(BTN__1__SHIFT)
#define BTN_1_INTR	((uint16)((uint16)0x0003u << (BTN__1__SHIFT*2u)))

#define BTN_2			(BTN__2__PC)
#define BTN_2_PS		(BTN__2__PS)
#define BTN_2_PC		(BTN__2__PC)
#define BTN_2_DR		(BTN__2__DR)
#define BTN_2_SHIFT	(BTN__2__SHIFT)
#define BTN_2_INTR	((uint16)((uint16)0x0003u << (BTN__2__SHIFT*2u)))

#define BTN_3			(BTN__3__PC)
#define BTN_3_PS		(BTN__3__PS)
#define BTN_3_PC		(BTN__3__PC)
#define BTN_3_DR		(BTN__3__DR)
#define BTN_3_SHIFT	(BTN__3__SHIFT)
#define BTN_3_INTR	((uint16)((uint16)0x0003u << (BTN__3__SHIFT*2u)))

#define BTN_INTR_ALL	 ((uint16)(BTN_0_INTR| BTN_1_INTR| BTN_2_INTR| BTN_3_INTR))


#endif /* End Pins BTN_ALIASES_H */


/* [] END OF FILE */
