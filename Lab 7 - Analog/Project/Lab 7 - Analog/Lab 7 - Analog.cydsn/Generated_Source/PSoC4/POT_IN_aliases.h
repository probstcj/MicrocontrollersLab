/*******************************************************************************
* File Name: POT_IN.h  
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

#if !defined(CY_PINS_POT_IN_ALIASES_H) /* Pins POT_IN_ALIASES_H */
#define CY_PINS_POT_IN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define POT_IN_0			(POT_IN__0__PC)
#define POT_IN_0_PS		(POT_IN__0__PS)
#define POT_IN_0_PC		(POT_IN__0__PC)
#define POT_IN_0_DR		(POT_IN__0__DR)
#define POT_IN_0_SHIFT	(POT_IN__0__SHIFT)
#define POT_IN_0_INTR	((uint16)((uint16)0x0003u << (POT_IN__0__SHIFT*2u)))

#define POT_IN_INTR_ALL	 ((uint16)(POT_IN_0_INTR))


#endif /* End Pins POT_IN_ALIASES_H */


/* [] END OF FILE */
