/*
 * USART_program.c
 *
 *  Created on: Mar 13, 2024
 *      Author: Adel
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_register.h"
#include "USART_inteerface.h"
#include "USART_config.h"


void USART_voidInit(void)
{
 u8 Local_u8UCSRCValue=0;
 SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);


 CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);

 CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
 CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);

 CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);

 SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
 SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);

 UCSRC=Local_u8UCSRCValue;
 UBRRL= 51;

 SET_BIT(UCSRB,UCSRB_TXEN);
 SET_BIT(UCSRB,UCSRB_RXEN);
}


u8 USART_voidRecieveData(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}

void USART_voidSend(u8 copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE==0));
	UDR=copy_u8Data;

}

/*u8 USART_intUBRRLCalc(void)
{
	u16 Local_u16UBRRL=0;
	Local_u16UBRRL=(u16)(SysFreq/16*BaudRate)-1;
	return Local_u16UBRRL;

}*/
