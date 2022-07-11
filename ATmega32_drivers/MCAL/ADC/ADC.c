/*
 * ADC.c
 *
 *  Created on: Oct 15, 2021
 *      Author: ziad
 */
#include "../../LIB/stdtypes.h"
#include "../../LIB/bitmath.h"
#include "AVR/delay.h"
#include "ADC_int.h"
#include "AVR/interrupt.h"
u8 ADC_init(VREF_STATE_ENUM Copy_EVrefState , LEFT_ADJUST_CTRL Copy_LAstate)
{
	u8 Local_u8ErrStatus = RT_OK;
	u8 Temp = ADCSRA_REG ;
	Temp = ADC_ADCSRA_DEFAULT ;
	ADCSRA_REG = Temp ;
	switch (Copy_EVrefState)
	{
	case 0: Temp = ADMUX_REG; Temp &= ADC_VREF_CLR_MSK; ADMUX_REG = Temp; break;
	case 1: Temp = ADMUX_REG; Temp &= ADC_VREF_CLR_MSK;Temp |= 0b01000000 ; ADMUX_REG = Temp; break;
	case 2: Temp = ADMUX_REG; Temp &= ADC_VREF_CLR_MSK; Temp |= 0b11000000 ; ADMUX_REG = Temp; break;
	default:Local_u8ErrStatus = RT_NOK; break;
	}
	switch (Copy_LAstate)
	{
	 case 0:CLR_BIT(ADMUX_REG,5);break;
	 case 1:SET_BIT(ADMUX_REG,5);break;
	 default: Local_u8ErrStatus = RT_NOK; break;
	}
	return(Local_u8ErrStatus);
}


u16 ADC_GetDigitalRead(ADC_INPUT_CHANNEL ADC_CHANNEL )
{
	u16 DigitalRead  ;
	u8 Temp = ADMUX_REG ;
	Temp &= ADC_CHANNEL_CLR_MSK ;
	Temp |= ADC_CHANNEL ;
	ADMUX_REG = Temp ;
	SET_BIT(ADCSRA_REG,6);
	while(GET_BIT(ADCSRA_REG,4)!=1);
	SET_BIT(ADCSRA_REG,4);
	DigitalRead = * ADC_REG;
	return(DigitalRead) ;
}
void ADC_PrescalerMode(ADC_PRESCALER_SELECT Select )
{

	u8 Temp = ADCSRA_REG ;
	Temp &= ADC_PRESCLR_CLR_MSK ;
	Temp |= Select ;
}
void ADC_AutoTriggerCTRL (ADC_AUTO_TRIGGER_SELECT Select)
{
	SET_BIT(ADCSRA_REG , 5);
	u8 Temp = SFIOR_REG ;
	Temp &=ADC_AUTOTRIG_CLR_MSK;
	Temp |= Select;
	SFIOR_REG = Temp ;
}
/*
 * Enable Global INTERRUPT GIE first !
 */
void ADC_InterruptEnable(void)
{
	SET_BIT(ADCSRA_REG , 3);
}
void(*cbf)(void);
void ADC_SetCBF (void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		cbf = Fptr;
	}

}
ISR(ADC_vect)
{
	if(cbf != NULL)
	{cbf();}
}

