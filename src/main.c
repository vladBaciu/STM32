#include "GPIO_Driver.h"

volatile uint32 DelayInterval = 0x00;

/*The Systick timer is used for the delay functionality, which decreases the DelayInterval.
 It is used only for the examples, in the applications the OS timing shall be used!*/

void SysTick_Handler() {
	if (DelayInterval != 0x00) {
		DelayInterval--;
	}
}

/*Stops the application for DelayTime interval in ms (ex DelayTime(100) stops the application for 100 ms)*/

void Delay(uint32 DelayTime) {
	DelayInterval = DelayTime;
	while (DelayInterval != 0x00) {/*Do nothing*/
	}
}

int main() {

	/*Setup the delay clock and the GPIO module*/
	SysTick_Config(SystemCoreClock/1000);
	GPIO_Module_Init(GPIOD, 15);

	while (1) {
		GPIO_Module_SetPin(GPIOD, 15);
		Delay(250);
		GPIO_Module_ClearPin(GPIOD, 15);
		Delay(250);
	}

	return 0;
}
