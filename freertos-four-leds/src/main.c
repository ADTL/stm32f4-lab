#include "freertos.h"
#include "freertosconfig.h"
#include "task.h"

#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"

#define GPIO_LED_GREEN  GPIO_Pin_12
#define GPIO_LED_ORANGE GPIO_Pin_13
#define GPIO_LED_RED    GPIO_Pin_14
#define GPIO_LED_BLUE   GPIO_Pin_15

GPIO_InitTypeDef GPIO_InitStructure;

int led_state =0;

void Delay(__IO uint32_t nCount) {
  while(nCount--) {
  }
}

void led_config(void)
{
    /* GPIOD Periph clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_SetBits(GPIOD, GPIO_LED_GREEN | GPIO_LED_ORANGE | GPIO_LED_RED | GPIO_LED_BLUE);
	//vTaskDelay(1500);
	Delay(3000000);
	GPIO_ResetBits(GPIOD, GPIO_LED_GREEN | GPIO_LED_ORANGE | GPIO_LED_RED | GPIO_LED_BLUE);
}

//12 is green
//13 is orange
//14 is red
//15 is blue

void led_status(void* p)
{
    while(1)
    {
    	if (led_state == 0)
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_14); // reset red
    		GPIO_ToggleBits(GPIOD, GPIO_Pin_12); // blink green
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_12); // reset green
    		GPIO_ToggleBits(GPIOD, GPIO_Pin_14); // blink red
    	}

    	//    	GPIO_ToggleBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    	vTaskDelay(150);
    }
}

int main()
{
    led_config();

    xTaskCreate(led_status, (signed char*)"led-status", configMINIMAL_STACK_SIZE, 0, 1, 0);

    vTaskStartScheduler();

    /*
     * Should never reach here!
     */
    led_state = 1;
    while (1);
}


