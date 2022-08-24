/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: Transistor			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Transistor_interface.h"
#include "Transistor_private.h"
#include "Transistor_config.h"


void Transisor_voidIntialization(void)
{
	DIO_u8SetPinDirection(TRANSISTOR_BASE_PORT, TRANSISTOR_BASE_PIN, DIO_PIN_OUTPUT);
}

void Transisor_voidSaturationMode(void)
{
	DIO_u8SetPinValue(TRANSISTOR_BASE_PORT, TRANSISTOR_BASE_PIN, DIO_PIN_HIGH);
}

void Transisor_voidCutOffMode(void)
{
	DIO_u8SetPinValue(TRANSISTOR_BASE_PORT, TRANSISTOR_BASE_PIN, DIO_PIN_LOW);
}
