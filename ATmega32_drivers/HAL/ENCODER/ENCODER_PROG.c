/*
 * ENCODER_PROG.c
 *
 *  Created on: Jun 19, 2022
 *      Author: Hosam
 */

#include "../../MCAL/DIO/DIO_INT.h"
#include"../../MCAL/EXT_INTR/EXT_INTR_INT.h"
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ENCODER_INT.h"

extern u8 lastStateCLK;


void ENCODER_vidINT(){
		DDRD &=(~(1<<PD2)| (1<<PD3));
		DDRC = 0XFF;
		PORTC = 0X00;
		lastStateCLK = PIND & (1 << PIND2);
		EXTERNALINTERRUPT_vidEnable(INT_00);
		EXTERNALINTERRUPT_vidSenseControlINT0OR1(INT_0,ANY_LOGICAL_CHANGE);
		GLOBEL_INTERRUPT_vidEnableDisable(1);
}

