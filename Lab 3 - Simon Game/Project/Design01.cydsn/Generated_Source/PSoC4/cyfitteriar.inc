;
; File Name: cyfitteriar.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar_trm.inc

/* BTN */
BTN__0__DR EQU CYREG_GPIO_PRT1_DR
BTN__0__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
BTN__0__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
BTN__0__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
BTN__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
BTN__0__HSIOM_MASK EQU 0x0000000F
BTN__0__HSIOM_SHIFT EQU 0
BTN__0__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__0__INTR EQU CYREG_GPIO_PRT1_INTR
BTN__0__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__0__INTSTAT EQU CYREG_GPIO_PRT1_INTR
BTN__0__MASK EQU 0x01
BTN__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
BTN__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
BTN__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
BTN__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
BTN__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
BTN__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
BTN__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
BTN__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
BTN__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
BTN__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
BTN__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
BTN__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
BTN__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
BTN__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
BTN__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
BTN__0__PC EQU CYREG_GPIO_PRT1_PC
BTN__0__PC2 EQU CYREG_GPIO_PRT1_PC2
BTN__0__PORT EQU 1
BTN__0__PS EQU CYREG_GPIO_PRT1_PS
BTN__0__SHIFT EQU 0
BTN__1__DR EQU CYREG_GPIO_PRT1_DR
BTN__1__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
BTN__1__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
BTN__1__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
BTN__1__HSIOM EQU CYREG_HSIOM_PORT_SEL1
BTN__1__HSIOM_MASK EQU 0x000000F0
BTN__1__HSIOM_SHIFT EQU 4
BTN__1__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__1__INTR EQU CYREG_GPIO_PRT1_INTR
BTN__1__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__1__INTSTAT EQU CYREG_GPIO_PRT1_INTR
BTN__1__MASK EQU 0x02
BTN__1__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
BTN__1__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
BTN__1__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
BTN__1__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
BTN__1__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
BTN__1__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
BTN__1__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
BTN__1__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
BTN__1__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
BTN__1__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
BTN__1__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
BTN__1__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
BTN__1__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
BTN__1__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
BTN__1__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
BTN__1__PC EQU CYREG_GPIO_PRT1_PC
BTN__1__PC2 EQU CYREG_GPIO_PRT1_PC2
BTN__1__PORT EQU 1
BTN__1__PS EQU CYREG_GPIO_PRT1_PS
BTN__1__SHIFT EQU 1
BTN__2__DR EQU CYREG_GPIO_PRT1_DR
BTN__2__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
BTN__2__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
BTN__2__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
BTN__2__HSIOM EQU CYREG_HSIOM_PORT_SEL1
BTN__2__HSIOM_MASK EQU 0x00000F00
BTN__2__HSIOM_SHIFT EQU 8
BTN__2__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__2__INTR EQU CYREG_GPIO_PRT1_INTR
BTN__2__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__2__INTSTAT EQU CYREG_GPIO_PRT1_INTR
BTN__2__MASK EQU 0x04
BTN__2__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
BTN__2__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
BTN__2__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
BTN__2__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
BTN__2__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
BTN__2__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
BTN__2__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
BTN__2__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
BTN__2__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
BTN__2__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
BTN__2__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
BTN__2__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
BTN__2__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
BTN__2__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
BTN__2__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
BTN__2__PC EQU CYREG_GPIO_PRT1_PC
BTN__2__PC2 EQU CYREG_GPIO_PRT1_PC2
BTN__2__PORT EQU 1
BTN__2__PS EQU CYREG_GPIO_PRT1_PS
BTN__2__SHIFT EQU 2
BTN__3__DR EQU CYREG_GPIO_PRT1_DR
BTN__3__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
BTN__3__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
BTN__3__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
BTN__3__HSIOM EQU CYREG_HSIOM_PORT_SEL1
BTN__3__HSIOM_MASK EQU 0x0000F000
BTN__3__HSIOM_SHIFT EQU 12
BTN__3__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__3__INTR EQU CYREG_GPIO_PRT1_INTR
BTN__3__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__3__INTSTAT EQU CYREG_GPIO_PRT1_INTR
BTN__3__MASK EQU 0x08
BTN__3__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
BTN__3__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
BTN__3__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
BTN__3__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
BTN__3__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
BTN__3__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
BTN__3__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
BTN__3__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
BTN__3__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
BTN__3__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
BTN__3__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
BTN__3__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
BTN__3__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
BTN__3__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
BTN__3__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
BTN__3__PC EQU CYREG_GPIO_PRT1_PC
BTN__3__PC2 EQU CYREG_GPIO_PRT1_PC2
BTN__3__PORT EQU 1
BTN__3__PS EQU CYREG_GPIO_PRT1_PS
BTN__3__SHIFT EQU 3
BTN__DR EQU CYREG_GPIO_PRT1_DR
BTN__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
BTN__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
BTN__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
BTN__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__INTR EQU CYREG_GPIO_PRT1_INTR
BTN__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
BTN__INTSTAT EQU CYREG_GPIO_PRT1_INTR
BTN__MASK EQU 0x0F
BTN__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
BTN__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
BTN__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
BTN__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
BTN__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
BTN__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
BTN__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
BTN__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
BTN__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
BTN__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
BTN__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
BTN__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
BTN__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
BTN__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
BTN__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
BTN__PC EQU CYREG_GPIO_PRT1_PC
BTN__PC2 EQU CYREG_GPIO_PRT1_PC2
BTN__PORT EQU 1
BTN__PS EQU CYREG_GPIO_PRT1_PS
BTN__SHIFT EQU 0

/* PRS */
PRS_ClkSp_CtrlReg__0__MASK EQU 0x01
PRS_ClkSp_CtrlReg__0__POS EQU 0
PRS_ClkSp_CtrlReg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
PRS_ClkSp_CtrlReg__16BIT_CONTROL_CONTROL_REG EQU CYREG_UDB_W16_CTL0
PRS_ClkSp_CtrlReg__16BIT_CONTROL_COUNT_REG EQU CYREG_UDB_W16_CTL0
PRS_ClkSp_CtrlReg__16BIT_COUNT_CONTROL_REG EQU CYREG_UDB_W16_CTL0
PRS_ClkSp_CtrlReg__16BIT_COUNT_COUNT_REG EQU CYREG_UDB_W16_CTL0
PRS_ClkSp_CtrlReg__16BIT_MASK_MASK_REG EQU CYREG_UDB_W16_MSK0
PRS_ClkSp_CtrlReg__16BIT_MASK_PERIOD_REG EQU CYREG_UDB_W16_MSK0
PRS_ClkSp_CtrlReg__16BIT_PERIOD_MASK_REG EQU CYREG_UDB_W16_MSK0
PRS_ClkSp_CtrlReg__16BIT_PERIOD_PERIOD_REG EQU CYREG_UDB_W16_MSK0
PRS_ClkSp_CtrlReg__32BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
PRS_ClkSp_CtrlReg__32BIT_CONTROL_REG EQU CYREG_UDB_W32_CTL
PRS_ClkSp_CtrlReg__32BIT_COUNT_REG EQU CYREG_UDB_W32_CTL
PRS_ClkSp_CtrlReg__32BIT_PERIOD_REG EQU CYREG_UDB_W32_MSK
PRS_ClkSp_CtrlReg__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
PRS_ClkSp_CtrlReg__CONTROL_REG EQU CYREG_UDB_W8_CTL0
PRS_ClkSp_CtrlReg__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST0
PRS_ClkSp_CtrlReg__COUNT_REG EQU CYREG_UDB_W8_CTL0
PRS_ClkSp_CtrlReg__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST0
PRS_ClkSp_CtrlReg__MASK EQU 0x01
PRS_ClkSp_CtrlReg__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PRS_ClkSp_CtrlReg__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PRS_ClkSp_CtrlReg__PERIOD_REG EQU CYREG_UDB_W8_MSK0
PRS_sC32_PRSdp_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A00
PRS_sC32_PRSdp_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A10
PRS_sC32_PRSdp_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D00
PRS_sC32_PRSdp_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D10
PRS_sC32_PRSdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
PRS_sC32_PRSdp_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F00
PRS_sC32_PRSdp_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F10
PRS_sC32_PRSdp_u0__32BIT_A0_REG EQU CYREG_UDB_W32_A0
PRS_sC32_PRSdp_u0__32BIT_A1_REG EQU CYREG_UDB_W32_A1
PRS_sC32_PRSdp_u0__32BIT_D0_REG EQU CYREG_UDB_W32_D0
PRS_sC32_PRSdp_u0__32BIT_D1_REG EQU CYREG_UDB_W32_D1
PRS_sC32_PRSdp_u0__32BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
PRS_sC32_PRSdp_u0__32BIT_F0_REG EQU CYREG_UDB_W32_F0
PRS_sC32_PRSdp_u0__32BIT_F1_REG EQU CYREG_UDB_W32_F1
PRS_sC32_PRSdp_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A0
PRS_sC32_PRSdp_u0__A0_REG EQU CYREG_UDB_W8_A00
PRS_sC32_PRSdp_u0__A1_REG EQU CYREG_UDB_W8_A10
PRS_sC32_PRSdp_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D0
PRS_sC32_PRSdp_u0__D0_REG EQU CYREG_UDB_W8_D00
PRS_sC32_PRSdp_u0__D1_REG EQU CYREG_UDB_W8_D10
PRS_sC32_PRSdp_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
PRS_sC32_PRSdp_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F0
PRS_sC32_PRSdp_u0__F0_REG EQU CYREG_UDB_W8_F00
PRS_sC32_PRSdp_u0__F1_REG EQU CYREG_UDB_W8_F10
PRS_sC32_PRSdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PRS_sC32_PRSdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PRS_sC32_PRSdp_u1__16BIT_A0_REG EQU CYREG_UDB_W16_A01
PRS_sC32_PRSdp_u1__16BIT_A1_REG EQU CYREG_UDB_W16_A11
PRS_sC32_PRSdp_u1__16BIT_D0_REG EQU CYREG_UDB_W16_D01
PRS_sC32_PRSdp_u1__16BIT_D1_REG EQU CYREG_UDB_W16_D11
PRS_sC32_PRSdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL1
PRS_sC32_PRSdp_u1__16BIT_F0_REG EQU CYREG_UDB_W16_F01
PRS_sC32_PRSdp_u1__16BIT_F1_REG EQU CYREG_UDB_W16_F11
PRS_sC32_PRSdp_u1__A0_A1_REG EQU CYREG_UDB_CAT16_A1
PRS_sC32_PRSdp_u1__A0_REG EQU CYREG_UDB_W8_A01
PRS_sC32_PRSdp_u1__A1_REG EQU CYREG_UDB_W8_A11
PRS_sC32_PRSdp_u1__D0_D1_REG EQU CYREG_UDB_CAT16_D1
PRS_sC32_PRSdp_u1__D0_REG EQU CYREG_UDB_W8_D01
PRS_sC32_PRSdp_u1__D1_REG EQU CYREG_UDB_W8_D11
PRS_sC32_PRSdp_u1__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL1
PRS_sC32_PRSdp_u1__F0_F1_REG EQU CYREG_UDB_CAT16_F1
PRS_sC32_PRSdp_u1__F0_REG EQU CYREG_UDB_W8_F01
PRS_sC32_PRSdp_u1__F1_REG EQU CYREG_UDB_W8_F11
PRS_sC32_PRSdp_u2__16BIT_A0_REG EQU CYREG_UDB_W16_A02
PRS_sC32_PRSdp_u2__16BIT_A1_REG EQU CYREG_UDB_W16_A12
PRS_sC32_PRSdp_u2__16BIT_D0_REG EQU CYREG_UDB_W16_D02
PRS_sC32_PRSdp_u2__16BIT_D1_REG EQU CYREG_UDB_W16_D12
PRS_sC32_PRSdp_u2__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL2
PRS_sC32_PRSdp_u2__16BIT_F0_REG EQU CYREG_UDB_W16_F02
PRS_sC32_PRSdp_u2__16BIT_F1_REG EQU CYREG_UDB_W16_F12
PRS_sC32_PRSdp_u2__A0_A1_REG EQU CYREG_UDB_CAT16_A2
PRS_sC32_PRSdp_u2__A0_REG EQU CYREG_UDB_W8_A02
PRS_sC32_PRSdp_u2__A1_REG EQU CYREG_UDB_W8_A12
PRS_sC32_PRSdp_u2__D0_D1_REG EQU CYREG_UDB_CAT16_D2
PRS_sC32_PRSdp_u2__D0_REG EQU CYREG_UDB_W8_D02
PRS_sC32_PRSdp_u2__D1_REG EQU CYREG_UDB_W8_D12
PRS_sC32_PRSdp_u2__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL2
PRS_sC32_PRSdp_u2__F0_F1_REG EQU CYREG_UDB_CAT16_F2
PRS_sC32_PRSdp_u2__F0_REG EQU CYREG_UDB_W8_F02
PRS_sC32_PRSdp_u2__F1_REG EQU CYREG_UDB_W8_F12
PRS_sC32_PRSdp_u3__A0_A1_REG EQU CYREG_UDB_CAT16_A3
PRS_sC32_PRSdp_u3__A0_REG EQU CYREG_UDB_W8_A03
PRS_sC32_PRSdp_u3__A1_REG EQU CYREG_UDB_W8_A13
PRS_sC32_PRSdp_u3__D0_D1_REG EQU CYREG_UDB_CAT16_D3
PRS_sC32_PRSdp_u3__D0_REG EQU CYREG_UDB_W8_D03
PRS_sC32_PRSdp_u3__D1_REG EQU CYREG_UDB_W8_D13
PRS_sC32_PRSdp_u3__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL3
PRS_sC32_PRSdp_u3__F0_F1_REG EQU CYREG_UDB_CAT16_F3
PRS_sC32_PRSdp_u3__F0_REG EQU CYREG_UDB_W8_F03
PRS_sC32_PRSdp_u3__F1_REG EQU CYREG_UDB_W8_F13
PRS_sC32_PRSdp_u3__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK3
PRS_sC32_PRSdp_u3__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK3

/* B_LED */
B_LED__0__DR EQU CYREG_GPIO_PRT0_DR
B_LED__0__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
B_LED__0__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
B_LED__0__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
B_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
B_LED__0__HSIOM_MASK EQU 0x00000F00
B_LED__0__HSIOM_SHIFT EQU 8
B_LED__0__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
B_LED__0__INTR EQU CYREG_GPIO_PRT0_INTR
B_LED__0__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
B_LED__0__INTSTAT EQU CYREG_GPIO_PRT0_INTR
B_LED__0__MASK EQU 0x04
B_LED__0__OUT_SEL EQU CYREG_UDB_PA0_CFG10
B_LED__0__OUT_SEL_SHIFT EQU 4
B_LED__0__OUT_SEL_VAL EQU 3
B_LED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
B_LED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
B_LED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
B_LED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
B_LED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
B_LED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
B_LED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
B_LED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
B_LED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
B_LED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
B_LED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
B_LED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
B_LED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
B_LED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
B_LED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
B_LED__0__PC EQU CYREG_GPIO_PRT0_PC
B_LED__0__PC2 EQU CYREG_GPIO_PRT0_PC2
B_LED__0__PORT EQU 0
B_LED__0__PS EQU CYREG_GPIO_PRT0_PS
B_LED__0__SHIFT EQU 2
B_LED__DR EQU CYREG_GPIO_PRT0_DR
B_LED__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
B_LED__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
B_LED__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
B_LED__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
B_LED__INTR EQU CYREG_GPIO_PRT0_INTR
B_LED__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
B_LED__INTSTAT EQU CYREG_GPIO_PRT0_INTR
B_LED__MASK EQU 0x04
B_LED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
B_LED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
B_LED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
B_LED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
B_LED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
B_LED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
B_LED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
B_LED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
B_LED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
B_LED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
B_LED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
B_LED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
B_LED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
B_LED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
B_LED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
B_LED__PC EQU CYREG_GPIO_PRT0_PC
B_LED__PC2 EQU CYREG_GPIO_PRT0_PC2
B_LED__PORT EQU 0
B_LED__PS EQU CYREG_GPIO_PRT0_PS
B_LED__SHIFT EQU 2

/* G_LED */
G_LED__0__DR EQU CYREG_GPIO_PRT3_DR
G_LED__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
G_LED__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
G_LED__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
G_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
G_LED__0__HSIOM_MASK EQU 0x000000F0
G_LED__0__HSIOM_SHIFT EQU 4
G_LED__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
G_LED__0__INTR EQU CYREG_GPIO_PRT3_INTR
G_LED__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
G_LED__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
G_LED__0__MASK EQU 0x02
G_LED__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
G_LED__0__OUT_SEL_SHIFT EQU 2
G_LED__0__OUT_SEL_VAL EQU 1
G_LED__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
G_LED__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
G_LED__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
G_LED__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
G_LED__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
G_LED__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
G_LED__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
G_LED__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
G_LED__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
G_LED__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
G_LED__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
G_LED__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
G_LED__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
G_LED__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
G_LED__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
G_LED__0__PC EQU CYREG_GPIO_PRT3_PC
G_LED__0__PC2 EQU CYREG_GPIO_PRT3_PC2
G_LED__0__PORT EQU 3
G_LED__0__PS EQU CYREG_GPIO_PRT3_PS
G_LED__0__SHIFT EQU 1
G_LED__DR EQU CYREG_GPIO_PRT3_DR
G_LED__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
G_LED__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
G_LED__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
G_LED__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
G_LED__INTR EQU CYREG_GPIO_PRT3_INTR
G_LED__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
G_LED__INTSTAT EQU CYREG_GPIO_PRT3_INTR
G_LED__MASK EQU 0x02
G_LED__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
G_LED__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
G_LED__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
G_LED__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
G_LED__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
G_LED__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
G_LED__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
G_LED__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
G_LED__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
G_LED__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
G_LED__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
G_LED__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
G_LED__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
G_LED__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
G_LED__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
G_LED__PC EQU CYREG_GPIO_PRT3_PC
G_LED__PC2 EQU CYREG_GPIO_PRT3_PC2
G_LED__PORT EQU 3
G_LED__PS EQU CYREG_GPIO_PRT3_PS
G_LED__SHIFT EQU 1

/* R_LED */
R_LED__0__DR EQU CYREG_GPIO_PRT3_DR
R_LED__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
R_LED__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
R_LED__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
R_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
R_LED__0__HSIOM_MASK EQU 0x0000000F
R_LED__0__HSIOM_SHIFT EQU 0
R_LED__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
R_LED__0__INTR EQU CYREG_GPIO_PRT3_INTR
R_LED__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
R_LED__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
R_LED__0__MASK EQU 0x01
R_LED__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
R_LED__0__OUT_SEL_SHIFT EQU 0
R_LED__0__OUT_SEL_VAL EQU 2
R_LED__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
R_LED__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
R_LED__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
R_LED__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
R_LED__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
R_LED__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
R_LED__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
R_LED__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
R_LED__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
R_LED__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
R_LED__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
R_LED__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
R_LED__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
R_LED__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
R_LED__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
R_LED__0__PC EQU CYREG_GPIO_PRT3_PC
R_LED__0__PC2 EQU CYREG_GPIO_PRT3_PC2
R_LED__0__PORT EQU 3
R_LED__0__PS EQU CYREG_GPIO_PRT3_PS
R_LED__0__SHIFT EQU 0
R_LED__DR EQU CYREG_GPIO_PRT3_DR
R_LED__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
R_LED__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
R_LED__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
R_LED__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
R_LED__INTR EQU CYREG_GPIO_PRT3_INTR
R_LED__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
R_LED__INTSTAT EQU CYREG_GPIO_PRT3_INTR
R_LED__MASK EQU 0x01
R_LED__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
R_LED__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
R_LED__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
R_LED__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
R_LED__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
R_LED__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
R_LED__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
R_LED__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
R_LED__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
R_LED__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
R_LED__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
R_LED__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
R_LED__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
R_LED__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
R_LED__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
R_LED__PC EQU CYREG_GPIO_PRT3_PC
R_LED__PC2 EQU CYREG_GPIO_PRT3_PC2
R_LED__PORT EQU 3
R_LED__PS EQU CYREG_GPIO_PRT3_PS
R_LED__SHIFT EQU 0

/* Y_LED */
Y_LED__0__DR EQU CYREG_GPIO_PRT0_DR
Y_LED__0__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
Y_LED__0__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
Y_LED__0__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
Y_LED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
Y_LED__0__HSIOM_MASK EQU 0x0000F000
Y_LED__0__HSIOM_SHIFT EQU 12
Y_LED__0__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
Y_LED__0__INTR EQU CYREG_GPIO_PRT0_INTR
Y_LED__0__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
Y_LED__0__INTSTAT EQU CYREG_GPIO_PRT0_INTR
Y_LED__0__MASK EQU 0x08
Y_LED__0__OUT_SEL EQU CYREG_UDB_PA0_CFG10
Y_LED__0__OUT_SEL_SHIFT EQU 6
Y_LED__0__OUT_SEL_VAL EQU 2
Y_LED__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Y_LED__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Y_LED__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Y_LED__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Y_LED__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Y_LED__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Y_LED__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Y_LED__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Y_LED__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Y_LED__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Y_LED__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Y_LED__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Y_LED__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Y_LED__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Y_LED__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Y_LED__0__PC EQU CYREG_GPIO_PRT0_PC
Y_LED__0__PC2 EQU CYREG_GPIO_PRT0_PC2
Y_LED__0__PORT EQU 0
Y_LED__0__PS EQU CYREG_GPIO_PRT0_PS
Y_LED__0__SHIFT EQU 3
Y_LED__DR EQU CYREG_GPIO_PRT0_DR
Y_LED__DR_CLR EQU CYREG_GPIO_PRT0_DR_CLR
Y_LED__DR_INV EQU CYREG_GPIO_PRT0_DR_INV
Y_LED__DR_SET EQU CYREG_GPIO_PRT0_DR_SET
Y_LED__INTCFG EQU CYREG_GPIO_PRT0_INTR_CFG
Y_LED__INTR EQU CYREG_GPIO_PRT0_INTR
Y_LED__INTR_CFG EQU CYREG_GPIO_PRT0_INTR_CFG
Y_LED__INTSTAT EQU CYREG_GPIO_PRT0_INTR
Y_LED__MASK EQU 0x08
Y_LED__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
Y_LED__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
Y_LED__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
Y_LED__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
Y_LED__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
Y_LED__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
Y_LED__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
Y_LED__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
Y_LED__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
Y_LED__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
Y_LED__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
Y_LED__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
Y_LED__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
Y_LED__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
Y_LED__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
Y_LED__PC EQU CYREG_GPIO_PRT0_PC
Y_LED__PC2 EQU CYREG_GPIO_PRT0_PC2
Y_LED__PORT EQU 0
Y_LED__PS EQU CYREG_GPIO_PRT0_PS
Y_LED__SHIFT EQU 3

/* LED_PWM */
LED_PWM_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
LED_PWM_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
LED_PWM_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
LED_PWM_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
LED_PWM_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
LED_PWM_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
LED_PWM_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
LED_PWM_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
LED_PWM_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
LED_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
LED_PWM_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
LED_PWM_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

/* LED_SEL */
LED_SEL_Sync_ctrl_reg__0__MASK EQU 0x01
LED_SEL_Sync_ctrl_reg__0__POS EQU 0
LED_SEL_Sync_ctrl_reg__1__MASK EQU 0x02
LED_SEL_Sync_ctrl_reg__1__POS EQU 1
LED_SEL_Sync_ctrl_reg__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL3
LED_SEL_Sync_ctrl_reg__CONTROL_REG EQU CYREG_UDB_W8_CTL3
LED_SEL_Sync_ctrl_reg__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST3
LED_SEL_Sync_ctrl_reg__COUNT_REG EQU CYREG_UDB_W8_CTL3
LED_SEL_Sync_ctrl_reg__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST3
LED_SEL_Sync_ctrl_reg__MASK EQU 0x03
LED_SEL_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK3
LED_SEL_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK3
LED_SEL_Sync_ctrl_reg__PERIOD_REG EQU CYREG_UDB_W8_MSK3

/* PWM_CLK */
PWM_CLK__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL19
PWM_CLK__DIV_ID EQU 0x00000040
PWM_CLK__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL0
PWM_CLK__PA_DIV_ID EQU 0x000000FF

/* SPEAKER */
SPEAKER__0__DR EQU CYREG_GPIO_PRT3_DR
SPEAKER__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
SPEAKER__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
SPEAKER__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
SPEAKER__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
SPEAKER__0__HSIOM_MASK EQU 0x000F0000
SPEAKER__0__HSIOM_SHIFT EQU 16
SPEAKER__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
SPEAKER__0__INTR EQU CYREG_GPIO_PRT3_INTR
SPEAKER__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
SPEAKER__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
SPEAKER__0__MASK EQU 0x10
SPEAKER__0__OUT_SEL EQU CYREG_UDB_PA3_CFG10
SPEAKER__0__OUT_SEL_SHIFT EQU 8
SPEAKER__0__OUT_SEL_VAL EQU -1
SPEAKER__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
SPEAKER__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
SPEAKER__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
SPEAKER__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
SPEAKER__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
SPEAKER__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
SPEAKER__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
SPEAKER__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
SPEAKER__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
SPEAKER__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
SPEAKER__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
SPEAKER__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
SPEAKER__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
SPEAKER__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
SPEAKER__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
SPEAKER__0__PC EQU CYREG_GPIO_PRT3_PC
SPEAKER__0__PC2 EQU CYREG_GPIO_PRT3_PC2
SPEAKER__0__PORT EQU 3
SPEAKER__0__PS EQU CYREG_GPIO_PRT3_PS
SPEAKER__0__SHIFT EQU 4
SPEAKER__DR EQU CYREG_GPIO_PRT3_DR
SPEAKER__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
SPEAKER__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
SPEAKER__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
SPEAKER__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
SPEAKER__INTR EQU CYREG_GPIO_PRT3_INTR
SPEAKER__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
SPEAKER__INTSTAT EQU CYREG_GPIO_PRT3_INTR
SPEAKER__MASK EQU 0x10
SPEAKER__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
SPEAKER__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
SPEAKER__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
SPEAKER__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
SPEAKER__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
SPEAKER__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
SPEAKER__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
SPEAKER__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
SPEAKER__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
SPEAKER__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
SPEAKER__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
SPEAKER__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
SPEAKER__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
SPEAKER__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
SPEAKER__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
SPEAKER__PC EQU CYREG_GPIO_PRT3_PC
SPEAKER__PC2 EQU CYREG_GPIO_PRT3_PC2
SPEAKER__PORT EQU 3
SPEAKER__PS EQU CYREG_GPIO_PRT3_PS
SPEAKER__SHIFT EQU 4
SPEAKER_PWM_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT2_CC
SPEAKER_PWM_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT2_CC_BUFF
SPEAKER_PWM_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT2_COUNTER
SPEAKER_PWM_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT2_CTRL
SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT2_INTR
SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT2_INTR_MASK
SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT2_INTR_MASKED
SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT2_INTR_SET
SPEAKER_PWM_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT2_PERIOD
SPEAKER_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT2_PERIOD_BUFF
SPEAKER_PWM_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT2_STATUS
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x04
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 2
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x400
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 10
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x4000000
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 26
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x40000
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 18
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x04
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 2
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x04
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 2
SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 2
SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT2_TR_CTRL0
SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT2_TR_CTRL1
SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT2_TR_CTRL2

/* TIMER_CLK */
TIMER_CLK__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL12
TIMER_CLK__DIV_ID EQU 0x00000041
TIMER_CLK__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL1
TIMER_CLK__PA_DIV_ID EQU 0x000000FF

/* INPUT_TIMER */
INPUT_TIMER_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT1_CC
INPUT_TIMER_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT1_CC_BUFF
INPUT_TIMER_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT1_COUNTER
INPUT_TIMER_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT1_CTRL
INPUT_TIMER_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT1_INTR
INPUT_TIMER_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT1_INTR_MASK
INPUT_TIMER_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT1_INTR_MASKED
INPUT_TIMER_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT1_INTR_SET
INPUT_TIMER_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT1_PERIOD
INPUT_TIMER_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT1_PERIOD_BUFF
INPUT_TIMER_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT1_STATUS
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x02
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 1
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x200
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 9
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x2000000
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 25
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x20000
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 17
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x02
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 1
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x02
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 1
INPUT_TIMER_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 1
INPUT_TIMER_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT1_TR_CTRL0
INPUT_TIMER_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT1_TR_CTRL1
INPUT_TIMER_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT1_TR_CTRL2
INPUT_TIMER_ISR__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
INPUT_TIMER_ISR__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
INPUT_TIMER_ISR__INTC_MASK EQU 0x100000
INPUT_TIMER_ISR__INTC_NUMBER EQU 20
INPUT_TIMER_ISR__INTC_PRIOR_MASK EQU 0xC0
INPUT_TIMER_ISR__INTC_PRIOR_NUM EQU 3
INPUT_TIMER_ISR__INTC_PRIOR_REG EQU CYREG_CM0_IPR5
INPUT_TIMER_ISR__INTC_SET_EN_REG EQU CYREG_CM0_ISER
INPUT_TIMER_ISR__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

/* Miscellaneous */
CYDEV_BCLK__HFCLK__HZ EQU 48000000
CYDEV_BCLK__HFCLK__KHZ EQU 48000
CYDEV_BCLK__HFCLK__MHZ EQU 48
CYDEV_BCLK__SYSCLK__HZ EQU 48000000
CYDEV_BCLK__SYSCLK__KHZ EQU 48000
CYDEV_BCLK__SYSCLK__MHZ EQU 48
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x112D11A1
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4M
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4M_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 10
CYDEV_DFT_SELECT_CLK1 EQU 11
CYDEV_DMA_CHANNELS_AVAILABLE EQU 8
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_INTR_NUMBER_DMA EQU 13
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_VDDIO_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_m0s8can_VERSION EQU 1
CYIPBLOCK_m0s8cpussv2_VERSION EQU 1
CYIPBLOCK_m0s8csd_VERSION EQU 1
CYIPBLOCK_m0s8ioss_VERSION EQU 1
CYIPBLOCK_m0s8lcd_VERSION EQU 2
CYIPBLOCK_m0s8lpcomp_VERSION EQU 2
CYIPBLOCK_m0s8peri_VERSION EQU 1
CYIPBLOCK_m0s8scb_VERSION EQU 2
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 2
CYIPBLOCK_m0s8udbif_VERSION EQU 1
CYIPBLOCK_m0s8wco_VERSION EQU 1
CYIPBLOCK_s8pass4al_VERSION EQU 1
DMA_CHANNELS_USED__MASK EQU 0
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */
