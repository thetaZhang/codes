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

unsigned char Second,second_1,second_10,Minute,minute_1,minute_10,Hour,hour_1,hour_10;

void main()
{
    LCD_Init();
    DS1302_Init();
    DS1302_WriteByte(0x80,0x00);
    DS1302_WriteByte(0x82,0x00);
    DS1302_WriteByte(0x84,0x00);
    LCD_ShowChar(2,3,':');
    LCD_ShowChar(2,6,':');

    while (1)
    {
        Second=DS1302_ReadByte(0x81);
        second_1=Second&0x0F;
        LCD_ShowNum(2,8,second_1,1);
        second_10=(Second>>4)&0x07;
        LCD_ShowNum(2,7,second_10,1);
        
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

        Delay_ms(10);
    }
}

