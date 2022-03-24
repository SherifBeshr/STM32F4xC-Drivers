/*==================================================================================================================
===============================   - SYSTICK_interface.h			 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#include "SYSTICK_config.h"
#include "SYSTICK_private.h"

#define SYSTICK_CLK_AHB			0U
#define SYSTICK_CLK_AHB_8		1U

#define SYSTICK_SINGLE			0U
#define SYSTICK_PERIODIC		1U


void SYSTICK_vInit(void);

void SYSTICK_vSetBusyWait(u32 Copy_u32Ticks);

u32 SYSTICK_u32GetRemainingTime(void);
u32 SYSTICK_u32GetElapsedTime(void);

void SYSTICK_vSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
void SYSTICK_vSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));



#endif /* SYSTICK_INTERFACE_H_ */
