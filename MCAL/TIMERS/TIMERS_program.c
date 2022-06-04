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
#include "../DIO/DIO_interface.h"

/*Array of pointers to function*/
static void (*Global_pvArrayFunction[ARRAY_SIZE])(void) = {NULL};

/********************			TIMER0 Functions			*********************************/

void TIMERS_voidTimer0Init (void)
{
	#if TIMER0_MODE == TIMER0_OVF_MODE
		/*Set OVF mode*/
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		/*Enable OVF interrupt*/
		SET_BIT(TIMSK, TIMSK_TOIE0);

	#elif TIMER0_MODE == TIMER0_PWM_PHASE_CORRECT_MODE
		/*Set OVF mode*/
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		/*Set mode: OC0 PIN mode*/
		TCCR0 &= OC0_PIN_MASK;
		TCCR0 |= OC0_PIN_MODE;

	#elif TIMER0_MODE == TIMER0_CTC_MODE
		/*Set CTC mode*/
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		/*Enable CTC interrupt*/
		SET_BIT(TIMSK, TIMSK_OCIE0);
		/*Set mode: OC0 PIN mode*/
		TCCR0 &= OC0_PIN_MASK;
		TCCR0 |= OC0_PIN_MODE;

	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
		/*Set Fast PMW mode*/
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		/*Set mode: OC0 PIN mode*/
		TCCR0 &= OC0_PIN_MASK;
		TCCR0 |= OC0_PIN_MODE;
	#else "Timer0_MODE Configuration Error"
	#endif

	/*Set Prescaler of the clock*/
	TCCR0 &= TIMERS_PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER;
}

void TIMERS_voidTimer0SetCompareMatchValue (u8 Copy_u8CompareMatchValue)
{
	OCR0 = Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer0SetPreloadValue (u8 Copy_u8PreloadValue)
{
	TCNT0 = Copy_u8PreloadValue;
}

void TIMERS_voidTimer0CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER0_CTC] = Copy_pvCTCFunction;
}

void TIMERS_voidTimer0OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER0_OVF] = Copy_pvCTCFunction;
}

void TIMERS_voidTimer0Delay_us (f32 Copy_f32MicroSeconds)
{
	#if TIMER0_MODE == TIMER0_CTC_MODE || TIMER0_MODE == TIMER0_OVF_MODE
		f32 Local_f32TickTime, Local_f32OVFNumbers = 0;
		u8 Local_u8Value = TIMER0_MAX_VALUE;
		u32 Local_u32OVFNumbersInteger = 0, Local_u32OverflowTime;
		#if TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_1
			Local_f32TickTime = 1 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_8
			Local_f32TickTime = 8 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_64
			Local_f32TickTime = 64 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_256
			Local_f32TickTime = 256 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_1024
			Local_f32TickTime = 1024 / CLOCK;
		#endif
		Local_u32OverflowTime = Local_f32TickTime * (TIMER0_MAX_VALUE + 1);
		if (Copy_f32MicroSeconds <= Local_f32TickTime)
		{
			Local_u8Value = 1;
		}
		else if ((Copy_f32MicroSeconds > Local_f32TickTime) && (Copy_f32MicroSeconds <= Local_u32OverflowTime))
		{
			Local_u8Value = Copy_f32MicroSeconds / Local_f32TickTime;
			Local_u32OVFNumbersInteger = 1;
		}
		else if (Copy_f32MicroSeconds > Local_u32OverflowTime)
		{
			Local_f32OVFNumbers = (Copy_f32MicroSeconds / ((Local_u8Value + 1) * Local_f32TickTime));
			Local_u32OVFNumbersInteger = (u32)(Local_f32OVFNumbers);
			Local_f32OVFNumbers -= Local_u32OVFNumbersInteger;
		}
		#if TIMER0_MODE == TIMER0_CTC_MODE
			TIMERS_voidTimer0SetCompareMatchValue(Local_u8Value);
			TIMERS_voidTimer0Init();
			for (u32 Local_u32Iterator = 0; Local_u32Iterator < Local_u32OVFNumbersInteger; Local_u32Iterator++)
			{
				while (GET_BIT(TIFR, TIFR_OCF0) == 0);
				SET_BIT(TIFR, TIFR_OCF0);
			}
			Local_u8Value = Local_f32OVFNumbers * (TIMER0_MAX_VALUE + 1);
			TIMERS_voidTimer0SetCompareMatchValue(Local_u8Value);
			while (GET_BIT(TIFR, TIFR_OCF0) == 0);
			SET_BIT(TIFR, TIFR_OCF0);
		#elif TIMER0_MODE == TIMER0_OVF_MODE
			TIMERS_voidTimer0Init();
			for (u32 Local_u32Iterator = 0; Local_u32Iterator < Local_u32OVFNumbersInteger; Local_u32Iterator++)
			{
				while (GET_BIT(TIFR, TIFR_TOV0) == 0);
				SET_BIT(TIFR, TIFR_TOV0);
			}
			Local_u8Value = 256 - (Local_f32OVFNumbers * (TIMER0_MAX_VALUE + 1));
			TIMERS_voidTimer0SetPreloadValue(Local_u8Value);
			while (GET_BIT(TIFR, TIFR_TOV0) == 0);
			SET_BIT(TIFR, TIFR_TOV0);
		#endif
	#elif
		#error "Wrong operation mode"
	#endif
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (Global_pvArrayFunction[TIMER0_CTC] != NULL)
	{
		Global_pvArrayFunction[TIMER0_CTC]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if (Global_pvArrayFunction[TIMER0_OVF] != NULL)
	{
		Global_pvArrayFunction[TIMER0_OVF]();
	}
	else
	{
		/*Do Nothing*/
	}
}


/********************			TIMER1 Functions			*********************************/

void TIMERS_voidTimer1Init (void)
{
	/*Set mode of operation*/
	TCCR1 &= TIMER1_MODE_MASK;
	TCCR1 |= TIMER1_MODE;
	#if TIMER1_MODE != TIMER1_OVF_MODE
		/*Set mode: OC1A PIN mode*/
		TCCR1A &= OC1A_PIN_MASK;
		TCCR1A |= OC1A_PIN_MODE;
		/*Set mode: OC1B PIN mode*/
		TCCR1A &= OC1B_PIN_MASK;
		TCCR1A |= OC1B_PIN_MODE;
	#elif TIMER1_MODE == TIMER1_OVF_MODE
		/*Enable OVF interrupt*/
		SET_BIT(TIMSK, TIMSK_TOIE1);
	#else "Timer1_MODE Configuration Error"
	#endif
	/*Set Prescaler of the clock*/
	TCCR1B &= TIMERS_PRESCALER_MASK;
	TCCR1B |= TIMER1_PRESCALER;
}

void TIMERS_voidTimer1SetPreloadValue (u16 Copy_u16PreloadValue)
{
	TCNT1 = Copy_u16PreloadValue;
}

void TIMERS_voidTimer1SetTopValue (u16 Copy_u16TopValue)
{
	ICR1 = Copy_u16TopValue;
}

void TIMERS_voidTimer1SetChannelACompareMatchValue (u16 Copy_u16CompareMatchValue)
{
	OCR1A = Copy_u16CompareMatchValue;
}

void TIMERS_voidTimer1SetCTCAInterruptControl (u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case TIMERS_ENABLE:
		{
			/*Enable CTC Interrupt for Channel A*/
			SET_BIT(TIMSK, TIMSK_OCIE1A);
			break;
		}
		case TIMERS_DISABLE:
		{
			/*Disable CTC Interrupt for Channel A*/
			CLR_BIT(TIMSK, TIMSK_OCIE1A);
			break;
		}
	}
}

void TIMERS_voidTimer1SetChannelBCompareMatchValue (u16 Copy_u16CompareMatchValue)
{
	OCR1B = Copy_u16CompareMatchValue;
}

void TIMERS_voidTimer1SetCTCBInterruptControl (u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case TIMERS_ENABLE:
		{
			/*Enable CTC Interrupt for Channel B*/
			SET_BIT(TIMSK, TIMSK_OCIE1B);
			break;
		}
		case TIMERS_DISABLE:
		{
			/*Disable CTC Interrupt for Channel B*/
			CLR_BIT(TIMSK, TIMSK_OCIE1B);
			break;
		}
	}
}

void TIMERS_voidTimer1ICUSetSenseControl (u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
		case TIMERS_FALLING_EDGE:
		{
			/*Set Sense Signal To Be Falling Edge*/
			CLR_BIT(TCCR1B, TCCR1B_ICES1);
			break;
		}
		case TIMERS_RISING_EDGE:
		{
			/*Set Sense Signal To Be Rising Edge*/
			SET_BIT(TCCR1B, TCCR1B_ICES1);
			break;
		}
	}
}

u16 TIMERS_u16Timer1ICUReadInputCapture (void)
{
	/*Return Input Capture Register*/
	return ICR1;
}

void TIMERS_voidTimer1ICUInterruptControl (u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case TIMERS_ENABLE:
		{
			/*Enable ICU Interrupt*/
			SET_BIT(TIMSK, TIMSK_TICIE1);
		break;
		}
		case TIMERS_DISABLE:
		{
			/*Disable ICU Interrupt*/
			CLR_BIT(TIMSK, TIMSK_TICIE1);
		break;
		}
	}
}

void TIMERS_voidTimer1ICUSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER1_ICU] = Copy_pvCTCFunction;
}

void TIMERS_voidTimer1CTCASetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER1_CTCA] = Copy_pvCTCFunction;
}

void TIMERS_voidTimer1CTCBSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER1_CTCB] = Copy_pvCTCFunction;
}

void TIMERS_voidTimer1OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER1_OVF] = Copy_pvCTCFunction;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if (Global_pvArrayFunction[TIMER1_ICU] != NULL)
	{
		Global_pvArrayFunction[TIMER1_ICU]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if (Global_pvArrayFunction[TIMER1_CTCA] != NULL)
	{
		Global_pvArrayFunction[TIMER1_CTCA]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if (Global_pvArrayFunction[TIMER1_CTCB] != NULL)
	{
		Global_pvArrayFunction[TIMER1_CTCB]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if (Global_pvArrayFunction[TIMER1_OVF] != NULL)
	{
		Global_pvArrayFunction[TIMER1_OVF]();
	}
	else
	{
		/*Do Nothing*/
	}
}


/********************			TIMER2 Functions			*********************************/

void TIMERS_voidTimer2Init (void)
{
	#if TIMER2_MODE == TIMER2_OVF_MODE
		/*Set OVF mode*/
		CLR_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
		/*Enable OVF interrupt*/
		SET_BIT(TIMSK, TIMSK_TOIE2);

	#elif TIMER2_MODE == TIMER2_PWM_PHASE_CORRECT_MODE
		/*Set OVF mode*/
		SET_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
		/*Set mode: OC2 PIN mode*/
		TCCR2 &= OC2_PIN_MASK;
		TCCR2 |= OC2_PIN_MODE;

	#elif TIMER2_MODE == TIMER2_CTC_MODE
		/*Set CTC mode*/
		CLR_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
		/*Enable CTC interrupt*/
		SET_BIT(TIMSK, TIMSK_OCIE2);
		/*Set mode: OC2 PIN mode*/
		TCCR2 &= OC2_PIN_MASK;
		TCCR2 |= OC2_PIN_MODE;

	#elif TIMER2_MODE == TIMER2_FAST_PWM_MODE
		/*Set Fast PMW mode*/
		SET_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
		/*Set mode: OC2 PIN mode*/
		TCCR2 &= OC2_PIN_MASK;
		TCCR2 |= OC2_PIN_MODE;
	#else "Timer2_MODE Configuration Error"
	#endif

	/*Set Prescaler of the clock*/
	TCCR2 &= TIMERS_PRESCALER_MASK;
	TCCR2 |= TIMER2_PRESCALER;
}

void TIMERS_voidTimer2SetCompareMatchValue (u8 Copy_u8CompareMatchValue)
{
	OCR2 = Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer2SetPreloadValue (u8 Copy_u8PreloadValue)
{
	TCNT2 = Copy_u8PreloadValue;
}

void TIMERS_voidTimer2CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER2_CTC] = Copy_pvCTCFunction;
}

void TIMERS_voidTimer2OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	Global_pvArrayFunction[TIMER2_OVF] = Copy_pvCTCFunction;
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if (Global_pvArrayFunction[TIMER2_CTC] != NULL)
	{
		Global_pvArrayFunction[TIMER2_CTC]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if (Global_pvArrayFunction[TIMER2_OVF] != NULL)
	{
		Global_pvArrayFunction[TIMER2_OVF]();
	}
	else
	{
		/*Do Nothing*/
	}
}



