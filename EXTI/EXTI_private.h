/*==================================================================================================================
===============================   - EXTI_private.h				 ===================================================
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
			*  Base_Address is				0x40013C00
=====================================================================================================================*/

#define EXTI_BASE_ADDRESS					0x40013C00

/*====================================================================================================================
	-----> RCC_Typedef
			*  Register Map
=====================================================================================================================*/
typedef struct
{
	volatile u32 IMR			;		/*!< EXTI Interrupt mask register,           			Address offset: 0x00 */
	volatile u32 EMR			;   	/*!< EXTI Event mask register,               			Address offset: 0x04 */
	volatile u32 RTSR			;   	/*!< EXTI Rising trigger selection register, 			Address offset: 0x08 */
	volatile u32 FTSR			;   	/*!< EXTI Falling trigger selection register,			Address offset: 0x0C */
	volatile u32 SWIER			;   	/*!< EXTI Software interrupt event register, 			Address offset: 0x10 */
	volatile u32 PR				;   	/*!< EXTI Pending register,                  			Address offset: 0x14 */
}EXTI_TypeDef_t;

#define EXTI								((EXTI_TypeDef_t *)EXTI_BASE_ADDRESS)

/********************************************************************************************************************/
/*																													*/
/*												EXTI Registers														*/
/*																													*/
/********************************************************************************************************************/

/********************************************************************************************************************/
/*								Bit definition for EXTI_IMR_Registers & EXTI_EMR_REGISTERS							*/
/********************************************************************************************************************/
#define EXTI_MR0					0U
#define EXTI_MR1					1U
#define EXTI_MR2					2U
#define EXTI_MR3					3U
#define EXTI_MR4					4U
#define EXTI_MR5					5U
#define EXTI_MR6					6U
#define EXTI_MR7					7U
#define EXTI_MR8					8U
#define EXTI_MR9					9U
#define EXTI_MR10					10U
#define EXTI_MR11					11U
#define EXTI_MR12					12U
#define EXTI_MR13					13U
#define EXTI_MR14					14U
#define EXTI_MR15					15U
#define EXTI_MR16					16U
#define EXTI_MR17					17U
#define EXTI_MR18					18U
#define EXTI_MR21					21U
#define EXTI_MR22					22U

/********************************************************************************************************************/
/*								Bit definition for EXTI_RTSR_Registers & EXTI_FTSR_REGISTERS						*/
/********************************************************************************************************************/
#define EXTI_TR0					0U
#define EXTI_TR1					1U
#define EXTI_TR2					2U
#define EXTI_TR3					3U
#define EXTI_TR4					4U
#define EXTI_TR5					5U
#define EXTI_TR6					6U
#define EXTI_TR7					7U
#define EXTI_TR8					8U
#define EXTI_TR9					9U
#define EXTI_TR10					10U
#define EXTI_TR11					11U
#define EXTI_TR12					12U
#define EXTI_TR13					13U
#define EXTI_TR14					14U
#define EXTI_TR15					15U
#define EXTI_TR16					16U
#define EXTI_TR17					17U
#define EXTI_TR18					18U
#define EXTI_TR21					21U
#define EXTI_TR22					22U

/********************************************************************************************************************/
/*										Bit definition for EXTI_SWIER_Registers										*/
/********************************************************************************************************************/
#define EXTI_SWIER0					0U
#define EXTI_SWIER1					1U
#define EXTI_SWIER2					2U
#define EXTI_SWIER3					3U
#define EXTI_SWIER4					4U
#define EXTI_SWIER5					5U
#define EXTI_SWIER6					6U
#define EXTI_SWIER7					7U
#define EXTI_SWIER8					8U
#define EXTI_SWIER9					9U
#define EXTI_SWIER10				10U
#define EXTI_SWIER11				11U
#define EXTI_SWIER12				12U
#define EXTI_SWIER13				13U
#define EXTI_SWIER14				14U
#define EXTI_SWIER15				15U
#define EXTI_SWIER16				16U
#define EXTI_SWIER17				17U
#define EXTI_SWIER18				18U
#define EXTI_SWIER21				21U
#define EXTI_SWIER22				22U

/********************************************************************************************************************/
/*										Bit definition for EXTI_PR_Registers										*/
/********************************************************************************************************************/
#define EXTI_PR0					0U
#define EXTI_PR1					1U
#define EXTI_PR2					2U
#define EXTI_PR3					3U
#define EXTI_PR4					4U
#define EXTI_PR5					5U
#define EXTI_PR6					6U
#define EXTI_PR7					7U
#define EXTI_PR8					8U
#define EXTI_PR9					9U
#define EXTI_PR10					10U
#define EXTI_PR11					11U
#define EXTI_PR12					12U
#define EXTI_PR13					13U
#define EXTI_PR14					14U
#define EXTI_PR15					15U
#define EXTI_PR16					16U
#define EXTI_PR17					17U
#define EXTI_PR18					18U
#define EXTI_PR21					21U
#define EXTI_PR22					22U




#endif /* RCC_PRIVATE_H_ */
