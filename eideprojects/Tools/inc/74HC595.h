#ifndef _74HC595_H_
#define _74HC595_H_
__sbit __at(0xB0+5) RCK;  //RCLK
__sbit __at(0xB0+6) SCK;  //SRCLK
__sbit __at(0xB0+4) SER;  //SER
void _74HC595_Init();
void _74HC595_WriteByte(unsigned char Byte);
#endif // !_74HC595_H_