#ifndef _MCAL_06_TIMER_PRIVATE_H_
#define _MCAL_06_TIMER_PRIVATE_H_

#include "../../01-LIB/01-TYPES/STD_TYPPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"TIMER_interface.h"

typedef struct{
	union{
		u32 REG;
		struct {
			u32 CEN:1;//counter enable
			u32 UDIS:1;//update event enable/disable
			u32 URS:1; //update event request
			u32 OPM:1; //counter automatic recount enable /disable
			u32 DIR:1; // count direction upcounter /downcounter
			u32 CMS:2; //Center-aligned mode selection
			u32 ARPE:1;//: Auto-reload preload disable/enable
			u32 CKD:2; // Clock division
			u32 RESERVED_0:22;}BIT;
	}CR1;
	union
	{
		u32 REGISTER;
		struct
		{
			u32 CCPC:1;
			u32 RESERVED_0:1;
			u32 CCUS:1;
			u32 CCDS:1;
			u32 MMS:3;
			u32 TI1S:1;
			u32 OIS1:1;
			u32 OIS1N:1;
			u32 OIS2:1;
			u32 OIS2N:1;
			u32 OIS3:1;
			u32 OIS3N:1;
			u32 OIS4:1;
			u32 RESERVED_1:17;
		}BIT;
	}CR2;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 SMS:3;
			u32 RESERVED_0:1;
			u32 TS:3;
			u32 MSM:1;
			u32 ETF:4; //  External trigger filter
			u32 ETPS:2; // external trogger prescaler
			u32 ECE:1;// external clock disable /enable
			u32 ETP:1; // External trigger polarity
			u32 RESERVED_1:16;
		}BIT;
	}SMCR;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 UIE:1;
			u32 CC1IE:1;
			u32 CC2IE:1;
			u32 CC3IE:1;
			u32 CC4IE:1;
			u32 COMIE:1;
			u32 TIE:1;
			u32 BIE:1;
			u32 UDE:1;
			u32 CC1DE:1;
			u32 CC2DE:1;
			u32 CC3DE:1;
			u32 CC4DE:1;
			u32 COMDE:1;
			u32 TDE:1;
			u32 RESERVED_0:17;
		}BIT;
	}DIER;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 UIF:1;// update interrupt flag
			u32 CC1IF:1; // compare /capture flag ch1
			u32 CC2IF:1; // compare /capture flag ch2
			u32 CC3IF:1; // compare /capture flag ch3
			u32 CC4IF:1; // compare /capture flag ch4
			u32 RESERVED_0:1;
			u32 TIF:1;//trigger interrupt flag
			u32 RESERVED_1:2;
			u32 CC1OF:1;//Capture/Compare 1 overcapture flag
			u32 CC2OF:1; //Capture/Compare 2 overcapture flag
			u32 CC3OF:1; //Capture/Compare 3 overcapture flag
			u32 CC4OF:1; //Capture/Compare 4 overcapture flag
			u32 RESERVED_2:19;
		}BIT;
	}SR;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 UG:1; // Update generation
			u32 CC1G:1; //  Capture/compare 1 generation
			u32 CC2G:1; //  Capture/compare 2 generation
			u32 CC3G:1; //  Capture/compare 3 generation
			u32 CC4G:1; //  Capture/compare 4 generation
			u32 RESERVED_0:1;
			u32 TG:1;//Trigger generation
			u32 RESERVED_1:25;
		}BIT;
	}EGR;

	union
	{
		// output mode
		u32 REGISTER_OCM;
		struct
		{
			u32 CC1S:2;//direction of the channel (input/output)
			u32 OC1FE:1;//Output compare 1 fast enable
			u32 OC1PE:1;//Output compare 1 preload disable/enable
			u32 OC1M:3; //  Output compare 1 mode
			u32 OC1CE:1;//Output compare 1 clear enable
			u32 CC2S:2;
			u32 OC2FE:1;
			u32 OC2PE:1;
			u32 OC2M:3;
			u32 OC2CE:1;
			u32 RESERVED_0:16;
		}BIT_OCM;
		// input mode
		u32 REGISTER_ICM;
		struct
		{
			u32 CC1S:2;//Capture/Compare 1 selection
			u32 IC1PSC:2;//Input capture 1 prescaler
			u32 IC1F:4;//Input capture 1 filter
			u32 CC2S:2;
			u32 IC2PSC:2;
			u32 IC2F:4;
			u32 RESERVED_0:16;
		}BIT_ICM;
	}CCMR1;

	union
	{
		u32 REGISTER_OCM;
		struct
		{
			u32 CC3S:2;
			u32 OC3FE:1;
			u32 OC3PE:1;
			u32 OC3M:3;
			u32 OC3CE:1;
			u32 CC4S:2;
			u32 OC4FE:1;
			u32 OC4PE:1;
			u32 OC4M:3;
			u32 OC4CE:1;
			u32 RESERVED_0:16;
		}BIT_OCM;

		u32 REGISTER_ICM;
		struct
		{
			u32 CC3S:2;
			u32 IC3PSC:2;
			u32 IC3F:4;
			u32 CC4S:2;
			u32 IC4PSC:2;
			u32 IC4F:4;
			u32 RESERVED_0:16;
		}BIT_ICM;
	}CCMR2;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 CC1E:1;//enables capture mode in input //1: On - OC1 signal is output on the corresponding output pin
			u32 CC1P:1;//Capture/Compare 1 output Polarity
			u32 CC1NE:1;
			u32 CC1NP:1;//Capture/Compare 1 output Polarity
			u32 CC2E:1;
			u32 CC2P:1;
			u32 CC2NE:1;
			u32 CC2NP:1;
			u32 CC3E:1;
			u32 CC3P:1;
			u32 CC3NE:1;
			u32 CC3NP:1;
			u32 CC4E:1;
			u32 CC4P:1;
			u32 RESERVED_3:1;
			u32 CC4NP:1;
			u32 RESERVED_4:16;
		}BIT;
	}CCER;
	union
	{
		u32 REGISTER;
		struct
		{
			u32 CNT:16;// counter for 16 bit
			u32 CNT_TIM2_TIM5:16; // rest of 32 bit counter
		}BIT;
	}CNT;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 PSC:16;//prescaller value
			u32 RESERVED_0:16;
		}BIT;
	}PSC;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 ARR:16;// auto reload value for 16-bit
			u32 ARR_TIM2_TIM5:16;// rest of 32 bit auto reload value
		}BIT;
	}ARR;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 REP:8;
			u32 RESERVED_0:24;
		}BIT;
	}RCR;/*in timer 1 only */

	union
	{
		u32 REGISTER;
		struct
		{
			u32 CCR1:16;//capture / compare values
			u32 CCR1_TIM2_TIM5:16;
		}BIT;
	}CCR1;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 CCR2:16;
			u32 CCR2_TIM2_TIM5:16;
		}BIT;
	}CCR2;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 CCR3:16;
			u32 CCR3_TIM2_TIM5:16;
		}BIT;
	}CCR3;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 CCR4:16;
			u32 CCR4_TIM2_TIM5:16;
		}BIT;
	}CCR4;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 DT:8;
			u32 LOCK:2;
			u32 OSSI:1;
			u32 OSSR:1;
			u32 BKE:1;
			u32 BKP:1;
			u32 AOE:1;
			u32 MOE:1;
			u32 RESERVED_0:16;
		}BIT;
	}BDTR;/*in timer 1 only*/

	union
	{
		u32 REGISTER;
		struct
		{
			u32 DBA:5;// DMA base address
			u32 RESERVED_0:3;
			u32 DBL:5;// DMA burst length
			u32 RESERVED_1:19;
		}BIT;
	}DCR;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 DMAB:32;//DMA register for burst accesses
		}BIT;
	}DMAR;

	union
	{
		u32 REGISTER;
		struct
		{
			u32 TI1_RMP_TIM11:2;
			u32 RESERVED_0:4;
			u32 TI4_RMP_TIM5:2;
			u32 RESERVED_1:2;
			u32 ITR1_RMP_TIM2:2;//Internal trigger 1 remap
			u32 RESERVED_2:20;
		}BIT;
	}OR;
}TIM_REG;


/*Advanced control timer */
#define TIM1_BASE_ADDRESS		(0x40010000)

/*General purpose timers */
#define TIM2_BASE_ADDRESS       (0x40000000)
#define TIM3_BASE_ADDRESS       (0x40000400)
#define TIM4_BASE_ADDRESS       (0x40000800)
#define TIM5_BASE_ADDRESS       (0x40000C00)
#define TIM9_BASE_ADDRESS       (0x40014000)
#define TIM10_BASE_ADDRESS      (0x40014400)
#define TIM11_BASE_ADDRESS      (0x40014800)

#define TIM1_R					((volatile TIM_REG*)TIM1_BASE_ADDRESS)
#define TIM2_R                  ((volatile TIM_REG*)TIM2_BASE_ADDRESS)
#define TIM3_R                  ((volatile TIM_REG*)TIM3_BASE_ADDRESS)
#define TIM4_R                  ((volatile TIM_REG*)TIM4_BASE_ADDRESS)
#define TIM5_R                  ((volatile TIM_REG*)TIM5_BASE_ADDRESS)
#define TIM9_R                  ((volatile TIM_REG*)TIM9_BASE_ADDRESS)
#define TIM10_R                 ((volatile TIM_REG*)TIM10_BASE_ADDRESS)
#define TIM11_R                 ((volatile TIM_REG*)TIM11_BASE_ADDRESS)

#endif /* 02_MCAL_06_TIMER_PRIVATE_H_ */
