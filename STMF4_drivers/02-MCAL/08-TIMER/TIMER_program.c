#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"TIMER_interface.h"
#include"TIMER_private.h"
#include "TIMER_config.h"

extern TIM_CONFIG_t globalTimersConfigs[];
void TIMER_vidInit(void){
	u8 LOC_u8Counter;
	TIM_CONFIG_t LOC_struct_timer_config;
	for (LOC_u8Counter = 0; LOC_u8Counter < NUM_OF_TIM_USED; LOC_u8Counter++)
	{
		/*take a copy of the timer config struct localy */
		LOC_struct_timer_config = globalTimersConfigs[LOC_u8Counter];
		switch(LOC_struct_timer_config.TimNum){
		case TIM_NUM_2:{
			/*add prescaller value */
			TIM2_R->PSC.BIT.PSC = LOC_struct_timer_config.u16Prescaler;
			/*up count or down count*/
			TIM2_R->CR1.BIT.DIR = LOC_struct_timer_config.TimDirection;
			if(LOC_struct_timer_config.TimMode == TIM_DELAY){
				/*should be handled to operate timer as delay only and enable its interrupt */
			}
			/*Timer as PWM or IC*/
			else{
				u8 LOC_u8ChannelCounter;
				TIM_CHANNEL_CONFIG_t LOC_structChannelConfig;
				/*iterate through every channel config*/
				for(LOC_u8ChannelCounter =0 ; LOC_u8ChannelCounter <LOC_struct_timer_config.numOfChannelUsed ; LOC_u8ChannelCounter ++){
					/*take a local copy for every channel config struct */
					LOC_structChannelConfig = LOC_struct_timer_config.channelConfig;
					switch (LOC_structChannelConfig.TimChannel){
					case TIM_NUM_CH_1: {
						//TIM3_R->CCER.BIT.CC1E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM2_R->CCMR1.BIT_OCM.CC1S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM2_R->CCMR1.BIT_OCM.OC1M = 0b110;
							/*PWM polarity active high or active low */
							TIM2_R->CCER.BIT.CC1P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM2_R->CCMR1.BIT_OCM.OC1PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM2_R->CCMR1.BIT_ICM.CC1S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM2_R->CCMR1.BIT_ICM.IC1PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM2_R->CCMR1.BIT_ICM.IC1F = LOC_structChannelConfig.ICFilter;

							TIM2_R->CCER.BIT.CC1P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM2_R->CCER.BIT.CC1NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					case TIM_NUM_CH_2: {
						//TIM3_R->CCER.BIT.CC2E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM2_R->CCMR1.BIT_OCM.CC2S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM2_R->CCMR1.BIT_OCM.OC2M = 0b110;
							/*PWM polarity active high or active low */
							TIM2_R->CCER.BIT.CC2P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM2_R->CCMR1.BIT_OCM.OC2PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM2_R->CCMR1.BIT_ICM.CC2S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM2_R->CCMR1.BIT_ICM.IC2PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM2_R->CCMR1.BIT_ICM.IC2F = LOC_structChannelConfig.ICFilter;

							TIM2_R->CCER.BIT.CC2P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM2_R->CCER.BIT.CC2NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					case TIM_NUM_CH_3: {
						//TIM3_R->CCER.BIT.CC3E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM2_R->CCMR2.BIT_OCM.CC3S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM2_R->CCMR2.BIT_OCM.OC3M = 0b110;
							/*PWM polarity active high or active low */
							TIM2_R->CCER.BIT.CC3P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM2_R->CCMR2.BIT_OCM.OC3PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM2_R->CCMR2.BIT_ICM.CC3S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM2_R->CCMR2.BIT_ICM.IC3PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM2_R->CCMR2.BIT_ICM.IC3F = LOC_structChannelConfig.ICFilter;

							TIM2_R->CCER.BIT.CC3P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM2_R->CCER.BIT.CC3NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					case TIM_NUM_CH_4: {
						//TIM2_R->CCER.BIT.CC4E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM2_R->CCMR2.BIT_OCM.CC4S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM2_R->CCMR2.BIT_OCM.OC4M = 0b110;
							/*PWM polarity active high or active low */
							TIM2_R->CCER.BIT.CC4P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM2_R->CCMR2.BIT_OCM.OC4PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM2_R->CCMR2.BIT_ICM.CC4S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM2_R->CCMR2.BIT_ICM.IC4PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM1_R->CCMR2.BIT_ICM.IC4F = LOC_structChannelConfig.ICFilter;

							TIM2_R->CCER.BIT.CC4P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM2_R->CCER.BIT.CC4NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					}
				}
			}
		}break;

		case TIM_NUM_3:{
			/*add prescaller value */
			TIM3_R->PSC.BIT.PSC = LOC_struct_timer_config.u16Prescaler;
			/*up count or down count*/
			TIM3_R->CR1.BIT.DIR = LOC_struct_timer_config.TimDirection;
			if(LOC_struct_timer_config.TimMode == TIM_DELAY){
				/*should be handled to operate timer as delay only and enable its interrupt */
			}
			/*Timer as PWM or IC*/
			else{
				u8 LOC_u8ChannelCounter;
				TIM_CHANNEL_CONFIG_t LOC_structChannelConfig;
				/*iterate through every channel config*/
				for(LOC_u8ChannelCounter =0 ; LOC_u8ChannelCounter <LOC_struct_timer_config.numOfChannelUsed ; LOC_u8ChannelCounter ++){
					/*take a local copy for every channel config struct */
					LOC_structChannelConfig = LOC_struct_timer_config.channelConfig;
					switch (LOC_structChannelConfig.TimChannel){
					case TIM_NUM_CH_1: {
						//TIM3_R->CCER.BIT.CC1E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM3_R->CCMR1.BIT_OCM.CC1S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM3_R->CCMR1.BIT_OCM.OC1M = 0b110;
							/*PWM polarity active high or active low */
							TIM3_R->CCER.BIT.CC1P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM3_R->CCMR1.BIT_OCM.OC1PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM3_R->CCMR1.BIT_ICM.CC1S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM3_R->CCMR1.BIT_ICM.IC1PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM3_R->CCMR1.BIT_ICM.IC1F = LOC_structChannelConfig.ICFilter;

							TIM3_R->CCER.BIT.CC1P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM3_R->CCER.BIT.CC1NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					case TIM_NUM_CH_2: {
						//TIM3_R->CCER.BIT.CC2E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM3_R->CCMR1.BIT_OCM.CC2S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM3_R->CCMR1.BIT_OCM.OC2M = 0b110;
							/*PWM polarity active high or active low */
							TIM3_R->CCER.BIT.CC2P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM3_R->CCMR1.BIT_OCM.OC2PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM3_R->CCMR1.BIT_ICM.CC2S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM3_R->CCMR1.BIT_ICM.IC2PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM3_R->CCMR1.BIT_ICM.IC2F = LOC_structChannelConfig.ICFilter;

							TIM3_R->CCER.BIT.CC2P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM3_R->CCER.BIT.CC2NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					case TIM_NUM_CH_3: {
						//TIM3_R->CCER.BIT.CC3E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM3_R->CCMR2.BIT_OCM.CC3S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM3_R->CCMR2.BIT_OCM.OC3M = 0b110;
							/*PWM polarity active high or active low */
							TIM3_R->CCER.BIT.CC3P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM3_R->CCMR2.BIT_OCM.OC3PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM3_R->CCMR2.BIT_ICM.CC3S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM3_R->CCMR2.BIT_ICM.IC3PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM3_R->CCMR2.BIT_ICM.IC3F = LOC_structChannelConfig.ICFilter;

							TIM3_R->CCER.BIT.CC3P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM3_R->CCER.BIT.CC3NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					case TIM_NUM_CH_4: {
						//TIM3_R->CCER.BIT.CC4E = FALSE
						if(LOC_structChannelConfig.ChannelMode == PWM_CHANNEL){
							/*select channel mode*/
							TIM3_R->CCMR2.BIT_OCM.CC4S = LOC_structChannelConfig.ChannelMode;
							/*: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 */
							TIM3_R->CCMR2.BIT_OCM.OC4M = 0b110;
							/*PWM polarity active high or active low */
							TIM3_R->CCER.BIT.CC4P = LOC_structChannelConfig.PWMPolarity;
							/*activate preload*/
							TIM3_R->CCMR2.BIT_OCM.OC4PE = TRUE;
						}
						else
						{
							/*select channel mode*/
							TIM3_R->CCMR2.BIT_ICM.CC4S = LOC_structChannelConfig.ChannelMode;
							/*prescaler value*/
							TIM3_R->CCMR2.BIT_ICM.IC4PSC = LOC_structChannelConfig.ICPrescaler;
							/*filter value */
							TIM3_R->CCMR2.BIT_ICM.IC4F = LOC_structChannelConfig.ICFilter;

							TIM3_R->CCER.BIT.CC4P = GET_BIT(LOC_structChannelConfig.ICPolarity, 0);
							TIM3_R->CCER.BIT.CC4NP = GET_BIT(LOC_structChannelConfig.ICPolarity, 1);
						}
					}break;

					}
				}
			}
		}break;

		}
	}
}


void TIMER_vidICStart (TIM_NUM TimerNumber, TIM_CH TimerChannel  ){
	switch(TimerNumber){
	case TIM_NUM_2:{
		/*auto reload value */
		TIM2_R->ARR.BIT.ARR = 0xFFFF;
		/*disable counter */
		TIM2_R->CR1.BIT.CEN = FALSE;
		/*switch on channel and enable its capture mode*/
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
			TIM2_R->CCER.BIT.CC1E = 1;
			break;
		case TIM_NUM_CH_2:
			TIM2_R->CCER.BIT.CC2E = 1;
			break;
		case TIM_NUM_CH_3:
			TIM2_R->CCER.BIT.CC3E = 1;
			break;
		case TIM_NUM_CH_4:
			TIM2_R->CCER.BIT.CC4E = 1;
			break;
		}
		if ( !TIM2_R->CR1.BIT.CEN)
		{
			/*enable counter*/
			TIM2_R->CR1.BIT.CEN = TRUE;
		}
	}break;
	case TIM_NUM_3:{/*auto reload value */
		TIM3_R->ARR.BIT.ARR = 0xFFFF;
		/*disable counter */
		TIM3_R->CR1.BIT.CEN = FALSE;
		/*switch on channel and enable its capture mode*/
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
			TIM3_R->CCER.BIT.CC1E = 1;
			break;
		case TIM_NUM_CH_2:
			TIM3_R->CCER.BIT.CC2E = 1;
			break;
		case TIM_NUM_CH_3:
			TIM3_R->CCER.BIT.CC3E = 1;
			break;
		case TIM_NUM_CH_4:
			TIM3_R->CCER.BIT.CC4E = 1;
			break;
		}
		if ( !TIM3_R->CR1.BIT.CEN)
		{
			/*enable counter*/
			TIM3_R->CR1.BIT.CEN = TRUE;
		}}break;
	}
}

void TIMER_vidICStop (TIM_NUM TimerNumber, TIM_CH TimerChannel  ){
	switch(TimerNumber){
	case TIM_NUM_2:{
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
			TIM2_R->CCER.BIT.CC1E = 0;
			break;
		case TIM_NUM_CH_2:
			TIM2_R->CCER.BIT.CC2E = 0;
			break;
		case TIM_NUM_CH_3:
			TIM2_R->CCER.BIT.CC3E = 0;
			break;
		case TIM_NUM_CH_4:
			TIM2_R->CCER.BIT.CC4E = 0;
			break;
		}

	}break;
	case TIM_NUM_3:{/*auto reload value */
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
			TIM3_R->CCER.BIT.CC1E = 0;
			break;
		case TIM_NUM_CH_2:
			TIM3_R->CCER.BIT.CC2E = 0;
			break;
		case TIM_NUM_CH_3:
			TIM3_R->CCER.BIT.CC3E = 0;
			break;
		case TIM_NUM_CH_4:
			TIM3_R->CCER.BIT.CC4E = 0;
			break;
		}

	}break;
	}
}

u32 TIMER_u32ICGetCapturedValue(TIM_NUM TimerNumber, TIM_CH TimerChannel){
	u32 LOC_u32CapturedValue = 0;

	switch(TimerNumber){
	case TIM_NUM_2:{
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
		{
			/*polling  on capture flag */
			while (TIM2_R->SR.BIT.CC1IF == 0);
			/*check for no overcapture flag*/
			while ( TIM2_R->SR.BIT.CC1OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM2_R->CCR1.BIT.CCR1);
			/*reset the capture flags */
			TIM2_R->SR.BIT.CC1IF = FALSE;
			TIM2_R->SR.BIT.CC1OF = FALSE;
		}
		break;
		case TIM_NUM_CH_2:
		{
			/*polling  on capture flag */
			while (TIM2_R->SR.BIT.CC2IF == 0);
			/*check for no overcapture flag*/
			while ( TIM2_R->SR.BIT.CC2OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM2_R->CCR2.BIT.CCR2);
			/*reset the capture flags */
			TIM2_R->SR.BIT.CC2IF = FALSE;
			TIM2_R->SR.BIT.CC2OF = FALSE;
		}
		break;
		case TIM_NUM_CH_3:
		{
			/*polling  on capture flag */
			while (TIM2_R->SR.BIT.CC3IF == 0);
			/*check for no overcapture flag*/
			while ( TIM2_R->SR.BIT.CC3OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM2_R->CCR3.BIT.CCR3);
			/*reset the capture flags */
			TIM2_R->SR.BIT.CC3IF = FALSE;
			TIM2_R->SR.BIT.CC3OF = FALSE;
		}
		break;
		case TIM_NUM_CH_4:
		{
			/*polling  on capture flag */
			while (TIM2_R->SR.BIT.CC4IF == 0);
			/*check for no overcapture flag*/
			while ( TIM2_R->SR.BIT.CC4OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM2_R->CCR4.BIT.CCR4);
			/*reset the capture flags */
			TIM2_R->SR.BIT.CC4IF = FALSE;
			TIM2_R->SR.BIT.CC4OF = FALSE;
		}
		break;
		}

	}break;
	case TIM_NUM_3:{/*auto reload value */
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
		{
			/*polling  on capture flag */
			while (TIM3_R->SR.BIT.CC1IF == 0);
			/*check for no overcapture flag*/
			while ( TIM3_R->SR.BIT.CC1OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM3_R->CCR1.BIT.CCR1);
			/*reset the capture flags */
			TIM3_R->SR.BIT.CC1IF = FALSE;
			TIM3_R->SR.BIT.CC1OF = FALSE;
		}
		break;
		case TIM_NUM_CH_2:
		{
			/*polling  on capture flag */
			while (TIM3_R->SR.BIT.CC2IF == 0);
			/*check for no overcapture flag*/
			while ( TIM3_R->SR.BIT.CC2OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM3_R->CCR2.BIT.CCR2);
			/*reset the capture flags */
			TIM3_R->SR.BIT.CC2IF = FALSE;
			TIM3_R->SR.BIT.CC2OF = FALSE;
		}
		break;
		case TIM_NUM_CH_3:
		{
			/*polling  on capture flag */
			while (TIM3_R->SR.BIT.CC3IF == 0);
			/*check for no overcapture flag*/
			while ( TIM3_R->SR.BIT.CC3OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM3_R->CCR3.BIT.CCR3);
			/*reset the capture flags */
			TIM3_R->SR.BIT.CC3IF = FALSE;
			TIM3_R->SR.BIT.CC3OF = FALSE;
		}
		break;
		case TIM_NUM_CH_4:
		{
			/*polling  on capture flag */
			while (TIM3_R->SR.BIT.CC4IF == 0);
			/*check for no overcapture flag*/
			while ( TIM3_R->SR.BIT.CC4OF == 1);
			//save the capture value
			LOC_u32CapturedValue = (u32)(TIM3_R->CCR4.BIT.CCR4);
			/*reset the capture flags */
			TIM3_R->SR.BIT.CC4IF = FALSE;
			TIM3_R->SR.BIT.CC4OF = FALSE;
		}
		break;
		}

	}break;
	}
}
void TIMER_vidPWMStart(TIM_NUM TimerNumber, TIM_CH TimerChannel, f32 Copy_f32SignalFreqInHz, PWM_DUTY_CYCLE_PERCENTAGE Copy_enmDutyCyclePer){
	u8 	LOC_u8Counter;
	u32 LOC_u32ArrValue = 0;
	f32 LOC_f32TimerFreq = 0;
	u16 LOC_u16TimerPrescaler = 0;
	u32 LOC_u32CCRxValue = 0;

	/*get the value of prescaller from config array*/
	for(LOC_u8Counter = 0; LOC_u8Counter < NUM_OF_TIM_USED; LOC_u8Counter++)
	{
		if(TimerNumber == globalTimersConfigs[LOC_u8Counter].TimNum)
		{
			LOC_u16TimerPrescaler = globalTimersConfigs[LOC_u8Counter].u16Prescaler;
			LOC_u16TimerPrescaler++;
			break;
		}
		else{}
	}
	/*timer frequency = 16*1000000 / prescaler*/
	LOC_f32TimerFreq =(((f32)TIM_CLK_IN_MHZ)*(1000000.0/((f32)LOC_u16TimerPrescaler)));
	//number of ticks needed to get the signal frequency needing
	LOC_u32ArrValue = (u32)(LOC_f32TimerFreq/Copy_f32SignalFreqInHz);
	/*calculate ticks for rquired duty cycle*/
	if(PWM_12_PERCENTAGE == Copy_enmDutyCyclePer)
	{
		LOC_u32CCRxValue = (u32)(((f32)LOC_u32ArrValue)*(((f32)12.5)/100.0));

	}
	else
	{
		LOC_u32CCRxValue = (u32)(((f32)LOC_u32ArrValue)*(((f32)Copy_enmDutyCyclePer)/100.0));
	}
	switch(TimerNumber){
	case TIM_NUM_2:{
		/*auto reload value */
		TIM2_R->ARR.REGISTER = LOC_u32ArrValue;
		/*disable counting*/
		TIM2_R->CR1.BIT.CEN = FALSE;
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
		{
			/*add pwm value for specified duty cycle*/
			TIM2_R->CCR1.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM2_R->CCER.BIT.CC1E = 1;
		}
		break;
		case TIM_NUM_CH_2:
		{
			/*add pwm value for specified duty cycle*/
			TIM2_R->CCR2.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM2_R->CCER.BIT.CC2E = 1;
		}
		break;
		case TIM_NUM_CH_3:
		{
			/*add pwm value for specified duty cycle*/
			TIM2_R->CCR3.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM2_R->CCER.BIT.CC3E = 1;
		}
		break;
		case TIM_NUM_CH_4:
		{
			/*add pwm value for specified duty cycle*/
			TIM2_R->CCR4.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM2_R->CCER.BIT.CC4E = 1;
		}
		break;
		}

	}break;

	case TIM_NUM_3:{
		/*auto reload value */
		TIM3_R->ARR.REGISTER = LOC_u32ArrValue;
		/*disable counting*/
		TIM3_R->CR1.BIT.CEN = FALSE;
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
		{
			/*add pwm value for specified duty cycle*/
			TIM3_R->CCR1.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM3_R->CCER.BIT.CC1E = 1;
		}
		break;
		case TIM_NUM_CH_2:
		{
			/*add pwm value for specified duty cycle*/
			TIM3_R->CCR2.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM3_R->CCER.BIT.CC2E = 1;
		}
		break;
		case TIM_NUM_CH_3:
		{
			/*add pwm value for specified duty cycle*/
			TIM3_R->CCR3.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM3_R->CCER.BIT.CC3E = 1;
		}
		break;
		case TIM_NUM_CH_4:
		{
			/*add pwm value for specified duty cycle*/
			TIM3_R->CCR4.REGISTER = LOC_u32CCRxValue;
			/*enable signle output on pin*/
			TIM3_R->CCER.BIT.CC4E = 1;
		}
		break;
		}

	}break;

	}
}


void TIMER_vidPWMStop(TIM_NUM TimerNumber, TIM_CH TimerChannel){
	switch(TimerNumber){
	case TIM_NUM_2:{
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
		{

			/*disable signle output on pin*/
			TIM2_R->CCER.BIT.CC1E = 0;
		}
		break;
		case TIM_NUM_CH_2:
		{

			/*disable signle output on pin*/
			TIM2_R->CCER.BIT.CC2E = 0;
		}
		break;
		case TIM_NUM_CH_3:
		{

			/*disable signle output on pin*/
			TIM2_R->CCER.BIT.CC3E = 0;
		}
		break;
		case TIM_NUM_CH_4:
		{

			/*disable signle output on pin*/
			TIM2_R->CCER.BIT.CC4E = 0;
		}
		break;
		}

	}break;

	case TIM_NUM_3:{
		switch (TimerChannel)
		{
		case TIM_NUM_CH_1:
		{

			/*disable signle output on pin*/
			TIM3_R->CCER.BIT.CC1E = 0;
		}
		break;
		case TIM_NUM_CH_2:
		{

			/*disable signle output on pin*/
			TIM3_R->CCER.BIT.CC2E = 0;
		}
		break;
		case TIM_NUM_CH_3:
		{

			/*disable signle output on pin*/
			TIM3_R->CCER.BIT.CC3E = 0;
		}
		break;
		case TIM_NUM_CH_4:
		{

			/*disable signle output on pin*/
			TIM3_R->CCER.BIT.CC4E = 0;
		}
		break;
		}

	}break;

	}
}
