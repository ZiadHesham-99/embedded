/*
 * WIFI_program.c
 *
 *  Created on: Oct 6, 2022
 *      Author: ziad
 */
#include "../../01- LIB/01- TYPES/STD_TYPES.h"
#include "../../01- LIB/02- BIT_MATH/BIT_MATH.h"
#include "../../01- LIB/03- ERROR_STATUS/ERROR_STATUS.h"

#include "../../02- MCAL/01- RCC/RCC_interface.h"
#include "../../02- MCAL/02- GPIO/GPIO_interface.h"
#include "../../02- MCAL/03- SYSTICK/SYSTICK_interface.h"
#include "../../02- MCAL/07- UART/UART_interface.h"


#include"WIFI_interface.h"
#include"WIFI_private.h"
#include"WIFI_config.h"

RESPONSE ESP_response[6]={
		{.command = WIFI_COMMAND_INIT,
				.response_size=12,
				.response={"AT\r\r\n\r\nOK\r\n#"}
		},

		{.command = WIFI_COMMAND_ECHO_MODE,
				.response_size=21,
				.response={"AT+CWMODE=1\r\r\n\r\nOK\r\n#"}
		},
		{.command = WIFI_COMMAND_WIFI_CONNECT,
				.response_size=89,
				.response={"AT+CWJAP_CUR=\"ziad\",\"nzk37600245\"\r\r\nWIFI DISCONNECT\r\nWIFI CONNECTED\r\nWIFI GOT IP\r\n\r\nOK\r\n#"}
		},
		{.command = WIFI_COMMAND_CONNECT_TO_SERVER,
				.response_size=57,
				.response={"AT+CIPSTART=\"TCP\",\"162.253.155.225\",80\r\r\nCONNECT\r\n\r\nOK\r\n#"}
		},
		{.command = WIFI_COMMAND_REQUEST_GET,
				.response_size=25,
				.response={"AT+CIPSEND=50\r\r\n\r\nOK\r\n> #"}
		},
		{.command = WIFI_COMMAND_DATA,
				.response_size=34,
				.response={"\r\nRecv 50 bytes\r\n\r\nSEND OK\r\n\r\n+IPD"}
		}
};

/*\r\nRecv 50 bytes\r\n\r\nSEND OK\r\n\r\n+IPD*/

ERROR_STATUS WIFI_u8Init(void){
	ERROR_STATUS localReturn =  _ERROR_ ;
	u8 counter=0;
	UART_vidTransmitString("AT\r\n");
	localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_INIT);
	while(localReturn!=_OK_){
		if(counter>=5){return _OVER_FLOW_;}
		UART_vidTransmitString("AT\r\n");
		localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_INIT);
		counter++;
	}
	counter=0;
	UART_vidTransmitString("AT+CWMODE=1\r\n");
	localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_ECHO_MODE);
	while(localReturn!=_OK_){
		if(counter>=5){return _OVER_FLOW_;}
		UART_vidTransmitString("AT+CWMODE=1\r\n");
		localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_ECHO_MODE);
		counter++;
	}
	counter=0;
	//	char temp[200] ="AT+CWJAP_CUR=\""+WIFI_NAME+"\",\""+WIFI_Password+"\"\r\n" ;
	UART_vidTransmitString("AT+CWJAP_CUR=\"ziad\",\"nzk37600245\"\r\n");
	localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_WIFI_CONNECT);
	while(localReturn!=_OK_){
		if(counter>=8){return _OVER_FLOW_;}
		UART_vidTransmitString("AT+CWJAP_CUR=\"ziad\",\"nzk37600245\"\r\n");
		localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_WIFI_CONNECT);
		counter++;
	}
	return _OK_ ;

}
ERROR_STATUS WIFI_u8ConnectToServer(void){
	ERROR_STATUS localReturn =  _ERROR_ ;
	u8 counter=0;
	UART_vidTransmitString(SERVER_IP);
	localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_CONNECT_TO_SERVER);
	while(localReturn!=_OK_){
		if(counter>=5){return _OVER_FLOW_;}
		UART_vidTransmitString(SERVER_IP);
		localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_WIFI_CONNECT);
		counter++;
	}
	return _OK_ ;
}
ERROR_STATUS WIFI_u8GetData(u8 * dataPtr ,u32 * startOfDataPtr , u32 * endOfDataPtr){
	ERROR_STATUS localReturn =  _OK_ ;
	volatile char Local_u8ReceivedChar =0 ;
	/*Data buffer size*/
	u32 Local_u8Counter =0 ;
	u32 counter=0 ;
	/*Start GET request*/
	UART_vidTransmitString("AT+CIPSEND=50\r\n");
	localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_REQUEST_GET);
	while(localReturn!=_OK_){
		if(counter>=5){return _OVER_FLOW_;}
		UART_vidTransmitString("AT+CIPSEND=50\r\n");
		localReturn = WIFI_u8ValidateRespomse(WIFI_COMMAND_REQUEST_GET);
		counter++;
	}
	/*GET request*/
	UART_vidTransmitString("GET http://ziad99zh.orgfree.com/deviceStatus.txt\r\n");
	/*listen to response*/
	while(Local_u8ReceivedChar != '#')
	{
		Local_u8ReceivedChar = UART_u8Receive(2000000);
		dataPtr[Local_u8Counter++] = Local_u8ReceivedChar;
	}
	/*validate response*/
	for(int i=0;i<ESP_response[WIFI_COMMAND_DATA].response_size;i++){
		if(dataPtr[i]!=ESP_response[WIFI_COMMAND_DATA].response[i]){
			return _ERROR_ ;
		}
	}
	Local_u8Counter = (ESP_response[WIFI_COMMAND_DATA].response_size+3) ;
	*(startOfDataPtr)= Local_u8Counter ;
	while(dataPtr[Local_u8Counter] !='C' &&  dataPtr[Local_u8Counter+1] !='L' &&dataPtr[Local_u8Counter+2] !='O' &&dataPtr[Local_u8Counter+5] !='D'){
		Local_u8Counter++;

	}
	*(endOfDataPtr)= Local_u8Counter ;
	return localReturn ;
}

ERROR_STATUS WIFI_u8ValidateRespomse(WIFI_COMMAND_t command){
	ERROR_STATUS localReturn =  _OK_ ;
	volatile char Local_u8ReceivedChar =0 ;
	volatile char Local_response[100]={0};
	u8 Local_u8Counter =0 ;
	while(Local_u8ReceivedChar != '#')
	{
		Local_u8ReceivedChar = UART_u8Receive(2000000);
		Local_response[Local_u8Counter++] = Local_u8ReceivedChar;
	}
	for(int i=0;i<ESP_response[command].response_size;i++){
		if(Local_response[i]!=ESP_response[command].response[i]){
			localReturn =_ERROR_;
			break ;
		}
	}
	return localReturn ;
}


