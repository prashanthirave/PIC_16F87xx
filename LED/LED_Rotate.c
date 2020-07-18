/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<PIC.H>
#include "delay.h"
unsigned char j,a,b;
void main()
{
	TRISB=0X00;
	
    while(1)
{
b=0x01;
for(a=0;a<=8;a++)
{
	PORTB=b;
	delay(500);
	b=b<<1;
	b++;
}
b=0x0ff;
for(j=0;j<=8;j++)
{
	PORTB=b;
	delay(500);
	b=b>>1;
b=b-1;
b=b+1;


}    
}

}
