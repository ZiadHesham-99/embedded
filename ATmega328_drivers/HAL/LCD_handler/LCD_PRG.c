/*
 * LCD_PRG.c
 *
 *  Created on: Oct 1, 2021
 *      Author: ziad
 */
#include "util/delay.h"
#include "../../LIB/stdtypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LCD_cfg.h"
#define LCD_FUNC_SET_CMD (u8)    0b00111000
#define LCD_ON_OFF_CTRL_CMD (u8) 0b00001110
#define LCD_DISPLAY_CLR_CMD (u8) 0b00000001
#define LCD_ENTRY_MODE_CMD (u8)  0b00000110
extern void LCD_vidInit(void)
{
	DIO_u8SetPortDir(LCD_DATA_PORT,OUTPUT_PORT);
	DIO_u8SetPinDir(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	DIO_u8SetPinDir(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
	DIO_u8SetPinDir(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	_delay_ms(40);
	LCD_vidSendCommand(LCD_FUNC_SET_CMD);
	_delay_ms(1);
	LCD_vidSendCommand(LCD_ON_OFF_CTRL_CMD);
	_delay_ms(1);
	LCD_vidSendCommand(LCD_DISPLAY_CLR_CMD);
	_delay_ms(2);
	LCD_vidSendCommand(LCD_ENTRY_MODE_CMD);
	_delay_ms(1);

}
extern void LCD_vidSendCommand(u8 Copy_u8Command)
{
	DIO_u8SetPinVal(LCD_RS_PORT,LCD_RS_PIN,LOW);
	DIO_u8SetPinVal(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8SetPortVal(LCD_DATA_PORT,Copy_u8Command);
	DIO_u8SetPinVal(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(2);



}
extern void LCD_VidWriteCharacter(u8 Copy_u8character)
{
	DIO_u8SetPinVal(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	DIO_u8SetPinVal(LCD_RW_PORT,LCD_RW_PIN,LOW);
	DIO_u8SetPortVal(LCD_DATA_PORT,Copy_u8character);
	DIO_u8SetPinVal(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_u8SetPinVal(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(2);

}

