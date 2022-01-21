/*
 * INTERRUPT.c
 *
 *  Created on: Oct 10, 2021
 *      Author: ziad
 */
#include "../../LIB/stdtypes.h"
#include"INTERRUPT_reg.h"
#include "INTERRUPT_int.h"
#include "../../LIB/bitmath.h"
#define RT_OK (u8) 0
#define RT_NOK (u8) 1
u8 INTERRUPT_u8GlobalInterruptControl(u8 Copy_u8Status)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8Status)
	{
	case ENABLE: SREG_reg |=(1<<7);break;
	case DISABLE: SREG_reg &= ~(1<<7);break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);

}
u8 INTERRUPT_u8Enable(u8 Copy_u8IntNo)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0:SREG_reg |=(1<<7);GICR_reg |=(1<<6) ; break;
	case INT_1:SREG_reg |=(1<<7);GICR_reg |=(1<<7) ; break;
	case INT_2:SREG_reg |=(1<<7);GICR_reg |=(1<<5) ; break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}
u8 INTERRUPT_u8Disable(u8 Copy_u8IntNo)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0: GICR_reg &= ~(1<<6) ; break;
	case INT_1: GICR_reg &= ~(1<<7) ; break;
	case INT_2: GICR_reg &= ~(1<<5) ; break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}
u8 INTERRUPT_u8SenseControl(u8 Copy_u8IntNo ,u8 Copy_u8Trigger)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0:
		switch(Copy_u8Trigger)
		{
		case LOW_LEVEL :  MCUCR_reg &= ~(1<<0) ; MCUCR_reg &= ~(1<<1)  ; break;
		case ANY_CHANGE:  MCUCR_reg |=(1<<0)   ; MCUCR_reg &= ~(1<<1) ; break;
		case FALLING_EDGE :  MCUCR_reg &= ~(1<<0) ;  MCUCR_reg |=(1<<1)    ; break;
		case RISING_EDGE :  MCUCR_reg |=(1<<0) ; MCUCR_reg |=(1<<1)  ; break;
		default: Local_u8ErrStatus = RT_NOK;break;
		};break;
	case INT_1:
		switch(Copy_u8Trigger)
		{
		case LOW_LEVEL :  MCUCR_reg &= ~(1<<2) ; MCUCR_reg &= ~(1<<3)  ; break;
		case ANY_CHANGE:  MCUCR_reg |=(1<<2)   ; MCUCR_reg &= ~(1<<3) ; break;
		case FALLING_EDGE :  MCUCR_reg &= ~(1<<2) ;  MCUCR_reg |=(1<<3)    ; break;
		case RISING_EDGE :  MCUCR_reg |=(1<<2) ; MCUCR_reg |=(1<<3)  ; break;
		default: Local_u8ErrStatus = RT_NOK;break;
		};break;
    case INT_2:
    	switch(Copy_u8Trigger)
    	{
    	case FALLING_EDGE: MCUCSR_reg &= ~(1<<6); break;
    	case RISING_EDGE : MCUCSR_reg |=(1<<6); break;
    	default : Local_u8ErrStatus = RT_NOK;break;
    	};break;
    default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}
u8 INTERRUPT_u8GetInterruptFlag(u8 Copy_u8IntNo ,u8 * Copy_u8pVal)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0: * Copy_u8pVal = (((GIFR_reg) >> (6)) & 0x01) ; break;
	case INT_1:* Copy_u8pVal = (((GIFR_reg) >> (7)) & 0x01) ; break;
	case INT_2: * Copy_u8pVal = (((GIFR_reg) >> (5)) & 0x01); break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}
