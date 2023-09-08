#include <DS1302.h>
#include <reg52.h>
#include <stdio.h>

#define DS1302_SECOND   0x80
#define DS1302_MINUTE   0x82
#define DS1302_HOUR     0x84
#define DS1302_DATE     0x86
#define DS1302_MONTH    0x88
#define DS1302_DAY      0x8A
#define DS1302_YEAR     0x8C
#define DS1302_WP       0x8E //写保护

unsigned int DS1302_Time[7]={0,0,0,0,0,0,1};   //全局变量，在c中定义，在h中声明为extern，则不会重定义

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
    DS1302_CE=1;
    Command|=0x01; //这样只要给写的地址就行了，用最上面的宏定义，给一个写的，这里自动变成对应的读的
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
    DS1302_IO=0;
    return Data;
}

/**
 * @brief 设置时间函数
 * 
 */
void DS1302_SetTime()
{
    DS1302_WriteByte(DS1302_WP,0x00);//关闭写保护
    DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
    DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
    DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
    DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
    DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
    DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
    DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);  
}

/**
 * @brief 读取时间函数，存储在全局变量Time中
 * 
 */
void DS1302_ReadTime()
{
    unsigned char tmp;
    tmp=DS1302_ReadByte(DS1302_YEAR);DS1302_Time[0]=tmp/16*10+tmp%16;
    tmp=DS1302_ReadByte(DS1302_MONTH);DS1302_Time[1]=tmp/16*10+tmp%16;
    tmp=DS1302_ReadByte(DS1302_DATE);DS1302_Time[2]=tmp/16*10+tmp%16;
    tmp=DS1302_ReadByte(DS1302_HOUR);DS1302_Time[3]=tmp/16*10+tmp%16;
    tmp=DS1302_ReadByte(DS1302_MINUTE);DS1302_Time[4]=tmp/16*10+tmp%16;
    tmp=DS1302_ReadByte(DS1302_SECOND);DS1302_Time[5]=tmp/16*10+tmp%16;
    tmp=DS1302_ReadByte(DS1302_DAY);DS1302_Time[6]=tmp/16*10+tmp%16;

}