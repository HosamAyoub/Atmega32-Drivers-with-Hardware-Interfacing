/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: SPI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*SPI Control Register*/
#define SPCR			(*((volatile u8*) 0x2D))
#define SPCR_SPR0		0							//SPI Prescaler bit 0
#define SPCR_SPR1		1							//SPI Prescaler bit 1
#define SPCR_CPHA		2							//SPI Clock phase
#define SPCR_CPOL		3							//SPI Clock polarity
#define SPCR_MSTR		4							//SPI Master/Slave
#define SPCR_DORD		5							//SPI Data Order
#define SPCR_SPE		6							//SPI Prephiral enable
#define SPCR_SPIE		7							//SPI Interrupt enable

/*SPI Status Register*/
#define SPSR			(*((volatile u8*) 0x2E))
#define SPSR_SPI2x		0							//SPI Prescaler bit 2
#define SPSR_WCOL		6							//SPI Writecollision flag
#define SPSR_SPIF		7							//SPI Interrupt flage

/*SPI Data Register*/
#define SPDR			(*((volatile u8*) 0x2F))

#endif
