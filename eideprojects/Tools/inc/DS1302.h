#ifndef _DS1302_H_
#define _DS1302_H_

__sbit __at(0xB0+6) DS1302_SCLK;
__sbit __at(0xB0+4) DS1302_IO;
__sbit __at(0xB0+5) DS1302_CE;

void DS1302_Init();
void DS1602_WriteByte(unsigned char Command,unsigned char Data);
unsigned char DS1602_ReadByte(unsigned char Command);

#endif // !_DS1302_H_