/*************************************
 * 
 *        89c52 sdcc serial try
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * 
 * ***********************************
*/

#include <reg52.h>
#include "Delay_ms.h"
#include <stdio.h>

/**
 * @brief UART串口初始化函数，配置SCON、PCON寄存器
 */
void UART_Init()
{
    SCON=0x40;//SM0和SM1为01设置为方式1，REN为0禁止接收
    PCON|=0x80; //PCON最高位置1，波特率加倍
    
//配置T1定时器
//使用定时器模式2：8位自动重装模式

    //配置T1定时器模式
    TMOD&=0x0F;
    TMOD|=0x20;
    TF1=0;
    TR1=1;
    TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
    //配置中断
    ET1 = 0;			//禁止定时器中断，此时不需要中断
	TR1 = 1;			//定时器1开始计时


}
/**
 * @brief 单片机接受上位机发送的字符
 * 
 * @param byte 要发送的字符
 */
void UART_SendByte(unsigned char byte)
{
    SBUF=byte;          //将byte直接写入寄存器SBUF即可发送
    while(TI==0);       //TI为1时候才发送结束
    TI=0;
}

void main()
{
    UART_Init();
    while(1){
        UART_SendByte(0x66);
        Delay_ms(1);
    }
}