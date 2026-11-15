#include "stm32f10x.h"                  // Device header

uint8_t readnum=0;
void lightsensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint16_t read_signal(void)
{
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9)==0)
	{
		readnum=1;
	}
	else
	{
		readnum=0;
	}
	return readnum;
}
