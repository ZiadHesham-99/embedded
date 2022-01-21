/*
 * INTERRUPT_int.h
 *
 *  Created on: Oct 10, 2021
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_INT_H_
#define MCAL_INTERRUPT_INTERRUPT_INT_H_

#define INT_0 (u8) 0
#define INT_1 (u8) 1
#define INT_2 (u8) 2

#define LOW_LEVEL (u8) 0
#define ANY_CHANGE (u8) 1
#define FALLING_EDGE (u8) 2
#define RISING_EDGE (u8) 3

#define ENABLE (u8) 1
#define DISABLE (u8) 0

u8 INTERRUPT_u8GlobalInterruptControl(u8 Copy_u8Status);
u8 INTERRUPT_u8Enable(u8 Copy_u8IntNo);
u8 INTERRUPT_u8Disable(u8 Copy_u8IntNo);
u8 INTERRUPT_u8SenseControl(u8 Copy_u8IntNo ,u8 Copy_u8Trigger);
u8 INTERRUPT_u8GetInterruptFlag(u8 Copy_u8IntNo ,u8 * Copy_u8pVal);
#endif /* MCAL_INTERRUPT_INTERRUPT_INT_H_ */
