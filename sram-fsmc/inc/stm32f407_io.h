/**
  ******************************************************************************
  * @file    stm32f407_io.h
  * @author  Juliano Mayor
  * @version V1.0
  * @date    25-Julho-2013
  * @brief    
  ******************************************************************************
  
// Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F407_IO_H
#define __STM32F407_IO_H


#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @Includes
 */
#include "stm32f4xx.h"
#include "stm32f407_fsmc_sram.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_fsmc.h"
#include "stm32f4xx_syscfg.h"
   
/**
 * @Diretivas de compilação
 */   
#define PLC 1   
   

#if PLC   
typedef enum 
{
  DIN_UC0 = 0,
  DIN_UC1 = 1,
  DIN_UC2 = 2,
  DIN_UC3 = 3,
  DIN_UC4 = 4,
  DIN_UC5 = 5,
  DIN_UC6 = 6,
  DIN_UC7 = 7 
} DIN_UC_TypeDef;

   
typedef enum 
{
  LED1 =        0, 
  LED2 =        1,
  LED3 =        2,
  LED4 =        3,
  LED5 =        4,
  LED6 =        5,
  TX_DATA =     6,
  TX_EN =       7,
  RX_EN =       8,
  DOUT_E0 =     9,
  DOUT_E1 =     10,
  DOUT_E2 =     11,
  DOUT_E3 =     12,
  DOUT_E4 =     13,
  DOUT_E5 =     14,
  DOUT_E6 =     15,
  DOUT_E7 =     16,
  DOUT_E8 =     17,
  DOUT_E9 =     18,
  DOUT_E10 =    19,
  DOUT_E11 =    20,
  BARRA_ON =    21,
  PTT1 =  		22,
  PTT2 = 		23
} Dout_TypeDef;

typedef enum 
{  
  DIN_UC_MODE_GPIO = 0,
  DIN_UC_MODE_EXTI = 1
} DIN_UCMode_TypeDef;

/** @addtogroup STM32F407_IO DIN_UC (DIN0UC_E0...7)
  * @
  */  
#define DIN_UCn                          8 /**/

/**
 * @brief DIN_UC0
 */
#define DIN_UC0_PIN                GPIO_Pin_5
#define DIN_UC0_GPIO_PORT          GPIOH
#define DIN_UC0_GPIO_CLK           RCC_AHB1Periph_GPIOH
#define DIN_UC0_EXTI_LINE          EXTI_Line5
#define DIN_UC0_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOH
#define DIN_UC0_EXTI_PIN_SOURCE    EXTI_PinSource5
#define DIN_UC0_EXTI_IRQn          EXTI0_IRQn 
/**
 * @brief DIN_UC1
 */
#define DIN_UC1_PIN                GPIO_Pin_6
#define DIN_UC1_GPIO_PORT          GPIOH
#define DIN_UC1_GPIO_CLK           RCC_AHB1Periph_GPIOH
#define DIN_UC1_EXTI_LINE          EXTI_Line6
#define DIN_UC1_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOH
#define DIN_UC1_EXTI_PIN_SOURCE    EXTI_PinSource6
#define DIN_UC1_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_UC2
 */
#define DIN_UC2_PIN                GPIO_Pin_9
#define DIN_UC2_GPIO_PORT          GPIOH
#define DIN_UC2_GPIO_CLK           RCC_AHB1Periph_GPIOH
#define DIN_UC2_EXTI_LINE          EXTI_Line9
#define DIN_UC2_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOH
#define DIN_UC2_EXTI_PIN_SOURCE    EXTI_PinSource9
#define DIN_UC2_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_UC3
 */
#define DIN_UC3_PIN                GPIO_Pin_10
#define DIN_UC3_GPIO_PORT          GPIOH
#define DIN_UC3_GPIO_CLK           RCC_AHB1Periph_GPIOH
#define DIN_UC3_EXTI_LINE          EXTI_Line10
#define DIN_UC3_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOH
#define DIN_UC3_EXTI_PIN_SOURCE    EXTI_PinSource10
#define DIN_UC3_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_UC4
 */
#define DIN_UC4_PIN                GPIO_Pin_11
#define DIN_UC4_GPIO_PORT          GPIOH
#define DIN_UC4_GPIO_CLK           RCC_AHB1Periph_GPIOH
#define DIN_UC4_EXTI_LINE          EXTI_Line11
#define DIN_UC4_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOH
#define DIN_UC4_EXTI_PIN_SOURCE    EXTI_PinSource11
#define DIN_UC4_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_UC5
 */
#define DIN_UC5_PIN                GPIO_Pin_12
#define DIN_UC5_GPIO_PORT          GPIOH
#define DIN_UC5_GPIO_CLK           RCC_AHB1Periph_GPIOH
#define DIN_UC5_EXTI_LINE          EXTI_Line12
#define DIN_UC5_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOH
#define DIN_UC5_EXTI_PIN_SOURCE    EXTI_PinSource12
#define DIN_UC5_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_UC6
 */
#define DIN_UC6_PIN                GPIO_Pin_12
#define DIN_UC6_GPIO_PORT          GPIOC
#define DIN_UC6_GPIO_CLK           RCC_AHB1Periph_GPIOC
#define DIN_UC6_EXTI_LINE          EXTI_Line12
#define DIN_UC6_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOC
#define DIN_UC6_EXTI_PIN_SOURCE    EXTI_PinSource12
#define DIN_UC6_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_UC7
 */
#define DIN_UC7_PIN                GPIO_Pin_13
#define DIN_UC7_GPIO_PORT          GPIOC
#define DIN_UC7_GPIO_CLK           RCC_AHB1Periph_GPIOC
#define DIN_UC7_EXTI_LINE          EXTI_Line13
#define DIN_UC7_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOC
#define DIN_UC7_EXTI_PIN_SOURCE    EXTI_PinSource13
#define DIN_UC7_EXTI_IRQn          EXTI0_IRQn

/** @addtogroup STM32F407_IO DIN  (DIN_E0...23)
  * @{
  */  
#define DIN_En                          8 /**/

/**
 * @brief DIN_E0
 */
#define DIN_E0_PIN                GPIO_Pin_14
#define DIN_E0_GPIO_PORT          GPIOD
#define DIN_E0_GPIO_CLK           RCC_AHB1Periph_GPIOD
#define DIN_E0_EXTI_LINE          EXTI_Line14
#define DIN_E0_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOD
#define DIN_E0_EXTI_PIN_SOURCE    EXTI_PinSource14
#define DIN_E0_EXTI_IRQn          EXTI0_IRQn 
/**
 * @brief DIN_E1
 */
#define DIN_E1_PIN                GPIO_Pin_15
#define DIN_E1_GPIO_PORT          GPIOD
#define DIN_E1_GPIO_CLK           RCC_AHB1Periph_GPIOD
#define DIN_E1_EXTI_LINE          EXTI_Line15
#define DIN_E1_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOD
#define DIN_E1_EXTI_PIN_SOURCE    EXTI_PinSource15
#define DIN_E1_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_E2
 */
#define DIN_E2_PIN                GPIO_Pin_0
#define DIN_E2_GPIO_PORT          GPIOD
#define DIN_E2_GPIO_CLK           RCC_AHB1Periph_GPIOD
#define DIN_E2_EXTI_LINE          EXTI_Line0
#define DIN_E2_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOD
#define DIN_E2_EXTI_PIN_SOURCE    EXTI_PinSource0
#define DIN_E2_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_E3
 */
#define DIN_E3_PIN                GPIO_Pin_1
#define DIN_E3_GPIO_PORT          GPIOD
#define DIN_E3_GPIO_CLK           RCC_AHB1Periph_GPIOD
#define DIN_E3_EXTI_LINE          EXTI_Line1
#define DIN_E3_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOD
#define DIN_E3_EXTI_PIN_SOURCE    EXTI_PinSource1
#define DIN_E3_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_E4
 */
#define DIN_E4_PIN                GPIO_Pin_7
#define DIN_E4_GPIO_PORT          GPIOE
#define DIN_E4_GPIO_CLK           RCC_AHB1Periph_GPIOE
#define DIN_E4_EXTI_LINE          EXTI_Line7
#define DIN_E4_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOE
#define DIN_E4_EXTI_PIN_SOURCE    EXTI_PinSource7
#define DIN_E4_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_E5
 */
#define DIN_E5_PIN                GPIO_Pin_8
#define DIN_E5_GPIO_PORT          GPIOE
#define DIN_E5_GPIO_CLK           RCC_AHB1Periph_GPIOE
#define DIN_E5_EXTI_LINE          EXTI_Line8
#define DIN_E5_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOE
#define DIN_E5_EXTI_PIN_SOURCE    EXTI_PinSource8
#define DIN_E5_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_E6
 */
#define DIN_E6_PIN                GPIO_Pin_9
#define DIN_E6_GPIO_PORT          GPIOE
#define DIN_E6_GPIO_CLK           RCC_AHB1Periph_GPIOE
#define DIN_E6_EXTI_LINE          EXTI_Line9
#define DIN_E6_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOE
#define DIN_E6_EXTI_PIN_SOURCE    EXTI_PinSource9
#define DIN_E6_EXTI_IRQn          EXTI0_IRQn
/**
 * @brief DIN_E7
 */
#define DIN_E7_PIN                GPIO_Pin_10
#define DIN_E7_GPIO_PORT          GPIOE
#define DIN_E7_GPIO_CLK           RCC_AHB1Periph_GPIOE
#define DIN_E7_EXTI_LINE          EXTI_Line10
#define DIN_E7_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOE
#define DIN_E7_EXTI_PIN_SOURCE    EXTI_PinSource10
#define DIN_E7_EXTI_IRQn          EXTI0_IRQn

/** @addtogroup STM32F407_IO DOUT  (A0...2)
  * @{
  */  
#define DIN_E_CSn                             3

#define DIN_E_CS_A0_PIN                         GPIO_Pin_0
#define DIN_E_CS_A0_GPIO_PORT                   GPIOF
#define DIN_E_CS_A0_GPIO_CLK                    RCC_AHB1Periph_GPIOF  
  
#define DIN_E_CS_A1_PIN                         GPIO_Pin_1
#define DIN_E_CS_A1_GPIO_PORT                   GPIOF
#define DIN_E_CS_A1_GPIO_CLK                    RCC_AHB1Periph_GPIOF  
  
#define DIN_E_CS_A2_PIN                         GPIO_Pin_2
#define DIN_E_CS_A2_GPIO_PORT                   GPIOF
#define DIN_E_CS_A2_GPIO_CLK                    RCC_AHB1Periph_GPIOF  



/** @addtogroup STM32F407_IO LEDn  (LED1...6)
  * @{
  */  

#define DOUTn                             24

#define LED1_PIN                         GPIO_Pin_0
#define LED1_GPIO_PORT                   GPIOB
#define LED1_GPIO_CLK                    RCC_AHB1Periph_GPIOB  
  
#define LED2_PIN                         GPIO_Pin_14
#define LED2_GPIO_PORT                   GPIOB
#define LED2_GPIO_CLK                    RCC_AHB1Periph_GPIOB  
  
#define LED3_PIN                         GPIO_Pin_15
#define LED3_GPIO_PORT                   GPIOB
#define LED3_GPIO_CLK                    RCC_AHB1Periph_GPIOB  
  
#define LED4_PIN                         GPIO_Pin_7
#define LED4_GPIO_PORT                   GPIOC
#define LED4_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define LED5_PIN                         GPIO_Pin_8
#define LED5_GPIO_PORT                   GPIOC
#define LED5_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define LED6_PIN                         GPIO_Pin_9
#define LED6_GPIO_PORT                   GPIOC
#define LED6_GPIO_CLK                    RCC_AHB1Periph_GPIOC


/** @addtogroup STM32F407_IO DOUT  (TX_DATA, TX_EN, RX_EN, DOUT_E0...11, BARRA_ON)
  * @{
  */  
#define TX_DATA_PIN                         GPIO_Pin_7
#define TX_DATA_GPIO_PORT                   GPIOI
#define TX_DATA_GPIO_CLK                    RCC_AHB1Periph_GPIOI  

#define TX_EN_PIN                           GPIO_Pin_8
#define TX_EN_GPIO_PORT                     GPIOI
#define TX_EN_GPIO_CLK                      RCC_AHB1Periph_GPIOI  

#define RX_EN_PIN                           GPIO_Pin_9
#define RX_EN_GPIO_PORT                     GPIOI
#define RX_EN_GPIO_CLK                      RCC_AHB1Periph_GPIOI  

#define DOUT_E0_PIN                         GPIO_Pin_10
#define DOUT_E0_GPIO_PORT                   GPIOI
#define DOUT_E0_GPIO_CLK                    RCC_AHB1Periph_GPIOI  

#define DOUT_E1_PIN                         GPIO_Pin_11
#define DOUT_E1_GPIO_PORT                   GPIOI
#define DOUT_E1_GPIO_CLK                    RCC_AHB1Periph_GPIOI  

#define DOUT_E2_PIN                         GPIO_Pin_2
#define DOUT_E2_GPIO_PORT                   GPIOH
#define DOUT_E2_GPIO_CLK                    RCC_AHB1Periph_GPIOH

#define DOUT_E3_PIN                         GPIO_Pin_3
#define DOUT_E3_GPIO_PORT                   GPIOH
#define DOUT_E3_GPIO_CLK                    RCC_AHB1Periph_GPIOH

#define DOUT_E4_PIN                         GPIO_Pin_4
#define DOUT_E4_GPIO_PORT                   GPIOH
#define DOUT_E4_GPIO_CLK                    RCC_AHB1Periph_GPIOH

#define DOUT_E5_PIN                         GPIO_Pin_15
#define DOUT_E5_GPIO_PORT                   GPIOG
#define DOUT_E5_GPIO_CLK                    RCC_AHB1Periph_GPIOG

#define DOUT_E6_PIN                         GPIO_Pin_0
#define DOUT_E6_GPIO_PORT                   GPIOC
#define DOUT_E6_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define DOUT_E7_PIN                         GPIO_Pin_6
#define DOUT_E7_GPIO_PORT                   GPIOC
#define DOUT_E7_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define DOUT_E8_PIN                         GPIO_Pin_2
#define DOUT_E8_GPIO_PORT                   GPIOD
#define DOUT_E8_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define DOUT_E9_PIN                         GPIO_Pin_3
#define DOUT_E9_GPIO_PORT                   GPIOD
#define DOUT_E9_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define DOUT_E10_PIN                         GPIO_Pin_6
#define DOUT_E10_GPIO_PORT                   GPIOD
#define DOUT_E10_GPIO_CLK                    RCC_AHB1Periph_GPIOD

#define DOUT_E11_PIN                         GPIO_Pin_7
#define DOUT_E11_GPIO_PORT                   GPIOF
#define DOUT_E11_GPIO_CLK                    RCC_AHB1Periph_GPIOF

#define BARRA_ON_PIN                         GPIO_Pin_6
#define BARRA_ON_GPIO_PORT                   GPIOI
#define BARRA_ON_GPIO_CLK                    RCC_AHB1Periph_GPIOI

#define PTT1_PIN                         	 GPIO_Pin_2
#define PTT1_GPIO_PORT                   	 GPIOC
#define PTT1_GPIO_CLK                    	 RCC_AHB1Periph_GPIOC

#define PTT2_PIN                          	 GPIO_Pin_3
#define PTT2_GPIO_PORT                   	 GPIOC
#define PTT2_GPIO_CLK                    	 RCC_AHB1Periph_GPIOC

#endif

/** @defgroup IAR_STM32F407ZG_SK_LOW_LEVEL_Exported_Macros
  * @{
  */  
/**
  * @}
  */ 


/** @defgroup IAR_STM32F407ZG_SK_LOW_LEVEL_Exported_Functions
  * @{
  */
void STM_GPIO_Init(Dout_TypeDef GPIOn);
void STM_GPIO_On(Dout_TypeDef GPIOn);
void STM_GPIO_Off(Dout_TypeDef GPIOn);
void STM_GPIO_Toggle(Dout_TypeDef GPIOn);
void STM_GPIO_DIN_UC_Init(DIN_UC_TypeDef DIN);
uint32_t STM_GPIO_DIN_UC_GetState(DIN_UC_TypeDef Button);
void STM_GPIO_On_Off(Dout_TypeDef GPIOn, uint8_t State);
uint8_t ReadBufferAdd( uint16_t address);
void WriteBufferAdd(uint16_t address, uint8_t val);
/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM32F407_IO_H */
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */  

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
