/*
 * EXTI_interface.h
 *
 *  Created on: Sep 5, 2022
 *      Author: ziad
 */

#ifndef _MCAL_05_EXTI_EXTI_INTERFACE_H_
#define _MCAL_05_EXTI_EXTI_INTERFACE_H_

typedef enum {
	EXTI_PORT_A ,
	EXTI_PORT_B ,
	EXTI_PORT_C
}EXTIPort_t;

typedef enum {
	EXTI_LINE_0 ,
	EXTI_LINE_1 ,
	EXTI_LINE_2 ,
	EXTI_LINE_3 ,
	EXTI_LINE_4 ,
	EXTI_LINE_5 ,
	EXTI_LINE_6 ,
	EXTI_LINE_7 ,
	EXTI_LINE_8 ,
	EXTI_LINE_9 ,
	EXTI_LINE_10,
	EXTI_LINE_11 ,
	EXTI_LINE_12 ,
	EXTI_LINE_13 ,
	EXTI_LINE_14 ,
	EXTI_LINE_15 ,
	EXTI_LINE_16

}EXTILine_t;

typedef enum{
	EXTI_TRIGGER_RISING ,
	EXTI_TRIGGER_FALLING ,
	EXTI_TRIGGER_ANYCHANGE
}EXTI_TRIGGER_t;

typedef void (*EXTI_callBack) (void)  ;

void EXTI_voidConfig (EXTIPort_t EXTIPort, EXTILine_t EXTILine , EXTI_TRIGGER_t EXTISenseMode) ;
void EXTI_setCallback(EXTILine_t EXTILine , void (*ptr)(void) );


#endif /* 02_MCAL_05_EXTI_EXTI_INTERFACE_H_ */
