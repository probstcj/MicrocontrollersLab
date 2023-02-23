<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Design01.cydsn/codegentemp/INPUT_TIMER_ISR.c
=======
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/INPUT_TIMER_ISR.c
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
=======
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/INPUT_TIMER_ISR.c
=======
<<<<<<< HEAD:Lab 3 - Simon Game/Project/Design01.cydsn/codegentemp/INPUT_TIMER_ISR.c
>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
/*******************************************************************************
* File Name: INPUT_TIMER_ISR.c  
* Version 1.71
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <INPUT_TIMER_ISR.h>
#include "cyapicallbacks.h"

#if !defined(INPUT_TIMER_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START INPUT_TIMER_ISR_intc` */
#include "INPUT_TIMER.h"

extern volatile int timeout;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(&INPUT_TIMER_ISR_Interrupt);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(address);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Stop(void)
{
    /* Disable this interrupt. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    INPUT_TIMER_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for INPUT_TIMER_ISR.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(INPUT_TIMER_ISR_Interrupt)
{
    #ifdef INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK
        INPUT_TIMER_ISR_Interrupt_InterruptCallback();
    #endif /* INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START INPUT_TIMER_ISR_Interrupt` */
INPUT_TIMER_ClearInterrupt(INPUT_TIMER_TC_INTERRUPT_MASK);
timeout = 1;
    
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling INPUT_TIMER_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use INPUT_TIMER_ISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress INPUT_TIMER_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *INPUT_TIMER_ISR_INTC_PRIOR = (*INPUT_TIMER_ISR_INTC_PRIOR & (uint32)(~(uint32)INPUT_TIMER_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*INPUT_TIMER_ISR_INTC_PRIOR & INPUT_TIMER_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_SET_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*INPUT_TIMER_ISR_INTC_SET_EN & (uint32)INPUT_TIMER_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_CLR_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPending(void)
{
    *INPUT_TIMER_ISR_INTC_SET_PD = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_ClearPending(void)
{
    *INPUT_TIMER_ISR_INTC_CLR_PD = INPUT_TIMER_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
/*******************************************************************************
* File Name: INPUT_TIMER_ISR.c  
* Version 1.71
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <INPUT_TIMER_ISR.h>
#include "cyapicallbacks.h"

#if !defined(INPUT_TIMER_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START INPUT_TIMER_ISR_intc` */
#include "INPUT_TIMER.h"

extern volatile int timeout;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(&INPUT_TIMER_ISR_Interrupt);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(address);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Stop(void)
{
    /* Disable this interrupt. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    INPUT_TIMER_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for INPUT_TIMER_ISR.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(INPUT_TIMER_ISR_Interrupt)
{
    #ifdef INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK
        INPUT_TIMER_ISR_Interrupt_InterruptCallback();
    #endif /* INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START INPUT_TIMER_ISR_Interrupt` */
INPUT_TIMER_ClearInterrupt(INPUT_TIMER_TC_INTERRUPT_MASK);
timeout = 1;
    
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling INPUT_TIMER_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use INPUT_TIMER_ISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress INPUT_TIMER_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *INPUT_TIMER_ISR_INTC_PRIOR = (*INPUT_TIMER_ISR_INTC_PRIOR & (uint32)(~(uint32)INPUT_TIMER_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*INPUT_TIMER_ISR_INTC_PRIOR & INPUT_TIMER_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_SET_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*INPUT_TIMER_ISR_INTC_SET_EN & (uint32)INPUT_TIMER_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_CLR_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPending(void)
{
    *INPUT_TIMER_ISR_INTC_SET_PD = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_ClearPending(void)
{
    *INPUT_TIMER_ISR_INTC_CLR_PD = INPUT_TIMER_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 3 - Simon Game/Project/Design01.cydsn/codegentemp/INPUT_TIMER_ISR.c
=======
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
/*******************************************************************************
* File Name: INPUT_TIMER_ISR.c  
* Version 1.71
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <INPUT_TIMER_ISR.h>
#include "cyapicallbacks.h"

#if !defined(INPUT_TIMER_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START INPUT_TIMER_ISR_intc` */
#include "INPUT_TIMER.h"

extern volatile int timeout;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(&INPUT_TIMER_ISR_Interrupt);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(address);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Stop(void)
{
    /* Disable this interrupt. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    INPUT_TIMER_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for INPUT_TIMER_ISR.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(INPUT_TIMER_ISR_Interrupt)
{
    #ifdef INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK
        INPUT_TIMER_ISR_Interrupt_InterruptCallback();
    #endif /* INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START INPUT_TIMER_ISR_Interrupt` */
INPUT_TIMER_ClearInterrupt(INPUT_TIMER_TC_INTERRUPT_MASK);
timeout = 1;
    
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling INPUT_TIMER_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use INPUT_TIMER_ISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress INPUT_TIMER_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *INPUT_TIMER_ISR_INTC_PRIOR = (*INPUT_TIMER_ISR_INTC_PRIOR & (uint32)(~(uint32)INPUT_TIMER_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*INPUT_TIMER_ISR_INTC_PRIOR & INPUT_TIMER_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_SET_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*INPUT_TIMER_ISR_INTC_SET_EN & (uint32)INPUT_TIMER_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_CLR_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPending(void)
{
    *INPUT_TIMER_ISR_INTC_SET_PD = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_ClearPending(void)
{
    *INPUT_TIMER_ISR_INTC_CLR_PD = INPUT_TIMER_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 3 - Simon Game/Project/Backup/ECE381_SP23_Lab03_Simon_Clone.4.4/Project/Design01.cydsn/Generated_Source/PSoC4/INPUT_TIMER_ISR.c
<<<<<<< HEAD
=======
/*******************************************************************************
* File Name: INPUT_TIMER_ISR.c  
* Version 1.71
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <INPUT_TIMER_ISR.h>
#include "cyapicallbacks.h"

#if !defined(INPUT_TIMER_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START INPUT_TIMER_ISR_intc` */
#include "INPUT_TIMER.h"

extern volatile int timeout;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(&INPUT_TIMER_ISR_Interrupt);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the INPUT_TIMER_ISR Interrupt. */
    INPUT_TIMER_ISR_SetVector(address);

    /* Set the priority. */
    INPUT_TIMER_ISR_SetPriority((uint8)INPUT_TIMER_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    INPUT_TIMER_ISR_Enable();
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Stop(void)
{
    /* Disable this interrupt. */
    INPUT_TIMER_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    INPUT_TIMER_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for INPUT_TIMER_ISR.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(INPUT_TIMER_ISR_Interrupt)
{
    #ifdef INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK
        INPUT_TIMER_ISR_Interrupt_InterruptCallback();
    #endif /* INPUT_TIMER_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START INPUT_TIMER_ISR_Interrupt` */
INPUT_TIMER_ClearInterrupt(INPUT_TIMER_TC_INTERRUPT_MASK);
timeout = 1;
    
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling INPUT_TIMER_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use INPUT_TIMER_ISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress INPUT_TIMER_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + INPUT_TIMER_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after INPUT_TIMER_ISR_Start or INPUT_TIMER_ISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *INPUT_TIMER_ISR_INTC_PRIOR = (*INPUT_TIMER_ISR_INTC_PRIOR & (uint32)(~(uint32)INPUT_TIMER_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((INPUT_TIMER_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*INPUT_TIMER_ISR_INTC_PRIOR & INPUT_TIMER_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_SET_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 INPUT_TIMER_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*INPUT_TIMER_ISR_INTC_SET_EN & (uint32)INPUT_TIMER_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *INPUT_TIMER_ISR_INTC_CLR_EN = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void INPUT_TIMER_ISR_SetPending(void)
{
    *INPUT_TIMER_ISR_INTC_SET_PD = INPUT_TIMER_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: INPUT_TIMER_ISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void INPUT_TIMER_ISR_ClearPending(void)
{
    *INPUT_TIMER_ISR_INTC_CLR_PD = INPUT_TIMER_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 3 - Simon Game/Project/Design01.cydsn/codegentemp/INPUT_TIMER_ISR.c
>>>>>>> 6306daa794c58f4c1cf0d730fde6cee6858903a2
=======
>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e
>>>>>>> b6af373156fbbfd3c8de315656f7bc6d715107fc
