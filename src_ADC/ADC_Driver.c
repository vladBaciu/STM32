/*
 * ADC_Driver.c
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#include "ADC_Driver.h"

void ADC_Module_Init(ADC_TypeDef* ADCx) {
	/*Set the clock of the selected ADC instance*/
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	/*The selected resolution (options 12bit,10bit,8bit,6bit) */
	ADCx->CR1 |= ADC_DRIVER_RESOLUTION_12_Bits;

	/*Set the alignment*/
	ADCx->CR2 |= ADC_DRIVER_ALIGNMENT_RIGHT;

	/*
	 Set the sampling time of the channel, in case the channel number is greater than 0x09 than use SMPR1
	 */
	ADCx->SMPR2 |= ((ADC_DRIVER_CHANNEL_SAMPLING_TIME_144_CYCLES) << 3);

	/*
	 Select the respective position in the sampling sequence of the desired channel
	 In our case we have one channel only (ADCx, channel 1)
	 */
	ADCx->SQR3 |= 0x01;

	/*Start the ADC*/
	ADCx->CR2 |= ADC_DRIVER_ON;
}

uint16 ADC_Module_GetSample(ADC_TypeDef* ADCx) {
	/*Get the result of the ADC conversion*/
	uint16 data = 0x00;
	data = ((uint16) (ADCx->DR));
	/*data = data>>4; remove last bits to reduce fluctuation (reduces the resolution to)*/
	return data;
}

uint8 ADC_Module_GetStatus(ADC_TypeDef* ADCx, uint8 Event) {
	/*Get the result of the ADC conversion*/
	if ((ADCx->SR & Event) == 0x00) {
		/*The selected option is set*/
		return 0x01;
	} else {
		/*The selected option is not set*/
		return 0x00;
	}
}

void ADC_Module_StartSampling(ADC_TypeDef* ADCx) {
	/*Start by Software of the regular conversion*/
	ADCx->CR2 |= ADC_DRIVER_REGULAR_START;
}
