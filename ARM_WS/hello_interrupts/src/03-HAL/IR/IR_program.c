/*
 * IR_program.c
 *
 *  Created on: Sep 12, 2022
 *      Author: ziad
 */
#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../../01-LIB/03-ERROR_STATUS/ERROR_STATUS.h"

#include"../../02-MCAL/01-RCC/RCC_interface.h"
#include"../../02-MCAL/02-GPIO/GPIO_interface.h"
#include"../../02-MCAL/03-SYSTICK/SYSTICK_interface.h"
#include"../../02-MCAL/04-NVIC/NVIC_interface.h"
#include"../../02-MCAL/05-EXTI/EXTI_interface.h"

#include"IR_interface.h"

volatile u16 IRframe[50] = {0};
volatile u8  IRframeCounter = 0;
volatile u8  data;
volatile u8 initFlag =0 ;
void(*IR_CBFunc)(void);

u8 IR_getData(void){return data ;}
void IR_setCBFunc( void(*ptr)(void) ){
	IR_CBFunc = ptr ;
}
void IR_getFrame(void){

	if(initFlag==0){
		SYSTICK_voidAsychronousSingleSecondDelay(IR_saveData);
		initFlag =1 ;
	}
	else{
		IRframe[IRframeCounter] = SYSTICK_u32GetElapsedTime();
		SYSTICK_voidAsychronousSingleSecondDelay(IR_saveData);
		IRframeCounter++;
	}
}

void IR_saveData (void ){
	if(IRframe[0] >= 12000 && IRframe[0] <= 14000){
		for(u8 i=0 ; i<8 ; i++){
			if(IRframe[17+i] >= 1000 && IRframe[17+i] <= 1200)
			{
				CLR_BIT(data, i);
			}
			else
			{
				SET_BIT(data, i);
			}
		}
	}
	initFlag = 0;
	IRframe[0] = 0;
	IRframeCounter=0;
	IR_CBFunc();

}
