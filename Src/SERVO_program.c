/*
 * SERVO_program.c
 *
 *  Created on: May 9, 2024
 *      Author: RD17
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "SERVO_interface.h"
#include <util/delay.h>


void servo_voidAngle(u16 TopValue, u16 compValue)
{

	TIMER1_voidSetTopValue(TopValue);
	TIMER1_voidSetChannelACompMatchValue(compValue);
	_delay_ms(1000);
	//TIMER1_voidSetChannelACompMatchValue(2000);


}

