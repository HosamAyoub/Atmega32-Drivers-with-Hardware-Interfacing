/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: H_bridge			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "H_Bridge_config.h"
#include "H_Bridge_interface.h"
#include "H_Bridge_private.h"


void H_Bridge_voidIntialization (void)
{
	DIO_u8SetPinDirection(H_BRIDGE_PORT, H_BRIDGE_FIRST_DIRECTION_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(H_BRIDGE_PORT, H_BRIDGE_SECOND_DIRECTION_PIN, DIO_PIN_OUTPUT);
}

void H_Bridge_voidFirstDirection (void)
{
	DIO_u8SetPinValue(H_BRIDGE_PORT, H_BRIDGE_SECOND_DIRECTION_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(H_BRIDGE_PORT, H_BRIDGE_FIRST_DIRECTION_PIN, DIO_PIN_HIGH);
}

void H_Bridge_voidSecondDirection (void)
{
	DIO_u8SetPinValue(H_BRIDGE_PORT, H_BRIDGE_FIRST_DIRECTION_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(H_BRIDGE_PORT, H_BRIDGE_SECOND_DIRECTION_PIN, DIO_PIN_HIGH);
}

void H_Bridge_voidStop (void)
{
	DIO_u8SetPinValue(H_BRIDGE_PORT, H_BRIDGE_FIRST_DIRECTION_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(H_BRIDGE_PORT, H_BRIDGE_SECOND_DIRECTION_PIN, DIO_PIN_LOW);
}
