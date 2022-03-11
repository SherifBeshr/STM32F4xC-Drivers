/*==================================================================================================================
===============================   - GPIO_prog.c					 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "GPIO_interface.h"
#include "common_macros.h"

/*====================================================   Start_FUNCTION   ==========================================*/
/*	Function Set The Mode Of Pin Mode Take 2Bits	
*			1- MODE_INPUT 
*			2- MODE_OUTPUT
*			3- MODE_ALTF  
*			4- MODE_ANALOG
*/
void GPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode)
{
	switch(Copy_u8PortName)
	{
		case (GPIOA_PORT): GPIOA->MODER |= (u32) (Copy_u8Mode << (2 * Copy_u8PinNum ));	break;
		case (GPIOB_PORT): GPIOB->MODER |= (u32) (Copy_u8Mode << (2 * Copy_u8PinNum ));	break;
		case (GPIOC_PORT): GPIOC->MODER |= (u32) (Copy_u8Mode << (2 * Copy_u8PinNum ));	break;
		case (GPIOD_PORT): GPIOD->MODER |= (u32) (Copy_u8Mode << (2 * Copy_u8PinNum ));	break;
		case (GPIOE_PORT): GPIOE->MODER |= (u32) (Copy_u8Mode << (2 * Copy_u8PinNum ));	break;
		case (GPIOH_PORT): GPIOH->MODER |= (u32) (Copy_u8Mode << (2 * Copy_u8PinNum ));	break;
	}
}
/*====================================================   END_ FUNCTION   ============================================*/
