#include "Systick.h"
#include "GPT.h"
#include "DIO.h"
#include "IntCtrl.h"
/*#include "TM4C123.h"*/
void ledToggleControl (u32 OnTicks , u32 OffTicks);
void ledOn(void);
void ledOff(void);
void ISR_control (void);
volatile static u32  OnTicksPtr ;
volatile static u32  OffTicksPtr ;


int main(void){

	Systick_setRawClkSrc();
	IntCrtl_Init();
	DIO_setPortDirection(DIO_PortType_Port_F,DIO_Direction_OUTPUT);
	static GPT_CONFIG_TYPE TimersCnfg [NUMBER_OF_ENABELED_TIMERS]={
    {TIMER_CHANNEL_0,16,65535,GPT_MODE_PERIODIC,ledOff} ,
		{TIMER_CHANNEL_1,16,65535,GPT_MODE_PERIODIC,ledOn} 
};

	GPT_Init(TimersCnfg);
	GPT_EnableNotification(TIMER_CHANNEL_0);
	GPT_EnableNotification(TIMER_CHANNEL_1);
	ledToggleControl(100,10);
	GPT_StartTimer(TIMER_CHANNEL_1 ,  OffTicksPtr );
	while(1){

	
	}
}
void ledOn(void){
		DIO_WritePort(DIO_PortType_Port_F,0xFF);
		GPT_StartTimer(TIMER_CHANNEL_0 ,  OnTicksPtr);
		GPT_StopTimer(TIMER_CHANNEL_1);
		


		
	
}
void ledOff(void){
		DIO_WritePort(DIO_PortType_Port_F,0x00);
		GPT_StartTimer(TIMER_CHANNEL_1 ,  OffTicksPtr);
		GPT_StopTimer(TIMER_CHANNEL_0);

}
void ledToggleControl (u32 OnTicks , u32 OffTicks){
	OnTicksPtr = OnTicks ;
	OffTicksPtr = OffTicks ;
	
}

