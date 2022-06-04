/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

/********************			Timer0 Functions			*********************************/
void TIMERS_voidTimer0Init (void);
void TIMERS_voidTimer0SetCompareMatchValue (u8 Copy_u8CompareMatchValue);
void TIMERS_voidTimer0SetPreloadValue (u8 Copy_u8PreloadValue);
void TIMERS_voidTimer0CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer0OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer0Delay_us (f32 Copy_f32MicroSeconds);

/********************			Timer1 Functions			*********************************/
void TIMERS_voidTimer1Init (void);
void TIMERS_voidTimer1SetPreloadValue (u16 Copy_u16PreloadValue);
void TIMERS_voidTimer1SetTopValue (u16 Copy_u16OverflowValue);
void TIMERS_voidTimer1SetChannelACompareMatchValue (u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1SetCTCAInterruptControl (u8 Copy_u8InterruptState);
void TIMERS_voidTimer1SetChannelBCompareMatchValue (u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1SetCTCBInterruptControl (u8 Copy_u8InterruptState);
void TIMERS_voidTimer1ICUSetSenseControl (u8 Copy_u8SenseControl);
void TIMERS_voidTimer1ICUInterruptControl (u8 Copy_u8InterruptState);
u16  TIMERS_u16Timer1ICUReadInputCapture (void);
void TIMERS_voidTimer1ICUSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer1CTCASetCallbackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer1CTCBSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer1OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void));

/********************			Timer2 Functions			*********************************/
void TIMERS_voidTimer2Init (void);
void TIMERS_voidTimer2SetCompareMatchValue (u8 Copy_u8CompareMatchValue);
void TIMERS_voidTimer2SetPreloadValue (u8 Copy_u8PreloadValue);
void TIMERS_voidTimer2CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer2OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void));


/*Timer1 ICU Sense Control Options*/
#define TIMERS_FALLING_EDGE				0
#define TIMERS_RISING_EDGE				1

/*Interrupt State Options*/
#define TIMERS_DISABLE					0
#define TIMERS_ENABLE					1

#endif
