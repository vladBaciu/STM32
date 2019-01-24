/*
 * TCNT_Driver.c
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#include "TCNT_Driver.h"

#define TCNT_DRIVER_UP_COUNTER   					((uint8)(0x00<<4))
#define TCNT_DRIVER_UPDATE_GENERATION         			((uint8)(1<<0))
#define TCNT_DRIVER_COUNTER_ENABLE   			             ((uint8)(0x01))

void TCNT_Module_Init(TIM_TypeDef* TIMx) {
	/*Set the clock of the selected TCNT instance*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*Set the direction of the counting*/
	TIMx->CR1 |= TCNT_DRIVER_UP_COUNTER;
	/*Restart the counter after it has reached its peak value*/
	TIMx->EGR |= TCNT_DRIVER_UPDATE_GENERATION;
}

/*Start the selected timer*/
void TCNT_Module_Start(TIM_TypeDef* TIMx) {
	TIMx->CR1 |= TCNT_DRIVER_COUNTER_ENABLE;
}

/*Select the peak value of the timer (can be used as a second prescaler)*/
void TCNT_Module_SetPeriod(TIM_TypeDef* TIMx, uint32 PeriodValue) {
	TIMx->ARR = PeriodValue;
}

/*Select the prescale value of the timer*/
void TCNT_Module_SetPrescale(TIM_TypeDef* TIMx, uint32 PrescaleValue) {
	TIMx->PSC = PrescaleValue;
}

/*Clear the timers status register*/
void TCNT_Module_ClearStatus(TIM_TypeDef* TIMx) {
	TIMx->SR = ((uint16) (0x00));
}

/*Get the timers status*/
uint8 TCNT_Module_GetStatus(TIM_TypeDef* TIMx, uint8 Event) {
	if (((TIMx->SR) & Event) == 0x00) {
		return 0x01;
	} else {
		return 0x00;
	}
}

