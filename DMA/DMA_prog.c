/*==================================================================================================================
===============================   - DMA_prog.c				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "std_types.h"
#include "common_macros.h"
#include "DMA_interface.h"


/* 1) Function to Initialize DMA */
void DMA_vStreamInit(u8 Copy_u8DMA_ID, u8 Copy_u8Stream_ID)
{
	switch(Copy_u8DMA_ID)
	{
		case DMA1_ID:
				/* 1- Check EN must be Disabled First */
				DMA1->DMA_Stream[0]->CR &=~(1U<<0);
				/* Make sure it is disabled */
				while((DMA1->DMA_Stream[0]->CR) == 1U){}
			
				/* 2-SoftWare Priority Stream :( LOW , Medium , High , VeryHigh ) BIT(16 , 17)-> VeryHigh  */
				DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (DMA_PL<<16U);
			
				/* 3- Set DIR Mode :( MTM ,PTM ,MTP ) BIT (6,7) */
				DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (DMA_DIR<<6U);

				/* 4- Set M & M SIZE BIT(13,14) ,(11,12) :(Byte , HalfWord , Word) */
					/* 	As Word 32 For Source	*/ 
					DMA1->DMA_Stream[Copy_u8Stream_ID]->CR &=~(1U<<11U);
					DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<12U);
					/* 	As Word 32 For Distination	*/ 
					DMA1->DMA_Stream[Copy_u8Stream_ID]->CR &=~(1U<<13U);
					DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<14U);
				
				/* 5- Disable Direct Mode to used fifo  */
				DMA1->DMA_Stream[Copy_u8Stream_ID]->FCR |= (1U<<2U);
				
				/* 6-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
				/* Use (1/2) full FIFO */
				DMA1->DMA_Stream[Copy_u8Stream_ID]->FCR |= (1U<<0U);
				DMA1->DMA_Stream[Copy_u8Stream_ID]->FCR &=~(1U<<1U);
				
				/* 7-SRC & DIS Increament For Both */
				DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<9U);
				DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<10U);
				
				/* 8- EN Interrput Of Transfer Complete */
				DMA1->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<4U);

		break;
		case DMA2_ID:
							/* 1- Check EN must be Disabled First */
				DMA2->DMA_Stream[0]->CR &=~(1U<<0);
				/* Make sure it is disabled */
				while((DMA2->DMA_Stream[0]->CR) == 1U){}
			
				/* 2-SoftWare Priority Stream :( LOW , Medium , High , VeryHigh ) BIT(16 , 17)-> VeryHigh  */
				DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (DMA_PL<<16U);
			
				/* 3- Set DIR Mode :( MTM ,PTM ,MTP ) BIT (6,7) */
				DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (DMA_DIR<<6U);

				/* 4- Set M & M SIZE BIT(13,14) ,(11,12) :(Byte , HalfWord , Word) */
					/* 	As Word 32 For Source	*/ 
					DMA2->DMA_Stream[Copy_u8Stream_ID]->CR &=~(1U<<11U);
					DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<12U);
					/* 	As Word 32 For Distination	*/ 
					DMA2->DMA_Stream[Copy_u8Stream_ID]->CR &=~(1U<<13U);
					DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<14U);
				
				/* 5- Disable Direct Mode to used fifo  */
				DMA2->DMA_Stream[Copy_u8Stream_ID]->FCR |= (1U<<2U);
				
				/* 6-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
				/* Use (1/2) full FIFO */
				DMA2->DMA_Stream[Copy_u8Stream_ID]->FCR |= (1U<<0U);
				DMA2->DMA_Stream[Copy_u8Stream_ID]->FCR &=~(1U<<1U);
				
				/* 7-SRC & DIS Increament For Both */
				DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<9U);
				DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<10U);
				
				/* 8- EN Interrput Of Transfer Complete */
				DMA2->DMA_Stream[Copy_u8Stream_ID]->CR |= (1U<<4U);
			
		break;
	}
}
