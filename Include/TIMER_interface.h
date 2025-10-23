#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define ICU_RISING_EDGE      1
#define ICU_FALLING_EDGE     0



void TIMER0_voidInit(void);

void TIMER1_voidInit(void);

void TIMER2_voidInit(void);

void TIMER1_voidSetTopValue(u16 Copy_u16Value);

void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value);

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);

u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

u16 TIMER1_u16ReadTimerValue(void);

u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge);

void ICU_voidInit(void);

void ICU_voidEnableInterrupt(void);

void ICU_voidDisableInterrupt(void);

u16 ICU_u16ReadInputCapture(void);

u8 ICU_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

u8 TIMER0_u8ReadTimerValue(void);

void TIMER0_voidSetTimerValue(u8 Copy_u8Value);


#endif
