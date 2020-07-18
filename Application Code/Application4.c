/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* Application Code convert decimal into binary */

#include <pic.h>
#include "delay.h"
#include "lcd_header.h"

unsigned char i,acc,ch;
unsigned char RX();
unsigned int arr[]={0,1,2,3,4,5,6,7,8,9};
unsigned char count=0,r,q,d=0xcb;

void main()
{
	TRISC7=1;
	TRISC6=0;

	TRISB=0x00;
	lcd_init();

	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=25;

	c_wr(0x80);
	lcd_string("Enter no: ");

	while(1)
	{	
		
	i=RX();
	c_wr(0x8a);
	d_wr(i);
	delay(5);
	
	c_wr(0xc0);
	lcd_string("Binary: ");
	c_wr(d);
	acc=arr[i-'0'];
		do{
		
		q=acc/2;
		r=acc%2;

		if(r==1)
		{
			c_wr(d);
			d_wr('1');
		}
		else
		{	
			c_wr(d);
			d_wr('0');
		}
		acc=q;		
		d--;
		count++;
	}while(count<=3 && d>=0xc8);
	count=0;
	d=0xcb;
}
}

unsigned char RX()
{	
	while(RCIF==0);
	ch=RCREG;
	RCIF=0;
	return ch;
}
