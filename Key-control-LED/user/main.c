#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "led.h"
#include "key.h"
uint16_t keynum1;
uint16_t keynum2;
int main(void)
{
	led_Init();
	key_Init();
	uint8_t led1_state = 0; 
	uint8_t led2_state = 0;
	while(1)
	{
		keynum1=key1_num();
		keynum2=key2_num();
		if(keynum1==1)
		{
			led1_state=!led1_state;
			if(led1_state==1)
			{
				led1_on();
			}
			else
		{
			led1_off();
		}
		}
		
		if(keynum2==1)
		{
			led2_state=!led2_state;
			if(led2_state==1)
			{
			led2_on();
			}
			else
		{
			led2_off();
		}
		}
		
	}
}

