/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* Timer 1 interrupt */



#include<pic.h>
#include "delay.h"
#define led1 RB1
#define led2 RB2

void timer1();
void main()
{
	PORTB=0X00;
	TRISB=0X00;
	GIE=1;
	PEIE=1;
	TMR1IE=1;//INTERRUPT
	timer1();
	while(1)
	{
		led1=~led1;
		delay(1000);
	}
}

void timer1()
{
	T1CON=0X01;
	TMR1L=0X9F;//delay
	TMR1H=0X15;//delay
}

void interrupt isr()
{
	if(TMR1IF)//timer1 interrupt
	{
		led2=~led2;
		timer1();//DELAY 60msec
		TMR1IF=0;	
	}
}
