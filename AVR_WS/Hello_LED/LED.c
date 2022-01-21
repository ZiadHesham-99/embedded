/*
 * LED.c

 *
 *  Created on: Sep 10, 2021
 *      Author: ziad
 */
#include"avr/io.h"
#include"util/delay.h"
void main (void)
{
	DDRA = 0b11111111;
	PORTA = 0b00000001;


	while(1)
	{
		for(int i=0 ; i<8;i++)
		{
			_delay_ms(500);
			PORTA = PORTA <<1 ;
			_delay_ms(500);
		}
		PORTA = 0B10000000;


		for(int i=0 ; i<8;i++)
				{
					_delay_ms(500);
					PORTA = PORTA >>1 ;
					_delay_ms(500);
				}
		PORTA = 0B00000001;
	}

}

