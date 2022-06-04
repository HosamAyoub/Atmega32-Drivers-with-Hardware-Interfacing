/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidSleep (u8 Copy_u8Time)
{
	if (Copy_u8Time < 8)
	{
		/*Bit masking for the prescaler options*/
		WDTCR &= PRESCALER_MASK;
		WDTCR |= Copy_u8Time;
	}
	else
	{
		/*Do nothing*/
	}
}

void WDT_voidEnable (void)
{
	SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidDisable (void)
{
	/*Write one to WDTOE and WDE in same operation*/
//	WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE);
	WDTCR |= 0b00011000;
	/*Write zero to WDE within the next four operations*/
	WDTCR = 0x00;
}
