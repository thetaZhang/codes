/*************************************
 * 
 *        89c52 sdcc serial try
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * 
 * ***********************************
*/
#include <UART.h>
#include <reg52.h>
#include <Delay.h>
#include <stdio.h>





void main()
{
    UART_Init();
    while(1){
        UART_SendByte(0x66);
        Delay_ms(1);
    }
}