/*
 * STP_program.c
 *
 *  Created on: Aug 19, 2022
 *      Author: ziad
 */
#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../../01-LIB/03-ERROR_STATUS/ERROR_STATUS.h"

#include"../../02-MCAL/01-RCC/RCC_interface.h"
#include"../../02-MCAL/02-GPIO/GPIO_interface.h"
#include"../../02-MCAL/02-GPIO/GPIO_private.h"
#include"../../02-MCAL/03-SYSTICK/SYSTICK_interface.h"

#include"STP_private.h"
#include"STP_interface.h"
#include"STP_config.h"

void STP_vidSendData(volatile u8 local_u8Data){
	u8 temp=0;
	for(s8 i=7;i>=0;i--){
		//temp = GET_BIT(local_u8Data ,i);
		temp = local_u8Data &(1<<i);
		GPIO_voidSetPinValue(DATA_PIN_PORT,DATA_PIN_NUM,temp);
		GPIO_voidSetPinValue(SHIFT_CLOCK_PORT,SHIFT_CLOCK_PIN,LEVEL_HIGH);
		//SYSTICK_voidsychronousDelay(1);
		//SYSTICK_voiduSecDelay(1);
		GPIO_voidSetPinValue(SHIFT_CLOCK_PORT,SHIFT_CLOCK_PIN,LEVEL_LOW);
	}
	GPIO_voidSetPinValue(LATCH_CLOCK_PORT,LATCH_CLOCK_PIN,LEVEL_HIGH);
	SYSTICK_voidsychronousDelay(3);
	//SYSTICK_voiduSecDelay(1);
	GPIO_voidSetPinValue(LATCH_CLOCK_PORT,LATCH_CLOCK_PIN,LEVEL_LOW);
}

