/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* 4-bit LCD */



#include <PIC.H>
#define _XTAL_FREQ 4000
#include "delay.h"
#include "lcd_header.h"


unsigned char a,b,i,j;


void main()
{

	TRISB=0X00;

	__delay_ms(10);
//	delay(10);
	lcd_init();
	lcd_string("Counter");

	while(1)
{
	a=0x30;
	for(j=0;j<10;j++)
	{
		c_wr(0xc0);
		d_wr(a);
		b=0x30;
	for(i=0;i<=10;i++)
	{
		c_wr(0xc1);
		d_wr(b);
		__delay_ms(1000);
		b++;
	}
		a++;
}
}
}
