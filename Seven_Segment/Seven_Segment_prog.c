/*==================================================================================================================
===============================   - Seven_Segment_prog.c		 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "common_macros.h"
#include "GPIO_interface.h"
#include "Seven_Segment_interface.h"
/*
 * Description :
 * Setup the direction for pins used by the 7-segment as Output
 */
void SevenSegment_vInit(void)
{
	/* Seven Segment First Pin Configuration */
	GPIO_vSetPinMode(SEVEN_SEG_PORT_PIN_1,SEVEN_SEG_PIN_1,GPIO_MODE_OUTPUT);
	GPIO_vSetPinOutPutType(SEVEN_SEG_PORT_PIN_1,SEVEN_SEG_PIN_1,GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_vSetPinOutSpeed(SEVEN_SEG_PORT_PIN_1,SEVEN_SEG_PIN_1,GPIO_OUTPUT_SPEED_MEDUIM);
	
	/* Seven Segment Second Pin Configuration */
	GPIO_vSetPinMode(SEVEN_SEG_PORT_PIN_2,SEVEN_SEG_PIN_2,GPIO_MODE_OUTPUT);
	GPIO_vSetPinOutPutType(SEVEN_SEG_PORT_PIN_2,SEVEN_SEG_PIN_2,GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_vSetPinOutSpeed(SEVEN_SEG_PORT_PIN_2,SEVEN_SEG_PIN_2,GPIO_OUTPUT_SPEED_MEDUIM);
	
	/* Seven Segment Third Pin Configuration */
	GPIO_vSetPinMode(SEVEN_SEG_PORT_PIN_3,SEVEN_SEG_PIN_3,GPIO_MODE_OUTPUT);
	GPIO_vSetPinOutPutType(SEVEN_SEG_PORT_PIN_3,SEVEN_SEG_PIN_3,GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_vSetPinOutSpeed(SEVEN_SEG_PORT_PIN_3,SEVEN_SEG_PIN_3,GPIO_OUTPUT_SPEED_MEDUIM);
	
	/* Seven Segment Fourth Pin Configuration */
	GPIO_vSetPinMode(SEVEN_SEG_PORT_PIN_4,SEVEN_SEG_PIN_4,GPIO_MODE_OUTPUT);
	GPIO_vSetPinOutPutType(SEVEN_SEG_PORT_PIN_4,SEVEN_SEG_PIN_4,GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_vSetPinOutSpeed(SEVEN_SEG_PORT_PIN_4,SEVEN_SEG_PIN_4,GPIO_OUTPUT_SPEED_MEDUIM);
	
	
}

/*
 * Description :
 * Check the number binary and set the equivalent pin
 * Example: Num = 5 (0101) --> Pin1 = 1, Pin2 = 0, Pin3 = 1, Pin4 = 0
 */
void SevenSegment_vDisplay (u8 Num)
{
	BIT_IS_SET(Num,0) ? GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_1,SEVEN_SEG_PIN_1,GPIO_STATE_HIGH) :\
						GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_1,SEVEN_SEG_PIN_1,GPIO_STATE_LOW);
	
	BIT_IS_SET(Num,1) ? GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_2,SEVEN_SEG_PIN_2,GPIO_STATE_HIGH) :\
						GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_2,SEVEN_SEG_PIN_2,GPIO_STATE_LOW);
	
	BIT_IS_SET(Num,2) ? GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_3,SEVEN_SEG_PIN_3,GPIO_STATE_HIGH) :\
						GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_3,SEVEN_SEG_PIN_3,GPIO_STATE_LOW);
	
	BIT_IS_SET(Num,3) ? GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_4,SEVEN_SEG_PIN_4,GPIO_STATE_HIGH) :\
						GPIO_vDirectionSetReset(SEVEN_SEG_PORT_PIN_4,SEVEN_SEG_PIN_4,GPIO_STATE_LOW);
}
