#include "main.h"

extern int bin_size;
extern char* bin_data;

////void INTTIM_Config()
////{
////    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
////
////    // SystemCoreClock is 168M
////
////    //    TIM_TimeBaseStructure.TIM_Prescaler = 84-1; // 24 MHz clock down to 1 MHz
////    //    TIM_TimeBaseStructure.TIM_Period = 100 - 1; // 1 MHz down to 10 KHz (.1 ms)
////
//////    TIM_TimeBaseStructure.TIM_Prescaler = 4200 -1;
//////    TIM_TimeBaseStructure.TIM_Period = 10000 - 2;
////
////    /*
////     * We want 50 Hz
////     */
////    TIM_TimeBaseStructure.TIM_Prescaler = 168 - 1; // down to 1 MHz
////    TIM_TimeBaseStructure.TIM_Period = 1000000; // down to 1 Hz
////
////    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
////    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
////
////    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
////
////    TIM_Cmd (TIM2, ENABLE);
////}
//
//// 0:ff going
//
//int main()
//{
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC | RCC_APB1Periph_TIM2, ENABLE);
//
//	TIM_TimeBaseInitTypeDef tim_base_structure;
//
//	/* Time base configuration */
//	TIM_TimeBaseStructInit(&tim_base_structure);
////	tim_base_structure.TIM_Prescaler = 10 - 1; // // 84 MHz to 8400 kHz
////	tim_base_structure.TIM_Period = 381 - 1; // 8400 kHz to 22 kHz
//
//		tim_base_structure.TIM_Prescaler = 10000 - 1; // // 84 MHz to 8.4 kHz
//		tim_base_structure.TIM_Period = 10000 - 1; // 8.4 kHz to 0.8 Hz
//
//	tim_base_structure.TIM_ClockDivision = 0;
//	tim_base_structure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM2, &tim_base_structure);
//
//	//  /* TIM2 TRGO selection */
//	//  TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);
//
//	/* TIM2 enable counter */
//	TIM_Cmd(TIM2, ENABLE);
//
//
//
//
//	GPIO_InitTypeDef gpio_init_structure;
//
///* Configure PA.04/05 (DAC) as output -------------------------*/
//	gpio_init_structure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
//	gpio_init_structure.GPIO_Mode = GPIO_Mode_OUT;
//	gpio_init_structure.GPIO_Speed = GPIO_Speed_50MHz;
////
//
////	gpio_init_structure.GPIO_Mode = GPIO_Mode_OUT;
////	gpio_init_structure.GPIO_OType = GPIO_OType_PP;
////	gpio_init_structure.GPIO_Speed = GPIO_Speed_100MHz;
////	gpio_init_structure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//
//	GPIO_Init(GPIOA, &gpio_init_structure);
//
//	DAC_InitTypeDef dac_init_structure;
//
//	dac_init_structure.DAC_Trigger = DAC_Trigger_None;
//	dac_init_structure.DAC_WaveGeneration = DAC_WaveGeneration_None;
//	dac_init_structure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
//	DAC_Init(DAC_Channel_2, &dac_init_structure);
//
//	/*
//	 * Enable DAC Channel2: Once the DAC channel2 is enabled, PA.05 is
//	 * automatically connected to the DAC converter.
//	 */
//	DAC_Cmd(DAC_Channel_2, ENABLE);
//
//	uint16_t data = 0;
//
//	void * pos = ((void*)(bin_data) + 44);
//	void * end = ((void*)(bin_data) + bin_size);
//
//    while (1)
//    {
//    	// wait for timer
//    	if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) != RESET)
//    	{
//    		TIM_ClearFlag(TIM2, TIM_IT_Update);
//
//    		pos+= sizeof (uint16_t);
//    		if (pos > end)
//    			pos = ((void*)(bin_data)+ 44);
//
//    		uint16_t * p_data = (uint16_t*)pos;
//    		uint16_t data = *p_data;
////    		data /= 256;
//
//    		DAC_SetChannel2Data(DAC_Align_8b_R, data & 0xff);
////    		if (data == 0)
////    			data = 0xff;
////    		else
////    			data = 0;
//    	}
//    }
//
//
//}
//
//
//void WWDG_IRQHandler(void)
//{
//	while (1);
//}
//
//void UsageFault_Handler()
//{
//	while (1);
//}
//
//#ifdef  USE_FULL_ASSERT
//
//void assert_failed(uint8_t* file, uint32_t line)
//{
//	/*
//	 * User can add his own implementation to report the file name and line number,
//	 * ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line)
//	 */
//	usart1_write_string ("\r\nERROR\r\n");
//
//	while (1)
//	{
//
//	}
//}
//#endif

#include <stm32f4xx.h>

void RCC_config(void)
{
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN); // enable the IO port A clock
	SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);   // enable the DAC clock
}

// GPIO setting
void GPIOA_config(void)
{
	SET_BIT(GPIOA->MODER, GPIO_MODER_MODER4);   // PA4 = Analog
}

void DAC_config(void)
{
	SET_BIT(DAC->CR, DAC_CR_EN1);
}

void main(void)
{
	RCC_config();
	GPIOA_config();
	DAC_config();

//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	TIM_TimeBaseInitTypeDef tim_base_structure;
//
//	/* Time base configuration */
//	TIM_TimeBaseStructInit(&tim_base_structure);
//	tim_base_structure.TIM_Prescaler = 10 - 1; // // 84 MHz to 8400 kHz
//	tim_base_structure.TIM_Period = 381 - 1; // 8400 kHz to 22 kHz
//
////	tim_base_structure.TIM_Prescaler = 10000 - 1; // // 84 MHz to 8.4 kHz
////	tim_base_structure.TIM_Period = 10000 - 1; // 8.4 kHz to 0.8 Hz
//
//	tim_base_structure.TIM_ClockDivision = 0;
//	tim_base_structure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM2, &tim_base_structure);
//
//	//  /* TIM2 TRGO selection */
//	//  TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);
//
//	/* TIM2 enable counter */
//	TIM_Cmd(TIM2, ENABLE);

//	uint16_t data = 0;
//
//	void * pos = ((void*) (bin_data) + 44);
//	void * end = ((void*) (bin_data) + bin_size);

	volatile int timer = 310;

	volatile unsigned short val = 0;

	short int counter = 10000;
	while (1)
	{
//		pos = ((void*) (bin_data) + 44);
		counter = 10000;
		while (counter > 0)
		{
			counter--;

			while (timer > 0)
				timer--;

//			pos += sizeof(uint16_t);

//			uint16_t * p_data = (uint16_t*) pos;
//			uint16_t data = *p_data;
//
//			data++;

			//    		DAC_SetChannel2Data(DAC_Align_8b_R, data & 0xff);

//			int val = data & 0xfff;

			if (val == 0)
				val = 0xfff;
			else
				val = 0;

			DAC ->DHR12R1 = val;
		}
	}
}

//
//    while (1)
//    {
//    	// wait for timer
//    	if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) != RESET)
//    	{
//    		TIM_ClearFlag(TIM2, TIM_IT_Update);
//
////    		if (data == 0)
////    			data = 0xff;
////    		else
////    			data = 0;
//    	}
//    }

