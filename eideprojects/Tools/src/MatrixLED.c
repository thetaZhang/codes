#include <reg52.h>
#include <stdio.h>
#include <74HC595.h>
#include <MatrixLED.h>
#include <Delay.h>

__sfr __at(0x80) MATRIX_LED_PORT;

/**
 * @brief LED点阵初始化函数
 * 
 */
void MatrixLED_Init()
{
     _74HC595_Init();
}

/**
 * @brief  点阵按列显示函数，选取一列（从0开始编号），按输入数据显示
 * 
 * @param Column 选择显示的列数
 * @param Date 显示的二进制数据
 */
void MatrixLED_ShowColumn(unsigned char Column,unsigned char Date)
{
    _74HC595_WriteByte(Date);
    MATRIX_LED_PORT=~(0x80>>Column);
    Delay_ms(1);
    MATRIX_LED_PORT=0xFF;  //清零消影

}