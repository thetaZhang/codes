/*************************************
 * 
 *        89c52 sdcc DS1302 CLK
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * 
 * ***********************************
*/

#include <reg52.h>
#include <stdio.h>
#include <LCD1602.h>
#include <DS1302.h>
#include <Delay.h>
#include <Timer0.h>


unsigned char Second,second_1,second_10,Minute,minute_1,minute_10,Hour,hour_1,hour_10;
unsigned char Date,date_1,date_10,Month,month_1,month_10,Year,year_1,year_10;
char* weekday[7]={"Mon", "Tue", "Wed", "Thu","Fri", "Sat", "Sun"};
unsigned int state=0;//显示模式，0为时间，1为日期

/**
 * @brief 在LCD上显示当前时间
 * 
 */
void ShowTime()
{
    LCD_ShowChar(2,3,':');
    LCD_ShowChar(2,6,':');

    Second=DS1302_ReadByte(0x81);
    second_1=Second&0x0F;
    LCD_ShowNum(2,8,second_1,1);
    second_10=(Second>>4)&0x07;
    LCD_ShowNum(2,7,second_10,1);   //DS1302存时间是BCD码
        
    Minute=DS1302_ReadByte(0x83);
    minute_1=Minute&0x0F;
    LCD_ShowNum(2,5,minute_1,1);
    minute_10=(Minute>>4)&0x07;
    LCD_ShowNum(2,4,minute_10,1);
        
    Hour=DS1302_ReadByte(0x85);
    hour_1=Hour&0x0F;
    LCD_ShowNum(2,2,hour_1,1);
    hour_10=(Hour>>4)&0x03;
    LCD_ShowNum(2,1,hour_10,1);

    LCD_ShowString(1,1,weekday[DS1302_ReadByte(0x8B)-1]);
}

/**
 * @brief 在LCD上显示日期
 * 
 */
void ShowDate()
{
    LCD_ShowChar(2,3,'-');
    LCD_ShowChar(2,6,'-');

    Date=DS1302_ReadByte(0x87);
    date_1=Date&0x0F;
    LCD_ShowNum(2,8,date_1,1);
    date_10=(Date>>4)&0x03;
    LCD_ShowNum(2,7,date_10,1);

    Month=DS1302_ReadByte(0x89);
    month_1=Month&0x0F;
    LCD_ShowNum(2,8,month_1,1);
    month_10=(Month>>4)&0x01;
    LCD_ShowNum(2,7,month_10,1);

    Year=DS1302_ReadByte(0x8D);
    year_1=Year&0x0F;
    LCD_ShowNum(2,8,year_1,1);
    year_10=(Year>>4)&0x0F;
    LCD_ShowNum(2,7,year_10,1);

    LCD_ShowString(1,1,weekday[DS1302_ReadByte(0x8B)-1]); 
}
/**
 * @brief 定时器中断处理
 * 
 */
void Timer0_Routine()  interrupt 1
{
    static unsigned int T0Count;//计时器计数
    TH0=64535/256;
    TL0=64535%256;
    T0Count++;
    if(T0Count>=1000)
    {
       //在这里写上中断处理内容
        
       //
        T0Count=0;
        
    }
}

void main()
{
    LCD_Init();
    DS1302_Init();
    Timer0_Init();
    DS1302_WriteByte(0x80,0x00);
    DS1302_WriteByte(0x82,0x00);
    DS1302_WriteByte(0x84,0x00);
    DS1302_WriteByte(0x86,0x00);
    DS1302_WriteByte(0x88,0x00);
    DS1302_WriteByte(0x8C,0x00);
    DS1302_WriteByte(0x8A,0x01);
    

    while (1)
    {
        if(state==0){
            ShowTime();
        }
        else {
            ShowDate();
        }
        Delay_ms(10);
    }
}

