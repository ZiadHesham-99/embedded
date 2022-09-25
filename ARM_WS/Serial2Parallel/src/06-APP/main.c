/*
 * main.c
 *
 *  Created on: Aug 19, 2022
 *      Author: ziad
 */
#include"../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../01-LIB/03-ERROR_STATUS/ERROR_STATUS.h"

#include"../02-MCAL/01-RCC/RCC_interface.h"
#include"../02-MCAL/02-GPIO/GPIO_interface.h"

#include"../03-HAL/DotMatrix/DotMatrix.h"

u8 DATA[17][8] ={ { 0, 130, 128, 130, 162, 228, 8, 192}
, {0, 1, 64, 65, 81, 114, 4, 96}
,{0, 0, 16, 16, 84, 93, 192, 24}
,{0, 0, 8, 8, 42, 46, 96, 12}
,{0, 0, 4, 4, 21, 23, 48, 6}
,{0, 0, 2, 2, 10, 11, 24, 3}
,{0, 0, 1, 1, 5, 5, 12, 1}
,{0, 0, 0, 0, 2, 2, 6, 0}
,{0, 0, 0, 0, 1, 1, 3, 0}
,{0, 0, 0, 0, 0, 0, 1, 0}
,{0, 128, 0, 128, 128, 0, 0, 0}
,{0, 64, 0, 64, 64, 128, 0, 0}
,{0, 32, 0, 32, 32, 64, 128, 0}
,{0, 16, 0, 16, 16, 32, 64, 0}
,{0, 8, 0, 8, 8, 144, 160, 0}
,{4, 0, 4, 4, 72, 208, 0, 128}
,{2, 0, 130, 130, 164, 232, 0, 192}};
/*use DotMatrix_vidSTP_Display() when connecting serial to parllel chip and use DotMatrix_vidDisplay() when connecting the full port */
int main (void){
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(PERIPHRAL_GPIO_A);
	RCC_voidEnablePeripheralClock(PERIPHRAL_GPIO_B);
	SYSTICK_voidInitialize();
	GPIO_setPinMode();
	while(1){
		for(int i=0;i<17;i++){
			DotMatrix_vidSTP_Display(DATA[i]);
			SYSTICK_voidAsychronousDelay(1000000);
		}

	}


}





/*	while(1){
		for(int i=0;i<17;i++){
			DotMatrix_vidDisplay(DATA[i]);
			SYSTICK_voidAsychronousDelay(1000000);
		}

	}*/
