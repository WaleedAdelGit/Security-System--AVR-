
#ifndef OLED_INTERFACE_H_
#define OLED_INTERFACE_H_





void OLED_VoidInit(void);
void OLED_voidTWIInit(void);
void OLED_VoidSendCommand(u8 command);
void OLED_VoidWriteChar(u8 character);
void OLED_write_one_number(u8 number);
void OLED_write_number(u32 Copy_u32Number);
void OLED_VoidSendData(u8 data);
void OLED_VoidSetPosition(u8 x, u8 y);
void OLED_VoidClearScreen(void);
void OLED_VoidClearDisplaybuffer(void);
void clear_display_buffer();
void OLED_Void_Update_Display(void);
void OLED_VoidexrtraInit(void);
void OLED_voidSendString(const char* Copy_pcString);
void OLED_voidSend_one_character(u8 character);
void OLED_VoidClear_Some_of_Screen(u8 col,u8 page);



#endif  OLED_INTERFACE_H_

