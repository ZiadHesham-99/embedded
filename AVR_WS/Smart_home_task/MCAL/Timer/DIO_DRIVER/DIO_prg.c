/*
 * DIO_prg.c
 *
 *  Created on: Sep 17, 2021
 *      Author: DELL
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "DIO_REG.h"
#include "DIO_int.h"

u8 DIO_U8_SetPortDir(u8 Copy_U8_PORT_NO , u8 COPY_U8_DIR)
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;

	switch(Copy_U8_PORT_NO)
	{
	case PORT_A:
		DDRA_REG=COPY_U8_DIR;
		break;
	case PORT_B:
		DDRB_REG=COPY_U8_DIR;
		break;
	case PORT_C:
		DDRC_REG=COPY_U8_DIR;
		break;
	case PORT_D:
		DDRD_REG=COPY_U8_DIR;
		break;
	default:
		LOCAL_U8_ERRSTATUS= RT_NOK;
		break;
	}

	return LOCAL_U8_ERRSTATUS;
}


u8 DIO_U8_SetPortVal(u8 Copy_U8_PORT_NO , u8 COPY_U8_VAL)
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;

	switch(Copy_U8_PORT_NO)
	{
	case PORT_A:
		PORTA_REG=COPY_U8_VAL;
		break;
	case PORT_B:
		PORTB_REG=COPY_U8_VAL;
		break;
	case PORT_C:
		PORTC_REG=COPY_U8_VAL;
		break;
	case PORT_D:
		PORTD_REG=COPY_U8_VAL;
		break;
	default:
		LOCAL_U8_ERRSTATUS= RT_NOK;
		break;
	}

	return LOCAL_U8_ERRSTATUS;
}

u8 DIO_U8_GetPortVal(u8 Copy_U8_PORT_NO , u8* COPY_U8P_VAR)
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;

	switch(Copy_U8_PORT_NO)
	{
	case PORT_A:
		*COPY_U8P_VAR=PINA_REG;
		break;
	case PORT_B:
		*COPY_U8P_VAR=PINB_REG;
		break;
	case PORT_C:
		*COPY_U8P_VAR=PINC_REG;
		break;
	case PORT_D:
		*COPY_U8P_VAR=PIND_REG;
		break;
	default:
		LOCAL_U8_ERRSTATUS= RT_NOK;
		break;
	}

	return LOCAL_U8_ERRSTATUS;
}

u8 DIO_U8_SetPinDir(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO , u8 COPY_U8_DIR)
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;
	if((Copy_U8_PIN_NO>=PIN_0)&&(Copy_U8_PIN_NO<=PIN_7))
	{
		if(COPY_U8_DIR==INPUT)
		{
			switch(Copy_U8_PORT_NO)
			{
			case PORT_A:
				CLR_BIT(DDRA_REG,Copy_U8_PIN_NO);
				break;
			case PORT_B:
				CLR_BIT(DDRB_REG,Copy_U8_PIN_NO);
				break;
			case PORT_C:
				CLR_BIT(DDRC_REG,Copy_U8_PIN_NO);
				break;
			case PORT_D:
				CLR_BIT(DDRD_REG,Copy_U8_PIN_NO);
				break;
			default:
				LOCAL_U8_ERRSTATUS= RT_NOK;
				break;
			}
		}
		else if (COPY_U8_DIR==OUTPUT)
		{
			switch(Copy_U8_PORT_NO)
			{
			case PORT_A:
				SET_BIT(DDRA_REG,Copy_U8_PIN_NO);
				break;
			case PORT_B:
				SET_BIT(DDRB_REG,Copy_U8_PIN_NO);
				break;
			case PORT_C:
				SET_BIT(DDRC_REG,Copy_U8_PIN_NO);
				break;
			case PORT_D:
				SET_BIT(DDRD_REG,Copy_U8_PIN_NO);
				break;
			default:
				LOCAL_U8_ERRSTATUS= RT_NOK;
				break;
			}
		}
		else
		{
			LOCAL_U8_ERRSTATUS= RT_NOK;
		}

	}
	else
	{
		LOCAL_U8_ERRSTATUS = RT_NOK;
	}

	return LOCAL_U8_ERRSTATUS;
}

u8 DIO_U8_SetPinVal(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO , u8 COPY_U8_VAL)
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;
	if((Copy_U8_PIN_NO>=PIN_0)&&(Copy_U8_PIN_NO<=PIN_7))
	{
		if(COPY_U8_VAL==LOW)
		{
			switch(Copy_U8_PORT_NO)
			{
			case PORT_A:
				CLR_BIT(PORTA_REG,Copy_U8_PIN_NO);
				break;
			case PORT_B:
				CLR_BIT(PORTB_REG,Copy_U8_PIN_NO);
				break;
			case PORT_C:
				CLR_BIT(PORTC_REG,Copy_U8_PIN_NO);
				break;
			case PORT_D:
				CLR_BIT(PORTD_REG,Copy_U8_PIN_NO);
				break;
			default:
				LOCAL_U8_ERRSTATUS= RT_NOK;
				break;
			}
		}
		else if (COPY_U8_VAL==HIGH)
		{
			switch(Copy_U8_PORT_NO)
			{
			case PORT_A:
				SET_BIT(PORTA_REG,Copy_U8_PIN_NO);
				break;
			case PORT_B:
				SET_BIT(PORTB_REG,Copy_U8_PIN_NO);
				break;
			case PORT_C:
				SET_BIT(PORTC_REG,Copy_U8_PIN_NO);
				break;
			case PORT_D:
				SET_BIT(PORTD_REG,Copy_U8_PIN_NO);
				break;
			default:
				LOCAL_U8_ERRSTATUS= RT_NOK;
				break;
			}
		}
		else
		{
			LOCAL_U8_ERRSTATUS= RT_NOK;
		}

	}
	else
	{
		LOCAL_U8_ERRSTATUS = RT_NOK;
	}

	return LOCAL_U8_ERRSTATUS;
}

u8 DIO_U8_GetPinVal(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO , u8* COPY_U8P_VAR)
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;
	if((Copy_U8_PIN_NO>=PIN_0)&&(Copy_U8_PIN_NO<=PIN_7))
	{
		switch(Copy_U8_PORT_NO)
		{
		case PORT_A:
			*COPY_U8P_VAR=GET_BIT(PINA_REG,Copy_U8_PIN_NO);
			break;
		case PORT_B:
			*COPY_U8P_VAR=GET_BIT(PINB_REG,Copy_U8_PIN_NO);
			break;
		case PORT_C:
			*COPY_U8P_VAR=GET_BIT(PINC_REG,Copy_U8_PIN_NO);
			break;
		case PORT_D:
			*COPY_U8P_VAR=GET_BIT(PIND_REG,Copy_U8_PIN_NO);
			break;
		default:
			LOCAL_U8_ERRSTATUS= RT_NOK;
			break;
		}
	}
	else
	{
		LOCAL_U8_ERRSTATUS = RT_NOK;
	}

	return LOCAL_U8_ERRSTATUS;
}

u8 DIO_U8_ToggleBit(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO )
{
	u8 LOCAL_U8_ERRSTATUS = RT_OK;
	if((Copy_U8_PIN_NO>=PIN_0)&&(Copy_U8_PIN_NO<=PIN_7))
		{
			switch(Copy_U8_PORT_NO)
			{
			case PORT_A:
				TOG_BIT(PORTA_REG,Copy_U8_PIN_NO);
				break;
			case PORT_B:
				TOG_BIT(PORTB_REG,Copy_U8_PIN_NO);
				break;
			case PORT_C:
				TOG_BIT(PORTC_REG,Copy_U8_PIN_NO);
				break;
			case PORT_D:
				TOG_BIT(PORTD_REG,Copy_U8_PIN_NO);
				break;
			default:
				LOCAL_U8_ERRSTATUS= RT_NOK;
				break;
			}
		}
		else
		{
			LOCAL_U8_ERRSTATUS = RT_NOK;
		}

	return LOCAL_U8_ERRSTATUS;
}
