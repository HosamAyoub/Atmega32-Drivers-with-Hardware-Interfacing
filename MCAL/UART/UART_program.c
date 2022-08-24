/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: UART					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"


void USART_voidInit (void)
{
//	SET_BIT(UCSRC, UCSRC_URSEL);
//
//	SET_BIT(UCSRC, UCSRC_UCSZ0);
//	SET_BIT(UCSRC, UCSRC_UCSZ1);
//	CLR_BIT(UCSRB, UCSRB_UCSZ2);
//
//	CLR_BIT(UCSRC, UCSRC_USBS);
//
//	CLR_BIT(UCSRC, UCSRC_UPM0);
//	CLR_BIT(UCSRC, UCSRC_UPM1);
//
//	CLR_BIT(UCSRC, UCSRC_UMSEL);
//
//	UBRRL = 51;
//
//	CLR_BIT(UBRRH, UCSRC_URSEL);
//	UBRRH = 0;
//
//	SET_BIT(UCSRB, UCSRB_TXEN);
//	SET_BIT(UCSRB, UCSRB_RXEN);
	   /*Set Bit URSEL To Write On UCSRC*/
	u8 Local_u8UCSRC;
	    SET_BIT(Local_u8UCSRC, UCSRC_URSEL);
	    /*Data Size = 8-bit*/
	    SET_BIT(Local_u8UCSRC, UCSRC_UCSZ0);
	    SET_BIT(Local_u8UCSRC, UCSRC_UCSZ1);
	    CLR_BIT(UCSRB, UCSRB_UCSZ2);

	    /*Stop bit = 1-bit*/
	    CLR_BIT(Local_u8UCSRC, UCSRC_USBS);

	    /*Parity Mode = Disabled*/
	    CLR_BIT(Local_u8UCSRC, UCSRC_UPM0);
	    CLR_BIT(Local_u8UCSRC, UCSRC_UPM1);

	    /*USART Mode = Asychnronous*/
	    CLR_BIT(Local_u8UCSRC, UCSRC_UMSEL);

	    /*BaudRate = 9600*/
	    UBRRL = 51;
	    /*Clear Bit URSEL To Write On UBRRH*/
	    CLR_BIT(UBRRH, UBRRH_URSEL);            // CLR_BIT(UCSRC, UCSRC_URSEL);
	    UBRRH = 0;

	    /*Enable Trasmitter & Receiver Circuits*/
	    SET_BIT(UCSRB, UCSRB_TXEN);
	    SET_BIT(UCSRB, UCSRB_RXEN);
	    UCSRC = Local_u8UCSRC;
}

void USART_voidTransmitData (u8 Copy_u8Data)
{

	while (GET_BIT(UCSRA, UCSRA_UDRE) == 0);	// or while (!GET_BIT(UCSRA, UCSRA_UDRE));

	UDR = Copy_u8Data;

//	while (GET_BIT(UCSRA, UCSRA_TXC) == 0);		// or while (!GET_BIT(UCSRA, UCSRA_TXC));
}


void USART_voidReceiveData (u8 *Copy_pu8CopyReceiveData)
{

	while (GET_BIT(UCSRA, UCSRA_RXC) == 0);		// or while (!GET_BIT(UCSRA, UCSRA_RXC));
	*Copy_pu8CopyReceiveData = UDR;
//	return UDR;
}
