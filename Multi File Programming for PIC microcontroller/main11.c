/* 
 * File:   main11.c
 * Author: hp
 *
 * Created on 9 October, 2019, 9:25 AM
 */

#include "header11.h"  /*Header file for Configuration Bits*/
#include <pic18f4520.h>                  /*Header file PIC18f4550 definitions*/
#include "lcd_header.h"
#include <xc.h>

void main()
{
    OSCCON=0x72;
    TRISC=0x00;
    TRISD=0x00;
    lcd_cmd(0x38);
    delay(1);
    lcd_cmd(0x0E);
    delay(1);
    lcd_cmd(0x01);
    delay(1);
    lcd_cmd(0x06);
    delay(1);
    
    // Using Char
    /*
    lcd_cmd(0x80);
    lcd_data('S');
    lcd_data('M');
    lcd_data('I');
    lcd_data('T');
    
    lcd_cmd(0x85);
    lcd_data('S');
    lcd_data('H');
    lcd_data('A');
    lcd_data('H');
    */
    
    // Using Array
    
    char i;
    char A[]="SMIT";
    char B[]="SHAH";
    
    lcd_cmd(0x80);
    for(i=0; A[i]!=0;i++)
    {
        lcd_data(A[i]);
    }
    
    lcd_cmd(0x85);
    for(i=0; B[i]!=0;i++)
    {
        lcd_data(B[i]);
    }
    
    while(1);
}
