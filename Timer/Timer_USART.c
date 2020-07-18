/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<pic.h>
#include "delay.h"
#define led1 RB6
#define led2 RB2

void timer1();
void uart();
char k;
void main()
{
	PORTB=0X00;
	TRISB=0X00;

	GIE=1;
	PEIE=1;

	TMR1IE=1;//TIMER INTERRUPT
	RCIE=1;//USART INTERRUPT	
	TRISC=0X80;

	timer1();
	uart();
	while(1);
}

void timer1()
{
	T1CON=0X01;
	TMR1L=0X9F;//delay
	TMR1H=0X15;//delay
}

void uart()
{
	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=25;
}
void interrupt isr()
{
	if(TMR1IF)//timer1 interrupt
	{
		led2=~led2;
		TMR1IF=0;
		timer1();//DELAY 60msec	
	}
	if(RCIF)
	{
		for(k=0;k<4;k++)
		{
			led1=~led1;
			delay(500);	
		}
		RCIF=0;
		RCREG='\0';	//NULL CHAR TRANFER	
	}

}
