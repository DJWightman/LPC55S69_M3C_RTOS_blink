/*
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    LPC55S69_M3C.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"


/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)
#define led_task_PRIORITY (configMAX_PRIORITIES - 1)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void hello_task(void *pvParameters);
static void led_task(void *pvParameters);
/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World, I'm Main   \n");

    if (xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE + 100, NULL, hello_task_PRIORITY, NULL) !=
            pdPASS)
        {
            PRINTF("Task creation failed!.\r\n");
            while (1)
                ;
        }

    if (xTaskCreate(led_task, "LED_task", configMINIMAL_STACK_SIZE + 100, NULL, led_task_PRIORITY, NULL) !=
                pdPASS)
            {
                PRINTF("Task creation failed!.\r\n");
                while (1)
                    ;
            }

    vTaskStartScheduler();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void hello_task(void *pvParameters)
{
	PRINTF("Hello world, I'm hello task\r\n");

	uint8_t i = 99;
    for (;;)
    {
    	PRINTF("%u bottles of beer on the wall\r\n", i);
    	if (i==0)
    		i = 99;
    	else
    		i--;
    	vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

/*!
 * @brief Task responsible for blinking LED
 */
static void led_task(void *pvParameters)
{
	uint8_t led_port = 0;
	uint8_t led_pin = 18;

    for (;;)
    {

    	GPIO_PortSet(GPIO, led_port, (1U << led_pin));

        vTaskDelay(pdMS_TO_TICKS(200));

        GPIO_PortClear(GPIO, led_port, (1U << led_pin));

        vTaskDelay(pdMS_TO_TICKS(1300));
    }
}
