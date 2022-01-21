/*
 * I2C.h
 *
 *  Created on: Nov 20, 2021
 *      Author: ziad
 */

#ifndef I2C_H_
#define I2C_H_

void I2C_Master_init(void);
void I2C_Slave_init(void);
void I2C_Start(void);
void I2C_Repeated_Start(void);
void I2C_Send_Slave_Adress_with_Write_request(u8 Address);
void I2C_Send_Slave_Address_With_Read_Request(u8 Address);
void I2C_Write_Byte(u8 Byte);
u8 I2C_Read_Byte(void);
void I2C_Stop(void);
void I2C_Slave_Check_address_received_with_Write_req(void);
void I2C_Slave_Check_address_received_with_Read_req(void);


#endif /* I2C_H_ */
