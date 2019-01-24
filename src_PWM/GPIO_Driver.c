/*
 * GPIO_Driver.c
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#include "GPIO_Driver.h"

/*Initialize the GPIO*/
void GPIO_Module_Init(GPIO_TypeDef *GPIO_Port, uint16 PinNr) {

	/*Enable the modules clock signal*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*the mode of the gpio (General purpose output, ADC, Alternate function or Input)*/
	GPIO_Port->MODER |= (GPIO_DRIVER_ALTERNATE_FUNCTION_MODE) << (2 * PinNr);
	/*the type of the output is push-pull (open-drain is only needed for the I2C communication)*/
	GPIO_Port->OTYPER |= (GPIO_DRIVER_OUTPUT_PP) << (PinNr);
	/*the slew rate of the pin*/
	GPIO_Port->OSPEEDR |= (GPIO_DRIVER_HIGH_SPEED_50MHZ) << (2 * PinNr);
	/*Selection of the pull-up/down resistors, in our case its not activated*/
	GPIO_Port->PUPDR |= (GPIO_DRIVER_PUPD_NOPULL) << (2 * PinNr);
}

/*
 Use the alternate function setup only in the case, when alternate functionality is needed (ex. PWM, USART,...).
 ADC is not an alternate function, it is configured by the MODER register.
 */

void GPIO_Module_SetAlternateFunction(GPIO_TypeDef *GPIO_Port, uint16 PinNr,
		uint16 Alt_function) {
	if (PinNr < 0x08) {
		GPIO_Port->AFR[0] |= (Alt_function) << (4 * PinNr);
	} else {
		GPIO_Port->AFR[1] |= (Alt_function) << (4 * (PinNr - 8));
	}
}

/*Set the selected pin to 1*/
void GPIO_Module_SetPin(GPIO_TypeDef *GPIO_Port, uint16 PinNr) {
	GPIO_Port->BSRR |= (1 << PinNr);
}

/*Clear the selected pin*/
void GPIO_Module_ClearPin(GPIO_TypeDef *GPIO_Port, uint16 PinNr) {
	GPIO_Port->BSRR |= ((1 << PinNr) << 16);
}

/*Read the value of the input data (the value of all the bits)*/
uint16 GPIO_Module_ReadInputData(GPIO_TypeDef *GPIO_Port) {
	uint16 result = 0x00;
	result = ((uint16) (GPIO_Port->IDR));
	return result;
}

/*Read the value of the input data (the value of only one bit)*/
uint8 GPIO_Module_ReadInputDataBit(GPIO_TypeDef *GPIO_Port, uint16 Bit_number) {
	uint16 input = 0x00;
	uint8 result = 0x00;

	input = ((uint16) (GPIO_Port->IDR));
	result = ((input & (1 << Bit_number)) != 0x00) ? 1 : 0;
	return result;
}

/*Read the value of the output data register(the value of all the bits)*/
uint16 GPIO_Module_ReadOutputData(GPIO_TypeDef *GPIO_Port) {
	uint16 result = 0x00;
	result = ((uint16) (GPIO_Port->ODR));
	return result;
}

