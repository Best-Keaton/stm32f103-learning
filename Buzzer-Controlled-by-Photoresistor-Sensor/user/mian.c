#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "buzzer.h"
#include "lightsensor.h"
uint8_t readsingal=0;
int main(void)
{	
	
	while(1)
	{
		readsingal=read_signal();
		if(readsingal==1)
		{
			buzzer_work();
		}
		else
		{
			buzzer_off();
		}
	}
}

