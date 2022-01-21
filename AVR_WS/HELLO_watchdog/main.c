/*
 * main.c
 *
 *  Created on: Dec 3, 2021
 *      Author: ziad
 */

#include "LIB/bitmath.h"
#include"LIB/stdtypes.h"
#include "avr/io.h"
#include "avr/delay.h"
void main (void)
{
	DDRA=0xff;
	for(int i =0 ;i<512 ;i++)
	{

		PORTA=0;
		PORTA = 0b00000001;
		_delay_ms(5);
		PORTA = 0b00000010;
		_delay_ms(5);
		PORTA = 0b00000100;
		_delay_ms(5);
		PORTA = 0b00001000;
		_delay_ms(5);

	}
}
