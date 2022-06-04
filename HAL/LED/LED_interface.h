/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LED					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


void LED_voidInitLED (u8 Copy_u8ID, u8 Copy_u8Port, u8 Copy_u8Pin);
/*Initialise Port of LEDS or some LEDS less than 8 in a single port*/
void LED_voidInitGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID, u8 Copy_u8Port, u8 Copy_u8Pin);
void LED_voidTurnOnLED (u8 Copy_u8ID);
void LED_voidTurnOnGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID);
void LED_voidTurnOffLED (u8 Copy_u8ID);
void LED_voidTurnOffGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID);
void LED_voidToggleLED (u8 Copy_u8ID);
void LED_voidToggleGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID);
void LED_voidBlinkLED (u8 Copy_u8ID, u16 Copy_u16Delay, u8 Copy_u8DelayType);

/*Delay Types*/
#define LED_MILLI_SECOND				0
#define LED_MICRO_SECOND				1

#endif
