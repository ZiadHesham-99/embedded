/*
 * WIFI_interface.h
 *
 *  Created on: Oct 6, 2022
 *      Author: ziad
 */

#ifndef _HAL_WIFI_WIFI_INTERFACE_H_
#define _HAL_WIFI_WIFI_INTERFACE_H_

typedef enum{
	WIFI_COMMAND_INIT ,
	WIFI_COMMAND_ECHO_MODE,
	WIFI_COMMAND_WIFI_CONNECT,
	WIFI_COMMAND_CONNECT_TO_SERVER ,
	WIFI_COMMAND_REQUEST_GET ,
	WIFI_COMMAND_DATA
}WIFI_COMMAND_t;
typedef struct{
	WIFI_COMMAND_t command;
	u8 response_size;
	char response [100];
}RESPONSE;

ERROR_STATUS WIFI_u8Init(void);
ERROR_STATUS WIFI_u8ValidateRespomse(WIFI_COMMAND_t command);
ERROR_STATUS WIFI_u8GetData(u8 * dataPtr ,u32 * startOfDataPtr , u32 * endOfDataPtr);
#endif /* 03_HAL_WIFI_WIFI_INTERFACE_H_ */
