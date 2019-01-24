/* Includes */
#include "GPIO_Driver.h"
#include "TCNT_Driver.h"
#include "PWM_Driver.h"

volatile uint32 TickCounter=0x00;
uint8 state = 0x00;
uint32 index = 0x00;


void SysTick_Handler()
{
	if(TickCounter!=0x00)
	{
		TickCounter--;
	}
}

void Delay(uint32 DelayInterval)
{
	TickCounter = DelayInterval;
	while(TickCounter!=0x00){}
}

int main(void)
{

	SysTick_Config(SystemCoreClock/1000);

	GPIO_Module_Init(GPIOA,1);
	GPIO_Module_SetAlternateFunction(GPIOA,1,GPIO_DRIVER_AF1_TIM_2);

	TCNT_Module_Init(TIM2);
	TCNT_Module_SetPrescale(TIM2,0x00);
	TCNT_Module_SetPeriod(TIM2,(16000));
	TCNT_Module_Start(TIM2);

	PWM_Module_Init(TIM2);

	while (1)
	{
		for(index = 0;index<10;index++)
		{
			PWM_Module_SetDutyCylce(TIM2,(index*10));
			Delay(80);
		}
		for(index = 5;index>=1;index--)
		{
			PWM_Module_SetDutyCylce(TIM2,(index*10));
			Delay(80);
		}
		Delay(200);
	}
}
