#include "stm32f10x.h"                  // Device header
#ifndef __lightsensor_H
#define __lightsensor_H

void lightsensor_Init(void);
uint16_t read_signal(void);

#endif
