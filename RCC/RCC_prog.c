/*==================================================================================================================
===============================   - RCC_prog.c					 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "RCC_private.h"
#include "RCC_interface.h"
#include "common_macros.h"

/* About The Function :

				- CLK		: HSE | HSI |PLL
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC
 */

void RCC_vInitSystemClk(void)
{
	/********** HSI **********/
#if CLKSRC == HSI
	/* 1- EN HSI */
	SET_BIT(RCC->CR, RCC_CR_HSION);
	/* 2- CLK SYS --> HSI */
	CLR_BIT(RCC->CFGR, RCC_CFGR_SW0);
	CLR_BIT(RCC->CFGR, RCC_CFGR_SW1);

	/********** HSE **********/
#elif CLKSRC == HSE
#if HSE_SRC == CRYSTAL
	/* 1- EN HSE */
	SET_BIT(RCC->CR , 16U);
	/* 2- Disable BYP */
	CLR_BIT(RCC->CR,18U);
	/* 3- CLK SYS --> HSE */
	SET_BIT(RCC->CFGR, 0U);
	CLR_BIT(RCC->CFGR, 1U);
#elif HSE_SRC == RC
	/* 1- EN HSE */
	SET_BIT(RCC->CR , 16U);
	/* 2- Enable BYP */
	SET_BIT(RCC->CR,18U);
	/* 3- CLK SYS --> HSE */
	SET_BIT(RCC->CFGR, 0U);
	CLR_BIT(RCC->CFGR, 1U);
#else
	/* Error */
#endif
#elif CLKSRC == PLL
#if PLL_SRC == _HSE_PLL
	/*1-Enable HSE */
	SET_BIT(RCC->CR,16U);
	/* while ( GET_BIT(RCC_CR, 17)==0);*/
	/*2- EN PLL*/
	SET_BIT(RCC->,24U);
	/* while ( GET_BIT(RCC_CR, 25)==0);*/
	/* 3- PLL From HSE */
	SET_BIT(RCC->PLLCFGR, 22U);
	/* 4- System Clk  PLL */
	CLR_BIT(RCC->CFGR,0U);
	SET_BIT(RCC->CFGR,1U);

#elif PLL_SRC == _HSI_PLL
	/*Enable HSI */
	SET_BIT(RCC->CR,0U);
	/*2- EN PLL*/
	SET_BIT(RCC->CR,24U);
	/* 3- PLL From HSI */
	CLR_BIT(RCC->PLLCFGR, 22U);
	/* 4- System Clk  PLL */
	CLR_BIT(RCC->CFGR,0U);
	SET_BIT(RCC->CFGR,1U);
#else
	/* Error*/


#endif


#endif
}

/*
- Function To Enable Peripheral :
				- BusName_t      :  The Bus Of The Peripheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 )
									Every One Detect Which REG To Choice Peripheral From It
				- Copy_u8PerName :  The Order Of Peripheral On The Selected Register
 */
void RCC_vEnableClock(BusName_t BusName, u8 Copy_u8PerName)
{
	switch(BusName)
	{
	case(AHB1_BUS):		SET_BIT(RCC->AHB1ENR, Copy_u8PerName);		break;
	case(AHB2_BUS):		SET_BIT(RCC->AHB2ENR, Copy_u8PerName);		break;
	case(APB1_BUS):		SET_BIT(RCC->APB1ENR, Copy_u8PerName);		break;
	case(APB2_BUS):		SET_BIT(RCC->APB2ENR, Copy_u8PerName);		break;
	default: 			/* ERROR */									break;
	}
}

/*
- Function To Disable Peripheral :
				- BusName_tPeripheral:  The Bus Of The Peripheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 )
										Every One Detect Which REG To Choice Peripheral From It
				- Copy_u8PerName :  The Order Of Peripheral On The Selected Register
 */
void RCC_vDisableClock(BusName_t BusName, u8 Copy_u8PerName)
{
	switch(BusName)
	{
	case(AHB1_BUS):		CLR_BIT(RCC->AHB1ENR, Copy_u8PerName);		break;
	case(AHB2_BUS):		CLR_BIT(RCC->AHB2ENR, Copy_u8PerName);		break;
	case(APB1_BUS):		CLR_BIT(RCC->APB1ENR, Copy_u8PerName);		break;
	case(APB2_BUS):		CLR_BIT(RCC->APB2ENR, Copy_u8PerName);		break;
	default: 			/* ERROR */									break;
	}
}

/* Function To Reset Register To Default Values */
void RCC_vResetRegister(BusName_t BusName, u8 Copy_u8PerName)
{
	switch(BusName)
	{
	case(AHB1_BUS):		SET_BIT(RCC->AHB1ENR, Copy_u8PerName);		break;
	case(AHB2_BUS):		SET_BIT(RCC->AHB2ENR, Copy_u8PerName);		break;
	case(APB1_BUS):		SET_BIT(RCC->APB1ENR, Copy_u8PerName);		break;
	case(APB2_BUS):		SET_BIT(RCC->APB2ENR, Copy_u8PerName);		break;
	default: 			/* ERROR */									break;
	}
}

/*Function To Enable Security System*/
void RCC_vEnableSecuritySystem(void)
{
	SET_BIT(RCC->CR, RCC_CR_CSSON);
}

/*Function To Disable Security System */
void RCC_vDisableSecuritySystem(void)
{
	CLR_BIT(RCC->CR, RCC_CR_CSSON);
}

