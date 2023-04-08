<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
=======
<<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/Generated_Source/PSoC4/ENC_ISR.c
========
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
>>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
/*******************************************************************************
* File Name: ENC_ISR.c  
* Version 1.70
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
#include <ENC_ISR.h>
#include "cyapicallbacks.h"

#if !defined(ENC_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ENC_ISR_intc` */
#include "ENC.h"
// Take variables from global space (main.c)
extern volatile int encoderAsync;
extern volatile int encoderPos;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ENC_ISR_Start
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
void ENC_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the ENC_ISR Interrupt. */
    ENC_ISR_SetVector(&ENC_ISR_Interrupt);

    /* Set the priority. */
    ENC_ISR_SetPriority((uint8)ENC_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ENC_ISR_Enable();
}


/*******************************************************************************
* Function Name: ENC_ISR_StartEx
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
void ENC_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the ENC_ISR Interrupt. */
    ENC_ISR_SetVector(address);

    /* Set the priority. */
    ENC_ISR_SetPriority((uint8)ENC_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ENC_ISR_Enable();
}


/*******************************************************************************
* Function Name: ENC_ISR_Stop
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
void ENC_ISR_Stop(void)
{
    /* Disable this interrupt. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    ENC_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ENC_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ENC_ISR.
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
CY_ISR(ENC_ISR_Interrupt)
{
    #ifdef ENC_ISR_INTERRUPT_INTERRUPT_CALLBACK
        ENC_ISR_Interrupt_InterruptCallback();
    #endif /* ENC_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START ENC_ISR_Interrupt` */
    // Read the first variable, then wait for it to change
    volatile int a  = ENC_Read();
    while(a == ENC_Read());
    // Read next variable, then wait for it to change
    volatile int b  = ENC_Read();
    while(b == ENC_Read());
    // Read next variable, then wait for it to change
    volatile int c  = ENC_Read();
    while(c == ENC_Read());
    // Based on the following variables, decide whether it is CW or CCW
    if(a == 1 && c == 2){
        // Clockwise (increase bar)
        // Set flag
        encoderAsync = 1;
        // Set limit of 80 on the right side
        if(encoderPos == 80){}
        // If not at limit, increase position
        else{
            encoderPos++;
        }
    }
    else if(a == 2 && c==1){
        // Counter-Clockwise (decrease bar)
        // Set flag
        encoderAsync = 1;
        // Set limit of 0 on the left side
        if(encoderPos == 0){}
        // If not at limit, decrease position
        else{
            encoderPos--;
        }
    }
    // Clear interrupt
    ENC_ClearInterrupt();   
    /* `#END` */
}


/*******************************************************************************
* Function Name: ENC_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ENC_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ENC_ISR_StartEx instead.
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
void ENC_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ENC_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ENC_ISR_GetVector
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
cyisraddress ENC_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ENC_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ENC_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling ENC_ISR_Start or ENC_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after ENC_ISR_Start or ENC_ISR_StartEx has been called. 
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
void ENC_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ENC_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ENC_ISR_INTC_PRIOR = (*ENC_ISR_INTC_PRIOR & (uint32)(~ENC_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ENC_ISR_GetPriority
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
uint8 ENC_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ENC_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ENC_ISR_INTC_PRIOR & ENC_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ENC_ISR_Enable
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
void ENC_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *ENC_ISR_INTC_SET_EN = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_GetState
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
uint8 ENC_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ENC_ISR_INTC_SET_EN & (uint32)ENC_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ENC_ISR_Disable
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
void ENC_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *ENC_ISR_INTC_CLR_EN = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_SetPending
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
void ENC_ISR_SetPending(void)
{
    *ENC_ISR_INTC_SET_PD = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_ClearPending
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
void ENC_ISR_ClearPending(void)
{
    *ENC_ISR_INTC_CLR_PD = ENC_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
<<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/Generated_Source/PSoC4/ENC_ISR.c
========
=======
>>>>>>> e23e5a7dadfbff1500a361091d478f7823854aed:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/Generated_Source/PSoC4/ENC_ISR.c
/*******************************************************************************
* File Name: ENC_ISR.c  
* Version 1.70
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
#include <ENC_ISR.h>
#include "cyapicallbacks.h"

#if !defined(ENC_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ENC_ISR_intc` */
    
#include "ENC.h"
#include "LCD.h"
extern volatile int encoderAsync;
extern volatile int encoderPos;
   
    
    
    
    
    

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ENC_ISR_Start
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
void ENC_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the ENC_ISR Interrupt. */
    ENC_ISR_SetVector(&ENC_ISR_Interrupt);

    /* Set the priority. */
    ENC_ISR_SetPriority((uint8)ENC_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ENC_ISR_Enable();
}


/*******************************************************************************
* Function Name: ENC_ISR_StartEx
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
void ENC_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the ENC_ISR Interrupt. */
    ENC_ISR_SetVector(address);

    /* Set the priority. */
    ENC_ISR_SetPriority((uint8)ENC_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ENC_ISR_Enable();
}


/*******************************************************************************
* Function Name: ENC_ISR_Stop
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
void ENC_ISR_Stop(void)
{
    /* Disable this interrupt. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    ENC_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ENC_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ENC_ISR.
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
CY_ISR(ENC_ISR_Interrupt)
{
    #ifdef ENC_ISR_INTERRUPT_INTERRUPT_CALLBACK
        ENC_ISR_Interrupt_InterruptCallback();
    #endif /* ENC_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START ENC_ISR_Interrupt` */
    
volatile int a  = ENC_Read();
while(a == ENC_Read());
volatile int b  = ENC_Read();
while(b == ENC_Read());
volatile int c  = ENC_Read();
while(c == ENC_Read());
//CyDelay(20);
if(a == 1 && c == 2){
    // Clockwise (increase bar)
    encoderAsync = 1;
    if(encoderPos == 80){
    }
    else{
        encoderPos++;
    }
}
else if(a == 2 && c==1){
    // Counter-Clockwise (decrease bar)
    encoderAsync = 1;
    if(encoderPos == 0){
    }
    else{
        encoderPos--;
    }
}
ENC_ClearInterrupt();   

    
    
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: ENC_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ENC_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ENC_ISR_StartEx instead.
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
void ENC_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ENC_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ENC_ISR_GetVector
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
cyisraddress ENC_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ENC_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ENC_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling ENC_ISR_Start or ENC_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after ENC_ISR_Start or ENC_ISR_StartEx has been called. 
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
void ENC_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ENC_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ENC_ISR_INTC_PRIOR = (*ENC_ISR_INTC_PRIOR & (uint32)(~ENC_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ENC_ISR_GetPriority
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
uint8 ENC_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ENC_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ENC_ISR_INTC_PRIOR & ENC_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ENC_ISR_Enable
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
void ENC_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *ENC_ISR_INTC_SET_EN = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_GetState
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
uint8 ENC_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ENC_ISR_INTC_SET_EN & (uint32)ENC_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ENC_ISR_Disable
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
void ENC_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *ENC_ISR_INTC_CLR_EN = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_SetPending
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
void ENC_ISR_SetPending(void)
{
    *ENC_ISR_INTC_SET_PD = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_ClearPending
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
void ENC_ISR_ClearPending(void)
{
    *ENC_ISR_INTC_CLR_PD = ENC_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
<<<<<<< HEAD:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
=======
/*******************************************************************************
* File Name: ENC_ISR.c  
* Version 1.70
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
#include <ENC_ISR.h>
#include "cyapicallbacks.h"

#if !defined(ENC_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ENC_ISR_intc` */
#include "ENC.h"
// Take variables from global space (main.c)
extern volatile int encoderAsync;
extern volatile int encoderPos;
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ENC_ISR_Start
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
void ENC_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the ENC_ISR Interrupt. */
    ENC_ISR_SetVector(&ENC_ISR_Interrupt);

    /* Set the priority. */
    ENC_ISR_SetPriority((uint8)ENC_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ENC_ISR_Enable();
}


/*******************************************************************************
* Function Name: ENC_ISR_StartEx
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
void ENC_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the ENC_ISR Interrupt. */
    ENC_ISR_SetVector(address);

    /* Set the priority. */
    ENC_ISR_SetPriority((uint8)ENC_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ENC_ISR_Enable();
}


/*******************************************************************************
* Function Name: ENC_ISR_Stop
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
void ENC_ISR_Stop(void)
{
    /* Disable this interrupt. */
    ENC_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    ENC_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ENC_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ENC_ISR.
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
CY_ISR(ENC_ISR_Interrupt)
{
    #ifdef ENC_ISR_INTERRUPT_INTERRUPT_CALLBACK
        ENC_ISR_Interrupt_InterruptCallback();
    #endif /* ENC_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START ENC_ISR_Interrupt` */
    // Read the first variable, then wait for it to change
    volatile int a  = ENC_Read();
    while(a == ENC_Read());
    // Read next variable, then wait for it to change
    volatile int b  = ENC_Read();
    while(b == ENC_Read());
    // Read next variable, then wait for it to change
    volatile int c  = ENC_Read();
    while(c == ENC_Read());
    // Based on the following variables, decide whether it is CW or CCW
    if(a == 1 && c == 2){
        // Clockwise (increase bar)
        // Set flag
        encoderAsync = 1;
        // Set limit of 80 on the right side
        if(encoderPos == 80){}
        // If not at limit, increase position
        else{
            encoderPos++;
        }
    }
    else if(a == 2 && c==1){
        // Counter-Clockwise (decrease bar)
        // Set flag
        encoderAsync = 1;
        // Set limit of 0 on the left side
        if(encoderPos == 0){}
        // If not at limit, decrease position
        else{
            encoderPos--;
        }
    }
    // Clear interrupt
    ENC_ClearInterrupt();   
    /* `#END` */
}


/*******************************************************************************
* Function Name: ENC_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ENC_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ENC_ISR_StartEx instead.
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
void ENC_ISR_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ENC_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ENC_ISR_GetVector
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
cyisraddress ENC_ISR_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ENC_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ENC_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling ENC_ISR_Start or ENC_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after ENC_ISR_Start or ENC_ISR_StartEx has been called. 
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
void ENC_ISR_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ENC_ISR__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ENC_ISR_INTC_PRIOR = (*ENC_ISR_INTC_PRIOR & (uint32)(~ENC_ISR__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ENC_ISR_GetPriority
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
uint8 ENC_ISR_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ENC_ISR__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ENC_ISR_INTC_PRIOR & ENC_ISR__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ENC_ISR_Enable
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
void ENC_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *ENC_ISR_INTC_SET_EN = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_GetState
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
uint8 ENC_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ENC_ISR_INTC_SET_EN & (uint32)ENC_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ENC_ISR_Disable
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
void ENC_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *ENC_ISR_INTC_CLR_EN = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_SetPending
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
void ENC_ISR_SetPending(void)
{
    *ENC_ISR_INTC_SET_PD = ENC_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: ENC_ISR_ClearPending
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
void ENC_ISR_ClearPending(void)
{
    *ENC_ISR_INTC_CLR_PD = ENC_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
>>>>>>> 8381928c4384acfcb7526ab7a6dd2d315e643534:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
=======
>>>>>>> e6b66f492be45cb54e7efb6d0f687a534db08ab8:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
>>>>>>>> d64eda67b547499d1a0cb642e2e449ca8147df5e:Lab 2 - Interrupts/Project/Code Turn in - Leo and Caleb/Lab02 - Interrupts.cydsn/codegentemp/ENC_ISR.c
>>>>>>> e23e5a7dadfbff1500a361091d478f7823854aed:Lab 2 - Interrupts/Project/Lab02 - Interrupts.cydsn/Generated_Source/PSoC4/ENC_ISR.c