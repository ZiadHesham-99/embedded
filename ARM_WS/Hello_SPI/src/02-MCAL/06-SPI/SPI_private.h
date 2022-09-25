/*
 * SPI_private.h
 *
 *  Created on: Sep 24, 2022
 *      Author: ziad
 */

#ifndef _MCAL_06_SPI_SPI_PRIVATE_H_
#define _MCAL_06_SPI_SPI_PRIVATE_H_

#define SPI_BASE_ADDRESS 0x40013000

typedef struct
{
	union
	{
		u32 REGISTER;
		struct
		{
			u32 CPHA:1;     //1->write first (should be configured according to the salve)
			u32 CPOL:1;     // 1->normal high (should be configured according to the salve)
			u32 MSTR:1;     //1->master
			u32 BR:3;         //baud rate control -> 000:FPCLK/2 , 111:FPCLK/256
			u32 SPE:1;
			u32 LSBFIRST:1; // 0->MSB ,1->LSB (should be configured according to the salve)
			u32 SSI:1;
			u32 SSM:1;        // used for single slave mode
			u32 RXONLY:1;    // should be kept as 0 if you don't use bidirection mode
			u32 DFF:1;         // data frame format ( 0 ->8bit , 1 ->16 bit)
			u32 CRCNEXT:1;    // must be written as soon as the last data is written to the SPI_DR register.
			u32 CRCEN:1;    // this feature enables an extra saftey layer to SPI , you send an indiependant frame of "keyword" before or after data frame
			u32 BIDIOE:1;    //used for single wire bi-directional mode
			u32 BIDIMODE:1;    //used for single wire bi-directional mode
		}BIT;
	}CR1;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 RXDMEAN:1; 	//When this bit is set, the DMA request is made whenever the RXNE flag is set.
			u32 TXDMEAN:1; 	//
			u32 SSOE:1;		//0: SS output is disabled in master mode and the cell can work in multimaster configuration
			u32 RESERVED:1;
			u32 FRF:1;		// 1: SPI TI mode , 0: SPI motorola mode
			u32 ERRIE:1;	//This bit controls the generation of an interrupt when an error condition occurs )(CRCERR,OVR, MODF in SPI mode, FRE in TI mode and UDR, OVR, and FRE in I2S mode).
			u32 RXNEIE:1;	// rx not empty IE
			u32 TXEIE:1;

		}BIT;
	}CR2;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 RXNE:1;
			u32 TXE:1;
			u32 CHSIDE:1;	//This bit is not used for SPI mode and is meaningless
			u32 UDR:1;		//This bit is not used in SPI mode.
			u32 CRCERR:1;	//(0: CRC value received matches the SPI_RXCRCR value)
			u32 MODF:1;
			u32 OVR:1;		//Overrun flag
			u32 BSY:1;		//1: SPIis busy in communication or Tx buffer is not empt
			u32 FRE:1;		//frame error
		}BIT;
	}SR;

	u32 DR;

}SPI_t;

#define SPI ((volatile SPI_t*) SPI_BASE_ADDRESS)

#endif /* 02_MCAL_06_SPI_SPI_PRIVATE_H_ */
