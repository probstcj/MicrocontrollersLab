/*******************************************************************************
* File Name: CLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CLK_H)
#define CY_CLOCK_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void CLK_StartEx(uint32 alignClkDiv);
#define CLK_Start() \
    CLK_StartEx(CLK__PA_DIV_ID)

#else

void CLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void CLK_Stop(void);

void CLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 CLK_GetDividerRegister(void);
uint8  CLK_GetFractionalDividerRegister(void);

#define CLK_Enable()                         CLK_Start()
#define CLK_Disable()                        CLK_Stop()
#define CLK_SetDividerRegister(clkDivider, reset)  \
    CLK_SetFractionalDividerRegister((clkDivider), 0u)
#define CLK_SetDivider(clkDivider)           CLK_SetDividerRegister((clkDivider), 1u)
#define CLK_SetDividerValue(clkDivider)      CLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define CLK_DIV_ID     CLK__DIV_ID

#define CLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define CLK_CTRL_REG   (*(reg32 *)CLK__CTRL_REGISTER)
#define CLK_DIV_REG    (*(reg32 *)CLK__DIV_REGISTER)

#define CLK_CMD_DIV_SHIFT          (0u)
#define CLK_CMD_PA_DIV_SHIFT       (8u)
#define CLK_CMD_DISABLE_SHIFT      (30u)
#define CLK_CMD_ENABLE_SHIFT       (31u)

#define CLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << CLK_CMD_DISABLE_SHIFT))
#define CLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << CLK_CMD_ENABLE_SHIFT))

#define CLK_DIV_FRAC_MASK  (0x000000F8u)
#define CLK_DIV_FRAC_SHIFT (3u)
#define CLK_DIV_INT_MASK   (0xFFFFFF00u)
#define CLK_DIV_INT_SHIFT  (8u)

#else 

#define CLK_DIV_REG        (*(reg32 *)CLK__REGISTER)
#define CLK_ENABLE_REG     CLK_DIV_REG
#define CLK_DIV_FRAC_MASK  CLK__FRAC_MASK
#define CLK_DIV_FRAC_SHIFT (16u)
#define CLK_DIV_INT_MASK   CLK__DIVIDER_MASK
#define CLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_CLK_H) */

/* [] END OF FILE */
