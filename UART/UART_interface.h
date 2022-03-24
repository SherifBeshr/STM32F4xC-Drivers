/*==================================================================================================================
===============================   - UART_interface.h			 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "std_types.h"
#include "UART_config.h"
#include "UART_private.h"

/*********************************/
#define UART_ID_1             1U     
#define UART_ID_2             2U
#define UART_ID_6             6U
/*********************************/
#define U_ENABLE              1U     
#define U_DISABLE             0U     
/*********************************/
#define U_EVEN_PARITY         0U     
#define U_ODD_PARITY          1U     
/*********************************/
#define U_DATA_8              0U     
#define U_DATA_9              1U     
/*********************************/
#define U_OVER_SAMPLING_16    0U     
#define U_OVER_SAMPLING_8     1U     
/*********************************/
#define STOP_1         		  1U     
#define STOP_05        		  2U     
#define STOP_2         		  3U     
#define STOP_1_05      		  4U     
/*********************************/
typedef enum{
    B_1200   = 0x44505400,          
    B_2400   = 0x43d05800,          
    B_9600   = 0x0683,              
    B_19200  = 0x42504000,          
    B_38400  = 0x41d08000,          
    B_57600  = 0x418b0000,          
    B_115200 = 0x410b0000           
}u_BaudRate_t;
/*********************************/

/*===========================     Function Prototypes     ===========================*/
/*===============   1-Function To Initialize UART			===============*/
void UART_vInit(void);	
	
/*===============   2-Function To Enable UARTx	 			===============*/
void UART_vEnable(u8 copy_u8UART_ID);	
	
/*===============   3-Function To Disable UARTx				===============*/
void UART_vDisable(u8 copy_u8UART_ID);
/*===============   4-Function To Send Data					===============*/
void UART_vSendByte(u8 copy_u8UART_ID, u8 copy_u8Data);

/*===============   5-Function To Read Data					===============*/
u8 UART_u8ReadByte(u8 copy_u8UART_ID);

/*===============   6-Function To get the UARTx Address		===============*/
UART_REG UART_GetHandler(u8 copy_u8UART_ID);

/*===============   7-Function To get the IRQ Number		===============*/
void USART1_IRQHandler(void);

/*===============   8-Function To call the Callback function ===============*/
void USART1_vIDSetCallBack( void (*ptr) (void) );

#endif /* UART_INTERFACE_H_ */
