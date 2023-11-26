/*
 * MPU_interface.h
 *
 *  Created on: Dec 9, 2022
 *      Author: ziad
 */

#ifndef __HAL_MPU_MPU_INTERFACE_H_
#define __HAL_MPU_MPU_INTERFACE_H_

ERROR_STATUS MPU_init(void);
void MPU_readXYZAccel (u16 * AcceLDataPtr);
void MPU_readXYZGyro (u16 * GyroDataPtr);

#endif /* 03__HAL_MPU_MPU_INTERFACE_H_ */
