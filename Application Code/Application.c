/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* Application code using ADC, LCD, UART with interrupt */



#include<pic.h>
#include "delay.h"
#include "lcd_header.h"

void timer1();
void uart();
void ascii_conv(unsigned int value);
void a_d();
void A_D();

unsigned int var1;
unsigned int ch;

char k;
void main()
{
	
	TRISB=0X00;
	PORTB=0X00;

	GIE=1;
	PEIE=1;

	TMR1IE=1;//TIMER INTERRUPT
	RCIE=1;//USART INTERRUPT
	ADIE=1;//A-D INTERRUPT	
	
	TRISC=0X80;//UART
	lcd_init();

	timer1();
	uart();
	a_d();
	
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

void a_d()
{
	TRISA1=1;
	ADCON1=0X80;
	ADCON0=0X0d;
}

void A_D()
{
		ADCON0=0X0d;

		var1=ADRESL;
		var1=var1|ADRESH<<8;
		var1=var1& 0x3ff;
		
		ascii_conv(var1);
		delay(500);
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

void interrupt isr()
{	
	if(ADIF)
	{	A_D();
		ADIF=0;
	}
	else if(TMR1IF)
	{
		c_wr(0xc0);
		lcd_string("ON");
		delay(100);
		timer1();
		lcd_string("OFF");
		delay(200);
		TMR1IF=0;
	}
	
	else if(RCIF)
	{
		c_wr(0xca);
		ch=RCREG;
		d_wr(ch);
		delay(200);
		RCIF=0;
		RCREG='\0';
	}
}
