/*
 * TIMER_int.h
 *
 *  Created on: Nov 5, 2021
 *      Author: ziad
 */

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_

#define MODE_CLR_MSK  (u8) 0b10110111
#define PHASE_CRRCT_SET_MSK (u8)0b00001000
#define CTC_SET_MSK	(u8)0b01000000
#define FAST_PWM_SET_MSK (u8)0b01001000

#define CLK_CLR_MSK (u8) 0b11111000

typedef enum{
	TIMER0_CLK_SLCT_NO_CLK = 0,
	TIMER0_CLK_SLCT_NO_PRESCALER ,
	TIMER0_CLK_SLCT_8_PRE_SCALER ,
	TIMER0_CLK_SLCT_64_PRE_SCALER ,
	TIMER0_CLK_SLCT_256_PRE_SCALER ,
	TIMER0_CLK_SLCT_1024_PRE_SCALER ,
	TIMER0_CLK_SLCT_EXTERNAL_FALLING ,
	TIMER0_CLK_SLCT_EXTERNAL_RISING

}TIMER0_CLK_SLCT;


void TIMER0_vidInit(void);
void TIMER0vidClkSlct(TIMER0_CLK_SLCT CLK);
void TIMER0_vidStart(void);
void TIMER0_vidStop(void);
void TIMER0_vidSetPreload(u8 Copy_u8Preload);
void TIMER0_vidSetCTC(u8 Copy_u8CTC);
void TIMER0_vidTimerOverflowRqstEnbl(void);
void TIMER0_vidTimerOverflowRqstDisbl(void);
void TIMER0_vidTimerCtcRqstEnbl(void);
void TIMER0_vidTimerCtcRqstDisbl(void);
void TIMER0_vidSetPwmDutyCycle(u8 Copy_u8DutyCycle);
void Timer0_vidSetOvfCbf(void (*fptr)(void));
void TIMER0_vidSetCtcCbf(void (*fptr)(void));

#endif /* MCAL_TIMER_TIMER_INT_H_ */
