#include <reg52.h>
#include <stdio.h>
#include <74HC595.h>
/**
 * @brief 74HC595初始化函数 
 * 
 */
void _74HC595_Init()
{
    RCK=0;
    SCK=0;    //上电后默认都为高电平，先让它为0，便于给时钟上升沿信号
}

/**
 * @brief 74HC595写入函数，将串行数据并行输出
 * 
 * @param Byte 要写入的8位二进制数据
 */
void _74HC595_WriteByte(unsigned char Byte)
{
    for (unsigned int i = 0; i <8; i++)
    {
        SER=Byte&(0x80>>i);
        SCK=1;
        SCK=0;
    }
    RCK=1;
    RCK=0;
}