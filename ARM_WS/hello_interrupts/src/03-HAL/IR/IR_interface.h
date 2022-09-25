/*
 * IR_interface.h
 *
 *  Created on: Sep 12, 2022
 *      Author: ziad
 */

#ifndef _HAL_IR_IR_INTERFACE_H_
#define _HAL_IR_IR_INTERFACE_H_

void IR_setCBFunc( void(*ptr)(void) );
void IR_getFrame(void);
void IR_saveData (void );
u8 IR_getData(void);

#endif /* 03_HAL_IR_IR_INTERFACE_H_ */
