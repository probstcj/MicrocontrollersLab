/*******************************************************************************
* File Name: C2.h  
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

#if !defined(CY_PINS_C2_ALIASES_H) /* Pins C2_ALIASES_H */
#define CY_PINS_C2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define C2_0			(C2__0__PC)
#define C2_0_PS		(C2__0__PS)
#define C2_0_PC		(C2__0__PC)
#define C2_0_DR		(C2__0__DR)
#define C2_0_SHIFT	(C2__0__SHIFT)
#define C2_0_INTR	((uint16)((uint16)0x0003u << (C2__0__SHIFT*2u)))

#define C2_INTR_ALL	 ((uint16)(C2_0_INTR))


#endif /* End Pins C2_ALIASES_H */


/* [] END OF FILE */
