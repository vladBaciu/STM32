/*
 * TCNT_Driver.h
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#ifndef TCNT_DRIVER_H_
#define TCNT_DRIVER_H_

#include "stm32f407xx.h"
#include "StdTypes.h"

#define TCNT_DRIVER_CAPTURE_COMPARE_4_OVERCAPTURE_FLAG 					((uint8)(1<<12))
#define TCNT_DRIVER_CAPTURE_COMPARE_3_OVERCAPTURE_FLAG 					((uint8)(1<<11))
#define TCNT_DRIVER_CAPTURE_COMPARE_2_OVERCAPTURE_FLAG 					((uint8)(1<<10))
#define TCNT_DRIVER_CAPTURE_COMPARE_1_OVERCAPTURE_FLAG 					((uint8)(1<<9))
#define TCNT_DRIVER_TRIGGER_INTERRUPT_FLAG             					((uint8)(1<<6))
#define TCNT_DRIVER_CAPTURE_COMPARE_4_INTERRUPT FLAG   					((uint8)(1<<4))
#define TCNT_DRIVER_CAPTURE_COMPARE_3_INTERRUPT FLAG   					((uint8)(1<<3))
#define TCNT_DRIVER_CAPTURE_COMPARE_2_INTERRUPT FLAG   					((uint8)(1<<2))
#define TCNT_DRIVER_CAPTURE_COMPARE_1_INTERRUPT FLAG   					((uint8)(1<<1))
#define TCNT_DRIVER_UPDATE_GENERATION              						((uint8)(1<<0))
#define TCNT_DRIVER_UPDATE_INTERRUPT_FLAG              					((uint8)(1<<0))
#define TCNT_DRIVER_UP_COUNTER											((uint8)(0x00<<4))
#define TCNT_DRIVER_DOWN_COUNTER										((uint8)(0x01<<4))
#define TCNT_DRIVER_COUNTER_ENABLE										((uint8)(0x01))
#define TCNT_DRIVER_COUNTER_DISABLE										((uint8)(0x00))
#define TCNT_DRIVER_OUTPUT_COMPARE_MODE_FROZEN							((uint8)(0x00))
#define TCNT_DRIVER_OUTPUT_COMPARE_MODE_SET_CHANNEL_HIGH                ((uint8)(0x01))
#define TCNT_DRIVER_OUTPUT_COMPARE_MODE_SET_CHANNEL_LOW                 ((uint8)(0x02))
#define TCNT_DRIVER_OUTPUT_COMPARE_MODE_TOGGLE_CHANNEL                  ((uint8)(0x03))
#define TCNT_DRIVER_OUTPUT_COMPARE_MODE_FORCE_LOW                       ((uint8)(0x04))
#define TCNT_DRIVER_OUTPUT_COMPARE_MODE_FORCE_HIGH                      ((uint8)(0x05))

void TCNT_Module_Init(TIM_TypeDef* TIMx);
void TCNT_Module_Start(TIM_TypeDef* TIMx);
void TCNT_Module_SetPeriod(TIM_TypeDef* TIMx, uint32 PeriodValue);
void TCNT_Module_SetPrescale(TIM_TypeDef* TIMx, uint32 PrescaleValue);
void TCNT_Module_ClearStatus(TIM_TypeDef* TIMx);
uint8 TCNT_Module_GetStatus(TIM_TypeDef* TIMx, uint8 Event);

#endif /* TCNT_DRIVER_H_ */
