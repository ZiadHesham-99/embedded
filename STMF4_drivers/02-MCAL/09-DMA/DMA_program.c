/*
 * DMA_program.c
 *
 *  Created on: Aug 7, 2023
 *      Author: ziad
 */
#include"../../01-LIB/01-TYPES/STD_TYPPES.h"
#include"../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include"DMA_interface.h"
#include"DMA_config.h"
#include"DMA_private.h"

DMA_callback_t global_TransferCompleteCallback;

void DMA_vidTransferStart(DMA_CH_NUM dmaChannelNum, u32 *srcAddress ,u32 *destAddress,DATA_TRANSFER_DIRECTION dataTransferDirection ,DATA_SIZE dataSize , INCREMENT_MODE incrementMode , u16 blockSize ,, DMA_callback_t callbackFunc ){
	/***************************************config.h configurations *************************/
	// Direct mode error interrupt config
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.DMEIE = DIRECT_MODE_INTERRUPT ;
	// transfer error interrupt
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.TEIE = TRANSFER_ERROR_INTERRUPT;
	//half transfer error interrupt
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.HTIE = HALF_TRANSFER_INTERRUPT ;
	//transfer complete error interrupt
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.TCIE = TRANSFER_COMPLETE_INTERRUPT ;
	// circular mode
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.CIRC = CIRCULAR_MODE ;
	/******************************************************************************************/

	//Data transfer direction
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.DIR =dataTransferDirection;
	switch(incrementMode){
	case INCREMENT_MODE_SRC_INCREMENT:DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.PINC =1;break;
	case INCREMENT_MODE_DST_INCREMENT:DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.MINC =1;break;
	case INCREMENT_MODE_BOTH_INCREMENT:DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.PINC =1;INCREMENT_MODE_DST_INCREMENT:DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.MINC =1;break;
	}

	/*data size ------> put same size for both to avoid padding or alignment*/
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.PSIZE =dataSize;
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.MSIZE =dataSize;

	/*let the channel selection is the same for every stream selection*/
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.CHSEL=dmaChannelNum;

	/*block size to be transfered */
	DMA_R->DMA_CH[dmaChannelNum].SXNDTR = blockSize;

	/*source address*/
	DMA_R->DMA_CH[dmaChannelNum].SXPAR.REG= srcAddress;

	/*destination address*/
	DMA_R->DMA_CH[dmaChannelNum].SXM0AR =destAddress ;

	/*set callback function for transfer complete*/
	global_TransferCompleteCallback = callbackFunc ;


	/*enable channel*/
	DMA_R->DMA_CH[dmaChannelNum].SXCR.BIT.EN =1;

}


void DMA1_Channel1_IRQHandler(void) {

	global_TransferCompleteCallback();

}


