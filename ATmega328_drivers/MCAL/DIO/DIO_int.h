/*
 * DIO_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: ziad
 */

#include "../../LIB/stdtypes.h"
#include "../../LIB/bitmath.h"

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define PORT_A (u8) 0
#define PORT_B (u8) 1
#define PORT_C (u8) 2
#define PORT_D (u8) 3


#define PIN_0 (u8) 0
#define PIN_1 (u8) 1
#define PIN_2 (u8) 2
#define PIN_3 (u8) 3
#define PIN_4 (u8) 4
#define PIN_5 (u8) 5
#define PIN_6 (u8) 6
#define PIN_7 (u8) 7

#define INPUT (u8) 0
#define OUTPUT (u8) 1

#define OUTPUT_PORT (u8) 255

#define LOW (u8) 0
#define HIGH (u8) 1
#define HIGH_PORT (u8) 255

#define Full_Input (u8) 0x00
#define Full_Output (u8) 0xff

u8 DIO_u8SetPortDir(u8 Copy_u8PortNo , u8 Copy_u8Dir);
u8 DIO_u8SetPortVal(u8 Copy_u8PortNo , u8 Copy_u8Val);
u8 DIO_u8GetPortVal(u8 Copy_u8PortNo , u8 * Copy_u8pVal);
u8 DIO_u8SetPinDir(u8 Copy_u8PortNo , u8 Copy_u8PinNo ,u8 Copy_u8Dir);
u8 DIO_u8SetPinVal(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 Copy_u8Val);
u8 DIO_u8GetPinVal(u8 Copy_u8PortNo , u8 Copy_u8PinNo , u8 * Copy_u8pVal);
#endif /* DIO_INT_H_ */
