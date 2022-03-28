/*==================================================================================================================
===============================   - UART_prog.c					 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#include "std_types.h"
#include "common_macros.h"

#include "UART_interface.h"

/*===============   1-Function To Initialize UART			===============*/
void UART_vInit(void)
{
/*------------------	    	UART 1 configurations		------------------*/
	#if (UART1_USED == U_ENABLE)
	UART1->CR1_Bits.SBK = UART1_SEND_BREAK;
	UART1->CR1_Bits.RE = UART1_RECEIVER;
	UART1->CR1_Bits.TE = UART1_TRANSMITTER;
	UART1->CR1_Bits.RXNEIE = UART1_RX_INT;
	UART1->CR1_Bits.TCIE = UART1_T_COMP_INT;
	UART1->CR1_Bits.PCE = UART1_PARITY_ENABLE;
	UART1->CR1_Bits.PS = UART1_PARITY_MODE;
	UART1->CR1_Bits.M = UART1_WORD_LEN;
	UART1->CR1_Bits.OVER8 = UART1_OVER_SAMPLING;
	UART1->BRR = UART1_BUAD_RATE;
	UART1->CR2 |=  (UART1_STOP_BITS << USART_CR2_STOP_0);
	#endif

/*------------------	    	UART 2 configurations		------------------*/
	#if (UART2_USED == U_ENABLE)
	UART2->CR1_Bits.SBK = UART2_SEND_BREAK;
	UART2->CR1_Bits.RE = UART2_RECEIVER;
	UART2->CR1_Bits.TE = UART2_TRANSMITTER;
	UART2->CR1_Bits.RXNEIE = UART2_RX_INT;
	UART2->CR1_Bits.TCIE = UART2_T_COMP_INT;
	UART2->CR1_Bits.PCE = UART2_PARITY_ENABLE;
	UART2->CR1_Bits.PS = UART2_PARITY_MODE;
	UART2->CR1_Bits.M = UART2_WORD_LEN;
	UART2->CR1_Bits.OVER8 = UART2_OVER_SAMPLING;
	UART2->BRR = UART2_BUAD_RATE;
	UART2->CR2 |=  (UART6_STOP_BITS << USART_CR2_STOP_0);
	#endif
/*------------------	    	UART 6 configurations		------------------*/
	#if (UART6_USED == U_ENABLE)
	UART6->CR1_Bits.SBK = UART6_SEND_BREAK;
	UART6->CR1_Bits.RE = UART6_RECEIVER;
	UART6->CR1_Bits.TE = UART6_TRANSMITTER;
	UART6->CR1_Bits.RXNEIE = UART6_RX_INT;
	UART6->CR1_Bits.TCIE = UART6_T_COMP_INT;
	UART6->CR1_Bits.PCE = UART6_PARITY_ENABLE;
	UART6->CR1_Bits.PS = UART6_PARITY_MODE;
	UART6->CR1_Bits.M = UART6_WORD_LEN;
	UART6->CR1_Bits.OVER8 = UART6_OVER_SAMPLING;
	UART6->BRR = UART6_BUAD_RATE;
	UART6->CR2 |=  (UART6_STOP_BITS << USART_CR2_STOP_0);
	#endif
}	

/*===============   2-Function To Enable UARTx	 			===============*/
void UART_vEnable(u8 copy_u8UART_ID)
{
	UART_REG uhandler = UART_GetHandler(copy_u8UART_ID);	/* Gets Pointer to struct of UARTx */
	uhandler->CR1_Bits.UE = 1U;
}	
	
/*===============   3-Function To Disable UARTx				===============*/
void UART_vDisable(u8 copy_u8UART_ID)
{
	UART_REG uhandler = UART_GetHandler(copy_u8UART_ID);	/* Gets Pointer to struct of UARTx */
	uhandler->CR1_Bits.UE = 0U;
}
/*===============   4-Function To Send Data					===============*/
void UART_vSendByte(u8 copy_u8UART_ID, u8 copy_u8Data)
{
	UART_REG uhandler = UART_GetHandler(copy_u8UART_ID);
	uhandler->DR = copy_u8Data;
	while(BIT_IS_CLEAR(uhandler->SR, USART_SR_TC));
}

/*===============   Function To Send String					===============*/
void UART_vSendString(u8 copy_u8UART_ID, u8 *copy_u8Str)
{
	u8 i = 0;
	UART_REG uhandler = UART_GetHandler(copy_u8UART_ID);
	while(copy_u8Str[i] != '\0')
	{
		uhandler->DR = copy_u8Str[i];
		while(BIT_IS_CLEAR(uhandler->SR, USART_SR_TC));
		//UART_vSendByte(copy_u8UART_ID,copy_u8Str[i]);
		i++;
	}
}

/*===============   5-Function To Read Data					===============*/
u8 UART_u8ReadByte(u8 copy_u8UART_ID)
{
	UART_REG uhandler = UART_GetHandler(copy_u8UART_ID);
	while (!(uhandler->SR & (1<<5)));
	//while(BIT_IS_CLEAR(uhandler->SR, USART_SR_RXNE));
	return (u8)uhandler->DR;
}

/*===============   6-Function To get the UARTx Address		===============*/
UART_REG UART_GetHandler(u8 copy_u8UART_ID)
{
	UART_REG L_handle= (UART_REG) UART1_BASE_ADDRESS;
	switch(copy_u8UART_ID)
	{
		case UART_ID_1 : L_handle = (UART_REG)UART1_BASE_ADDRESS; 	break;
		case UART_ID_2 : L_handle = (UART_REG)UART2_BASE_ADDRESS; 	break;
		case UART_ID_6 : L_handle = (UART_REG)UART6_BASE_ADDRESS; 	break;
		default: /* ERROR */										break; 
	}
	return L_handle;
}

/*===============   7-Function To get the IRQ Number		===============*/
void USART1_IRQHandler(void);

/*===============   8-Function To call the Callback function ===============*/
void USART1_vIDSetCallBack( void (*ptr) (void) );
