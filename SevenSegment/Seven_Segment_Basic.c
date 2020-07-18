/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<PIC.H>
#include "delay.h"
#define S1 RA1
#define S2 RC0
#define S3 RC1
#define S4 RC2

void main()
{
	TRISB=0X00;
	TRISA1=0;
	TRISC0=0;
	TRISC1=0;
	TRISC2=0;
	while(1)
{
	delay(500);
	S1=0;
	S2=S3=S4=1;
	PORTB=0XFC;	
}
}
