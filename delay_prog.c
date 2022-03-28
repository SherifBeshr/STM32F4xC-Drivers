/*========================================================================================
===========================   - Delay_program.c		     	=============================
===========================   - Created: 2022	 	    	=============================
===========================   - Author: Sherif Beshr	    =============================
===========================   - Version : _1_		     	=============================
========================================================================================*/

#include "std_types.h"
#include "common_macros.h"
#include "delay_interface.h"

/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Milliseconds ( 16MHz CPU CLK )
*/

 void Delay_vMsIn16MHz(u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3180  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}



/*======================================================== END_ FUNCTION   ========================================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Microseconds ( 16MHz CPU CLK )
*/

 void Delay_vUsIn16MHzint (u16 copy_u16CountNum)
{
	volatile u16 u16Local_Count1 ;
	volatile u16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}



/*======================================================== END_ FUNCTION   ========================================================*/
