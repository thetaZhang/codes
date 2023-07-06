/*************************************
 * 
 *        Timer Try
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * 
 * ***********************************
*/

#include <regx52.h>






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
        P2_0=~P2_0;
        T0Count=0;
        
    }
}

void main()
{
    Timer0_Init();
    P2_0=0;
    while (1)
    {

    }
}