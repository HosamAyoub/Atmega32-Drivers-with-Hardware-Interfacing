/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: ADC					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
static void (*Global_pvNotificationFunction) (void) = NULL;
static u8 Global_u8BusyState = FREE;
static u16 Global_u16Result;

void ADC_voidInit (void)
{
	/*AVCC as a reference voltage*/
	ADMUX &= ADC_REFERANCE_MASK;
	ADMUX |= ADC_REF_VOLTAGE;

	/*Enable left adjust*/
	#if ADC_NUMBER_OF_BITS == EIGHT_BITS
		SET_BIT(ADMUX, ADMUX_ADLAR);
	/*Enable right adjust*/
	#elif ADC_NUMBER_OF_BITS == TEN_BITS
		CLR_BIT(ADMUX, ADMUX_ADLAR);
	#else
		#error "ADC_ADJSUT configuration Error"
	#endif

	/*Set the prescaler value*/
	ADCSRA &= ADC_PRESCALER_MASK;
	ADCSRA |= ADC_PRESCALER;

	/*ADC interrupt enable*/
	#if ADC_INTERRUPT_MODE  == ENABLE
		SET_BIT(ADCSRA, ADCSRA_ADIE);
	#elif ADC_INTERRUPT_MODE  == DISABLE
    	CLR_BIT(ADCSRA, ADCSRA_ADIE);
	#else
    	#error "ADC_INTERRUPT_MODE Configuration Error"
	#endif

	/*Enable ADC peripheral*/
	#if ADC_ENABLE == ENABLE
    	SET_BIT(ADCSRA, ADCSRA_ADEN);
	#elif ADC_ENABLE == DISABLE
    	CLR_BIT(ADCSRA, ADCSRA_ADEN);
	#else
		#error "ADC_ENABLE Configuration Error"
	#endif
}


u16 ADC_u8GetChannelReadingSynchronous (u8 Copy_u8Channel)
{
	if (Global_u8BusyState == BUSY)
	{
		return 0;
	}
	else
	{
		/*Check if the function argument in valid or not*/
		if (Copy_u8Channel < 8)
		{
			/*Set the ADC_BusyState to be busy*/
			Global_u8BusyState = BUSY;

			/*Set the MUX bits to the input Channel*/
			ADMUX &= ADC_MUX_MASK;
			ADMUX |= Copy_u8Channel;

		    /*ADC operation mode*/
			#if ADC_MODE == SINGLE_CONVERSATION
				/*Disable the AutoTrigger*/
		    	CLR_BIT(ADCSRA, ADCSRA_ADATE);
				/*Start conversion*/
				SET_BIT(ADCSRA, ADCSRA_ADSC);
				/*Polling (busy waiting) until the conversion complete flag is set*/
				while (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);
				/*Clear the conversion complete flag*/
				SET_BIT(ADCSRA, ADCSRA_ADIF);
			#elif ADC_MODE == AUTO_TRIGGER
				/*Enable the AutoTrigger*/
		    	SET_BIT(ADCSRA, ADCSRA_ADATE);
		    	/*Set the AutoTrigger source*/
				SFIOR &= ADC_AUTO_TRIGGER_MASK;
				SFIOR |= ADC_AUTO_TRIGGER;
				/*Start conversion*/
				SET_BIT(ADCSRA, ADCSRA_ADSC);
			#else
				#error "ADC_MODE Configuration Error"
			#endif

			/*Set the ADC_BusyState to be free*/
			Global_u8BusyState = FREE;

			/*Return the reading*/
			#if ADC_NUMBER_OF_BITS == EIGHT_BITS
				return ADCH;
			#elif ADC_NUMBER_OF_BITS == TEN_BITS
				return ADC;
			#else
				#error "ADC_ENABLE Configuration Error"
			#endif
		}
		else
		{
			/*Do Nothing*/
			return 1;
		}

	}
}


u16 ADC_u8GetChannelReadingAsynchronous (u8 Copy_u8Channel, void (*Copy_pvCallBackFunction) (void))
{
	if (Global_u8BusyState == BUSY)
	{
		return 0;
	}
	else
	{
		/*Check if the function argument in valid or not*/
		if (Copy_u8Channel < 8)
		{
			/*Set the ADC_BusyState to be busy*/
			Global_u8BusyState = BUSY;

			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= ADC_MUX_MASK;
			/*Set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel;

			/*Set the call back function*/
			Global_pvNotificationFunction = Copy_pvCallBackFunction;

		    /*ADC operation mode*/
			#if ADC_MODE == SINGLE_CONVERSATION
				/*Disable the AutoTrigger*/
		    	CLR_BIT(ADCSRA, ADCSRA_ADATE);
				/*Start conversion*/
				SET_BIT(ADCSRA, ADCSRA_ADSC);
				/*Enable the interrupt*/
				SET_BIT(ADCSRA, ADCSRA_ADIE);
			#elif ADC_MODE == AUTO_TRIGGER
				/*Enable the AutoTrigger*/
				SET_BIT(ADCSRA, ADCSRA_ADATE);
				/*Enable the interrupt*/
				SET_BIT(ADCSRA, ADCSRA_ADIE);
				/*Set the AutoTrigger source*/
				SFIOR &= ADC_AUTO_TRIGGER_MASK;
				SFIOR |= ADC_AUTO_TRIGGER;
				/*Start conversion*/
				SET_BIT(ADCSRA, ADCSRA_ADSC);
			#else
				#error "ADC_MODE Configuration Error"
			#endif

			/*Return the reading*/
			return Global_u16Result;
		}
		else
		{
			/*Do nothing*/
			return 1;
		}
	}
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*Read the result*/
	#if ADC_NUMBER_OF_BITS == EIGHT_BITS
		Global_u16Result = ADCH;
	#elif ADC_NUMBER_OF_BITS == TEN_BITS
		Global_u16Result = ADC;
	#else
		#error "ADC_NUMBER_OF_BITS Configuration Error"
	#endif

	if (Global_pvNotificationFunction != NULL)
	{
		Global_pvNotificationFunction();

		/*Set the ADC_BusyState to be free*/
		Global_u8BusyState = FREE;

		/*Disable the interrupt*/
		CLR_BIT(ADCSRA, ADCSRA_ADIE);
	}
	else
	{
		/*Do nothing*/
	}
}
