/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* 4-bit LCD */


#include <PIC.H>
#include "delay.h"
#include "lcd_header.h"


unsigned char ACC,a,b,B;


void main()
{

	TRISB=0X00;

	delay(10);
	lcd_init();
	d_wr('A');
	c_wr(0xc0);
	lcd_string("DOT_HEX");

	while(1)
{

	for(a=0;a<=10;a++)
	{
		c_wr(0x1c);
		delay(500);
	}

	for(a=0;a<=10;a++)
	{
		c_wr(0x18);
		delay(500);
	}
}
}
