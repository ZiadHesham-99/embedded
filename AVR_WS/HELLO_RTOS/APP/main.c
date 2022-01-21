/*
 * main.c
 *
 *  Created on: Dec 17, 2021
 *      Author: ziad
 */
#include "../LIB/bitmath.h"
#include "../LIB/stdtypes.h"
#include"sched.h"
#include "../MCAL/TIMER/TIMER_int.h"
Task tasks[TASK_MAX_NO];
void LED_1(void)
{
	/*toggle Led 1*/
}
void LED_2(void)
{
	/*toggle led 2*/
}
void sched_init(void)
{
	TIMER0_vidInit();
	TIMER0_vidSetPreload(1024);
}
void sched_start (void)
{
	TIMER0vidClkSlct(TIMER0_CLK_SLCT_1024_PRE_SCALER);
}


