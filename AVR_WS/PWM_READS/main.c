/*
 * main.c
 *
 *  Created on: Nov 6, 2021
 *      Author: ziad
 */
#include "LIB/bitmath.h"
#include"LIB/stdtypes.h"
#include "MCAL/INTERRUPT/INTERRUPT_int.h"
#include "MCAL/INTERRUPT/INTERRUPT_reg.h"
#include "MCAL/Timer/Timer_int.h"

#define FIRST_RISIG 0
#define RISING 1
#define FALLING 2
u16 Ton_ticks ;
u16 Totalticks ;



