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
#include "DIO.h"
#include "GPIO_Reg.h"
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

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void DIO_setChannelDirection(DIO_PortType port ,DIO_ChannelType channel , DIO_Channel_direction direction){
	switch(port){
		case DIO_PortType_Port_A:{
			RCGCGPIO_REG |= (1<<0);
			
			if(direction){
				GPIO_PORT_A_DIR |= (1<<channel);
			}
			else{
				GPIO_PORT_A_DIR &= ~(1<<channel);
			}
			GPIO_PORT_A_DEN |= (1<<channel);
			
			break;
		}
		case DIO_PortType_Port_B:{
			RCGCGPIO_REG |= (1<<1);
			
			if(direction){
				GPIO_PORT_B_DIR |= (1<<channel);
			}
			else{
				GPIO_PORT_B_DIR &= ~(1<<channel);
			}
			GPIO_PORT_B_DEN |= (1<<channel);
			break;
		}
		case DIO_PortType_Port_C:{
			RCGCGPIO_REG |= (1<<2);
			
			if(direction){
				GPIO_PORT_C_DIR |= (1<<channel);
			}
			else{
				GPIO_PORT_C_DIR &= ~(1<<channel);
			}
			GPIO_PORT_C_DEN |= (1<<channel);
			break ;
		}
		case DIO_PortType_Port_D:{
			RCGCGPIO_REG |= (1<<3);
			
			if(direction){
				GPIO_PORT_D_DIR |= (1<<channel);
			}
			else{
				GPIO_PORT_D_DIR &= ~(1<<channel);
			}
			GPIO_PORT_D_DEN |= (1<<channel);
			break;
		}
		case DIO_PortType_Port_E:{
			RCGCGPIO_REG |= (1<<4);
			if(direction){
				GPIO_PORT_E_DIR |= (1<<channel);
			}
			else{
				GPIO_PORT_E_DIR &= ~(1<<channel);
			}
			GPIO_PORT_E_DEN |= (1<<channel);
			break;
		}
		case DIO_PortType_Port_F:{
			RCGCGPIO_REG |= (1<<5);
			if(direction){
				GPIO_PORT_F_DIR |= (1<<channel);
			}
			else{
				GPIO_PORT_F_DIR &= ~(1<<channel);
			}
			GPIO_PORT_F_DEN |= (1<<channel);
			break;
		}

	}
}

void DIO_WriteChannel(DIO_PortType port ,DIO_ChannelType channel , DIO_LevelType level){
	switch(port){
		case DIO_PortType_Port_A:{
		switch(channel){
			case DIO_ChannelType_Pin_0: if(level){GPIO_PORT_A_DATA->DATA[1] = 0xff;} 		else{GPIO_PORT_A_DATA->DATA[1] = 0 ;} break;
			case DIO_ChannelType_Pin_1: if(level){GPIO_PORT_A_DATA->DATA[2] = 0xff;} 		else{GPIO_PORT_A_DATA->DATA[2] = 0 ;} break;
			case DIO_ChannelType_Pin_2: if(level){GPIO_PORT_A_DATA->DATA[4]  = 0xff;} 	else{GPIO_PORT_A_DATA->DATA[4]  = 0 ;} break;
			case DIO_ChannelType_Pin_3: if(level){GPIO_PORT_A_DATA->DATA[8]  = 0xff;} 	else{GPIO_PORT_A_DATA->DATA[8]  = 0 ;} break;
			case DIO_ChannelType_Pin_4: if(level){GPIO_PORT_A_DATA->DATA[16] = 0xff;} 	else{GPIO_PORT_A_DATA->DATA[16] = 0 ;} break;
			case DIO_ChannelType_Pin_5: if(level){GPIO_PORT_A_DATA->DATA[32] = 0xff;}		else{GPIO_PORT_A_DATA->DATA[32] = 0 ;} break;
			case DIO_ChannelType_Pin_6: if(level){GPIO_PORT_A_DATA->DATA[64] = 0xff;}		else{GPIO_PORT_A_DATA->DATA[64] = 0 ;} break;
			case DIO_ChannelType_Pin_7: if(level){GPIO_PORT_A_DATA->DATA[128] = 0xff;}	else{GPIO_PORT_A_DATA->DATA[128] = 0 ;} break;

		}
			
			break;
		}
		case DIO_PortType_Port_B:{
		switch(channel){
			case DIO_ChannelType_Pin_0: if(level){GPIO_PORT_B_DATA->DATA[1] = 0xff;} 		else{GPIO_PORT_B_DATA->DATA[1] = 0 ;} break;
			case DIO_ChannelType_Pin_1: if(level){GPIO_PORT_B_DATA->DATA[2] = 0xff;} 		else{GPIO_PORT_B_DATA->DATA[2] = 0 ;} break;
			case DIO_ChannelType_Pin_2: if(level){GPIO_PORT_B_DATA->DATA[4]  = 0xff;} 	else{GPIO_PORT_B_DATA->DATA[4]  = 0 ;} break;
			case DIO_ChannelType_Pin_3: if(level){GPIO_PORT_B_DATA->DATA[8]  = 0xff;} 	else{GPIO_PORT_B_DATA->DATA[8]  = 0 ;} break;
			case DIO_ChannelType_Pin_4: if(level){GPIO_PORT_B_DATA->DATA[16] = 0xff;} 	else{GPIO_PORT_B_DATA->DATA[16] = 0 ;} break;
			case DIO_ChannelType_Pin_5: if(level){GPIO_PORT_B_DATA->DATA[32] = 0xff;}		else{GPIO_PORT_B_DATA->DATA[32] = 0 ;} break;
			case DIO_ChannelType_Pin_6: if(level){GPIO_PORT_B_DATA->DATA[64] = 0xff;}		else{GPIO_PORT_B_DATA->DATA[64] = 0 ;} break;
			case DIO_ChannelType_Pin_7: if(level){GPIO_PORT_B_DATA->DATA[128] = 0xff;}	else{GPIO_PORT_B_DATA->DATA[128] = 0 ;} break;

		}
			
			break;
		}case DIO_PortType_Port_C:{
		switch(channel){
			case DIO_ChannelType_Pin_0: if(level){GPIO_PORT_C_DATA->DATA[1]   = 0xFF;} 		else{GPIO_PORT_C_DATA->DATA[1] = 0 ;} break;
			case DIO_ChannelType_Pin_1: if(level){GPIO_PORT_C_DATA->DATA[2]   = 0xFF;} 		else{GPIO_PORT_C_DATA->DATA[2] = 0 ;} break;
			case DIO_ChannelType_Pin_2: if(level){GPIO_PORT_C_DATA->DATA[4]   = 0xFFFF;} 	else{GPIO_PORT_C_DATA->DATA[4]  = 0 ;} break;
			case DIO_ChannelType_Pin_3: if(level){GPIO_PORT_C_DATA->DATA[8]   = 0xFFFF;} 	else{GPIO_PORT_C_DATA->DATA[8]  = 0 ;} break;
			case DIO_ChannelType_Pin_4: if(level){GPIO_PORT_C_DATA->DATA[16]  = 0xFFFF;} 	else{GPIO_PORT_C_DATA->DATA[16] = 0 ;} break;
			case DIO_ChannelType_Pin_5: if(level){GPIO_PORT_C_DATA->DATA[32]  = 0xFFFF;}		else{GPIO_PORT_C_DATA->DATA[32] = 0 ;} break;
			case DIO_ChannelType_Pin_6: if(level){GPIO_PORT_C_DATA->DATA[64]  = 0xFFFF;}		else{GPIO_PORT_C_DATA->DATA[64] = 0 ;} break;
			case DIO_ChannelType_Pin_7: if(level){GPIO_PORT_C_DATA->DATA[128] = 0xFFFF;}	else{GPIO_PORT_C_DATA->DATA[128] = 0 ;} break;

		}
			
			break;
		}case DIO_PortType_Port_D:{
		switch(channel){
			case DIO_ChannelType_Pin_0: if(level){GPIO_PORT_D_DATA->DATA[1] = 0xff;} 		else{GPIO_PORT_D_DATA->DATA[1] = 0 ;} break;
			case DIO_ChannelType_Pin_1: if(level){GPIO_PORT_D_DATA->DATA[2] = 0xff;} 		else{GPIO_PORT_D_DATA->DATA[2] = 0 ;} break;
			case DIO_ChannelType_Pin_2: if(level){GPIO_PORT_D_DATA->DATA[255] |= (1<<2) ;} 	else{GPIO_PORT_D_DATA->DATA[4]  = 0 ;} break;
			case DIO_ChannelType_Pin_3: if(level){GPIO_PORT_D_DATA->DATA[8]  = 0xff;} 	else{GPIO_PORT_D_DATA->DATA[8]  = 0 ;} break;
			case DIO_ChannelType_Pin_4: if(level){GPIO_PORT_D_DATA->DATA[16] = 0xff;} 	else{GPIO_PORT_D_DATA->DATA[16] = 0 ;} break;
			case DIO_ChannelType_Pin_5: if(level){GPIO_PORT_D_DATA->DATA[32] = 0xff;}		else{GPIO_PORT_D_DATA->DATA[32] = 0 ;} break;
			case DIO_ChannelType_Pin_6: if(level){GPIO_PORT_D_DATA->DATA[64] = 0xff;}		else{GPIO_PORT_D_DATA->DATA[64] = 0 ;} break;
			case DIO_ChannelType_Pin_7: if(level){GPIO_PORT_D_DATA->DATA[128] = 0xff;}	else{GPIO_PORT_D_DATA->DATA[128] = 0 ;} break;

		}
			
			break;
		}case DIO_PortType_Port_E:{
		switch(channel){
			case DIO_ChannelType_Pin_0: if(level){GPIO_PORT_E_DATA->DATA[1] = 0xff;} 		else{GPIO_PORT_E_DATA->DATA[1] = 0 ;} break;
			case DIO_ChannelType_Pin_1: if(level){GPIO_PORT_E_DATA->DATA[2] = 0xff;} 		else{GPIO_PORT_E_DATA->DATA[2] = 0 ;} break;
			case DIO_ChannelType_Pin_2: if(level){GPIO_PORT_E_DATA->DATA[4]  = 0xff;} 	else{GPIO_PORT_E_DATA->DATA[4]  = 0 ;} break;
			case DIO_ChannelType_Pin_3: if(level){GPIO_PORT_E_DATA->DATA[8]  = 0xff;} 	else{GPIO_PORT_E_DATA->DATA[8]  = 0 ;} break;
			case DIO_ChannelType_Pin_4: if(level){GPIO_PORT_E_DATA->DATA[16] = 0xff;} 	else{GPIO_PORT_E_DATA->DATA[16] = 0 ;} break;
			case DIO_ChannelType_Pin_5: if(level){GPIO_PORT_E_DATA->DATA[32] = 0xff;}		else{GPIO_PORT_E_DATA->DATA[32] = 0 ;} break;
			case DIO_ChannelType_Pin_6: if(level){GPIO_PORT_E_DATA->DATA[64] = 0xff;}		else{GPIO_PORT_E_DATA->DATA[64] = 0 ;} break;
			case DIO_ChannelType_Pin_7: if(level){GPIO_PORT_E_DATA->DATA[128] = 0xff;}	else{GPIO_PORT_E_DATA->DATA[128] = 0 ;} break;

		}
			
			break;
		}case DIO_PortType_Port_F:{
		switch(channel){
			case DIO_ChannelType_Pin_0: if(level){GPIO_PORT_F_DATA->DATA[1] = 0xff;} 		else{GPIO_PORT_F_DATA->DATA[1] = 0 ;} break;
			case DIO_ChannelType_Pin_1: if(level){GPIO_PORT_F_DATA->DATA[2] = 0xff;} 		else{GPIO_PORT_F_DATA->DATA[2] = 0 ;} break;
			case DIO_ChannelType_Pin_2: if(level){GPIO_PORT_F_DATA->DATA[4] = 0xff;} 		else{GPIO_PORT_F_DATA->DATA[4]  = 0 ;} break;
			case DIO_ChannelType_Pin_3: if(level){GPIO_PORT_F_DATA->DATA[8] = 0xff;} 		else{GPIO_PORT_F_DATA->DATA[8]  = 0 ;} break;
			case DIO_ChannelType_Pin_4: if(level){GPIO_PORT_F_DATA->DATA[16] = 0xff;} 	else{GPIO_PORT_F_DATA->DATA[16] = 0 ;} break;
			case DIO_ChannelType_Pin_5: if(level){GPIO_PORT_F_DATA->DATA[32] = 0xff;}		else{GPIO_PORT_F_DATA->DATA[32] = 0 ;} break;
			case DIO_ChannelType_Pin_6: if(level){GPIO_PORT_F_DATA->DATA[64] = 0xff;}		else{GPIO_PORT_F_DATA->DATA[64] = 0 ;} break;
			case DIO_ChannelType_Pin_7: if(level){GPIO_PORT_F_DATA->DATA[128] = 0xff;}	else{GPIO_PORT_F_DATA->DATA[128] = 0 ;} break;

		}
			
			break;
		}


	}
	

}



DIO_LevelType DIO_ReadChannel(DIO_PortType port ,DIO_ChannelType channel  ){
		switch(port){
		case DIO_PortType_Port_A:{
		if( (GPIO_PORT_A_DATA->DATA[255])&(1<<channel) ){
			return DIO_LevelType_HIGH;
			}
		else{
			return DIO_LevelType_LOW ;
			}
			break;
		}
		case DIO_PortType_Port_B:{
		if( (GPIO_PORT_B_DATA->DATA[255])&(1<<channel) ){
			return DIO_LevelType_HIGH;
			}
		else{
			return DIO_LevelType_LOW ;
			}
			break;
		}
		case DIO_PortType_Port_C:{
		if( (GPIO_PORT_C_DATA->DATA[255])&(1<<channel) ){
			return DIO_LevelType_HIGH;
			}
		else{
			return DIO_LevelType_LOW ;
			}
			break;
		}
		case DIO_PortType_Port_D:{
		if( (GPIO_PORT_D_DATA->DATA[255])&(1<<channel) ){
			return DIO_LevelType_HIGH;
			}
		else{
			return DIO_LevelType_LOW ;
			}
			break;
		}
		case DIO_PortType_Port_E:{
		if( (GPIO_PORT_E_DATA->DATA[255])&(1<<channel) ){
			return DIO_LevelType_HIGH;
			}
		else{
			return DIO_LevelType_LOW ;
			}
			break;
		}
		case DIO_PortType_Port_F:{
		if( (GPIO_PORT_F_DATA->DATA[255])&(1<<channel) ){
			return DIO_LevelType_HIGH;
			}
		else{
			return DIO_LevelType_LOW ;
			}
			break;
		}
			
			
		}
		
}


u32 DIO_ReadPort(DIO_PortType port){
	u32 CopyLocalPortVal;
	switch(port){
		case DIO_PortType_Port_A: CopyLocalPortVal = GPIO_PORT_A_DATA->DATA[255];break;
		case DIO_PortType_Port_B: CopyLocalPortVal = GPIO_PORT_B_DATA->DATA[255];break;
		case DIO_PortType_Port_C: CopyLocalPortVal = GPIO_PORT_C_DATA->DATA[255];break;
		case DIO_PortType_Port_D: CopyLocalPortVal = GPIO_PORT_D_DATA->DATA[255];break;
		case DIO_PortType_Port_E: CopyLocalPortVal = GPIO_PORT_E_DATA->DATA[255];break;
		case DIO_PortType_Port_F: CopyLocalPortVal = GPIO_PORT_F_DATA->DATA[255];break;
	}
	return CopyLocalPortVal;
}
void DIO_WritePort(DIO_PortType port , u8 value){
	switch(port){
		case DIO_PortType_Port_A: GPIO_PORT_A_DATA->DATA[255] = value ; break ;
		case DIO_PortType_Port_B: GPIO_PORT_B_DATA->DATA[255] = value ; break ;
		case DIO_PortType_Port_C: GPIO_PORT_C_DATA->DATA[255] = value ; break ;
		case DIO_PortType_Port_D: GPIO_PORT_D_DATA->DATA[255] = value ; break ;
		case DIO_PortType_Port_E: GPIO_PORT_E_DATA->DATA[255] = value ; break ;
		case DIO_PortType_Port_F: GPIO_PORT_F_DATA->DATA[255] = value ; break ;
	}
	
}

void DIO_setPortDirection(DIO_PortType port , DIO_Channel_direction direction ){
	switch(port){
		case DIO_PortType_Port_A:RCGCGPIO_REG |= (1<<0);if(direction){GPIO_PORT_A_DIR = 255;} else{GPIO_PORT_A_DIR = 0;} GPIO_PORT_A_DEN = 255;break;
		case DIO_PortType_Port_B:RCGCGPIO_REG |= (1<<1);if(direction){GPIO_PORT_B_DIR = 255;} else{GPIO_PORT_B_DIR = 0;} GPIO_PORT_B_DEN = 255;break;
		case DIO_PortType_Port_C:RCGCGPIO_REG |= (1<<2);if(direction){GPIO_PORT_C_DIR = 255;} else{GPIO_PORT_C_DIR = 0;} GPIO_PORT_C_DEN = 255;break;
		case DIO_PortType_Port_D:RCGCGPIO_REG |= (1<<3);if(direction){GPIO_PORT_D_DIR = 255;} else{GPIO_PORT_D_DIR = 0;} GPIO_PORT_D_DEN = 255;break;
		case DIO_PortType_Port_E:RCGCGPIO_REG |= (1<<4);if(direction){GPIO_PORT_E_DIR = 255;} else{GPIO_PORT_E_DIR = 0;} GPIO_PORT_E_DEN = 255;break;
		case DIO_PortType_Port_F:RCGCGPIO_REG |= (1<<5);if(direction){GPIO_PORT_F_DIR = 255;} else{GPIO_PORT_F_DIR = 0;} GPIO_PORT_F_DEN = 255;break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/