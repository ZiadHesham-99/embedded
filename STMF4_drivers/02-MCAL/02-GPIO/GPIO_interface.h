#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#include"../../01-LIB/01-TYPES/STD_TYPPES.h"

#define  NOT_USED  255
typedef enum{
 INPUT   =  0b00,
 OUTPUT  =  0b01,
 AF      =  0b10,
 ANALOG  =  0b11
}PIN_MODE;

typedef enum{
 OUTPUT_SPEED_LOW_SPEED         =  0b00,
 OUTPUT_SPEED_NORMAL_SPEED      =  0b01,
 OUTPUT_SPEED_HIGH_SPEED        =  0b10,
 OUTPUT_SPEED_VERY_HIGH_SPEED   =  0b11

}OUTPUT_SPEED;

typedef enum{
	PORT_NAME_A = 0,
	PORT_NAME_B = 1,
	PORT_NAME_C = 2
}PORT_NAME;
typedef enum {
	PIN_NUM_0 = 0 ,
	PIN_NUM_1 = 1 ,
	PIN_NUM_2 = 2 ,
	PIN_NUM_3 = 3 ,
	PIN_NUM_4 = 4 ,
	PIN_NUM_5 = 5 ,
	PIN_NUM_6 = 6 ,
	PIN_NUM_7 = 7 ,
	PIN_NUM_8 = 8 ,
	PIN_NUM_9 = 9 ,
	PIN_NUM_10 =10,
	PIN_NUM_11 =11,
	PIN_NUM_12 =12,
	PIN_NUM_13 =13,
	PIN_NUM_14 =14,
	PIN_NUM_15 =15
}PIN_NUM;

typedef enum {
	PUSHPULL = 0,
	OPENDRAIN = 1

}PUSHPULL_OR_OPENDRAIN;

typedef enum {
	NO_PULL_UP_PULL_DOWN = 0 ,
	PULL_UP = 1 ,
	PULL_DOWN = 2 ,
}PULL_UP_DOWN;



typedef enum {
	LEVEL_LOW = 0,
	LEVEL_HIGH = 1
}LEVEL;

typedef enum{
	AF_SYSTEM= 0 ,
	AF_TIM1_2= 1 ,
	AF_TIM3_5= 2 ,
	AF_TIM9_11= 3 ,
	AF_I2C1_3= 4 ,
	AF_SPI1_4= 5 ,
	AF_SPI3= 6 ,
	AF_USART1_2= 7 ,
	AF_USAART6= 8 ,
	AF_I2C2_3= 9 ,
	AF_OTG_FS =10,
	AF_NF1 =11,
	AF_SDIO =12,
	AF_NF2 =13,
	AF_NF3=14,
	AF_EVENTOUT =15,
}AF_ID_t;

void GPIO_setPinMode(void);

void GPIO_voidSetPinValue(PORT_NAME local_u8PortID, PIN_NUM local_u8PinID,LEVEL local_u8Value);

LEVEL GPIO_voidGetPinValue(PORT_NAME local_u8PortID,PIN_NUM local_u8PinID);

void GPIO_voidSetPortValue(PORT_NAME local_u8PortID , u16  local_u16PortValue);
#endif
