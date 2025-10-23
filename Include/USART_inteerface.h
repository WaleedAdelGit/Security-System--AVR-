/*
 * USART_inteerface.h
 *
 *  Created on: Mar 13, 2024
 *      Author: Adel
 */

#ifndef USART_INTEERFACE_H_
#define USART_INTEERFACE_H_

void USART_voidInit(void);
u8 USART_voidRecieveData(void);
void USART_voidSend(u8 copy_u8Data);
u8 USART_intUBRRLCalc(void);


#endif /* USART_INTEERFACE_H_ */
