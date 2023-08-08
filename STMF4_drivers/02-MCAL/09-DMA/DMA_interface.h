/*
 * DMA_interface.h
 *
 *  Created on: Aug 7, 2023
 *      Author: ziad
 */

#ifndef _MCAL_09_DMA_DMA_INTERFACE_H_
#define _MCAL_09_DMA_DMA_INTERFACE_H_

#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"DMA_config.h"
#include"DMA_private.h"

typedef enum{
	DMA_CH_NUM_0 = (u8)0,
	DMA_CH_NUM_1 = (u8)1,
	DMA_CH_NUM_2 = (u8)2,
	DMA_CH_NUM_3 = (u8)3,
	DMA_CH_NUM_4 = (u8)4,
	DMA_CH_NUM_5 = (u8)5,
	DMA_CH_NUM_6 = (u8)6,
	DMA_CH_NUM_7 = (u8)7
}DMA_CH_NUM;

/*
typedef enum{
	CIRCULAR_MODE_DISABLE = (u8)0,
	CIRCULAR_MODE_ENABLE = (u8)1
}CIRCULAR_MODE;*/

typedef enum{
	INCREMENT_MODE_SRC_INCREMENT = (u8)0,
	INCREMENT_MODE_DST_INCREMENT = (u8)1,
	INCREMENT_MODE_BOTH_INCREMENT = (u8)2
}INCREMENT_MODE;


typedef enum{
	PERIPHERAL_TO_MEMORY = (u8)0,
	MEMORY_TO_PERIPHERAL = (u8)1,
	MEMORY_TO_MEOMRY = (u8)2
}DATA_TRANSFER_DIRECTION;



typedef enum{
	DATA_SIZE_8_BIT = (u8)0,
	DATA_SIZE_16_BIT = (u8)1,
	DATA_SIZE_32_BIT = (u8)2
}DATA_SIZE;

void DMA_vidTransferStart(DMA_CH_NUM dmaChannelNum, u32 *srcAddress ,u32 *destAddress,DATA_TRANSFER_DIRECTION dataTransferDirection ,DATA_SIZE dataSize , INCREMENT_MODE incrementMode , u16 blockSize , DMA_callback_t callbackFunc );


typedef void (*DMA_callback_t)(void);

#endif /* 02_MCAL_09_DMA_DMA_INTERFACE_H_ */
