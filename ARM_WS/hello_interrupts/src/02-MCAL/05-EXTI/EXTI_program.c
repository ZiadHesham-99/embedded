/*
 * EXTI_program.c
 *
 *  Created on: Sep 5, 2022
 *      Author: ziad
 */

#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"

EXTI_callBack EXTI_ISR[16] ={NULL} ;

void EXTI_voidConfig (EXTIPort_t EXTIPort, EXTILine_t EXTILine , EXTI_TRIGGER_t EXTISenseMode) {


	/*set the specific channel to the needed port */
	u32 volatile temp =0;
	temp = SYSCFG->EXTICR[EXTILine/4] ;
	temp &= ~(0b1111<< ((EXTILine%4)*4)  );
	temp |= ( EXTIPort << ((EXTILine%4)*4) );
	SYSCFG->EXTICR[EXTILine/4] = temp ;

	/*configuring sense control setting*/
	if(EXTISenseMode ==0 || EXTISenseMode==2 ){
		EXTI->RTSR = (1<< EXTILine);
	}
	if(EXTISenseMode ==1 || EXTISenseMode==2){
		EXTI->FTSR = (1<< EXTILine);
	}
	/*enable interrupts on the specific line */
		EXTI->IMR = (1<<EXTILine);
}
void EXTI_setCallback(EXTILine_t EXTILine , void (*ptr)(void) ){
	EXTI_ISR[EXTILine] = ptr ;
}

void EXTI0_IRQHandler()
{
	EXTI_ISR[0]();
	EXTI->PR = (1<<0);

}
void EXTI1_IRQHandler()
{
	EXTI_ISR[1]();
	EXTI->PR = (1<<1);
}
void EXTI2_IRQHandler()
{
	EXTI_ISR[2]();
	EXTI->PR = (1<<2);
}
void EXTI3_IRQHandler()
{
	EXTI_ISR[3]();
	EXTI->PR = (1<<3);
}
void EXTI4_IRQHandler()
{
	EXTI_ISR[4]();
	EXTI->PR = (1<<4);
}
void EXTI5_IRQHandler()
{
	EXTI_ISR[5]();
	EXTI->PR = (1<<5);
}
void EXTI6_IRQHandler()
{
	EXTI_ISR[6]();
	EXTI->PR = (1<<6);
}
void EXTI7_IRQHandler()
{
	EXTI_ISR[7]();
	EXTI->PR = (1<<7);
}
