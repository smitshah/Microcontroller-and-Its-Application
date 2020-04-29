/*
 * File:   main10.c
 * Author: hp
 *
 * Created on 1 October, 2019, 10:33 AM
 */


#include "header10.h"
#include "pic18f4520.h"

#define Relay_Switch RB0
#define Buzzer_Switch RB1
#define Relay_Drive RB2
#define Buzzer_Drive RB3
#define Y_1 RB4
#define Y_2 RB5
#define Y_3 RB6
#define Y_4 RB7

# define _XTAL_Freq 80000000
void delay(unsigned int);
char switch_press_scan(void);
char keypad_scanner(void);
char InitKeypad(void);
char a=0;
void main()
{
    char key;
    OSCCON=0x72;
    GIE=0;
    TRISC=0x03;
    
    LATC=1;
    delay(100);
    //LATB=0;
    //delay(100);
    while(1);
}

void delay(unsigned int val)
{
 unsigned int i,j;
 for(i=0;i<val;i++)
     for(j=0;j<165;j++);         /*This count Provide delay of 1 ms for 8MHz Frequency */
}