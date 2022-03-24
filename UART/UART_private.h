/*==================================================================================================================
===============================   - UART_private.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "std_types.h"

/*====================================================================================================================
	-----> Macros
			*  Base_Address is					0xE000E010
=====================================================================================================================*/

#define UART1_BASE_ADDRESS						0x40011000
#define UART2_BASE_ADDRESS						0x40004400
#define UART6_BASE_ADDRESS						0x40011400



typedef struct{                              
    u32 SBK       :1;	/* Send break This bit set is used to send break characters.								*/
    u32 RWU       :1;	/* Receiver wakeup This bit determines if the USART is in mute mode or not. 				*/
    u32 RE        :1;	/* Receiver enable This bit enables the receiver. It is set and cleared by software   		*/
    u32 TE        :1;	/* Transmitter enable This bit enables the transmitter. It is set and cleared by software. 	*/
    u32 IDLEIE    :1;	/* IDLE interrupt enable This bit is set and cleared by software.  							*/
    u32 RXNEIE    :1;	/* RXNE interrupt enable This bit is set and cleared by software   							*/
    u32 TCIE      :1;	/* Transmission complete interrupt enable This bit is set and cleared by software.   		*/
    u32 TXEIE     :1;	/* TXE interrupt enable This bit is set and cleared by software.   							*/
    u32 PEIE      :1;	/* PE interrupt enable This bit is set and cleared by software  							*/
    u32 PS        :1;	/* Parity selection This bit selects the odd or even parity when the parity generation		*/
    u32 PCE       :1;	/* Parity control enable This bit selects the hardware parity control   					*/
    u32 WAKE      :1;	/* Wakeup method This bit determines the USART wakeup method.  								*/
    u32 M         :1;	/* Word length This bit determines the word length. It is set or cleared by software.   	*/
    u32 UE        :1;	/* USART enable */
    u32 RESERVED  :1;	  
    u32 OVER8     :1;	/* Oversampling mode    */
    u32 RESERVED2 :16;
}UART_CR1;


/* Structure type to access the UARTx */
typedef struct{
	volatile u32 SR;      	/* USART Status register,                   Address offset: 0x00 */
	volatile u32 DR;      	/* USART Data register,                     Address offset: 0x04 */
	volatile u32 BRR;      	/* USART Baud rate register,                Address offset: 0x08 */
	union{
		UART_CR1 CR1_Bits;	/* USART Control register 1 (BIT_FIELD) 	Address offset: 0x0C */
		volatile u32 CR1;	/* USART Control register 1 			 	Address offset: 0x0C */
	};
	volatile u32 CR2;   	/* USART Control register 2,                Address offset: 0x10 */
	volatile u32 CR3;   	/* USART Control register 3,                Address offset: 0x14 */
	volatile u32 GTPR;  	/* USART Guard time and prescaler register, Address offset: 0x18 */
}UART_Typedef_t;                     

typedef    volatile UART_Typedef_t* UART_REG ;
/*==============================================================================
*     --> Pointer To STRUCT From UARTx
================================================================================*/
#define UART1							((UART_Typedef_t *)UART1_BASE_ADDRESS)
#define UART2							((UART_Typedef_t *)UART2_BASE_ADDRESS)
#define UART6							((UART_Typedef_t *)UART6_BASE_ADDRESS)


/********************************************************************************************************************/
/*																													*/
/*													USART Registers													*/
/*																													*/
/********************************************************************************************************************/

/********************************************************************************************************************/
/*										Bit definition for USART_SR_Registers										*/
/********************************************************************************************************************/
#define USART_SR_PE						0U
#define USART_SR_FE 					1U
#define USART_SR_NF						2U
#define USART_SR_ORE					3U
#define USART_SR_IDLE					4U
#define USART_SR_RXNE					5U
#define USART_SR_TC						6U
#define USART_SR_TXE					7U
#define USART_SR_LBD					8U
#define USART_SR_CTS					9U


/********************************************************************************************************************/
/*										Bit definition for USART_DR_Registers										*/
/********************************************************************************************************************/
#define USART_DR						0U


/********************************************************************************************************************/
/*										Bit definition for USART_BRR_Registers										*/
/********************************************************************************************************************/
#define USART_BRR_DIV_FRACTION_0		0U
#define USART_BRR_DIV_MANTISSA_0		1U


/********************************************************************************************************************/
/*										Bit definition for USART_CR1_Registers										*/
/********************************************************************************************************************/
#define USART_CR1_SBK					0U
#define USART_CR1_RWU 					1U
#define USART_CR1_RE					2U
#define USART_CR1_TE					3U
#define USART_CR1_IDLEIE				4U
#define USART_CR1_RXNEIE				5U
#define USART_CR1_TCIE					6U
#define USART_CR1_TXEIE					7U
#define USART_CR1_PEIE					8U
#define USART_CR1_PS					9U
#define USART_CR1_PCE					10U
#define USART_CR1_WAKE					11U
#define USART_CR1_M						12U
#define USART_CR1_UE					13U

/********************************************************************************************************************/
/*										Bit definition for USART_CR2_Registers										*/
/********************************************************************************************************************/
#define USART_CR2_ADD_0					0U
#define USART_CR2_LBDL					5U
#define USART_CR2_LBDIE					6U
#define USART_CR2_LBCL					8U
#define USART_CR2_CPHA					9U
#define USART_CR2_CPOL					10U
#define USART_CR2_CLKEN					11U
#define USART_CR2_STOP_0				12U
#define USART_CR2_STOP_1				13U
#define USART_CR2_LINEN					14U

/********************************************************************************************************************/
/*										Bit definition forUSART_CR3_Registers										*/
/********************************************************************************************************************/
#define USART_CR3_EIE					0U
#define USART_CR3_IREN					1U
#define USART_CR3_IRLP					2U
#define USART_CR3_HDSEL					3U
#define USART_CR3_NACK					4U
#define USART_CR3_SCEN					5U
#define USART_CR3_DMAR					6U
#define USART_CR3_DMAT					7U
#define USART_CR3_RTSE					8U
#define USART_CR3_CTSE					9U
#define USART_CR3_CTSIE					10U
#define USART_CR3_ONEBIT				11U

/********************************************************************************************************************/
/*										Bit definition for USART_GTPR_Registers										*/
/********************************************************************************************************************/
#define USART_GTPR_PSC_0				0U
#define USART_GTPR_GT_0					8U


#endif /* UART_PRIVATE_H_ */
