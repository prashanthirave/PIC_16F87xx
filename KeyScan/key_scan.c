/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* Hex Keypad */



#include <PIC.H>
#define _XTAL_FREQ 4000
void row1();
void row2();
void row3();
void row4();
void disp();

#define s1 RA1
#define s2 RC0
#define s3 RC1
#define s4 RC2
#define k4 RA2
#define k5 RA3
#define k6 RA4
#define k7 RA5

void main()
{__delay_ms(100);
TRISB=0X00;
TRISA=0X3C;
TRISC=0xf8;
//TRISC1=0;
//TRISC2=0;

ADCON1=0X06;
while(1)
{
	row1();
	row2();
	row3();
	row4();	
}			

}

void row1()
{
	s1=0;
	s2=s3=s4=1;
	while(k4==0)
	{
	 PORTB=0xfc;
	}
		
	while(k5==0)
	{
	 PORTB=0x60;	
	}
	while(k6==0)
	{
	 PORTB=0xda;	
	}		
	while(k7==0)
	{
	 PORTB=0xf2;	
	}
	PORTB=0x00;
}

void row2()
{
	s2=0;
	s1=s3=s4=1;
	while(k4==0)
	{ 	
		disp();	
	 	PORTB=0x66;
	}
		
	while(k5==0)
	{
		disp();
	 	PORTB=0xb6;	
	}
	while(k6==0)
	{
	 	disp();	
		PORTB=0xbe;	
	}		
	while(k7==0)
	{
	 	disp();	
		PORTB=0xe0;	
	} 
	PORTB=0x00;

}

void row3()
{
	s3=0;
	s2=s1=s4=1;
	while(k4==0)
	{
		disp();	
	 	PORTB=0xfe;
	}
		
	while(k5==0)
	{
		disp();	
	 	PORTB=0xf6;	
	}
	while(k6==0)
	{
		disp();	
	 	PORTB=0xee;	
	}		
	while(k7==0)
	{
		disp();	
	 	PORTB=0x3e;	
	}	
	PORTB=0x00;	
}
 
void row4()
{
	s4=0;
	s2=s3=s1=1;
	while(k4==0)
	{
		disp();	
	 	PORTB=0x9c;
	}
			
	while(k5==0)
	{
		disp();	
	 	PORTB=0x7a;	
	}
	while(k6==0)
	{
	 	disp();	
	 	PORTB=0x9e;	
	}		
	while(k7==0)
	{
	 	disp();	
		PORTB=0x8e;	
	}
} 
   
void disp()
{
	s1=0;
	s2=s3=s4=1;
}
