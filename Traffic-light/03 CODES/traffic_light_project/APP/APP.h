#ifndef APP_H_
#define APP_H_

#include "avr/interrupt.h"

#define F_CPU 8000000UL
#include "UTIL/STD_TYPES.h"
#include "UTIL/REG.h"
#include "UTIL/BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/EXT_INT/EXT_INT.h"
#include "MCAL/TIMER/TIMER.h"
#include "HAL/LED/LED.h"
#include "HAL/P_B/P_B.h"
#include <avr/wdt.h>

void app_init();
void app_start();





#endif // APP_H_
