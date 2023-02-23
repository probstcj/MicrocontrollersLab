/*******************************************************************************
* File Name: PhsAPos.h  
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

#if !defined(CY_PINS_PhsAPos_ALIASES_H) /* Pins PhsAPos_ALIASES_H */
#define CY_PINS_PhsAPos_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PhsAPos_0			(PhsAPos__0__PC)
#define PhsAPos_0_PS		(PhsAPos__0__PS)
#define PhsAPos_0_PC		(PhsAPos__0__PC)
#define PhsAPos_0_DR		(PhsAPos__0__DR)
#define PhsAPos_0_SHIFT	(PhsAPos__0__SHIFT)
#define PhsAPos_0_INTR	((uint16)((uint16)0x0003u << (PhsAPos__0__SHIFT*2u)))

#define PhsAPos_INTR_ALL	 ((uint16)(PhsAPos_0_INTR))


#endif /* End Pins PhsAPos_ALIASES_H */


/* [] END OF FILE */
