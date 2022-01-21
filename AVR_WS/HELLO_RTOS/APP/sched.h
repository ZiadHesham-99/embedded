/*
 * sched.h
 *
 *  Created on: Dec 17, 2021
 *      Author: ziad
 */

#ifndef APP_SCHED_H_
#define APP_SCHED_H_
typedef struct {
	u16 Periodecity;
	u16 First_delay;
	(void) (*task_ptr)(void);

}Task;

#define TASK_MAX_NO 3
#endif /* APP_SCHED_H_ */
