#include "main.h"
#include "usart.h"
#include "leds.h"
#include "task-lua.h"
#include "task-stepmotor.h"

#include <stdlib.h>


xQueueHandle queue_uart_char;
xQueueHandle queue_lua_commands;
xQueueHandle queue_stepmotor;

void task_receive_uart_chars(void* param)
{
//	(void)param;
//
	char t;

	uint8_t cnt = 0; // this counter is used to determine the string length
	char received_string[MAX_STRLEN+1]; // this will hold the received string

	while (1)
	{
		if (pdPASS == xQueueReceive(
				queue_uart_char,
				&t,
				portMAX_DELAY))
		{
			/* check if the received character is not the LF character (used to determine end of string)
			 * or the if the maximum string length has been been reached
			 */
			if( (t != '\r') && (cnt < MAX_STRLEN) )
			{
				ledlib_flash_blue_led();

				received_string[cnt] = t;
				received_string[cnt+1] = '\0';

				cnt++;
			}
			else
			{ // otherwise reset the character counter and print the received string
				cnt = 0;

				ledlib_flash_orange_led();

				xQueueSendToBack(queue_lua_commands, received_string, 0);
			}

			usart1_write_char(t);
			if (t == '\r')
				usart1_write_char('\n');
		}
	}
}

void vApplicationStackOverflowHook( xTaskHandle xTask, signed char *pcTaskName )
{
	ledlib_set_error_state();
}

int main()
{
	// create the UART queue
	queue_uart_char = xQueueGenericCreate(5, 10, 0);
	queue_lua_commands = xQueueGenericCreate(5, MAX_STRLEN + 1, 0);
	queue_stepmotor = xQueueGenericCreate(5, sizeof(int), 0);

	ledlib_init();
	usart1_init(9600, &queue_uart_char);
	task_lua_init(&queue_lua_commands);
	task_stepmotor_init(&queue_stepmotor);

	// just send a message to indicate that it worksa
	usart1_write_string ("\r\nInit complete with motors\r\n");

    xTaskCreate(task_receive_uart_chars, (signed char*)"uart-chars", 100, 0, 1, 0);

    vTaskStartScheduler();

    /*
     * Should never reach here!
     */
    ledlib_set_error_state();
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{
	/*
	 * User can add his own implementation to report the file name and line number,
	 * ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line)
	 */
	usart1_write_string ("\r\nERROR\r\n");

	while (1)
	{

	}
}
#endif
