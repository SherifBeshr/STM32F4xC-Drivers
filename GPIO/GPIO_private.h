/*==================================================================================================================
===============================   - GPIO_private.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef GPIO_GPIO_PRIVATE_H_
#define GPIO_GPIO_PRIVATE_H_

#include "std_types.h"

/*====================================================================================================================
	-----> Macros
			*  Base_Address is				0x40020000
=====================================================================================================================*/
#define GPIO_BASE_ADDRESS					0x40020000

#define GPIOA_BASE_ADDRESS					(GPIO_BASE_ADDRESS + 0x0000)
#define GPIOB_BASE_ADDRESS					(GPIO_BASE_ADDRESS + 0x0400)
#define GPIOC_BASE_ADDRESS					(GPIO_BASE_ADDRESS + 0x0800)
#define GPIOD_BASE_ADDRESS					(GPIO_BASE_ADDRESS + 0x0C00)
#define GPIOE_BASE_ADDRESS					(GPIO_BASE_ADDRESS + 0x1000)
#define GPIOH_BASE_ADDRESS					(GPIO_BASE_ADDRESS + 0x1C00)

/*====================================================================================================================
	-----> GPIO_TypeDef_t
			*  Register Map
=====================================================================================================================*/
typedef struct
{
	volatile u32 MODER	;					/*  GPIO port mode register,               	Address offset: 0x00      	*/
	volatile u32 OTYPER	;   				/*  GPIO port output type register,        	Address offset: 0x04      	*/
	volatile u32 OSPEEDR;   				/*  GPIO port output speed register,       	Address offset: 0x08      	*/
	volatile u32 PUPDR	;   				/*  GPIO port pull-up/pull-down register,  	Address offset: 0x0C      	*/
	volatile u32 IDR	;   				/*  GPIO port input data register,         	Address offset: 0x10      	*/
	volatile u32 ODR	;   				/*  GPIO port output data register,        	Address offset: 0x14      	*/
	volatile u32 BSRR	;					/*  GPIO port bit set/reset register,      	Address offset: 0x18      	*/
	volatile u32 LCKR	;   				/*  GPIO port configuration lock register, 	Address offset: 0x1C		*/
	volatile u32 AFRL	;   				/*  GPIO alternate function registers LOW, 	Address offset: 0x20		*/
	volatile u32 AFRH	;   				/*  GPIO alternate function registers HIGH,	Address offset: 0x24 		*/	
}GPIO_TypeDef_t;

/*====================================================================================================================
	-)Struct Macros :
			*  Base_Address GPIOx 				
=====================================================================================================================*/
#define GPIOA								((GPIO_TypeDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB								((GPIO_TypeDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC								((GPIO_TypeDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD								((GPIO_TypeDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE								((GPIO_TypeDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOH								((GPIO_TypeDef_t *)GPIOH_BASE_ADDRESS)




#endif /* GPIO_GPIO_PRIVATE_H_ */
