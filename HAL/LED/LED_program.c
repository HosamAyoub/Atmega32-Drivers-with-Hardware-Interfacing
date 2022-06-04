/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LED					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "util/delay.h"

LED_t LEDS[NUMBER_OF_LEDS] = {{NULL}};

void LED_voidInitLED (u8 Copy_u8ID, u8 Copy_u8Port, u8 Copy_u8Pin)
{
	LEDS[Copy_u8ID].u8Port = Copy_u8Port;
	LEDS[Copy_u8ID].u8Pin = Copy_u8Pin;
	DIO_u8SetPinDirection(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_OUTPUT);
}

void LED_voidInitGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID, u8 Copy_u8Port, u8 Copy_u8Pin)
{
	if ((Copy_u8EndID - Copy_u8StartID) <= (DIO_PIN7 - Copy_u8Pin))
	{
		for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
		{
			LEDS[Local_u8Iterator].u8Port = Copy_u8Port;
			LEDS[Local_u8Iterator].u8Pin = Copy_u8Pin + (Local_u8Iterator - Copy_u8StartID);
			DIO_u8SetPinDirection(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_OUTPUT);
		}
	}
	else
	{
		/*Do Nothing*/
	}
}

void LED_voidTurnOnLED (u8 Copy_u8ID)
{
	#if CONNECTION_TYPE == SOURCE
		DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
	#elif CONNECTION_TYPE == SINK
		DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
	#else
		#error "LED Connection Type Error"
	#endif
}

void LED_voidTurnOnGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID)
{
	for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
	{
		#if CONNECTION_TYPE == SOURCE
			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
		#elif CONNECTION_TYPE == SINK
			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
		#else
			#error "LED Connection Type Error"
		#endif
	}
}

void LED_voidTurnOffLED (u8 Copy_u8ID)
{
	#if CONNECTION_TYPE == SOURCE
		DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
	#elif CONNECTION_TYPE == SINK
		DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
	#else
		#error "LED Connection Type Error"
	#endif
}

void LED_voidTurnOffGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID)
{
	for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
	{
		#if CONNECTION_TYPE == SOURCE
			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
		#elif CONNECTION_TYPE == SINK
			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
		#else
			#error "LED Connection Type Error"
		#endif
	}
}

void LED_voidToggleLED (u8 Copy_u8ID)
{
	u8 Local_u8PinState;
	DIO_u8GetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, &Local_u8PinState);
	#if CONNECTION_TYPE == SOURCE
		if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
		}
		else if (Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
		}
	#elif CONNECTION_TYPE == SINK
		if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
		}
		else if (Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
		}
	#else
		#error "LED Connection Type Error"
	#endif
}

void LED_voidToggleGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID)
{
	u8 Local_u8PinState;
	for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
	{
		DIO_u8GetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, &Local_u8PinState);
		#if CONNECTION_TYPE == SOURCE
			if (Local_u8PinState == 0)
			{
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
			}
			else if (Local_u8PinState == 1)
			{
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
			}
		#elif CONNECTION_TYPE == SINK
			if (Local_u8PinState == 0)
			{
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
			}
			else if (Local_u8PinState == 1)
			{
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
			}
		#else
			#error "LED Connection Type Error"
		#endif
	}
}

void LED_voidBlinkLED (u8 Copy_u8ID, u16 Copy_u16Delay, u8 Copy_u8DelayType)
{
	u8 Local_u8PinState;
	DIO_u8GetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, &Local_u8PinState);
	#if CONNECTION_TYPE == SOURCE
		if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					_delay_ms(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					_delay_ms(Copy_u16Delay);
					break;
				}
				case LED_MICRO_SECOND:
				{
					_delay_us(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					_delay_us(Copy_u16Delay);
					break;
				}
			}

		}
		else if (Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					_delay_ms(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					_delay_ms(Copy_u16Delay);
					break;
				}
				case LED_MICRO_SECOND:
				{
					_delay_us(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					_delay_us(Copy_u16Delay);
					break;
				}
			}
		}
	#elif CONNECTION_TYPE == SINK
		if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					_delay_ms(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					_delay_ms(Copy_u16Delay);
					break;
				}
				case LED_MICRO_SECOND:
				{
					_delay_us(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					_delay_us(Copy_u16Delay);
					break;
				}
			}
		}
		else if (Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					_delay_ms(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					_delay_ms(Copy_u16Delay);
					break;
				}
				case LED_MICRO_SECOND:
				{
					_delay_us(Copy_u16Delay);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					_delay_us(Copy_u16Delay);
					break;
				}
			}
		}
	#else
		#error "LED Connection Type Error"
	#endif
}
