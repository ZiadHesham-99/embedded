#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "TIMER_interface.h"
#include"TIMER_config.h"
#include "TIMER_private.h"


TIM_CONFIG_t globalTimersConfigs[NUM_OF_TIM_USED] =
{
		[0] =
		{
				.TimNum			= TIM_NUM_2,
				.TimMode				= TIM_INPUT_OUTPUT,
				.TimDirection		= UP_COUNTER,
				.u16Prescaler			= 0,
				.numOfChannelUsed		=2,
				.TIM_CHANNEL_CONFIG_t[0] = {	.TimChannel		= TIM_NUM_CH_1,
												.ChannelMode 	= PWM_CHANNEL ,
												.PWMPolarity    = PWM_ACTIVE_HIGH,
												.ICPolarity     = TIMER_NOT_USED ,
												.ICPrescaler   = TIMER_NOT_USED ,
												.ICFilter       = TIMER_NOT_USED
											},
				.TIM_CHANNEL_CONFIG_t[1] = {	.TimChannel		= TIM_NUM_CH_1,
												.ChannelMode 	= IC_DIRECT_MODE_TI1 ,
												.PWMPolarity    = TIMER_NOT_USED,
												.ICPolarity     = IC_BOTH_EDGES ,
												.ICPrescaler   = IC_NO_PRESCALER ,
												.ICFilter       = IC_NO_FILTER
											}
		},

		[1] =
				{
						.TimNum			= TIM_NUM_3,
						.TimMode				= TIM_INPUT_OUTPUT,
						.TimDirection		= UP_COUNTER,
						.u16Prescaler			= 0,
						.numOfChannelUsed		=2,
						.TIM_CHANNEL_CONFIG_t[0] = {	.TimChannel		= TIM_NUM_CH_1,
														.ChannelMode 	= PWM_CHANNEL ,
														.PWMPolarity    = PWM_ACTIVE_HIGH,
														.ICPolarity     = TIMER_NOT_USED ,
														.ICPrescaler   = TIMER_NOT_USED ,
														.ICFilter       = TIMER_NOT_USED
													},
						.TIM_CHANNEL_CONFIG_t[1] = {	.TimChannel		= TIM_NUM_CH_1,
														.ChannelMode 	= IC_DIRECT_MODE_TI1 ,
														.PWMPolarity    = TIMER_NOT_USED,
														.ICPolarity     = IC_BOTH_EDGES ,
														.ICPrescaler   = IC_NO_PRESCALER ,
														.ICFilter       = IC_NO_FILTER
													}
				}
};
