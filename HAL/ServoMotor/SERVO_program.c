/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: SERVO					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMERS/TIMERS_interface.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"

u8 SERVO_u8SetAngle (u8 Copy_u8Angle)
{
	if (Copy_u8Angle < 180)
	{
		u16 Local_u16OCRValue = (( (u16)(Copy_u8Angle*1000UL)/180.0) + 999);
		TIMERS_voidTimer1SetChannelACompareMatchValue(Local_u16OCRValue);
		return OK;
	}
	else
	{
		return ERROR;
	}
}
