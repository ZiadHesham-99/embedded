/*
 * LCD_int.h
 *
 *  Created on: Oct 1, 2021
 *      Author: ziad
 */

#ifndef HALL_LCD_HANDLER_LCD_INT_H_
#define HALL_LCD_HANDLER_LCD_INT_H_
void LCD_vidSendCommand(u8 Copy_u8Command);
void LCD_vidInit(void);
void LCD_VidWriteCharacter(u8 Copy_u8character);
void LCD_vidWriteStr(u8 * Copy_u8pstr);
void LCD_vidClearScreen(void);



#endif /* HALL_LCD_HANDLER_LCD_INT_H_ */
