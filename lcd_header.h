/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* 4-bit LCD header file */


#define BK RB0
#define RS RB1
#define RW RB2
#define EN RB3


void lcd_string(unsigned char *p);
void d_wr(unsigned char ch);
void c_wr(unsigned char ch);
void lcd_init();


unsigned char ACC,a,b,B;

void lcd_init()
{

	c_wr(0x03);
   
	c_wr(0x03);
	
	c_wr(0x03);
	
	c_wr(0x02);

	c_wr(0x28);

	c_wr(0x0c);

//	c_wr(0x06);
	
	c_wr(0x01);
}
void lcd_string(unsigned char *p)
{
	while(*p!='\0')
	{
		d_wr(*p);
		p++;
	}
}
void c_wr(unsigned char ch)
{
	ACC=ch;
	ACC=ACC&0xf0;

	PORTB=ACC;
	RS=0;
	RW=0;
	
	EN=1;
	delay(5);
	EN=0;
	
	B=ch;
	B=B<<4;
	B=B&0xf0;
	PORTB=B;


	RS=0;
	RW=0;

	EN=1;
	delay(5);
	EN=0;
}
		 
void d_wr(unsigned char ch)
{
	ACC=ch;
	ACC=ACC&0xf0;

	PORTB=ACC;
	RS=1;
	RW=0;
	
	EN=1;
	delay(5);
	EN=0;
	B=ch;
	B=B<<4;
	B=B&0xf0;
	PORTB=B;


	RS=1;
	RW=0;

	EN=1;
	delay(5);
	EN=0;
}
