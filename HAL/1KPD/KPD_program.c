/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: KPD					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_voidInit(void)
{
	/* Set the columns pins to be output */
	DIO_u8SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, DIO_PIN_OUTPUT);

	/* Set the columns pins to be high */
	DIO_u8SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN0_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN1_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN2_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_COLUMNS_PORT, KPD_COLUMN3_PIN, DIO_PIN_HIGH);

	/* Set the rows pins to be input */
	DIO_u8SetPinDirection(KPD_ROWS_PORT, KPD_ROW0_PIN, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(KPD_ROWS_PORT, KPD_ROW1_PIN, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(KPD_ROWS_PORT, KPD_ROW2_PIN, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(KPD_ROWS_PORT, KPD_ROW3_PIN, DIO_PIN_INPUT);

	/* Set the rows pins to be pulled up */
	DIO_u8SetPinValue(KPD_ROWS_PORT, KPD_ROW0_PIN, DIO_PULLUP);
	DIO_u8SetPinValue(KPD_ROWS_PORT, KPD_ROW1_PIN, DIO_PULLUP);
	DIO_u8SetPinValue(KPD_ROWS_PORT, KPD_ROW2_PIN, DIO_PULLUP);
	DIO_u8SetPinValue(KPD_ROWS_PORT, KPD_ROW3_PIN, DIO_PULLUP);
}

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColumnsIndex, Local_u8RowsIndex, Local_u8PinState, Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	u8 Local_u8ColumnsArray[4] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	u8 Local_u8RowsArray[4] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	u8 Local_u8KeysArray[4][4] = KPD_KEYS_ARRAYS_VALUES;

	/* Loop for columns */
	for (Local_u8ColumnsIndex = 0; Local_u8ColumnsIndex < 4; Local_u8ColumnsIndex++)
	{
		/* Activate Current Column */
		DIO_u8SetPinValue(KPD_COLUMNS_PORT, Local_u8ColumnsArray[Local_u8ColumnsIndex], DIO_PIN_LOW);

		/* Loops for rows */
		for(Local_u8RowsIndex = 0; Local_u8RowsIndex < 4; Local_u8RowsIndex++)
		{
			DIO_u8GetPinValue(KPD_ROWS_PORT, Local_u8RowsArray[Local_u8RowsIndex], &Local_u8PinState);
			if(Local_u8PinState == 0)
			{
				/* Get the pressed Key */
				Local_u8PressedKey = Local_u8KeysArray[Local_u8RowsIndex][Local_u8ColumnsIndex];
				/* Polling (Busy Waiting), Wait until the pressed key is released */
				while(Local_u8PinState == 0)
				{
					DIO_u8GetPinValue(KPD_ROWS_PORT, Local_u8RowsArray[Local_u8RowsIndex], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/* Deactivate Current Column */
		DIO_u8SetPinValue(KPD_COLUMNS_PORT, Local_u8ColumnsArray[Local_u8ColumnsIndex], DIO_PIN_HIGH);
	}
	return Local_u8PressedKey;
}
