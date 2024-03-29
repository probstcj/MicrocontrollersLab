/*******************************************************************************
* File Name: SPEAKER_PWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the SPEAKER_PWM
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

#if !defined(CY_TCPWM_SPEAKER_PWM_H)
#define CY_TCPWM_SPEAKER_PWM_H


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
} SPEAKER_PWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  SPEAKER_PWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define SPEAKER_PWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define SPEAKER_PWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define SPEAKER_PWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define SPEAKER_PWM_QUAD_ENCODING_MODES            (0lu)
#define SPEAKER_PWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define SPEAKER_PWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define SPEAKER_PWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define SPEAKER_PWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define SPEAKER_PWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define SPEAKER_PWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define SPEAKER_PWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define SPEAKER_PWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define SPEAKER_PWM_TC_RUN_MODE                    (0lu)
#define SPEAKER_PWM_TC_COUNTER_MODE                (0lu)
#define SPEAKER_PWM_TC_COMP_CAP_MODE               (2lu)
#define SPEAKER_PWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define SPEAKER_PWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define SPEAKER_PWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define SPEAKER_PWM_TC_START_SIGNAL_MODE           (0lu)
#define SPEAKER_PWM_TC_STOP_SIGNAL_MODE            (0lu)
#define SPEAKER_PWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define SPEAKER_PWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define SPEAKER_PWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define SPEAKER_PWM_TC_START_SIGNAL_PRESENT        (0lu)
#define SPEAKER_PWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define SPEAKER_PWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SPEAKER_PWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define SPEAKER_PWM_PWM_KILL_EVENT                 (0lu)
#define SPEAKER_PWM_PWM_STOP_EVENT                 (0lu)
#define SPEAKER_PWM_PWM_MODE                       (4lu)
#define SPEAKER_PWM_PWM_OUT_N_INVERT               (0lu)
#define SPEAKER_PWM_PWM_OUT_INVERT                 (0lu)
#define SPEAKER_PWM_PWM_ALIGN                      (0lu)
#define SPEAKER_PWM_PWM_RUN_MODE                   (0lu)
#define SPEAKER_PWM_PWM_DEAD_TIME_CYCLE            (0lu)
#define SPEAKER_PWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define SPEAKER_PWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define SPEAKER_PWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define SPEAKER_PWM_PWM_START_SIGNAL_MODE          (0lu)
#define SPEAKER_PWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define SPEAKER_PWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define SPEAKER_PWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define SPEAKER_PWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define SPEAKER_PWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define SPEAKER_PWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define SPEAKER_PWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SPEAKER_PWM_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define SPEAKER_PWM_TC_PERIOD_VALUE                (65535lu)
#define SPEAKER_PWM_TC_COMPARE_VALUE               (65535lu)
#define SPEAKER_PWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define SPEAKER_PWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define SPEAKER_PWM_PWM_PERIOD_VALUE               (65535lu)
#define SPEAKER_PWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define SPEAKER_PWM_PWM_PERIOD_SWAP                (0lu)
#define SPEAKER_PWM_PWM_COMPARE_VALUE              (65535lu)
#define SPEAKER_PWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define SPEAKER_PWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define SPEAKER_PWM__LEFT 0
#define SPEAKER_PWM__RIGHT 1
#define SPEAKER_PWM__CENTER 2
#define SPEAKER_PWM__ASYMMETRIC 3

#define SPEAKER_PWM__X1 0
#define SPEAKER_PWM__X2 1
#define SPEAKER_PWM__X4 2

#define SPEAKER_PWM__PWM 4
#define SPEAKER_PWM__PWM_DT 5
#define SPEAKER_PWM__PWM_PR 6

#define SPEAKER_PWM__INVERSE 1
#define SPEAKER_PWM__DIRECT 0

#define SPEAKER_PWM__CAPTURE 2
#define SPEAKER_PWM__COMPARE 0

#define SPEAKER_PWM__TRIG_LEVEL 3
#define SPEAKER_PWM__TRIG_RISING 0
#define SPEAKER_PWM__TRIG_FALLING 1
#define SPEAKER_PWM__TRIG_BOTH 2

#define SPEAKER_PWM__INTR_MASK_TC 1
#define SPEAKER_PWM__INTR_MASK_CC_MATCH 2
#define SPEAKER_PWM__INTR_MASK_NONE 0
#define SPEAKER_PWM__INTR_MASK_TC_CC 3

#define SPEAKER_PWM__UNCONFIG 8
#define SPEAKER_PWM__TIMER 1
#define SPEAKER_PWM__QUAD 3
#define SPEAKER_PWM__PWM_SEL 7

#define SPEAKER_PWM__COUNT_UP 0
#define SPEAKER_PWM__COUNT_DOWN 1
#define SPEAKER_PWM__COUNT_UPDOWN0 2
#define SPEAKER_PWM__COUNT_UPDOWN1 3


/* Prescaler */
#define SPEAKER_PWM_PRESCALE_DIVBY1                ((uint32)(0u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY2                ((uint32)(1u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY4                ((uint32)(2u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY8                ((uint32)(3u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY16               ((uint32)(4u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY32               ((uint32)(5u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY64               ((uint32)(6u << SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_PRESCALE_DIVBY128              ((uint32)(7u << SPEAKER_PWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define SPEAKER_PWM_MODE_TIMER_COMPARE             ((uint32)(SPEAKER_PWM__COMPARE         <<  \
                                                                  SPEAKER_PWM_MODE_SHIFT))
#define SPEAKER_PWM_MODE_TIMER_CAPTURE             ((uint32)(SPEAKER_PWM__CAPTURE         <<  \
                                                                  SPEAKER_PWM_MODE_SHIFT))
#define SPEAKER_PWM_MODE_QUAD                      ((uint32)(SPEAKER_PWM__QUAD            <<  \
                                                                  SPEAKER_PWM_MODE_SHIFT))
#define SPEAKER_PWM_MODE_PWM                       ((uint32)(SPEAKER_PWM__PWM             <<  \
                                                                  SPEAKER_PWM_MODE_SHIFT))
#define SPEAKER_PWM_MODE_PWM_DT                    ((uint32)(SPEAKER_PWM__PWM_DT          <<  \
                                                                  SPEAKER_PWM_MODE_SHIFT))
#define SPEAKER_PWM_MODE_PWM_PR                    ((uint32)(SPEAKER_PWM__PWM_PR          <<  \
                                                                  SPEAKER_PWM_MODE_SHIFT))

/* Quad Modes */
#define SPEAKER_PWM_MODE_X1                        ((uint32)(SPEAKER_PWM__X1              <<  \
                                                                  SPEAKER_PWM_QUAD_MODE_SHIFT))
#define SPEAKER_PWM_MODE_X2                        ((uint32)(SPEAKER_PWM__X2              <<  \
                                                                  SPEAKER_PWM_QUAD_MODE_SHIFT))
#define SPEAKER_PWM_MODE_X4                        ((uint32)(SPEAKER_PWM__X4              <<  \
                                                                  SPEAKER_PWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define SPEAKER_PWM_COUNT_UP                       ((uint32)(SPEAKER_PWM__COUNT_UP        <<  \
                                                                  SPEAKER_PWM_UPDOWN_SHIFT))
#define SPEAKER_PWM_COUNT_DOWN                     ((uint32)(SPEAKER_PWM__COUNT_DOWN      <<  \
                                                                  SPEAKER_PWM_UPDOWN_SHIFT))
#define SPEAKER_PWM_COUNT_UPDOWN0                  ((uint32)(SPEAKER_PWM__COUNT_UPDOWN0   <<  \
                                                                  SPEAKER_PWM_UPDOWN_SHIFT))
#define SPEAKER_PWM_COUNT_UPDOWN1                  ((uint32)(SPEAKER_PWM__COUNT_UPDOWN1   <<  \
                                                                  SPEAKER_PWM_UPDOWN_SHIFT))

/* PWM output invert */
#define SPEAKER_PWM_INVERT_LINE                    ((uint32)(SPEAKER_PWM__INVERSE         <<  \
                                                                  SPEAKER_PWM_INV_OUT_SHIFT))
#define SPEAKER_PWM_INVERT_LINE_N                  ((uint32)(SPEAKER_PWM__INVERSE         <<  \
                                                                  SPEAKER_PWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define SPEAKER_PWM_TRIG_RISING                    ((uint32)SPEAKER_PWM__TRIG_RISING)
#define SPEAKER_PWM_TRIG_FALLING                   ((uint32)SPEAKER_PWM__TRIG_FALLING)
#define SPEAKER_PWM_TRIG_BOTH                      ((uint32)SPEAKER_PWM__TRIG_BOTH)
#define SPEAKER_PWM_TRIG_LEVEL                     ((uint32)SPEAKER_PWM__TRIG_LEVEL)

/* Interrupt mask */
#define SPEAKER_PWM_INTR_MASK_TC                   ((uint32)SPEAKER_PWM__INTR_MASK_TC)
#define SPEAKER_PWM_INTR_MASK_CC_MATCH             ((uint32)SPEAKER_PWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define SPEAKER_PWM_CC_MATCH_SET                   (0x00u)
#define SPEAKER_PWM_CC_MATCH_CLEAR                 (0x01u)
#define SPEAKER_PWM_CC_MATCH_INVERT                (0x02u)
#define SPEAKER_PWM_CC_MATCH_NO_CHANGE             (0x03u)
#define SPEAKER_PWM_OVERLOW_SET                    (0x00u)
#define SPEAKER_PWM_OVERLOW_CLEAR                  (0x04u)
#define SPEAKER_PWM_OVERLOW_INVERT                 (0x08u)
#define SPEAKER_PWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define SPEAKER_PWM_UNDERFLOW_SET                  (0x00u)
#define SPEAKER_PWM_UNDERFLOW_CLEAR                (0x10u)
#define SPEAKER_PWM_UNDERFLOW_INVERT               (0x20u)
#define SPEAKER_PWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define SPEAKER_PWM_PWM_MODE_LEFT                  (SPEAKER_PWM_CC_MATCH_CLEAR        |   \
                                                         SPEAKER_PWM_OVERLOW_SET           |   \
                                                         SPEAKER_PWM_UNDERFLOW_NO_CHANGE)
#define SPEAKER_PWM_PWM_MODE_RIGHT                 (SPEAKER_PWM_CC_MATCH_SET          |   \
                                                         SPEAKER_PWM_OVERLOW_NO_CHANGE     |   \
                                                         SPEAKER_PWM_UNDERFLOW_CLEAR)
#define SPEAKER_PWM_PWM_MODE_ASYM                  (SPEAKER_PWM_CC_MATCH_INVERT       |   \
                                                         SPEAKER_PWM_OVERLOW_SET           |   \
                                                         SPEAKER_PWM_UNDERFLOW_CLEAR)

#if (SPEAKER_PWM_CY_TCPWM_V2)
    #if(SPEAKER_PWM_CY_TCPWM_4000)
        #define SPEAKER_PWM_PWM_MODE_CENTER                (SPEAKER_PWM_CC_MATCH_INVERT       |   \
                                                                 SPEAKER_PWM_OVERLOW_NO_CHANGE     |   \
                                                                 SPEAKER_PWM_UNDERFLOW_CLEAR)
    #else
        #define SPEAKER_PWM_PWM_MODE_CENTER                (SPEAKER_PWM_CC_MATCH_INVERT       |   \
                                                                 SPEAKER_PWM_OVERLOW_SET           |   \
                                                                 SPEAKER_PWM_UNDERFLOW_CLEAR)
    #endif /* (SPEAKER_PWM_CY_TCPWM_4000) */
#else
    #define SPEAKER_PWM_PWM_MODE_CENTER                (SPEAKER_PWM_CC_MATCH_INVERT       |   \
                                                             SPEAKER_PWM_OVERLOW_NO_CHANGE     |   \
                                                             SPEAKER_PWM_UNDERFLOW_CLEAR)
#endif /* (SPEAKER_PWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define SPEAKER_PWM_CMD_CAPTURE                    (0u)
#define SPEAKER_PWM_CMD_RELOAD                     (8u)
#define SPEAKER_PWM_CMD_STOP                       (16u)
#define SPEAKER_PWM_CMD_START                      (24u)

/* Status */
#define SPEAKER_PWM_STATUS_DOWN                    (1u)
#define SPEAKER_PWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   SPEAKER_PWM_Init(void);
void   SPEAKER_PWM_Enable(void);
void   SPEAKER_PWM_Start(void);
void   SPEAKER_PWM_Stop(void);

void   SPEAKER_PWM_SetMode(uint32 mode);
void   SPEAKER_PWM_SetCounterMode(uint32 counterMode);
void   SPEAKER_PWM_SetPWMMode(uint32 modeMask);
void   SPEAKER_PWM_SetQDMode(uint32 qdMode);

void   SPEAKER_PWM_SetPrescaler(uint32 prescaler);
void   SPEAKER_PWM_TriggerCommand(uint32 mask, uint32 command);
void   SPEAKER_PWM_SetOneShot(uint32 oneShotEnable);
uint32 SPEAKER_PWM_ReadStatus(void);

void   SPEAKER_PWM_SetPWMSyncKill(uint32 syncKillEnable);
void   SPEAKER_PWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   SPEAKER_PWM_SetPWMDeadTime(uint32 deadTime);
void   SPEAKER_PWM_SetPWMInvert(uint32 mask);

void   SPEAKER_PWM_SetInterruptMode(uint32 interruptMask);
uint32 SPEAKER_PWM_GetInterruptSourceMasked(void);
uint32 SPEAKER_PWM_GetInterruptSource(void);
void   SPEAKER_PWM_ClearInterrupt(uint32 interruptMask);
void   SPEAKER_PWM_SetInterrupt(uint32 interruptMask);

void   SPEAKER_PWM_WriteCounter(uint32 count);
uint32 SPEAKER_PWM_ReadCounter(void);

uint32 SPEAKER_PWM_ReadCapture(void);
uint32 SPEAKER_PWM_ReadCaptureBuf(void);

void   SPEAKER_PWM_WritePeriod(uint32 period);
uint32 SPEAKER_PWM_ReadPeriod(void);
void   SPEAKER_PWM_WritePeriodBuf(uint32 periodBuf);
uint32 SPEAKER_PWM_ReadPeriodBuf(void);

void   SPEAKER_PWM_WriteCompare(uint32 compare);
uint32 SPEAKER_PWM_ReadCompare(void);
void   SPEAKER_PWM_WriteCompareBuf(uint32 compareBuf);
uint32 SPEAKER_PWM_ReadCompareBuf(void);

void   SPEAKER_PWM_SetPeriodSwap(uint32 swapEnable);
void   SPEAKER_PWM_SetCompareSwap(uint32 swapEnable);

void   SPEAKER_PWM_SetCaptureMode(uint32 triggerMode);
void   SPEAKER_PWM_SetReloadMode(uint32 triggerMode);
void   SPEAKER_PWM_SetStartMode(uint32 triggerMode);
void   SPEAKER_PWM_SetStopMode(uint32 triggerMode);
void   SPEAKER_PWM_SetCountMode(uint32 triggerMode);

void   SPEAKER_PWM_SaveConfig(void);
void   SPEAKER_PWM_RestoreConfig(void);
void   SPEAKER_PWM_Sleep(void);
void   SPEAKER_PWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define SPEAKER_PWM_BLOCK_CONTROL_REG              (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SPEAKER_PWM_BLOCK_CONTROL_PTR              ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SPEAKER_PWM_COMMAND_REG                    (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SPEAKER_PWM_COMMAND_PTR                    ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SPEAKER_PWM_INTRRUPT_CAUSE_REG             (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SPEAKER_PWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SPEAKER_PWM_CONTROL_REG                    (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__CTRL )
#define SPEAKER_PWM_CONTROL_PTR                    ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__CTRL )
#define SPEAKER_PWM_STATUS_REG                     (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__STATUS )
#define SPEAKER_PWM_STATUS_PTR                     ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__STATUS )
#define SPEAKER_PWM_COUNTER_REG                    (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__COUNTER )
#define SPEAKER_PWM_COUNTER_PTR                    ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__COUNTER )
#define SPEAKER_PWM_COMP_CAP_REG                   (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__CC )
#define SPEAKER_PWM_COMP_CAP_PTR                   ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__CC )
#define SPEAKER_PWM_COMP_CAP_BUF_REG               (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define SPEAKER_PWM_COMP_CAP_BUF_PTR               ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define SPEAKER_PWM_PERIOD_REG                     (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__PERIOD )
#define SPEAKER_PWM_PERIOD_PTR                     ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__PERIOD )
#define SPEAKER_PWM_PERIOD_BUF_REG                 (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SPEAKER_PWM_PERIOD_BUF_PTR                 ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SPEAKER_PWM_TRIG_CONTROL0_REG              (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SPEAKER_PWM_TRIG_CONTROL0_PTR              ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SPEAKER_PWM_TRIG_CONTROL1_REG              (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SPEAKER_PWM_TRIG_CONTROL1_PTR              ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SPEAKER_PWM_TRIG_CONTROL2_REG              (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SPEAKER_PWM_TRIG_CONTROL2_PTR              ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SPEAKER_PWM_INTERRUPT_REQ_REG              (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR )
#define SPEAKER_PWM_INTERRUPT_REQ_PTR              ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR )
#define SPEAKER_PWM_INTERRUPT_SET_REG              (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define SPEAKER_PWM_INTERRUPT_SET_PTR              ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define SPEAKER_PWM_INTERRUPT_MASK_REG             (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define SPEAKER_PWM_INTERRUPT_MASK_PTR             ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define SPEAKER_PWM_INTERRUPT_MASKED_REG           (*(reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define SPEAKER_PWM_INTERRUPT_MASKED_PTR           ( (reg32 *) SPEAKER_PWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define SPEAKER_PWM_MASK                           ((uint32)SPEAKER_PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define SPEAKER_PWM_RELOAD_CC_SHIFT                (0u)
#define SPEAKER_PWM_RELOAD_PERIOD_SHIFT            (1u)
#define SPEAKER_PWM_PWM_SYNC_KILL_SHIFT            (2u)
#define SPEAKER_PWM_PWM_STOP_KILL_SHIFT            (3u)
#define SPEAKER_PWM_PRESCALER_SHIFT                (8u)
#define SPEAKER_PWM_UPDOWN_SHIFT                   (16u)
#define SPEAKER_PWM_ONESHOT_SHIFT                  (18u)
#define SPEAKER_PWM_QUAD_MODE_SHIFT                (20u)
#define SPEAKER_PWM_INV_OUT_SHIFT                  (20u)
#define SPEAKER_PWM_INV_COMPL_OUT_SHIFT            (21u)
#define SPEAKER_PWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define SPEAKER_PWM_RELOAD_CC_MASK                 ((uint32)(SPEAKER_PWM_1BIT_MASK        <<  \
                                                                            SPEAKER_PWM_RELOAD_CC_SHIFT))
#define SPEAKER_PWM_RELOAD_PERIOD_MASK             ((uint32)(SPEAKER_PWM_1BIT_MASK        <<  \
                                                                            SPEAKER_PWM_RELOAD_PERIOD_SHIFT))
#define SPEAKER_PWM_PWM_SYNC_KILL_MASK             ((uint32)(SPEAKER_PWM_1BIT_MASK        <<  \
                                                                            SPEAKER_PWM_PWM_SYNC_KILL_SHIFT))
#define SPEAKER_PWM_PWM_STOP_KILL_MASK             ((uint32)(SPEAKER_PWM_1BIT_MASK        <<  \
                                                                            SPEAKER_PWM_PWM_STOP_KILL_SHIFT))
#define SPEAKER_PWM_PRESCALER_MASK                 ((uint32)(SPEAKER_PWM_8BIT_MASK        <<  \
                                                                            SPEAKER_PWM_PRESCALER_SHIFT))
#define SPEAKER_PWM_UPDOWN_MASK                    ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                            SPEAKER_PWM_UPDOWN_SHIFT))
#define SPEAKER_PWM_ONESHOT_MASK                   ((uint32)(SPEAKER_PWM_1BIT_MASK        <<  \
                                                                            SPEAKER_PWM_ONESHOT_SHIFT))
#define SPEAKER_PWM_QUAD_MODE_MASK                 ((uint32)(SPEAKER_PWM_3BIT_MASK        <<  \
                                                                            SPEAKER_PWM_QUAD_MODE_SHIFT))
#define SPEAKER_PWM_INV_OUT_MASK                   ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                            SPEAKER_PWM_INV_OUT_SHIFT))
#define SPEAKER_PWM_MODE_MASK                      ((uint32)(SPEAKER_PWM_3BIT_MASK        <<  \
                                                                            SPEAKER_PWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define SPEAKER_PWM_CAPTURE_SHIFT                  (0u)
#define SPEAKER_PWM_COUNT_SHIFT                    (2u)
#define SPEAKER_PWM_RELOAD_SHIFT                   (4u)
#define SPEAKER_PWM_STOP_SHIFT                     (6u)
#define SPEAKER_PWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define SPEAKER_PWM_CAPTURE_MASK                   ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                  SPEAKER_PWM_CAPTURE_SHIFT))
#define SPEAKER_PWM_COUNT_MASK                     ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                  SPEAKER_PWM_COUNT_SHIFT))
#define SPEAKER_PWM_RELOAD_MASK                    ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                  SPEAKER_PWM_RELOAD_SHIFT))
#define SPEAKER_PWM_STOP_MASK                      ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                  SPEAKER_PWM_STOP_SHIFT))
#define SPEAKER_PWM_START_MASK                     ((uint32)(SPEAKER_PWM_2BIT_MASK        <<  \
                                                                  SPEAKER_PWM_START_SHIFT))

/* MASK */
#define SPEAKER_PWM_1BIT_MASK                      ((uint32)0x01u)
#define SPEAKER_PWM_2BIT_MASK                      ((uint32)0x03u)
#define SPEAKER_PWM_3BIT_MASK                      ((uint32)0x07u)
#define SPEAKER_PWM_6BIT_MASK                      ((uint32)0x3Fu)
#define SPEAKER_PWM_8BIT_MASK                      ((uint32)0xFFu)
#define SPEAKER_PWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define SPEAKER_PWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define SPEAKER_PWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(SPEAKER_PWM_QUAD_ENCODING_MODES     << SPEAKER_PWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(SPEAKER_PWM_CONFIG                  << SPEAKER_PWM_MODE_SHIFT)))

#define SPEAKER_PWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(SPEAKER_PWM_PWM_STOP_EVENT          << SPEAKER_PWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(SPEAKER_PWM_PWM_OUT_INVERT          << SPEAKER_PWM_INV_OUT_SHIFT))         |\
         ((uint32)(SPEAKER_PWM_PWM_OUT_N_INVERT        << SPEAKER_PWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(SPEAKER_PWM_PWM_MODE                << SPEAKER_PWM_MODE_SHIFT)))

#define SPEAKER_PWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(SPEAKER_PWM_PWM_RUN_MODE         << SPEAKER_PWM_ONESHOT_SHIFT))
            
#define SPEAKER_PWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(SPEAKER_PWM_PWM_ALIGN            << SPEAKER_PWM_UPDOWN_SHIFT))

#define SPEAKER_PWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(SPEAKER_PWM_PWM_KILL_EVENT      << SPEAKER_PWM_PWM_SYNC_KILL_SHIFT))

#define SPEAKER_PWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(SPEAKER_PWM_PWM_DEAD_TIME_CYCLE  << SPEAKER_PWM_PRESCALER_SHIFT))

#define SPEAKER_PWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(SPEAKER_PWM_PWM_PRESCALER        << SPEAKER_PWM_PRESCALER_SHIFT))

#define SPEAKER_PWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(SPEAKER_PWM_TC_PRESCALER            << SPEAKER_PWM_PRESCALER_SHIFT))       |\
         ((uint32)(SPEAKER_PWM_TC_COUNTER_MODE         << SPEAKER_PWM_UPDOWN_SHIFT))          |\
         ((uint32)(SPEAKER_PWM_TC_RUN_MODE             << SPEAKER_PWM_ONESHOT_SHIFT))         |\
         ((uint32)(SPEAKER_PWM_TC_COMP_CAP_MODE        << SPEAKER_PWM_MODE_SHIFT)))
        
#define SPEAKER_PWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(SPEAKER_PWM_QUAD_PHIA_SIGNAL_MODE   << SPEAKER_PWM_COUNT_SHIFT))           |\
         ((uint32)(SPEAKER_PWM_QUAD_INDEX_SIGNAL_MODE  << SPEAKER_PWM_RELOAD_SHIFT))          |\
         ((uint32)(SPEAKER_PWM_QUAD_STOP_SIGNAL_MODE   << SPEAKER_PWM_STOP_SHIFT))            |\
         ((uint32)(SPEAKER_PWM_QUAD_PHIB_SIGNAL_MODE   << SPEAKER_PWM_START_SHIFT)))

#define SPEAKER_PWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(SPEAKER_PWM_PWM_SWITCH_SIGNAL_MODE  << SPEAKER_PWM_CAPTURE_SHIFT))         |\
         ((uint32)(SPEAKER_PWM_PWM_COUNT_SIGNAL_MODE   << SPEAKER_PWM_COUNT_SHIFT))           |\
         ((uint32)(SPEAKER_PWM_PWM_RELOAD_SIGNAL_MODE  << SPEAKER_PWM_RELOAD_SHIFT))          |\
         ((uint32)(SPEAKER_PWM_PWM_STOP_SIGNAL_MODE    << SPEAKER_PWM_STOP_SHIFT))            |\
         ((uint32)(SPEAKER_PWM_PWM_START_SIGNAL_MODE   << SPEAKER_PWM_START_SHIFT)))

#define SPEAKER_PWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(SPEAKER_PWM_TC_CAPTURE_SIGNAL_MODE  << SPEAKER_PWM_CAPTURE_SHIFT))         |\
         ((uint32)(SPEAKER_PWM_TC_COUNT_SIGNAL_MODE    << SPEAKER_PWM_COUNT_SHIFT))           |\
         ((uint32)(SPEAKER_PWM_TC_RELOAD_SIGNAL_MODE   << SPEAKER_PWM_RELOAD_SHIFT))          |\
         ((uint32)(SPEAKER_PWM_TC_STOP_SIGNAL_MODE     << SPEAKER_PWM_STOP_SHIFT))            |\
         ((uint32)(SPEAKER_PWM_TC_START_SIGNAL_MODE    << SPEAKER_PWM_START_SHIFT)))
        
#define SPEAKER_PWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((SPEAKER_PWM__COUNT_UPDOWN0 == SPEAKER_PWM_TC_COUNTER_MODE)                  ||\
                 (SPEAKER_PWM__COUNT_UPDOWN1 == SPEAKER_PWM_TC_COUNTER_MODE))

#define SPEAKER_PWM_PWM_UPDOWN_CNT_USED                                                            \
                ((SPEAKER_PWM__CENTER == SPEAKER_PWM_PWM_ALIGN)                               ||\
                 (SPEAKER_PWM__ASYMMETRIC == SPEAKER_PWM_PWM_ALIGN))               
        
#define SPEAKER_PWM_PWM_PR_INIT_VALUE              (1u)
#define SPEAKER_PWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_SPEAKER_PWM_H */

/* [] END OF FILE */
