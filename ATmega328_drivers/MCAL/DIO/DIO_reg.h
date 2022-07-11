/*
 * DIO_reg.h
 *
 *  Created on: Sep 17, 2021
 *      Author: ziad
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_
/*Port A does not exist but i'm defining it for the sake of errors in this driver*/
#define DDRA_REG (*(volatile u8*)  0x3A)
#define PORTA_REG (*(volatile u8*)  0x3B)
#define PINA_REG (*(volatile u8*)  0x39)

#define DDRB_REG (*(volatile u8*)  0x24)
#define PORTB_REG (*(volatile u8*)  0x25)
#define PINB_REG (*(volatile u8*)  0x23)

#define DDRC_REG (*(volatile u8*)  0x27)
#define PORTC_REG (*(volatile u8*)  0x28)
#define PINC_REG (*(volatile u8*)  0x26)

#define DDRD_REG (*(volatile u8*)  0x2A)
#define PORTD_REG (*(volatile u8*)  0x2B)
#define PIND_REG (*(volatile u8*)  0x29)

#endif /* DIO_REG_H_ */
