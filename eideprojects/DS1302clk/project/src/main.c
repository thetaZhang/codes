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



unsigned char Second,Minute,Hour;
unsigned char Date,Month,Year;
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
    Second=(Second/16)*10+Second%16; //BCD码转十进制
    LCD_ShowNum(2,7,Second,2);
        
    Minute=DS1302_ReadByte(0x83);
    Minute=(Minute/16)*10+Minute%16;
    LCD_ShowNum(2,4,Minute,2);
        
    Hour=DS1302_ReadByte(0x85);
    Hour=(Hour/16)*10+Hour%16;
    LCD_ShowNum(2,1,Hour,2);

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
    Date=(Date/16)*10+Date%16;
    LCD_ShowNum(2,7,Date,2);

    Month=DS1302_ReadByte(0x89);
    Month=(Month/16)*10+Month%16;
    LCD_ShowNum(2,4,Month,2);

    Year=DS1302_ReadByte(0x8D);
    Year=(Year/16)*10+Year%16;
    LCD_ShowNum(2,1,Year,2);

    LCD_ShowString(1,1,weekday[DS1302_ReadByte(0x8B)-1]); 
}


void main()
{
    LCD_Init();
    DS1302_Init();
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

