/*
 * main.c
 *
 *  Created on: Oct 27, 2021
 *      Author: ziad
 */
#include"../LIB/bitmath.h"
#include"../LIB/stdtypes.h"
#include"../HAL/KEYPAD_handler/KEYPAD_int.h"
#include"../HAL/LCD_handler/LCD_int.h"
#include"../MCAL/ADC/ADC_int.h"
#include"AVR/io.h"
#include"AVR/delay.h"
u8 PassCheck(u8 *Password)
{
	u8 pass_counter=0;
	LCD_vidWriteStr("PLEASE ENTER THE PASSWORD");
	LCD_vidSendCommand(0xC0);
	LCD_VidWriteCharacter(':');
	for(u8 i=0;i<8;i++)
	{
		if(Password[i]== KEYPAD_u8GetPressed())
			{
				pass_counter++;
			}
	}
	if(pass_counter == 8)
	{
		return(0);
	}
	else{
		LCD_vidClearScreen();
		LCD_vidWriteStr("WRONG PASSWORD...!");
		_delay_ms(300);
		return(PassCheck(Password));
	}

}
void main (void)
{
	u8 Password[8] ={'1','2','3','4','5','6','7','8'};
	LCD_vidInit();
	ADC_init(VREF_STATE_ENUM_EXTERNALVREF,LEFT_ADJUST_CTRL_ENABLE);
	KEYPAD_vidInit();
	LCD_vidWriteStr("HELLO ");
	_delay_ms(300);
	PassCheck(Password);
	LCD_vidWriteStr(" ********");
	_delay_ms(200);
	LCD_vidClearScreen();
	LCD_vidWriteStr("WELCOME USER ! ");

}



