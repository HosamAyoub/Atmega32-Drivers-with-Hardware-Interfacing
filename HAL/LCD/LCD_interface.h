/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LCD					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define LCD_ROW0		0
#define LCD_ROW1		1

#define LCD_COLUMN0		0
#define LCD_COLUMN1     1
#define LCD_COLUMN2     2
#define LCD_COLUMN3     3
#define LCD_COLUMN4     4
#define LCD_COLUMN5     5
#define LCD_COLUMN6     6
#define LCD_COLUMN7     7
#define LCD_COLUMN8     8
#define LCD_COLUMN9     9
#define LCD_COLUMN10    10
#define LCD_COLUMN11    11
#define LCD_COLUMN12    12
#define LCD_COLUMN13    13
#define LCD_COLUMN14    14
#define LCD_COLUMN15    15

#define LCD_FOUR_BIT	0
#define LCD_EIGHT_BIT	1


void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInitialize(void);
void LCD_voidGoToXY(u8 Copy_u8XPostion, u8 Copy_u8YPostion);
void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray, u8 Copy_u8PatternNumber, u8 Copy_u8XPostion, u8 Copy_u8YPostion);
void LCD_voidSendString(const u8 *Copy_pu8String);
void LCD_voidSplitNumber(s32 Copy_s32Number);
u32 LCD_u32Power(u32 Copy_u32Base, u32 Copy_u32Power);

#endif
