/* 
 * File:   lcd_header.h
 * Author: hp
 *
 * Created on 9 October, 2019, 9:35 AM
 */

#ifndef LCD_HEADER_H
#define	LCD_HEADER_H

#include <xc.h>
#include <pic18f4520.h>

void lcd_cmd(char);
void delay(unsigned int);
void lcd_data(char);

#endif	/* LCD_HEADER_H */

