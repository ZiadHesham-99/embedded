/*
 * main.c
 *
 *  Created on: Aug 28, 2021
 *      Author: ziad
 */
#include"avr/io.h"
#include"util/delay.h"
#include "bitmath.h"
void main(void)
{
	DDRA = 0b000000001;
	PORTA = 0b00000000 ;
	while(1)
	{
		SET_BIT(PORTA,0);
		_delay_ms(1000);
		CLR_BIT(PORTA,0);
		_delay_ms(1000);
	}

}

