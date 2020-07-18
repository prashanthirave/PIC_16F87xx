/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/
#include<pic.h>
#define led RB5
void main()
{
	int C=0;
	TRISB=0X00;
	PORTB=0X00;
	while(1)
	{
		OPTION=0X00;
		TMR0=0x9C;
		while(TMR0IF==0);
		TMR0IF=0;
		led=~led;
	
	}
}
