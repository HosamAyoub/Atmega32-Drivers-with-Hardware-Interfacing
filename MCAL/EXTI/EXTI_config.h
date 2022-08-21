/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: EXTI					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*EXTI_INT_SENSE_CONTROL options:
 * 1- ENALBE							2- DISABLE */
#define EXTI_INT0_ENALBE			ENALBE
#define EXTI_INT1_ENALBE			DISABLE
#define EXTI_INT2_ENALBE			DISABLE

/*EXTI_INT_SENSE_CONTROL options:
 * 1- FALLING_EDGE							2- RISING_EDGE
 * 3- LOW_LEVEL 							4- ON_CHANGE */
#define EXTI_INT0_SENSE_CONTROL		FALLING_EDGE
#define EXTI_INT1_SENSE_CONTROL		FALLING_EDGE
#define EXTI_INT2_SENSE_CONTROL		FALLING_EDGE


#endif
