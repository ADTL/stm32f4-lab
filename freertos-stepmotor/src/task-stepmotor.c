#include "main.h"
#include "leds.h"
#include "usart.h"

#include "task-stepmotor.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

// Based on code written by Andrew Markham.

xTaskHandle task_stepmotor_handle;
xQueueHandle *_p_queue_stepmotor;

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;

// 50 Hz
#define MAX_PERIOD 1680

void task_stepmotor_send_dutycycle(int value)
{
	if (_p_queue_stepmotor)
		xQueueSendToBack(*_p_queue_stepmotor, &value, 0);
}

void task_stepmotor(void* param)
{
	(void)param;

	int value = 0;

	while (1)
	{
		if (pdPASS == xQueueReceive(
				*_p_queue_stepmotor,
				&value,
				portMAX_DELAY))
		{
			if (value > 100)
				value = 100; // TODO add error

			// after 216 it gets weird
			// below 48 too.

			int dutycycle = 48 + (value * (207-48) / 100);
			TIM3->CCR1 = dutycycle;

			static char buffer[25];
			sprintf (buffer, "Setting dutycycle to = %d/1680\r\n", value);
			usart1_write_string(buffer);
		}
	}

	ledlib_set_error_state();

	vTaskDelete(task_stepmotor_handle);
}




void TIM_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // TIM3 clock enable
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  // GPIOC Configuration: TIM3 CH1 (PC6)
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // Connect TIM3 pins to AF2
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
}

void PWM_Config(int period)
{
  uint16_t PrescalerValue = 0;

  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Prescaler = 1000 - 1; // 84 MHz to 84 kHz
  TIM_TimeBaseStructure.TIM_Period = period - 1; // 84 kHz to 50 Hz
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC1Init(TIM3, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM3, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);
}

void task_stepmotor_init(xQueueHandle *p_queue_stepmotor)
{
	_p_queue_stepmotor = p_queue_stepmotor;

	TIM_Config();
	PWM_Config(MAX_PERIOD); // 1680 for 50 Hz, 20 ms period PWM

	TIM3->CCR1 = 46; // minimum

    xTaskCreate(task_stepmotor, (signed char*)"task-stepmotor", configMINIMAL_STACK_SIZE, 0, tskIDLE_PRIORITY, &task_stepmotor_handle);
}
