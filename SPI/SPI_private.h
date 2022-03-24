/*==================================================================================================================
===============================   - SPI_private.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "std_types.h"

/*====================================================================================================================
	-----> Macros
			*  Base_Address is					0xE000E010
=====================================================================================================================*/

#define SPI1_BASE_ADDRESS						0x40013000
#define SPI2_BASE_ADDRESS						0x40003800
#define SPI3_BASE_ADDRESS						0x40003C00
#define SPI4_BASE_ADDRESS						0x40013400


/* Structure type to access the SPIx */
typedef struct{

	volatile u32 CR1 			;	/* SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	volatile u32 CR2			;   /* SPI control register 2 (not used in I2S mode),      Address offset: 0x04 */
	volatile u32 SR				;   /* SPI status register,                                Address offset: 0x08 */
	volatile u32 DR 			;   /* SPI data register,                                  Address offset: 0x0C */
	volatile u32 CRCPR			;   /* SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	volatile u32 RXCRCR			;   /* SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	volatile u32 TXCRCR 		;   /* SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	volatile u32 I2SCFGR		;   /* SPI_I2S configuration register,                     Address offset: 0x1C */
	volatile u32 I2SPR			;	/* SPI_I2S prescaler register,                         Address offset: 0x20 */
}SPI_Typedef_t;                     


#define SPI1									((SPI_Typedef_t *)SPI1_BASE_ADDRESS)
#define SPI2									((SPI_Typedef_t *)SPI2_BASE_ADDRESS)
#define SPI3									((SPI_Typedef_t *)SPI3_BASE_ADDRESS)
#define SPI4									((SPI_Typedef_t *)SPI4_BASE_ADDRESS)

/********************************************************************************************************************/
/*																													*/
/*													SPI Registers													*/
/*																													*/
/********************************************************************************************************************/

/********************************************************************************************************************/
/*										Bit definition for SPI_CR1_Registers										*/
/********************************************************************************************************************/
#define SPI_CR1_CPHA					0U
#define SPI_CR1_CPOL					1U
#define SPI_CR1_MSTR					2U
#define SPI_CR1_BR_0					3U
#define SPI_CR1_BR_1					4U
#define SPI_CR1_BR_2					5U
#define SPI_CR1_SPE						6U
#define SPI_CR1_LSBFIRST				7U
#define SPI_CR1_SSI						8U
#define SPI_CR1_SSM						9U
#define SPI_CR1_RXONLY					10U
#define SPI_CR1_DFF						11U
#define SPI_CR1_CRCNEXT					12U
#define SPI_CR1_CRCEN					13U
#define SPI_CR1_BIDIOE					14U
#define SPI_CR1_BIDIMODE				15U

/********************************************************************************************************************/
/*										Bit definition for SPI_CR2_Registers										*/
/********************************************************************************************************************/
#define SPI_CR2_RXDMAEN					0U
#define SPI_CR2_TXDMAEN					1U
#define SPI_CR2_SSOE					2U
#define SPI_CR2_FRF						4U
#define SPI_CR2_ERRIE					5U
#define SPI_CR2_RXNEIE					6U
#define SPI_CR2_TXEIE					7U

/********************************************************************************************************************/
/*										Bit definition for SPI_SR_Registers											*/
/********************************************************************************************************************/
#define SPI_SR_RXNE						0U
#define SPI_SR_TXE						1U
#define SPI_SR_CHSIDE					2U
#define SPI_SR_UDR						3U
#define SPI_SR_CRCERR					4U
#define SPI_SR_MODF						5U
#define SPI_SR_OVR						6U
#define SPI_SR_BSY						7U
#define SPI_SR_FRE						8U

/********************************************************************************************************************/
/*										Bit definition for SPI_DR_Registers											*/
/********************************************************************************************************************/
#define SPI_DR							0U

/********************************************************************************************************************/
/*										Bit definition for SPI_CRCPR_Registers										*/
/********************************************************************************************************************/
#define SPI_CRCPR						0U

/********************************************************************************************************************/
/*										Bit definition for SPI_TXCRCR_Registers										*/
/********************************************************************************************************************/
#define SPI_TXCRCR						0U

/********************************************************************************************************************/
/*										Bit definition for SPI_I2SCFGR_Registers									*/
/********************************************************************************************************************/
#define SPI_I2SCFGR_CHLEN				0U
#define SPI_I2SCFGR_DATLEN_0			1U
#define SPI_I2SCFGR_DATLEN_1			2U
#define SPI_I2SCFGR_CKPOL				3U
#define SPI_I2SCFGR_I2SSTD_0			4U
#define SPI_I2SCFGR_I2SSTD_1			5U
#define SPI_I2SCFGR_PCMSYNC				7U
#define SPI_I2SCFGR_I2SCFG_0			8U
#define SPI_I2SCFGR_I2SCFG_1			9U
#define SPI_I2SCFGR_I2SE				10U
#define SPI_I2SCFGR_I2SMOD				11U

/********************************************************************************************************************/
/*										Bit definition for SPI_I2SPR_Registers										*/
/********************************************************************************************************************/
#define SPI_I2SPR_I2SDIV				0U
#define SPI_I2SPR_ODD					8U
#define SPI_I2SPR_MCKOE					9U





#endif /* SPI_PRIVATE_H_ */
