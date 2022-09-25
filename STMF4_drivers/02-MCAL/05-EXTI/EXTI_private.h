/*
 * EXTI_private.h
 *
 *  Created on: Sep 5, 2022
 *      Author: ziad
 */

#ifndef _MCAL_05_EXTI_EXTI_PRIVATE_H_
#define _MCAL_05_EXTI_EXTI_PRIVATE_H_

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;
#define EXTI ((volatile EXTI_t*)0x40013C00)

typedef struct
{
	u32 reserved[2];
	u32 EXTICR[4]  ;

}SYSCFG_t;

#define SYSCFG ((volatile SYSCFG_t*)0x40013800)



#endif /* 02_MCAL_05_EXTI_EXTI_PRIVATE_H_ */
