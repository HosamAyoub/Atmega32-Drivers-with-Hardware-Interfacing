/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LCD					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set the RS pin to be LOW: 0 command*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	/*Set the RW pin to be LOW: 0 write*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_RW_PIN, DIO_PIN_LOW);

#if 	LCD_MODE == LCD_EIGHT_BIT

	/*Set the Port value to be the command*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

#elif 	LCD_MODE == LCD_FOUR_BIT

	/*Set the Port value to be the command*/
	DIO_u8SetPortValue(LCD_DATA_PORT, (Copy_u8Command & 0xf0));

	/*Set the EN pin to be HIGH: 1 to read , waiting for 2ms and then make it LOW again: 0*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_LOW);


	DIO_u8SetPortValue(LCD_DATA_PORT, ((Copy_u8Command<<4) & 0xf0));
#endif

	/*Set the EN pin to be HIGH: 1 to read , waiting for 2ms and then make it LOW again: 0*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}


void LCD_voidSendData(u8 Copy_u8Data)
{
	/*Set the RS pin to be HIGH: 1 command*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	/*Set the RW pin to be LOW: 0 write*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_RW_PIN, DIO_PIN_LOW);

#if 	LCD_MODE == LCD_EIGHT_BIT

	/*Set the Port value to be the data*/
	DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

#elif 	LCD_MODE == LCD_FOUR_BIT

	/*Set the Port value to be the data*/
	DIO_u8SetPortValue(LCD_DATA_PORT, (Copy_u8Data & 0xf0));

	/*Set the EN pin to be HIGH: 1 to read , waiting for 2ms and then make it LOW again: 0*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	DIO_u8SetPortValue(LCD_DATA_PORT, ((Copy_u8Data<<4) & 0xf0));

#endif

	/*Set the EN pin to be HIGH: 1 to read , waiting for 2ms and then make it LOW again: 0*/
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_voidInitialize(void)
{
	/*Set the control pins to be output*/
	DIO_u8SetPinDirection(LCD_CRTL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CRTL_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CRTL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);

	/*waiting for more than 30ms*/
	_delay_ms(40);

#if LCD_MODE == LCD_EIGHT_BIT

	/*Set the data port to be output*/
	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);

	/*Send the function set command: N = 1 ->2 lines, F = 0 -> 5*8 font size*/
	LCD_voidSendCommand(0x38);

	/*Send the function set command: D = 1 -> DisplayOn, C = 0 -> CursorInvisible, B = 0 -> NoBlinking*/
	LCD_voidSendCommand(0x0C);

	/*Send the display clear command*/
	LCD_voidSendCommand(0x01);

#elif LCD_MODE == LCD_FOUR_BIT

	/*Set the data port to be output*/
	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_PORT_LHALF_OUTPUT);


//	/*First Way*/
//	/*Send the function set command: N = 1 ->2 lines, F = 0 -> 5*8 font size*/
//	LCD_voidSendCommand(0x20);
//	LCD_voidSendCommand(0x20);
//	LCD_voidSendCommand(0x80);
//	/*Send the function set command: D = 0 -> DisplayOff, C = 0 -> CursorInvisible, B = 0 -> NoBlinking*/
//	LCD_voidSendCommand(0x00);
//	LCD_voidSendCommand(0xC0);
//	/*Send the display clear command*/
//	LCD_voidSendCommand(0x00);
//	LCD_voidSendCommand(0x10);

	/*Second Way*/
	/*Send the function set command: N = 1 ->2 lines, F = 0 -> 5*8 font size*/
		LCD_voidSendCommand(0x28);
	/*Send the function set command: D = 0 -> DisplayOff, C = 0 -> CursorInvisible, B = 0 -> NoBlinking*/
		LCD_voidSendCommand(0x0C);
	/*Send the display clear command*/
		LCD_voidSendCommand(0x01);

#endif
}


void LCD_voidGoToXY(u8 Copy_u8XPostion, u8 Copy_u8YPostion)
{
	u8 Local_u8Address = 0;
	/* Check the number of row 0 or 1 */
	if (Copy_u8XPostion == LCD_ROW0)
	{
		Local_u8Address = Copy_u8YPostion;
	}
	else if (Copy_u8XPostion == LCD_ROW1)
	{
		Local_u8Address = Copy_u8YPostion + DDRAM_OFFSET;
	}

	SET_BIT(Local_u8Address, 7);

	LCD_voidSendCommand(Local_u8Address);

}


void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPostion, u8 Copy_u8YPostion)
{
	u8 Local_u8CGRAMAddress = 0, Local_u8LoopCounter;
	/* Calculating CGRAMAddress */
	Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;

	/* make the 6th bit from address to 1 and sending the command to the LCD */
	SET_BIT(Local_u8CGRAMAddress, 6);
	LCD_voidSendCommand(Local_u8CGRAMAddress);

	/* Sending the bytes from character array to the LCD */
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
	{
		LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
	}
	/* Send the DDRAM address command and specifying the position of the character */
	LCD_voidGoToXY(Copy_u8XPostion, Copy_u8YPostion);

	/* Displaying the pattern from CGRAM */
	LCD_voidSendData(Copy_u8PatternNumber);
}


void LCD_voidSendString(const u8 *Copy_pu8String)
{
	for(u8 Local_u8Iterator = 0; Copy_pu8String[Local_u8Iterator] != '\0'; Local_u8Iterator++)
	{
		LCD_voidSendData(Copy_pu8String[Local_u8Iterator]);
	}
}

void LCD_voidSplitNumber(s32 Copy_s32Number)
{
	s8 Local_s8Array[11], Local_s8Digits = 0;
	s32 Local_s32Copy;

	if (Copy_s32Number > 0)
	{
		Local_s32Copy = Copy_s32Number;
		while (Local_s32Copy != 0)
		{
			Local_s32Copy /= 10;
			Local_s8Digits++;
		}
	}
	else if (Copy_s32Number < 0)
	{
		Local_s32Copy = -Copy_s32Number;

		{
			while (Local_s32Copy != 0)
			{
				Local_s32Copy /= 10;
				Local_s8Digits++;
			}
		}
	}
	else
	{
		Local_s8Array[Local_s8Digits] = Copy_s32Number;
		LCD_voidSendData(Local_s8Array[Local_s8Digits] + '0');
	}

	if (Local_s8Digits > 0)
	{
		if (Copy_s32Number > 0)
		{
			for (u8 Local_u8Iterator= 0; Local_s8Digits != 0; Local_u8Iterator++)
			{
				Local_s8Array[Local_u8Iterator] = Copy_s32Number / LCD_u32Power(10, Local_s8Digits-1);
				Copy_s32Number -= Local_s8Array[Local_u8Iterator] * LCD_u32Power(10, Local_s8Digits-1);
				Local_s8Digits--;
				LCD_voidSendData(Local_s8Array[Local_u8Iterator] + '0');
			}
		}
		else
		{
			u8 Local_u8Iterator= 0;
			Local_s8Array[Local_s8Digits] = '-';
			LCD_voidSendData(Local_s8Array[Local_s8Digits]);
			Local_u8Iterator++;
			Copy_s32Number = -Copy_s32Number;
			for (; Local_s8Digits != 0; Local_u8Iterator++)
			{
				Local_s8Array[Local_u8Iterator] = Copy_s32Number / LCD_u32Power(10, Local_s8Digits-1);
				Copy_s32Number -= Local_s8Array[Local_u8Iterator] * LCD_u32Power(10, Local_s8Digits-1);
				Local_s8Digits--;
				LCD_voidSendData(Local_s8Array[Local_u8Iterator] + '0');
			}
		}
	}
}

u32 LCD_u32Power(u32 Copy_u32Base, u32 Copy_u32Power)
{
	u32 Local_u32Number = Copy_u32Base;

	/*Covering the case if the power of number was 0*/
	if(Copy_u32Power == 0)
	{
		Copy_u32Base = 1;
	}

	/*The body of power function for postive number*/
	for(; Copy_u32Power > 1; Copy_u32Power--)
	{
		Copy_u32Base *= Local_u32Number;
	}
	return Copy_u32Base;
}
