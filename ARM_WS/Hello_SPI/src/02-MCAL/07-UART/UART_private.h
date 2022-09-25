/*
 * UART_private.h
 *
 *  Created on: Sep 24, 2022
 *      Author: ziad
 */

#ifndef MCAL_07_UART_UART_PRIVATE_H_
#define MCAL_07_UART_UART_PRIVATE_H_

typedef struct {
	union{
		u32 REG;
		struct{
			u32 PE:  1;
			u32 FE:  1;
			u32 NF:  1;
			u32 ORE: 1;
			u32 IDLE:1;
			u32 RXNE:1;
			u32 TC:  1;
			u32 TXE: 1;
			u32 LBD: 1;
			u32 CTS: 1;
			u32 :22;
		}BIT;
	}SR;

	union{
		u32 REG ;
		struct{
			u32 DATA:9;
			u32:23;
		}BIT;
	}DR;

	union{
		u32 REG;
		struct{
			u32 DIV_FRACTION:4;
			u32 DIV_MANTISSA:12;
			u32 :16;
		}BIT;
	}BRR;

	union{
		u32 REG;
		struct{
			u32 SBK	   :1;
			u32 RWU    :1;
			u32 RE     :1;
			u32 TE     :1;
			u32 IDLEIE :1;
			u32 RXNEIE :1;
			u32 TCIE   :1;
			u32 TXEIE  :1;
			u32 PEIE   :1;
			u32 PS     :1;
			u32 PCE    :1;
			u32 WAKE   :1;
			u32 M      :1;
			u32 UE     :1;
			u32        :1;
			u32 OVER8  :1;
			u32        :16;
		}BIT;
	}CR1;
	union{
		u32 REG;
		struct{
			u32 ADD   :4;
			u32       :1;
			u32 LBDL  :1;
			u32 LBDIE :1;
			u32       :1;
			u32 LBCL  :1;
			u32 CPHA  :1;
			u32 CPOL  :1;
			u32 CLKEN :1;
			u32 STOP  :2;
			u32 LINEN :1;
			u32       :17;
		}BIT;
	}CR2;
	union{
		u32 REG;
		struct{
			u32 EIE   :1;
			u32 IREN  :1;
			u32 IRLP  :1;
			u32 HDSEL :1;
			u32 NACK  :1;
			u32 SCEN  :1;
			u32 DMAR  :1;
			u32 DMAT  :1;
			u32 RTSE  :1;
			u32 CTSE  :1;
			u32 CTSIE :1;
			u32 ONEBIT:1;
			u32       :20;
		}BIT;
	}CR3;
}UART_t;

#define UART ((volatile UART_t*) 0x40011000)

#endif /* 02_MCAL_07_UART_UART_PRIVATE_H_ */

