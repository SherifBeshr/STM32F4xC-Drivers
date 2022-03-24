/*==================================================================================================================
===============================   - ADC_prog.c					 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "std_types.h"
#include "common_macros.h"

#include "ADC_interface.h"



/*===========================     Function Prototypes     ===========================*/
/*===============   1-Function To Initialize ADC			===============*/
void ADC_vInit(void)
{
	ADC1->CR2 |= (1<<ADC_CR2_ADON_Pos);			// Enable ADC
	ADC1->CR2 |= (1<<ADC_CR2_CONT_Pos);
	//ADC1->CR1 |= (1<<ADC_CR1_DISCEN_Pos);		/* Discontinous Mode */
	ADC1->SMPR2  |= (0x3<<ADC_SMPR2_SMP0_Pos);
}

u16 ADC_vReadChannel(u8 copy_u8ACD_ChannelNumber)
{
	ADC1->CR2 |= (1<<ADC_CR2_SWSTART_Pos);
	
	return (u16)(ADC1->DR);
}