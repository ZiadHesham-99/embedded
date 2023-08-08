/*
 * DMA_private.h
 *
 *  Created on: Aug 7, 2023
 *      Author: ziad
 */

#ifndef _MCAL_09_DMA_DMA_PRIVATE_H_
#define _MCAL_09_DMA_DMA_PRIVATE_H_

#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"DMA_interface.h"
#include "DMA_config.h"



typedef struct {
	union {
		u32 REG;
		struct {
			u32 EN:1;      /* Stream disable/enable . */
			u32 DMEIE:1;   /* Direct mode error interrupt disable/enable . */
			u32 TEIE:1;    /* Transfer error interrupt disable/enable. */
			u32 HTIE:1;    /* Half transfer interrupt disable/enable. */
			u32 TCIE:1;    /* Transfer complete interrupt disable/enable. */
			u32 PFCTRL:1;  /*  DMA flow controller. / Peripheral flow controller */
			u32 DIR:2;     /* Data transfer direction. 00: Peripheral-to-memory 01: Memory-to-peripheral 10: Memory-to-memory*/
			u32 CIRC:1;    /* Circular mode  disable/enable. */
			u32 PINC:1;    /* Peripheral increment mode disable/enable. */
			u32 MINC:1;    /* Memory increment mode disable/enable. */
			u32 PSIZE:2;   /* Peripheral data size 00: Byte (8-bit) 01: Half-word (16-bit) 10: Word (32-bit). */
			u32 MSIZE:2;   /* Memory data size.00: Byte (8-bit) 01: Half-word (16-bit) 10: Word (32-bit) */
			u32 PINCOS:1;  /* Peripheral increment offset size. */
			u32 PL:2;      /* Priority level. 00: Low 01: Medium 10: High 11: Very high*/
			u32 DBM:1;     /* Double buffer mode  disable/enable . */
			u32 CT:1;      /* Current target (double buffer). */
			u32 RESERVED_0:1;
			u32 PBURST:2;  /* Peripheral burst transfer configuration 00: single transfer 01: INCR4 10: INCR8  11: INCR16 . */
			u32 MBURST:2;  /* Memory burst transfer configuration. 00: single transfer 01: INCR4 10: INCR8  11: INCR16  */
			u32 CHSEL:3;   /* Channel selection. from 0 to 7 */
			u32 RESERVED:4;
		}BIT;
	}SXCR; /* DMA stream X configuration register */


	union {
		u32 REG;
		struct {
			u32 NDTR:16;   /* Number of data to transfer. */
			u32 RESERVED:16;
		}BIT;
	}SXNDTR; /* DMA stream X number of data register */

	union {
		u32 REG;
		struct {
			u32 PA:32;    /* Peripheral address. */
		}BIT;
	}SXPAR; /* DMA stream X peripheral address register */

	union {
		u32 REG;
		struct {
			u32 M0A:32;    /* Memory0 address. */
		}BIT;
	}SXM0AR; /* DMA stream X Memory0 address register */

	union {
		u32 REG;
		struct {
			u32 M1A:32;    /* Memory1 address in case of double buffer mode. */
		}BIT;
	}SXM1AR; /* DMA stream X Memory1 address register in case of double buffer mode */

	union {
		u32 REG;
		struct {
			u32 FTH:2;    /* FIFO threshold selection 00: 1/4 full FIFO 01: 1/2 full FIFO 10: 3/4 full FIFO 11: full FIFO. */
			u32 DMDIS:1;  /* Direct mode  enable /disable */
			u32 FS:3;	  /* FIFO status*/
			u32 RESERVED_0 : 1;
			u32 FEIE:1;   /*: FIFO error interrupt disable /enable */
		}BIT;
	}SXFCR; /* DMA stream X FIFO control register */


}CHANNEL_ADRESSES_BLOCK ;
typedef struct {

	union {
		u32 REG;
		struct {
			u32 FEIF0:1;   		// Stream 0 FIFO error interrupt flag
			u32 RESERVED_0:1;	//Reserved0
			u32 DMEIF0:1;  		// Stream 0 direct mode error interrupt flag
			u32 TEIF0:1;   		// Stream 0 transfer error interrupt flag
			u32 HTIF0:1;   		// Stream 0 half transfer interrupt flag
			u32 TCIF0:1;   		// Stream 0 transfer complete interrupt flag

			u32 FEIF1:1;   		// Stream 1 FIFO error interrupt flag
			u32 RESERVED_1:1;	//Reserved1
			u32 DMEIF1:1;  		// Stream 1 direct mode error interrupt flag
			u32 TEIF1:1;   		// Stream 1 transfer error interrupt flag
			u32 HTIF1:1;   		// Stream 1 half transfer interrupt flag
			u32 TCIF1:1;   		// Stream 1 transfer complete interrupt flag

			u32 RESERVED_2:4;

			u32 FEIF2:1;   		// Stream 2 FIFO error interrupt flag
			u32 RESERVED_3:1;	//Reserved2
			u32 DMEIF2:1;  		// Stream 2 direct mode error interrupt flag
			u32 TEIF2:1;   		// Stream 2 transfer error interrupt flag
			u32 HTIF2:1;   		// Stream 2 half transfer interrupt flag
			u32 TCIF2:1;   		// Stream 2 transfer complete interrupt flag

			u32 FEIF3:1;   		// Stream 3 FIFO error interrupt flag
			u32 RESERVED_4:1;	//Reserved3
			u32 DMEIF3:1;  		// Stream 3 direct mode error interrupt flag
			u32 TEIF3:1;   		// Stream 3 transfer error interrupt flag
			u32 HTIF3:1;   		// Stream 3 half transfer interrupt flag
			u32 TCIF3:1;   		// Stream 3 transfer complete interrupt flag

			u32 RESERVED_5:4;

		} BIT;
	} LISR;// DMA low interrupt status register (DMA_LISR)

	union {
		u32 REG;
		struct {
			u32 FEIF4:1;   		// Stream 4 FIFO error interrupt flag
			u32 RESERVED_0:1;	//Reserved4
			u32 DMEIF4:1;  		// Stream 4 direct mode error interrupt flag
			u32 TEIF4:1;   		// Stream 4 transfer error interrupt flag
			u32 HTIF4:1;   		// Stream 4 half transfer interrupt flag
			u32 TCIF4:1;   		// Stream 4 transfer complete interrupt flag

			u32 FEIF5:1;   		// Stream 5 FIFO error interrupt flag
			u32 RESERVED_1:1;	//Reserved5
			u32 DMEIF5:1;  		// Stream 5 direct mode error interrupt flag
			u32 TEIF5:1;   		// Stream 5 transfer error interrupt flag
			u32 HTIF5:1;   		// Stream 5 half transfer interrupt flag
			u32 TCIF5:1;   		// Stream 5 transfer complete interrupt flag

			u32 RESERVED_2:4;

			u32 FEIF6:1;   		// Stream 6 FIFO error interrupt flag
			u32 RESERVED_3:1;	//Reserved6
			u32 DMEIF6:1;  		// Stream 6 direct mode error interrupt flag
			u32 TEIF6:1;   		// Stream 6 transfer error interrupt flag
			u32 HTIF6:1;   		// Stream 6 half transfer interrupt flag
			u32 TCIF6:1;   		// Stream 6 transfer complete interrupt flag

			u32 FEIF7:1;   		// Stream 7 FIFO error interrupt flag
			u32 RESERVED_4:1;	//Reserved7
			u32 DMEIF7:1;  		// Stream 7 direct mode error interrupt flag
			u32 TEIF7:1;   		// Stream 7 transfer error interrupt flag
			u32 HTIF7:1;   		// Stream 7 half transfer interrupt flag
			u32 TCIF7:1;   		// Stream 7 transfer complete interrupt flag

			u32 RESERVED_5:4;

		} BIT;
	} HISR;// DMA High interrupt status register (DMA_LISR)

	union {
		u32 REG;
		struct {
			u32 CFEIF0:1;  /* Stream 0 clear FIFO error interrupt flag  */
			u32 RESERVED_0:1;
			u32 CDMEIF0:1; /* Stream 0 clear direct mode error interrupt flag  */
			u32 CTEIF0:1;  /* Stream 0 clear transfer error interrupt  flag  */
			u32 CHTIF0:1;  /* Stream 0 clear half transfer interrupt flag  */
			u32 CTCIF0:1;  /* Stream 0 clear transfer complete interrupt flag  */

			u32 CFEIF1:1;  /* Stream 1 clear FIFO error interrupt flag  */
			u32 RESERVED_1:1;
			u32 CDMEIF1:1; /* Stream 1 clear direct mode error interrupt flag  */
			u32 CTEIF1:1;  /* Stream 1 clear transfer error interrupt  flag  */
			u32 CHTIF1:1;  /* Stream 1 clear half transfer interrupt flag  */
			u32 CTCIF1:1;  /* Stream 1 clear transfer complete interrupt flag  */

			u32 RESERVED_2:4;

			u32 CFEIF2:1;  /* Stream 2 clear FIFO error interrupt flag  */
			u32 RESERVED_3:1;
			u32 CDMEIF2:1; /* Stream 2 clear direct mode error interrupt flag  */
			u32 CTEIF2:1;  /* Stream 2 clear transfer error interrupt  flag  */
			u32 CHTIF2:1;  /* Stream 2 clear half transfer interrupt flag  */
			u32 CTCIF2:1;  /* Stream 2 clear transfer complete interrupt flag  */

			u32 CFEIF3:1;  /* Stream 3 clear FIFO error interrupt flag  */
			u32 RESERVED_4:1;
			u32 CDMEIF3:1; /* Stream 3 clear direct mode error interrupt flag  */
			u32 CTEIF3:1;  /* Stream 3 clear transfer error interrupt  flag  */
			u32 CHTIF3:1;  /* Stream 3 clear half transfer interrupt flag  */
			u32 CTCIF3:1;  /* Stream 3 clear transfer complete interrupt flag  */

			u32 RESERVED_5:4;

		}BIT;
	}LIFCR; /*  low interrupt flag clear register */

	union {
		u32 REG;
		struct {
			u32 CFEIF4:1;  /* Stream 4 clear FIFO error interrupt flag  */
			u32 RESERVED_0:1;
			u32 CDMEIF4:1; /* Stream 4 clear direct mode error interrupt flag  */
			u32 CTEIF4:1;  /* Stream 4 clear transfer error interrupt  flag  */
			u32 CHTIF4:1;  /* Stream 4 clear half transfer interrupt flag  */
			u32 CTCIF4:1;  /* Stream 4 clear transfer complete interrupt flag  */

			u32 CFEIF5:1;  /* Stream 5clear FIFO error interrupt flag  */
			u32 RESERVED_1:1;
			u32 CDMEIF5:1; /* Stream 5clear direct mode error interrupt flag  */
			u32 CTEIF5:1;  /* Stream 5clear transfer error interrupt  flag  */
			u32 CHTIF5:1;  /* Stream 5clear half transfer interrupt flag  */
			u32 CTCIF5:1;  /* Stream 5clear transfer complete interrupt flag  */

			u32 RESERVED_2:4;

			u32 CFEIF6:1;  /* Stream 6 clear FIFO error interrupt flag  */
			u32 RESERVED_3:1;
			u32 CDMEIF6:1; /* Stream 6 clear direct mode error interrupt flag  */
			u32 CTEIF6:1;  /* Stream 6 clear transfer error interrupt  flag  */
			u32 CHTIF6:1;  /* Stream 6 clear half transfer interrupt flag  */
			u32 CTCIF6:1;  /* Stream 6 clear transfer complete interrupt flag  */

			u32 CFEIF7:1;  /* Stream 7 clear FIFO error interrupt flag  */
			u32 RESERVED_4:1;
			u32 CDMEIF7:1; /* Stream 7 clear direct mode error interrupt flag  */
			u32 CTEIF7:1;  /* Stream 7 clear transfer error interrupt  flag  */
			u32 CHTIF7:1;  /* Stream 7 clear half transfer interrupt flag  */
			u32 CTCIF7:1;  /* Stream 7 clear transfer complete interrupt flag  */

			u32 RESERVED_5:4;

		}BIT;
	}HIFCR; /*  High interrupt flag clear register */


	CHANNEL_ADRESSES_BLOCK	DMA_CH[8];

} DMA_REG;

/*DMA 0 Base address */
#define DMA_BASE_ADDRESS       (0x40026000)

#define DMA_R					( (volatile DMA_REG*)DMA_BASE_ADDRESS )




#endif /* 02_MCAL_09_DMA_DMA_PRIVATE_H_ */
