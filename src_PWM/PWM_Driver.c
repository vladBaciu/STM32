/*
 * PWM_Driver.c
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#include "PWM_Driver.h"

/*
 The example below uses the 2nd PWM channel of the timer
 First set up the PWMs timmer according to the requirements
 Set the GPIO in Alternate function mode, and set the AFR register to with the AF number. Output mode will be Push-Pull, no pull-up/down resistors. Speed will be high.
 */

void PWM_Module_Init(TIM_TypeDef *TIMx) {
	/*
	 Enable the CCR registers updating
	 Set to PWM mode 1 (the pulse gets high when CCR > CNT)
	 PWM pin out high when active CCR > CNT
	 PWM pin out enable
	 */
	TIMx->CCMR1 |= ((PWM_DRIVER_OUTPUT_COMPARE_PRELOAD_ENABLE << 0x0B)
			| (PWM_DRIVER_PWM_MODE_1 << 0x0C));

	TIMx->CCER |= ((PWM_DRIVER_ACTIVE_HIGH << 0x05)
			| (PWM_DRIVER_CAPTURE_COMPARE_ENABLE << 0x04));
}

void PWM_Module_SetDutyCylce(TIM_TypeDef *TIMx, uint32 DutyCycle) {
	/*Set the desired duty cycle in percents*/
	if (DutyCycle > 100) {
		DutyCycle = 100;
	}

	TIMx->CCR2 = ((uint16) (((TIMx->ARR) * DutyCycle) / 100));
}
