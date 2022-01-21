/*
 * main.c
 *
 *  Created on: Sep 13, 2021
 *      Author: ziad
 */
#include"avr/io.h"
#include"util/delay.h"
void main (void)
{
	DDRA = 0b00000000;
	DDRC = 0b00000001;
	PORTA= 0b11111111;

	while(1)
	{
		if(PINA == 0b10101010)
		{PORTC=0b00000010;}
		else
		{PORTC= 0b00000001;}
	}
}

