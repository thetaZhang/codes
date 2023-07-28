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
#include <MatrixLED.h>






void main()
{
    MatrixLED_Init();
    
    while (1){
        MatrixLED_ShowColumn(0,0x80);
        MatrixLED_ShowColumn(1,0x40);
        MatrixLED_ShowColumn(2,0x20);
        MatrixLED_ShowColumn(3,0x10);
    }
}