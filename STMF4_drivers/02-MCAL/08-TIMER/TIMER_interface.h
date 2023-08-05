#ifndef _MCAL_06_TIMER_INTERFACE_H_
#define _MCAL_06_TIMER_INTERFACE_H_

#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"TIMER_config.h"
#include"TIMER_private.h"

#define TIMER_NOT_USED (u8)255

typedef enum
{
	/*use timer as systick for delays */
	TIM_DELAY	= (u8)0,
	/*use timer for PWM or ICM*/
	TIM_INPUT_OUTPUT
}TIM_MODE;

typedef enum{
	TIM_NUM_0 = (u8)0,
	TIM_NUM_1 = (u8)1,
	TIM_NUM_2 = (u8)2,
	TIM_NUM_3 = (u8)3,
	TIM_NUM_4 = (u8)4,
	TIM_NUM_5 = (u8)5,
	TIM_NUM_9 = (u8)9,
	TIM_NUM_10 = (u8)10,
	TIM_NUM_11 = (u8)11
}TIM_NUM;

typedef enum{
	TIM_NUM_CH_1 = (u8)1,
	TIM_NUM_CH_2 = (u8)2,
	TIM_NUM_CH_3 = (u8)3,
	TIM_NUM_CH_4 = (u8)4
}TIM_CH;

typedef enum
{
	PWM_CHANNEL = (u8)0,
	IC_DIRECT_MODE_TI1,
	IC_INDIRECT_MODE_TI2,
	IC_TRC_MODE
}CHANNEL_MODE;

typedef enum
{
	UP_COUNTER	= (u8)0,
	DOWN_COUNTER
}TIM_DIRECTION;

/*******PWM configuration********/
typedef enum
{
	PWM_ACTIVE_HIGH	= (u8)0,
	PWM_ACTIVE_LOW
}PWM_POLARITY;
/********************************/

/******ICM configuration*********/
typedef enum
{
	IC_NO_PRESCALER = (u8)0,
	IC_CAPTURE_EVERY_2_EVENTS,
	IC_CAPTURE_EVERY_4_EVENTS,
	IC_CAPTURE_EVERY_8_EVENTS
}IC_PRESCALER;
typedef enum
{
	IC_RAISING_EDGE = (u8)0,
	IC_FALLING_EDGE,
	IC_BOTH_EDGES = (u8)3
}IC_POLARITY;
typedef enum
{
	IC_NO_FILTER = (u8)0,
	IC_F_CK_INT_N2,
	IC_F_CK_INT_N4,
	IC_F_CK_INT_N8,
	IC_F_DTS_2_N6,
	IC_F_DTS_2_N8,
	IC_F_DTS_4_N6,
	IC_F_DTS_4_N8,
	IC_F_DTS_8_N6,
	IC_F_DTS_8_N8,
	IC_F_DTS_16_N5,
	IC_F_DTS_16_N6,
	IC_F_DTS_16_N8,
	IC_F_DTS_32_N5,
	IC_F_DTS_32_N6,
	IC_F_DTS_32_N8,
}IC_FILTER;
/********************************/
typedef struct
{
	TIM_CH			TimChannel;
	CHANNEL_MODE	ChannelMode;
	PWM_POLARITY	PWMPolarity;
	IC_POLARITY		ICPolarity;
	IC_PRESCALER	ICPrescaler;
	IC_FILTER		ICFilter;
}TIM_CHANNEL_CONFIG_t;

typedef struct
{
	TIM_NUM					TimNum;
	TIM_MODE				TimMode;
	TIM_DIRECTION			TimDirection;
	u16						u16Prescaler;
	u8						numOfChannelUsed;
	TIM_CHANNEL_CONFIG_t	channelConfig[4];
}TIM_CONFIG_t;

TIM_CONFIG_t globalTimersConfigs[NUM_OF_TIM_USED];

typedef enum
{
	PWM_0_PERCENTAGE 	= 0,
	PWM_3_PERCENTAGE 	= 3,
	PWM_5_PERCENTAGE 	= 5,
	PWM_6_PERCENTAGE 	= 6,
	PWM_8_PERCENTAGE 	= 8,
	PWM_10_PERCENTAGE 	= 10,
	PWM_12_PERCENTAGE 	= 12,
	PWM_13_PERCENTAGE 	= 13,
	PWM_20_PERCENTAGE 	= 20,
	PWM_25_PERCENTAGE 	= 25,
	PWM_30_PERCENTAGE 	= 30,
	PWM_40_PERCENTAGE 	= 40,
	PWM_50_PERCENTAGE 	= 50,
	PWM_60_PERCENTAGE 	= 60,
	PWM_70_PERCENTAGE 	= 70,
	PWM_75_PERCENTAGE 	= 75,
	PWM_80_PERCENTAGE 	= 80,
	PWM_90_PERCENTAGE 	= 90,
	PWM_100_PERCENTAGE 	= 100,
}PWM_DUTY_CYCLE_PERCENTAGE;

void TIMER_vidInit(void);

void TIMER_vidICStart (TIM_NUM TimerNumber, TIM_CH TimerChannel  );
void TIMER_vidICStop (TIM_NUM TimerNumber, TIM_CH TimerChannel  );
u32 TIMER_u32ICGetCapturedValue(TIM_NUM TimerNumber, TIM_CH TimerChannel);

void TIMER_vidPWMStart(TIM_NUM TimerNumber, TIM_CH TimerChannel, f32 Copy_f32SignalFreqInHz, PWM_DUTY_CYCLE_PERCENTAGE Copy_enmDutyCyclePer);
void TIMER_vidPWMStop(TIM_NUM TimerNumber, TIM_CH TimerChannel);

#endif /* 02_MCAL_06_TIMER_INTERFACE_H_ */
