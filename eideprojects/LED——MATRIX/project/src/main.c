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


/**
 * @brief  点阵按列显示函数，选取一列（从0开始编号），按输入数据显示
 * 
 * @param Column 选择显示的列数
 * @param Date 显示的二进制数据
 */
void MatrixLED_ShowColumn(unsigned char Column,unsigned char Date)
{
    _74HC595_WriteByte(Date);
    P0=~(0x80>>Column);
}




void main()
{
    _74HC595_Init();
    MatrixLED_ShowColumn(0,0xAA);
    while (1){

    }
}