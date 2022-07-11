/*
 * INTERRUPT_reg.h
 *
 *  Created on: Oct 10, 2021
 *      Author: ziad
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_reg_H_
#define MCAL_INTERRUPT_INTERRUPT_reg_H_

#define MCUCR_reg (*(volatile u8*) 0x55)
#define MCUCSR_reg (*(volatile u8*) 0x54)

#define GICR_reg (*(volatile u8*) 0x5B)
#define SREG_reg (*(volatile u8*) 0x5F)

#define GIFR_reg (*(volatile u8*) 0x5A)


#endif /* MCAL_INTERRUPT_INTERRUPT_reg_H_ */
