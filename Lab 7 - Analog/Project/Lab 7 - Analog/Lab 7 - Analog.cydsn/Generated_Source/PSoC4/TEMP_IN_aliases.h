/*******************************************************************************
* File Name: TEMP_IN.h  
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

#if !defined(CY_PINS_TEMP_IN_ALIASES_H) /* Pins TEMP_IN_ALIASES_H */
#define CY_PINS_TEMP_IN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define TEMP_IN_0			(TEMP_IN__0__PC)
#define TEMP_IN_0_PS		(TEMP_IN__0__PS)
#define TEMP_IN_0_PC		(TEMP_IN__0__PC)
#define TEMP_IN_0_DR		(TEMP_IN__0__DR)
#define TEMP_IN_0_SHIFT	(TEMP_IN__0__SHIFT)
#define TEMP_IN_0_INTR	((uint16)((uint16)0x0003u << (TEMP_IN__0__SHIFT*2u)))

#define TEMP_IN_INTR_ALL	 ((uint16)(TEMP_IN_0_INTR))


#endif /* End Pins TEMP_IN_ALIASES_H */


/* [] END OF FILE */
