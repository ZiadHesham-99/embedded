/*
 * main.c
 *
 *  Created on: Aug 13, 2022
 *      Author: ziad
 */
#include"STD_TYPPES.h"
#include"SYSTICK_interface.h"
#include"GPIO_interface.h"
#include"RCC_interface.h"
u8 segment[10]={0b00111111 ,0b00000110, 0b01011011 ,0b01001111 ,0b01100110 ,0b01101101 , 0b01111101,0b00000111 ,0b01111111 ,  0b01101111};
void test_func(void);
int main (void){
RCC_voidInit();
SYSTICK_voidInitialize();
RCC_voidEnablePeripheralClock(PERIPHRAL_GPIO_A);
RCC_voidEnablePeripheralClock(PERIPHRAL_GPIO_B);
GPIO_setPinMode();
GPIO_voidSetPortValue(PORT_NAME_A , segment[0]);

while(1){
	if( GPIO_voidGetPinValue(PORT_NAME_B , PIN_NUM_0) ){
		SYSTICK_voidAsychronousDelay(100,test_func);

	}

}
return 0 ;
}
void test_func(void){
	for(int i=0 ;i<10;i++){
				GPIO_voidSetPortValue(PORT_NAME_A , segment[i]);
	}
}



