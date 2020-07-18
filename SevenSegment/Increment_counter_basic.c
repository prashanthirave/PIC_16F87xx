/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<PIC.H>
#include"delay.h"

void display();
#define S1 RA1
#define S2 RC0
#define S3 RC1
#define S4 RC2

unsigned char a[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};

void main()
{
	TRISB=0X00;
	TRISA1=0;
	TRISC0=0;
	TRISC1=0;
	TRISC2=0;
	while(1)
{
	display();
}
}

void display()
{
unsigned int i;
S2=0;
S1=S3=S4=1;
for(i=0;i<10;i++)
{
	PORTB=a[i];
	delay(1000);
}
}
