/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: OptoCoupler			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "OptoCoupler_interface.h"
#include "OptoCoupler_private.h"
#include "OptoCoupler_config.h"


void OptoCoupler_voidIntialization(void)
{
	DIO_u8SetPinDirection(OPTOCOUPLER_ANODE_PORT, OPTOCOUPLER_ANODE_PIN, DIO_PIN_OUTPUT);
}

void OptoCoupler_voidOnMode(void)
{
	DIO_u8SetPinValue(OPTOCOUPLER_ANODE_PORT, OPTOCOUPLER_ANODE_PIN, DIO_PIN_HIGH);
}

void OptoCoupler_voidOffMode(void)
{
	DIO_u8SetPinValue(OPTOCOUPLER_ANODE_PORT, OPTOCOUPLER_ANODE_PIN, DIO_PIN_LOW);
}
