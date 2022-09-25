#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../../01-LIB/03-ERROR_STATUS/ERROR_STATUS.h"

#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"

void RCC_voidInit(){/*reg CR and CFGR */
	#if RCC_OSCILATOE_SRC==0 
	/*Enable HSI oscillator */
	SET_BIT(RCC_CR , 0);
	SET_BIT(RCC_CR , 7);
	/*poll on HSI is ready flag  */
	while(!GET_BIT(RCC_CR,1));
	//RCC_CFGR= 0x00000000;
	/*prescaller div by 2 */
	SET_BIT(RCC_CFGR , 7);
	#else
	
	/*Enable HSE oscillator */
	SET_BIT(RCC_CR , 16);
	RCC_CFGR= 0x00000001;
	
	/*poll on HSE is ready flag  */
	while(!GET_BIT(RCC_CR,17));
	
	#endif
	
}
void RCC_voidEnablePeripheralClock(PERIPHRAL PeriphralId){
	switch(PeriphralId){
		case PERIPHRAL_GPIO_A 	:	SET_BIT(RCC_AHB1ENR , 0) ;break;
		case PERIPHRAL_GPIO_B 	:	SET_BIT(RCC_AHB1ENR , 1) ;break;
		case PERIPHRAL_GPIO_C 	:	SET_BIT(RCC_AHB1ENR , 2) ;break;
		case PERIPHRAL_GPIO_D 	:	SET_BIT(RCC_AHB1ENR , 3) ;break;
		case PERIPHRAL_GPIO_E 	:	SET_BIT(RCC_AHB1ENR , 4) ;break;
		case PERIPHRAL_GPIO_H 	:	SET_BIT(RCC_AHB1ENR , 7) ;break;
		case PERIPHRAL_CRC 	  	:	SET_BIT(RCC_AHB1ENR , 12);break;
		case PERIPHRAL_DMA_1  	:	SET_BIT(RCC_AHB1ENR ,21 );break;
		case PERIPHRAL__DMA_2 	:	SET_BIT(RCC_AHB1ENR ,22 );break;
		case PERIPHRAL_OTG_FS 	:	SET_BIT(RCC_AHB2ENR ,7 ) ;break;
		case PERIPHRAL_TIMER_2	: 	SET_BIT(RCC_APB1ENR ,0 ) ;break;
		case PERIPHRAL_TIMER_3	: 	SET_BIT(RCC_APB1ENR ,1 ) ;break;
		case PERIPHRAL_TIMER_4	: 	SET_BIT(RCC_APB1ENR ,2 ) ;break;
		case PERIPHRAL_TIMER_5	: 	SET_BIT(RCC_APB1ENR ,3 ) ;break;
		case PERIPHRAL_WWDG   	: 	SET_BIT(RCC_APB1ENR ,11 );break;
		case PERIPHRAL_SPI_2  	: 	SET_BIT(RCC_APB1ENR ,14 );break;
		case PERIPHRAL_SPI_3  	: 	SET_BIT(RCC_APB1ENR ,15 );break;
		case PERIPHRAL_USART_2	: 	SET_BIT(RCC_APB1ENR ,17 );break;
		case PERIPHRAL_I2C_1  	:	SET_BIT(RCC_APB1ENR ,21 );break;
		case PERIPHRAL_I2C_2  	: 	SET_BIT(RCC_APB1ENR ,22 );break;
		case PERIPHRAL_I2C_3  	: 	SET_BIT(RCC_APB1ENR ,23 );break;
		case PERIPHRAL_PWR_INTFC: 	SET_BIT(RCC_APB1ENR ,28 );break;
		case PERIPHRAL_TIMER_1  : 	SET_BIT(RCC_APB2ENR ,0 ) ;break;
		case PERIPHRAL_USART_1  :	SET_BIT(RCC_APB2ENR ,4 ) ;break;
		case PERIPHRAL_USART_6  :	SET_BIT(RCC_APB2ENR ,5 ) ;break;
		case PERIPHRAL_ADC_1    : 	SET_BIT(RCC_APB2ENR ,8 ) ;break;
		case PERIPHRAL_SDIO     : 	SET_BIT(RCC_APB2ENR ,11 );break;
		case PERIPHRAL_SPI_1    :	SET_BIT(RCC_APB2ENR ,12 );break;
		case PERIPHRAL_SPI_4    :	SET_BIT(RCC_APB2ENR ,13 );break;
		case PERIPHRAL_SYSCFG   :	SET_BIT(RCC_APB2ENR ,14 );break;
		case PERIPHRAL_TIMER_9  : 	SET_BIT(RCC_APB2ENR ,16 );break;
		case PERIPHRAL_TIMER_10 :	SET_BIT(RCC_APB2ENR ,17 );break;
		case PERIPHRAL_TIMER_11 :	SET_BIT(RCC_APB2ENR ,18 );break;
		default: //DET_reportError(RCC /*Module ID*/, 0 /*ERROR ID*/, 2 /*FUNCTION ID*/);
			break;
		

		

	}
	
}


void RCC_voidDisablePeripheralClock(PERIPHRAL PeriphralId){
	switch(PeriphralId){
		case PERIPHRAL_GPIO_A 	:	CLR_BIT(RCC_AHB1ENR , 0) ;break;
		case PERIPHRAL_GPIO_B 	:	CLR_BIT(RCC_AHB1ENR , 1) ;break;
		case PERIPHRAL_GPIO_C 	:	CLR_BIT(RCC_AHB1ENR , 2) ;break;
		case PERIPHRAL_GPIO_D 	:	CLR_BIT(RCC_AHB1ENR , 3) ;break;
		case PERIPHRAL_GPIO_E 	:	CLR_BIT(RCC_AHB1ENR , 4) ;break;
		case PERIPHRAL_GPIO_H 	:	CLR_BIT(RCC_AHB1ENR , 7) ;break;
		case PERIPHRAL_CRC 	  	:	CLR_BIT(RCC_AHB1ENR , 12);break;
		case PERIPHRAL_DMA_1  	:	CLR_BIT(RCC_AHB1ENR ,21 );break;
		case PERIPHRAL__DMA_2 	:	CLR_BIT(RCC_AHB1ENR ,22 );break;
		case PERIPHRAL_OTG_FS 	:	CLR_BIT(RCC_AHB2ENR ,7 ) ;break;
		case PERIPHRAL_TIMER_2	: 	CLR_BIT(RCC_APB1ENR ,0 ) ;break;
		case PERIPHRAL_TIMER_3	: 	CLR_BIT(RCC_APB1ENR ,1 ) ;break;
		case PERIPHRAL_TIMER_4	: 	CLR_BIT(RCC_APB1ENR ,2 ) ;break;
		case PERIPHRAL_TIMER_5	: 	CLR_BIT(RCC_APB1ENR ,3 ) ;break;
		case PERIPHRAL_WWDG   	: 	CLR_BIT(RCC_APB1ENR ,11 );break;
		case PERIPHRAL_SPI_2  	: 	CLR_BIT(RCC_APB1ENR ,14 );break;
		case PERIPHRAL_SPI_3  	: 	CLR_BIT(RCC_APB1ENR ,15 );break;
		case PERIPHRAL_USART_2	: 	CLR_BIT(RCC_APB1ENR ,17 );break;
		case PERIPHRAL_I2C_1  	:	CLR_BIT(RCC_APB1ENR ,21 );break;
		case PERIPHRAL_I2C_2  	: 	CLR_BIT(RCC_APB1ENR ,22 );break;
		case PERIPHRAL_I2C_3  	: 	CLR_BIT(RCC_APB1ENR ,23 );break;
		case PERIPHRAL_PWR_INTFC: 	CLR_BIT(RCC_APB1ENR ,28 );break;
		case PERIPHRAL_TIMER_1  : 	CLR_BIT(RCC_APB2ENR ,0 ) ;break;
		case PERIPHRAL_USART_1  :	CLR_BIT(RCC_APB2ENR ,4 ) ;break;
		case PERIPHRAL_USART_6  :	CLR_BIT(RCC_APB2ENR ,5 ) ;break;
		case PERIPHRAL_ADC_1    : 	CLR_BIT(RCC_APB2ENR ,8 ) ;break;
		case PERIPHRAL_SDIO     : 	CLR_BIT(RCC_APB2ENR ,11 );break;
		case PERIPHRAL_SPI_1    :	CLR_BIT(RCC_APB2ENR ,12 );break;
		case PERIPHRAL_SPI_4    :	CLR_BIT(RCC_APB2ENR ,13 );break;
		case PERIPHRAL_SYSCFG   :	CLR_BIT(RCC_APB2ENR ,14 );break;
		case PERIPHRAL_TIMER_9  : 	CLR_BIT(RCC_APB2ENR ,16 );break;
		case PERIPHRAL_TIMER_10 :	CLR_BIT(RCC_APB2ENR ,17 );break;
		case PERIPHRAL_TIMER_11 :	CLR_BIT(RCC_APB2ENR ,18 );break;
		default: //DET_reportError(RCC /*Module ID*/, 0 /*ERROR ID*/, 2 /*FUNCTION ID*/);
			break;

	}
	
}
