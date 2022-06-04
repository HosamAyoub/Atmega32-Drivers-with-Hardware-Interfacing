/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: ADC					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit (void);

/*Options: 1- CHANNEL0		2- CHANNEL1		3- CHANNEL2		4- CHANNEL3
 * 5- CHANNEL4		6- CHANNEL5		7- CHANNEL6		8- CHANNEL7*/
u16 ADC_u8GetChannelReadingSynchronous (u8 Copy_u8Channel);
u16 ADC_u8GetChannelReadingAsynchronous (u8 Copy_u8Channel, void (*Copy_pvCallBackFunction) (void));

#define CHANNEL0		0
#define CHANNEL1		1
#define CHANNEL2		2
#define CHANNEL3		3
#define CHANNEL4		4
#define CHANNEL5		5
#define CHANNEL6		6
#define CHANNEL7		7


#endif
