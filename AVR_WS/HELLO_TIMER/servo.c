///*
// * servo.c
// *
// *  Created on: Oct 30, 2021
// *      Author: ziad
// */
//#include"LIB/stdtypes.h"
//#include"LIB/bitmath.h"
//#include"AVR/io.h"
//#include"avr/interrupt.h"
//#include "AVR/delay.h"
//#define ANGLE_0_TICKS 1000
//#define ANGLE_180_TICKS 2000
//void main(void)
//{
//	u16 angle_ticks ;
//	/*
//	 * select output mode for fast pwm
//	 */
//	DDRD |=(1<<5);
//	TCCR1A |=(1<<COM1A1);
//	TCCR1A &=(1<<0);
//	TCCR1A |=(1<<1);
//	TCCR1B |=(1<<WGM12) | (1<<WGM13);
//	/*
//	 * Select prescaller = 8 i.e timer freq= 1MHZ
//	 */
//	TCCR1B |=(1<<CS11);
//	/*
//	 * SET ICR1 with total =20ms
//	 */
//	ICR1 = 20000;
//	while(1)
//	{
//		for(angle_ticks = ANGLE_0_TICKS ; angle_ticks <ANGLE_180_TICKS ; angle_ticks+=10)
//		{
//			OCR1A = angle_ticks ;
//			_delay_ms(40);
//		}
//		for(angle_ticks = ANGLE_180_TICKS ; angle_ticks >ANGLE_0_TICKS ; angle_ticks-=10)
//		{
//			OCR1A = angle_ticks ;
//					_delay_ms(40);
//		}
//	}
//
//}
//
