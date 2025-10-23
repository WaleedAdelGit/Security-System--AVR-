#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* Copy_pu8Reading);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void));

s32 ADC_u32Mapping(s32 Input_min, s32 Input_max, s32 Output_min, s32 Output_max, s32 Input_val);






#endif
