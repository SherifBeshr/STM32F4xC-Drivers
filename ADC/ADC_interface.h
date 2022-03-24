/*==================================================================================================================
===============================   - ADC_interface.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "std_types.h"
#include "ADC_config.h"
#include "ADC_private.h"



/*===========================     Function Prototypes     ===========================*/
/*===============   1-Function To Initialize ADC			===============*/
void ADC_vInit(void);	
	
/*===============   2-Function To Read ADC	 				===============*/
u16 ADC_vReadChannel(u8 copy_u8ACD_ChannelNumber);	

/*===============   7-Function To get the IRQ Number		===============*/
void ADC_vIRQHandler(void);

/*===============   8-Function To call the Callback function ===============*/
void ADC_vIDSetCallBack( void (*ptr) (void) );

#endif /* ADC_INTERFACE_H_ */
