/*==================================================================================================================
===============================   - EXTI_interface.h			 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "std_types.h"


/* Function to Enable Line */
void EXTI_vEnableLine(u8 Copy_u8LineNum);

/* Function to Disable Line */
void EXTI_vMaskLine(u8 Copy_u8LineNum);

/* Function to Set Event State ( Falling , Rising , On Change)*/
void EXTI_vEventType(u8 Copy_u8LineNum, u8 Copy_u8State);

/* Function to Set SW Trigger */
void EXTI_vTrigSW(u8 Copy_u8LineNum);

/* Function to Set Port */
void EXTI_vSelectPort(u8 Copy_u8LineNum, u8 Copy_u8PortID);


#define EXTI_STATE_RISING			0U
#define EXTI_STATE_FALLING			1U
#define EXTI_STATE_ONCHANGE			2U


#endif /* RCC_INTERFACE_H_ */
