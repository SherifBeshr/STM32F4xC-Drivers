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
		case GPIOA_PORT : GPIOA->MODER |= (u32) (Copy_u8Mode << (2U* Copy_u8PinNum ));	break;
		case GPIOB_PORT : GPIOB->MODER |= (u32) (Copy_u8Mode << (2U* Copy_u8PinNum ));	break;
		case GPIOC_PORT : GPIOC->MODER |= (u32) (Copy_u8Mode << (2U* Copy_u8PinNum ));	break;
		case GPIOD_PORT : GPIOD->MODER |= (u32) (Copy_u8Mode << (2U* Copy_u8PinNum ));	break;
		case GPIOE_PORT : GPIOE->MODER |= (u32) (Copy_u8Mode << (2U* Copy_u8PinNum ));	break;
		case GPIOH_PORT : GPIOH->MODER |= (u32) (Copy_u8Mode << (2U* Copy_u8PinNum ));	break;
		default: 			/* ERROR */													break;

	}
}
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/*	Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1) :
*		- OUTPUT_TYPE_PUSH_PULL
*		- OUTPUT_TYPE_OPEN_DRAIN	
*/
void  GPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutputType)
{
		switch(Copy_u8PortName)
	{
		case GPIOA_PORT	: GPIOA->OTYPER |= (u32) (Copy_u8OutputType << ( Copy_u8PinNum ));	break;
		case GPIOB_PORT	: GPIOB->OTYPER |= (u32) (Copy_u8OutputType << ( Copy_u8PinNum ));	break;
		case GPIOC_PORT	: GPIOC->OTYPER |= (u32) (Copy_u8OutputType << ( Copy_u8PinNum ));	break;
		case GPIOD_PORT	: GPIOD->OTYPER |= (u32) (Copy_u8OutputType << ( Copy_u8PinNum ));	break;
		case GPIOE_PORT	: GPIOE->OTYPER |= (u32) (Copy_u8OutputType << ( Copy_u8PinNum ));	break;
		case GPIOH_PORT	: GPIOH->OTYPER |= (u32) (Copy_u8OutputType << ( Copy_u8PinNum ));	break;
		default: 			/* ERROR */														break;

	}
}	
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/* Function Set The Speed (LOW , Meduim , High ,VeryHaigh):		
*	 - OUTPUT_SPEED_LOW      
*	 - OUTPUT_SPEED_MEDUIM   
*	 - OUTPUT_SPEED_HIGH     
*	 - OUTPUT_SPEED_VERY_HIGH	
*/
void GPIO_vSetPinOutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutSpeed)
{
	switch(Copy_u8PortName)
	{
		case GPIOA_PORT	: GPIOA->OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum ));	break;
		case GPIOB_PORT	: GPIOB->OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum ));	break;
		case GPIOC_PORT	: GPIOC->OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum ));	break;
		case GPIOD_PORT	: GPIOD->OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum ));	break;
		case GPIOE_PORT	: GPIOE->OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum ));	break;
		case GPIOH_PORT	: GPIOH->OSPEEDR |= (u32) (Copy_u8OutSpeed << (2U* Copy_u8PinNum ));	break;
		default: 			/* ERROR */															break;

	}
}
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/*	Function Set The PULL :			
*		- PULL_OFF
*		- PULL_UP
*		- PULL_DOWN
*/
void GPIO_vSetPullType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType)
{
	switch(Copy_u8PortName)
	{
		case GPIOA_PORT	: GPIOA->PUPDR |= (u32) (Copy_u8PullType << (2U* Copy_u8PinNum ));	break;
		case GPIOB_PORT	: GPIOB->PUPDR |= (u32) (Copy_u8PullType << (2U* Copy_u8PinNum ));	break;
		case GPIOC_PORT	: GPIOC->PUPDR |= (u32) (Copy_u8PullType << (2U* Copy_u8PinNum ));	break;
		case GPIOD_PORT	: GPIOD->PUPDR |= (u32) (Copy_u8PullType << (2U* Copy_u8PinNum ));	break;
		case GPIOE_PORT	: GPIOE->PUPDR |= (u32) (Copy_u8PullType << (2U* Copy_u8PinNum ));	break;
		case GPIOH_PORT	: GPIOH->PUPDR |= (u32) (Copy_u8PullType << (2U* Copy_u8PinNum ));	break;
		default: 			/* ERROR */														break;
	}
}
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/*		
 *Function To Read Data From IDR
 */
u8 GPIO_u8ReadData(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	u8 L_u8Data = 0 ;
	switch(Copy_u8PortName)
	{
		case GPIOA_PORT	: L_u8Data = GET_BIT(GPIOA->IDR, Copy_u8PinNum); break;
		case GPIOB_PORT	: L_u8Data = GET_BIT(GPIOB->IDR, Copy_u8PinNum); break;
		case GPIOC_PORT	: L_u8Data = GET_BIT(GPIOC->IDR, Copy_u8PinNum); break;
		case GPIOD_PORT	: L_u8Data = GET_BIT(GPIOD->IDR, Copy_u8PinNum); break;
		case GPIOE_PORT	: L_u8Data = GET_BIT(GPIOE->IDR, Copy_u8PinNum); break;
		case GPIOH_PORT	: L_u8Data = GET_BIT(GPIOH->IDR, Copy_u8PinNum); break;
		default: 			/* ERROR */									 break;
	}
	return L_u8Data;
}
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/*		
* Function To Write Data At ODR	Value :
*	 - HIGH  
*	 - LOW	
*/

void GPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{

	if(Copy_u8State==GPIO_HIGH)
	{
		switch(Copy_u8PortName)
		{
		case GPIOA_PORT :  SET_BIT(GPIOA ->ODR,Copy_u8PinNum); break;
		case GPIOB_PORT :  SET_BIT(GPIOB ->ODR,Copy_u8PinNum); break;
		case GPIOC_PORT :  SET_BIT(GPIOC ->ODR,Copy_u8PinNum); break;
		case GPIOD_PORT :  SET_BIT(GPIOD ->ODR,Copy_u8PinNum); break;
		case GPIOE_PORT :  SET_BIT(GPIOE ->ODR,Copy_u8PinNum); break;
		case GPIOH_PORT :  SET_BIT(GPIOH ->ODR,Copy_u8PinNum); break;
		default: 			/* ERROR */						   break;
		}		
	}
	else{
		switch(Copy_u8PortName)
		{
		case GPIOA_PORT :  CLR_BIT(GPIOA ->ODR,Copy_u8PinNum); break;
		case GPIOB_PORT :  CLR_BIT(GPIOB ->ODR,Copy_u8PinNum); break;
		case GPIOC_PORT :  CLR_BIT(GPIOC ->ODR,Copy_u8PinNum); break;
		case GPIOD_PORT :  CLR_BIT(GPIOD ->ODR,Copy_u8PinNum); break;
		case GPIOE_PORT :  CLR_BIT(GPIOE ->ODR,Copy_u8PinNum); break;
		case GPIOH_PORT :  CLR_BIT(GPIOH ->ODR,Copy_u8PinNum); break;
		default: 			/* ERROR */						   break;
		}
	}
}
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/*		
* Function To Write Data At ODR	Value in a single instruction with BSRR register ( ATMOIC ):
*	 - HIGH  
*	 - LOW	
*/
void GPIO_vDirectionSetReset(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
	if( Copy_u8State == GPIO_STATE_HIGH )
	{
		switch(Copy_u8PortName)
		{
			case GPIOA_PORT :	GPIOA->BSRR = (1U<<Copy_u8PinNum);	break;
			case GPIOB_PORT :	GPIOB->BSRR = (1U<<Copy_u8PinNum);	break;
			case GPIOC_PORT :	GPIOC->BSRR = (1U<<Copy_u8PinNum);	break;
			case GPIOD_PORT :	GPIOD->BSRR = (1U<<Copy_u8PinNum);	break;
			case GPIOE_PORT :	GPIOE->BSRR = (1U<<Copy_u8PinNum);	break;
			case GPIOH_PORT:	GPIOH->BSRR = (1U<<Copy_u8PinNum);	break;
			default: 			/* ERROR */							break;

		}		
	}
	else
	{
		switch(Copy_u8PortName)
		{
			case GPIOA_PORT :	GPIOA->BSRR = (1U<<(Copy_u8PinNum+16));	break;
			case GPIOB_PORT :	GPIOB->BSRR = (1U<<(Copy_u8PinNum+16));	break;
			case GPIOC_PORT :	GPIOC->BSRR = (1U<<(Copy_u8PinNum+16));	break;
			case GPIOD_PORT :	GPIOD->BSRR = (1U<<(Copy_u8PinNum+16));	break;
			case GPIOE_PORT :	GPIOE->BSRR = (1U<<(Copy_u8PinNum+16));	break;
			case GPIOH_PORT :	GPIOH->BSRR = (1U<<(Copy_u8PinNum+16));	break;
			default: 			/* ERROR */								break;

		}
	}
}
/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/*
- Function to Lock pin :
	1)Set Pin bit
	2)Set bit 16
	3)Wait bit 16 =high
*/
void GPIO_vPinLock(u8 Copy_u8PortName ,u8 Copy_u8PinNum )
{
		switch(Copy_u8PortName)
		{
			case GPIOA_PORT :
				SET_BIT(GPIOA->LCKR,Copy_u8PinNum);
				SET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN);
				while(!(GET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN)));
				break;
			
				case GPIOB_PORT :
				SET_BIT(GPIOA->LCKR,Copy_u8PinNum);
				SET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN);
				while(!(GET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN)));
				break;
				
				case GPIOC_PORT :
				SET_BIT(GPIOA->LCKR,Copy_u8PinNum);
				SET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN);
				while(!(GET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN)));
				break;
				
				case GPIOD_PORT :
				SET_BIT(GPIOA->LCKR,Copy_u8PinNum);
				SET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN);
				while(!(GET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN)));
				break;
				
				case GPIOE_PORT :
				SET_BIT(GPIOA->LCKR,Copy_u8PinNum);
				SET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN);
				while(!(GET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN)));
				break;
				
				case GPIOH_PORT :
				SET_BIT(GPIOA->LCKR,Copy_u8PinNum);
				SET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN);
				while(!(GET_BIT(GPIOA->LCKR,GPIO_LOCK_PIN)));
				break;
		}
}

/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
void GPIO_vSetPinAltFn( u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8ALF )
{
	if(Copy_u8PinNum <= 7U)
	{
		switch(Copy_u8PortName)
		{
			case GPIOA_PORT: GPIOA->AFRL |= (u32)((Copy_u8ALF << (4U * Copy_u8PinNum)));	break;
			case GPIOB_PORT: GPIOA->AFRL |= (u32)((Copy_u8ALF << (4U * Copy_u8PinNum)));	break;
			case GPIOC_PORT: GPIOA->AFRL |= (u32)((Copy_u8ALF << (4U * Copy_u8PinNum)));	break;
			case GPIOD_PORT: GPIOA->AFRL |= (u32)((Copy_u8ALF << (4U * Copy_u8PinNum)));	break;
			case GPIOE_PORT: GPIOA->AFRL |= (u32)((Copy_u8ALF << (4U * Copy_u8PinNum)));	break;
			case GPIOH_PORT: GPIOA->AFRL |= (u32)((Copy_u8ALF << (4U * Copy_u8PinNum)));	break;
			default: 			/* ERROR */													break;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
			case GPIOA_PORT: GPIOA->AFRH |= (u32)((Copy_u8ALF << ((4U * Copy_u8PinNum) - 32U)));	break;
			case GPIOB_PORT: GPIOA->AFRH |= (u32)((Copy_u8ALF << ((4U * Copy_u8PinNum) - 32U)));	break;
			case GPIOC_PORT: GPIOA->AFRH |= (u32)((Copy_u8ALF << ((4U * Copy_u8PinNum) - 32U)));	break;
			case GPIOD_PORT: GPIOA->AFRH |= (u32)((Copy_u8ALF << ((4U * Copy_u8PinNum) - 32U)));	break;
			case GPIOE_PORT: GPIOA->AFRH |= (u32)((Copy_u8ALF << ((4U * Copy_u8PinNum) - 32U)));	break;
			case GPIOH_PORT: GPIOA->AFRH |= (u32)((Copy_u8ALF << ((4U * Copy_u8PinNum) - 32U)));	break;
			default: 			/* ERROR */															break;
		}
	}
}

/*====================================================   END_ FUNCTION   ===========================================*/
