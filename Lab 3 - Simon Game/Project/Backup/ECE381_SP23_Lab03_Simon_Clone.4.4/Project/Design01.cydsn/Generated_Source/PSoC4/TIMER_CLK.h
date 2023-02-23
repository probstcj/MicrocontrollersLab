/*******************************************************************************
* File Name: TIMER_CLK.h
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

#if !defined(CY_CLOCK_TIMER_CLK_H)
#define CY_CLOCK_TIMER_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void TIMER_CLK_StartEx(uint32 alignClkDiv);
#define TIMER_CLK_Start() \
    TIMER_CLK_StartEx(TIMER_CLK__PA_DIV_ID)

#else

void TIMER_CLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void TIMER_CLK_Stop(void);

void TIMER_CLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 TIMER_CLK_GetDividerRegister(void);
uint8  TIMER_CLK_GetFractionalDividerRegister(void);

#define TIMER_CLK_Enable()                         TIMER_CLK_Start()
#define TIMER_CLK_Disable()                        TIMER_CLK_Stop()
#define TIMER_CLK_SetDividerRegister(clkDivider, reset)  \
    TIMER_CLK_SetFractionalDividerRegister((clkDivider), 0u)
#define TIMER_CLK_SetDivider(clkDivider)           TIMER_CLK_SetDividerRegister((clkDivider), 1u)
#define TIMER_CLK_SetDividerValue(clkDivider)      TIMER_CLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define TIMER_CLK_DIV_ID     TIMER_CLK__DIV_ID

#define TIMER_CLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define TIMER_CLK_CTRL_REG   (*(reg32 *)TIMER_CLK__CTRL_REGISTER)
#define TIMER_CLK_DIV_REG    (*(reg32 *)TIMER_CLK__DIV_REGISTER)

#define TIMER_CLK_CMD_DIV_SHIFT          (0u)
#define TIMER_CLK_CMD_PA_DIV_SHIFT       (8u)
#define TIMER_CLK_CMD_DISABLE_SHIFT      (30u)
#define TIMER_CLK_CMD_ENABLE_SHIFT       (31u)

#define TIMER_CLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << TIMER_CLK_CMD_DISABLE_SHIFT))
#define TIMER_CLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << TIMER_CLK_CMD_ENABLE_SHIFT))

#define TIMER_CLK_DIV_FRAC_MASK  (0x000000F8u)
#define TIMER_CLK_DIV_FRAC_SHIFT (3u)
#define TIMER_CLK_DIV_INT_MASK   (0xFFFFFF00u)
#define TIMER_CLK_DIV_INT_SHIFT  (8u)

#else 

#define TIMER_CLK_DIV_REG        (*(reg32 *)TIMER_CLK__REGISTER)
#define TIMER_CLK_ENABLE_REG     TIMER_CLK_DIV_REG
#define TIMER_CLK_DIV_FRAC_MASK  TIMER_CLK__FRAC_MASK
#define TIMER_CLK_DIV_FRAC_SHIFT (16u)
#define TIMER_CLK_DIV_INT_MASK   TIMER_CLK__DIVIDER_MASK
#define TIMER_CLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_TIMER_CLK_H) */

/* [] END OF FILE */
