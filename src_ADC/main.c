#include "GPIO_Driver.h"
#include "ADC_Driver.h"

volatile uint32 measurement = 0x00;

int main() {

	GPIO_Module_Init(GPIOA, 1);
	ADC_Module_Init(ADC1);

	while (1) {
		/*Trigger ADC read on tye selected channel*/
		ADC_Module_StartSampling(ADC1);
		/*Read the measured value*/
		measurement = ADC_Module_GetSample(ADC1);
	}

	return 0;
}
