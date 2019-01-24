#include "GPIO_Driver.h"
#include "TCNT_Driver.h"

uint8 state = 0x00;

int main(void)
{
	GPIO_Module_Init(GPIOD,12);
	GPIO_Module_Init(GPIOD,13);

	TCNT_Module_Init(TIM2);
	TCNT_Module_SetPrescale(TIM2,(48-1));
	TCNT_Module_SetPeriod(TIM2,(500000-1));
	TCNT_Module_Start(TIM2);

	while (1)
	{
		if((TCNT_Module_GetStatus(TIM2,TCNT_DRIVER_UPDATE_INTERRUPT_FLAG))==SUCCES)
		{
			state = !state;
			TCNT_Module_ClearStatus(TIM2);
		}
		if(state)
		{
			GPIO_Module_SetPin(GPIOD,13);
			GPIO_Module_ClearPin(GPIOD,12);
		}
		else
		{
			GPIO_Module_SetPin(GPIOD,12);
			GPIO_Module_ClearPin(GPIOD,13);
		}
	}
}
