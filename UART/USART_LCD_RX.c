/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/


#include <pic.h>
#include "delay.h"
#include "lcd_header.h"
void tx(unsigned char ch);
unsigned char acc,ch;
unsigned char RX();

void main()
{
	TRISC7=1;
	TRISC6=0;

	TRISB=0x00;
	lcd_init();

	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=25;

	while(1)
	{	
	acc=RX();
    d_wr(acc);
	delay(5);
	tx(0x0d);
	c_wr(0x80);
	}
}
void tx(unsigned char ch)
{
	while(!TXIF);
	TXREG=ch;
	TXIF=0;
}
unsigned char RX()
{	
	while(RCIF==0);
	ch=RCREG;
	RCIF=0;
	return ch;
}
