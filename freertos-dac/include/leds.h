#ifndef __LEDS_H
#define __LEDS_H

#include "main.h"

//------------------------------------------------exported functions-----------

void ledlib_init();
void ledlib_set_error_state();

void ledlib_flash_blue_led();
void ledlib_flash_orange_led();

//-----------------------------------------------------------------------------

#endif //__LEDS_H
