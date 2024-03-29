/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* C0 */
#define C0__0__DR CYREG_GPIO_PRT1_DR
#define C0__0__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define C0__0__DR_INV CYREG_GPIO_PRT1_DR_INV
#define C0__0__DR_SET CYREG_GPIO_PRT1_DR_SET
#define C0__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define C0__0__HSIOM_MASK 0x00000F00u
#define C0__0__HSIOM_SHIFT 8u
#define C0__0__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define C0__0__INTR CYREG_GPIO_PRT1_INTR
#define C0__0__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define C0__0__INTSTAT CYREG_GPIO_PRT1_INTR
#define C0__0__MASK 0x04u
#define C0__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define C0__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define C0__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define C0__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define C0__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define C0__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define C0__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define C0__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define C0__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define C0__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define C0__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define C0__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define C0__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define C0__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define C0__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define C0__0__PC CYREG_GPIO_PRT1_PC
#define C0__0__PC2 CYREG_GPIO_PRT1_PC2
#define C0__0__PORT 1u
#define C0__0__PS CYREG_GPIO_PRT1_PS
#define C0__0__SHIFT 2u
#define C0__DR CYREG_GPIO_PRT1_DR
#define C0__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define C0__DR_INV CYREG_GPIO_PRT1_DR_INV
#define C0__DR_SET CYREG_GPIO_PRT1_DR_SET
#define C0__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define C0__INTR CYREG_GPIO_PRT1_INTR
#define C0__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define C0__INTSTAT CYREG_GPIO_PRT1_INTR
#define C0__MASK 0x04u
#define C0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define C0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define C0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define C0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define C0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define C0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define C0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define C0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define C0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define C0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define C0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define C0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define C0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define C0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define C0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define C0__PC CYREG_GPIO_PRT1_PC
#define C0__PC2 CYREG_GPIO_PRT1_PC2
#define C0__PORT 1u
#define C0__PS CYREG_GPIO_PRT1_PS
#define C0__SHIFT 2u

/* C1 */
#define C1__0__DR CYREG_GPIO_PRT1_DR
#define C1__0__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define C1__0__DR_INV CYREG_GPIO_PRT1_DR_INV
#define C1__0__DR_SET CYREG_GPIO_PRT1_DR_SET
#define C1__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define C1__0__HSIOM_MASK 0x0000F000u
#define C1__0__HSIOM_SHIFT 12u
#define C1__0__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define C1__0__INTR CYREG_GPIO_PRT1_INTR
#define C1__0__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define C1__0__INTSTAT CYREG_GPIO_PRT1_INTR
#define C1__0__MASK 0x08u
#define C1__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define C1__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define C1__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define C1__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define C1__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define C1__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define C1__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define C1__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define C1__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define C1__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define C1__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define C1__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define C1__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define C1__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define C1__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define C1__0__PC CYREG_GPIO_PRT1_PC
#define C1__0__PC2 CYREG_GPIO_PRT1_PC2
#define C1__0__PORT 1u
#define C1__0__PS CYREG_GPIO_PRT1_PS
#define C1__0__SHIFT 3u
#define C1__DR CYREG_GPIO_PRT1_DR
#define C1__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define C1__DR_INV CYREG_GPIO_PRT1_DR_INV
#define C1__DR_SET CYREG_GPIO_PRT1_DR_SET
#define C1__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define C1__INTR CYREG_GPIO_PRT1_INTR
#define C1__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define C1__INTSTAT CYREG_GPIO_PRT1_INTR
#define C1__MASK 0x08u
#define C1__PA__CFG0 CYREG_UDB_PA1_CFG0
#define C1__PA__CFG1 CYREG_UDB_PA1_CFG1
#define C1__PA__CFG10 CYREG_UDB_PA1_CFG10
#define C1__PA__CFG11 CYREG_UDB_PA1_CFG11
#define C1__PA__CFG12 CYREG_UDB_PA1_CFG12
#define C1__PA__CFG13 CYREG_UDB_PA1_CFG13
#define C1__PA__CFG14 CYREG_UDB_PA1_CFG14
#define C1__PA__CFG2 CYREG_UDB_PA1_CFG2
#define C1__PA__CFG3 CYREG_UDB_PA1_CFG3
#define C1__PA__CFG4 CYREG_UDB_PA1_CFG4
#define C1__PA__CFG5 CYREG_UDB_PA1_CFG5
#define C1__PA__CFG6 CYREG_UDB_PA1_CFG6
#define C1__PA__CFG7 CYREG_UDB_PA1_CFG7
#define C1__PA__CFG8 CYREG_UDB_PA1_CFG8
#define C1__PA__CFG9 CYREG_UDB_PA1_CFG9
#define C1__PC CYREG_GPIO_PRT1_PC
#define C1__PC2 CYREG_GPIO_PRT1_PC2
#define C1__PORT 1u
#define C1__PS CYREG_GPIO_PRT1_PS
#define C1__SHIFT 3u

/* C2 */
#define C2__0__DR CYREG_GPIO_PRT5_DR
#define C2__0__DR_CLR CYREG_GPIO_PRT5_DR_CLR
#define C2__0__DR_INV CYREG_GPIO_PRT5_DR_INV
#define C2__0__DR_SET CYREG_GPIO_PRT5_DR_SET
#define C2__0__HSIOM CYREG_HSIOM_PORT_SEL5
#define C2__0__HSIOM_MASK 0x0000F000u
#define C2__0__HSIOM_SHIFT 12u
#define C2__0__INTCFG CYREG_GPIO_PRT5_INTR_CFG
#define C2__0__INTR CYREG_GPIO_PRT5_INTR
#define C2__0__INTR_CFG CYREG_GPIO_PRT5_INTR_CFG
#define C2__0__INTSTAT CYREG_GPIO_PRT5_INTR
#define C2__0__MASK 0x08u
#define C2__0__PC CYREG_GPIO_PRT5_PC
#define C2__0__PC2 CYREG_GPIO_PRT5_PC2
#define C2__0__PORT 5u
#define C2__0__PS CYREG_GPIO_PRT5_PS
#define C2__0__SHIFT 3u
#define C2__DR CYREG_GPIO_PRT5_DR
#define C2__DR_CLR CYREG_GPIO_PRT5_DR_CLR
#define C2__DR_INV CYREG_GPIO_PRT5_DR_INV
#define C2__DR_SET CYREG_GPIO_PRT5_DR_SET
#define C2__INTCFG CYREG_GPIO_PRT5_INTR_CFG
#define C2__INTR CYREG_GPIO_PRT5_INTR
#define C2__INTR_CFG CYREG_GPIO_PRT5_INTR_CFG
#define C2__INTSTAT CYREG_GPIO_PRT5_INTR
#define C2__MASK 0x08u
#define C2__PC CYREG_GPIO_PRT5_PC
#define C2__PC2 CYREG_GPIO_PRT5_PC2
#define C2__PORT 5u
#define C2__PS CYREG_GPIO_PRT5_PS
#define C2__SHIFT 3u

/* C3 */
#define C3__0__DR CYREG_GPIO_PRT5_DR
#define C3__0__DR_CLR CYREG_GPIO_PRT5_DR_CLR
#define C3__0__DR_INV CYREG_GPIO_PRT5_DR_INV
#define C3__0__DR_SET CYREG_GPIO_PRT5_DR_SET
#define C3__0__HSIOM CYREG_HSIOM_PORT_SEL5
#define C3__0__HSIOM_MASK 0x00F00000u
#define C3__0__HSIOM_SHIFT 20u
#define C3__0__INTCFG CYREG_GPIO_PRT5_INTR_CFG
#define C3__0__INTR CYREG_GPIO_PRT5_INTR
#define C3__0__INTR_CFG CYREG_GPIO_PRT5_INTR_CFG
#define C3__0__INTSTAT CYREG_GPIO_PRT5_INTR
#define C3__0__MASK 0x20u
#define C3__0__PC CYREG_GPIO_PRT5_PC
#define C3__0__PC2 CYREG_GPIO_PRT5_PC2
#define C3__0__PORT 5u
#define C3__0__PS CYREG_GPIO_PRT5_PS
#define C3__0__SHIFT 5u
#define C3__DR CYREG_GPIO_PRT5_DR
#define C3__DR_CLR CYREG_GPIO_PRT5_DR_CLR
#define C3__DR_INV CYREG_GPIO_PRT5_DR_INV
#define C3__DR_SET CYREG_GPIO_PRT5_DR_SET
#define C3__INTCFG CYREG_GPIO_PRT5_INTR_CFG
#define C3__INTR CYREG_GPIO_PRT5_INTR
#define C3__INTR_CFG CYREG_GPIO_PRT5_INTR_CFG
#define C3__INTSTAT CYREG_GPIO_PRT5_INTR
#define C3__MASK 0x20u
#define C3__PC CYREG_GPIO_PRT5_PC
#define C3__PC2 CYREG_GPIO_PRT5_PC2
#define C3__PORT 5u
#define C3__PS CYREG_GPIO_PRT5_PS
#define C3__SHIFT 5u

/* R0 */
#define R0__0__DR CYREG_GPIO_PRT3_DR
#define R0__0__DR_CLR CYREG_GPIO_PRT3_DR_CLR
#define R0__0__DR_INV CYREG_GPIO_PRT3_DR_INV
#define R0__0__DR_SET CYREG_GPIO_PRT3_DR_SET
#define R0__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define R0__0__HSIOM_MASK 0x0000000Fu
#define R0__0__HSIOM_SHIFT 0u
#define R0__0__INTCFG CYREG_GPIO_PRT3_INTR_CFG
#define R0__0__INTR CYREG_GPIO_PRT3_INTR
#define R0__0__INTR_CFG CYREG_GPIO_PRT3_INTR_CFG
#define R0__0__INTSTAT CYREG_GPIO_PRT3_INTR
#define R0__0__MASK 0x01u
#define R0__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define R0__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define R0__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define R0__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define R0__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define R0__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define R0__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define R0__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define R0__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define R0__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define R0__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define R0__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define R0__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define R0__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define R0__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define R0__0__PC CYREG_GPIO_PRT3_PC
#define R0__0__PC2 CYREG_GPIO_PRT3_PC2
#define R0__0__PORT 3u
#define R0__0__PS CYREG_GPIO_PRT3_PS
#define R0__0__SHIFT 0u
#define R0__DR CYREG_GPIO_PRT3_DR
#define R0__DR_CLR CYREG_GPIO_PRT3_DR_CLR
#define R0__DR_INV CYREG_GPIO_PRT3_DR_INV
#define R0__DR_SET CYREG_GPIO_PRT3_DR_SET
#define R0__INTCFG CYREG_GPIO_PRT3_INTR_CFG
#define R0__INTR CYREG_GPIO_PRT3_INTR
#define R0__INTR_CFG CYREG_GPIO_PRT3_INTR_CFG
#define R0__INTSTAT CYREG_GPIO_PRT3_INTR
#define R0__MASK 0x01u
#define R0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define R0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define R0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define R0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define R0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define R0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define R0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define R0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define R0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define R0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define R0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define R0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define R0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define R0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define R0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define R0__PC CYREG_GPIO_PRT3_PC
#define R0__PC2 CYREG_GPIO_PRT3_PC2
#define R0__PORT 3u
#define R0__PS CYREG_GPIO_PRT3_PS
#define R0__SHIFT 0u

/* R1 */
#define R1__0__DR CYREG_GPIO_PRT3_DR
#define R1__0__DR_CLR CYREG_GPIO_PRT3_DR_CLR
#define R1__0__DR_INV CYREG_GPIO_PRT3_DR_INV
#define R1__0__DR_SET CYREG_GPIO_PRT3_DR_SET
#define R1__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define R1__0__HSIOM_MASK 0x000000F0u
#define R1__0__HSIOM_SHIFT 4u
#define R1__0__INTCFG CYREG_GPIO_PRT3_INTR_CFG
#define R1__0__INTR CYREG_GPIO_PRT3_INTR
#define R1__0__INTR_CFG CYREG_GPIO_PRT3_INTR_CFG
#define R1__0__INTSTAT CYREG_GPIO_PRT3_INTR
#define R1__0__MASK 0x02u
#define R1__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define R1__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define R1__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define R1__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define R1__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define R1__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define R1__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define R1__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define R1__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define R1__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define R1__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define R1__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define R1__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define R1__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define R1__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define R1__0__PC CYREG_GPIO_PRT3_PC
#define R1__0__PC2 CYREG_GPIO_PRT3_PC2
#define R1__0__PORT 3u
#define R1__0__PS CYREG_GPIO_PRT3_PS
#define R1__0__SHIFT 1u
#define R1__DR CYREG_GPIO_PRT3_DR
#define R1__DR_CLR CYREG_GPIO_PRT3_DR_CLR
#define R1__DR_INV CYREG_GPIO_PRT3_DR_INV
#define R1__DR_SET CYREG_GPIO_PRT3_DR_SET
#define R1__INTCFG CYREG_GPIO_PRT3_INTR_CFG
#define R1__INTR CYREG_GPIO_PRT3_INTR
#define R1__INTR_CFG CYREG_GPIO_PRT3_INTR_CFG
#define R1__INTSTAT CYREG_GPIO_PRT3_INTR
#define R1__MASK 0x02u
#define R1__PA__CFG0 CYREG_UDB_PA3_CFG0
#define R1__PA__CFG1 CYREG_UDB_PA3_CFG1
#define R1__PA__CFG10 CYREG_UDB_PA3_CFG10
#define R1__PA__CFG11 CYREG_UDB_PA3_CFG11
#define R1__PA__CFG12 CYREG_UDB_PA3_CFG12
#define R1__PA__CFG13 CYREG_UDB_PA3_CFG13
#define R1__PA__CFG14 CYREG_UDB_PA3_CFG14
#define R1__PA__CFG2 CYREG_UDB_PA3_CFG2
#define R1__PA__CFG3 CYREG_UDB_PA3_CFG3
#define R1__PA__CFG4 CYREG_UDB_PA3_CFG4
#define R1__PA__CFG5 CYREG_UDB_PA3_CFG5
#define R1__PA__CFG6 CYREG_UDB_PA3_CFG6
#define R1__PA__CFG7 CYREG_UDB_PA3_CFG7
#define R1__PA__CFG8 CYREG_UDB_PA3_CFG8
#define R1__PA__CFG9 CYREG_UDB_PA3_CFG9
#define R1__PC CYREG_GPIO_PRT3_PC
#define R1__PC2 CYREG_GPIO_PRT3_PC2
#define R1__PORT 3u
#define R1__PS CYREG_GPIO_PRT3_PS
#define R1__SHIFT 1u

/* R2 */
#define R2__0__DR CYREG_GPIO_PRT1_DR
#define R2__0__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define R2__0__DR_INV CYREG_GPIO_PRT1_DR_INV
#define R2__0__DR_SET CYREG_GPIO_PRT1_DR_SET
#define R2__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define R2__0__HSIOM_MASK 0x0000000Fu
#define R2__0__HSIOM_SHIFT 0u
#define R2__0__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define R2__0__INTR CYREG_GPIO_PRT1_INTR
#define R2__0__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define R2__0__INTSTAT CYREG_GPIO_PRT1_INTR
#define R2__0__MASK 0x01u
#define R2__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define R2__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define R2__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define R2__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define R2__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define R2__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define R2__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define R2__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define R2__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define R2__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define R2__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define R2__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define R2__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define R2__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define R2__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define R2__0__PC CYREG_GPIO_PRT1_PC
#define R2__0__PC2 CYREG_GPIO_PRT1_PC2
#define R2__0__PORT 1u
#define R2__0__PS CYREG_GPIO_PRT1_PS
#define R2__0__SHIFT 0u
#define R2__DR CYREG_GPIO_PRT1_DR
#define R2__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define R2__DR_INV CYREG_GPIO_PRT1_DR_INV
#define R2__DR_SET CYREG_GPIO_PRT1_DR_SET
#define R2__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define R2__INTR CYREG_GPIO_PRT1_INTR
#define R2__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define R2__INTSTAT CYREG_GPIO_PRT1_INTR
#define R2__MASK 0x01u
#define R2__PA__CFG0 CYREG_UDB_PA1_CFG0
#define R2__PA__CFG1 CYREG_UDB_PA1_CFG1
#define R2__PA__CFG10 CYREG_UDB_PA1_CFG10
#define R2__PA__CFG11 CYREG_UDB_PA1_CFG11
#define R2__PA__CFG12 CYREG_UDB_PA1_CFG12
#define R2__PA__CFG13 CYREG_UDB_PA1_CFG13
#define R2__PA__CFG14 CYREG_UDB_PA1_CFG14
#define R2__PA__CFG2 CYREG_UDB_PA1_CFG2
#define R2__PA__CFG3 CYREG_UDB_PA1_CFG3
#define R2__PA__CFG4 CYREG_UDB_PA1_CFG4
#define R2__PA__CFG5 CYREG_UDB_PA1_CFG5
#define R2__PA__CFG6 CYREG_UDB_PA1_CFG6
#define R2__PA__CFG7 CYREG_UDB_PA1_CFG7
#define R2__PA__CFG8 CYREG_UDB_PA1_CFG8
#define R2__PA__CFG9 CYREG_UDB_PA1_CFG9
#define R2__PC CYREG_GPIO_PRT1_PC
#define R2__PC2 CYREG_GPIO_PRT1_PC2
#define R2__PORT 1u
#define R2__PS CYREG_GPIO_PRT1_PS
#define R2__SHIFT 0u

/* R3 */
#define R3__0__DR CYREG_GPIO_PRT1_DR
#define R3__0__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define R3__0__DR_INV CYREG_GPIO_PRT1_DR_INV
#define R3__0__DR_SET CYREG_GPIO_PRT1_DR_SET
#define R3__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define R3__0__HSIOM_MASK 0x000000F0u
#define R3__0__HSIOM_SHIFT 4u
#define R3__0__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define R3__0__INTR CYREG_GPIO_PRT1_INTR
#define R3__0__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define R3__0__INTSTAT CYREG_GPIO_PRT1_INTR
#define R3__0__MASK 0x02u
#define R3__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define R3__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define R3__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define R3__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define R3__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define R3__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define R3__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define R3__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define R3__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define R3__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define R3__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define R3__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define R3__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define R3__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define R3__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define R3__0__PC CYREG_GPIO_PRT1_PC
#define R3__0__PC2 CYREG_GPIO_PRT1_PC2
#define R3__0__PORT 1u
#define R3__0__PS CYREG_GPIO_PRT1_PS
#define R3__0__SHIFT 1u
#define R3__DR CYREG_GPIO_PRT1_DR
#define R3__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define R3__DR_INV CYREG_GPIO_PRT1_DR_INV
#define R3__DR_SET CYREG_GPIO_PRT1_DR_SET
#define R3__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define R3__INTR CYREG_GPIO_PRT1_INTR
#define R3__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define R3__INTSTAT CYREG_GPIO_PRT1_INTR
#define R3__MASK 0x02u
#define R3__PA__CFG0 CYREG_UDB_PA1_CFG0
#define R3__PA__CFG1 CYREG_UDB_PA1_CFG1
#define R3__PA__CFG10 CYREG_UDB_PA1_CFG10
#define R3__PA__CFG11 CYREG_UDB_PA1_CFG11
#define R3__PA__CFG12 CYREG_UDB_PA1_CFG12
#define R3__PA__CFG13 CYREG_UDB_PA1_CFG13
#define R3__PA__CFG14 CYREG_UDB_PA1_CFG14
#define R3__PA__CFG2 CYREG_UDB_PA1_CFG2
#define R3__PA__CFG3 CYREG_UDB_PA1_CFG3
#define R3__PA__CFG4 CYREG_UDB_PA1_CFG4
#define R3__PA__CFG5 CYREG_UDB_PA1_CFG5
#define R3__PA__CFG6 CYREG_UDB_PA1_CFG6
#define R3__PA__CFG7 CYREG_UDB_PA1_CFG7
#define R3__PA__CFG8 CYREG_UDB_PA1_CFG8
#define R3__PA__CFG9 CYREG_UDB_PA1_CFG9
#define R3__PC CYREG_GPIO_PRT1_PC
#define R3__PC2 CYREG_GPIO_PRT1_PC2
#define R3__PORT 1u
#define R3__PS CYREG_GPIO_PRT1_PS
#define R3__SHIFT 1u

/* LCD_LCDPort */
#define LCD_LCDPort__0__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__0__HSIOM_MASK 0x0000000Fu
#define LCD_LCDPort__0__HSIOM_SHIFT 0u
#define LCD_LCDPort__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__0__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__0__MASK 0x01u
#define LCD_LCDPort__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__0__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__0__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__0__PORT 2u
#define LCD_LCDPort__0__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__0__SHIFT 0u
#define LCD_LCDPort__1__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__1__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__1__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__1__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__1__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__1__HSIOM_MASK 0x000000F0u
#define LCD_LCDPort__1__HSIOM_SHIFT 4u
#define LCD_LCDPort__1__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__1__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__1__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__1__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__1__MASK 0x02u
#define LCD_LCDPort__1__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__1__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__1__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__1__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__1__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__1__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__1__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__1__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__1__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__1__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__1__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__1__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__1__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__1__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__1__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__1__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__1__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__1__PORT 2u
#define LCD_LCDPort__1__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__1__SHIFT 1u
#define LCD_LCDPort__2__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__2__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__2__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__2__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__2__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__2__HSIOM_MASK 0x00000F00u
#define LCD_LCDPort__2__HSIOM_SHIFT 8u
#define LCD_LCDPort__2__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__2__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__2__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__2__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__2__MASK 0x04u
#define LCD_LCDPort__2__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__2__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__2__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__2__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__2__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__2__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__2__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__2__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__2__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__2__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__2__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__2__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__2__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__2__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__2__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__2__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__2__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__2__PORT 2u
#define LCD_LCDPort__2__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__2__SHIFT 2u
#define LCD_LCDPort__3__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__3__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__3__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__3__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__3__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__3__HSIOM_MASK 0x0000F000u
#define LCD_LCDPort__3__HSIOM_SHIFT 12u
#define LCD_LCDPort__3__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__3__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__3__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__3__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__3__MASK 0x08u
#define LCD_LCDPort__3__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__3__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__3__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__3__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__3__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__3__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__3__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__3__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__3__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__3__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__3__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__3__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__3__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__3__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__3__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__3__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__3__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__3__PORT 2u
#define LCD_LCDPort__3__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__3__SHIFT 3u
#define LCD_LCDPort__4__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__4__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__4__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__4__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__4__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__4__HSIOM_MASK 0x000F0000u
#define LCD_LCDPort__4__HSIOM_SHIFT 16u
#define LCD_LCDPort__4__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__4__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__4__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__4__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__4__MASK 0x10u
#define LCD_LCDPort__4__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__4__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__4__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__4__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__4__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__4__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__4__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__4__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__4__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__4__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__4__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__4__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__4__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__4__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__4__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__4__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__4__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__4__PORT 2u
#define LCD_LCDPort__4__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__4__SHIFT 4u
#define LCD_LCDPort__5__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__5__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__5__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__5__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__5__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__5__HSIOM_MASK 0x00F00000u
#define LCD_LCDPort__5__HSIOM_SHIFT 20u
#define LCD_LCDPort__5__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__5__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__5__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__5__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__5__MASK 0x20u
#define LCD_LCDPort__5__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__5__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__5__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__5__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__5__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__5__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__5__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__5__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__5__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__5__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__5__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__5__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__5__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__5__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__5__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__5__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__5__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__5__PORT 2u
#define LCD_LCDPort__5__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__5__SHIFT 5u
#define LCD_LCDPort__6__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__6__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__6__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__6__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__6__HSIOM CYREG_HSIOM_PORT_SEL2
#define LCD_LCDPort__6__HSIOM_MASK 0x0F000000u
#define LCD_LCDPort__6__HSIOM_SHIFT 24u
#define LCD_LCDPort__6__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__6__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__6__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__6__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__6__MASK 0x40u
#define LCD_LCDPort__6__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__6__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__6__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__6__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__6__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__6__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__6__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__6__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__6__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__6__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__6__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__6__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__6__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__6__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__6__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__6__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__6__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__6__PORT 2u
#define LCD_LCDPort__6__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__6__SHIFT 6u
#define LCD_LCDPort__DR CYREG_GPIO_PRT2_DR
#define LCD_LCDPort__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LCD_LCDPort__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LCD_LCDPort__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LCD_LCDPort__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__INTR CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LCD_LCDPort__INTSTAT CYREG_GPIO_PRT2_INTR
#define LCD_LCDPort__MASK 0x7Fu
#define LCD_LCDPort__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LCD_LCDPort__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LCD_LCDPort__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LCD_LCDPort__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LCD_LCDPort__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LCD_LCDPort__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LCD_LCDPort__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LCD_LCDPort__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LCD_LCDPort__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LCD_LCDPort__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LCD_LCDPort__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LCD_LCDPort__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LCD_LCDPort__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LCD_LCDPort__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LCD_LCDPort__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LCD_LCDPort__PC CYREG_GPIO_PRT2_PC
#define LCD_LCDPort__PC2 CYREG_GPIO_PRT2_PC2
#define LCD_LCDPort__PORT 2u
#define LCD_LCDPort__PS CYREG_GPIO_PRT2_PS
#define LCD_LCDPort__SHIFT 0u

/* Miscellaneous */
#define CY_PROJECT_NAME "Lab1"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 48000000U
#define CYDEV_BCLK__HFCLK__KHZ 48000U
#define CYDEV_BCLK__HFCLK__MHZ 48U
#define CYDEV_BCLK__SYSCLK__HZ 48000000U
#define CYDEV_BCLK__SYSCLK__KHZ 48000U
#define CYDEV_BCLK__SYSCLK__MHZ 48U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x112D11A1u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4M
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4M_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_Disallowed
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 10u
#define CYDEV_DFT_SELECT_CLK1 11u
#define CYDEV_DMA_CHANNELS_AVAILABLE 8
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 0u
#define CYDEV_INTR_NUMBER_DMA 13u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO 3.3
#define CYDEV_VDDIO_MV 3300
#define CYDEV_WDT_GENERATE_ISR 1u
#define CYIPBLOCK_m0s8can_VERSION 1
#define CYIPBLOCK_m0s8cpussv2_VERSION 1
#define CYIPBLOCK_m0s8csd_VERSION 1
#define CYIPBLOCK_m0s8ioss_VERSION 1
#define CYIPBLOCK_m0s8lcd_VERSION 2
#define CYIPBLOCK_m0s8lpcomp_VERSION 2
#define CYIPBLOCK_m0s8peri_VERSION 1
#define CYIPBLOCK_m0s8scb_VERSION 2
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 2
#define CYIPBLOCK_m0s8udbif_VERSION 1
#define CYIPBLOCK_m0s8wco_VERSION 1
#define CYIPBLOCK_s8pass4al_VERSION 1
#define DMA_CHANNELS_USED__MASK 0u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
