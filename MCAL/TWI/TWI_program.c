/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TWI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_voidMasterInit (u8 Copy_u8MasterAddress)
{
	/*Enable Acknowledge*/
	SET_BIT(TWCR, TWCR_TWEA);

	/*Set Frequency = 100KHZ, with TWPS bit = 0 and CPU Clock = 8MHZ*/
	TWBR = 32;
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);

	if (Copy_u8MasterAddress == 0)
	{
		/*Do nothing*/
	}
	else
	{
		/*Set the required address for the master*/
		TWAR = Copy_u8MasterAddress << 1;
	}

	/*Enable TWI peripheral*/
	SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit (u8 Copy_u8SlaveAddress)
{
	/*Enable Acknowledge*/
	SET_BIT(TWCR, TWCR_TWEA);

	/*Set the required address for the slave*/
	TWAR = (Copy_u8SlaveAddress << 1);

	/*Enable TWI peripheral*/
	SET_BIT(TWCR, TWCR_TWEN);
}

TWI_ErrorStatus_t TWI_ErrorStatusSendStartConditionWithACK (void)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set start condition bit*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*Clear  the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy wait) on the TWINT flag*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right or not*/
	if ((TWSR & 0xF8) != START_CONDITION_ACK)
	{
		/*Return Error*/
		Local_ErrorStatus = StartConditionError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusSendRepeatedStartConditionWithACK (void)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set start condition bit*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*Clear  the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy wait) on the TWINT flag*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right*/
	if ((TWSR & 0xF8) != REPEATED_START_CONDITION_ACK)
	{
		/*Return Error*/
		Local_ErrorStatus = RepeatedStartConditionError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithWriteACK (u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set the Slave address in the TWDR*/
	TWDR = (Copy_u8SlaveAddress << 1);
	/*Clear Bit 0 for Write*/
	CLR_BIT(TWDR, TWDR_TWD0);
	/*Clear start condition bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);
	/*Clear the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy wait) on the TWINT flag*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right*/
	if ((TWSR & 0xF8) != SLAVE_ADDRESS_WITH_WRITE_ACK)
	{
		/*Return Error*/
		Local_ErrorStatus = SlaveAddressWriteError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusSendSlaveAddressWithReadACK (u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set the Slave address in the TWDR*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*Set Bit 0 for Read*/
	SET_BIT(TWDR, TWDR_TWD0);
	/*Clear start condition bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);
	/*Clear the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy wait) on the TWINT flag*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right*/
	if ((TWSR & 0xF8) != SLAVE_ADDRESS_WITH_READ_ACK)
	{
		/*Return Error*/
		Local_ErrorStatus = SlaveAddressReadError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusMasterWriteDataByteWithACK (u8 Copy_u8Data)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Set the data in the TWDR*/
	TWDR = Copy_u8Data;
	/*Clear the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy wait) on the TWINT flag*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right*/
	if ((TWSR & 0xF8) != MASTER_WRITE_DATA_ACK)
	{
		/*Return Error*/
		Local_ErrorStatus = MasterWriteDataError;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrorStatus;
}

TWI_ErrorStatus_t TWI_ErrorStatusMasterReadDataByteWithACK (u8 *Copy_pu8ReceiveData)
{
	TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	/*Clear the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (Busy wait) on the TWINT flag*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right*/
	if ((TWSR & 0xF8) != MASTER_READ_DATA_ACK)
	{
		/*Return Error*/
		Local_ErrorStatus = MasterReadDataError;
	}
	else
	{
		/*Receive the data*/
		*Copy_pu8ReceiveData = TWDR;
	}
	return Local_ErrorStatus;
}

void TWI_voidStopCondition (void)
{
	/*Set the stop condition*/
	SET_BIT(TWCR, TWCR_TWSTO);
	/*Clear the TWINT flag*/
	SET_BIT(TWCR, TWCR_TWINT);
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Checking if operation is transmitted right*/
}
