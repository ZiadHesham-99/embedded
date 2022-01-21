/*
 * main.c
 *
 *  Created on: Oct 1, 2021
 *      Author: ziad
 */
#include"../LIB/stdtypes.h"
#include"../HAL/LCD_handler/LCD_int.h"
#include"../HAL/KEYPAD_handler/KEYPAD_int.h"
#include "../MCAL/DIO/DIO_int.h"
#include "util/delay.h"

void main (void)
{
	u8 Local_u8Key ;
	LCD_vidInit();
	KEYPAD_vidInit();

	while(1)
	{
		Local_u8Key = KEYPAD_u8GetPressed();
		if(Local_u8Key != 0)
		{
			LCD_VidWriteCharacter(Local_u8Key);
		}

	}




}
