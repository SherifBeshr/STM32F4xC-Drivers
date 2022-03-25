#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "std_types.h"
#include "LCD_config.h"

#define LCD_DATA_PINS_NUMBER			0x08

/* LCD Commands */
#define LCD_CLEAR_COMMAND              	0x01
#define LCD_GO_TO_HOME                 	0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  	0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   	0x28
#define LCD_CURSOR_OFF                 	0x0C
#define LCD_CURSOR_ON                  	0x0E
#define LCD_SET_CURSOR_LOCATION        	0x80

/***************************************************************************************************
 *                                		Function Prototypes                                  	   *
 ***************************************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);


/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* LCD_INTERFACE_H_ */
