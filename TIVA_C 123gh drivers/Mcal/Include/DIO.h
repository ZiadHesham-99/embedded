/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DIO_FULL_HIGH_PORT 	(u8) 255

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	DIO_ChannelType_Pin_0 = 0 ,
	DIO_ChannelType_Pin_1 = 1 ,
	DIO_ChannelType_Pin_2 = 2 ,
	DIO_ChannelType_Pin_3 = 3 ,
	DIO_ChannelType_Pin_4 = 4 ,
	DIO_ChannelType_Pin_5 = 5 ,
	DIO_ChannelType_Pin_6 = 6 ,
	DIO_ChannelType_Pin_7 = 7 
}DIO_ChannelType;

typedef enum
{
	DIO_PortType_Port_A = 0 ,
	DIO_PortType_Port_B = 1 ,
	DIO_PortType_Port_C = 2 ,
	DIO_PortType_Port_D = 3 ,
	DIO_PortType_Port_E = 4 ,
	DIO_PortType_Port_F = 5 
}DIO_PortType;
typedef enum
{
	DIO_LevelType_LOW =0 , 
	DIO_LevelType_HIGH = 1 
	
}DIO_LevelType;

typedef enum
{
	DIO_Direction_INPUT =0 , 
	DIO_Direction_OUTPUT = 1
}DIO_Channel_direction ;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
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
void DIO_setChannelDirection(DIO_PortType port ,DIO_ChannelType channel , DIO_Channel_direction direction);
void DIO_WriteChannel(DIO_PortType port ,DIO_ChannelType channel , DIO_LevelType level);
DIO_LevelType DIO_ReadChannel(DIO_PortType port ,DIO_ChannelType channel  );
u32 DIO_ReadPort(DIO_PortType port);
void DIO_WritePort(DIO_PortType port , u8 value);
void DIO_setPortDirection(DIO_PortType port , DIO_Channel_direction direction);
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/