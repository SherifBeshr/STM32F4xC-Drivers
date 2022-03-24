/*==================================================================================================================
===============================   - SYSTICK_private.h			 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#include "std_types.h"

/*====================================================================================================================
	-----> Macros
			*  Base_Address is					0xE000E010
=====================================================================================================================*/

#define SYSTICK_BASE_ADDRESS					0xE000E010

/* Structure type to access the System Timer (SysTick) */
typedef struct{

	volatile u32 CTRL			;		/* Offset: 0x000 (R/W)  SysTick Control and Status Register */
	volatile u32 LOAD			;   	/* Offset: 0x004 (R/W)  SysTick Reload Value Register		*/
	volatile u32 VAL			;   	/* Offset: 0x008 (R/W)  SysTick Current Value Register 		*/
	volatile u32 CALIB			;   	/* Offset: 0x00C (R/ )  SysTick Calibration Register 		*/
}SYSTICK_Typedef_t;

#define SYSTICK							((SYSTICK_Typedef_t *)SYSTICK_BASE_ADDRESS)


/********************************************************************************************************************/
/*																													*/
/*												SYSTICK Registers													*/
/*																													*/
/********************************************************************************************************************/

/********************************************************************************************************************/
/*										Bit definition for SYSTICK_CTRL_Registers									*/
/********************************************************************************************************************/
#define SYSTICK_CTRL_ENABLE			0U
#define SYSTICK_CTRL_TICKINT		1U
#define SYSTICK_CTRL_CLKSOURCE		2U
#define SYSTICK_CTRL_COUNTFLAG		16U





#endif /* SYSTICK_PRIVATE_H_ */
