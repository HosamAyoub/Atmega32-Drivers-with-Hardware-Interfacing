/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: SPI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/*MSB, Prescaler = 16, Leading edge, sample(receive) at leading edge*/
void SPI_voidMasterInit (void)
{
	/*Set the node to be Master*/
	SET_BIT(SPCR, SPCR_MSTR);
	/*Set the MSB to be sent first*/
	CLR_BIT(SPCR, SPCR_DORD);
	/*Set the leading edge to be rising*/
	CLR_BIT(SPCR, SPCR_CPOL);
	/*Sample at leading edge*/
	CLR_BIT(SPCR, SPCR_CPHA);
	/*Prescaler = 16*/
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2x);
	/*Enable SPI*/
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidSlaveInit (void)
{
	/*Set the node to be Slave*/
	CLR_BIT(SPCR, SPCR_MSTR);
	/*Set the MSB to be sent first*/
	CLR_BIT(SPCR, SPCR_DORD);
	/*Set the leading edge to be rising*/
	CLR_BIT(SPCR, SPCR_CPOL);
	/*Sample at leading edge*/
	CLR_BIT(SPCR, SPCR_CPHA);
	/*Enable SPI*/
	SET_BIT(SPCR, SPCR_SPE);
}

u8 SPI_u8Tranceive (u8 Copy_u8DataToBeSent)
{
	u8 Local_u8Dummy, Local_u8ReceivedData;
	/*Set the data in the SPDR register*/
	SPDR = Copy_u8DataToBeSent;
	/*Polling (busy waiting) on the flag until the exchange complete*/
	while (!GET_BIT(SPSR, SPSR_SPIF));		//while (GET_BIT(SPSR, SPSR_SPIF) == 0);
	/*Clearing flag register need 3 steps*/
	/*1- Read the status register*/
	Local_u8Dummy = SPSR;
	/*2- Clear the flag by writing 1*/
	SET_BIT(SPSR, SPSR_SPIF);
	/*3- Access SPDR*/
	Local_u8ReceivedData = SPDR;
	/*Returning the exchange data*/
	return Local_u8ReceivedData;
}
