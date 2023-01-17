/*******************************************************************************
* File Name: C0.h  
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

#if !defined(CY_PINS_C0_ALIASES_H) /* Pins C0_ALIASES_H */
#define CY_PINS_C0_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define C0_0			(C0__0__PC)
#define C0_0_PS		(C0__0__PS)
#define C0_0_PC		(C0__0__PC)
#define C0_0_DR		(C0__0__DR)
#define C0_0_SHIFT	(C0__0__SHIFT)
#define C0_0_INTR	((uint16)((uint16)0x0003u << (C0__0__SHIFT*2u)))

#define C0_INTR_ALL	 ((uint16)(C0_0_INTR))


#endif /* End Pins C0_ALIASES_H */


/* [] END OF FILE */
