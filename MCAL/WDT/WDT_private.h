/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: WDT					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#define WDTCR				(*((volatile u8*) 0x41))	// Watch Dog timer control register
#define WDTCR_WDP0			0							// Watch Dog timer prescaler bit 0
#define WDTCR_WDP1			1							// Watch Dog timer prescaler bit 1
#define WDTCR_WDP2			2							// Watch Dog timer prescaler bit 2
#define WDTCR_WDE			3							// Watch Dog timer enable bit
#define WDTCR_WDTOE			4							// Watch Dog timer turn off enable

#define PRESCALER_MASK		0b11111000

#endif
