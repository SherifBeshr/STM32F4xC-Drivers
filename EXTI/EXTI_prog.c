/*==================================================================================================================
===============================   - EXTI_prog.c					 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "EXTI_interface.h"
#include "common_macros.h"

/*====================================================   Start_FUNCTION   ==========================================*/
/* Function to Enable Line */
void EXTI_vEnableLine(u8 Copy_u8LineNum)
{
	SET_BIT(EXTI->IMR, Copy_u8LineNum);
}

/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/* Function to Disable Line */
void EXTI_vMaskLine(u8 Copy_u8LineNum)
{
	CLR_BIT(EXTI->IMR, Copy_u8LineNum);
}

/*====================================================   END_ FUNCTION   ===========================================*/

/*====================================================   Start_FUNCTION   ==========================================*/
/* Function to Set Event State ( Falling , Rising , On Change)*/
void EXTI_vEventType(u8 Copy_u8LineNum, u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case(EXTI_STATE_RISING):
		SET_BIT(EXTI->RTSR, Copy_u8LineNum);
		CLR_BIT(EXTI->FTSR, Copy_u8LineNum);
		break;
		
		case(EXTI_STATE_FALLING):
		SET_BIT(EXTI->FTSR, Copy_u8LineNum);
		CLR_BIT(EXTI->RTSR, Copy_u8LineNum);
		break;
		
		case(EXTI_STATE_ONCHANGE):
		SET_BIT(EXTI->FTSR, Copy_u8LineNum);
		SET_BIT(EXTI->RTSR, Copy_u8LineNum);
		break;
		
		default: /* ERROR */ break;
	}
}

/*====================================================   END_ FUNCTION   ===========================================*/
/* Function to Set SW Trigger */
void EXTI_vTrigSW(u8 Copy_u8LineNum)
{
	
}


/*====================================================   Start_FUNCTION   ==========================================*/
/* Function to Set Port */
void EXTI_vSelectPort(u8 Copy_u8LineNum, u8 Copy_u8PortID)
{
	
}
/*====================================================   END_ FUNCTION   ===========================================*/