/*************************************
 * 
 *        89c52 sdcc blink demo
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * PIN: P00
 * 
 * ***********************************
*/

#include <reg52.h>
#include <stdio.h>

/**
  * @brief 中断处理函数，计时器每过1ms触发该函数
  * @param 无
  * @retval 无
  */
void Timer0_Routine()  interrupt 1
{
    static unsigned int T0Count;//计时器计数
    TH0=64535/256;
    TL0=64535%256;
    T0Count++;
    if(T0Count>=1000)
    {
        P20=~P20;
        T0Count=0;
        
    }
}

void main()
{
    Timer0_Init();
    P20=0;
    while (1)
    {

    }
}