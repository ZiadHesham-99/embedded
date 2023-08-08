/*
 * DMA_config.h
 *
 *  Created on: Aug 7, 2023
 *      Author: ziad
 */

#ifndef _MCAL_09_DMA_DMA_CONFIG_H_
#define _MCAL_09_DMA_DMA_CONFIG_H_

#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"

#define DISABLE	((u8)0)
#define ENABLE	((u8)1)

/* Direct mode error interrupt disable/enable . */
#define DIRECT_MODE_INTERRUPT 	DISABLE

/* Transfer error interrupt disable/enable. */
#define TRANSFER_ERROR_INTERRUPT 	DISABLE

/* Half transfer interrupt disable/enable. */
#define HALF_TRANSFER_INTERRUPT 	DISABLE

/* Transfer complete interrupt disable/enable. */
#define TRANSFER_COMPLETE_INTERRUPT 	ENABLE

/* Circular mode  disable/enable. */
#define CIRCULAR_MODE		DISABLE

#endif /* 02_MCAL_09_DMA_DMA_CONFIG_H_ */
