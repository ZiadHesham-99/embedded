/*
 * UART_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: ziad
 */

#ifndef MCAL_07_UART_UART_INTERFACE_H_
#define MCAL_07_UART_UART_INTERFACE_H_

u8 UART_u8Receive(u32 MaxTimeToWait);
void UART_vidTransmitChar(u8 Data);
void UART_vidTransmitString(u8 * dataPtr);

#endif /* 02_MCAL_07_UART_UART_INTERFACE_H_ */
