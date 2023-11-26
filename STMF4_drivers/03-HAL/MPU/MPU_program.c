/*
 * MPU_program.c
 *
 *  Created on: Dec 9, 2022
 *      Author: ziad
 */
#include"../../01- LIB/01- TYPES/STD_TYPES.h"
#include"../../01- LIB/02- BIT_MATH/BIT_MATH.h"
#include"../../01- LIB/03- ERROR_STATUS/ERROR_STATUS.h"

#include"../../02- MCAL/10 - I2C/I2C_interface.h"

#include"MPU_interface.h"
#include"MPU_config.h"
#include"MPU_private.h"

ERROR_STATUS MPU_init(void){
	ERROR_STATUS returnStatus = _ERROR_ ;
	u8 readDataBfr = 0;
	u8 writeDataBfr = 0 ;
	I2C_vidMemRead(I2C_1,MPU_SLAVE_ADDRESS ,MPU_WHO_AM_I_REG,_8BITS_I2C_MEM,&readDataBfr,3);
	if(readDataBfr==MPU_OK_RESPONSE){
		writeDataBfr = 0x00 ;
		I2C_vidMemWrite(I2C_1 ,MPU_SLAVE_ADDRESS , MPU_PWR_MGMT_1 ,_8BITS_I2C_MEM ,writeDataBfr ,1 );
		writeDataBfr = 0x07 ;
		I2C_vidMemWrite(I2C_1 ,MPU_SLAVE_ADDRESS , MPU_SMPLR_DIV ,_8BITS_I2C_MEM ,writeDataBfr ,1 );
		writeDataBfr = 0x00 ;
		I2C_vidMemWrite(I2C_1 ,MPU_SLAVE_ADDRESS , MPU_GYRO_CONFIG ,_8BITS_I2C_MEM ,writeDataBfr ,1 );
		writeDataBfr = 0x00 ;
		I2C_vidMemWrite(I2C_1 ,MPU_SLAVE_ADDRESS , MPU_ACCEL_CONFIG ,_8BITS_I2C_MEM ,writeDataBfr ,1 );
		returnStatus = _OK_ ;
	}
	return returnStatus ;
}

void MPU_readXYZAccel (u16 * AcceLDataPtr){
	u8 readDataBfr[6] = {0};
	I2C_vidMemRead(I2C_1,MPU_SLAVE_ADDRESS ,MPU_XYZ_ACCEL_DATA_START_ADDRESS,_8BITS_I2C_MEM,readDataBfr,6);
	AcceLDataPtr [0]= ((s16)(readDataBfr[0] << 8 | readDataBfr[1])/16384.0);
	AcceLDataPtr [1]= ((s16)(readDataBfr[2] << 8 | readDataBfr[3])/16384.0);
	AcceLDataPtr [2]= ((s16)(readDataBfr[4] << 8 | readDataBfr[5])/16384.0);

}


void MPU_readXYZGyro (u16 * GyroDataPtr){
	u8 readDataBfr[6] = {0};
	I2C_vidMemRead(I2C_1,MPU_SLAVE_ADDRESS ,MPU_XYZ_GYRO_DATA_START_ADDRESS,_8BITS_I2C_MEM,readDataBfr,6);
	GyroDataPtr [0]= ((s16)(readDataBfr[0] << 8 | readDataBfr[1])/131.0);
	GyroDataPtr [1]= ((s16)(readDataBfr[2] << 8 | readDataBfr[3])/131.0);
	GyroDataPtr [2]= ((s16)(readDataBfr[4] << 8 | readDataBfr[5])/131.0);

}
