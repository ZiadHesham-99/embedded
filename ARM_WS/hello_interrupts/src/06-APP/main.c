/*
 * main.c
 *
 *  Created on: Sep 3, 2022
 *      Author: ziad
 */
#include "../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"../02-MCAL/01-RCC/RCC_interface.h"
#include "../02-MCAL/02-GPIO/GPIO_interface.h"
#include"../02-MCAL/03-SYSTICK/SYSTICK_interface.h"
#include "../02-MCAL/04-NVIC/NVIC_interface.h"
#include"../02-MCAL/05-EXTI/EXTI_interface.h"

#include"../03-HAL/IR/IR_interface.h"

void func(void);
int main(void){
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(PERIPHRAL_GPIO_A);
	RCC_voidEnablePeripheralClock(PERIPHRAL_GPIO_B);
	GPIO_setPinMode();
	NVIC_voidInterruptEnable(7);
	NVIC_voidSoftwarePriority(7,0,0);
	IR_setCBFunc(func);
	EXTI_voidConfig(EXTI_PORT_A , EXTI_LINE_1 , EXTI_TRIGGER_FALLING);
	EXTI_setCallback(EXTI_LINE_1 , IR_getFrame);

	while(1){

	}


}
void func(void){
	volatile u8 temp ;
	temp = IR_getData();
	if(temp==69){

	}
}

