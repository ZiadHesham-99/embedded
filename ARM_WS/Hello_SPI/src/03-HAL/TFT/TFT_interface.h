/*
 * TFT_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: ziad
 */

#ifndef _HAL_TFT_TFT_INTERFACE_H_
#define _HAL_TFT_TFT_INTERFACE_H_

void TFT_vidInit(void);
void TFT_sendCommand(u8 command);
void TFT_sendData(u8 Data);



#endif /* 03_HAL_TFT_TFT_INTERFACE_H_ */
