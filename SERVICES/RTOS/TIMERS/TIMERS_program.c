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
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

static void (*Global_pvCTCFunction)(void) = NULL;

void TIMERS_voidTimer0Init (void)
{
//	/*Enable the output compare interrupt*/
//	SET_BIT(TIMSK, TIMSK_OCIE0);

//	/*Set CTC mode*/
//	CLR_BIT(TCCR0, TCCR0_WGM00);
//	SET_BIT(TCCR0, TCCR0_WGM01);

	/*Set Fast PMW mode*/
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	/*set on top, clear on compare*/
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

	/*Set prescaler to be 8*/
	TCCR0 &= 0b11111000;
	TCCR0 |= 0b00000010;
}

void TIMERS_voidTimer0SetCompareMatchValue (u8 Copy_u8CompareMatchValue)
{
	OCR0 = Copy_u8CompareMatchValue;
}


void TIMERS_voidTimer0SetPreloadhValue (u8 Copy_u8PreloadValue)
{
	TCNT0 = Copy_u8PreloadValue;
}

void TIMERS_voidTimer0CTCSetCallBackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvCTCFunction = Copy_pvCTCFunction;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (Global_pvCTCFunction != NULL)
	{
		Global_pvCTCFunction();
	}
	else
	{

	}
}
