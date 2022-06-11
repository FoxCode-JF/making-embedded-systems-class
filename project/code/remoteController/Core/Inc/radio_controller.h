/*
 * radio_controller.h
 *
 *  Created on: May 29, 2022
 *      Author: Fox
 */

#ifndef INC_RADIO_CONTROLLER_H_
#define INC_RADIO_CONTROLLER_H_

#include "nrf24.h"

void radio_Init();
void radio_Process_Tx(uint8_t *dataToSend, uint8_t dataByteSize);
nRF24_TXResult radio_TransmitPacket(uint8_t *pBuf, uint8_t length);

void UART_SendChar(char b);
void UART_SendStr(char *string);
void Toggle_LED();
void UART_SendHex8(uint16_t num);
void UART_SendBufHex(char *buf, uint16_t bufsize);
void UART_SendInt(int32_t num);
void UART_SendInt16(int16_t num);

#endif /* INC_RADIO_CONTROLLER_H_ */
