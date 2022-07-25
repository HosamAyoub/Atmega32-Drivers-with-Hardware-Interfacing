/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: EEPROM			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"
#define F_CPU 8000000UL
#include "util/delay.h"

void EEPROM_voidSendData (u16 Copy_u16LocationAddress, u8 Copy_u8Data)
{
	u8 Local_u8AddressPacket;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);
	/*Send start condition*/
	TWI_ErrorStatusSendStartConditionWithACK();
	/*Send slave address with write request*/
	TWI_ErrorStatusSendSlaveAddressWithWriteACK(Local_u8AddressPacket);
	/*Send the reset of data from b7->b0*/
	TWI_ErrorStatusMasterWriteDataByteWithACK((u8)Local_u8AddressPacket);
	/*Send data*/
	TWI_ErrorStatusMasterWriteDataByteWithACK(Copy_u8Data);
	/*Send stop condition*/
	TWI_voidStopCondition();
	/*Delay for 5mses*/
	_delay_ms(5);
}

void EEPROM_voidReceiveData (u16 Copy_u16LocationAddress, u8 *Copy_pu8ReceivedData)
{
	u8 Local_u8AddressPacket;
	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (EEPROM_A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);
	/*Send start condition*/
	TWI_ErrorStatusSendStartConditionWithACK();
	/*Send slave address with write request*/
	TWI_ErrorStatusSendSlaveAddressWithWriteACK(Local_u8AddressPacket);
	/*Send the reset of data from b7->b0*/
	TWI_ErrorStatusMasterWriteDataByteWithACK((u8)Local_u8AddressPacket);
	/*Send repeated start condition*/
	TWI_ErrorStatusSendRepeatedStartConditionWithACK();
	/*Send slave address with write request*/
	TWI_ErrorStatusSendSlaveAddressWithReadACK(Local_u8AddressPacket);
	/*Read the data*/
	TWI_ErrorStatusMasterReadDataByteWithACK(Copy_pu8ReceivedData);
	/*Send stop condition*/
	TWI_voidStopCondition();
}
