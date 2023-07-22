/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: MOTOR					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_config.h"

void MOTOR_voidInitialize(void)
{
	DIO_u8SetPinDirection(MOTOR_PORT, MOTOR_CCW_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(MOTOR_PORT, MOTOR_CW_PIN, DIO_PIN_OUTPUT);
}

void MOTOR_voidCounterClockWise(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, MOTOR_CW_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, MOTOR_CCW_PIN, DIO_PIN_HIGH);
}
void MOTOR_voidClockWise(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, MOTOR_CCW_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, MOTOR_CW_PIN, DIO_PIN_HIGH);
}
void MOTOR_voidStop(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, MOTOR_CCW_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, MOTOR_CW_PIN, DIO_PIN_LOW);
}
