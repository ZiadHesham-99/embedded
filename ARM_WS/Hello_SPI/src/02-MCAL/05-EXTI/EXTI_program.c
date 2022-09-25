/*
 * EXTI_program.c
 *
 *  Created on: Sep 5, 2022
 *      Author: ziad
 */

#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"

/* (<< ((EXTILine%4)*3) ) */

void EXTI_voidConfig (EXTIPort_t EXTIPort, EXTILine_t EXTILine , EXTI_TRIGGER_t EXTISenseMode) {


	/*set the specific channel to the needed port */
	u32 temp =0;
	temp = SYSCFG->EXTICR[EXTILine/4] ;
	temp &= ~(0b1111<< ((EXTILine%4)*4)  );
	temp |= ( EXTIPort << ((EXTILine%4)*4) );
	SYSCFG->EXTICR[EXTILine/4] = temp ;

	/*configuring sense control setting*/
	if(EXTISenseMode ==0 || EXTISenseMode==2 ){
		EXTI->RTSR = (1<< EXTILine);
	}
	if(EXTISenseMode ==1 || EXTISenseMode==2){
		EXTI->FTSR = (1<< EXTILine);
	}
	/*enable interrupts on the specific line */
		EXTI->IMR = (1<<EXTILine);
}

