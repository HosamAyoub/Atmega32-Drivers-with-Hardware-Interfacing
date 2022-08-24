/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: Transistor			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Relay_interface.h"
#include "Relay_private.h"
#include "Relay_config.h"


void Relay_voidIntialization(void)
{
	DIO_u8SetPinDirection(RELAY_PORT, RELAY_PIN, DIO_PIN_OUTPUT);
}

void Relay_voidNormallyClose(void)
{
	DIO_u8SetPinValue(RELAY_PORT, RELAY_PIN, DIO_PIN_LOW);
}

void Relay_voidNormallyOpen(void)
{
	DIO_u8SetPinValue(RELAY_PORT, RELAY_PIN, DIO_PIN_HIGH);
}
