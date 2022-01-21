/*
 * Timer_cfg.h
 *
 *  Created on: Oct 29, 2021
 *      Author: DELL
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_


/*TIMER 0 MODES*/
#define T0_NORMAL			0
#define T0_CTC				1
#define T0_FAST_PWM			2
#define T0_PCORRECT_PWM		3


/*TIMER 1 MODES*/
#define T1_NORMAL						0
#define T1_PCORRECT_PWM_8bit			1
#define T1_PCORRECT_PWM_9bit			2
#define T1_PCORRECT_PWM_10bit			3
#define T1_CTC							4
#define T1_FAST_PWM_8bit				5
#define T1_FAST_PWM_9bit				6
#define T1_FAST_PWM_10bit				7
#define T1_PFCORRECT_PWM_TOP_ICR		8
#define T1_PFCORRECT_PWM_TOP_OCRA		9
#define T1_PCORRECT_PWM_TOP_ICR			10
#define T1_PCORRECT_PWM_TOP_OCRA		11
#define T1_CTC_TOP_ICR					12
#define T1_FAST_PWM_ICR					14
#define T1_FAST_PWM_OCRA				15


/*TIMER 2 MODES*/
#define T2_NORMAL			0
#define T2_CTC				1
#define T2_FAST_PWM			2
#define T2_PCORRECT_PWM		3


/*Select TIMERS MODE*/
#define TIMER0_MODE		T0_NORMAL
#define TIMER1_MODE		T1_FAST_PWM_ICR
#define TIMER2_MODE		T2_NORMAL


#endif /* TIMER_CFG_H_ */
