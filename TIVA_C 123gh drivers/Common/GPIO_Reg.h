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
typedef struct{
    u32 DATA[256];
}DATA_REG;

/*#define GPIO_DIR                                     *((volatile uint32*)(0x40006000+0x400))*/
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define RCGCGPIO_REG															*((volatile u32*)(0x400FE000+0x608))
/**/
/*
#define GPIODIR_REG_OFFSET													0x400
#define GPIODEN_REG_OFFSET													0x51C  
*/
/**/
#define GPIO_PORT_A_BASE													  ((volatile u32*)(0x40004000))
#define GPIO_PORT_A_DATA														((volatile DATA_REG*)0x40004000)
#define GPIO_PORT_A_DIR															*((volatile u32*)(0x40004000+0x400))
#define GPIO_PORT_A_DEN															*((volatile u32*)(0x40004000+0x51C))
/**/
#define GPIO_PORT_B_BASE														((volatile u32*)(0x40005000))
#define GPIO_PORT_B_DATA														((volatile DATA_REG*)0x40005000)
#define GPIO_PORT_B_DIR															*((volatile u32*)(0x40005000+0x400))
#define GPIO_PORT_B_DEN															*((volatile u32*)(0x40005000+0x51C))
/**/
#define GPIO_PORT_C_BASE														*((volatile u32*)(0x40006000))
#define GPIO_PORT_C_DATA														((volatile DATA_REG*)0x40006000)
#define GPIO_PORT_C_DIR															*((volatile u32*)(0x40006000+0x400))
#define GPIO_PORT_C_DEN															*((volatile u32*)(0x40006000+0x51C))
/**/
#define GPIO_PORT_D_BASE														((volatile u32*)(0x40007000))
#define GPIO_PORT_D_DATA														((volatile DATA_REG*)0x40007000)
#define GPIO_PORT_D_DIR															*((volatile u32*)(0x40007000+0x400))
#define GPIO_PORT_D_DEN															*((volatile u32*)(0x40007000+0x51C))
/**/
#define GPIO_PORT_E_BASE														((volatile u32*)(0x40024000))
#define GPIO_PORT_E_DATA														((volatile DATA_REG*)0x40024000)
#define GPIO_PORT_E_DIR															*((volatile u32*)(0x40024000+0x400))
#define GPIO_PORT_E_DEN															*((volatile u32*)(0x40024000+0x51C))
/**/
#define GPIO_PORT_F_BASE														((volatile u32*)(0x40025000))
#define GPIO_PORT_F_DATA														((volatile DATA_REG*)0x40025000)
#define GPIO_PORT_F_DIR															*((volatile u32*)(0x40025000+0x400))
#define GPIO_PORT_F_DEN															*((volatile u32*)(0x40025000+0x51C))




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* REG_H */

/**********************************************************************************************************************
 *  END OF FILE: Reg.h
 *********************************************************************************************************************/