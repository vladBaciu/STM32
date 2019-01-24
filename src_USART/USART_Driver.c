/*
 * USART_Driver.c
 *
 *  Created on: Jan 16, 2019
 *      Author: zsolt.balo
 */

/*
 Set the selected Tx and Rx pins as Alternate function mode(with AFR registers also configured for both), TX as output PushPull, and RX as input. No pull-up/down resistors. Speed will be high for both.
 */
#include "USART_Driver.h"

void USART_Module_Init(USART_TypeDef* USARTx) {
	/*Set the clock off the selected USART instance*/
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	/*
	 Set the oversampling option (8 or 16), word length (8 or 9 bits), and if the parity controll is needed
	 */
	USARTx->CR1 |= (USART_DRIVER_OVERSAMPLING << 0x0F)
			| (USART_DRIVER_WORD_LENGTH << 0x0C)
			| (USART_DRIVER_PARITY_CONTROL_ENABLE << 0x0A);

	/*If parity controll is needed than set the parity mode (even or odd)*/
#if (USART_DRIVER_PARITY_CONTROL_ENABLE == 0x01)
	USARTx->CR1 |=(USART_DRIVER_PARITY_SELECTION<<0x09);
#endif

	/*Enable USART Rx and Tx*/
	USARTx->CR1 |= (0x01 << 0x03) | (0x01 << 0x02);

	/*Select the STOP bit (1,2,1.5)*/
	USARTx->CR2 |= (USART_DRIVER_STOP_BIT_SELECT << 0x0C);

	/*Select if the half duplex mode is needed*/
	USARTx->CR3 |= (USART_DRIVER_HALF_DUPLEX_SELECTION << 0x03);
}

/*Calculate the USART Baud rate*/
void USART_Module_Set_Baudrate(USART_TypeDef* USARTx) {
	uint16_t MANTISA = 0;
	uint8_t FRACTION = 0;
	uint32_t tmp = 0, result = 0;

#if (USART_DRIVER_OVERSAMPLING == USART_DRIVER_OVERSAMPLING_BY_16 )
	tmp = (((25 * (USART_DRIVER_WORKING_FREQUENCY_2)) / USART_DRIVER_BAUDRATE)
			/ 4);
#else
	tmp = (((25*(USART_DRIVER_WORKING_FREQUENCY_2))/USART_DRIVER_BAUDRATE)/2);
#endif

	/*to double precision*/
	MANTISA = ((tmp / 100) << 4);

	/*truchate the fraction, move the integer left to left space for the new fraction*/
	tmp = tmp - ((MANTISA >> 4) * 100);

	/*to get the fraction shift back the last value and multiply back,
	 then save the difference got by subtracting from the old one*/

#if (USART_DRIVER_OVERSAMPLING == USART_DRIVER_OVERSAMPLING_BY_16 )
	FRACTION = ((((tmp * 16) + 50) / 100) & ((uint8_t) 0x0F));
#else
	FRACTION = ((((tmp*8)+50)/100)&((uint8_t)0x07));
#endif

	/*\100 with the multiplication at the begining the value had been modified, it had to be turned back*/
	/*+50 is used for rounding up*/
	/*Multiply with the available maximum value of the fraction part of the BRR*/
	result = MANTISA | FRACTION;
	USARTx->BRR = result;
}

/*Receive a byte through USART*/
uint8 USART_Module_Receive_Char(USART_TypeDef* USARTx) {
	uint8 Payload = 0x00;
	while ((USART_Module_GetStatus(USARTx, USART_Driver_RXNE)) == FAILED)
		;
	Payload = USARTx->DR;
	return Payload;
}

/*Send a byte through USART*/
void USART_Module_Send_Char(USART_TypeDef* USARTx, uint8 data) {
	USARTx->DR = data;
	while ((USART_Module_GetStatus(USARTx, USART_Driver_TXE)) == FAILED)
		;
}

/*Send a string through USART*/
void USART_Module_Send_Str(USART_TypeDef* USARTx, char* Msg) {
	uint8 index = 0x00;
	while (Msg[index]) {
		USART_Module_Send_Char(USARTx, Msg[index]);
		index++;
	}
}

/*Start the USART*/
void USART_Module_Start(USART_TypeDef* USARTx) {
	USARTx->CR1 |= (0x01 << 0x0D);
}

/*Stop the USART*/
void USART_Module_Stop(USART_TypeDef* USARTx) {
	USARTx->CR1 &= (~(0x01 << 0x0D));
}

/*Check the USART event in the status register*/
uint8 USART_Module_GetStatus(USART_TypeDef* USARTx, uint8 Status_Bit) {
	if ((USARTx->SR & Status_Bit) != FALSE) {
		return SUCCES;
	} else {
		return FAILED;
	}
}
