/*
 * main.c
 *
 *  Created on: Nov 12, 2021
 *      Author: ziad
 */
#include "avr/io.h"
#include "LIB/bitmath.h"
#include"LIB/stdtypes.h"
#include "HAL/LCD_handler/LCD_int.h"
#include "HAL/LCD_handler/LCD_cfg.h"
#include "avr/delay.h"
void UART_vidInit(void)
{
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	char UCSRC_TEMP ;
	UCSRC_TEMP |= (1<<7) |(1<<2) |(1<<1);
	UBRRL = 51 ;
	UBRRH = 0;

}
void UART_SEND_DATA (char Data )
{
	UDR = Data ;
	while (GET_BIT(UCSRA,5) == 0);

}
char UART_RECEIVE_DATA (void )
{
	char received ;
	while(GET_BIT(UCSRA,7) == 0);
	received = UDR ;
	return(received);
}
void main (void)
{
	char REC;
	UART_vidInit();
	DDRC =0b00001111;
	LCD_vidInit();

	while(1)
	{
		REC = UART_RECEIVE_DATA();
		if(REC <=255 && REC >= 0)
		{LCD_VidWriteCharacter(REC);}

	}
}
