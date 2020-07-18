/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/*
Led's connected to PORTB
*/

#include <PIC.H>
void delay( unsigned int time);
void main()
{
	TRISB=0X00;
	PORTB=0X00;

	while(1)
	{
		PORTB=~PORTB;
		delay(1000);
	}
}

void delay( unsigned int time)
{
	unsigned int i;
	unsigned char j;
	for (i=0;i<time;i++)
	{
		for(j=0;j<40;j++);
	}
}
