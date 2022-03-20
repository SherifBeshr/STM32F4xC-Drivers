/*==================================================================================================================
===============================   - NVIC_interface.h	 		 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "std_types.h"

#include "NVIC_config.h"
#include "NVIC_private.h"


void NVIC_vEnableINT(u8 Copy_u8IRQNumber);
void NVIC_vDisableINT(u8 Copy_u8IRQNumber);

void NVIC_vSetPendigFlag(u8 Copy_u8IRQNumber);
void NVIC_vClearPendigFlag(u8 Copy_u8IRQNumber);

u8 NVIC_vGetActiveFlag(u8 Copy_u8IRQNumber);

void NVIC_vConfigGroupSub(u8 Copy_u8Config);

void NVIC_vSetGroupSubGroupPriority(u8 Copy_u8IRQNum, u8 Copy_GroupPriority, u8 Copy_SubGroup, u8 GroupPriorityCFG);

#define GROUP_4_SUB_0					0U
#define GROUP_3_SUB_1					1U
#define GROUP_2_SUB_2					2U
#define GROUP_1_SUB_3					3U
#define GROUP_0_SUB_4					4U


#endif /* NVIC_INTERFACE_H_ */
