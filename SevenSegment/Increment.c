/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<PIC.H>
#include"delay.h"

void display();
void increament();

#define S1 RA1
#define S2 RC0
#define S3 RC1
#define S4 RC2

unsigned char r0=0,r1=0,r2=0,r3=0,b;
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
	for(b=0;b<40;b++)
	display();
	increament();
}
}

void display()
{
S1=0;
S2=S3=S4=1;
PORTB=a[r0];
delay(5);

S2=0;
S1=S3=S4=1;
PORTB=a[r1];
delay(5);

S3=0;
S1=S2=S4=1;
PORTB=a[r2];
delay(5);

S4=0;
S1=S3=S2=1;
PORTB=a[r3];
delay(5);
}

void increament()
{
	r0++;
	if(r0==10)
	{
	r0=0;
	r1++;
	if(r1==10)
	{
	r1=0;
	r2++;
	if(r2==10)
	{
	r2=0;
	r3++;
	if(r3==10)
	{
	r3=0;
}
}
}
}
}
