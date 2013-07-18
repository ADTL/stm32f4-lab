#ifndef __USART_H
#define __USART_H

#include "main.h"

/*
 * Connect orange to PB7
 * Connect brown to PB6
 * Use 3V (3.3) power source.
 */

//------------------------------------------------exported functions-----------
void usart1_init (uint32_t baudrate, xQueueHandle* p_queue_chars);
void usart1_write_string (char *string);
void usart1_write_char (char c);
//-----------------------------------------------------------------------------

#endif //__USART_H
