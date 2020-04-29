// Port Interrupts

// Seven Segment Interfacing using PIC18F4550

#include "header2.h"  /*Header file for Configuration Bits*/
#include <pic18f4520.h>                  /*Header file PIC18f4550 definitions*/

void delay(unsigned int);
char A=0xFE;
void main()
{
    OSCCON=0x72;         /* Use internal oscillator of 8MHz Frequency */
    TRISBbits.RB0=1;
    TRISC=0x00;
    TRISD=0x00;
    
    LATC=A;  // FOR PORT C CONNECTED WITH LED SEGMENT
    LATD=0x01;  // FOR PORT D CONNECTED WITH J10
    
    INT0IF=0;
    INT0IE=1;  // RB0 AS INTERRUPT PIN RATHER THAN GPIO PORT PIN
    GIE=1;
    
    INTCON2=0x00; // TO DECLARE FALLING EDGE TRIGGERED INTERRUPT ON RB0
    while(1);
}

void interrupt low_priority Port_ISR()
{
    INT0IF=0; // CLEAR THE PERIPHERAL FLAG IN ISR
    A=A<<1;
    if(A==0x00)
        A=0xFE;
    LATC=A;
    // FOLLOWING DELAY STEPS WILL TAKE CARE FOR DEBOUNCE LOGIC IMPLEMENTATION
    delay(100);
    while(RB0==0);
    delay(100);
    while(RB1==0);
    delay(100);
}
void delay(unsigned int val)
{
 unsigned int i,j;
 for(i=0;i<val;i++)
     for(j=0;j<165;j++);         /*This count Provide delay of 1 ms for 8MHz Frequency */
 }
