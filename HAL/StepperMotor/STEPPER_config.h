/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: STEPPER				*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef HAL_STEPPER_STEPPER_CONFIG_H_
#define HAL_STEPPER_STEPPER_CONFIG_H_

/* Port options:
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD */
#define STEPPER_PORT				DIO_PORTA
/* PIN options:
 * DIO_PIN0 : DIO_PIN7 */
#define STEPPER_BLUE_PIN			DIO_PIN0
#define STEPPER_PINK_PIN			DIO_PIN1
#define STEPPER_YELLOW_PIN			DIO_PIN2
#define STEPPER_ORANGE_PIN			DIO_PIN3

/* Rotation options:
 * 1- CLOCKWISE
 * 2- COUNTER_CLOCKWISE */
#define STEPPER_ROTATION			CLOCKWISE

/* Delay options:
 * delay between each step start from 2 */
#define STEPPER_STEP_DELAY			5

#endif
