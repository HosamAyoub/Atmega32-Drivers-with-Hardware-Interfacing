/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.10				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#define FALLING_EDGE	0
#define RISING_EDGE		1
#define LOW_LEVEL		2
#define ON_CHANGE		3

/* In this driver I make it have two option:
 * first option is the pre-build configuration and second option is post-build configurations*/

/* These functions is responsible of set the sense control for all EXTI to be:
 * (FALLING_EDGE - RISING_EDGE - LOW_LEVEL - ON_CHANGE) and return the Error states 0 for OK and 1 for ERROR
 * Returns: Error states (OK - ERROR) */
u8 EXTI_u8SetInt0SenseControl (u8 Copy_u8SenseControl);
u8 EXTI_u8SetInt1SenseControl (u8 Copy_u8SenseControl);
u8 EXTI_u8SetInt2SenseControl (u8 Copy_u8SenseControl);
/* This function is responsible for set the EXTI settings pre-build configuration*/
void EXTI_voidInit (void);
/* These are the call back functions for all EXTI
 * Arguments: pointer to function which will be called in the ISR
 * Returns: Error states (OK - ERROR) */
u8 EXTI_u8Int0SetCallBack (void (*Copy_pvNotificationFunction) (void));
u8 EXTI_u8Int1SetCallBack (void (*Copy_pvNotificationFunction) (void));
u8 EXTI_u8Int2SetCallBack (void (*Copy_pvNotificationFunction) (void));

#define ENABLE			0
#define DISABLE			1

#endif
