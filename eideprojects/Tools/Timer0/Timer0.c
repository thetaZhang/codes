#include <reg52.h>
#include "Timer.h"


/**
  * @brief 定时器0初始化函数，对计时器和中断相关寄存器进行配置，12MHz，1ms中断
  * @param 无
  * @retval 无
  */
void Timer0_Init()
{
//配置定时器

    //配置T0定时器模式，寄存器T0_M0为1，其余为0，使定时器T0为16位模式
    //TMOD不可位寻址，整体赋值
    TMOD&=0xF0;
    TMOD|=0x01;//这样赋值可以不动前四位，防止在同时用T0和T1时影响
    //配置T0定时器中断控制
    //TCON可以位寻址
    TF0=0;//T0溢出中断标志，先赋值0防止直接中断
    TR0=1;//T0运行控制，赋值1允许计数
    //对计数器赋初值使得每1ms中断一次，其为两个8位拼接，故应该分开赋值
    TH0=64535/256;
    TL0=64535%256;

//配置中断
    ET0=1;
    EA=1;
    PT0=0;

}

/*
定时器中断函数模板
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
*/