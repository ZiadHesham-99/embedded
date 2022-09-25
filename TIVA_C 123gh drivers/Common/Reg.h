/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Reg.h
 *       Module:  Reg.h
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef REG_H
#define REG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    u32 VECACT   :8;
    u32          :3;
    u32 RETBASE  :1;
    u32 VECPEND  :8;
    u32          :2;
    u32 ISRPEND  :1;
    u32 ISRPRE   :1;
    u32          :1;
    u32 PENDSTCLR:1;
    u32 PENDSTSET:1;
    u32 UNPENDSV :1;
    u32 PENDSV   :1;
    u32          :2;
    u32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    u32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT_REG                                 *((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL_REG                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define EN0_REG_ADDR																	(volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)
/*
#define EN1_REG																		*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2_REG																		*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3_REG																		*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4_REG																		*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))
*/
#define DISO_REG_ADDR																	(volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0X180)
/*
#define DIS1_REG																	*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0X184))
#define DIS2_REG																	*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0X188))
#define DIS3_REG																	*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0X18C))
#define DIS4_REG																	*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0X190))
*/
#define SWTRIG_REG 																*((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0XF00))
#define PRI0_REG_ADDR																	(volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0X400)
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* REG_H */

/**********************************************************************************************************************
 *  END OF FILE: Reg.h
 *********************************************************************************************************************/