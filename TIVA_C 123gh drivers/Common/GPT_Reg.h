/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Reg.h
 *       Module:  Reg.h
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef GPT_REG_H
#define GPT_REG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/*#define GPIO_DIR                                     *((volatile uint32*)(0x40006000+0x400))*/
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCGCTIMER_REG																										*((volatile u32*)(0x400FE000+0x604))
#define RCGCWTIMER_REG																									*((volatile u32*)(0x400FE000+0x65C))

/*Timer0 16 bit */

#define CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS															0x40030000
#define TIMER0_16BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+0x00C))
#define TIMER0_16BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+0x000))
#define TIMER0_16BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+0x004))
#define TIMER0_16BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+0x028))
#define TIMER0_16BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+ 0x01C))
#define TIMER0_16BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+ 0x018))
#define TIMER0_16BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+ 0x038))
#define TIMER0_16BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+ 0x048))
#define TIMER0_16BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_16BIT_BASE_ADDRESS+ 0x024))

/*Timer1 16 bit */

#define CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS															0x40031000
#define TIMER1_16BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+0x00C))
#define TIMER1_16BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+0x000))
#define TIMER1_16BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+0x004))
#define TIMER1_16BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+0x028))
#define TIMER1_16BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+ 0x01C))
#define TIMER1_16BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+ 0x018))
#define TIMER1_16BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+ 0x038))
#define TIMER1_16BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+ 0x048))
#define TIMER1_16BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_16BIT_BASE_ADDRESS+ 0x024))


	
/*Timer0 16 bit */

#define CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS															0x40032000
#define TIMER2_16BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+0x00C))
#define TIMER2_16BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+0x000))
#define TIMER2_16BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+0x004))
#define TIMER2_16BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+0x028))
#define TIMER2_16BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+ 0x01C))
#define TIMER2_16BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+ 0x018))
#define TIMER2_16BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+ 0x038))
#define TIMER2_16BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+ 0x048))
#define TIMER2_16BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_16BIT_BASE_ADDRESS+ 0x024))


	
/*Timer0 16 bit */

#define CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS															0x40033000
#define TIMER3_16BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+0x00C))
#define TIMER3_16BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+0x000))
#define TIMER3_16BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+0x004))
#define TIMER3_16BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+0x028))
#define TIMER3_16BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+ 0x01C))
#define TIMER3_16BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+ 0x018))
#define TIMER3_16BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+ 0x038))
#define TIMER3_16BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+ 0x048))
#define TIMER3_16BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_16BIT_BASE_ADDRESS+ 0x024))

	
/*Timer0 16 bit */

#define CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS															0x40034000
#define TIMER4_16BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+0x00C))
#define TIMER4_16BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+0x000))
#define TIMER4_16BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+0x004))
#define TIMER4_16BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+0x028))
#define TIMER4_16BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+ 0x01C))
#define TIMER4_16BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+ 0x018))
#define TIMER4_16BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+ 0x038))
#define TIMER4_16BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+ 0x048))
#define TIMER4_16BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_16BIT_BASE_ADDRESS+ 0x024))

	
/*Timer0 16 bit */

#define CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS															0x40035000
#define TIMER5_16BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+0x00C))
#define TIMER5_16BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+0x000))
#define TIMER5_16BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+0x004))
#define TIMER5_16BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+0x028))
#define TIMER5_16BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+ 0x01C))
#define TIMER5_16BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+ 0x018))
#define TIMER5_16BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+ 0x038))
#define TIMER5_16BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+ 0x048))
#define TIMER5_16BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_16BIT_BASE_ADDRESS+ 0x024))

	
	

/*Timer0 32 bit */

#define CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS															0x40036000
#define TIMER0_32BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+0x00C))
#define TIMER0_32BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+0x000))
#define TIMER0_32BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+0x004))
#define TIMER0_32BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+0x028))
#define TIMER0_32BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+ 0x01C))
#define TIMER0_32BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+ 0x018))
#define TIMER0_32BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+ 0x038))
#define TIMER0_32BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+ 0x048))
#define TIMER0_32BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER0_32BIT_BASE_ADDRESS+ 0x024))


/*Timer0 32 bit */

#define CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS															0x40037000
#define TIMER1_32BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+0x00C))
#define TIMER1_32BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+0x000))
#define TIMER1_32BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+0x004))
#define TIMER1_32BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+0x028))
#define TIMER1_32BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+ 0x01C))
#define TIMER1_32BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+ 0x018))
#define TIMER1_32BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+ 0x038))
#define TIMER1_32BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER1_32BIT_BASE_ADDRESS+ 0x048))

	

/*Timer0 32 bit */

#define CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS															0x4004C000
#define TIMER2_32BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+0x00C))
#define TIMER2_32BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+0x000))
#define TIMER2_32BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+0x004))
#define TIMER2_32BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+0x028))
#define TIMER2_32BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+ 0x01C))
#define TIMER2_32BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+ 0x018))
#define TIMER2_32BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+ 0x038))
#define TIMER2_32BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+ 0x048))
#define TIMER2_32BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER2_32BIT_BASE_ADDRESS+ 0x024))
	
/*Timer0 32 bit */

#define CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS															0x4004D000
#define TIMER3_32BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+0x00C))
#define TIMER3_32BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+0x000))
#define TIMER3_32BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+0x004))
#define TIMER3_32BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+0x028))
#define TIMER3_32BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+ 0x01C))
#define TIMER3_32BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+ 0x018))
#define TIMER3_32BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+ 0x038))
#define TIMER3_32BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+ 0x048))
#define TIMER3_32BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER3_32BIT_BASE_ADDRESS+ 0x024))

	
/*Timer0 32 bit */

#define CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS															0x4004E000
#define TIMER4_32BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+0x00C))
#define TIMER4_32BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+0x000))
#define TIMER4_32BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+0x004))
#define TIMER4_32BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+0x028))
#define TIMER4_32BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+ 0x01C))
#define TIMER4_32BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+ 0x018))
#define TIMER4_32BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+ 0x038))
#define TIMER4_32BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+ 0x048))
#define TIMER4_32BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER4_32BIT_BASE_ADDRESS+ 0x024))

	
/*Timer0 32 bit */

#define CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS															0x4004F000
#define TIMER5_32BIT_GPTMCTL_REG																				*((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+0x00C))
#define TIMER5_32BIT_GPTMCFG_REG																				*((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+0x000))
#define TIMER5_32BIT_GPTMTAMR_REG																				*((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+0x004))
#define TIMER5_32BIT_GPTMTAILR_REG																			*((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+0x028))
#define TIMER5_32BIT_GPTMRIS_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+ 0x01C))
#define TIMER5_32BIT_GPTMIMR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+ 0x018))
#define TIMER5_32BIT_GPTMTAPR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+ 0x038))
#define TIMER5_32BIT_GPTMTAR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+ 0x048))
#define TIMER5_32BIT_GPTMICR_REG																			  *((volatile u32*)(CORTEX_M4_TIMER5_32BIT_BASE_ADDRESS+ 0x024))





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* REG_H */

/**********************************************************************************************************************
 *  END OF FILE: Reg.h
 *********************************************************************************************************************/