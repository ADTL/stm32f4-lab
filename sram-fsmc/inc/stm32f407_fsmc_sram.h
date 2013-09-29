/**
  ******************************************************************************
  * @file    stm32f407_sram.cpp
  * @author  Juliano Mayor
  * @version V1.0
  * @date    25-Julho-2013
  * @brief   Este arquivo contém as funções necessárias para inicialização e uso 
  *          da memória SRAM IS62WV512 via FSMC.
  * @date    09-Agosto-2013
  * @brief   Incluidas funções de escrita/leitura para 8 bits 
  ******************************************************************************
 Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F407_FSMC_SRAM_H
#define __STM32F407_FSMC_SRAM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stm32f4xx_conf.h>
#include <stdint.h>
/* Includes ------------------------------------------------------------------*/
//#include "STM324x7i_eval.h"
//#include "stm32f407_io.h"
   
#define Bank1_SRAM2_ADDR  ((uint32_t)0x64007d00)  

#define addressOut_0    ((uint32_t)0x080000)
#define addressIn_0     ((uint32_t)0x080000)
#define addressIn_1     ((uint32_t)0x080001)
#define addressIn_2     ((uint32_t)0x080002)
   
#define rele_K1 ((uint8_t)0x08)
#define rele_K2 ((uint8_t)0x10)
#define rele_K3 ((uint8_t)0x20)
#define rele_K4 ((uint8_t)0x40)
#define rele_K5 ((uint8_t)0x80)

#define Din_E0   ((uint16_t)0x101) 
#define Din_E1   ((uint16_t)0x102) 
#define Din_E2   ((uint16_t)0x104) 
#define Din_E3   ((uint16_t)0x108) 
#define Din_E4   ((uint16_t)0x110) 
#define Din_E5   ((uint16_t)0x120) 
#define Din_E6   ((uint16_t)0x140) 
#define Din_E7   ((uint16_t)0x180) 
   
#define Din_E8   ((uint16_t)0x201) 
#define Din_E9   ((uint16_t)0x202) 
#define Din_E10  ((uint16_t)0x204) 
#define Din_E11  ((uint16_t)0x208) 
#define Din_E12  ((uint16_t)0x210) 
#define Din_E13  ((uint16_t)0x220) 
#define Din_E14  ((uint16_t)0x240) 
#define Din_E15  ((uint16_t)0x280)
   
#define Din_E16  ((uint16_t)0x301) 
#define Din_E17  ((uint16_t)0x302) 
#define Din_E18  ((uint16_t)0x304) 
#define Din_E19  ((uint16_t)0x308) 
#define Din_E20  ((uint16_t)0x310) 
#define Din_E21  ((uint16_t)0x320) 
#define Din_E22  ((uint16_t)0x340) 
#define Din_E23  ((uint16_t)0x380)
   

/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM324x7I_EVAL
  * @{
  */
  
/** @addtogroup STM324x7I_EVAL_FSMC_SRAM
  * @{
  */  

/** @defgroup STM324x7I_EVAL_FSMC_SRAM_Exported_Types
  * @{
  */
/**
  * @}
  */
  
/** @defgroup STM324x7I_EVAL_FSMC_SRAM_Exported_Constants
  * @{
  */ 
/**
  * @}
  */ 
  
/** @defgroup STM324x7I_EVAL_FSMC_SRAM_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup STM324x7I_EVAL_FSMC_SRAM_Exported_Functions
  * @{
  */      

void FSMC_Init(uint32_t DataLenght);
void SRAM_WriteBuffer_16(uint16_t* pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite);
void SRAM_ReadBuffer_16(uint16_t* pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead);
void SRAM_WriteBuffer_8(uint8_t* pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite);
void SRAM_ReadBuffer_8(uint8_t* pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead);


#ifdef __cplusplus
}
#endif

#endif /* __STM324x7I_EVAL_FSMC_SRAM_H */
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

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
