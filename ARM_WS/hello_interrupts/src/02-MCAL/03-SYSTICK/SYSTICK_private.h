/*
 * SYSTICK_private.h
 *
 *  Created on: Aug 16, 2022
 *      Author: ziad
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_



typedef struct
{
	union{
		 u32 R;
		struct
		{
			u32 Enable:1;
			u32 TickInt:1;
			u32 ClockSrc:1;
			u32 reserved_0:13;
			u32 CountFlag:1;
			u32 reserved_1:15;
		}B;
	}CTRL;

		union{
		u32 R;
		struct
		{
			u32 RELOAD:24;
			u32 reserved_0:8;
		}B;
	}LOAD;

		union{
		u32 R;
		struct
		{
			u32 CURRENT:24;
			u32 reserved_0:8;
		}B;
	}VALUE;
}SYSTICK_type;

//SYSTICK_type *Register;
#define SYSTICK  ((volatile SYSTICK_type*)0xE000E010)


#endif /* SYSTICK_PRIVATE_H_ */
