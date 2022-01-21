/*
 * main.c
 *
 *  Created on: Sep 29, 2021
 *      Author: ziad
 */
#include"stdtypes.h"
#include"bitmath.h"
#include "DIO_int.h"
#include"util/delay.h"

void main (void)
{
  /* u8 Flags [30] = {0};
   //Flags[0] = DIO_u8SetPortDir(PORT_A , 255);
   Flags[0] = DIO_u8SetPinDir(PORT_D,PIN_0,OUTPUT);
   Flags[21] = DIO_u8SetPinDir(PORT_D,PIN_1,OUTPUT);
   Flags[22] = DIO_u8SetPinDir(PORT_D,PIN_2,OUTPUT);
   Flags[23] = DIO_u8SetPinDir(PORT_D,PIN_3,OUTPUT);
   Flags[24] = DIO_u8SetPinDir(PORT_D,PIN_4,OUTPUT);
   Flags[25] = DIO_u8SetPinDir(PORT_D,PIN_5,OUTPUT);
   Flags[26] = DIO_u8SetPinDir(PORT_D,PIN_6,OUTPUT);
   Flags[27] = DIO_u8SetPinDir(PORT_D,PIN_7,OUTPUT);
   for(int i=0 ; i<8 ;i++)
   		{
   			_delay_ms(500);
   			Flags[i+1] = DIO_u8SetPinVal(PORT_D,i,HIGH);
   			_delay_ms(1000);
   			Flags[19-i] = DIO_u8SetPinVal(PORT_D,i,LOW);
   		}

   Flags[29]=DIO_u8SetPortVal(PORT_D,HIGH_PORT);
   _delay_ms(500);
   for(int i=0 ;i <30 ; i++)
   		{
 			if(Flags[i] != 0)
 			{
 				u8 X = DIO_u8SetPinDir(PORT_C , PIN_0 , OUTPUT);
 				u8 Y = DIO_u8SetPinVal(PORT_C ,PIN_0, HIGH );
 				_delay_ms(300);
 				u8 Z = DIO_u8SetPinVal(PORT_C ,PIN_0, LOW );
 				_delay_ms(300);

 			}
 			else{
 				u8 X = DIO_u8SetPinDir(PORT_C , PIN_1 , OUTPUT);
 				u8 Y = DIO_u8SetPinVal(PORT_C ,PIN_1, HIGH );
 				_delay_ms(300);
 				u8 Z = DIO_u8SetPinVal(PORT_C ,PIN_1, LOW );
 				_delay_ms(300);

 			}
   		}*/

	while(1)
	{
		u8 pin ,flag;
		u8 *p = &pin;
		flag = DIO_u8GetPinVal(PORT_C,PIN_0,p);
		if(pin == 0)
		{
			DIO_u8SetPortDir(PORT_D , 255);
			DIO_u8SetPortVal(PORT_D,255);
		}
		else
		{
			DIO_u8SetPortDir(PORT_D , 255);
			DIO_u8SetPinVal(PORT_D,PIN_0,HIGH);
		}
	}

}
