/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: STEPPER				*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMERS/TIMERS_interface.h"
#include "STEPPER_interface.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"

u8 STEPPER_u8Rotate (u8 Copy_u8Direction, u16 Copy_u16Angle)
{
	if (Copy_u8Direction == STEPPER_CLOCKWISE)
	{
		while (Copy_u16Angle > 360)
		{
			Copy_u16Angle -= 360;
		}

		f32 Local_f32Iterations = (Copy_u16Angle*(512.0/360));

		for (u16 Local_u16Iterator = 0; Local_u16Iterator < (u16)Local_f32Iterations; Local_u16Iterator++)
		{
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
		}
		return OK;
	}
	else if (Copy_u8Direction == STEPPER_COUNTER_CLOCKWISE)
	{
		while (Copy_u16Angle > 360)
		{
			Copy_u16Angle -= 360;
		}

		f32 Local_f32Iterations = (Copy_u16Angle*(512.0/360));

		for (u16 Local_u16Iterator = 0; Local_u16Iterator < (u16)Local_f32Iterations; Local_u16Iterator++)
		{
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_LOW);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_PIN_HIGH);
			TIMERS_u8Timer0Delay(STEPPER_STEP_DELAY, TIMERS_MS);
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}
