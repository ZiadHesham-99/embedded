/*
 * main.c
 *
 *  Created on: Oct 1, 2021
 *      Author: ziad
 */
#include"../LIB/stdtypes.h"
#include"../HAL/LCD_handler/LCD_int.h"
#include "util/delay.h"

void main (void)
{

	LCD_vidInit();
	LCD_vidWriteStr("HELLO DILARA !");
	_delay_ms(200);
	while(1)
	{
		LCD_vidShiftLeft();
		_delay_ms(300);
	}






}
