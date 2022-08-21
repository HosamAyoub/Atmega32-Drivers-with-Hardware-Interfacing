/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: GIE					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
#include "GIE_private.h"
#include "GIE_config.h"

/* This function Enable the Global Interrupt */
void GIE_voidEnableGlobalInterrupt(void);
/* This function Disable the Global Interrupt */
void GIE_voidDisableGlobalInterrupt(void);

#endif
