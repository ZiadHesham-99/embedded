#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include"../../01-LIB/03-ERROR_STATUS/ERROR_STATUS.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

extern  pinInfo ARRAY_OF_PINS[NUMBER_OF_USED_PINS] ;

void GPIO_setPinMode(void){
	for(int i = 0 ; i<NUMBER_OF_USED_PINS ; i++){
		switch(ARRAY_OF_PINS[i].PORT){
			case PORT_NAME_A:{
				/*configure mode of the pin i/p o/p or AP*/
				GPIOA->MODER &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
				GPIOA->MODER |= (ARRAY_OF_PINS[i].MODE << (ARRAY_OF_PINS[i].PIN *2));
				if(ARRAY_OF_PINS[i].TYPE != NOT_USED){
					/*push_pull or open_drain*/
					GPIOA->OTYPER &= ~ ( 0b1 <<ARRAY_OF_PINS[i].PIN);
					GPIOA->OTYPER |= (ARRAY_OF_PINS[i].TYPE <<ARRAY_OF_PINS[i].PIN);
					/*configure speed if output*/
					GPIOA->OSPEEDR &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
					GPIOA->OSPEEDR |= (ARRAY_OF_PINS[i].SPEED<< (ARRAY_OF_PINS[i].PIN *2) );
				}
				/*pull_up and pull_down setting*/
				GPIOA->PUPDR &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
				GPIOA->PUPDR |= (ARRAY_OF_PINS[i].SETTING<< (ARRAY_OF_PINS[i].PIN *2) );
				break ;
			}
			case PORT_NAME_B:{
				/*configure mode of the pin i/p o/p or AP*/
				GPIOB->MODER &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
				GPIOB->MODER |= (ARRAY_OF_PINS[i].MODE << (ARRAY_OF_PINS[i].PIN *2));
				if(ARRAY_OF_PINS[i].TYPE != NOT_USED){
					/*push_pull or open_drain*/
					GPIOB->OTYPER &= ~ ( 0b1 <<ARRAY_OF_PINS[i].PIN);
					GPIOB->OTYPER |= (ARRAY_OF_PINS[i].TYPE <<ARRAY_OF_PINS[i].PIN);
					/*configure speed if output*/
					GPIOB->OSPEEDR &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
					GPIOB->OSPEEDR |= (ARRAY_OF_PINS[i].SPEED<< (ARRAY_OF_PINS[i].PIN *2) );
				}
				/*pull_up and pull_down setting*/
				GPIOB->PUPDR &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
				GPIOB->PUPDR |= (ARRAY_OF_PINS[i].SETTING<< (ARRAY_OF_PINS[i].PIN *2) );
				break ;

			}
			case PORT_NAME_C:{
				/*configure mode of the pin i/p o/p or AP*/
				GPIOC->MODER &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
				GPIOC->MODER |= (ARRAY_OF_PINS[i].MODE << (ARRAY_OF_PINS[i].PIN *2));
				if(ARRAY_OF_PINS[i].TYPE != NOT_USED){
					/*push_pull or open_drain*/
					GPIOC->OTYPER &= ~ ( 0b1 <<ARRAY_OF_PINS[i].PIN);
					GPIOC->OTYPER |= (ARRAY_OF_PINS[i].TYPE <<ARRAY_OF_PINS[i].PIN);
					/*configure speed if output*/
					GPIOC->OSPEEDR &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
					GPIOC->OSPEEDR |= (ARRAY_OF_PINS[i].SPEED<< (ARRAY_OF_PINS[i].PIN *2) );
				}
				/*pull_up and pull_down setting*/
				GPIOC->PUPDR &= ~ (0b11 << (ARRAY_OF_PINS[i].PIN *2) );
				GPIOC->PUPDR |= (ARRAY_OF_PINS[i].SETTING<< (ARRAY_OF_PINS[i].PIN *2) );
				break ;
			}
		}
	}
}


void GPIO_voidSetPinValue(PORT_NAME local_u8PortID, PIN_NUM local_u8PinID, LEVEL local_u8Value){
	 switch(local_u8PortID){
	        case PORT_NAME_A:
	            if(local_u8Value == LEVEL_LOW )        GPIOA->BSRR=(1<<(local_u8PinID+16));
	            else                     			   GPIOA->BSRR=(1<<local_u8PinID);
	            break;
	        case PORT_NAME_B:
	            if(local_u8Value == LEVEL_LOW )        GPIOB->BSRR=(1<<(local_u8PinID+16));
	            else                      			   GPIOB->BSRR=(1<<local_u8PinID);
	            break;
	        case PORT_NAME_C:
	            if(local_u8Value == LEVEL_LOW )        GPIOC->BSRR=(1<<(local_u8PinID+16));
	            else                        		   GPIOC->BSRR=(1<<local_u8PinID);
	            break;
	    }
}

LEVEL GPIO_voidGetPinValue(PORT_NAME local_u8PortID, PIN_NUM local_u8PinID){
	switch (local_u8PortID){
		case PORT_NAME_A : if(GET_BIT(GPIOA->IDR ,local_u8PinID )){return LEVEL_HIGH ;}	else{return LEVEL_LOW ;}
		case PORT_NAME_B : if(GET_BIT(GPIOB->IDR ,local_u8PinID )){return LEVEL_HIGH ;}	else{return LEVEL_LOW ;}
		case PORT_NAME_C : if(GET_BIT(GPIOC->IDR ,local_u8PinID )){return LEVEL_HIGH ;}	else{return LEVEL_LOW ;}
	}
}

void GPIO_voidSetPortValue(PORT_NAME local_u8PortID , u16  local_u16PortValue){
	switch (local_u8PortID){
	     case PORT_NAME_A :GPIOA->ODR = local_u16PortValue; break;
	     case PORT_NAME_B :GPIOB->ODR = local_u16PortValue; break;
         case PORT_NAME_C :GPIOC->ODR = local_u16PortValue; break;
	}

}
