/*
 * Timer_reg.h
 *
 *  Created on: Oct 29, 2021
 *      Author: DELL
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TCCR0	(*(volatile u8*) 0x53)
#define OCR0	(*(volatile u8*) 0x5C)
#define TCNT0	(*(volatile u8*) 0x52)

#define TCCR1A	(*(volatile u8*) 0x4F)
#define TCCR1B	(*(volatile u8*) 0x4E)
#define TCNT1	(*(volatile u16*) 0x4C)
#define OCR1A	(*(volatile u16*) 0x4A)
#define OCR1B	(*(volatile u16*) 0x48)
#define ICR1	(*(volatile u16*) 0x46)

#define TCCR2	(*(volatile u8*) 0x45)
#define OCR2	(*(volatile u8*) 0x43)
#define TCNT2	(*(volatile u8*) 0x44)


#define TIMSK	(*(volatile u8*) 0x59)


#endif /* TIMER_REG_H_ */
