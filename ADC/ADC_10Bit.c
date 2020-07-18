/*
Organisation name	: DOT HEX Technology.
Controller		: PIC16f876A.
Compiler		: HITECH-C or XC-8.
IDE			: MPLABV8.53 or MPLAB-X.
*/


#include<PIC.H>
#include "delay.h"
#include "lcd_header.h"

void ascii_conv(unsigned int value);
void ascii_conv1(unsigned int value1);

unsigned int var1,var2;
void main()
{
	TRISB=0X00;
	lcd_init();
	TRISA1=1;
	ADCON1=0X80;
	ADCON0=0X0d;
	while(1)
	{
		ADCON0=0X0d;
		delay(5);
		c_wr(0x80);
		while((ADCON0 & 0X04)!=0);
		var1=ADRESL;
		var1=var1|ADRESH<<8;
		var1=var1& 0x3ff;
		
		ascii_conv(var1);
		delay(500);

		var2=var1*4.88;
		c_wr(0xc0);
		ascii_conv1(var2);
		delay(500);
	}
}

void ascii_conv(unsigned int value) // resistance
{
	unsigned char p,q,r,s;
	p=value/1000;
	d_wr(p+'0');

	value=value%1000;
	q=value/100;
	d_wr(q+'0');

	value=value%100;
	r=value/10;
	d_wr(r+'0');

	s=value%10;
	d_wr(s+'0');
}

void ascii_conv1(unsigned int value1) //voltage
{
	unsigned char p,q,r,s;
	p=value1/1000;
	d_wr(p+'0');
	d_wr('.');
	value1=value1%1000;
	q=value1/100;
	d_wr(q+'0');

	value1=value1%100;
	r=value1/10;
	d_wr(r+'0');

	s=value1%10;
	d_wr(s+'0');
}
