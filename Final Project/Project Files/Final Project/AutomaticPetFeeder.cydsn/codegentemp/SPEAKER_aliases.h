/*******************************************************************************
* File Name: SPEAKER.h  
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

#if !defined(CY_PINS_SPEAKER_ALIASES_H) /* Pins SPEAKER_ALIASES_H */
#define CY_PINS_SPEAKER_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SPEAKER_0			(SPEAKER__0__PC)
#define SPEAKER_0_PS		(SPEAKER__0__PS)
#define SPEAKER_0_PC		(SPEAKER__0__PC)
#define SPEAKER_0_DR		(SPEAKER__0__DR)
#define SPEAKER_0_SHIFT	(SPEAKER__0__SHIFT)
#define SPEAKER_0_INTR	((uint16)((uint16)0x0003u << (SPEAKER__0__SHIFT*2u)))

#define SPEAKER_INTR_ALL	 ((uint16)(SPEAKER_0_INTR))


#endif /* End Pins SPEAKER_ALIASES_H */


/* [] END OF FILE */
