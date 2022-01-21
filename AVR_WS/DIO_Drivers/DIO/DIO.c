/*
 * DIO.c
 *
 *  Created on: Sep 23, 2021
 *      Author: ziad
 */
#include "stdtypes.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#define RT_OK (u8) 0
#define RT_NOK (u8) 1
#define NULL ((void*)0)
// Set direction func for port and pin
u8 DIO_u8SetPortDir(u8 Copy_u8PortNo , u8 Copy_u8Dir)
{
	u8 Local_u8ErrStatus = RT_OK;

	if(Copy_u8Dir != INPUT && Copy_u8Dir != OUTPUT_PORT )
	{
		Local_u8ErrStatus = RT_NOK;
	}
	else{
		switch( Copy_u8PortNo )
		{
			case PORT_A: DDRA_REG = Copy_u8Dir; break;
			case PORT_B: DDRB_REG = Copy_u8Dir; break;
			case PORT_C: DDRC_REG = Copy_u8Dir; break;
			case PORT_D: DDRD_REG = Copy_u8Dir; break;
			default: Local_u8ErrStatus = RT_NOK;
		}
		}
		return (Local_u8ErrStatus);
}
u8 DIO_u8SetPinDir(u8 Copy_u8PortNo , u8 Copy_u8PinNo ,u8 Copy_u8Dir)
{
	u8 Local_u8ErrStatus = RT_OK;
	if(Copy_u8PortNo <= PORT_D && Copy_u8PinNo <= PIN_7)
	{
		if(Copy_u8Dir == INPUT)
		{
			switch(Copy_u8PortNo)
			{
			case PORT_A: CLR_BIT(DDRA_REG,Copy_u8PinNo); break;
			case PORT_B: CLR_BIT(DDRB_REG,Copy_u8PinNo); break;
			case PORT_C: CLR_BIT(DDRC_REG,Copy_u8PinNo); break;
			case PORT_D: CLR_BIT(DDRD_REG,Copy_u8PinNo); break;
			}
		}
		else if (Copy_u8Dir == OUTPUT)
		{
			switch(Copy_u8PortNo)
			{
    		case PORT_A: SET_BIT(DDRA_REG,Copy_u8PinNo); break;
            case PORT_B: SET_BIT(DDRB_REG,Copy_u8PinNo); break;
            case PORT_C: SET_BIT(DDRC_REG,Copy_u8PinNo); break;
            case PORT_D: SET_BIT(DDRD_REG,Copy_u8PinNo); break;
     		}
		}
		else{Local_u8ErrStatus = RT_NOK;}
	}
	else{Local_u8ErrStatus = RT_NOK;}
	return (Local_u8ErrStatus);
}

// SET func for port and pin

u8 DIO_u8SetPortVal(u8 Copy_u8PortNo , u8 Copy_u8Val)
{
	u8 Local_u8ErrStatus = RT_OK;
	if(Copy_u8Val == LOW || Copy_u8Val == HIGH_PORT)
	{
		switch( Copy_u8PortNo )
		{
			case PORT_A: PORTA_REG = Copy_u8Val; break;
		    case PORT_B: PORTB_REG = Copy_u8Val; break;
		    case PORT_C: PORTC_REG = Copy_u8Val; break;
		    case PORT_D: PORTD_REG = Copy_u8Val; break;
		    default: Local_u8ErrStatus = RT_NOK;
		}
	}
	else{Local_u8ErrStatus = RT_NOK;}

	return (Local_u8ErrStatus);

}

u8 DIO_u8SetPinVal(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 Copy_u8Val)
{
	u8 Local_u8ErrStatus = RT_OK;
	if(Copy_u8PortNo <= PORT_D && Copy_u8PinNo <= 7)
	{
		if(Copy_u8Val == LOW )
		{
            switch(Copy_u8PortNo)
            {
            case PORT_A: CLR_BIT(PORTA_REG,Copy_u8PinNo); break;
			case PORT_B: CLR_BIT(PORTB_REG,Copy_u8PinNo); break;
			case PORT_C: CLR_BIT(PORTC_REG,Copy_u8PinNo); break;
			case PORT_D: CLR_BIT(PORTD_REG,Copy_u8PinNo); break;
            }
		}
		else if ( Copy_u8Val == HIGH)
		{
			switch(Copy_u8PortNo)
		    {
            case PORT_A: SET_BIT(PORTA_REG,Copy_u8PinNo); break;
			case PORT_B: SET_BIT(PORTB_REG,Copy_u8PinNo); break;
			case PORT_C: SET_BIT(PORTC_REG,Copy_u8PinNo); break;
			case PORT_D: SET_BIT(PORTD_REG,Copy_u8PinNo); break;
			}

		}
		else{Local_u8ErrStatus = RT_NOK;}
	}
	else{Local_u8ErrStatus = RT_NOK;}
	return (Local_u8ErrStatus) ;
}


u8 DIO_u8GetPortVal(u8 Copy_u8PortNo , u8 * Copy_u8pVal)
{
	u8 Local_u8ErrStatus = RT_OK;
	if(Copy_u8pVal == NULL )
	{Local_u8ErrStatus = RT_NOK;}
	else
	{
		switch( Copy_u8PortNo )
			{
				case PORT_A: * Copy_u8pVal = PINA_REG ; break;
			    case PORT_B: * Copy_u8pVal = PINB_REG; break;
			    case PORT_C: * Copy_u8pVal = PINC_REG; break;
			    case PORT_D: * Copy_u8pVal = PIND_REG; break;
			    default: Local_u8ErrStatus = RT_NOK; break;
			}
	}
	return(Local_u8ErrStatus);
}


u8 DIO_u8GetPinVal(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 * Copy_u8pVal)
{
	u8 Local_u8ErrStatus = RT_OK;
	if(Copy_u8pVal == NULL )
	{Local_u8ErrStatus = RT_NOK;}
	else
	{
		if(Copy_u8PortNo <= PORT_D && Copy_u8PinNo <= 7)
		{
			switch(Copy_u8PortNo)
			{
				case PORT_A: * Copy_u8pVal = GET_BIT(PINA_REG , Copy_u8PinNo ); break;
				case PORT_B: * Copy_u8pVal = GET_BIT(PINB_REG , Copy_u8PinNo ); break;
				case PORT_C: * Copy_u8pVal = GET_BIT(PINC_REG , Copy_u8PinNo ); break;
				case PORT_D: * Copy_u8pVal = GET_BIT(PIND_REG , Copy_u8PinNo ); break;
			}
		}
		else{Local_u8ErrStatus = RT_NOK;}
	}
	return(Local_u8ErrStatus);
}
