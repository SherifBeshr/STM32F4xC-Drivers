/*==================================================================================================================
===============================   - DMA_interface.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include "DMA_config.h"
#include "DMA_private.h"

#include "std_types.h"


#define DMA1_ID						1U
#define DMA2_ID						2U

/*  Priority Level */
#define DMA_PL_LOW					0U
#define DMA_PL_Medium				1U
#define DMA_PL_HIGH					2U
#define DMA_PL_VERY_HIGH			3U

/*  Data transfer direction */
#define DMA_DIR_PTM					0U
#define DMA_DIR_MTP					1U
#define DMA_DIR_MTM					2U


/* 1) Function to Initialize DMA */
void DMA_vStreamInit(u8 Copy_u8DMA_ID, u8 Copy_u8Stream_ID);

/* 2) Function to Set Source & Destination Addresses  */

/* 3) Function to Initialize DMA */


#endif /* DMA_INTERFACE_H_ */
