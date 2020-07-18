/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<pic.h>
#define led RB5
void main()
{
TRISB=0X00;
PORTB=0X00;
while(1)
{
T1CON=0X01;
TMR1L=0X9F;
TMR1H=0X15;
while(TMR1IF==0);
TMR1IF=0;
led=~led;
}
}
