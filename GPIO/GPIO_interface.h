/*==================================================================================================================
===============================   - GPIO_interface.h			 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "std_types.h"
#include "GPIO_config.h"
#include "GPIO_private.h"



/*==========================================	Function Prototypes	================================================*/

/*===============   1-Function Set The Mode Of Pin	 ===============*/
void GPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode);

/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void GPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutPutType);

/*===============	3-Function Set The Speed Of output pin  (LOW , Meduim , High ,VeryHaigh	===============*/
void GPIO_vSetPinOutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutSpeed);

/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void GPIO_vSetPullType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType);

/*===============   5-Function To Read Data From IDR  ===============*/
u8 GPIO_u8ReadData(u8 Copy_u8PortName ,u8 Copy_u8PinNum);

/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void GPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);

void GPIO_vDirectionSetReset(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);

/*===============   7-Function To Locked   ===============*/
void GPIO_vPinLock(u8 Copy_u8PortName ,u8 Copy_u8PinNum );

/*===============   8-Function To Set ALTF   ===============*/
void GPIO_vSetPinAltFn( u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8ALF );
/*==========================================================================================================*/

/*================= 	STATE		 ==========*/
#define GPIO_STATE_HIGH						1U
#define GPIO_STATE_LOW						0U

/*============ Macros Of Port =================*/
#define GPIOA_PORT   		   				0U
#define GPIOB_PORT   		   				1U
#define GPIOC_PORT   		   				2U
#define GPIOD_PORT   		   				3U
#define GPIOE_PORT   		   				4U
#define GPIOH_PORT   		   				5U
/*============ Macros Of Pins =================*/
#define GPIO_PIN_0        					0U 
#define GPIO_PIN_1        					1U 
#define GPIO_PIN_2        					2U 
#define GPIO_PIN_3        					3U 
#define GPIO_PIN_4        					4U 
#define GPIO_PIN_5        					5U
#define GPIO_PIN_6        					6U
#define GPIO_PIN_7        					7U
#define GPIO_PIN_8        					8U
#define GPIO_PIN_9        					9U
#define GPIO_PIN_10       					10U
#define GPIO_PIN_11       					11U
#define GPIO_PIN_12       					12U
#define GPIO_PIN_13       					13U
#define GPIO_PIN_14       					14U
#define GPIO_PIN_15       					15U
/*============ Macros Of Mode =================*/
#define GPIO_MODE_INPUT    	 				(0x00)
#define GPIO_MODE_OUTPUT   	 				(0x01)
#define GPIO_MODE_ALTF     	 				(0x02)
#define GPIO_MODE_ANALOG   	 				(0x03)
/*============ Macros Of Type =================*/
#define GPIO_OUTPUT_TYPE_PUSH_PULL    		0U
#define GPIO_OUTPUT_TYPE_OPEN_DRAIN   		1U
/*============ Macros Of Speed ================*/
#define GPIO_OUTPUT_SPEED_LOW       		(0x00)
#define GPIO_OUTPUT_SPEED_MEDUIM    		(0x01)
#define GPIO_OUTPUT_SPEED_HIGH      		(0x02)
#define GPIO_OUTPUT_SPEED_VERY_HIGH 		(0x03)
/*============ Macros Of PULL  ================*/
#define GPIO_PULL_OFF              			(0x00)
#define GPIO_PULL_UP               			(0x01)
#define GPIO_PULL_DOWN             			(0x02)
/*============ Macros Of PULL  ================*/
#define GPIO_LOCK_PIN              			16U
/*============ Macros Write Data  =============*/
#define GPIO_HIGH                     		1U
#define GPIO_LOW	                  	 	0U
/*============ Macros ALTF  ===================*/
#define GPIO_ALTFN_0           				(0x00)
#define GPIO_ALTFN_1           				(0x01)
#define GPIO_ALTFN_2           				(0x02)
#define GPIO_ALTFN_3           				(0x03)
#define GPIO_ALTFN_4           				(0x04)
#define GPIO_ALTFN_5           				(0x05)
#define GPIO_ALTFN_6           				(0x06)
#define GPIO_ALTFN_7           				(0x07)
#define GPIO_ALTFN_8           				(0x08)
#define GPIO_ALTFN_9           				(0x09)
#define GPIO_ALTFN_10          				(0x0A)
#define GPIO_ALTFN_11          				(0x0B)
#define GPIO_ALTFN_12          				(0x0C)
#define GPIO_ALTFN_13          				(0x0D)
#define GPIO_ALTFN_14          				(0x0E)
#define GPIO_ALTFN_15          				(0x0F)



#endif /* GPIO_GPIO_INTERFACE_H_ */
