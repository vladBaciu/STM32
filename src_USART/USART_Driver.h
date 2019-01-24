/*
 * USART_Driver.h
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

#include "stm32f407xx.h"
#include "StdTypes.h"

#define USART_DRIVER_BAUDRATE 				9600

/*Clear to send flag*/
#define USART_Driver_CTS					0x200
/*LIN break direction flag*/
#define USART_Driver_LBD					0x100
/*Transmit data register empty flag*/
#define USART_Driver_TXE					0x080
/*Transmission complete flag*/
#define USART_Driver_TC						0x040
/*Read data register not empty*/
#define USART_Driver_RXNE					0x020
/*Idle line detected flag*/
#define USART_Driver_IDLE					0x010
/*Overrun error flag*/
#define USART_Driver_ORE					0x008
/*Noise detected flag*/
#define USART_Driver_NF						0x004
/*Framing error flag*/
#define USART_Driver_FE						0x002
/*Parity error flag*/
#define USART_Driver_PE 					0x001

#define USART_DRIVER_OVERSAMPLING_BY_16		0x00
#define USART_DRIVER_OVERSAMPLING_BY_8		0x01
#define USART_DRIVER_8_DATA_BITS			0x00
#define USART_DRIVER_9_DATA_BITS			0x01
#define USART_DRIVER_EVEN_PARITY			0x00
#define USART_DRIVER_ODD_PARITY				0x01
#define USART_DRIVER_1_STOP_BIT				0x00

/*UART4 and UART 5 doesn't implement these options*/
#if(((USART_DRIVER_USART5_SELECT == NOK) && (USART_DRIVER_USART4_SELECT == NOK))==OK)
#define USART_DRIVER_0_5_STOP_BIT			0x01
#endif

#define USART_DRIVER_2_STOP_BIT				0x10

/*UART4 and UART 5 doesn't implement these options*/
#if(((USART_DRIVER_USART5_SELECT == NOK) && (USART_DRIVER_USART4_SELECT == NOK))==OK)
#define USART_DRIVER_1_5_STOP_BIT			0x11
#endif

#define USART_DRIVER_OVERSAMPLING         		USART_DRIVER_OVERSAMPLING_BY_16
#define USART_DRIVER_WORD_LENGTH         	 	USART_DRIVER_8_DATA_BITS
#define USART_DRIVER_STOP_BIT_SELECT     		USART_DRIVER_1_STOP_BIT
#define USART_DRIVER_PARITY_CONTROL_ENABLE  	0x00
#define USART_DRIVER_HALF_DUPLEX_SELECTION    	0x00
#define USART_DRIVER_WORKING_FREQUENCY_2    	84000000

void USART_Module_Init(USART_TypeDef* USARTx);
void USART_Module_Set_Baudrate(USART_TypeDef* USARTx);
uint8 USART_Module_Receive_Char(USART_TypeDef* USARTx);
void USART_Module_Send_Char(USART_TypeDef* USARTx, uint8 data);
void USART_Module_Send_Str(USART_TypeDef* USARTx, char* Msg);
void USART_Module_Start(USART_TypeDef* USARTx);
void USART_Module_Stop(USART_TypeDef* USARTx);
uint8 USART_Module_GetStatus(USART_TypeDef* USARTx, uint8 Status_Bit);

#endif /* USART_DRIVER_H_ */
