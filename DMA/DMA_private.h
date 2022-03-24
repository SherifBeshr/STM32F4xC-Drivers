/*==================================================================================================================
===============================   - DMA_private.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#include "std_types.h"

/*====================================================================================================================
	-----> Macros
			*  Base_Address is					0xE000E010
=====================================================================================================================*/

#define DMA1_BASE_ADDRESS						0x40026000
#define DMA2_BASE_ADDRESS						0x40026400


/* Structure type to access the DMA Streams [0..7] */
typedef struct{

	volatile u32  CR  			;			/* DMA stream x configuration register      */
	volatile u32  NDTR			;   		/* DMA stream x number of data register     */
	volatile u32  PAR 			;   		/* DMA stream x peripheral address register */
	volatile u32  M0AR			;   		/* DMA stream x memory 0 address register   */
	volatile u32  M1AR			;   		/* DMA stream x memory 1 address register   */
	volatile u32  FCR 			;   		/* DMA stream x FIFO control register       */
}DMA_Stream_t;

/* Structure type to access the DMA */
typedef struct{

	volatile u32 LISR			;			/* DMA low interrupt status register,      Address offset: 0x00	*/
	volatile u32 HISR			;   		/* DMA high interrupt status register,     Address offset: 0x04	*/
	volatile u32 LIFCR			;   		/* DMA low interrupt flag clear register,  Address offset: 0x08	*/
	volatile u32 HIFCR			;   		/* DMA high interrupt flag clear register, Address offset: 0x0C	*/
	volatile DMA_Stream_t *DMA_Stream[8]	;	/* 8 different streams each has 6 registers 					*/
}DMA_Typedef_t;



#define DMA1									((DMA_Typedef_t *)DMA1_BASE_ADDRESS)
#define DMA2									((DMA_Typedef_t *)DMA2_BASE_ADDRESS)

/********************************************************************************************************************/
/*																													*/
/*													DMA Registers													*/
/*																													*/
/********************************************************************************************************************/

/********************************************************************************************************************/
/*										Bit definition for DMA_LISR_Registers										*/
/********************************************************************************************************************/






#endif /* DMA_PRIVATE_H_ */
