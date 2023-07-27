/*************************************
 * 
 *        89c52 LED Matrix
 * 
 * CPU: 89C52
 * FREQ: 12MHz
 * 
 * ***********************************
*/

#include <reg52.h>
#include <stdio.h>
#include <74HC595.h>





void main()
{
    _74HC595_Init();
    _74HC595_WriteByte(0x66);
    while (1){

    }
}