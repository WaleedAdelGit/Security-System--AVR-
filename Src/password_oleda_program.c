/*
 * password_oleda_program.c
 *
 *  Created on: May 14, 2024
 *      Author: RD17
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "TWI_interface.h"
#include "OLED_interface.h"
#include "OLED_config.h"
#include "USART_inteerface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "STEPPER_MOTOR_interface.h"
#include "STEPPER_MOTOR_config.h"
#include "SERVO_interface.h"
#include "password_oleda_config.h"


void buzzer_void(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
	_delay_ms(500);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_LOW);

}




void Password_oleda_wrong_input(u8 counter)
{
	OLED_VoidSetPosition(0,5);
	_delay_ms(10);
	buzzer_void();
	OLED_voidSendString("Wrong input,Try again");
	_delay_ms(1000);
	OLED_VoidClear_Some_of_Screen(0,5);
	_delay_ms(10);
	OLED_VoidClear_Some_of_Screen(0,5);
	_delay_ms(10);

}

void Password_oleda_Byebye(void)
{
	OLED_voidSendString("Bye Bye");
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
}

void Password_oleda_order_clear(u8* counter, u8* charcter_position, u8 screen_position)
{
	if(*charcter_position<102)
	{
		int var = (*charcter_position-(*counter*6));
		if(*counter>0 && *charcter_position>var)
		{
			OLED_VoidClear_Some_of_Screen(*charcter_position-6,screen_position);
			*counter=*counter-1;
			*charcter_position-=6;
		}
	}
}


