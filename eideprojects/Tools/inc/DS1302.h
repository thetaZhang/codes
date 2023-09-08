#ifndef _DS1302_H_
#define _DS1302_H_

__sbit __at(0xB0+6) DS1302_SCLK;
__sbit __at(0xB0+4) DS1302_IO;
__sbit __at(0xB0+5) DS1302_CE;

extern unsigned int DS1302_Time[]; //存储时间，年月日时分秒星期

void DS1302_Init();
void DS1302_WriteByte(unsigned char Command,unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);
void DS1302_SetTime();
void DS1302_ReadTime();

#endif // !_DS1302_H_