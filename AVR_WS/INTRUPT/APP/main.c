/*
 * main.c
 *
 *  Created on: Oct 1, 2021
 *      Author: ziad
 */
#include"../LIB/stdtypes.h"
#include "util/delay.h"
#include"avr/interrupt.h"
#include"../MCAL/INTERRUPT/INTERRUPT_int.h"

ISR(INT2_vect)
{
	PORTB  ^=(1<<0);
}



void main (void)
{


	PORTB |=(1<<2);
	/*
	 * Configure the LED PIN OUTPUT
	 */
	DDRB |= (1<<0);
	DDRA |= (1<<0);
	/*
	 * configure INT0

	MCUCR |= (1<<0);
	/*
	 * Enable PIE of INT0

	GICR |= (1<<6);
	/*
	 * Enable GIE

	SREG  |= (1<<7);
	*/
	INTERRUPT_u8GlobalInterruptControl(ENABLE);
	INTERRUPT_u8Enable(INT_2);
	INTERRUPT_u8SenseControl(INT_2,FALLING_EDGE);

	while(1)
	{



	}






}
