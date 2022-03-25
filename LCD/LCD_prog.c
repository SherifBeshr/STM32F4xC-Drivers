/*==================================================================================================================
===============================   - LCD_prog.c				 	 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "std_types.h"
#include "common_macros.h"
#include "LCD_interface.h"
#include "GPIO_interface.h"
#include "delay_interface.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SET_IF(expr)  ((expr) ? GPIO_STATE_HIGH : GPIO_STATE_LOW)

/***************************************************************************************************
 *                                		Definitions                                  			   *
 ***************************************************************************************************/
/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{
	/* Configure the direction for RS, RW and E pins as output pins */
	GPIO_vSetPinMode(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_MODE_OUTPUT);
	GPIO_vSetPinMode(LCD_RW_PORT_ID, LCD_RW_PIN_ID, GPIO_MODE_OUTPUT);
	GPIO_vSetPinMode(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_MODE_OUTPUT);

	/* Configure the data pins as output*/
	u8 i=0;
	for(i=0 ; i<LCD_DATA_PINS_NUMBER ; i++)
	{
		GPIO_vSetPinMode(LCD_DATA_PORT_ID, LCD_FIRST_DATA_PIN+i, GPIO_MODE_OUTPUT);
	}

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);		/* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

	LCD_sendCommand(LCD_CURSOR_OFF);					/* cursor off */

	LCD_sendCommand(LCD_CLEAR_COMMAND);					/* clear LCD at the beginning */
}

static void LCD_Send8Bits(u8 val)
{
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+0, SET_IF(val&0x01));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+1, SET_IF(val&0x02));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+2, SET_IF(val&0x04));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+3, SET_IF(val&0x08));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+4, SET_IF(val&0x10));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+5, SET_IF(val&0x20));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+6, SET_IF(val&0x40));
	GPIO_vWriteData(LCD_DATA_PORT_ID,LCD_FIRST_DATA_PIN+7, SET_IF(val&0x80));
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command)
{
	GPIO_vWriteData(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_LOW);	/* Instruction Mode RS=0 */
	GPIO_vWriteData(LCD_RW_PORT_ID, LCD_RW_PIN_ID, GPIO_LOW);	/* write data to LCD so RW=0 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Tas = 50ns */
	GPIO_vWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_HIGH);		/* Enable LCD E=1 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Tpw - Tdws = 190ns */
	LCD_Send8Bits(command);										/* out the required command to the data bus D0 --> D7 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Tdsw = 100ns */
	GPIO_vWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_LOW);		/* Disable LCD E=0 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Th = 13ns */
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data)
{
	GPIO_vWriteData(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_HIGH);	/* Instruction Mode RS=1 */
	GPIO_vWriteData(LCD_RW_PORT_ID, LCD_RW_PIN_ID, GPIO_LOW);	/* write data to LCD so RW=0 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Tas = 50ns */
	GPIO_vWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_HIGH);		/* Enable LCD E=1 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Tpw - Tdws = 190ns */
	LCD_Send8Bits(data);										/* out the required data to the data bus D0 --> D7 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Tdsw = 100ns */
	GPIO_vWriteData(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_LOW);		/* Disable LCD E=0 */
	
	Delay_vMsIn16MHz(1U);
	//_delay_ms(1);												/* delay for processing Th = 13ns */
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}
	/***************** Another Method ***********************
	 * 	uint8 i;
	while (Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		++i;
	}
	 *********************************************************/
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col)
{
	u8 lcd_memory_address = 0;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;			break;
	case 1:
		lcd_memory_address=col+0x40;	break;
	case 2:
		lcd_memory_address=col+0x10;	break;
	case 3:
		lcd_memory_address=col+0x50;	break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str)
{
	LCD_moveCursor(row,col); 		/* go to to the required LCD position */
	LCD_displayString(Str); 		/* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int num)
{
	   char buff[16]; /* String to hold the ascii result */
		sprintf(buff, "%d", num);
	   //itoa(num,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	   LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
