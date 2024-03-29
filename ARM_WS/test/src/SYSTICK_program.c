/*
 * SYSTICK_program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: ziad
 */

#include"BIT_MATH.h"
#include"STD_TYPPES.h"

#include"SYSTICK_private.h"
#include"SYSTICK_config.h"

void (*Systick_CBNotification) (void)  ;
void SYSTICK_voidInitialize(void){
	#if (CLK_SRC_SELECTION_AHB_DIV_BY_8 == 1)
	/*CLK SRC AHB / 8*/
	SYSTICK->CTRL.B.ClockSrc = 0;

	#else
	/*CLK SRC AHB */
	SYSTICK->CTRL.B.ClockSrc = 1;
	#endif
}

void SYSTICK_voidsychronousDelay(u32 local_u32Ticks){
	/*inserting ticks number */
	SYSTICK->LOAD.B.RELOAD = local_u32Ticks;
	/*Enable systick*/
	SYSTICK->CTRL.B.Enable=1;
	/*poll untill the value ot tisck is reached*/
	while(!SYSTICK->CTRL.B.CountFlag);
}
void SYSTICK_voidAsychronousDelay(u32 local_u32Ticks, void (*ptr) (void)){
	/*inserting ticks number */
	SYSTICK->LOAD.B.RELOAD = local_u32Ticks;
	/*Enable interrupt */
	SYSTICK->CTRL.B.TickInt =1;
	/*saving function pointer in a global variable to be accessed by ISR*/
	Systick_CBNotification = ptr ;
	/*Enable systick*/
	SYSTICK->CTRL.B.Enable=1;
}
void SYSTICK_voidStop(void){
	/*Disable systick*/
	SYSTICK->CTRL.B.Enable=1;
}

ISR(){
	Systick_CBNotification();
}
