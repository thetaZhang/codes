#include <stdio.h>
#include "Delay.h"

/**
 * @brief 阻塞式毫秒软件延时器，可自定义延时毫秒
 * 
 * @param t 延迟毫秒数 
 */
void Delay_ms(unsigned int t)		//@12.000MHz
{

    for (unsigned int n=0;n<t;n++){
        unsigned char i, j;

	    i = 12;
	    j = 169;
	    do
	    {
		    while (--j);
	    } while (--i);
    }
}