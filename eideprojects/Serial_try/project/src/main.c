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
#include <stdio.h>

/**
 * @brief UART串口初始化函数，配置SCON、PCON寄存器
 */
void UART_init()
{
    SCON=0x40;//SM0和SM1为01设置为方式1，REN为0禁止接收
    PCON=0;

}