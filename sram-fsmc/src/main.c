#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include <stdint.h>

void Delay(__IO uint32_t nCount) {
  while(nCount--) {
  }
}


int main (void)
{
#define BUFFER_SIZE         ((uint32_t)0x000F)
#define WRITE_READ_ADDR     ((uint32_t)0x0000000)

    uint16_t aTxBuffer [BUFFER_SIZE];
    uint16_t aRxBuffer [BUFFER_SIZE];
    uint8_t* aTxBuffer_8 = "PLC-ART 1234567";
    uint8_t aRxBuffer_8 [BUFFER_SIZE];

    uint8_t i;
    FSMC_Init(FSMC_MemoryDataWidth_16b);

    for (i = 0; i <= strlen((char*) aTxBuffer_8); i++)
    {
        aTxBuffer [i] = (aTxBuffer_8 [i * 2] << 8) | aTxBuffer_8 [i * 2 + 1];
    }

    SRAM_WriteBuffer_16(aTxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);
    SRAM_ReadBuffer_16(aRxBuffer, WRITE_READ_ADDR, BUFFER_SIZE);

    for (i = 0; i <= strlen((char*) aTxBuffer_8); i++)
    {
        aRxBuffer_8 [i * 2] = (aRxBuffer [i] & 0xFF00) >> 8;
        aRxBuffer_8 [i * 2 + 1] = aRxBuffer [i] & 0x00FF;
    }

    while(1)
        ;
}
