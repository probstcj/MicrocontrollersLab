/*******************************************************************************
* File Name: PhsBNeg.h  
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

#if !defined(CY_PINS_PhsBNeg_ALIASES_H) /* Pins PhsBNeg_ALIASES_H */
#define CY_PINS_PhsBNeg_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define PhsBNeg_0			(PhsBNeg__0__PC)
#define PhsBNeg_0_PS		(PhsBNeg__0__PS)
#define PhsBNeg_0_PC		(PhsBNeg__0__PC)
#define PhsBNeg_0_DR		(PhsBNeg__0__DR)
#define PhsBNeg_0_SHIFT	(PhsBNeg__0__SHIFT)
#define PhsBNeg_0_INTR	((uint16)((uint16)0x0003u << (PhsBNeg__0__SHIFT*2u)))

#define PhsBNeg_INTR_ALL	 ((uint16)(PhsBNeg_0_INTR))


#endif /* End Pins PhsBNeg_ALIASES_H */


/* [] END OF FILE */
