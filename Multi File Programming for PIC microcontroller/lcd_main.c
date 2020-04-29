// LCD Interfacing using PIC18F4520
/* 
 * File:   lcd_main.c
 * Author: hp
 *
 * Created on 9 October, 2019, 9:35 AM
 */

#include "lcd_header.h"
#include <pic18f4520.h>
#include<xc.h>

void lcd_cmd(char x)
{
   
    //LATC=x;
    RD3=0; // RS
    RD4=0; // W
    RD5=1; // EN
    LATC=x;
    delay(100);
    RD5=0;
}

void lcd_data(char y)
{
    //LATC=y;
    RD3=1; // RS
    RD4=0; // W
    RD5=1; // EN
    LATC=y;
    delay(100);
    RD5=0;
}

void delay(unsigned int val)
{
 unsigned int i,j;
 for(i=0;i<val;i++)
     for(j=0;j<165;j++);         /*This count Provide delay of 1 ms for 8MHz Frequency */
}
