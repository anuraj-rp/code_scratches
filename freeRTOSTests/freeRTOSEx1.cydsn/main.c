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
#include "timers.h"


extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);
extern void vPortSVCHandler(void);
#define CORTEX_INTERRUPT_BASE          (16)



void setupFreeRTOS()
{
    /* Handler for Cortex Supervisor Call (SVC, formerly SWI) - address 11 */
    CyIntSetSysVector( CORTEX_INTERRUPT_BASE + SVCall_IRQn,
        (cyisraddress)vPortSVCHandler );
    
    /* Handler for Cortex PendSV Call - address 14 */
	CyIntSetSysVector( CORTEX_INTERRUPT_BASE + PendSV_IRQn,
        (cyisraddress)xPortPendSVHandler );    
    
    /* Handler for Cortex SYSTICK - address 15 */
	CyIntSetSysVector( CORTEX_INTERRUPT_BASE + SysTick_IRQn,
        (cyisraddress)xPortSysTickHandler );
}


void LED_Task(void *arg)
{
    (void)arg;
    
	while(1) {
        UART_UartPutString("RED\n");
        LED_RED_Write(0);
        LED_GREEN_Write(1);
        LED_BLUE_Write(1);
        vTaskDelay(500);
        UART_UartPutString("GREEN\n");
        LED_RED_Write(1);
        LED_GREEN_Write(0);
        LED_BLUE_Write(1);
        vTaskDelay(500);
        UART_UartPutString("BLUE\n");
        LED_RED_Write(1);
        LED_GREEN_Write(1);
        LED_BLUE_Write(0);
        vTaskDelay(500);
	}
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    setupFreeRTOS();
  
    UART_Start();
    /* Create LED task, which will blink the RED LED */
    xTaskCreate(
        LED_Task,       /* Task function */
        "LED Blink",    /* Task name (string) */
        200,            /* Task stack, allocated from heap */
        0,              /* No param passed to task function */
        1,              /* Low priority */
        0 );            /* Not using the task handle */
     

    
    vTaskStartScheduler();
    while(1); // get rid of the stupid warning
}
/* [] END OF FILE */
