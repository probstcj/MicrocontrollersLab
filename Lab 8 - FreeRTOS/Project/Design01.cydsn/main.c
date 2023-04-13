/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

// FreeRTOS Variables
SemaphoreHandle_t adc_mutex;
TaskHandle_t blink_task, lcd_task, motor_task;

// Other Globals
volatile int16 adcDV;

// This task should blink the RED LED at
// a rate of 2Hz
void vBlinkTaskRed(void *pvParameters)
{
    while(1) {
        
    }
    
}

// Print the temperature in F and C
// to the LCD once per second.
// Whole number temps are fine so 
// you can use LCD_PrintNumber() instead of snprintf()
void vUpdateLCDTask(void *pvParameters)
{
    int16 adcDV_local;
    
    while(1) {
        if (xSemaphoreTake(adc_mutex, 0) == pdTRUE)
        {
            adcDV_local = adcDV;
            
            xSemaphoreGive(adc_mutex);
        }
        else
        {
            
        }
        
    }
    
}

// Spin the motor at a rate of 2ms per step
void vSpinMotorTask(void *pvParameters)
{
    while(1) {
        
    }
    
}

void prvHardwareSetup();

int main(void)
{
    
    adc_mutex = xSemaphoreCreateMutex();
    
    xTaskCreate(vBlinkTaskRed, (portCHAR *) "BlinkRed",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, &blink_task);
    xTaskCreate(vUpdateLCDTask, (portCHAR *) "UpdateLCD",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3, &lcd_task);
    xTaskCreate(vSpinMotorTask, (portCHAR *) "SpinMotor",configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 4, &motor_task);
    
    prvHardwareSetup(); //Set up FreeRTOS for our hardware    
    
    // Start our modules and ISRs
    SW_ISR_Start();
    ADC_Start();
    ADC_StartConvert();
    ADC_ISR_Start();    
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    vTaskStartScheduler();

    for(;;)
    {
        /* WE SHOULD NEVER GET HERE! THE SCHEDULER TAKES OVER! */
    }
        
    
}

void prvHardwareSetup( void )
{
	/* Port layer functions that need to be copied into the vector table. */
	extern void xPortPendSVHandler( void );
	extern void xPortSysTickHandler( void );
	extern void vPortSVCHandler( void );
	extern cyisraddress CyRamVectors[];

	/* Install the OS Interrupt Handlers. */
	CyRamVectors[ 11 ] = ( cyisraddress ) vPortSVCHandler;
	CyRamVectors[ 14 ] = ( cyisraddress ) xPortPendSVHandler;
	CyRamVectors[ 15 ] = ( cyisraddress ) xPortSysTickHandler;
   
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	/* The stack space has been execeeded for a task, considering allocating more. */
	taskDISABLE_INTERRUPTS();
    
	for( ;; );
}

void vApplicationMallocFailedHook( void )
{
	/* The heap space has been execeeded. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}


/* [] END OF FILE */
