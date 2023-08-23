#include <DS1302.h>
#include <reg52.h>
#include <stdio.h>

/**
 * @brief DS1302初始化
 * 
 */
void DS1302_Init()
{
   DS1302_CE=0;
   DS1302_SCLK=0;

}
/**
 * @brief DS1302写入byte
 * 
 * @param Command 命令字
 * @param Data 要写入的数据
 */
void DS1302_WriteByte(unsigned char Command,unsigned char Data)
{
    DS1302_CE=1;
    for (int i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<i);
        DS1302_SCLK=1;
        DS1302_SCLK=0;
    }

    for (int i=0;i<8;i++)
    {
        DS1302_IO=Data&(0x01<<i);
        DS1302_SCLK=1;
        DS1302_SCLK=0;
    }
    DS1302_CE=0;
}

/**
 * @brief DS1302读出byte
 * 
 * @param Command 命令字
 * @return unsigned char 读出的byte
 */
unsigned char DS1302_ReadByte(unsigned char Command)
{
    unsigned char Data=0x00;
    for (int i=0;i<8;i++)
    {
        DS1302_IO=Command&(0x01<<i);
        DS1302_SCLK=0;
        DS1302_SCLK=1;    //输入是上升沿，输出是下降沿，为了让时序中间分开，故这样操作
    }

    for (int i=0;i<8;i++)
    {
        DS1302_SCLK=1;
        DS1302_SCLK=0;
        if (DS1302_IO) {Data|=(0x01<<i);}
    }
    DS1302_CE=0;
    return Data;
}