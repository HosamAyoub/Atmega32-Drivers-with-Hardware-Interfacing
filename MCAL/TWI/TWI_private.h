/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TWI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

#define TWCR							(*((volatile u8*)0x56))			// TWI Control register
#define TWCR_TWIE						0								// TWI Interrupt enable bit
#define TWCR_TWEN						2								// TWI Enable bit
#define TWCR_TWWC						3								// TWI Write collision flag bit
#define TWCR_TWSTO						4								// TWI Stop condition bit
#define TWCR_TWSTA						5								// TWI Start condition bit
#define TWCR_TWEA						6								// TWI Enable acknowledge bit
#define TWCR_TWINT						7								// TWI Interrupt flag bit


#define TWDR							(*((volatile u8*)0x23))			// TWI Data register
#define TWDR_TWD0						0


#define TWAR							(*((volatile u8*)0x22))			// TWI (slave) Address register
#define TWAR_TWGCE						0								// TWI General call Recognition bit

#define TWSR							(*((volatile u8*)0x21))			// TWI Bit status register
#define TWSR_TWPS0						0								// TWI Prescaler bit 0
#define TWSR_TWPS1						1								// TWI Prescaler bit 1

#define TWBR							(*((volatile u8*)0x20))			// TWI Bit rate register

#define START_CONDITION_ACK				0x08
#define REPEATED_START_CONDITION_ACK	0x10
#define SLAVE_ADDRESS_WITH_WRITE_ACK	0x18
#define SLAVE_ADDRESS_WITH_READ_ACK		0x40
#define MASTER_WRITE_DATA_ACK			0x28
#define MASTER_READ_DATA_ACK			0X50

#endif
