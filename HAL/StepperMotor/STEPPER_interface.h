/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: STEPPER				*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

/* This function make the stepper motor rotate for specific angle
 * Arguments: Direction (STEPPER_CLOCKWISE - STEPPER_COUNTER_CLOCKWISE) - Angle (in degree)
 * Return: Error states (OK - ERROR) */
u8 STEPPER_u8Rotate (u8 Copy_u8Direction, u16 Copy_u16Angle);

#define STEPPER_CLOCKWISE					0
#define STEPPER_COUNTER_CLOCKWISE			1

#endif
