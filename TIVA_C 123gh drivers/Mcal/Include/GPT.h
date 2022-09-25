/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT_Cnfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef   void (*GptNotification)(void);

typedef enum {
	TIMER_CHANNEL_0 = 0 ,
	TIMER_CHANNEL_1 = 1 ,
	TIMER_CHANNEL_2 = 2 ,
	TIMER_CHANNEL_3 = 3 ,
	TIMER_CHANNEL_4 = 4 ,
	TIMER_CHANNEL_5 = 5 ,
	TIMER_CHANNEL_6 =	6 ,
	TIMER_CHANNEL_7 = 7 ,
	TIMER_CHANNEL_8 = 8 ,
	TIMER_CHANNEL_9 = 9 ,
	TIMER_CHANNEL_10 = 10 ,
	TIMER_CHANNEL_11= 11 
}TIMER_CHANNEL;



typedef enum{
	GPT_MODE_ONE_SHOT = 0 ,
	GPT_MODE_PERIODIC = 1 
}GPT_MODE;

typedef struct {
	TIMER_CHANNEL ChannelId ;
	u8  GptChannelTickFrequency;
	u32 GptChannelTickValueMax ;
	GPT_MODE GptMode;
	GptNotification callback ;
}GPT_CONFIG_TYPE;





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void GPT_Init(const GPT_CONFIG_TYPE * TimersCnfg);
void GPT_StartTimer(TIMER_CHANNEL ChannelId ,u32 Value );
void GPT_StopTimer(TIMER_CHANNEL ChannelId);
u32 GPT_GetTimeElapsed(TIMER_CHANNEL ChannelId);
u32 GPT_GetTimeRemaining(TIMER_CHANNEL ChannelId);
u8 GPT_GetPredefTimerValue( GPT_PREDEF_TIMER_CONFIG PredefTimer , u32*TimerValuePtr);
void GPT_EnableNotification(TIMER_CHANNEL ChannelId);
void GPT_DisbleNotification(TIMER_CHANNEL ChannelId);

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/