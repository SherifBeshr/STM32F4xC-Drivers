/*==================================================================================================================
===============================   - RCC_interface.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include <RCC_config.h>
#include "std_types.h"
#include "RCC_private.h"

/********** Bus Name  **********/
typedef enum{
	AHB1_BUS, AHB2_BUS, APB1_BUS, APB2_BUS
}BusName_t;

/**********  APH1_Prescaler   **********/
typedef enum
{
	AHB_Pre1  = 0x00,  AHB_Pre2   = 0x08U, AHB_Pre4   = 0x09U, AHB_Pre8   = 0x0AU, AHB_Pre16 = 0x0BU,\
	AHB_Pre64 = 0x0CU, AHB_Pre128 = 0x0DU, AHB_Pre256 = 0x0EU, AHB_Pre512 = 0x0FU
}AHBPreName_t;

/**********  APB1_Prescaler   **********/
typedef enum
{
	APB1_Pre1 = 0x00U, APB1_Pre2 = 0x04U, APB1_Pre4   = 0x05U, APB1_Pre8 = 0x06U, APB1_Pre16 = 0x07U
}APB1PreName_t;

/**********  APB2_Prescaler   **********/
typedef enum
{
	APB2_Pre1 = 0x00U, APB2_Pre2 = 0x04U, APB2_Pre4   = 0x05U, APB2_Pre8 = 0x06U, APB2_Pre16 = 0x07U
}APB2PreName_t;

/********** Clock Source **********/
#define  HSE   0U
#define  HSI   1U
#define  PLL   2U
/********** HSE Source   **********/
#define _HSE_CRYSTAL  0U
#define _HSE_RC       1U
/********** PLL Source   **********/
#define _HSE_PLL       0U
#define _HSI_PLL       1U

/*
-Function To Set System CLK From Enum Type Send :
	* ClkSrcName_t 		: RCC_HSE  RCC_HSI	RCC_PLL
	* HSESrcName_t 		: Crystal CLK From (HSE_Crystal , HSE_RC )
	* AHBPreName_t    : AHB  Prescaller ( 1 : 512 )
	* APB1PreName_t   : APB1 Prescaller ( 1 : 16  )
	* APB2PreName_t   : APB2_Prescaller ( 1 : 16  )
	*( M N P Q )      : By #define .
*/

void RCC_vInitSystemClk(void);

/*
- Function To Enable Prepheral :
				- BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
				- Copy_u8PerName :  The Order Of Prepheral On The Selected Reg
*/
void RCC_vEnableClock(BusName_t BusName, u8 Copy_u8PerName);

/*
- Function To Disable Prepheral :
				- BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
				- Copy_u8PerName :  The Order Of Prepheral On The Selected Reg
*/
void RCC_vDisableClock(BusName_t BusName, u8 Copy_u8PerName);

/* Function To Reset Register To Default Values */
void RCC_vResetRegister(BusName_t BusName, u8 Copy_u8PerName);

/*Function To Enable Security System*/
void RCC_vEnableSecuritySystem(void);

/*Function To Disable Security System */
void RCC_vDisableSecuritySystem(void);






#endif /* RCC_INTERFACE_H_ */
