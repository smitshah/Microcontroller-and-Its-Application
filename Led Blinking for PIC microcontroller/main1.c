/*
 Led blinking using PIC18F4550
 http://www.electronicwings.com
 */

#include "header.h"  /*Header file for Configuration Bits*/
//#include <pic18f4550.h>                  /*Header file PIC18f4550 definitions*/

void MSdelay(unsigned int);

void main()
{
    OSCCON=0x72;                /* Use internal oscillator of 8MHz Frequency */
    TRISB=0x00;                 /* Set direction of PORTB as OUTPUT to which LED is connected */
    while(1)
    {
        LATB = 0xFF;            /* Turn ON LED for 500 ms */
        MSdelay (500);
        LATB = 0x00;            /* Turn OFF LED for 500 ms */
        MSdelay (500);
    }
}
void MSdelay(unsigned int val)
{
 unsigned int i,j;
 for(i=0;i<val;i++)
     for(j=0;j<165;j++);         /*This count Provide delay of 1 ms for 8MHz Frequency */
 }