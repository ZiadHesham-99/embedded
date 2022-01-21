/*
 * Timer_prg.c
 *
 *  Created on: Oct 29, 2021
 *      Author: DELL
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO_DRIVER/DIO_int.h"
#include "Timer_cfg.h"
#include "Timer_reg.h"
#include "Timer_int.h"

void TIMER_vidInit(u8 Copy_u8Timertype)
{
	if(Copy_u8Timertype==TIMER_0)
	{
		#if TIMER0_MODE == T0_NORMAL
		/*Set Normal Mode*/
		TCCR0&=CLR_MASK_M;
		TCCR0|=T0_NORMAL_VAL;
		#elif TIMER0_MODE == T0_CTC
		/*CTC*/
		TCCR0&=CLR_MASK_M;
		TCCR0|=T0_CTC_VAL;
		#elif TIMER0_MODE == T0_FAST_PWM
		/*FAST_PWM*/
		TCCR0&=CLR_MASK_M;
		TCCR0|=T0_FAST_PWM_VAL;
		#elif TIMER0_MODE == T0_PCORRECT_PWM
		/*Phase Correct PWM*/
		TCCR0&=CLR_MASK_M;
		TCCR0|=T0_PCORRECT_PWM_VAL;
		#endif
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		#if TIMER1_MODE	==T1_NORMAL
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		#elif TIMER1_MODE	==	T1_PCORRECT_PWM_8bit
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=1;
		#elif TIMER1_MODE	==	T1_PCORRECT_PWM_9bit
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=2;
		#elif TIMER1_MODE	==	T1_PCORRECT_PWM_10bit
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=3;
		#elif TIMER1_MODE	==	T1_CTC
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1B|=8;
		#elif TIMER1_MODE	==	T1_FAST_PWM_8bit
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=1;
		TCCR1B|=8;
		#elif TIMER1_MODE	==	T1_FAST_PWM_9bit
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=2;
		TCCR1B|=8;
		#elif TIMER1_MODE	==	T1_FAST_PWM_10bit
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=3;
		TCCR1B|=8;
		#elif TIMER1_MODE	==	T1_PFCORRECT_PWM_TOP_ICR
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1B|=16;
		#elif TIMER1_MODE	==	T1_PFCORRECT_PWM_TOP_OCRA
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=1;
		TCCR1B|=16;
		#elif TIMER1_MODE	==	T1_PCORRECT_PWM_TOP_ICR
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=2;
		TCCR1B|=16;
		#elif TIMER1_MODE	==	T1_PCORRECT_PWM_TOP_OCRA
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=3;
		TCCR1B|=16;
		#elif TIMER1_MODE	==	T1_CTC_TOP_ICR
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1B|=24;
		#elif TIMER1_MODE	==	T1_FAST_PWM_ICR
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=2;
		TCCR1B|=24;
		#elif TIMER1_MODE	==	T1_FAST_PWM_OCRA
		TCCR1A&=CLR_MASK_MA1;
		TCCR1B&=CLR_MASK_MB1;
		TCCR1A|=3;
		TCCR1B|=24;
		#endif

	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		#if TIMER2_MODE == T2_NORMAL
		/*Set Normal Mode*/
		TCCR2&=CLR_MASK_M;
		TCCR2|=T2_NORMAL_VAL;
		#elif TIMER2_MODE == T2_CTC
		/*CTC*/
		TCCR2&=CLR_MASK_M;
		TCCR2|=T2_CTC_VAL;
		#elif TIMER2_MODE == T2_FAST_PWM
		/*FAST_PWM*/
		TCCR2&=CLR_MASK_M;
		TCCR2|=T2_FAST_PWM_VAL;;
		#elif TIMER2_MODE == T2_PCORRECT_PWM
		/*Phase Correct PWM*/
		TCCR2&=CLR_MASK_M;
		TCCR2|=T2_PCORRECT_PWM_VAL;
		#endif

	}
}

void TIMER_voidReset(u8 Copy_u8Timertype)
{
	if(Copy_u8Timertype==TIMER_0)
	{
		TCNT0=0;
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		TCNT1=0;
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		TCNT2=0;
	}
}

u16	TIMER_u16GetValue(u8 Copy_u8Timertype)
{
	u16 Local_TicksVal=0;
	if(Copy_u8Timertype==TIMER_0)
	{
		Local_TicksVal=TCNT0;
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		Local_TicksVal=TCNT1;
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		Local_TicksVal=TCNT2;
	}
	return Local_TicksVal;
}

void TIMER_vidClkSlct(u8 Copy_u8Timertype,u8 Copy_u8Prescaler)
{

	if(Copy_u8Timertype==TIMER_0)
	{
		TCCR0 &=CLR_MASK_PS;
		TCCR0|=Copy_u8Prescaler;
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		TCCR1B &=CLR_MASK_PS;
		TCCR1B|=Copy_u8Prescaler;

	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		TCCR2 &=CLR_MASK_PS;
		TCCR2|=Copy_u8Prescaler;
	}

}

void TIMER_vidCOM(u8 Copy_u8Timertype,u8 Copy_u8TimerMode,u8 Copy_u8COMMode)
{
	if(Copy_u8Timertype==TIMER_0)
	{
		DIO_U8_SetPinDir(PORT_B,PIN_3,HIGH);
		if(Copy_u8TimerMode==T0_FAST_PWM)
		{
			switch(Copy_u8COMMode)
			{
			case SET_TOP:
				TCCR0&=CLR_MASK_COM;
				TCCR0|=T0_SET_TOP_VAL;
				break;
			case CLR_TOP:
				TCCR0&=CLR_MASK_COM;
				TCCR0|=T0_CLR_TOP_VAL;
				break;
			}
		}
		else if(Copy_u8TimerMode==T0_PCORRECT_PWM)
		{
			DIO_U8_SetPinDir(PORT_B,PIN_3,HIGH);
			switch(Copy_u8COMMode)
			{
			case INVERTING:
				TCCR0&=CLR_MASK_COM;
				TCCR0|=T0_INVERTING_VAL;
				break;
			case NON_INVERTING:
				TCCR0&=CLR_MASK_COM;
				TCCR0|=T0_NON_INVERTING_VAL;
				break;
			}
		}
	}
	else if(Copy_u8Timertype==TIMER_1_CHA)
	{
		DIO_U8_SetPinDir(PORT_D,PIN_5,HIGH);
		if((Copy_u8TimerMode==T1_FAST_PWM_OCRA)||(Copy_u8TimerMode==T1_FAST_PWM_8bit)||(Copy_u8TimerMode==T1_FAST_PWM_9bit)||(Copy_u8TimerMode==T1_FAST_PWM_10bit)||(Copy_u8TimerMode==T1_FAST_PWM_ICR))
			{
				switch(Copy_u8COMMode)
				{
				case T1_SET_TOP_ChannelA:
					TCCR1A&=CLR_MASK_COM_T1_CHA;
					TCCR1A|=128;
					break;
				case T1_CLR_TOP_ChannelA:
					TCCR1A&=CLR_MASK_COM_T1_CHA;
					TCCR1A|=192;
					break;
				}
			}
			else if((Copy_u8TimerMode==T1_PCORRECT_PWM_TOP_OCRA)||(Copy_u8TimerMode==T1_PCORRECT_PWM_TOP_ICR)||(Copy_u8TimerMode==T1_PCORRECT_PWM_8bit)||(Copy_u8TimerMode==T1_PCORRECT_PWM_9bit)||(Copy_u8TimerMode==T1_PCORRECT_PWM_10bit)||(Copy_u8TimerMode==T1_PFCORRECT_PWM_TOP_ICR)||(Copy_u8TimerMode==T1_PFCORRECT_PWM_TOP_OCRA))
			{
				DIO_U8_SetPinDir(PORT_B,PIN_3,HIGH);
				switch(Copy_u8COMMode)
				{
				case T1_INVERTING_ChannelA:
					TCCR1A&=CLR_MASK_COM_T1_CHA;
					TCCR1A|=192;
					break;
				case T1_NON_INVERTING_ChannelA:
					TCCR1A&=CLR_MASK_COM_T1_CHA;
					TCCR1A|=128;
					break;
				}
			}
	}
	else if(Copy_u8Timertype==TIMER_1_CHB)
	{
		DIO_U8_SetPinDir(PORT_D,PIN_4,HIGH);
		if((Copy_u8TimerMode==T1_FAST_PWM_OCRA)||(Copy_u8TimerMode==T1_FAST_PWM_8bit)||(Copy_u8TimerMode==T1_FAST_PWM_9bit)||(Copy_u8TimerMode==T1_FAST_PWM_10bit)||(Copy_u8TimerMode==T1_FAST_PWM_ICR))
			{
				switch(Copy_u8COMMode)
				{
				case T1_SET_TOP_ChannelB:
					TCCR1B&=CLR_MASK_COM_T1_CHB;
					TCCR1B|=32;
					break;
				case T1_CLR_TOP_ChannelB:
					TCCR1B&=CLR_MASK_COM_T1_CHB;
					TCCR1B|=48;
					break;
				}
			}
			else if((Copy_u8TimerMode==T1_PCORRECT_PWM_TOP_OCRA)||(Copy_u8TimerMode==T1_PCORRECT_PWM_TOP_ICR)||(Copy_u8TimerMode==T1_PCORRECT_PWM_8bit)||(Copy_u8TimerMode==T1_PCORRECT_PWM_9bit)||(Copy_u8TimerMode==T1_PCORRECT_PWM_10bit)||(Copy_u8TimerMode==T1_PFCORRECT_PWM_TOP_ICR)||(Copy_u8TimerMode==T1_PFCORRECT_PWM_TOP_OCRA))
			{
				DIO_U8_SetPinDir(PORT_B,PIN_3,HIGH);
				switch(Copy_u8COMMode)
				{
				case T1_INVERTING_ChannelB:
					TCCR1B&=CLR_MASK_COM_T1_CHB;
					TCCR1B|=48;
					break;
				case T1_NON_INVERTING_ChannelB:
					TCCR1B&=CLR_MASK_COM_T1_CHB;
					TCCR1B|=32;
					break;
				}
			}
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		if(Copy_u8TimerMode==T2_FAST_PWM)
		{
			DIO_U8_SetPinDir(PORT_D,PIN_7,HIGH);
			switch(Copy_u8COMMode)
			{
			case SET_TOP:
				TCCR2&=CLR_MASK_COM;
				TCCR2|=T2_SET_TOP_VAL;
				break;
			case CLR_TOP:
				TCCR2&=CLR_MASK_COM;
				TCCR2|=T2_CLR_TOP_VAL;
				break;
			}
		}
		else if(Copy_u8TimerMode==T2_PCORRECT_PWM)
		{
			DIO_U8_SetPinDir(PORT_D,PIN_7,HIGH);
			switch(Copy_u8COMMode)
			{
			case INVERTING:
				TCCR2&=CLR_MASK_COM;
				TCCR2|=T2_INVERTING_VAL;
				break;
			case NON_INVERTING:
				TCCR2&=CLR_MASK_COM;
				TCCR2|=T2_NON_INVERTING_VAL;
				break;
			}
		}
	}

}
void TIMER_vidSetPreload(u8 Copy_u8Timertype,u16 Copy_u16Preload)
{

	if(Copy_u8Timertype==TIMER_0)
	{
		TCNT0=Copy_u16Preload;
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		TCNT1=Copy_u16Preload;
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		TCNT2=Copy_u16Preload;
	}
}

void TIMER_vidSetOCR(u8 Copy_u8Timertype,u8 Copy_u8OCR)
{

	if(Copy_u8Timertype==TIMER_0)
	{
		OCR0=Copy_u8OCR;
	}
	else if(Copy_u8Timertype==TIMER_1_CHA)
	{
		OCR1A=Copy_u8OCR;
	}
	else if(Copy_u8Timertype==TIMER_1_CHB)
	{
		OCR1B=Copy_u8OCR;
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		OCR2=Copy_u8OCR;
	}
}
void TIMER1_vidSetICR(u16 Copy_u16ICR)
{
	ICR1=Copy_u16ICR;
}
void TIMER_vidTovfIrqEnable(u8 Copy_u8Timertype)
{

	if(Copy_u8Timertype==TIMER_0)
	{
		SET_BIT(TIMSK,0);
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		SET_BIT(TIMSK,2);
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		SET_BIT(TIMSK,6);
	}

}

void TIMER_vidTovfIrqDisable(u8 Copy_u8Timertype)
{

	if(Copy_u8Timertype==TIMER_0)
	{
		CLR_BIT(TIMSK,0);
	}
	else if(Copy_u8Timertype==TIMER_1)
	{
		CLR_BIT(TIMSK,2);
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		CLR_BIT(TIMSK,6);
	}

}

void TIMER_vidCtcIrqEnable(u8 Copy_u8Timertype)
{

	if(Copy_u8Timertype==TIMER_0)
	{
		SET_BIT(TIMSK,1);
	}
	else if(Copy_u8Timertype==TIMER_1_CHA)
	{
		SET_BIT(TIMSK,4);
	}
	else if(Copy_u8Timertype==TIMER_1_CHB)
	{
		SET_BIT(TIMSK,3);
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		SET_BIT(TIMSK,7);

	}

}

void TIMER_vidCtcIrqDisable(u8 Copy_u8Timertype)
{
	if(Copy_u8Timertype==TIMER_0)
	{
		CLR_BIT(TIMSK,1);
	}
	else if(Copy_u8Timertype==TIMER_1_CHA)
	{
		CLR_BIT(TIMSK,4);
	}
	else if(Copy_u8Timertype==TIMER_1_CHB)
	{
		CLR_BIT(TIMSK,3);
	}
	else if(Copy_u8Timertype==TIMER_2)
	{
		CLR_BIT(TIMSK,7);
	}
}
