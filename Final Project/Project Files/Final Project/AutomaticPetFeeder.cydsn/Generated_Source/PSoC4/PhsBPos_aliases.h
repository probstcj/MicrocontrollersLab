/*******************************************************************************
* File Name: PhsBPos.h  
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

#if !defined(CY_PINS_PhsBPos_ALIASES_H) /* Pins PhsBPos_ALIASES_H */
#define CY_PINS_PhsBPos_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PhsBPos_0			(PhsBPos__0__PC)
#define PhsBPos_0_PS		(PhsBPos__0__PS)
#define PhsBPos_0_PC		(PhsBPos__0__PC)
#define PhsBPos_0_DR		(PhsBPos__0__DR)
#define PhsBPos_0_SHIFT	(PhsBPos__0__SHIFT)
#define PhsBPos_0_INTR	((uint16)((uint16)0x0003u << (PhsBPos__0__SHIFT*2u)))

#define PhsBPos_INTR_ALL	 ((uint16)(PhsBPos_0_INTR))


#endif /* End Pins PhsBPos_ALIASES_H */


/* [] END OF FILE */
