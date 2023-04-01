/*******************************************************************************
* File Name: ENC.h  
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

#if !defined(CY_PINS_ENC_ALIASES_H) /* Pins ENC_ALIASES_H */
#define CY_PINS_ENC_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ENC_0			(ENC__0__PC)
#define ENC_0_PS		(ENC__0__PS)
#define ENC_0_PC		(ENC__0__PC)
#define ENC_0_DR		(ENC__0__DR)
#define ENC_0_SHIFT	(ENC__0__SHIFT)
#define ENC_0_INTR	((uint16)((uint16)0x0003u << (ENC__0__SHIFT*2u)))

#define ENC_1			(ENC__1__PC)
#define ENC_1_PS		(ENC__1__PS)
#define ENC_1_PC		(ENC__1__PC)
#define ENC_1_DR		(ENC__1__DR)
#define ENC_1_SHIFT	(ENC__1__SHIFT)
#define ENC_1_INTR	((uint16)((uint16)0x0003u << (ENC__1__SHIFT*2u)))

#define ENC_INTR_ALL	 ((uint16)(ENC_0_INTR| ENC_1_INTR))


#endif /* End Pins ENC_ALIASES_H */


/* [] END OF FILE */
