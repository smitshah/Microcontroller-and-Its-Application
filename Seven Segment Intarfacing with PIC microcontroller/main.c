// Seven Segment Interfacing using PIC18F4550

#include "header.h"  /*Header file for Configuration Bits*/
//#include <pic18f4550.h>                  /*Header file PIC18f4550 definitions*/

void delay(unsigned int);

void main()
{
    
    //OSCCON=0x72;                /* Use internal oscillator of 8MHz Frequency */
    //TRISC=0x00;                 /* Set direction of PORTB as OUTPUT to which LED is connected */
    //TRISD=0x00;
    //while(1)
    //{
    //    for(LATD=0x01;LATD<=0x08;LATD=LATD*(0x02))
    //    {
        //LATD=0x01;
    //    LATC=0xC0;   // Display 0
    //    delay(1000);
        //LATD=0x02;
    //    LATC=0xF9;   // Display 1
    //    delay(1000);
        //LATD=0x04;
    //    LATC=0xA4;   // Display 2
    //    delay(1000);
        //LATD=0x08;
    //    LATC=0xB0;   // Display 3
    //    delay(1000);
        //LATD=0x01;
    //    LATC=0x99;   // Display 4
    //    delay(1000);
        //LATD=0x02;
    //    LATC=0x92;   // Display 5
    //    delay(1000);
        //LATD=0x04;
    //    LATC=0x82;   // Display 6
    //    delay(1000);
        //LATD=0x08;
    //    LATC=0xF8;   // Display 7
    //    delay(1000);
        //LATD=0x01;
    //    LATC=0x80;   // Display 8
    //    delay(1000);
        //LATD=0x02;
    //    LATC=0x90;   // Display 9
    //    delay(1000);
    //    }
    //}
    OSCCON=0x72;                /* Use internal oscillator of 8MHz Frequency */
    char a=0x01;
    char buffer[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
    int i;
    while(1)
    {
       TRISC = buffer[i];
       TRISD = a;
       delay(1000);
       a << 1;
       i++;
       if(i==10)
       {
           i=0;
           a=0x01;
       }
    }
}

void delay(unsigned int val)
{
 unsigned int i,j;
 for(i=0;i<val;i++)
     for(j=0;j<165;j++);         /*This count Provide delay of 1 ms for 8MHz Frequency */
 }