/* Includes */
#include "GPIO_Driver.h"
#include "USART_Driver.h"

volatile uint32 DelayInterval = 0x00;
uint32 transmit_counter = 0x00;

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

int main(void) {
	/*Setup the delay clock and the GPIO module*/
	SysTick_Config(SystemCoreClock / 1000);

	GPIO_Module_Init(GPIOB, 6);
	GPIO_Module_SetAlternateFunction(GPIOB, 6, GPIO_DRIVER_AF7_USART_1);

	GPIO_Module_Init(GPIOB, 7);
	GPIO_Module_SetAlternateFunction(GPIOB, 7, GPIO_DRIVER_AF7_USART_1);

	USART_Module_Init(USART1);
	USART_Module_Set_Baudrate(USART1);

	while (1) {
		USART_Module_Start(USART1);
		USART_Module_Send_Str(USART1, "Hello world\n\r");
		USART_Module_Send_Char(USART1, '0' + transmit_counter);
		USART_Module_Send_Str(USART1, "\n\r");
		transmit_counter++;
		if (transmit_counter > 0x09) {
			transmit_counter = 0x00;
		}
		USART_Module_Stop(USART1);

		Delay(350);
	}
}
