#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0                *((volatile u8*)0x53)                       /*Timer0 control register*/
#define TCCR0_WGM00          6                                           /*Waveform generation mode bit0*/
#define TCCR0_WGM01          3                                           /*Waveform generation mode bit1*/
#define TCCR0_COM00          4
#define TCCR0_COM01          5
#define TCCR0_CS02           2                                           /*Prescalar bit2*/
#define TCCR0_CS01           1                                           /*Prescalar bit1*/
#define TCCR0_CS00           0                                           /*prescalar bit0*/


#define OCR0                 *((volatile u8*)0x5C)                       /*Output compare register 0*/

#define TIMSK                *((volatile u8*)0x59)                       /*Timer mask*/
#define TIMSK_OCIE0          1                                           /*Output compare 0 interrupt enable*/
#define TIMSK_TOIE0          0                                           /*Timer 0 overflow interrupt enable*/
#define TIMSK_TICIE1         5                                           /*Timer1 Input capture interrupt enable*/


#define TCCR1A               *((volatile u8*)0x4F)                       /*Timer1 control register A*/
#define TCCR1A_COM1A1        7
#define TCCR1A_COM1A0        6
#define TCCR1A_COM1B1        5
#define TCCR1A_COM1B0        4
#define TCCR1A_FOC1A         3
#define TCCR1A_FOC1B         2
#define TCCR1A_WGM11         1
#define TCCR1A_WGM10         0



#define TCCR1B               *((volatile u8*)0x4E)                       /*Timer1 control register B*/
#define TCCR1B_ICNC1         7
#define TCCR1B_ICES1         6                                           /*Input capture edge select*/
#define TCCR1B_WGM13         4
#define TCCR1B_WGM12         3
#define TCCR1B_CS12          2
#define TCCR1B_CS11          1
#define TCCR1B_CS10          0

#define TCNT0                *((volatile u8*)0x52)


#define ICR1                 *((volatile u16*)0x46)
#define OCR1A                *((volatile u16*)0x4A)
#define TCNT1                *((volatile u16*)0x4C)

#define TCCR2                *((volatile u8*)0x45)
#define TCCR2_CS20           0
#define TCCR2_CS21           1
#define TCCR2_CS22           2
#define TCCR2_WGM21          3
#define TCCR2_COM20          4
#define TCCR2_COM21          5
#define TCCR2_WGM20          6
#define TCCR2_FOC2           7

#endif
