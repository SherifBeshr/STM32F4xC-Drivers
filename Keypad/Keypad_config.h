/*==================================================================================================================
===============================   - Keypad_config.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_


/*============================================	 Definitions 	====================================================*/


/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                  4					/* Editable for keypad column number */
#define KEYPAD_NUM_ROWS                  4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID                   GPIOC_PORT

#define KEYPAD_FIRST_ROW_PIN_ID        	 GPIO_PIN_0
#define KEYPAD_FIRST_COLUMN_PIN_ID       GPIO_PIN_4

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            GPIO_STATE_LOW
#define KEYPAD_BUTTON_RELEASED           GPIO_STATE_HIGH

#endif /* SEVEN_SEGMENT_CONFIG_H_ */
