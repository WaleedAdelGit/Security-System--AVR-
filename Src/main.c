/*
 * OLED_program.c
 *
 *  Created on: Apr 28, 2024
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
#include "STEPPER_interface.h"
#include "SERVO_interface.h"
#include "password_oleda_config.h"
#include "password_oleda_interface.h"

static u8 *ptr1=NULL,*ptr2=NULL ;
u8 App_u8ADCReading=0;

void ADCNotification (void);

void main(void)
{


	u8 Local_u8Data=0xFF;
	u8 Local_u8arr1[6],Local_u8arr2[6],Local_u8arr3[18];//,Local_u8arr4[11],Local_u8arr5[14],Local_u8arr6[17];
	u8 arr_ID[7]="waleed";
	u8 arr_password[7]="123456";
	u8 arr_Stepper1[]="door open",arr_Stepper2[]="door close";
	u8 arr_temprature1[]="get temp",arr_LED1[]="led on",arr_LED2[]="led off";

	static u8 i=0,j=0,One_loop_count=0,One_loop_count2=0,One_loop_count3=0,ID_Pass_count=0,Ok_count=0,Ok_count2=0,Ok_count3=0,counter=0,counter2=0,counter3=0,charcter_position=charcter_position_ID,sec_line_counter=0,order_counter=0;
	u16 Local_u16ADCReading=0;
	u16 Local_u16Temp=0;


	OLED_voidTWIInit();

	PORT_voidInit();
	ADC_voidInit();
	TIMER1_voidInit();
	USART_voidInit();
	GIE_voidEnable();


	OLED_voidSendString("Enter ID:");

	servo_voidAngle(20000,1000);
	Stepper_u8CW(360.0);



	while(1)
	{
		Local_u8Data=USART_voidRecieveData();

		if(Local_u8Data!=0xFF && ID_Pass_count==0)
		{

			if(Local_u8Data!=13 && Local_u8Data!=127 && One_loop_count<3)
			{

				Local_u8arr1[counter]=Local_u8Data;
				counter++;
				USART_voidSend('D');
				OLED_VoidSetPosition(charcter_position,1);
				charcter_position+=6;
				OLED_voidSend_one_character(Local_u8Data);

			}
			else if(Local_u8Data==127)
			{
				ptr1=&counter;
				ptr2=&charcter_position;
				Password_oleda_order_clear(ptr1,ptr2,1);
			}

			else if(Local_u8Data==13)
			{
				if(counter==6)
				{
					for(u8 i=0;i<6;i++)//check ID
					{
						if(Local_u8arr1[i]==arr_ID[i])
						{
							Ok_count++;
						}
					}
					if(Ok_count==6)
					{
						while(i<1)
						{

							OLED_VoidSetPosition(0,3);
							OLED_voidSendString("Enter password:");
							i++;
							_delay_ms(10);
							ID_Pass_count++;
							One_loop_count=0;
							charcter_position=charcter_position_password;
						}
					}
					else if(Ok_count!=6)
					{
						Ok_count=0;
						if(One_loop_count<3)
						{
							Password_oleda_wrong_input();
							One_loop_count++;
							if(One_loop_count==3)
							{
								OLED_VoidClearScreen();
								Password_oleda_Byebye();
								break;
							}
							counter=0;
							charcter_position=charcter_position_ID;
							OLED_VoidClear_Some_of_Screen(charcter_position,1);
							sec_line_counter=0;

						}

					}


				}
				else if(counter!=6)
				{
					if(One_loop_count<3)
					{
						Password_oleda_wrong_input();
						One_loop_count++;
						if(One_loop_count==3)
						{
							OLED_VoidClearScreen();
							Password_oleda_Byebye();
							break;
						}
						counter=0;
						charcter_position=charcter_position_ID;
						OLED_VoidClear_Some_of_Screen(charcter_position,1);
						sec_line_counter=0;
					}

				}
			}

		}

		else if(Local_u8Data!=0xFF && ID_Pass_count==1)
		{

			if(Local_u8Data!=13 && Local_u8Data!=127)
			{

				Local_u8arr2[counter2]=Local_u8Data;
				counter2++;
				USART_voidSend('D');
				OLED_VoidSetPosition(charcter_position,4);
				charcter_position+=6;
				OLED_voidSend_one_character('*');

			}
			else if(Local_u8Data==127)
			{
				ptr1=&counter2;
				ptr2=&charcter_position;
				Password_oleda_order_clear(ptr1,ptr2,4);
			}
			else if(Local_u8Data==13)
			{
				if(counter2==6)
				{
					for(u8 i=0;i<6;i++)//check Password
					{
						if(Local_u8arr2[i]==arr_password[i])
						{
							Ok_count2++;
						}
					}
					if(Ok_count2==6)
					{

						OLED_VoidClearScreen();
						_delay_ms(10);
						OLED_VoidSetPosition(0,1);
						OLED_voidSendString("Welcome Waleed");
						ID_Pass_count++;
						sec_line_counter=0;
						charcter_position=charcter_position_order;
						_delay_ms(5);
						servo_voidAngle(20000,2000);
						order_counter=0;
						while(j<1)
						{
							OLED_VoidSetPosition(0,3);
							OLED_voidSendString("Enter ORDER :");
							j++;
						}

					}
					else if(Ok_count2!=6)
					{
						Ok_count2=0;
						if(One_loop_count2<3)
						{
							Password_oleda_wrong_input();

							One_loop_count++;
							if(One_loop_count==3)
							{
								OLED_VoidClearScreen();
								Password_oleda_Byebye();
								break;
							}
							counter2=0;
							charcter_position=charcter_position_password;
							OLED_VoidClear_Some_of_Screen(charcter_position,4);
							sec_line_counter=0;

						}
					}


				}

				else if(counter2!=6)
				{
					if(One_loop_count2<3)
					{
						Password_oleda_wrong_input();

						One_loop_count++;
						counter2=0;
						if(One_loop_count==3)
						{
							OLED_VoidClearScreen();
							Password_oleda_Byebye();
							break;
						}
						charcter_position=charcter_position_password;
						OLED_VoidClear_Some_of_Screen(charcter_position,4);
						sec_line_counter=0;
					}
				}
			}

		}
		else if(Local_u8Data!=0xFF && ID_Pass_count==2)
		{
			if(Local_u8Data!=13 && Local_u8Data != 127)
			{
				if(counter3==0)
				{
					OLED_VoidClear_Some_of_Screen(0,5);
					OLED_VoidSetPosition(0,4);
					charcter_position=0;
				}
				Local_u8arr3[counter3]=Local_u8Data;
				counter3++;
				USART_voidSend('D');
				OLED_VoidSetPosition(charcter_position,5);
				charcter_position+=6;
				OLED_voidSend_one_character(Local_u8Data);

			}
			else if(Local_u8Data==127)
			{
				ptr1=&counter3;
				ptr2=&charcter_position;
				Password_oleda_order_clear(ptr1,ptr2,5);
			}

			else if(Local_u8Data==13)
			{
				_delay_ms(1000);
				OLED_VoidClear_Some_of_Screen(0,5);
				switch(counter3)
				{

				case 6:
					if(order_counter==1)
					{
						charcter_position=charcter_position_order;
						counter3=0;
						break;
					}
					else if(order_counter!=1)
					{
						for(u8 i=0;i<6;i++)//check Order
						{
							if(Local_u8arr3[i]==arr_LED1[i])
							{
								Ok_count3++;
							}
						}
						if(Ok_count3==6)
						{
							counter3=0;
							Ok_count3=0;
							order_counter=1;

							DIO_u8SetPortValue(DIO_u8PORTA,0xF0);

							//charcter_position=charcter_position_order;
						}
						else if(Ok_count3!=6)
						{
							Ok_count3=0;
							if(One_loop_count3<3)
							{

								Password_oleda_wrong_input();

								One_loop_count3++;
								if(One_loop_count==3)
								{
									OLED_VoidClearScreen();
									Password_oleda_Byebye();
									break;
								}
								counter3=0;
								charcter_position=charcter_position_order;
								sec_line_counter=0;
							}

						}
					}
					else
					{
						break;

					}

					break;

				case 7:
					if(order_counter==2)
					{
						charcter_position=charcter_position_order;
						counter3=0;
						break;
					}
					else if(order_counter!=2)
					{

						for(u8 i=0;i<7;i++)//check Order
						{
							if(Local_u8arr3[i]==arr_LED2[i])
							{
								Ok_count3++;
							}
						}
						if(Ok_count3==7)
						{

							counter3=0;
							Ok_count3=0;
							DIO_u8SetPortValue(DIO_u8PORTA,0x00);
							order_counter=2;
							//charcter_position=charcter_position_order;

						}
						else if(Ok_count3!=7)
						{
							Ok_count3=0;
							if(One_loop_count3<3)
							{
								Password_oleda_wrong_input();

								One_loop_count3++;
								if(One_loop_count==3)
								{
									OLED_VoidClearScreen();
									Password_oleda_Byebye();
									break;
								}
								counter3=0;
								charcter_position=charcter_position_order;
							}

						}
					}
					else{
						break;
					}
					break;

				case 8:
					if(order_counter==3)
					{
						charcter_position=charcter_position_order;
						counter3=0;
						break;
					}
					else if(order_counter !=3)
					{
						for(u8 i=0;i<8;i++)//check Order
						{
							if(Local_u8arr3[i]==arr_temprature1[i])
							{
								Ok_count3++;
							}
						}
						if(Ok_count3==8)
						{
							counter3=0;
							Ok_count3=0;
							order_counter=3;


							OLED_VoidClear_Some_of_Screen(0,6);
							OLED_VoidSetPosition(0,6);
							ADC_u8StartConversionAsynch(0,&App_u8ADCReading,&ADCNotification);
							_delay_ms(500);


						}
						else if(Ok_count3!=8)
						{
							Ok_count3=0;
							if(One_loop_count3<3)
							{
								Password_oleda_wrong_input();
								One_loop_count3++;
								if(One_loop_count==3)
								{
									OLED_VoidClearScreen();
									Password_oleda_Byebye();
									break;
								}
								counter3=0;
								charcter_position=charcter_position_order;
							}

							break;

						}
						break;



				case 9:
					if(order_counter==4)
					{
						charcter_position=charcter_position_order;
						counter3=0;
						break;
					}
					else if(order_counter!=4)
					{
						for(u8 i=0;i<9;i++)//check Order
						{
							if(Local_u8arr3[i]==arr_Stepper1[i])
							{
								Ok_count3++;
							}
						}
						if(Ok_count3==9)
						{
							Stepper_u8CW(0);
							counter3=0;
							Ok_count3=0;
							order_counter=4;
						}
						else if(Ok_count3!=9)
						{
							Ok_count3=0;
							if(One_loop_count3<3)
							{
								Password_oleda_wrong_input();

								One_loop_count3++;
								if(One_loop_count==3)
								{
									OLED_VoidClearScreen();
									Password_oleda_Byebye();
									break;
								}
								counter3=0;
								charcter_position=charcter_position_order;
							}

						}
					}

					break;

				case 10:
					if(order_counter==5)
					{
						charcter_position=charcter_position_order;
						counter3=0;
						break;
					}
					else if(order_counter!=5)
					{
						for(u8 i=0;i<10;i++)//check Order
						{
							if(Local_u8arr3[i]==arr_Stepper2[i])
							{
								Ok_count3++;
							}
						}
						if(Ok_count3==10)
						{
							Stepper_u8CW(360.0);
							counter3=0;
							Ok_count3=0;
							order_counter=5;
						}
						else if(Ok_count3!=10)
						{
							Ok_count3=0;
							if(One_loop_count3<3)
							{
								Password_oleda_wrong_input();

								One_loop_count3++;
								if(One_loop_count==3)
								{
									OLED_VoidClearScreen();
									Password_oleda_Byebye();
									break;
								}
								counter3=0;
								charcter_position=charcter_position_order;
							}

							break;
						}
					}

					break;


				default:
					Ok_count3=0;
					if(One_loop_count3<3)
					{
						Password_oleda_wrong_input();

						One_loop_count3++;
						if(One_loop_count==3)
						{
							OLED_VoidClearScreen();
							Password_oleda_Byebye();
							break;
						}
						counter3=0;
						charcter_position=charcter_position_order;
						sec_line_counter=0;
					}

					break;
					}
				}
			}


		}
	}
}



void ADCNotification(void)
{
	u16 Local_u16Temp = (u16)(500UL* (u32)App_u8ADCReading)/256UL;

	Local_u16Temp=Local_u16Temp/10;

	OLED_write_number(Local_u16Temp);
	OLED_VoidWriteChar(C);
	_delay_ms(1000);
}




