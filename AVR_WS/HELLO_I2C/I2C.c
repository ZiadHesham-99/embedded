/*
 * I2C.c
 *
 *  Created on: Nov 20, 2021
 *      Author: ziad
 */
#include"I2C.h"
#include "LIB/bitmath.h"
#include "LIB/stdtypes.h"
#include "AVR/io.h"
void I2C_Master_init(void)
{
	/*This bit is needed to make pins work as I2C*/
	SET_BIT(TWCR,2);
	CLR_BIT(TWCR,5);
	/*PRESCALEER setting = 1*/
	TWSR &= 0b11111100;
	/*TWI BIT RATE*/
	TWBR=2
	/*Enable ACK signal*/
	SET_BIT(TWCR ,6);
	/*TWAR is my Slave address register I choose 44 */
	TWAR =44;

}
void I2C_Start(void)
{
	/*wait till ACK signal  */
	while();
	SET_BIT(TWCR,5);
	/*When start condition is detected clr start condition bit*/
	while();
	CLR_BIT(TWCR,5);

}
void I2C_Send_Slave_Adress_with_Write_request(u8 Address)
{
	/*TWDR Data Register*/
	TWDR = (Address<<1);
	/*wait till ACK signal  */
	while();
}
void I2C_Write_Byte(u8 Byte)
{
	/*TWDR Data Register*/
	TWDR = Byte ;
	/*wait till ACK signal  */
	while();
}
void I2C_Send_Slave_Address_With_Read_Request(u8 Address)
{
	/*TWDR Data Register*/
	TWDR = ((Address<<1)|1);
	/*wait till ACK signal  */
	while();
}
u8 I2C_Read_Byte(void)
{
	u8 Data;
	/*wait till byte is recieved*/
	while();
	Data = TWDR;
	return Data ;
}
void I2C_Stop(void)
{
	/*enable stop condition  bit*/
	SET_BIT(TWCR , 4);

}


