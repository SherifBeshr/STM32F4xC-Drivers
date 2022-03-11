/*==================================================================================================================
===============================   - RCC_private.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#include "std_types.h"


/*====================================================================================================================
	-----> Macros
			*  Base_Address is				0x40023800
=====================================================================================================================*/

#define RCC_BASE_ADDRESS		0x40023800


/*====================================================================================================================
	-----> RCC_Typedef
			*  Register Map
=====================================================================================================================*/
typedef struct
{
	volatile u32 CR				;		/* RCC clock control register,                          Address offset: 0x00 */
	volatile u32 PLLCFGR		;   	/* RCC PLL configuration register,                      Address offset: 0x04 */
	volatile u32 CFGR			;   	/* RCC clock configuration register,                    Address offset: 0x08 */
	volatile u32 CIR			;   	/* RCC clock interrupt register,                        Address offset: 0x0C */
	volatile u32 AHB1RSTR		;   	/* RCC AHB1 peripheral reset register,                  Address offset: 0x10 */
	volatile u32 AHB2RSTR		;   	/* RCC AHB2 peripheral reset register,                  Address offset: 0x14 */
	volatile u32 Reserved0[2]	;		/* Reserved, 0x18 - 0x1C                                                     */
	volatile u32 APB1RSTR		;   	/* RCC APB1 peripheral reset register,                  Address offset: 0x20 */
	volatile u32 APB2RSTR		;   	/* RCC APB2 peripheral reset register,                  Address offset: 0x24 */
	volatile u32 Reserved1[2]	;   	/* Reserved, 0x28-0x2C                                                       */
	volatile u32 AHB1ENR		;   	/* RCC AHB1 peripheral clock register,                  Address offset: 0x30 */
	volatile u32 AHB2ENR		;   	/* RCC AHB2 peripheral clock register,                  Address offset: 0x34 */
	volatile u32 Reserved2[2]	;   	/* Reserved, 0x38-0x3C                                                       */
	volatile u32 APB1ENR		;   	/* RCC APB1 peripheral clock enable register,           Address offset: 0x40 */
	volatile u32 APB2ENR		;   	/* RCC APB2 peripheral clock enable register,           Address offset: 0x44 */
	volatile u32 Reserved3[2]	;   	/* Reserved, 0x48-0x4C                                                       */
	volatile u32 AHB1LPENR		;   	/* RCC AHB1 peripheral clock enable in LP mode register,Address offset: 0x50 */
	volatile u32 AHB2LPENR		;   	/* RCC AHB2 peripheral clock enable in LP mode register,Address offset: 0x54 */
	volatile u32 Reserved4[2]	;   	/* Reserved, 0x58-0x5C                 			                             */
	volatile u32 APB1LPENR		;   	/* RCC APB1 peripheral clock enable in LP mode register,Address offset: 0x60 */
	volatile u32 APB2LPENR		;   	/* RCC APB2 peripheral clock enable in LP mode register,Address offset: 0x64 */
	volatile u32 Reserved5[2]	;   	/* Reserved, 0x68-0x6C                                                       */
	volatile u32 BDCR			;   	/* RCC Backup domain control register,                  Address offset: 0x70 */
	volatile u32 CSR			;   	/* RCC clock control & status register,                 Address offset: 0x74 */
	volatile u32 Reserved6[2]	;   	/* Reserved, 0x78-0x7C                                                       */
	volatile u32 SSCGR			;   	/* RCC spread spectrum clock generation register,       Address offset: 0x80 */
	volatile u32 PLLI2CFGR		;   	/* RCC PLLI2S configuration register,                   Address offset: 0x84 */
	volatile u32 Reserved7[1]	;   	/* Reserved, 0x88                                                            */
	volatile u32 DCKCFGR		;   	/* RCC Dedicated Clocks configuration register,         Address offset: 0x8C */
}RCC_TypeDef_t;

#define RCC									((RCC_TypeDef_t *)RCC_BASE_ADDRESS)

/********************************************************************************************************************/
/*																													*/
/*												RCC Registers														*/
/*																													*/
/********************************************************************************************************************/

/********************************************************************************************************************/
/*										Bit definition for RCC_CR_Registers											*/
/********************************************************************************************************************/
#define RCC_CR_HSION						0U
#define RCC_CR_HSIRDY						1U
#define RCC_CR_HSITRIM_0					3U
#define RCC_CR_HSITRIM_1					4U
#define RCC_CR_HSITRIM_2					5U
#define RCC_CR_HSITRIM_3					6U
#define RCC_CR_HSITRIM_4					7U
#define RCC_CR_HSEON						16U
#define RCC_CR_HSERDY						17U
#define RCC_CR_HSEBYP						18U
#define RCC_CR_CSSON   						19U
#define RCC_CR_PLLON						24U
#define RCC_CR_PLLRDY						25U
#define RCC_CR_PLLI2SON						26U
#define RCC_CR_PLLI2SRDY					27U

/********************************************************************************************************************/
/*									Bit definition for RCC_PLLCFGR_Registers										*/
/********************************************************************************************************************/
#define RCC_PLLCFGR_PLLM0					0U
#define RCC_PLLCFGR_PLLM1					1U
#define RCC_PLLCFGR_PLLM2					2U
#define RCC_PLLCFGR_PLLM3					3U
#define RCC_PLLCFGR_PLLM4					4U
#define RCC_PLLCFGR_PLLM5					5U
#define RCC_PLLCFGR_PLLN_0   				6U
#define RCC_PLLCFGR_PLLP0					16U
#define RCC_PLLCFGR_PLLP1					17U
#define RCC_PLLCFGR_PLLSRC					22U
#define RCC_PLLCFGR_PLLQ0					24U
#define RCC_PLLCFGR_PLLQ1					25U
#define RCC_PLLCFGR_PLLQ2					26U
#define RCC_PLLCFGR_PLLQ3					27U

/********************************************************************************************************************/
/*									Bit definition for RCC_CFGR_Registers											*/
/********************************************************************************************************************/
#define RCC_CFGR_SW0						0U
#define RCC_CFGR_SW1						1U
#define RCC_CFGR_SWS0						2U
#define RCC_CFGR_SWS1						3U
#define RCC_CFGR_HPRE_0						4U
#define RCC_CFGR_HPRE_1						5U
#define RCC_CFGR_HPRE_2						6U
#define RCC_CFGR_HPRE_3						7U
#define RCC_CFGR_PPRE1_0					10U
#define RCC_CFGR_PPRE1_1					11U
#define RCC_CFGR_PPRE1_2					12U
#define RCC_CFGR_PPRE2_0   					13U
#define RCC_CFGR_PPRE2_1   					14U
#define RCC_CFGR_PPRE2_2   					15U
#define RCC_CFGR_RTCPRE_0					16U
#define RCC_CFGR_RTCPRE_1					17U
#define RCC_CFGR_RTCPRE_2					18U
#define RCC_CFGR_RTCPRE_3					19U
#define RCC_CFGR_RTCPRE_4					20U
#define RCC_CFGR_MCO1_0						21U
#define RCC_CFGR_MCO1_1						22U
#define RCC_CFGR_I2SSCR						23U
#define RCC_CFGR_MCO1_PRE_0					24U
#define RCC_CFGR_MCO1_PRE_1					25U
#define RCC_CFGR_MCO1_PRE_2					26U
#define RCC_CFGR_MCO2_PRE_0					27U
#define RCC_CFGR_MCO2_PRE_1					28U
#define RCC_CFGR_MCO2_PRE_2					29U
#define RCC_CFGR_MCO2_0						30U
#define RCC_CFGR_MCO2_1						31U

/********************************************************************************************************************/
/*									Bit definition for RCC_CIR_Registers											*/
/********************************************************************************************************************/
#define RCC_CIR_LSIRDYF						0U
#define RCC_CIR_LSERDYF						1U
#define RCC_CIR_HSIRDYF						2U
#define RCC_CIR_HSERDYF						3U
#define RCC_CIR_PLLRDYF						4U
#define RCC_CIR_PLLI2SRDYF					5U
#define RCC_CIR_CSSF 						7U
#define RCC_CIR_LSIRDYIE					8U
#define RCC_CIR_LSERDYIE					9U
#define RCC_CIR_HSIRDYIE					10U
#define RCC_CIR_HSERDYIE					11U
#define RCC_CIR_PLLRDYIE					12U
#define RCC_CIR_PLLI2SRDYIE					13U
#define RCC_CIR_LSIRDYC						16U
#define RCC_CIR_LSERDYC                 	17U
#define RCC_CIR_HSIRDYC                 	18U
#define RCC_CIR_HSERDYC                 	19U
#define RCC_CIR_PLLRDYC                 	20U
#define RCC_CIR_PLLI2SRDYC              	21U
#define RCC_CIR_CSSC                    	23U


/********************************************************************************************************************/
/*									Bit definition for RCC_AHB1RSTR_Registers										*/
/********************************************************************************************************************/
#define RCC_AHB1RSTR_GPIOA_RST				0U
#define RCC_AHB1RSTR_GPIOB_RST				1U
#define RCC_AHB1RSTR_GPIOC_RST				2U
#define RCC_AHB1RSTR_GPIOD_RST				3U
#define RCC_AHB1RSTR_GPIOE_RST				4U
#define RCC_AHB1RSTR_GPIOH_RST				7U
#define RCC_AHB1RSTR_CRC_RST				12U
#define RCC_AHB1RSTR_DMA1_RST				21U
#define RCC_AHB1RSTR_DMA2_RST				22U

/********************************************************************************************************************/
/*									Bit definition for RCC_AHB2RSTR_Registers										*/
/********************************************************************************************************************/
#define RCC_AHB2RSTR_OTGFS_RST				7U


/********************************************************************************************************************/
/*									Bit definition for RCC_APB1RSTR_Registers										*/
/********************************************************************************************************************/
#define RCC_APB1RSTR_TIM2_RST				0U
#define RCC_APB1RSTR_TIM3_RST				1U
#define RCC_APB1RSTR_TIM4_RST				2U
#define RCC_APB1RSTR_TIM5_RST				3U
#define RCC_APB1RSTR_WWDG_RST				11U
#define RCC_APB1RSTR_SPI2_RST				14U
#define RCC_APB1RSTR_SPI3_RST				15U
#define RCC_APB1RSTR_USART2_RST				17U
#define RCC_APB1RSTR_I2C1_RST				21U
#define RCC_APB1RSTR_I2C2_RST				22U
#define RCC_APB1RSTR_I2C3_RST				23U
#define RCC_APB1RSTR_PWR_RST				28U


/********************************************************************************************************************/
/*									Bit definition for RCC_APB2RSTR_Registers										*/
/********************************************************************************************************************/
#define RCC_APB2RSTR_TIM1_RST				0U
#define RCC_APB2RSTR_USART1_RST				4U
#define RCC_APB2RSTR_USART6_RST				5U
#define RCC_APB2RSTR_ADC_RST				8U
#define RCC_APB2RSTR_SDIO_RST				11U
#define RCC_APB2RSTR_SPI1_RST				12U
#define RCC_APB2RSTR_SPI4_RST				13U
#define RCC_APB2RSTR_SYSCFG_RST				14U
#define RCC_APB2RSTR_TIM9_RST				16U
#define RCC_APB2RSTR_TIM10_RST				17U
#define RCC_APB2RSTR_TIM11_RST				18U

/********************************************************************************************************************/
/*									Bit definition for RCC_AHB1ENR_Registers										*/
/********************************************************************************************************************/
#define RCC_AHB1ENR_GPIOA_EN				0U
#define RCC_AHB1ENR_GPIOB_EN				1U
#define RCC_AHB1ENR_GPIOC_EN				2U
#define RCC_AHB1ENR_GPIOD_EN				3U
#define RCC_AHB1ENR_GPIOE_EN				4U
#define RCC_AHB1ENR_GPIOH_EN				7U
#define RCC_AHB1ENR_CRC_EN					12U
#define RCC_AHB1ENR_DMA1_EN					21U
#define RCC_AHB1ENR_DMA2_EN					22U

/********************************************************************************************************************/
/*									Bit definition for RCC_AHB2ENR_Registers										*/
/********************************************************************************************************************/
#define RCC_AHB2ENR_OTGFS_EN				7U


/********************************************************************************************************************/
/*									Bit definition for RCC_APB1ENR_Registers										*/
/********************************************************************************************************************/
#define RCC_APB1ENR_TIM2_EN					0U
#define RCC_APB1ENR_TIM3_EN					1U
#define RCC_APB1ENR_TIM4_EN					2U
#define RCC_APB1ENR_TIM5_EN					3U
#define RCC_APB1ENR_WWDG_EN					11U
#define RCC_APB1ENR_SPI2_EN					14U
#define RCC_APB1ENR_SPI3_EN					15U
#define RCC_APB1ENR_USART2_EN				17U
#define RCC_APB1ENR_I2C1_EN					21U
#define RCC_APB1ENR_I2C2_EN					22U
#define RCC_APB1ENR_I2C3_EN					23U
#define RCC_APB1ENR_PWR_EN					28U


/********************************************************************************************************************/
/*									Bit definition for RCC_APB2ENR_Registers										*/
/********************************************************************************************************************/
#define RCC_APB2ENR_TIM1_EN					0U
#define RCC_APB2ENR_USART1_EN				4U
#define RCC_APB2ENR_USART6_EN				5U
#define RCC_APB2ENR_ADC_EN					8U
#define RCC_APB2ENR_SDIO_EN					11U
#define RCC_APB2ENR_SPI1_EN					12U
#define RCC_APB2ENR_SPI4_EN					13U
#define RCC_APB2ENR_SYSCFG_EN				14U
#define RCC_APB2ENR_TIM9_EN					16U
#define RCC_APB2ENR_TIM10_EN				17U
#define RCC_APB2ENR_TIM11_EN				18U


#endif /* RCC_PRIVATE_H_ */
