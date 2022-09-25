/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

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
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
u8 GetPriorityAndGroupConfig(u8  local_u8Group  ,u8  local_u8SubGroup ){
		u8 localconfigReturnValue = 0 ;
		#if  GROUP_SUB_PRIORITY  == GROUP_16_SUB_0
		localconfigReturnValue = local_u8Group ;
		#elif GROUP_SUB_PRIORITY == GROUP_8_SUB_2
		localconfigReturnValue = ((local_u8Group<<1) | (local_u8SubGroup<<0) );
		#elif GROUP_SUB_PRIORITY == GROUP_4_SUB_4
		localconfigReturnValue = ((local_u8Group<<2) | (local_u8SubGroup<<0) );
		#elif GROUP_SUB_PRIORITY == GROUP_2_SUB_8
		localconfigReturnValue = ((local_u8Group<<3) | (local_u8SubGroup<<0) );
		#else GROUP_SUB_PRIORITY == GROUP_0_SUB_16
		localconfigReturnValue =  local_u8SubGroup ;
		#endif
		return (localconfigReturnValue<<4);
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void NVIC_voidGroupSubPriority (void)
{
	SCB_AIRCR->B.PRIGROUP = GROUP_8_SUB_2;
}


void NVIC_voidInterruptEnable(u8 local_uint8Position)
{

   NVIC -> ISER[local_uint8Position / 32] = (1 << (local_uint8Position % 32));
}

void NVIC_voidInterruptDisable(u8 local_uint8Position)
{

   NVIC -> ICER[local_uint8Position / 32] = (1 << (local_uint8Position % 32));
}

void NVIC_voidSetPendingFlag(u8 local_uint8Position)
{

   NVIC -> ISPR[local_uint8Position / 32] =  (1 << (local_uint8Position % 32));
}

void NVIC_voidClearPendingFlag(u8 local_uint8Position)
{

   NVIC -> ICPR[local_uint8Position / 32] = (1 << (local_uint8Position % 32));
}
u8 NVIC_uint8GetActiveFlag(u8 local_uint8Position)
{
	u8 local_unit8ActiveFlag = GET_BIT(NVIC -> IABR[local_uint8Position / 32],local_uint8Position % 32);
	return local_unit8ActiveFlag;
}

void NVIC_voidSoftwarePriority (u8 local_uint8Position, u8  local_u8Group  ,u8  local_u8SubGroup )
{
	NVIC -> IPR[local_uint8Position] = GetPriorityAndGroupConfig(local_u8Group ,local_u8SubGroup);
}

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

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
