/*
 * Timer_int.h
 *
 *  Created on: Oct 29, 2021
 *      Author: DELL
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#define TIMER_0				0

#define TIMER_1				1
#define	TIMER_1_CHA			3
#define	TIMER_1_CHB			4

#define	TIMER_2				2

/*TIMER 0*/
#define T0_NO_CLKSOURCE			0
#define T0_NO_PRESCALER			1
#define T0_PRESCALER_8			2
#define T0_PRESCALER_64			3
#define T0_PRESCALER_256		4
#define T0_PRESCALER_1024		5
#define T0_EXTCLK_FALLING		6
#define T0_EXTCLK_RISING		7

#define T0_NORMAL_VAL			0
#define T0_CTC_VAL				8
#define T0_FAST_PWM_VAL			72
#define T0_PCORRECT_PWM_VAL		64

#define T0_SET_TOP_VAL			32
#define T0_CLR_TOP_VAL			48
#define T0_INVERTING_VAL		48
#define T0_NON_INVERTING_VAL	32

/*TIMER 1*/
#define T1_NO_CLKSOURCE			0
#define T1_NO_PRESCALER			1
#define T1_PRESCALER_8			2
#define T1_PRESCALER_64			3
#define T1_PRESCALER_256		4
#define T1_PRESCALER_1024		5
#define T1_EXTCLK_FALLING		6
#define T1_EXTCLK_RISING		7

#define T1_SET_TOP_ChannelA				1
#define T1_SET_TOP_ChannelB				11
#define	T1_CLR_TOP_ChannelA				2
#define T1_CLR_TOP_ChannelB				22

#define T1_INVERTING_ChannelA			1
#define T1_INVERTING_ChannelB			11
#define	T1_NON_INVERTING_ChannelA		2
#define	T1_NON_INVERTING_ChannelB		22


/*TIMER 2*/
#define T2_NO_CLKSOURCE			0
#define T2_NO_PRESCALER			1
#define T2_PRESCALER_8			2
#define T2_PRESCALER_32			3
#define T2_PRESCALER_64			4
#define T2_PRESCALER_128		5
#define T2_PRESCALER_256		6
#define T2_PRESCALER_1024		7

#define T2_NORMAL_VAL			0
#define T2_CTC_VAL				8
#define T2_FAST_PWM_VAL			72
#define T2_PCORRECT_PWM_VAL		64

#define T2_SET_TOP_VAL			32
#define T2_CLR_TOP_VAL			48
#define T2_INVERTING_VAL		48
#define T2_NON_INVERTING_VAL	32


#define SET_TOP				1
#define	CLR_TOP				0

#define INVERTING			1
#define	NON_INVERTING		0


#define CLR_MASK_M			0b10110111
#define CLR_MASK_COM		0b11001111
#define CLR_MASK_PS			0b11111000
#define CLR_MASK_MA1		0b11111100
#define CLR_MASK_MB1		0b11100111
#define CLR_MASK_COM_T1_CHA	0b00111111
#define CLR_MASK_COM_T1_CHB	0b11001111


void TIMER_vidInit(u8 Copy_u8Timertype);
void TIMER_voidReset(u8 Copy_u8Timertype);
u16	TIMER_u16GetValue(u8 Copy_u8Timertype);
void TIMER_vidClkSlct(u8 Copy_u8Timertype , u8 Copy_u8Prescaler);
void TIMER_vidCOM(u8 Copy_u8Timertype,u8 Copy_u8TimerMode,u8 Copy_u8COMMode);
void TIMER_vidSetPreload(u8 Copy_u8Timertype ,u16 Copy_u16Preload);
void TIMER_vidSetOCR(u8 Copy_u8Timertype,u8 Copy_u8OCR);
void TIMER1_vidSetICR(u16 Copy_u16ICR);
void TIMER_vidTovfIrqEnable(u8 Copy_u8Timertype);
void TIMER_vidTovfIrqDisable(u8 Copy_u8Timertype);
void TIMER_vidCtcIrqEnable(u8 Copy_u8Timertype);
void TIMER_vidCtcIrqDisable(u8 Copy_u8Timertype);


#endif /* TIMER_INT_H_ */
