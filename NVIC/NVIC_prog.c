/*==================================================================================================================
===============================   - NVIC_prog.c		 			 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "common_macros.h"

#include "NVIC_interface.h"


void NVIC_vEnableINT(u8 Copy_u8IRQNumber)
{
	if(Copy_u8IRQNumber <= 31U)
	{
		NVIC_ISER_0 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 63U)
	{
		Copy_u8IRQNumber -= 32;
		NVIC_ISER_1 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 95U)
	{
		Copy_u8IRQNumber -= 64;
		NVIC_ISER_1 = (1U << Copy_u8IRQNumber);
	}
	else
	{
		/* ERROR */
	}
}

void NVIC_vDisableINT(u8 Copy_u8IRQNumber)
{
	if(Copy_u8IRQNumber <= 31U)
	{
		NVIC_ICER_0 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 63U)
	{
		Copy_u8IRQNumber -= 32;
		NVIC_ICER_1 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 95U)
	{
		Copy_u8IRQNumber -= 64;
		NVIC_ICER_2 = (1U << Copy_u8IRQNumber);
	}
	else
	{
		/* ERROR */
	}
}

void NVIC_vSetPendigFlag(u8 Copy_u8IRQNumber)
{
		if(Copy_u8IRQNumber <= 31U)
	{
		NVIC_ISPR_0 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 63U)
	{
		Copy_u8IRQNumber -= 32;
		NVIC_ISPR_1 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 95U)
	{
		Copy_u8IRQNumber -= 64;
		NVIC_ISPR_2 = (1U << Copy_u8IRQNumber);
	}
	else
	{
		/* ERROR */
	}
}

void NVIC_vClearPendigFlag(u8 Copy_u8IRQNumber)
{
		if(Copy_u8IRQNumber <= 31U)
	{
		NVIC_ICPR_0 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 63U)
	{
		Copy_u8IRQNumber -= 32;
		NVIC_ICPR_1 = (1U << Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 95U)
	{
		Copy_u8IRQNumber -= 64;
		NVIC_ICPR_2 = (1U << Copy_u8IRQNumber);
	}
	else
	{
		/* ERROR */
	}
}

u8 NVIC_vGetActiveFlag(u8 Copy_u8IRQNumber)
{
	u8 L_u8ActiveState = 0;
	if(Copy_u8IRQNumber <= 31U)
	{
		GET_BIT(NVIC_IABR_0, Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber <= 63U)
	{
		Copy_u8IRQNumber -= 32;
		GET_BIT(NVIC_IABR_1, Copy_u8IRQNumber);

	}
	else if(Copy_u8IRQNumber <= 95U)
	{
		Copy_u8IRQNumber -= 64;
		GET_BIT(NVIC_IABR_2, Copy_u8IRQNumber);
	}
	else
	{
		/* ERROR */
	}
	return L_u8ActiveState;
}

void NVIC_vConfigGroupSub(u8 Copy_u8Config)
{
	switch(Copy_u8Config)
	{
		case GROUP_4_SUB_0: SCB_AIRCR = 0x5FA0300	break;
		case GROUP_3_SUB_1:	SCB_AIRCR = 0x5FA0400	break;
		case GROUP_2_SUB_2:	SCB_AIRCR = 0x5FA0500	break;
		case GROUP_1_SUB_3:	SCB_AIRCR = 0x5FA0600	break;
		case GROUP_0_SUB_4:	SCB_AIRCR = 0x5FA0700	break;
	}
}

void NVIC_vSetGroupSubGroupPriority(u8 Copy_u8IRQNum, u8 Copy_GroupPriority, u8 Copy_SubGroup, u8 GroupPriorityCFG)
{
	switch(GroupPriorityCFG)
	{
		case GROUP_4_SUB_0:
		SCB_AIRCR = 0x5FA0300;
		NVIC_IPR[Copy_u8IRQNum] = (u8)(Copy_GroupPriority << 4U);
		break;
		/**********************************************************************************************************/
		case GROUP_3_SUB_1:
		SCB_AIRCR = 0x5FA0400;
		NVIC_IPR[Copy_u8IRQNum] = (u8)(Copy_GroupPriority << 5U) | (u8)(Copy_SubGroup << 4U);
		break;
		/**********************************************************************************************************/
		case GROUP_2_SUB_2:
		SCB_AIRCR = 0x5FA0500;
		NVIC_IPR[Copy_u8IRQNum] = (u8)(Copy_GroupPriority << 6U) | (u8)(Copy_SubGroup << 4U);
		break;
		/**********************************************************************************************************/	
		case GROUP_1_SUB_3:
		SCB_AIRCR = 0x5FA0600;
		NVIC_IPR[Copy_u8IRQNum] = (u8)(Copy_GroupPriority << 7U) | (u8)(Copy_SubGroup << 4U);
		break;
		/**********************************************************************************************************/
		case GROUP_0_SUB_4:
		SCB_AIRCR = 0x5FA0700;
		NVIC_IPR[Copy_u8IRQNum] = (u8)(Copy_SubGroup << 4U);
		break;
	}
}