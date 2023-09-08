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



char* weekday[7]={"Mon", "Tue", "Wed", "Thu","Fri", "Sat", "Sun"};

/**
 * @brief 在LCD上显示当前时间
 * 
 */
void ShowTime()
{
    DS1302_ReadTime();

    LCD_ShowNum(1,1,DS1302_Time[0],2);
    LCD_ShowNum(1,4,DS1302_Time[1],2);
    LCD_ShowNum(1,7,DS1302_Time[2],2);
    LCD_ShowNum(2,1,DS1302_Time[3],2);
    LCD_ShowNum(2,4,DS1302_Time[4],2);
    LCD_ShowNum(2,7,DS1302_Time[5],2);
    LCD_ShowString(1,14,weekday[DS1302_Time[6]-1]);
}




void main()
{
    LCD_Init();
    DS1302_Init();
    LCD_ShowChar(2,3,':');
    LCD_ShowChar(2,6,':');
    LCD_ShowChar(1,3,'-');
    LCD_ShowChar(1,6,'-');
    DS1302_SetTime();
    

    while (1)
    {
        
        ShowTime();
        Delay_ms(10);
    }
}

