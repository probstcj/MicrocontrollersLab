/*******************************************************************************
* File Name: LED_PWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the LED_PWM
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_LED_PWM_H)
#define CY_TCPWM_LED_PWM_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} LED_PWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  LED_PWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define LED_PWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define LED_PWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define LED_PWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define LED_PWM_QUAD_ENCODING_MODES            (0lu)
#define LED_PWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define LED_PWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define LED_PWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define LED_PWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define LED_PWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define LED_PWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define LED_PWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define LED_PWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define LED_PWM_TC_RUN_MODE                    (0lu)
#define LED_PWM_TC_COUNTER_MODE                (0lu)
#define LED_PWM_TC_COMP_CAP_MODE               (2lu)
#define LED_PWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define LED_PWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define LED_PWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define LED_PWM_TC_START_SIGNAL_MODE           (0lu)
#define LED_PWM_TC_STOP_SIGNAL_MODE            (0lu)
#define LED_PWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define LED_PWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define LED_PWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define LED_PWM_TC_START_SIGNAL_PRESENT        (0lu)
#define LED_PWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define LED_PWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define LED_PWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define LED_PWM_PWM_KILL_EVENT                 (0lu)
#define LED_PWM_PWM_STOP_EVENT                 (0lu)
#define LED_PWM_PWM_MODE                       (4lu)
#define LED_PWM_PWM_OUT_N_INVERT               (0lu)
#define LED_PWM_PWM_OUT_INVERT                 (0lu)
#define LED_PWM_PWM_ALIGN                      (0lu)
#define LED_PWM_PWM_RUN_MODE                   (0lu)
#define LED_PWM_PWM_DEAD_TIME_CYCLE            (0lu)
#define LED_PWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define LED_PWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define LED_PWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define LED_PWM_PWM_START_SIGNAL_MODE          (0lu)
#define LED_PWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define LED_PWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define LED_PWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define LED_PWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define LED_PWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define LED_PWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define LED_PWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define LED_PWM_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define LED_PWM_TC_PERIOD_VALUE                (65535lu)
#define LED_PWM_TC_COMPARE_VALUE               (65535lu)
#define LED_PWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define LED_PWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define LED_PWM_PWM_PERIOD_VALUE               (65535lu)
#define LED_PWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define LED_PWM_PWM_PERIOD_SWAP                (0lu)
#define LED_PWM_PWM_COMPARE_VALUE              (65535lu)
#define LED_PWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define LED_PWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define LED_PWM__LEFT 0
#define LED_PWM__RIGHT 1
#define LED_PWM__CENTER 2
#define LED_PWM__ASYMMETRIC 3

#define LED_PWM__X1 0
#define LED_PWM__X2 1
#define LED_PWM__X4 2

#define LED_PWM__PWM 4
#define LED_PWM__PWM_DT 5
#define LED_PWM__PWM_PR 6

#define LED_PWM__INVERSE 1
#define LED_PWM__DIRECT 0

#define LED_PWM__CAPTURE 2
#define LED_PWM__COMPARE 0

#define LED_PWM__TRIG_LEVEL 3
#define LED_PWM__TRIG_RISING 0
#define LED_PWM__TRIG_FALLING 1
#define LED_PWM__TRIG_BOTH 2

#define LED_PWM__INTR_MASK_TC 1
#define LED_PWM__INTR_MASK_CC_MATCH 2
#define LED_PWM__INTR_MASK_NONE 0
#define LED_PWM__INTR_MASK_TC_CC 3

#define LED_PWM__UNCONFIG 8
#define LED_PWM__TIMER 1
#define LED_PWM__QUAD 3
#define LED_PWM__PWM_SEL 7

#define LED_PWM__COUNT_UP 0
#define LED_PWM__COUNT_DOWN 1
#define LED_PWM__COUNT_UPDOWN0 2
#define LED_PWM__COUNT_UPDOWN1 3


/* Prescaler */
#define LED_PWM_PRESCALE_DIVBY1                ((uint32)(0u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY2                ((uint32)(1u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY4                ((uint32)(2u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY8                ((uint32)(3u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY16               ((uint32)(4u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY32               ((uint32)(5u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY64               ((uint32)(6u << LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_PRESCALE_DIVBY128              ((uint32)(7u << LED_PWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define LED_PWM_MODE_TIMER_COMPARE             ((uint32)(LED_PWM__COMPARE         <<  \
                                                                  LED_PWM_MODE_SHIFT))
#define LED_PWM_MODE_TIMER_CAPTURE             ((uint32)(LED_PWM__CAPTURE         <<  \
                                                                  LED_PWM_MODE_SHIFT))
#define LED_PWM_MODE_QUAD                      ((uint32)(LED_PWM__QUAD            <<  \
                                                                  LED_PWM_MODE_SHIFT))
#define LED_PWM_MODE_PWM                       ((uint32)(LED_PWM__PWM             <<  \
                                                                  LED_PWM_MODE_SHIFT))
#define LED_PWM_MODE_PWM_DT                    ((uint32)(LED_PWM__PWM_DT          <<  \
                                                                  LED_PWM_MODE_SHIFT))
#define LED_PWM_MODE_PWM_PR                    ((uint32)(LED_PWM__PWM_PR          <<  \
                                                                  LED_PWM_MODE_SHIFT))

/* Quad Modes */
#define LED_PWM_MODE_X1                        ((uint32)(LED_PWM__X1              <<  \
                                                                  LED_PWM_QUAD_MODE_SHIFT))
#define LED_PWM_MODE_X2                        ((uint32)(LED_PWM__X2              <<  \
                                                                  LED_PWM_QUAD_MODE_SHIFT))
#define LED_PWM_MODE_X4                        ((uint32)(LED_PWM__X4              <<  \
                                                                  LED_PWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define LED_PWM_COUNT_UP                       ((uint32)(LED_PWM__COUNT_UP        <<  \
                                                                  LED_PWM_UPDOWN_SHIFT))
#define LED_PWM_COUNT_DOWN                     ((uint32)(LED_PWM__COUNT_DOWN      <<  \
                                                                  LED_PWM_UPDOWN_SHIFT))
#define LED_PWM_COUNT_UPDOWN0                  ((uint32)(LED_PWM__COUNT_UPDOWN0   <<  \
                                                                  LED_PWM_UPDOWN_SHIFT))
#define LED_PWM_COUNT_UPDOWN1                  ((uint32)(LED_PWM__COUNT_UPDOWN1   <<  \
                                                                  LED_PWM_UPDOWN_SHIFT))

/* PWM output invert */
#define LED_PWM_INVERT_LINE                    ((uint32)(LED_PWM__INVERSE         <<  \
                                                                  LED_PWM_INV_OUT_SHIFT))
#define LED_PWM_INVERT_LINE_N                  ((uint32)(LED_PWM__INVERSE         <<  \
                                                                  LED_PWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define LED_PWM_TRIG_RISING                    ((uint32)LED_PWM__TRIG_RISING)
#define LED_PWM_TRIG_FALLING                   ((uint32)LED_PWM__TRIG_FALLING)
#define LED_PWM_TRIG_BOTH                      ((uint32)LED_PWM__TRIG_BOTH)
#define LED_PWM_TRIG_LEVEL                     ((uint32)LED_PWM__TRIG_LEVEL)

/* Interrupt mask */
#define LED_PWM_INTR_MASK_TC                   ((uint32)LED_PWM__INTR_MASK_TC)
#define LED_PWM_INTR_MASK_CC_MATCH             ((uint32)LED_PWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define LED_PWM_CC_MATCH_SET                   (0x00u)
#define LED_PWM_CC_MATCH_CLEAR                 (0x01u)
#define LED_PWM_CC_MATCH_INVERT                (0x02u)
#define LED_PWM_CC_MATCH_NO_CHANGE             (0x03u)
#define LED_PWM_OVERLOW_SET                    (0x00u)
#define LED_PWM_OVERLOW_CLEAR                  (0x04u)
#define LED_PWM_OVERLOW_INVERT                 (0x08u)
#define LED_PWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define LED_PWM_UNDERFLOW_SET                  (0x00u)
#define LED_PWM_UNDERFLOW_CLEAR                (0x10u)
#define LED_PWM_UNDERFLOW_INVERT               (0x20u)
#define LED_PWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define LED_PWM_PWM_MODE_LEFT                  (LED_PWM_CC_MATCH_CLEAR        |   \
                                                         LED_PWM_OVERLOW_SET           |   \
                                                         LED_PWM_UNDERFLOW_NO_CHANGE)
#define LED_PWM_PWM_MODE_RIGHT                 (LED_PWM_CC_MATCH_SET          |   \
                                                         LED_PWM_OVERLOW_NO_CHANGE     |   \
                                                         LED_PWM_UNDERFLOW_CLEAR)
#define LED_PWM_PWM_MODE_ASYM                  (LED_PWM_CC_MATCH_INVERT       |   \
                                                         LED_PWM_OVERLOW_SET           |   \
                                                         LED_PWM_UNDERFLOW_CLEAR)

#if (LED_PWM_CY_TCPWM_V2)
    #if(LED_PWM_CY_TCPWM_4000)
        #define LED_PWM_PWM_MODE_CENTER                (LED_PWM_CC_MATCH_INVERT       |   \
                                                                 LED_PWM_OVERLOW_NO_CHANGE     |   \
                                                                 LED_PWM_UNDERFLOW_CLEAR)
    #else
        #define LED_PWM_PWM_MODE_CENTER                (LED_PWM_CC_MATCH_INVERT       |   \
                                                                 LED_PWM_OVERLOW_SET           |   \
                                                                 LED_PWM_UNDERFLOW_CLEAR)
    #endif /* (LED_PWM_CY_TCPWM_4000) */
#else
    #define LED_PWM_PWM_MODE_CENTER                (LED_PWM_CC_MATCH_INVERT       |   \
                                                             LED_PWM_OVERLOW_NO_CHANGE     |   \
                                                             LED_PWM_UNDERFLOW_CLEAR)
#endif /* (LED_PWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define LED_PWM_CMD_CAPTURE                    (0u)
#define LED_PWM_CMD_RELOAD                     (8u)
#define LED_PWM_CMD_STOP                       (16u)
#define LED_PWM_CMD_START                      (24u)

/* Status */
#define LED_PWM_STATUS_DOWN                    (1u)
#define LED_PWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   LED_PWM_Init(void);
void   LED_PWM_Enable(void);
void   LED_PWM_Start(void);
void   LED_PWM_Stop(void);

void   LED_PWM_SetMode(uint32 mode);
void   LED_PWM_SetCounterMode(uint32 counterMode);
void   LED_PWM_SetPWMMode(uint32 modeMask);
void   LED_PWM_SetQDMode(uint32 qdMode);

void   LED_PWM_SetPrescaler(uint32 prescaler);
void   LED_PWM_TriggerCommand(uint32 mask, uint32 command);
void   LED_PWM_SetOneShot(uint32 oneShotEnable);
uint32 LED_PWM_ReadStatus(void);

void   LED_PWM_SetPWMSyncKill(uint32 syncKillEnable);
void   LED_PWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   LED_PWM_SetPWMDeadTime(uint32 deadTime);
void   LED_PWM_SetPWMInvert(uint32 mask);

void   LED_PWM_SetInterruptMode(uint32 interruptMask);
uint32 LED_PWM_GetInterruptSourceMasked(void);
uint32 LED_PWM_GetInterruptSource(void);
void   LED_PWM_ClearInterrupt(uint32 interruptMask);
void   LED_PWM_SetInterrupt(uint32 interruptMask);

void   LED_PWM_WriteCounter(uint32 count);
uint32 LED_PWM_ReadCounter(void);

uint32 LED_PWM_ReadCapture(void);
uint32 LED_PWM_ReadCaptureBuf(void);

void   LED_PWM_WritePeriod(uint32 period);
uint32 LED_PWM_ReadPeriod(void);
void   LED_PWM_WritePeriodBuf(uint32 periodBuf);
uint32 LED_PWM_ReadPeriodBuf(void);

void   LED_PWM_WriteCompare(uint32 compare);
uint32 LED_PWM_ReadCompare(void);
void   LED_PWM_WriteCompareBuf(uint32 compareBuf);
uint32 LED_PWM_ReadCompareBuf(void);

void   LED_PWM_SetPeriodSwap(uint32 swapEnable);
void   LED_PWM_SetCompareSwap(uint32 swapEnable);

void   LED_PWM_SetCaptureMode(uint32 triggerMode);
void   LED_PWM_SetReloadMode(uint32 triggerMode);
void   LED_PWM_SetStartMode(uint32 triggerMode);
void   LED_PWM_SetStopMode(uint32 triggerMode);
void   LED_PWM_SetCountMode(uint32 triggerMode);

void   LED_PWM_SaveConfig(void);
void   LED_PWM_RestoreConfig(void);
void   LED_PWM_Sleep(void);
void   LED_PWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define LED_PWM_BLOCK_CONTROL_REG              (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define LED_PWM_BLOCK_CONTROL_PTR              ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define LED_PWM_COMMAND_REG                    (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define LED_PWM_COMMAND_PTR                    ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define LED_PWM_INTRRUPT_CAUSE_REG             (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define LED_PWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define LED_PWM_CONTROL_REG                    (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__CTRL )
#define LED_PWM_CONTROL_PTR                    ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__CTRL )
#define LED_PWM_STATUS_REG                     (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__STATUS )
#define LED_PWM_STATUS_PTR                     ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__STATUS )
#define LED_PWM_COUNTER_REG                    (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__COUNTER )
#define LED_PWM_COUNTER_PTR                    ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__COUNTER )
#define LED_PWM_COMP_CAP_REG                   (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__CC )
#define LED_PWM_COMP_CAP_PTR                   ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__CC )
#define LED_PWM_COMP_CAP_BUF_REG               (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define LED_PWM_COMP_CAP_BUF_PTR               ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define LED_PWM_PERIOD_REG                     (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__PERIOD )
#define LED_PWM_PERIOD_PTR                     ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__PERIOD )
#define LED_PWM_PERIOD_BUF_REG                 (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define LED_PWM_PERIOD_BUF_PTR                 ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define LED_PWM_TRIG_CONTROL0_REG              (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define LED_PWM_TRIG_CONTROL0_PTR              ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define LED_PWM_TRIG_CONTROL1_REG              (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define LED_PWM_TRIG_CONTROL1_PTR              ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define LED_PWM_TRIG_CONTROL2_REG              (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define LED_PWM_TRIG_CONTROL2_PTR              ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define LED_PWM_INTERRUPT_REQ_REG              (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR )
#define LED_PWM_INTERRUPT_REQ_PTR              ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR )
#define LED_PWM_INTERRUPT_SET_REG              (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define LED_PWM_INTERRUPT_SET_PTR              ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define LED_PWM_INTERRUPT_MASK_REG             (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define LED_PWM_INTERRUPT_MASK_PTR             ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define LED_PWM_INTERRUPT_MASKED_REG           (*(reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define LED_PWM_INTERRUPT_MASKED_PTR           ( (reg32 *) LED_PWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define LED_PWM_MASK                           ((uint32)LED_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define LED_PWM_RELOAD_CC_SHIFT                (0u)
#define LED_PWM_RELOAD_PERIOD_SHIFT            (1u)
#define LED_PWM_PWM_SYNC_KILL_SHIFT            (2u)
#define LED_PWM_PWM_STOP_KILL_SHIFT            (3u)
#define LED_PWM_PRESCALER_SHIFT                (8u)
#define LED_PWM_UPDOWN_SHIFT                   (16u)
#define LED_PWM_ONESHOT_SHIFT                  (18u)
#define LED_PWM_QUAD_MODE_SHIFT                (20u)
#define LED_PWM_INV_OUT_SHIFT                  (20u)
#define LED_PWM_INV_COMPL_OUT_SHIFT            (21u)
#define LED_PWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define LED_PWM_RELOAD_CC_MASK                 ((uint32)(LED_PWM_1BIT_MASK        <<  \
                                                                            LED_PWM_RELOAD_CC_SHIFT))
#define LED_PWM_RELOAD_PERIOD_MASK             ((uint32)(LED_PWM_1BIT_MASK        <<  \
                                                                            LED_PWM_RELOAD_PERIOD_SHIFT))
#define LED_PWM_PWM_SYNC_KILL_MASK             ((uint32)(LED_PWM_1BIT_MASK        <<  \
                                                                            LED_PWM_PWM_SYNC_KILL_SHIFT))
#define LED_PWM_PWM_STOP_KILL_MASK             ((uint32)(LED_PWM_1BIT_MASK        <<  \
                                                                            LED_PWM_PWM_STOP_KILL_SHIFT))
#define LED_PWM_PRESCALER_MASK                 ((uint32)(LED_PWM_8BIT_MASK        <<  \
                                                                            LED_PWM_PRESCALER_SHIFT))
#define LED_PWM_UPDOWN_MASK                    ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                            LED_PWM_UPDOWN_SHIFT))
#define LED_PWM_ONESHOT_MASK                   ((uint32)(LED_PWM_1BIT_MASK        <<  \
                                                                            LED_PWM_ONESHOT_SHIFT))
#define LED_PWM_QUAD_MODE_MASK                 ((uint32)(LED_PWM_3BIT_MASK        <<  \
                                                                            LED_PWM_QUAD_MODE_SHIFT))
#define LED_PWM_INV_OUT_MASK                   ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                            LED_PWM_INV_OUT_SHIFT))
#define LED_PWM_MODE_MASK                      ((uint32)(LED_PWM_3BIT_MASK        <<  \
                                                                            LED_PWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define LED_PWM_CAPTURE_SHIFT                  (0u)
#define LED_PWM_COUNT_SHIFT                    (2u)
#define LED_PWM_RELOAD_SHIFT                   (4u)
#define LED_PWM_STOP_SHIFT                     (6u)
#define LED_PWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define LED_PWM_CAPTURE_MASK                   ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                  LED_PWM_CAPTURE_SHIFT))
#define LED_PWM_COUNT_MASK                     ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                  LED_PWM_COUNT_SHIFT))
#define LED_PWM_RELOAD_MASK                    ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                  LED_PWM_RELOAD_SHIFT))
#define LED_PWM_STOP_MASK                      ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                  LED_PWM_STOP_SHIFT))
#define LED_PWM_START_MASK                     ((uint32)(LED_PWM_2BIT_MASK        <<  \
                                                                  LED_PWM_START_SHIFT))

/* MASK */
#define LED_PWM_1BIT_MASK                      ((uint32)0x01u)
#define LED_PWM_2BIT_MASK                      ((uint32)0x03u)
#define LED_PWM_3BIT_MASK                      ((uint32)0x07u)
#define LED_PWM_6BIT_MASK                      ((uint32)0x3Fu)
#define LED_PWM_8BIT_MASK                      ((uint32)0xFFu)
#define LED_PWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define LED_PWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define LED_PWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(LED_PWM_QUAD_ENCODING_MODES     << LED_PWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(LED_PWM_CONFIG                  << LED_PWM_MODE_SHIFT)))

#define LED_PWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(LED_PWM_PWM_STOP_EVENT          << LED_PWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(LED_PWM_PWM_OUT_INVERT          << LED_PWM_INV_OUT_SHIFT))         |\
         ((uint32)(LED_PWM_PWM_OUT_N_INVERT        << LED_PWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(LED_PWM_PWM_MODE                << LED_PWM_MODE_SHIFT)))

#define LED_PWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(LED_PWM_PWM_RUN_MODE         << LED_PWM_ONESHOT_SHIFT))
            
#define LED_PWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(LED_PWM_PWM_ALIGN            << LED_PWM_UPDOWN_SHIFT))

#define LED_PWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(LED_PWM_PWM_KILL_EVENT      << LED_PWM_PWM_SYNC_KILL_SHIFT))

#define LED_PWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(LED_PWM_PWM_DEAD_TIME_CYCLE  << LED_PWM_PRESCALER_SHIFT))

#define LED_PWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(LED_PWM_PWM_PRESCALER        << LED_PWM_PRESCALER_SHIFT))

#define LED_PWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(LED_PWM_TC_PRESCALER            << LED_PWM_PRESCALER_SHIFT))       |\
         ((uint32)(LED_PWM_TC_COUNTER_MODE         << LED_PWM_UPDOWN_SHIFT))          |\
         ((uint32)(LED_PWM_TC_RUN_MODE             << LED_PWM_ONESHOT_SHIFT))         |\
         ((uint32)(LED_PWM_TC_COMP_CAP_MODE        << LED_PWM_MODE_SHIFT)))
        
#define LED_PWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(LED_PWM_QUAD_PHIA_SIGNAL_MODE   << LED_PWM_COUNT_SHIFT))           |\
         ((uint32)(LED_PWM_QUAD_INDEX_SIGNAL_MODE  << LED_PWM_RELOAD_SHIFT))          |\
         ((uint32)(LED_PWM_QUAD_STOP_SIGNAL_MODE   << LED_PWM_STOP_SHIFT))            |\
         ((uint32)(LED_PWM_QUAD_PHIB_SIGNAL_MODE   << LED_PWM_START_SHIFT)))

#define LED_PWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(LED_PWM_PWM_SWITCH_SIGNAL_MODE  << LED_PWM_CAPTURE_SHIFT))         |\
         ((uint32)(LED_PWM_PWM_COUNT_SIGNAL_MODE   << LED_PWM_COUNT_SHIFT))           |\
         ((uint32)(LED_PWM_PWM_RELOAD_SIGNAL_MODE  << LED_PWM_RELOAD_SHIFT))          |\
         ((uint32)(LED_PWM_PWM_STOP_SIGNAL_MODE    << LED_PWM_STOP_SHIFT))            |\
         ((uint32)(LED_PWM_PWM_START_SIGNAL_MODE   << LED_PWM_START_SHIFT)))

#define LED_PWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(LED_PWM_TC_CAPTURE_SIGNAL_MODE  << LED_PWM_CAPTURE_SHIFT))         |\
         ((uint32)(LED_PWM_TC_COUNT_SIGNAL_MODE    << LED_PWM_COUNT_SHIFT))           |\
         ((uint32)(LED_PWM_TC_RELOAD_SIGNAL_MODE   << LED_PWM_RELOAD_SHIFT))          |\
         ((uint32)(LED_PWM_TC_STOP_SIGNAL_MODE     << LED_PWM_STOP_SHIFT))            |\
         ((uint32)(LED_PWM_TC_START_SIGNAL_MODE    << LED_PWM_START_SHIFT)))
        
#define LED_PWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((LED_PWM__COUNT_UPDOWN0 == LED_PWM_TC_COUNTER_MODE)                  ||\
                 (LED_PWM__COUNT_UPDOWN1 == LED_PWM_TC_COUNTER_MODE))

#define LED_PWM_PWM_UPDOWN_CNT_USED                                                            \
                ((LED_PWM__CENTER == LED_PWM_PWM_ALIGN)                               ||\
                 (LED_PWM__ASYMMETRIC == LED_PWM_PWM_ALIGN))               
        
#define LED_PWM_PWM_PR_INIT_VALUE              (1u)
#define LED_PWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_LED_PWM_H */

/* [] END OF FILE */
