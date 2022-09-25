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
#include "Systick_Reg.h"
#include "Systick.h"
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

/*set the clk source in 16 MHZ*/
void Systick_setRawClkSrc(void){
	/*set system clk from internal prescion oscillator*/
	RCC_REG->B.OSCSRC =1 ;
	/*set bypass to pass the frequancy without PLL*/
	RCC_REG->B.BYPASS = 1 ;
	/*powe down PLL to save power*/
	RCC_REG->B.PWRDN = 1 ;
	RCC_REG->B.SYSDIV = 0;
}


void Systick_SetInternalOSC(SYS_DIV Freq ){
	/*set system clk from internal prescion oscillator */
	RCC_REG->B.OSCSRC =1 ;
	/*clear bypass to pass the frequancy with PLL*/
	RCC_REG->B.BYPASS = 0 ;
	/*wait till PLL is locked and ready */
	//while(! PLLSTAT_REG);
	/*enable SYSDIV*/
	RCC_REG ->B.USESYSDIV = 1;
	/*set wanted frequancy by handling system divider*/
	switch(Freq){
		case SYS_DIV_BY_3_EQUL_66_67_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_3_EQUL_66_67_MHZ 	; break;
		case SYS_DIV_BY_4_EQUL_50_MHZ : RCC_REG->B.SYSDIV = SYS_DIV_BY_4_EQUL_50_MHZ        	; break;
		case SYS_DIV_BY_5_EQUL_40_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_5_EQUL_40_MHZ       	; break;
		case SYS_DIV_BY_6_EQUL_33_33_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_6_EQUL_33_33_MHZ 	; break;
		case SYS_DIV_BY_7_EQUL_28_57_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_7_EQUL_28_57_MHZ 	; break;
		case SYS_DIV_BY_8_EQUL_25_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_8_EQUL_25_MHZ       	; break;
		case SYS_DIV_BY_9_EQUL_22_22_MHZ : RCC_REG->B.SYSDIV =   SYS_DIV_BY_9_EQUL_22_22_MHZ  ; break;
		case SYS_DIV_BY_10_EQUL_20_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_10_EQUL_20_MHZ       ; break;
		case SYS_DIV_BY_11_EQUL_18_18_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_11_EQUL_18_18_MHZ ; break;
		case SYS_DIV_BY_12_EQUL_16_67_MHZ : RCC_REG->B.SYSDIV = SYS_DIV_BY_12_EQUL_16_67_MHZ  ; break;
		case SYS_DIV_BY_13_EQUL_15_38_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_13_EQUL_15_38_MHZ ; break;
		case SYS_DIV_BY_14_EQUL_14_29_MHZ : RCC_REG->B.SYSDIV = SYS_DIV_BY_14_EQUL_14_29_MHZ  ; break;
		case SYS_DIV_BY_15_EQUL_13_33_MHZ : RCC_REG->B.SYSDIV =  SYS_DIV_BY_15_EQUL_13_33_MHZ ; break;
		default: RCC_REG->B.SYSDIV = SYS_DIV_BY_16_EQUL_12_5_MHZ														; break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/