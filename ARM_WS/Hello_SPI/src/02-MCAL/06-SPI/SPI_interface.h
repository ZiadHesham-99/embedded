/*
 * SPI_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: ziad
 */

#ifndef _MCAL_06_SPI_SPI_INTERFACE_H_
#define _MCAL_06_SPI_SPI_INTERFACE_H_

void SPI_vidInit(void) ;
#if SPI_DATA_FRAME_FORMAT == FRAME_FORMAT_8_BIT

void SPI_vidSendData(u8 Data);
u8 SPI_u8RecieveData(void);

#else

void SPI_vidSendData(u16 Data);
u16 SPI_u8RecieveData(void)

#endif

#endif /* 02_MCAL_06_SPI_SPI_INTERFACE_H_ */
