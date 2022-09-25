/*
 * DotMatrix.c
 *
 *  Created on: Aug 20, 2022
 *      Author: ziad
 */
#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../../01-LIB/03-ERROR_STATUS/ERROR_STATUS.h"

#include"../../02-MCAL/01-RCC/RCC_interface.h"
#include"../../02-MCAL/02-GPIO/GPIO_interface.h"
#include"../../02-MCAL/02-GPIO/GPIO_private.h"
#include"../../02-MCAL/03-SYSTICK/SYSTICK_interface.h"

#include"../STP/STP_interface.h"

#include"DotMatrix.h"
#include"DotMatrix_config.h"



void vidusecDelay(u32 msecs){

	SYSTICK_voidsychronousDelay(msecs*3);
}

void DotMatrix_vidDisplay( u8 * arr ){
	for(u8 i= 0;i<50;i++){
		disableAllColumn();
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_0 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[0]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_0 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue( DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_1 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[1]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_1 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , /*DOT_MATRIX_COL_2*/PIN_NUM_2 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[2]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_2 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_3 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[3]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_3 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_4 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[4]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_4 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_5 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[5]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_5 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_6 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[6]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_6 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_7 ,LEVEL_LOW);
		GPIO_voidSetPortValue(DOT_MATRIX_ROW_PORT /*DOT_MATRIX_ROW_PORT*/ ,arr[7]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(DOT_MATRIX_COLUMN_PORT , DOT_MATRIX_COL_7 ,LEVEL_HIGH);

	}
}

void disableAllColumn(void){
	GPIO_voidSetPortValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/,255);
}
void DotMatrix_vidSTP_Display( u8 * arr ){
	for(u8 i= 0;i<50;i++){
		disableAllColumn();
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_0 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[0]);
		STP_vidSendData(arr[0]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_0 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_1 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[1]);
		STP_vidSendData(arr[1]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_1 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , /*DOT_MATRIX_COL_2*/PIN_NUM_2 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[2]);
		STP_vidSendData(arr[2]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_2 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_3 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[3]);
		STP_vidSendData(arr[3]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_3 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_4 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[4]);
		STP_vidSendData(arr[4]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_4 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_5 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[5]);
		STP_vidSendData(arr[5]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_5 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_6 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[6]);
		STP_vidSendData(arr[6]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_6 ,LEVEL_HIGH);
		/**/
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_7 ,LEVEL_LOW);
		//GPIO_voidSetPortValue(PORT_NAME_B /*DOT_MATRIX_ROW_PORT*/ ,arr[7]);
		STP_vidSendData(arr[7]);
		vidusecDelay(2500);
		GPIO_voidSetPinValue(PORT_NAME_A /*DOT_MATRIX_COLUMN_PORT*/ , DOT_MATRIX_COL_7 ,LEVEL_HIGH);

	}
}

