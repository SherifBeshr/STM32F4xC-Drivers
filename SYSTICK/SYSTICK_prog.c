/*==================================================================================================================
===============================   - SYSTICK_prog.c				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "std_types.h"
#include "common_macros.h"
#include "SYSTICK_interface.h"

/* Global variable to take function address */
void (*SYSTICK_CallBack)(void);
/* Global variable to take SYSTICK_SINGLE or  SYSTICK_PERIODIC */
static volatile u8 G_u8SetMode;

void SysTick_Handler(void);

void SYSTICK_vInit(void)
{
	#if SYSTICK_CLK_SRC == SYSTICK_CLK_AHB
	SET_BIT(SYSTICK->CTRL , SYSTICK_CTRL_CLKSOURCE);
	#elif SYSTICK_CLK_SRC == SYSTICK_CLK_AHB_8
	SYSTICK->CTRL = 0;
	#endif
}

void SYSTICK_vSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load value in Load Register */
	SYSTICK->LOAD = Copy_u32Ticks;
	/* Start Timer */
	SYSTICK->CTRL = (1U << SYSTICK_CTRL_ENABLE);
	/* Wait for the count flag */
	while(GET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_COUNTFLAG) == 0U);
	/* Stop Timer */
	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);
	SYSTICK->LOAD = 0U;
	SYSTICK->VAL = 0U;
}

u32 SYSTICK_u32GetRemainingTime(void)
{
	u32 L_u32RemainTime = 0U;
	L_u32RemainTime = SYSTICK->VAL;
	return L_u32RemainTime;
}

u32 SYSTICK_u32GetElapsedTime(void)
{
	u32 L_u32ElapsedTime = 0U;
	L_u32ElapsedTime = ((SYSTICK->LOAD) - (SYSTICK->VAL));
	return L_u32ElapsedTime;
}

void SYSTICK_vSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	SYSTICK->LOAD = Copy_u32Ticks;
	SYSTICK_CallBack = Copy_ptr;
	G_u8SetMode = SYSTICK_PERIODIC;
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT);
	SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE);
}

void SYSTICK_vSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	SYSTICK->LOAD = Copy_u32Ticks;
	SYSTICK_CallBack = Copy_ptr;
	G_u8SetMode = SYSTICK_SINGLE;
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT);
	SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE);
}

void SysTick_Handler(void)
{
	u8 L_u8Temp;
	if(G_u8SetMode == SYSTICK_SINGLE)
	{
		CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);
		SYSTICK->VAL = 0U;
		SYSTICK->LOAD = 0U;
		
		CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT);
	}
	(*SYSTICK_CallBack)();
	
	L_u8Temp = GET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_COUNTFLAG);
}
