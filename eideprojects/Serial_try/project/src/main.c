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
#include <stdio.h>
#include <Timer0.h>



unsigned char Sec=0x61;
unsigned int counter=0;

void Timer0_Routine()  interrupt 1
{
    
    TH0=64535/256;
    TL0=64535%256;
    counter++;
    
}

void main()
{
    Timer0_Init();
    UART_Init();
    UART_SendByte(Sec);
    while(1){
        if (counter>=1000) {
            UART_SendByte(Sec);
            Sec++;
            counter=0;
        }
        
    }
}