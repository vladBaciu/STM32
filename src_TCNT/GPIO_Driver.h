/*
 * GPIO_Driver.h
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f407xx.h"
#include "StdTypes.h"

#define GPIO_DRIVER_INPUT_MODE 								((uint32)0x0000)
#define GPIO_DRIVER_OUTPUT_MODE  							((uint32)0x0001)
#define GPIO_DRIVER_ALTERNATE_FUNCTION_MODE 				((uint32)0x0002)
#define GPIO_DRIVER_ANALOG_MODE  							((uint32)0x0003)
#define GPIO_DRIVER_OUTPUT_PP 								((uint32)0x0000)
#define GPIO_DRIVER_OUTPUT_OD 								((uint32)0x0001)
#define GPIO_DRIVER_LOW_SPEED_2MHZ 							((uint32)0x0000)
#define GPIO_DRIVER_MEDIUM_SPEED_25MHZ 						((uint32)0x0001)
#define GPIO_DRIVER_HIGH_SPEED_50MHZ 						((uint32)0x0002)
#define GPIO_DRIVER_VERY_HIGH_SPEED_100MHZ					((uint32)0x0003)
#define GPIO_DRIVER_PUPD_NOPULL 							((uint32)0x0000)
#define GPIO_DRIVER_PUPD_UP 								((uint32)0x0001)
#define GPIO_DRIVER_PUPD_DOWN 								((uint32)0x0002)
#define GPIO_DRIVER_AF0_SYSTEM								((uint8)0x00)
#define GPIO_DRIVER_AF1_TIM_1								((uint8)0x01)
#define GPIO_DRIVER_AF1_TIM_2                               ((uint8)0x01)
#define GPIO_DRIVER_AF2_TIM_3                               ((uint8)0x02)
#define GPIO_DRIVER_AF2_TIM_4                               ((uint8)0x02)
#define GPIO_DRIVER_AF2_TIM_5                               ((uint8)0x02)
#define GPIO_DRIVER_AF3_TIM_8                               ((uint8)0x03)
#define GPIO_DRIVER_AF3_TIM_9                               ((uint8)0x03)
#define GPIO_DRIVER_AF3_TIM_10                              ((uint8)0x03)
#define GPIO_DRIVER_AF3_TIM_11                              ((uint8)0x03)
#define GPIO_DRIVER_AF4_I2C_1                               ((uint8)0x04)
#define GPIO_DRIVER_AF4_I2C_2                               ((uint8)0x04)
#define GPIO_DRIVER_AF4_I2C_3                               ((uint8)0x04)
#define GPIO_DRIVER_AF5_SPI_1                               ((uint8)0x05)
#define GPIO_DRIVER_AF5_SPI_2                               ((uint8)0x05)
#define GPIO_DRIVER_AF6_SPI_3                               ((uint8)0x06)
#define GPIO_DRIVER_AF7_USART_1                             ((uint8)0x07)
#define GPIO_DRIVER_AF7_USART_2                             ((uint8)0x07)
#define GPIO_DRIVER_AF7_USART_3                             ((uint8)0x07)
#define GPIO_DRIVER_AF8_USART_4                             ((uint8)0x08)
#define GPIO_DRIVER_AF8_USART_5                             ((uint8)0x08)
#define GPIO_DRIVER_AF8_USART_6                             ((uint8)0x08)
#define GPIO_DRIVER_AF9_CAN_1                               ((uint8)0x09)
#define GPIO_DRIVER_AF9_CAN_2                               ((uint8)0x09)
#define GPIO_DRIVER_AF9_TIM_12                              ((uint8)0x09)
#define GPIO_DRIVER_AF9_TIM_13                              ((uint8)0x09)
#define GPIO_DRIVER_AF9_TIM_14                              ((uint8)0x09)
#define GPIO_DRIVER_AF10_OTG_FS                             ((uint8)0x0A)
#define GPIO_DRIVER_AF10_OTG_HS                             ((uint8)0x0A)
#define GPIO_DRIVER_AF11_ETH                                ((uint8)0x0B)
#define GPIO_DRIVER_AF12_FSMC                               ((uint8)0x0C)
#define GPIO_DRIVER_AF12_SDIO                               ((uint8)0x0C)
#define GPIO_DRIVER_AF12_OTG_HS                             ((uint8)0x0C)
#define GPIO_DRIVER_AF13_DCMI                               ((uint8)0x0D)
#define GPIO_DRIVER_AF14                                    ((uint8)0x0E)
#define GPIO_DRIVER_AF15_EVENTOUT                           ((uint8)0x0F)

void GPIO_Module_Init(GPIO_TypeDef *GPIO_Port, uint16 PinNr);
void GPIO_Module_SetAlternateFunction(GPIO_TypeDef *GPIO_Port, uint16 PinNr,
uint16 Alt_function);
void GPIO_Module_SetPin(GPIO_TypeDef *GPIO_Port, uint16 PinNr);
void GPIO_Module_ClearPin(GPIO_TypeDef *GPIO_Port, uint16 PinNr);
uint16 GPIO_Module_ReadInputData(GPIO_TypeDef *GPIO_Port);
uint8 GPIO_Module_ReadInputDataBit(GPIO_TypeDef *GPIO_Port, uint16 Bit_number);
uint16 GPIO_Module_ReadOutputData(GPIO_TypeDef *GPIO_Port);

#endif /* GPIO_DRIVER_H_ */
