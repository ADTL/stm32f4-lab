#ifndef __STEPMOTOR_TASK_H
#define __STEPMOTOR_TASK_H

#include "main.h"

//------------------------------------------------exported functions-----------

void task_stepmotor_init(xQueueHandle *p_queue_stepmotor);
void task_stepmotor_send_dutycycle(int value);

//-----------------------------------------------------------------------------

#endif //__STEPMOTOR_TASK_H
