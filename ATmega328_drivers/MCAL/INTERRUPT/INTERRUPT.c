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
/*Enable Global interrupt (bit I)*/
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

/*takes the interrupt number (INT_0 or INT_1 and enables global interrupt and the inturrupt number )*/
u8 INTERRUPT_u8Enable(u8 Copy_u8IntNo)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0:SREG_reg |=(1<<7);EIMSK_reg |=(1<<0) ; break;
	case INT_1:SREG_reg |=(1<<7);EIMSK_reg |=(1<<1) ; break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}

/*takes the interrupt number and disable it */
u8 INTERRUPT_u8Disable(u8 Copy_u8IntNo)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0: EIMSK_reg &= ~(1<<0) ; break;
	case INT_1: EIMSK_reg &= ~(1<<1) ; break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}

/*takes interrupt number and trigger type */

u8 INTERRUPT_u8SenseControl(u8 Copy_u8IntNo ,u8 Copy_u8Trigger)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0:
		switch(Copy_u8Trigger)
		{
		case LOW_LEVEL :  EICRA_reg &= ~(1<<0) ; EICRA_reg &= ~(1<<1)  ; break;
		case ANY_CHANGE:  EICRA_reg |=(1<<0)   ; EICRA_reg &= ~(1<<1) ; break;
		case FALLING_EDGE :  EICRA_reg &= ~(1<<0) ;  EICRA_reg |=(1<<1)    ; break;
		case RISING_EDGE :  EICRA_reg |=(1<<0) ; EICRA_reg |=(1<<1)  ; break;
		default: Local_u8ErrStatus = RT_NOK;break;
		};break;
	case INT_1:
		switch(Copy_u8Trigger)
		{
		case LOW_LEVEL :  EICRA_reg &= ~(1<<2) ; EICRA_reg &= ~(1<<3)  ; break;
		case ANY_CHANGE:  EICRA_reg |=(1<<2)   ; EICRA_reg &= ~(1<<3) ; break;
		case FALLING_EDGE :  EICRA_reg &= ~(1<<2) ;  EICRA_reg |=(1<<3)    ; break;
		case RISING_EDGE :  EICRA_reg |=(1<<2) ; EICRA_reg |=(1<<3)  ; break;
		default: Local_u8ErrStatus = RT_NOK;break;
		};break;
    default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}

/*retuen in the argument address the value interrupt flag of the argument interrupt number */

u8 INTERRUPT_u8GetInterruptFlag(u8 Copy_u8IntNo ,u8 * Copy_u8pVal)
{
	u8 Local_u8ErrStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT_0: * Copy_u8pVal = (((EIFR_reg) >> (0)) & 0x01) ; break;
	case INT_1:* Copy_u8pVal = (((EIFR_reg) >> (1)) & 0x01) ; break;
	default:Local_u8ErrStatus = RT_NOK;break;
	}
	return (Local_u8ErrStatus);
}
