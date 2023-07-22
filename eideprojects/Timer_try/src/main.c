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
#include "Timer0.h"
#include <stdio.h>

unsigned int COUNT_Timer0=1000;//定时器计数上限
/**
  * @brief 中断处理函数，计时器每过1ms触发该函数
  * @param 无
  * @retval 无
  */
void Button_detect();
void Timer0_Routine()  interrupt 1
{
    static unsigned int T0Count;//计时器计数
    static unsigned int buttonCount;//按键计时用计数，用来计时20ms
    
    TH0=64535/256;
    TL0=64535%256;
    T0Count++;
    buttonCount++;if (buttonCount>20) {buttonCount-=20;}
    if(T0Count>=COUNT_Timer0)
    {
        P20=!P20;
        T0Count=0;
        
    }
    if (buttonCount==20){Button_detect();}
}
unsigned int buttonState=1;//记录按钮当前状态
unsigned int lastButtonState=1;//记录按钮上个状态
unsigned int state=0;//记录按钮是否按下，按下状态为1，松开状态为0
unsigned int flag=0;
/**
 * @brief 按钮探测函数，每次1ms中断时探测按钮状态
 * @param 无
 * @retval 无
 */
void Button_detect()
{
    buttonState=P30;
    if (buttonState!=lastButtonState){
        if (buttonState==0){
            state=1;
        }
        if (buttonState==1&&state==1){
            state=0;
            COUNT_Timer0=((!flag)? 2000:1000);
            flag=!flag;
        }

    }
    lastButtonState=buttonState;
}

void main()
{
    Timer0_Init();
    P20=0;
    while (1)
    {

    }
}