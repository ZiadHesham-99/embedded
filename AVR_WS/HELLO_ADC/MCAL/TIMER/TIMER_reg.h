/*
 * TIMER_reg.h
 *
 *  Created on: Nov 11, 2021
 *      Author: ziad
 */

#ifndef MCAL_TIMER_TIMER_REG_H_
#define MCAL_TIMER_TIMER_REG_H_

#define TCCR0_REG (*(volatile u8*) 0x53)
#define OCR0_REG (*(volatile u8*) 0x5C)
#define TCNT_REG (*(volatile u8*) 0x52)

#define TCCR1_REG (*(volatile u8*) 0x4F)
#define TCCR1_REG (*(volatile u8*) 0x4E)
#define TCNT_REG (*(volatile u16*) 0x4C)
#define OCR1_REG (*(volatile u16*) 0x4A)
#define OCR1_REG (*(volatile u16*) 0x48)
#define ICR1_REG (*(volatile u16*) 0x46)

#define TCCR_REG (*(volatile u8*) 0x45)
#define OCR2_REG (*(volatile u8*) 0x43)
#define TCNT_REG (*(volatile u8*) 0x44)


#define TIMSK_REG	(*(volatile u8*) 0x59)


#endif /* MCAL_TIMER_TIMER_REG_H_ */
