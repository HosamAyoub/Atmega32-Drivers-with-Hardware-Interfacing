/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: Seven Segment			*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

u8 SSD_u8SetNumber(u8 Copy_u8Number, SSD_t *Copy_pSSD_tElements)
{
	u8 Local_u8ErrorState = 0;
	u8 Local_u8ArrayOfNumbers[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
								0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

	if(Copy_pSSD_tElements != 0)
	{
		if(Copy_pSSD_tElements->u8CommonType == ANODE)
		{
			DIO_u8SetPinDirection(Copy_pSSD_tElements->u8EnablePort, Copy_pSSD_tElements->u8EnablePin, DIO_PIN_OUTPUT);
			DIO_u8SetPinValue(Copy_pSSD_tElements->u8EnablePort, Copy_pSSD_tElements->u8EnablePin, DIO_PIN_HIGH);
			DIO_u8SetPortDirection(Copy_pSSD_tElements->u8Port, DIO_PORT_OUTPUT);
			DIO_u8SetPortValue(Copy_pSSD_tElements->u8Port, ~(Local_u8ArrayOfNumbers[Copy_u8Number]));
		}
		else if(Copy_pSSD_tElements->u8CommonType == CATHODE)
		{
			DIO_u8SetPinDirection(Copy_pSSD_tElements->u8EnablePort, Copy_pSSD_tElements->u8EnablePin, DIO_PIN_INPUT);
			DIO_u8SetPortDirection(Copy_pSSD_tElements->u8Port, DIO_PORT_OUTPUT);
			DIO_u8SetPortValue(Copy_pSSD_tElements->u8Port, Local_u8ArrayOfNumbers[Copy_u8Number]);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}


	return Local_u8ErrorState;
}
