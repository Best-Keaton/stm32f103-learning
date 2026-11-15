#include "stm32f10x.h"                  // Device header
#include "Delay.h"
uint8_t flag=0;
uint16_t num=0x0002;
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//LED active low
	GPIO_InitStructure.GPIO_Pin = 0x01FE;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA,0x01FE);//High level,LED don't work
	while(1)
	{
	if(flag==0)
	{
	GPIO_SetBits(GPIOA, 0x01FE);
	GPIO_ResetBits(GPIOA,num);
	num=num<<1;
	Delay_ms(50);
	if(num==0x0200)
	{
		flag=1;
		num=0x0100;
	}
		}
	if(flag==1)
		{
	GPIO_SetBits(GPIOA, 0x01FE);
	GPIO_ResetBits(GPIOA,num);
	num=num>>1;
	Delay_ms(50);
	if(num==0x001)
	{
		flag=0;
		num=0x0002;
	}
		}
}
}
