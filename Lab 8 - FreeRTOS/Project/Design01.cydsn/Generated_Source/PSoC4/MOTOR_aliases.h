/*******************************************************************************
* File Name: MOTOR.h  
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

#if !defined(CY_PINS_MOTOR_ALIASES_H) /* Pins MOTOR_ALIASES_H */
#define CY_PINS_MOTOR_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MOTOR_0			(MOTOR__0__PC)
#define MOTOR_0_PS		(MOTOR__0__PS)
#define MOTOR_0_PC		(MOTOR__0__PC)
#define MOTOR_0_DR		(MOTOR__0__DR)
#define MOTOR_0_SHIFT	(MOTOR__0__SHIFT)
#define MOTOR_0_INTR	((uint16)((uint16)0x0003u << (MOTOR__0__SHIFT*2u)))

#define MOTOR_1			(MOTOR__1__PC)
#define MOTOR_1_PS		(MOTOR__1__PS)
#define MOTOR_1_PC		(MOTOR__1__PC)
#define MOTOR_1_DR		(MOTOR__1__DR)
#define MOTOR_1_SHIFT	(MOTOR__1__SHIFT)
#define MOTOR_1_INTR	((uint16)((uint16)0x0003u << (MOTOR__1__SHIFT*2u)))

#define MOTOR_2			(MOTOR__2__PC)
#define MOTOR_2_PS		(MOTOR__2__PS)
#define MOTOR_2_PC		(MOTOR__2__PC)
#define MOTOR_2_DR		(MOTOR__2__DR)
#define MOTOR_2_SHIFT	(MOTOR__2__SHIFT)
#define MOTOR_2_INTR	((uint16)((uint16)0x0003u << (MOTOR__2__SHIFT*2u)))

#define MOTOR_3			(MOTOR__3__PC)
#define MOTOR_3_PS		(MOTOR__3__PS)
#define MOTOR_3_PC		(MOTOR__3__PC)
#define MOTOR_3_DR		(MOTOR__3__DR)
#define MOTOR_3_SHIFT	(MOTOR__3__SHIFT)
#define MOTOR_3_INTR	((uint16)((uint16)0x0003u << (MOTOR__3__SHIFT*2u)))

#define MOTOR_INTR_ALL	 ((uint16)(MOTOR_0_INTR| MOTOR_1_INTR| MOTOR_2_INTR| MOTOR_3_INTR))


#endif /* End Pins MOTOR_ALIASES_H */


/* [] END OF FILE */
