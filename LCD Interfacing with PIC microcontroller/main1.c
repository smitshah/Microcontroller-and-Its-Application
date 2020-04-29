// LCD Interfacing using PIC18F4520

#include "header1.h"
#include "pic18f4520.h"
void lcd_cmd(char);
void delay(unsigned int);
void lcd_data(char);

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
    lcd_data('R');
    lcd_data('U');
    lcd_data('I');
    lcd_data('T');
    
    lcd_cmd(0xC0);
    lcd_data('S');
    lcd_data('A');
    lcd_data('N');
    lcd_data('Y');
    lcd_data('U');
    lcd_data('K');
    lcd_data('T');
    lcd_data('A');
    */
    // Using Array
    
    char i;
    char A[]="SMIT";
    char B[]="SHRUTI";
    char C[]="SANYUKTA";
    
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
    
    lcd_cmd(0xC0);
    for(i=0; C[i]!=0;i++)
    {
        lcd_data(C[i]);
    }
   
    while(1);
}

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