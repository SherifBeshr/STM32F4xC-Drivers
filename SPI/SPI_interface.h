/*==================================================================================================================
===============================   - SPI_interface.h				 ===================================================
===============================   - Created: 2022			     ===================================================
===============================   - Author: Sherif Beshr	     ===================================================
===============================   - Version : _1_				 ===================================================
===============================   - Note :
====================================================================================================================*/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_config.h"
#include "SPI_private.h"

#include "std_types.h"

/* SPI_NUM */
#define SPI_NUM_1				0U
#define SPI_NUM_2				1U
#define SPI_NUM_3				2U
#define SPI_NUM_4				3U
/* SPI_MODE_MASTER */
#define SPI_MODE_MASTER			0U
#define SPI_MODE_SLAVE			1U
/*	SPI_BI_DIRECTION Mode */
#define SPI_BI_DIR_EN			0U
#define SPI_BI_DIR_DIS			1U
/*	SPI PHASE  */
#define SPI_PHASE_READ_WRITE	0U
#define SPI_PHASE_WRITE_READ	1U
/*	SPI POLARITY  */
#define SPI_POL_IDLE_LOW		0U
#define SPI_POL_IDLE_HIGH		1U
/*	SPI Baud Rate */
#define SPI_Presc_2             0b000
#define SPI_Presc_4             0b001
#define SPI_Presc_8             0b010
#define SPI_Presc_16            0b011
#define SPI_Presc_32            0b100
#define SPI_Presc_64            0b101
#define SPI_Presc_128           0b110
#define SPI_Presc_256           0b111
/* SPI DATA FORMAT */
#define SPI_DATA_SIZE_8			0U
#define SPI_DATA_SIZE_16		1U
/* SPI FRAME FORMAT */
#define SPI_FORMAT_MSB			0U
#define SPI_FORMAT_LSB			1U
/* SPI Enable or Disable */
#define SPI_ENABLE				0U
#define SPI_DISBALE				1U



#endif /* SPI_INTERFACE_H_ */
