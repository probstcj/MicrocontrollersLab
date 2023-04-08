/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* I2C */
#define I2C_SCB__CTRL CYREG_SCB0_CTRL
#define I2C_SCB__EZ_DATA0 CYREG_SCB0_EZ_DATA0
#define I2C_SCB__EZ_DATA1 CYREG_SCB0_EZ_DATA1
#define I2C_SCB__EZ_DATA10 CYREG_SCB0_EZ_DATA10
#define I2C_SCB__EZ_DATA11 CYREG_SCB0_EZ_DATA11
#define I2C_SCB__EZ_DATA12 CYREG_SCB0_EZ_DATA12
#define I2C_SCB__EZ_DATA13 CYREG_SCB0_EZ_DATA13
#define I2C_SCB__EZ_DATA14 CYREG_SCB0_EZ_DATA14
#define I2C_SCB__EZ_DATA15 CYREG_SCB0_EZ_DATA15
#define I2C_SCB__EZ_DATA16 CYREG_SCB0_EZ_DATA16
#define I2C_SCB__EZ_DATA17 CYREG_SCB0_EZ_DATA17
#define I2C_SCB__EZ_DATA18 CYREG_SCB0_EZ_DATA18
#define I2C_SCB__EZ_DATA19 CYREG_SCB0_EZ_DATA19
#define I2C_SCB__EZ_DATA2 CYREG_SCB0_EZ_DATA2
#define I2C_SCB__EZ_DATA20 CYREG_SCB0_EZ_DATA20
#define I2C_SCB__EZ_DATA21 CYREG_SCB0_EZ_DATA21
#define I2C_SCB__EZ_DATA22 CYREG_SCB0_EZ_DATA22
#define I2C_SCB__EZ_DATA23 CYREG_SCB0_EZ_DATA23
#define I2C_SCB__EZ_DATA24 CYREG_SCB0_EZ_DATA24
#define I2C_SCB__EZ_DATA25 CYREG_SCB0_EZ_DATA25
#define I2C_SCB__EZ_DATA26 CYREG_SCB0_EZ_DATA26
#define I2C_SCB__EZ_DATA27 CYREG_SCB0_EZ_DATA27
#define I2C_SCB__EZ_DATA28 CYREG_SCB0_EZ_DATA28
#define I2C_SCB__EZ_DATA29 CYREG_SCB0_EZ_DATA29
#define I2C_SCB__EZ_DATA3 CYREG_SCB0_EZ_DATA3
#define I2C_SCB__EZ_DATA30 CYREG_SCB0_EZ_DATA30
#define I2C_SCB__EZ_DATA31 CYREG_SCB0_EZ_DATA31
#define I2C_SCB__EZ_DATA4 CYREG_SCB0_EZ_DATA4
#define I2C_SCB__EZ_DATA5 CYREG_SCB0_EZ_DATA5
#define I2C_SCB__EZ_DATA6 CYREG_SCB0_EZ_DATA6
#define I2C_SCB__EZ_DATA7 CYREG_SCB0_EZ_DATA7
#define I2C_SCB__EZ_DATA8 CYREG_SCB0_EZ_DATA8
#define I2C_SCB__EZ_DATA9 CYREG_SCB0_EZ_DATA9
#define I2C_SCB__I2C_CFG CYREG_SCB0_I2C_CFG
#define I2C_SCB__I2C_CTRL CYREG_SCB0_I2C_CTRL
#define I2C_SCB__I2C_M_CMD CYREG_SCB0_I2C_M_CMD
#define I2C_SCB__I2C_S_CMD CYREG_SCB0_I2C_S_CMD
#define I2C_SCB__I2C_STATUS CYREG_SCB0_I2C_STATUS
#define I2C_SCB__INTR_CAUSE CYREG_SCB0_INTR_CAUSE
#define I2C_SCB__INTR_I2C_EC CYREG_SCB0_INTR_I2C_EC
#define I2C_SCB__INTR_I2C_EC_MASK CYREG_SCB0_INTR_I2C_EC_MASK
#define I2C_SCB__INTR_I2C_EC_MASKED CYREG_SCB0_INTR_I2C_EC_MASKED
#define I2C_SCB__INTR_M CYREG_SCB0_INTR_M
#define I2C_SCB__INTR_M_MASK CYREG_SCB0_INTR_M_MASK
#define I2C_SCB__INTR_M_MASKED CYREG_SCB0_INTR_M_MASKED
#define I2C_SCB__INTR_M_SET CYREG_SCB0_INTR_M_SET
#define I2C_SCB__INTR_RX CYREG_SCB0_INTR_RX
#define I2C_SCB__INTR_RX_MASK CYREG_SCB0_INTR_RX_MASK
#define I2C_SCB__INTR_RX_MASKED CYREG_SCB0_INTR_RX_MASKED
#define I2C_SCB__INTR_RX_SET CYREG_SCB0_INTR_RX_SET
#define I2C_SCB__INTR_S CYREG_SCB0_INTR_S
#define I2C_SCB__INTR_S_MASK CYREG_SCB0_INTR_S_MASK
#define I2C_SCB__INTR_S_MASKED CYREG_SCB0_INTR_S_MASKED
#define I2C_SCB__INTR_S_SET CYREG_SCB0_INTR_S_SET
#define I2C_SCB__INTR_SPI_EC CYREG_SCB0_INTR_SPI_EC
#define I2C_SCB__INTR_SPI_EC_MASK CYREG_SCB0_INTR_SPI_EC_MASK
#define I2C_SCB__INTR_SPI_EC_MASKED CYREG_SCB0_INTR_SPI_EC_MASKED
#define I2C_SCB__INTR_TX CYREG_SCB0_INTR_TX
#define I2C_SCB__INTR_TX_MASK CYREG_SCB0_INTR_TX_MASK
#define I2C_SCB__INTR_TX_MASKED CYREG_SCB0_INTR_TX_MASKED
#define I2C_SCB__INTR_TX_SET CYREG_SCB0_INTR_TX_SET
#define I2C_SCB__RX_CTRL CYREG_SCB0_RX_CTRL
#define I2C_SCB__RX_FIFO_CTRL CYREG_SCB0_RX_FIFO_CTRL
#define I2C_SCB__RX_FIFO_RD CYREG_SCB0_RX_FIFO_RD
#define I2C_SCB__RX_FIFO_RD_SILENT CYREG_SCB0_RX_FIFO_RD_SILENT
#define I2C_SCB__RX_FIFO_STATUS CYREG_SCB0_RX_FIFO_STATUS
#define I2C_SCB__RX_MATCH CYREG_SCB0_RX_MATCH
#define I2C_SCB__SPI_CTRL CYREG_SCB0_SPI_CTRL
#define I2C_SCB__SPI_STATUS CYREG_SCB0_SPI_STATUS
#define I2C_SCB__SS0_POSISTION 0u
#define I2C_SCB__SS1_POSISTION 1u
#define I2C_SCB__SS2_POSISTION 2u
#define I2C_SCB__SS3_POSISTION 3u
#define I2C_SCB__STATUS CYREG_SCB0_STATUS
#define I2C_SCB__TX_CTRL CYREG_SCB0_TX_CTRL
#define I2C_SCB__TX_FIFO_CTRL CYREG_SCB0_TX_FIFO_CTRL
#define I2C_SCB__TX_FIFO_STATUS CYREG_SCB0_TX_FIFO_STATUS
#define I2C_SCB__TX_FIFO_WR CYREG_SCB0_TX_FIFO_WR
#define I2C_SCB__UART_CTRL CYREG_SCB0_UART_CTRL
#define I2C_SCB__UART_FLOW_CTRL CYREG_SCB0_UART_FLOW_CTRL
#define I2C_SCB__UART_RX_CTRL CYREG_SCB0_UART_RX_CTRL
#define I2C_SCB__UART_RX_STATUS CYREG_SCB0_UART_RX_STATUS
#define I2C_SCB__UART_TX_CTRL CYREG_SCB0_UART_TX_CTRL
#define I2C_SCB_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define I2C_SCB_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define I2C_SCB_IRQ__INTC_MASK 0x100u
#define I2C_SCB_IRQ__INTC_NUMBER 8u
#define I2C_SCB_IRQ__INTC_PRIOR_MASK 0xC0u
#define I2C_SCB_IRQ__INTC_PRIOR_NUM 3u
#define I2C_SCB_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR2
#define I2C_SCB_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define I2C_SCB_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR
#define I2C_SCBCLK__CTRL_REGISTER CYREG_PERI_PCLK_CTL2
#define I2C_SCBCLK__DIV_ID 0x00000040u
#define I2C_SCBCLK__DIV_REGISTER CYREG_PERI_DIV_16_CTL0
#define I2C_SCBCLK__PA_DIV_ID 0x000000FFu
#define I2C_scl__0__DR CYREG_GPIO_PRT4_DR
#define I2C_scl__0__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define I2C_scl__0__DR_INV CYREG_GPIO_PRT4_DR_INV
#define I2C_scl__0__DR_SET CYREG_GPIO_PRT4_DR_SET
#define I2C_scl__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define I2C_scl__0__HSIOM_GPIO 0u
#define I2C_scl__0__HSIOM_I2C 14u
#define I2C_scl__0__HSIOM_I2C_SCL 14u
#define I2C_scl__0__HSIOM_MASK 0x0000000Fu
#define I2C_scl__0__HSIOM_SHIFT 0u
#define I2C_scl__0__HSIOM_SPI 15u
#define I2C_scl__0__HSIOM_SPI_MOSI 15u
#define I2C_scl__0__HSIOM_UART 9u
#define I2C_scl__0__HSIOM_UART_RX 9u
#define I2C_scl__0__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_scl__0__INTR CYREG_GPIO_PRT4_INTR
#define I2C_scl__0__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_scl__0__INTSTAT CYREG_GPIO_PRT4_INTR
#define I2C_scl__0__MASK 0x01u
#define I2C_scl__0__PC CYREG_GPIO_PRT4_PC
#define I2C_scl__0__PC2 CYREG_GPIO_PRT4_PC2
#define I2C_scl__0__PORT 4u
#define I2C_scl__0__PS CYREG_GPIO_PRT4_PS
#define I2C_scl__0__SHIFT 0u
#define I2C_scl__DR CYREG_GPIO_PRT4_DR
#define I2C_scl__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define I2C_scl__DR_INV CYREG_GPIO_PRT4_DR_INV
#define I2C_scl__DR_SET CYREG_GPIO_PRT4_DR_SET
#define I2C_scl__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_scl__INTR CYREG_GPIO_PRT4_INTR
#define I2C_scl__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_scl__INTSTAT CYREG_GPIO_PRT4_INTR
#define I2C_scl__MASK 0x01u
#define I2C_scl__PC CYREG_GPIO_PRT4_PC
#define I2C_scl__PC2 CYREG_GPIO_PRT4_PC2
#define I2C_scl__PORT 4u
#define I2C_scl__PS CYREG_GPIO_PRT4_PS
#define I2C_scl__SHIFT 0u
#define I2C_sda__0__DR CYREG_GPIO_PRT4_DR
#define I2C_sda__0__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define I2C_sda__0__DR_INV CYREG_GPIO_PRT4_DR_INV
#define I2C_sda__0__DR_SET CYREG_GPIO_PRT4_DR_SET
#define I2C_sda__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define I2C_sda__0__HSIOM_GPIO 0u
#define I2C_sda__0__HSIOM_I2C 14u
#define I2C_sda__0__HSIOM_I2C_SDA 14u
#define I2C_sda__0__HSIOM_MASK 0x000000F0u
#define I2C_sda__0__HSIOM_SHIFT 4u
#define I2C_sda__0__HSIOM_SPI 15u
#define I2C_sda__0__HSIOM_SPI_MISO 15u
#define I2C_sda__0__HSIOM_UART 9u
#define I2C_sda__0__HSIOM_UART_TX 9u
#define I2C_sda__0__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_sda__0__INTR CYREG_GPIO_PRT4_INTR
#define I2C_sda__0__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_sda__0__INTSTAT CYREG_GPIO_PRT4_INTR
#define I2C_sda__0__MASK 0x02u
#define I2C_sda__0__PC CYREG_GPIO_PRT4_PC
#define I2C_sda__0__PC2 CYREG_GPIO_PRT4_PC2
#define I2C_sda__0__PORT 4u
#define I2C_sda__0__PS CYREG_GPIO_PRT4_PS
#define I2C_sda__0__SHIFT 1u
#define I2C_sda__DR CYREG_GPIO_PRT4_DR
#define I2C_sda__DR_CLR CYREG_GPIO_PRT4_DR_CLR
#define I2C_sda__DR_INV CYREG_GPIO_PRT4_DR_INV
#define I2C_sda__DR_SET CYREG_GPIO_PRT4_DR_SET
#define I2C_sda__INTCFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_sda__INTR CYREG_GPIO_PRT4_INTR
#define I2C_sda__INTR_CFG CYREG_GPIO_PRT4_INTR_CFG
#define I2C_sda__INTSTAT CYREG_GPIO_PRT4_INTR
#define I2C_sda__MASK 0x02u
#define I2C_sda__PC CYREG_GPIO_PRT4_PC
#define I2C_sda__PC2 CYREG_GPIO_PRT4_PC2
#define I2C_sda__PORT 4u
#define I2C_sda__PS CYREG_GPIO_PRT4_PS
#define I2C_sda__SHIFT 1u

/* TEST */
#define TEST__0__DR CYREG_GPIO_PRT0_DR
#define TEST__0__DR_CLR CYREG_GPIO_PRT0_DR_CLR
#define TEST__0__DR_INV CYREG_GPIO_PRT0_DR_INV
#define TEST__0__DR_SET CYREG_GPIO_PRT0_DR_SET
#define TEST__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define TEST__0__HSIOM_MASK 0xF0000000u
#define TEST__0__HSIOM_SHIFT 28u
#define TEST__0__INTCFG CYREG_GPIO_PRT0_INTR_CFG
#define TEST__0__INTR CYREG_GPIO_PRT0_INTR
#define TEST__0__INTR_CFG CYREG_GPIO_PRT0_INTR_CFG
#define TEST__0__INTSTAT CYREG_GPIO_PRT0_INTR
#define TEST__0__MASK 0x80u
#define TEST__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define TEST__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define TEST__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define TEST__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define TEST__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define TEST__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define TEST__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define TEST__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define TEST__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define TEST__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define TEST__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define TEST__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define TEST__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define TEST__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define TEST__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define TEST__0__PC CYREG_GPIO_PRT0_PC
#define TEST__0__PC2 CYREG_GPIO_PRT0_PC2
#define TEST__0__PORT 0u
#define TEST__0__PS CYREG_GPIO_PRT0_PS
#define TEST__0__SHIFT 7u
#define TEST__DR CYREG_GPIO_PRT0_DR
#define TEST__DR_CLR CYREG_GPIO_PRT0_DR_CLR
#define TEST__DR_INV CYREG_GPIO_PRT0_DR_INV
#define TEST__DR_SET CYREG_GPIO_PRT0_DR_SET
#define TEST__INTCFG CYREG_GPIO_PRT0_INTR_CFG
#define TEST__INTR CYREG_GPIO_PRT0_INTR
#define TEST__INTR_CFG CYREG_GPIO_PRT0_INTR_CFG
#define TEST__INTSTAT CYREG_GPIO_PRT0_INTR
#define TEST__MASK 0x80u
#define TEST__PA__CFG0 CYREG_UDB_PA0_CFG0
#define TEST__PA__CFG1 CYREG_UDB_PA0_CFG1
#define TEST__PA__CFG10 CYREG_UDB_PA0_CFG10
#define TEST__PA__CFG11 CYREG_UDB_PA0_CFG11
#define TEST__PA__CFG12 CYREG_UDB_PA0_CFG12
#define TEST__PA__CFG13 CYREG_UDB_PA0_CFG13
#define TEST__PA__CFG14 CYREG_UDB_PA0_CFG14
#define TEST__PA__CFG2 CYREG_UDB_PA0_CFG2
#define TEST__PA__CFG3 CYREG_UDB_PA0_CFG3
#define TEST__PA__CFG4 CYREG_UDB_PA0_CFG4
#define TEST__PA__CFG5 CYREG_UDB_PA0_CFG5
#define TEST__PA__CFG6 CYREG_UDB_PA0_CFG6
#define TEST__PA__CFG7 CYREG_UDB_PA0_CFG7
#define TEST__PA__CFG8 CYREG_UDB_PA0_CFG8
#define TEST__PA__CFG9 CYREG_UDB_PA0_CFG9
#define TEST__PC CYREG_GPIO_PRT0_PC
#define TEST__PC2 CYREG_GPIO_PRT0_PC2
#define TEST__PORT 0u
#define TEST__PS CYREG_GPIO_PRT0_PS
#define TEST__SHIFT 7u
#define TEST__SNAP CYREG_GPIO_PRT0_INTR
#define TEST_ISR__INTC_CLR_EN_REG CYREG_CM0_ICER
#define TEST_ISR__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define TEST_ISR__INTC_MASK 0x01u
#define TEST_ISR__INTC_NUMBER 0u
#define TEST_ISR__INTC_PRIOR_MASK 0xC0u
#define TEST_ISR__INTC_PRIOR_NUM 3u
#define TEST_ISR__INTC_PRIOR_REG CYREG_CM0_IPR0
#define TEST_ISR__INTC_SET_EN_REG CYREG_CM0_ISER
#define TEST_ISR__INTC_SET_PD_REG CYREG_CM0_ISPR

/* LED_B */
#define LED_B__0__DR CYREG_GPIO_PRT6_DR
#define LED_B__0__DR_CLR CYREG_GPIO_PRT6_DR_CLR
#define LED_B__0__DR_INV CYREG_GPIO_PRT6_DR_INV
#define LED_B__0__DR_SET CYREG_GPIO_PRT6_DR_SET
#define LED_B__0__HSIOM CYREG_HSIOM_PORT_SEL6
#define LED_B__0__HSIOM_MASK 0x00F00000u
#define LED_B__0__HSIOM_SHIFT 20u
#define LED_B__0__INTCFG CYREG_GPIO_PRT6_INTR_CFG
#define LED_B__0__INTR CYREG_GPIO_PRT6_INTR
#define LED_B__0__INTR_CFG CYREG_GPIO_PRT6_INTR_CFG
#define LED_B__0__INTSTAT CYREG_GPIO_PRT6_INTR
#define LED_B__0__MASK 0x20u
#define LED_B__0__PC CYREG_GPIO_PRT6_PC
#define LED_B__0__PC2 CYREG_GPIO_PRT6_PC2
#define LED_B__0__PORT 6u
#define LED_B__0__PS CYREG_GPIO_PRT6_PS
#define LED_B__0__SHIFT 5u
#define LED_B__DR CYREG_GPIO_PRT6_DR
#define LED_B__DR_CLR CYREG_GPIO_PRT6_DR_CLR
#define LED_B__DR_INV CYREG_GPIO_PRT6_DR_INV
#define LED_B__DR_SET CYREG_GPIO_PRT6_DR_SET
#define LED_B__INTCFG CYREG_GPIO_PRT6_INTR_CFG
#define LED_B__INTR CYREG_GPIO_PRT6_INTR
#define LED_B__INTR_CFG CYREG_GPIO_PRT6_INTR_CFG
#define LED_B__INTSTAT CYREG_GPIO_PRT6_INTR
#define LED_B__MASK 0x20u
#define LED_B__PC CYREG_GPIO_PRT6_PC
#define LED_B__PC2 CYREG_GPIO_PRT6_PC2
#define LED_B__PORT 6u
#define LED_B__PS CYREG_GPIO_PRT6_PS
#define LED_B__SHIFT 5u

/* LED_G */
#define LED_G__0__DR CYREG_GPIO_PRT2_DR
#define LED_G__0__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_G__0__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_G__0__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_G__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define LED_G__0__HSIOM_MASK 0x0F000000u
#define LED_G__0__HSIOM_SHIFT 24u
#define LED_G__0__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_G__0__INTR CYREG_GPIO_PRT2_INTR
#define LED_G__0__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_G__0__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_G__0__MASK 0x40u
#define LED_G__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_G__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_G__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_G__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_G__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_G__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_G__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_G__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_G__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_G__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_G__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_G__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_G__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_G__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_G__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_G__0__PC CYREG_GPIO_PRT2_PC
#define LED_G__0__PC2 CYREG_GPIO_PRT2_PC2
#define LED_G__0__PORT 2u
#define LED_G__0__PS CYREG_GPIO_PRT2_PS
#define LED_G__0__SHIFT 6u
#define LED_G__DR CYREG_GPIO_PRT2_DR
#define LED_G__DR_CLR CYREG_GPIO_PRT2_DR_CLR
#define LED_G__DR_INV CYREG_GPIO_PRT2_DR_INV
#define LED_G__DR_SET CYREG_GPIO_PRT2_DR_SET
#define LED_G__INTCFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_G__INTR CYREG_GPIO_PRT2_INTR
#define LED_G__INTR_CFG CYREG_GPIO_PRT2_INTR_CFG
#define LED_G__INTSTAT CYREG_GPIO_PRT2_INTR
#define LED_G__MASK 0x40u
#define LED_G__PA__CFG0 CYREG_UDB_PA2_CFG0
#define LED_G__PA__CFG1 CYREG_UDB_PA2_CFG1
#define LED_G__PA__CFG10 CYREG_UDB_PA2_CFG10
#define LED_G__PA__CFG11 CYREG_UDB_PA2_CFG11
#define LED_G__PA__CFG12 CYREG_UDB_PA2_CFG12
#define LED_G__PA__CFG13 CYREG_UDB_PA2_CFG13
#define LED_G__PA__CFG14 CYREG_UDB_PA2_CFG14
#define LED_G__PA__CFG2 CYREG_UDB_PA2_CFG2
#define LED_G__PA__CFG3 CYREG_UDB_PA2_CFG3
#define LED_G__PA__CFG4 CYREG_UDB_PA2_CFG4
#define LED_G__PA__CFG5 CYREG_UDB_PA2_CFG5
#define LED_G__PA__CFG6 CYREG_UDB_PA2_CFG6
#define LED_G__PA__CFG7 CYREG_UDB_PA2_CFG7
#define LED_G__PA__CFG8 CYREG_UDB_PA2_CFG8
#define LED_G__PA__CFG9 CYREG_UDB_PA2_CFG9
#define LED_G__PC CYREG_GPIO_PRT2_PC
#define LED_G__PC2 CYREG_GPIO_PRT2_PC2
#define LED_G__PORT 2u
#define LED_G__PS CYREG_GPIO_PRT2_PS
#define LED_G__SHIFT 6u

/* LED_R */
#define LED_R__0__DR CYREG_GPIO_PRT0_DR
#define LED_R__0__DR_CLR CYREG_GPIO_PRT0_DR_CLR
#define LED_R__0__DR_INV CYREG_GPIO_PRT0_DR_INV
#define LED_R__0__DR_SET CYREG_GPIO_PRT0_DR_SET
#define LED_R__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define LED_R__0__HSIOM_MASK 0x0F000000u
#define LED_R__0__HSIOM_SHIFT 24u
#define LED_R__0__INTCFG CYREG_GPIO_PRT0_INTR_CFG
#define LED_R__0__INTR CYREG_GPIO_PRT0_INTR
#define LED_R__0__INTR_CFG CYREG_GPIO_PRT0_INTR_CFG
#define LED_R__0__INTSTAT CYREG_GPIO_PRT0_INTR
#define LED_R__0__MASK 0x40u
#define LED_R__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define LED_R__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define LED_R__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define LED_R__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define LED_R__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define LED_R__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define LED_R__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define LED_R__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define LED_R__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define LED_R__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define LED_R__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define LED_R__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define LED_R__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define LED_R__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define LED_R__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define LED_R__0__PC CYREG_GPIO_PRT0_PC
#define LED_R__0__PC2 CYREG_GPIO_PRT0_PC2
#define LED_R__0__PORT 0u
#define LED_R__0__PS CYREG_GPIO_PRT0_PS
#define LED_R__0__SHIFT 6u
#define LED_R__DR CYREG_GPIO_PRT0_DR
#define LED_R__DR_CLR CYREG_GPIO_PRT0_DR_CLR
#define LED_R__DR_INV CYREG_GPIO_PRT0_DR_INV
#define LED_R__DR_SET CYREG_GPIO_PRT0_DR_SET
#define LED_R__INTCFG CYREG_GPIO_PRT0_INTR_CFG
#define LED_R__INTR CYREG_GPIO_PRT0_INTR
#define LED_R__INTR_CFG CYREG_GPIO_PRT0_INTR_CFG
#define LED_R__INTSTAT CYREG_GPIO_PRT0_INTR
#define LED_R__MASK 0x40u
#define LED_R__PA__CFG0 CYREG_UDB_PA0_CFG0
#define LED_R__PA__CFG1 CYREG_UDB_PA0_CFG1
#define LED_R__PA__CFG10 CYREG_UDB_PA0_CFG10
#define LED_R__PA__CFG11 CYREG_UDB_PA0_CFG11
#define LED_R__PA__CFG12 CYREG_UDB_PA0_CFG12
#define LED_R__PA__CFG13 CYREG_UDB_PA0_CFG13
#define LED_R__PA__CFG14 CYREG_UDB_PA0_CFG14
#define LED_R__PA__CFG2 CYREG_UDB_PA0_CFG2
#define LED_R__PA__CFG3 CYREG_UDB_PA0_CFG3
#define LED_R__PA__CFG4 CYREG_UDB_PA0_CFG4
#define LED_R__PA__CFG5 CYREG_UDB_PA0_CFG5
#define LED_R__PA__CFG6 CYREG_UDB_PA0_CFG6
#define LED_R__PA__CFG7 CYREG_UDB_PA0_CFG7
#define LED_R__PA__CFG8 CYREG_UDB_PA0_CFG8
#define LED_R__PA__CFG9 CYREG_UDB_PA0_CFG9
#define LED_R__PC CYREG_GPIO_PRT0_PC
#define LED_R__PC2 CYREG_GPIO_PRT0_PC2
#define LED_R__PORT 0u
#define LED_R__PS CYREG_GPIO_PRT0_PS
#define LED_R__SHIFT 6u

/* ACCEL_INT */
#define ACCEL_INT__0__DR CYREG_GPIO_PRT1_DR
#define ACCEL_INT__0__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define ACCEL_INT__0__DR_INV CYREG_GPIO_PRT1_DR_INV
#define ACCEL_INT__0__DR_SET CYREG_GPIO_PRT1_DR_SET
#define ACCEL_INT__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define ACCEL_INT__0__HSIOM_MASK 0x0F000000u
#define ACCEL_INT__0__HSIOM_SHIFT 24u
#define ACCEL_INT__0__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define ACCEL_INT__0__INTR CYREG_GPIO_PRT1_INTR
#define ACCEL_INT__0__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define ACCEL_INT__0__INTSTAT CYREG_GPIO_PRT1_INTR
#define ACCEL_INT__0__MASK 0x40u
#define ACCEL_INT__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define ACCEL_INT__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define ACCEL_INT__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define ACCEL_INT__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define ACCEL_INT__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define ACCEL_INT__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define ACCEL_INT__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define ACCEL_INT__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define ACCEL_INT__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define ACCEL_INT__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define ACCEL_INT__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define ACCEL_INT__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define ACCEL_INT__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define ACCEL_INT__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define ACCEL_INT__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define ACCEL_INT__0__PC CYREG_GPIO_PRT1_PC
#define ACCEL_INT__0__PC2 CYREG_GPIO_PRT1_PC2
#define ACCEL_INT__0__PORT 1u
#define ACCEL_INT__0__PS CYREG_GPIO_PRT1_PS
#define ACCEL_INT__0__SHIFT 6u
#define ACCEL_INT__DR CYREG_GPIO_PRT1_DR
#define ACCEL_INT__DR_CLR CYREG_GPIO_PRT1_DR_CLR
#define ACCEL_INT__DR_INV CYREG_GPIO_PRT1_DR_INV
#define ACCEL_INT__DR_SET CYREG_GPIO_PRT1_DR_SET
#define ACCEL_INT__INTCFG CYREG_GPIO_PRT1_INTR_CFG
#define ACCEL_INT__INTR CYREG_GPIO_PRT1_INTR
#define ACCEL_INT__INTR_CFG CYREG_GPIO_PRT1_INTR_CFG
#define ACCEL_INT__INTSTAT CYREG_GPIO_PRT1_INTR
#define ACCEL_INT__MASK 0x40u
#define ACCEL_INT__PA__CFG0 CYREG_UDB_PA1_CFG0
#define ACCEL_INT__PA__CFG1 CYREG_UDB_PA1_CFG1
#define ACCEL_INT__PA__CFG10 CYREG_UDB_PA1_CFG10
#define ACCEL_INT__PA__CFG11 CYREG_UDB_PA1_CFG11
#define ACCEL_INT__PA__CFG12 CYREG_UDB_PA1_CFG12
#define ACCEL_INT__PA__CFG13 CYREG_UDB_PA1_CFG13
#define ACCEL_INT__PA__CFG14 CYREG_UDB_PA1_CFG14
#define ACCEL_INT__PA__CFG2 CYREG_UDB_PA1_CFG2
#define ACCEL_INT__PA__CFG3 CYREG_UDB_PA1_CFG3
#define ACCEL_INT__PA__CFG4 CYREG_UDB_PA1_CFG4
#define ACCEL_INT__PA__CFG5 CYREG_UDB_PA1_CFG5
#define ACCEL_INT__PA__CFG6 CYREG_UDB_PA1_CFG6
#define ACCEL_INT__PA__CFG7 CYREG_UDB_PA1_CFG7
#define ACCEL_INT__PA__CFG8 CYREG_UDB_PA1_CFG8
#define ACCEL_INT__PA__CFG9 CYREG_UDB_PA1_CFG9
#define ACCEL_INT__PC CYREG_GPIO_PRT1_PC
#define ACCEL_INT__PC2 CYREG_GPIO_PRT1_PC2
#define ACCEL_INT__PORT 1u
#define ACCEL_INT__PS CYREG_GPIO_PRT1_PS
#define ACCEL_INT__SHIFT 6u
#define ACCEL_INT__SNAP CYREG_GPIO_PRT1_INTR

/* ACCEL_ISR */
#define ACCEL_ISR__INTC_CLR_EN_REG CYREG_CM0_ICER
#define ACCEL_ISR__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define ACCEL_ISR__INTC_MASK 0x02u
#define ACCEL_ISR__INTC_NUMBER 1u
#define ACCEL_ISR__INTC_PRIOR_MASK 0xC000u
#define ACCEL_ISR__INTC_PRIOR_NUM 3u
#define ACCEL_ISR__INTC_PRIOR_REG CYREG_CM0_IPR0
#define ACCEL_ISR__INTC_SET_EN_REG CYREG_CM0_ISER
#define ACCEL_ISR__INTC_SET_PD_REG CYREG_CM0_ISPR

/* Miscellaneous */
#define CY_PROJECT_NAME "Lab 5 - I2C"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 48000000U
#define CYDEV_BCLK__HFCLK__KHZ 48000U
#define CYDEV_BCLK__HFCLK__MHZ 48U
#define CYDEV_BCLK__SYSCLK__HZ 48000000U
#define CYDEV_BCLK__SYSCLK__KHZ 48000U
#define CYDEV_BCLK__SYSCLK__MHZ 48U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
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
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
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
#define CYDEV_HEAP_SIZE 0x200
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
