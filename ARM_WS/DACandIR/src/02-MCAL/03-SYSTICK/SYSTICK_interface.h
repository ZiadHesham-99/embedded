/*
 * SYSTICK_interface.h
 *
 *  Created on: Aug 16, 2022
 *      Author: ziad
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#include"../../01-LIB/01-TYPES/STD_TYPPES.h"

#include"SYSTICK_private.h"
#include"SYSTICK_interface.h"
#include"SYSTICK_config.h"

void SYSTICK_voidInitialize(void); //AHB OR AHB/8
void SYSTICK_voidsychronousDelay(u32 local_u32Ticks);
void SYSTICK_voidAsychronousDelay(u32 local_u32Ticks, void (*ptr) (void));
void SYSTICK_voidStop(void);
void SYSTICK_voiduSecDelay(u32 usecs);

#endif /* SYSTICK_INTERFACE_H_ */
