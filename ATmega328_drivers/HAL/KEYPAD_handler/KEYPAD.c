/*
 * KEYPAD.c
 *
 *  Created on: Oct 2, 2021
 *      Author: ziad
 */
#include "util/delay.h"
#include "../../LIB/stdtypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "KEYPAD_cfg.h"
#define NOT_PRESSED (u8) 0
extern u8 KEYPAD_u8arrKeypadMap[KEYPAD_ROWS][KEYPAD_COLS];
void KEYPAD_vidInit(void)
{
	/*
	 * SET columns as output
	 */
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_COL1_PIN , OUTPUT);
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_COL2_PIN , OUTPUT);
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_COL3_PIN , OUTPUT);
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_COL4_PIN , OUTPUT);
	/*
	 * set columns by high
	 */
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_COL1_PIN , HIGH);
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_COL2_PIN , HIGH);
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_COL3_PIN , HIGH);
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_COL4_PIN , HIGH);
	/*
	 * set rows as input
	 */
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_ROW1_PIN , INPUT);
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_ROW2_PIN , INPUT);
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_ROW3_PIN , INPUT);
	DIO_u8SetPinDir(KEYPAD_PORT,KEYPAD_ROW4_PIN , INPUT);
	/*
	 * ENABLE PULLUP FOR ROWS
	 */
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_ROW1_PIN , HIGH);
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_ROW2_PIN , HIGH);
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_ROW3_PIN , HIGH);
	DIO_u8SetPinVal(KEYPAD_PORT,KEYPAD_ROW4_PIN , HIGH);
}

u8 KEYPAD_u8GetPressed(void)
{
	u8 Local_u8PressedSwitch = NOT_PRESSED ;
	u8 Local_u8CurrentCol;
	u8 Local_u8CurrentRow ;
	u8 Local_u8CurrentRowStatus;

	for(Local_u8CurrentCol = KEYPAD_COL_START; Local_u8CurrentCol <=KEYPAD_COL_END;  Local_u8CurrentCol++)
	{
		DIO_u8SetPinVal(KEYPAD_PORT  , Local_u8CurrentCol , LOW);
		for(Local_u8CurrentRow = KEYPAD_ROW_START; Local_u8CurrentRow <=KEYPAD_ROW_END;  Local_u8CurrentRow++)
		{
			DIO_u8GetPinVal(KEYPAD_PORT,Local_u8CurrentRow,&Local_u8CurrentRowStatus);
			{
				if(Local_u8CurrentRowStatus==LOW)
				{

					_delay_ms(5);
					Local_u8PressedSwitch = KEYPAD_u8arrKeypadMap[Local_u8CurrentRow - KEYPAD_ROW_START][Local_u8CurrentCol - KEYPAD_COL_START];
					while(Local_u8CurrentRowStatus==LOW)
					{
						DIO_u8GetPinVal(KEYPAD_PORT,Local_u8CurrentRow,&Local_u8CurrentRowStatus);
					}
					_delay_ms(5);

				}
			}
		}
		DIO_u8SetPinVal(KEYPAD_PORT  , Local_u8CurrentCol , HIGH);
	}

	return(Local_u8PressedSwitch);
}
