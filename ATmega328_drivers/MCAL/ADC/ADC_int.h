/*
 * ADC_int.h
 *
 *  Created on: Oct 15, 2021
 *      Author: ziad
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define RT_OK (u8) 0
#define RT_NOK (u8) 1
#define NULL ((void*)0)

#define ADC_REG ((volatile u16 *)0x78)

#define ADCSRA_REG (*(volatile u8 *)0x7A)
#define ADCSRB_REG (*(volatile u8 *)0x7B)
#define ADMUX_REG  (*(volatile u8 *)0x7C)
#define SFIOR_REG (*(volatile u8 *)0x50)
#define ADCL_REG  (*(volatile u8 *)0x78)
#define ADCH_REG  (*(volatile u8 *)0x79)

#define ADC_VREF_CLR_MSK (u8) 0b00111111
#define ADC_ADCSRA_DEFAULT (u8) 0b10000110
#define ADC_CHANNEL_CLR_MSK (u8) 0b11100000
#define ADC_PRESCLR_CLR_MSK (u8) 0b11111000
#define ADC_AUTOTRIG_CLR_MSK (u8) 0b10111000

typedef enum {
	VREF_STATE_ENUM_EXTERNALVREF = 0 ,
	VREF_STATE_ENUM_VCC              ,
	VREF_STATE_ENUM_INTERNAL_1_1
}VREF_STATE_ENUM ;

typedef enum {
	LEFT_ADJUST_CTRL_DISABLE = 0 ,
	LEFT_ADJUST_CTRL_ENABLE =1  ,
}LEFT_ADJUST_CTRL ;

typedef enum {
	ADC_INPUT_CHANNEL_ADC0 =0 ,
	ADC_INPUT_CHANNEL_ADC1 =1  ,
	ADC_INPUT_CHANNEL_ADC2 =2  ,
	ADC_INPUT_CHANNEL_ADC3 =3  ,
	ADC_INPUT_CHANNEL_ADC4 =4  ,
	ADC_INPUT_CHANNEL_ADC5 =5  ,
	ADC_INPUT_CHANNEL_ADC6 =6  ,
	//ADC_INPUT_CHANNEL_ADC7 =7  ,
}ADC_INPUT_CHANNEL ;

typedef enum {
	ADC_PRESCALER_SELECT_2 = 0 ,
	ADC_PRESCALER_SELECT_4 = 2 ,
	ADC_PRESCALER_SELECT_8 = 3 ,
	ADC_PRESCALER_SELECT_16 =4 ,
	ADC_PRESCALER_SELECT_32 =5 ,
	ADC_PRESCALER_SELECT_64 =6 ,
	ADC_PRESCALER_SELECT_128=7 ,
}ADC_PRESCALER_SELECT;

typedef enum {
	ADC_AUTO_TRIGGER_SELECT_FREE_RUNNING= 0 ,
	ADC_AUTO_TRIGGER_SELECT_ANALOG_COMPARATOR= 1 ,
	ADC_AUTO_TRIGGER_SELECT_EXT_INT0= 2 ,
	ADC_AUTO_TRIGGER_SELECT_TIMER_0_COMPARE_MATCH= 3 ,
	ADC_AUTO_TRIGGER_SELECT_TIMER_0_OVERFLOW= 4 ,
	ADC_AUTO_TRIGGER_SELECT_TIMER_1_COMPARE_MATCH_B= 5 ,
	ADC_AUTO_TRIGGER_SELECT_TIMER_1_PIN_CHANGE_INT= 6 ,
}ADC_AUTO_TRIGGER_SELECT;

u8 ADC_init(VREF_STATE_ENUM Copy_EState ,  LEFT_ADJUST_CTRL Copy_LAstate) ;
u16 ADC_GetDigitalRead(ADC_INPUT_CHANNEL ADC_CHANNEL );
void ADC_PrescalerMode(ADC_PRESCALER_SELECT Select );
void ADC_AutoTriggerCTRL (ADC_AUTO_TRIGGER_SELECT Select);
void ADC_InterruptEnable(void);
void ADC_SetCBF (void (*Fptr)(void));

#endif /* MCAL_ADC_ADC_INT_H_ */
