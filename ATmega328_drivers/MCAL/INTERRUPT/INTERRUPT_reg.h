/*
 * INTERRUPT_reg.h
 *
 *  Created on: Oct 10, 2021
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_reg_H_
#define MCAL_INTERRUPT_INTERRUPT_reg_H_

#define EICRA_reg (*(volatile u8*) 0x69)
/*#define MCUCSR_reg (*(volatile u8*) 0x54)*/

#define EIMSK_reg (*(volatile u8*) 0x3D)
#define SREG_reg (*(volatile u8*) 0x5F)

#define EIFR_reg (*(volatile u8*) 0x3C)


#endif /* MCAL_INTERRUPT_INTERRUPT_reg_H_ */
