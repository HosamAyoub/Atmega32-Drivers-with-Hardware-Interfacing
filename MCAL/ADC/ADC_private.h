/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: ADC					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX				                (*((volatile u8*)0x27))			//ADC multiplexer selection register
#define ADMUX_REFS1		                    7								//Reference selection Bit 1
#define ADMUX_REFS0		                    6                               //Reference selection Bit 0
#define ADMUX_ADLAR		                    5                               //ADC Left adjust result

#define ADCSRA			                    (*((volatile u8*)0x26))         //ADC control & status register A
#define ADCSRA_ADEN		                    7                               //ADC enable
#define ADCSRA_ADSC		                    6                               //Start conversion
#define ADCSRA_ADATE	                    5                               //ADC auto trigger enable
#define ADCSRA_ADIF		                    4                               //ADC interrupt flag
#define ADCSRA_ADIE		                    3                               //ADC interrupt enable
#define ADCSRA_ADPS2	                    2                               //ADC prescaler selection Bit 2
#define ADSCRA_ADPS1	                    1                               //ADC prescaler selection Bit 1
#define ADSCRA_ADPS0	                    0                               //ADC prescaler selection Bit 0

#define ADCH			                    (*((volatile u8*)0x25))         //ADC high register
#define ADCL			                    (*((volatile u8*)0x24))         //ADC low register
#define ADC			    	                (*((volatile u16*)0x24))		//ADC result register

#define SFIOR			                    (*((volatile u8*)0x50))			//Special function input & output register

#define DISABLE					            0
#define ENABLE					            1

#define AREF					            0b00000000
#define AVCC					            0b01000000
#define REVERSED				            0b10000000
#define INTERNAL				            0b11000000

#define ADC_REFERANCE_MASK		            0b00111111

#define PRESCALER_DIV_BY_2		            1
#define PRESCALER_DIV_BY_4		            2
#define PRESCALER_DIV_BY_8		            3
#define PRESCALER_DIV_BY_16		            4
#define PRESCALER_DIV_BY_32		            5
#define PRESCALER_DIV_BY_64		            6
#define PRESCALER_DIV_BY_128	            7

#define ADC_PRESCALER_MASK		            0b11111000

#define ADC_MUX_MASK						0b11100000

#define TEN_BITS							0
#define EIGHT_BITS							1

#define FREE_RUNNING_MODE					0b00000000
#define ANALOG_COMPARATOR					0b00100000
#define EXTERNAL_INTERRUPT					0b01000000
#define TIMER_COUNTER0_COMPARE_MATCH		0b01100000
#define TIMER_COUNTER0_OVERFLOW				0b10000000
#define TIMER_COUNTER_COMPARE_MATCH_B		0b10100000
#define TIMER_COUNTER1_OVERFLOW				0b11000000
#define TIMER_COUNTER0_CAPTURE_EVENT		0b11100000

#define ADC_AUTO_TRIGGER_MASK				0b00011111

#define FREE								0
#define BUSY								1

#define SINGLE_CONVERSATION					0
#define AUTO_TRIGGER						1

#endif
