/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT.h"
#include "GPT_Cnfg.h"
#include "GPT_Reg.h"
#include "Bit_Math.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
GptNotification Notifications[12]={};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 				
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
 void GPT_Init(const GPT_CONFIG_TYPE * TimersCnfg){
	#if TIMER0_PREDEF_SETTING == 0
	 /*GPT_PREDEF_TIMER_CONFIG_100US_32BIT*/
	 /*enable 32 bit wide timer 0*/
	 SET_BIT(RCGCWTIMER_REG,0);
	/*check timer is disabled before doing any changes*/
	if(GET_BIT(TIMER0_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER0_32BIT_GPTMCTL_REG,0);}
	/*put 0x00 in CFG*/
	TIMER0_32BIT_GPTMCFG_REG = 0x00;
	/*set in periodic mode*/
	TIMER0_32BIT_GPTMTAMR_REG |= 0x02 ;
	/*select 32 bit timer in CFG*/
	TIMER0_32BIT_GPTMCFG_REG = 0x04;
	/*set counting direction to counting down */
	CLR_BIT(TIMER0_32BIT_GPTMTAMR_REG,4);
	/*put 1 in prescaller*/
	 TIMER0_32BIT_GPTMTAPR_REG=1600;

	
	#elif TIMER0_PREDEF_SETTING == 1
	 /*GPT_PREDEF_TIMER_CONFIG_1US_16BIT*/
	/*enable clock to 16 bit timer 0*/
	SET_BIT(RCGCTIMER_REG,0);
	/*check timer is disabled before doing any changes*/
	if(GET_BIT(TIMER0_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER0_16BIT_GPTMCTL_REG,0);}
	/*put 0x00 in CFG*/
	TIMER0_16BIT_GPTMCFG_REG = 0x00;
	/*set in periodic mode*/
	TIMER0_16BIT_GPTMTAMR_REG |= 0x02 ;
	/*select 16 bit timer in CFG*/
	TIMER0_16BIT_GPTMCFG_REG = 0x4;
	/*set counting direction to counting down*/
	CLR_BIT(TIMER0_16BIT_GPTMTAMR_REG,4);
	/*put 1 in prescaller*/
	 TIMER0_16BIT_GPTMTAPR_REG =160;
	 
	#elif TIMER0_PREDEF_SETTING == 2 
	 /*GPT_PREDEF_TIMER_CONFIG_1US_24BIT*/
	/*enable 32 bit wide timer 0*/
	 SET_BIT(RCGCWTIMER_REG,0);
	/*check timer is disabled before doing any changes*/
	if(GET_BIT(TIMER0_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER0_32BIT_GPTMCTL_REG,0);}
	/*put 0x00 in CFG*/
	TIMER0_32BIT_GPTMCFG_REG = 0x00;
	/*set in periodic mode*/
	TIMER0_32BIT_GPTMTAMR_REG |= 0x02 ;
	/*select 32 bit timer in CFG*/
	TIMER0_32BIT_GPTMCFG_REG = 0x04;
	/*set counting direction to counting down */
	CLR_BIT(TIMER0_32BIT_GPTMTAMR_REG,4);
	/*put 1 in prescaller*/
	 TIMER0_32BIT_GPTMTAPR_REG=160;
	
	
	
	#elif TIMER0_PREDEF_SETTING == 3
	 /*GPT_PREDEF_TIMER_CONFIG_1US_32BIT*/
	/*enable 32 bit wide timer 0*/
	 SET_BIT(RCGCWTIMER_REG,0);
	/*check timer is disabled before doing any changes*/
	if(GET_BIT(TIMER0_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER0_32BIT_GPTMCTL_REG,0);}
	/*put 0x00 in CFG*/
	TIMER0_32BIT_GPTMCFG_REG = 0x00;
	/*set in periodic mode*/
	TIMER0_32BIT_GPTMTAMR_REG |= 0x02 ;
	/*select 32 bit timer in CFG*/
	TIMER0_32BIT_GPTMCFG_REG = 0x04;
	/*set counting direction to counting down */
	CLR_BIT(TIMER0_32BIT_GPTMTAMR_REG,4);
	/*put 1 in prescaller*/
	 TIMER0_32BIT_GPTMTAPR_REG=160;
	 
	 
	 /* static GPT_CONFIG_TYPE TimersCnfg [NUMBER_OF_ENABELED_TIMERS]={
    {TIMER_CHANNEL_0,16,65535,GPT_MODE_PERIODIC,NULL},
    {TIMER_CHANNEL_1,8,65535,GPT_MODE_ONE_SHOT,NULL}
};*/
	#elif TIMER0_PREDEF_SETTING == 4
	u8 i , prescallerValue , Local_GptMode;
	/*no predef*/
	for( i =0 ; i< NUMBER_OF_ENABELED_TIMERS;i++){
		prescallerValue = TimersCnfg[i].GptChannelTickFrequency;
		prescallerValue =16/prescallerValue;
		if(TimersCnfg[i].GptMode==GPT_MODE_PERIODIC)	{Local_GptMode = 0x02;}
		else{Local_GptMode = 0x01;}
		switch(TimersCnfg[i].ChannelId){
			case TIMER_CHANNEL_0:{
				/*enable clock to 16 bit timer 0*/
				SET_BIT(RCGCTIMER_REG,0);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER0_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER0_16BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER0_16BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER0_16BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER0_16BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER0_16BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER0_16BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[0] = TimersCnfg[i].callback;
				}
				break;
			}
			case TIMER_CHANNEL_1:{
				/*enable clock to 16 bit timer 0*/
				SET_BIT(RCGCTIMER_REG,1);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER1_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER1_16BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER1_16BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER1_16BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER1_16BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER1_16BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER1_16BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[1] = TimersCnfg[i].callback;
				}
				break;
			}
			case TIMER_CHANNEL_2:{
				/*enable clock to 16 bit timer 0*/
				SET_BIT(RCGCTIMER_REG,2);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER2_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER2_16BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER2_16BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER2_16BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER2_16BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER2_16BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER2_16BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[2] = TimersCnfg[i].callback;		
				}
				break;
			}
			case TIMER_CHANNEL_3:{
				/*enable clock to 16 bit timer 0*/
				SET_BIT(RCGCTIMER_REG,3);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER3_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER3_16BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER3_16BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER3_16BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER3_16BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER3_16BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER3_16BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[0] = TimersCnfg[3].callback;
				}
				break;
			}
			case TIMER_CHANNEL_4:{
				/*enable clock to 16 bit timer 0*/
				SET_BIT(RCGCTIMER_REG,4);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER4_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER4_16BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER4_16BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER4_16BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER4_16BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER4_16BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER4_16BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[4] = TimersCnfg[i].callback;	
				}
				break;
			}
			case TIMER_CHANNEL_5:{
				/*enable clock to 16 bit timer 0*/
				SET_BIT(RCGCTIMER_REG,5);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER5_16BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER5_16BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER5_16BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER5_16BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER5_16BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER5_16BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER5_16BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[5] = TimersCnfg[i].callback;		
				}
				break;
			}
			case TIMER_CHANNEL_6:{
			  /*enable clock to 32 bit timer 0*/
				SET_BIT(RCGCWTIMER_REG,0);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER0_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER0_32BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER0_32BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER0_32BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER0_32BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER0_32BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER0_32BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[6] = TimersCnfg[i].callback;
				}
				break;
			}
			case TIMER_CHANNEL_7:{
			  /*enable clock to 32 bit timer 0*/
				SET_BIT(RCGCWTIMER_REG,1);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER1_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER1_32BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER1_32BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER1_32BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER1_32BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER1_32BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER1_32BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[7] = TimersCnfg[i].callback;
				}			
				break;
			}
			case TIMER_CHANNEL_8:{
			  /*enable clock to 32 bit timer 0*/
				SET_BIT(RCGCWTIMER_REG,2);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER2_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER2_32BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER2_32BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER2_32BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER2_32BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER2_32BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER2_32BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[8] = TimersCnfg[i].callback;
				}				
				break;
			}
			case TIMER_CHANNEL_9:{
			  /*enable clock to 32 bit timer 0*/
				SET_BIT(RCGCWTIMER_REG,3);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER3_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER3_32BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER3_32BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER3_32BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER3_32BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER3_32BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER3_32BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[9] = TimersCnfg[i].callback;
				}			
				break;
			}
			case TIMER_CHANNEL_10:{
			  /*enable clock to 32 bit timer 0*/
				SET_BIT(RCGCWTIMER_REG,4);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER4_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER4_32BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER4_32BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER4_32BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER4_32BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER4_32BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER4_32BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[10] = TimersCnfg[i].callback;
				}			
				break;
			}
			case TIMER_CHANNEL_11:{
			  /*enable clock to 32 bit timer 0*/
				SET_BIT(RCGCWTIMER_REG,5);
				/*check timer is disabled before doing any changes*/
				if(GET_BIT(TIMER5_32BIT_GPTMCTL_REG,0)==1)	{CLR_BIT(TIMER5_32BIT_GPTMCTL_REG,0);}
				/*put 0x00 in CFG*/
				TIMER5_32BIT_GPTMCFG_REG = 0x00;
				/*set in periodic mode*/
				TIMER5_32BIT_GPTMTAMR_REG |= Local_GptMode ;
				/*select 16 bit timer in CFG*/
				TIMER5_32BIT_GPTMCFG_REG = 0x4;
				/*set counting direction to counting up*/
				SET_BIT(TIMER5_32BIT_GPTMTAMR_REG,4);
				/*configure in prescaller*/
				TIMER5_32BIT_GPTMTAPR_REG=prescallerValue;
				if(TimersCnfg[i].callback != NULL){
				/*save the pointer to function*/
				Notifications[11] = TimersCnfg[i].callback;
				}			
				break;
			}
			
		}
	}


	#endif
 }

 
 void GPT_StartTimer(TIMER_CHANNEL ChannelId ,u32 Value ){
		switch(ChannelId){
			case TIMER_CHANNEL_0:{
				/*set the counting bound */
				TIMER0_16BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER0_16BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_1:{
				/*set the counting bound */
				TIMER1_16BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER1_16BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_2:{
				/*set the counting bound */
				TIMER2_16BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER2_16BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_3:{
				/*set the counting bound */
				TIMER3_16BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER3_16BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_4:{
				/*set the counting bound */
				TIMER4_16BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER4_16BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_5:{
				/*set the counting bound */
				TIMER5_16BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER0_16BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_6:{
				/*set the counting bound */
				TIMER0_32BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER0_32BIT_GPTMCTL_REG,0);
				break;
			}
			case TIMER_CHANNEL_7:{
				/*set the counting bound */
				TIMER1_32BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER1_32BIT_GPTMCTL_REG,0);		
				break;
			}
			case TIMER_CHANNEL_8:{
				/*set the counting bound */
				TIMER2_32BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER2_32BIT_GPTMCTL_REG,0);			
				break;
			}
			case TIMER_CHANNEL_9:{
				/*set the counting bound */
				TIMER3_32BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER3_32BIT_GPTMCTL_REG,0);			
				break;
			}
			case TIMER_CHANNEL_10:{
				/*set the counting bound */
				TIMER4_32BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER4_32BIT_GPTMCTL_REG,0);			
				break;
			}
			case TIMER_CHANNEL_11:{
				/*set the counting bound */
				TIMER5_32BIT_GPTMTAILR_REG = Value ;
				/*enable timer 0*/
				SET_BIT(TIMER5_32BIT_GPTMCTL_REG,0);			
				break;
			}
			
		}
}
 

void GPT_StopTimer(TIMER_CHANNEL ChannelId){
	switch(ChannelId){
		case TIMER_CHANNEL_0:TIMER0_16BIT_GPTMCTL_REG =0x00; break;
		case TIMER_CHANNEL_1:TIMER1_16BIT_GPTMCTL_REG =0x00;break;
		case TIMER_CHANNEL_2:TIMER2_16BIT_GPTMCTL_REG =0x00;break;
		case TIMER_CHANNEL_3:TIMER3_16BIT_GPTMCTL_REG =0x00;break;
		case TIMER_CHANNEL_4:TIMER4_16BIT_GPTMCTL_REG =0x00;break;
		case TIMER_CHANNEL_5:TIMER5_16BIT_GPTMCTL_REG =0x00;break;
		case TIMER_CHANNEL_6:TIMER0_32BIT_GPTMCTL_REG = 0x00; break;
		case TIMER_CHANNEL_7:TIMER1_32BIT_GPTMCTL_REG = 0x00;break;
		case TIMER_CHANNEL_8:TIMER2_32BIT_GPTMCTL_REG = 0x00;break;
		case TIMER_CHANNEL_9:TIMER3_32BIT_GPTMCTL_REG = 0x00;break;
		case TIMER_CHANNEL_10:TIMER4_32BIT_GPTMCTL_REG = 0x00;break;
		case TIMER_CHANNEL_11:TIMER5_32BIT_GPTMCTL_REG = 0x00;break;
	
	}
}
u32 GPT_GetTimeElapsed(TIMER_CHANNEL ChannelId){
	switch(ChannelId){
		case TIMER_CHANNEL_0: return(TIMER0_16BIT_GPTMTAR_REG * TIMER0_16BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_1: return(TIMER1_16BIT_GPTMTAR_REG * TIMER1_16BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_2: return(TIMER2_16BIT_GPTMTAR_REG * TIMER2_16BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_3: return(TIMER3_16BIT_GPTMTAR_REG * TIMER3_16BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_4: return(TIMER4_16BIT_GPTMTAR_REG * TIMER4_16BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_5: return(TIMER5_16BIT_GPTMTAR_REG * TIMER5_16BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_6: return(TIMER0_32BIT_GPTMTAR_REG * TIMER0_32BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_7: return(TIMER1_32BIT_GPTMTAR_REG * TIMER1_32BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_8: return(TIMER2_32BIT_GPTMTAR_REG * TIMER2_32BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_9: return(TIMER3_32BIT_GPTMTAR_REG * TIMER3_32BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_10:return(TIMER4_32BIT_GPTMTAR_REG * TIMER4_32BIT_GPTMTAPR_REG);
		case TIMER_CHANNEL_11:return(TIMER5_32BIT_GPTMTAR_REG * TIMER5_32BIT_GPTMTAPR_REG);
	
	}
}
u32 GPT_GetTimeRemaining(TIMER_CHANNEL ChannelId){
	switch(ChannelId){
		case TIMER_CHANNEL_0: return(TIMER0_16BIT_GPTMTAILR_REG - TIMER0_16BIT_GPTMTAR_REG)* TIMER0_16BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_1: return(TIMER1_16BIT_GPTMTAILR_REG - TIMER1_16BIT_GPTMTAR_REG)* TIMER1_16BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_2: return(TIMER2_16BIT_GPTMTAILR_REG - TIMER2_16BIT_GPTMTAR_REG)* TIMER2_16BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_3: return(TIMER3_16BIT_GPTMTAILR_REG - TIMER3_16BIT_GPTMTAR_REG)* TIMER3_16BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_4: return(TIMER4_16BIT_GPTMTAILR_REG - TIMER4_16BIT_GPTMTAR_REG)* TIMER4_16BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_5: return(TIMER5_16BIT_GPTMTAILR_REG - TIMER5_16BIT_GPTMTAR_REG)* TIMER5_16BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_6: return(TIMER0_32BIT_GPTMTAILR_REG - TIMER0_32BIT_GPTMTAR_REG)* TIMER0_32BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_7: return(TIMER1_32BIT_GPTMTAILR_REG - TIMER1_32BIT_GPTMTAR_REG)* TIMER1_32BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_8: return(TIMER2_32BIT_GPTMTAILR_REG - TIMER2_32BIT_GPTMTAR_REG)* TIMER2_32BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_9: return(TIMER3_32BIT_GPTMTAILR_REG - TIMER3_32BIT_GPTMTAR_REG)* TIMER3_32BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_10:return(TIMER4_32BIT_GPTMTAILR_REG - TIMER4_32BIT_GPTMTAR_REG)* TIMER4_32BIT_GPTMTAPR_REG ;
		case TIMER_CHANNEL_11:return(TIMER5_32BIT_GPTMTAILR_REG - TIMER5_32BIT_GPTMTAR_REG)* TIMER5_32BIT_GPTMTAPR_REG ;
	
	}
}
u8 GPT_GetPredefTimerValue( GPT_PREDEF_TIMER_CONFIG PredefTimer , u32*TimerValuePtr){
	u8 localReturnFlag = RT_NOK;
	#if TIMER0_PREDEF_SETTING == 4
	return localReturnFlag ;
	#else
	localReturnFlag = RT_OK ;
	switch(PredefTimer){
	case GPT_PREDEF_TIMER_CONFIG_100US_32BIT:*TimerValuePtr = (TIMER0_32BIT_GPTMTAR_REG) *1600 ;break;
	case GPT_PREDEF_TIMER_CONFIG_1US_16BIT:*TimerValuePtr = (TIMER0_16BIT_GPTMTAR_REG)*160 ;break;
	case GPT_PREDEF_TIMER_CONFIG_1US_24BIT:*TimerValuePtr = ( (TIMER0_32BIT_GPTMTAR_REG) *160 << 8) ;break;
	case GPT_PREDEF_TIMER_CONFIG_1US_32BIT:*TimerValuePtr = (TIMER0_32BIT_GPTMTAR_REG) *160 ;break;
	default: localReturnFlag = RT_NOK;
	}
	return (localReturnFlag);
	#endif
}

void GPT_EnableNotification(TIMER_CHANNEL ChannelId){
	switch(ChannelId){
		case TIMER_CHANNEL_0:  SET_BIT(TIMER0_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_1:  SET_BIT(TIMER1_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_2:  SET_BIT(TIMER2_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_3:  SET_BIT(TIMER3_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_4:  SET_BIT(TIMER4_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_5:  SET_BIT(TIMER5_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_6:  SET_BIT(TIMER0_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_7:  SET_BIT(TIMER1_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_8:  SET_BIT(TIMER2_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_9:  SET_BIT(TIMER3_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_10: SET_BIT(TIMER4_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_11: SET_BIT(TIMER5_32BIT_GPTMIMR_REG,0); break;
	
	}
}
void GPT_DisbleNotification(TIMER_CHANNEL ChannelId){
	switch(ChannelId){
		case TIMER_CHANNEL_0:  CLR_BIT(TIMER0_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_1:  CLR_BIT(TIMER1_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_2:  CLR_BIT(TIMER2_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_3:  CLR_BIT(TIMER3_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_4:  CLR_BIT(TIMER4_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_5:  CLR_BIT(TIMER5_16BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_6:  CLR_BIT(TIMER0_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_7:  CLR_BIT(TIMER1_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_8:  CLR_BIT(TIMER2_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_9:  CLR_BIT(TIMER3_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_10: CLR_BIT(TIMER4_32BIT_GPTMIMR_REG,0); break;
		case TIMER_CHANNEL_11: CLR_BIT(TIMER5_32BIT_GPTMIMR_REG,0); break;
	
	}
}
void TIMER0A_Handler(void){
	Notifications[0]();
	TIMER0_16BIT_GPTMICR_REG = 0x01;
}
void TIMER1A_Handler(void){
	Notifications[1]();
	TIMER1_16BIT_GPTMICR_REG = 0x01;
}
void TIMER2A_Handler(void){
	Notifications[2]();
	TIMER2_16BIT_GPTMICR_REG = 0x01;
}
void TIMER3A_Handler(void){
	Notifications[3]();
	TIMER3_16BIT_GPTMICR_REG = 0x01;
}
void TIMER4A_Handler(void){
	Notifications[4]();
	TIMER4_16BIT_GPTMICR_REG = 0x01;
}
void TIMER5A_Handler(void){
	Notifications[5]();
	TIMER5_16BIT_GPTMICR_REG = 0x01;
}



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/





/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/