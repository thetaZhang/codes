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


void main()
{
    LCD_Init();
    LCD_ShowNum(1,1,1,1);
    
    while (1)
    {
      
    }
}

