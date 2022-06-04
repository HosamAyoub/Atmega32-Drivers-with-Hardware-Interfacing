/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: ADC					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*
 * Options:
 * 1- CHANNEL0
 * 2- CHANNEL1
 * 3- CHANNEL2
 * 4- CHANNEL3
 * 5- CHANNEL4
 * 6- CHANNEL5
 * 7- CHANNEL6
 * 8- CHANNEL7
 */
#define ADC_CHANNEL					CHANNEL0

/*
 * Options:
 * 1- TEN_BITS
 * 2- EIGHT_BITS
 */
#define ADC_NUMBER_OF_BITS			TEN_BITS

/*
 * Options:
 * 1- AREF
 * 2- AVCC
 * 3- REVERSED
 * 4- INTERNAL
 */
#define ADC_REF_VOLTAGE				AVCC

/*
 * Options:
 * 1- DISABLE
 * 2- ENABLE
 */
#define ADC_ENABLE					ENABLE
#define ADC_INTERRUPT_MODE    		DISABLE

/*
 * Options:
 * 1- SINGLE_CONVERSATION
 * 2- AUTO_TRIGGER*/
#define ADC_MODE					SINGLE_CONVERSATION

/*
 * Options:
 * 1- PRESCALER_DIV_BY_2
 * 2- PRESCALER_DIV_BY_4
 * 3- PRESCALER_DIV_BY_8
 * 4- PRESCALER_DIV_BY_16
 * 5- PRESCALER_DIV_BY_32
 * 6- PRESCALER_DIV_BY_64
 * 7- PRESCALER_DIV_BY_128
 */
#define ADC_PRESCALER				PRESCALER_DIV_BY_64

/*
 * Options:
 * 1- FREE_RUNNING_MODE
 * 2- ANALOG_COMPARATOR
 * 3- EXTERNAL_INTERRUPT
 * 4- TIMER_COUNTER0_COMPARE_MATCH
 * 5- TIMER_COUNTER0_OVERFLOW
 * 6- TIMER_COUNTER_COMPARE_MATCH_B
 * 7- TIMER_COUNTER1_OVERFLOW
 * 8- TIMER_COUNTER0_CAPTURE_EVENT
 */
#define ADC_AUTO_TRIGGER			FREE_RUNNING_MODE

#endif
