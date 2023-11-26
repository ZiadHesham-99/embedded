/*
 * MPU_private.h
 *
 *  Created on: Dec 9, 2022
 *      Author: ziad
 */

#ifndef __HAL_MPU_MPU_PRIVATE_H_
#define __HAL_MPU_MPU_PRIVATE_H_

#define MPU_SLAVE_ADDRESS	                ((u8)0x68)

#define MPU_WHO_AM_I_REG	                ((u8)0x75)
#define MPU_OK_RESPONSE		                ((u8)0x68)
#define MPU_PWR_MGMT_1		                ((u8)0x6B)
#define MPU_SMPLR_DIV		                ((u8)0x19)
#define MPU_GYRO_CONFIG		                ((u8)0x1B)
#define MPU_ACCEL_CONFIG	                ((u8)0x1C)

#define MPU_XYZ_ACCEL_DATA_START_ADDRESS	((u8)0x3B)
#define MPU_XYZ_GYRO_DATA_START_ADDRESS		((u8)0x43)
#endif /* 03__HAL_MPU_MPU_PRIVATE_H_ */
