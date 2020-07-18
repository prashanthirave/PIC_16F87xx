/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include <pic.h>
#include "delay.h"
void TX(unsigned char ch);
void tx_string(unsigned char *p);

void main()
{
	TRISC7=1;
	TRISC6=0;
	
	TXSTA=0X24;
	RCSTA=0X80;
	SPBRG=25;
	tx_string("DOT_HEX_Technology");

	while(1);
}

void TX(unsigned char ch)
{
	TXREG=ch;
	while(TXIF==0);
	TXIF=0;
}

void tx_string(unsigned char *p)
{
	while(*p!='\0')
	{
		TX(*p);
		delay(5);
		p++;
	}
}
