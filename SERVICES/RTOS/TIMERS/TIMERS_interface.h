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

void TIMERS_voidTimer0Init (void);
void TIMERS_voidTimer1Init (void);
void TIMERS_voidTimer1SetOverflowValue (u16 Copy_u16OverflowValue);
void TIMERS_voidTimer0SetCompareMatchValue (u8 Copy_u8CompareMatchValue);
void TIMERS_voidTimer1SetChannelACompareMatchValue (u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1SetChannelBCompareMatchValue (u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer0SetPreloadhValue (u8 Copy_u8PreloadValue);
void TIMERS_voidTimer0CTCSetCallBackFunction (void (*Copy_pvCTCFunction) (void));
void TIMERS_voidTimer1CTCSetCallBackFunction (void (*Copy_pvCTCFunction) (void));

#endif
