/*
 * main.c
 *
 *  Created on: Oct 29, 2021
 *      Author: ziad
 */
#include"LIB/stdtypes.h"
#include"LIB/bitmath.h"
#include"AVR/io.h"
#include"avr/interrupt.h"
#include"AVR/delay.h"
#define NORMAL_MODE_SET_MASK (u8) 0b10110000
#define PRESCALLER_1024_SET_MASK (u8) 0b00000101
#define ANGLE_0_TICKS 1000
#define ANGLE_180_TICKS 2000
/*
ISR(__vector_11)
{
	static u8 counter=0;
	counter++;
	if(counter==31)
	{
		PORTD^=0b10000000;
		TCNT0 = 123;
		counter = 0 ;
	}
}
void main (void)
{
	DDRD = 0b10000000;
	TCCR0 &=  NORMAL_MODE_SET_MASK ;
	SET_BIT(TIMSK,0);
	TCNT0 = 123;
	SET_BIT(SREG,7);
	TCCR0 |= PRESCALLER_1024_SET_MASK;
	while(1)
	{

	}


}
*/
void main(void)
{
	u16 angle_ticks ;
	/*
	 * select output mode for fast pwm
	 */
	DDRD |=(1<<5);
	TCCR1A |=(1<<COM1A1);
	TCCR1A &=(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B |=(1<<WGM12) | (1<<WGM13);
	/*
	 * Select prescaller = 8 i.e timer freq= 1MHZ
	 */
	TCCR1B |=(1<<CS11);
	/*
	 * SET ICR1 with total =20ms
	 */
	ICR1 = 20000;
	while(1)
	{
		for(angle_ticks = ANGLE_0_TICKS ; angle_ticks <ANGLE_180_TICKS ; angle_ticks+=10)
		{
			OCR1A = angle_ticks ;
			_delay_ms(40);
		}
		for(angle_ticks = ANGLE_180_TICKS ; angle_ticks >ANGLE_0_TICKS ; angle_ticks-=10)
		{
			OCR1A = angle_ticks ;
					_delay_ms(40);
		}
	}
}
