/*
 * main.c
 *
 *  Created on: Oct 3, 2021
 *      Author: ziad
 */
#include"avr/io.h"
#include"util/delay.h"
void main (void)
{
	DDRA = 0b00000001;
	DDRB = 0b00000001;
	while(1)
	{
		_delay_ms(2000);
		PORTA = 0b00000001;
		_delay_ms(2000);
		PORTA = 0b00000000;
		_delay_ms(2000);
	    PORTB = 0b00000001;
	    _delay_ms(2000);
	    PORTB = 0b00000000;
	}
}
