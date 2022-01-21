/*
 * DIO_init.h
 *
 *  Created on: Sep 17, 2021
 *      Author: DELL
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#define PORT_A (u8)0
#define PORT_B (u8)1
#define PORT_C (u8)2
#define PORT_D (u8)3

#define PIN_0 (u8)0
#define PIN_1 (u8)1
#define PIN_2 (u8)2
#define PIN_3 (u8)3
#define PIN_4 (u8)4
#define PIN_5 (u8)5
#define PIN_6 (u8)6
#define PIN_7 (u8)7

#define INPUT (u8)0
#define OUTPUT (u8)1

#define LOW (u8)0
#define HIGH (u8)1

#define FULL_INPUT (u8)0
#define FULL_OUTPUT (u8)255

#define RT_OK 0
#define RT_NOK 1

u8 DIO_U8_SetPortDir(u8 Copy_U8_PORT_NO , u8 COPY_U8_DIR);
u8 DIO_U8_SetPortVal(u8 Copy_U8_PORT_NO , u8 COPY_U8_VAL);
u8 DIO_U8_GetPortVal(u8 Copy_U8_PORT_NO , u8* COPY_U8P_VAR);

u8 DIO_U8_SetPinDir(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO , u8 COPY_U8_DIR);
u8 DIO_U8_SetPinVal(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO , u8 COPY_U8_VAL);
u8 DIO_U8_GetPinVal(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO , u8* COPY_U8P_VAR);

u8 DIO_U8_ToggleBit(u8 Copy_U8_PORT_NO , u8 Copy_U8_PIN_NO );


#endif /* DIO_INT_H_ */
