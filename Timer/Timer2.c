/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<pic.h>
#define led RB6
void main()
{
	TRISB=0X00;
	PORTB=0X00;
	while(1)
	{
		T2CON=0Xff;
		TMR2=0;
		PR2=186;
		//TMR2H=0X15;
		while(TMR2IF==0);
		TMR2IF=0;
		led=~led;
	}
}
