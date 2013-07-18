#include "main.h"

#define LED_STATUS_GREEN 	0
#define LED_STATUS_RED		1

#define GPIO_LED_GREEN  GPIO_Pin_12
#define GPIO_LED_ORANGE GPIO_Pin_13
#define GPIO_LED_RED    GPIO_Pin_14
#define GPIO_LED_BLUE   GPIO_Pin_15

uint8_t flash_blue_counter = 0; // will be used every time UART receives a char
uint8_t flash_orange_counter = 0; // will be used every time UART runs a command
uint8_t status_error =0;

void ledlib_set_error_state()
{
	status_error = 1;
}

void ledlib_flash_blue_led()
{
	flash_blue_counter++;
}

void ledlib_flash_orange_led()
{
	flash_orange_counter++;
}

void task_led_status(void* p)
{
    while(1)
    {
    	if (status_error)
    	{
    		GPIO_ResetBits(GPIOD, GPIO_LED_GREEN); // reset green
    		GPIO_ToggleBits(GPIOD, GPIO_LED_RED); // blink red
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_LED_RED); // reset red
    		GPIO_ToggleBits(GPIOD, GPIO_LED_GREEN); // blink green
    	}

    	if (flash_blue_counter)
    	{
    		GPIO_SetBits(GPIOD, GPIO_LED_BLUE); // set blue for a couple of seconds
    		flash_blue_counter = 0;
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_LED_BLUE); // reset blue
    	}

    	if (flash_orange_counter)
    	{
    		GPIO_SetBits(GPIOD, GPIO_LED_ORANGE); // set orange for a couple of seconds
    		flash_orange_counter = 0;
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_LED_ORANGE); // reset blue
    	}

    	vTaskDelay(250);
    }
}

void ledlib_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOD Periph clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    // start the task flashing the leds
    xTaskCreate(task_led_status, (signed char*)"task-led-status", configMINIMAL_STACK_SIZE, 0, 1, 0);
}
