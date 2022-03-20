/*==================================================================================================================
===============================   - NVIC_private.h		 		 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "std_types.h"

/*====================================================================================================================
	-----> Macros
	*  Base_Address is			0xE000E100
=====================================================================================================================*/

#define NVIC_BASE_ADDRESS		0xE000E100

/*====================================================================================================================
	-----> NVIC MACROS
			*  Register Map	NVIC
=====================================================================================================================*/
#define NVIC_ISER_0			(*((volatile u32 *)(0xE000E100))) /* Enable External INT from 0 to 31 */
#define NVIC_ISER_1         (*((volatile u32 *)(0xE000E104)))	/* Enable External INT from 0 to 63 */
#define NVIC_ISER_2         (*((volatile u32 *)(0xE000E108)))	/* Enable External INT from 0 to 95 */
	

	
#define NVIC_ICER_0			(*((volatile u32 *)(0xE000E180))) /* Enable External INT from 0 to 31 */
#define NVIC_ICER_1         (*((volatile u32 *)(0xE000E184)))	/* Enable External INT from 0 to 63 */
#define NVIC_ICER_2         (*((volatile u32 *)(0xE000E188)))	/* Enable External INT from 0 to 95 */


#define NVIC_ISPR_0			(*((volatile u32 *)(0xE000E200)))
#define NVIC_ISPR_1			(*((volatile u32 *)(0xE000E204)))
#define NVIC_ISPR_2			(*((volatile u32 *)(0xE000E208)))
	
#define NVIC_ICPR_0			(*((volatile u32 *)(0xE000E280)))
#define NVIC_ICPR_1			(*((volatile u32 *)(0xE000E284)))
#define NVIC_ICPR_2			(*((volatile u32 *)(0xE000E288)))
	
#define NVIC_IABR_0			(*((volatile u32 *)(0xE000E300)))
#define NVIC_IABR_1			(*((volatile u32 *)(0xE000E304)))
#define NVIC_IABR_2			(*((volatile u32 *)(0xE000E308)))
	
#define NVIC_IPR			((volatile u8 *)0xE00E400)

#define SCB_BASE_ADDRESS	0XE00ED00


											
#endif /* NVIC_PRIVATE_H_ */                
