/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include <PIC.H>
#include "delay.h"
void display();
void increment();
void decrement();

#define s1 RA1
#define s2 RC0
#define s3 RC1
#define s4 RC2
#define k4 RA2
#define k5 RA3

unsigned char i,r0,r1,r2,r3,r4,B;
unsigned char a[]={0x00,0x6e,0x9e,0x1c,0x1c,0xfc,0x02,0x00};
char get_key();

void main()
{	unsigned char c,d;
	TRISB=0X00;
	TRISA=0X3C;
	TRISC=0x00;
PORTB=0x00;

	ADCON1=0X06;
	
	r0=0;
	r1=0;
	r2=0;
	r3=0;
	r4=0;
  	while(1)
	{c=0;
	c=get_key();
	switch(c)
	{
	case '0':
				if(k4==0){
			do{ 
			for(B=0;B<100;B++)
			 	display();
	 			increment();
				s1=0;
				s2=s3=s4=1;
					if(k5==0)
					{
						c='1';
						//d=1;
						break;
					}
			
				}while( k4==1 );
				
				}

			break;

	case '1':if(k5==0){
			r4=7;
			do{	d=1;
			
			for(B=0;B<100;B++)
			 display();
			 decrement();
				s1=0;
				s2=s3=s4=1;
					if(k4==0)
					{
						c='0';
						d=0;
						break;
					}
				
			}while(k5==1);
			}		
			break;	
	}
}
}
char get_key()
{	s1=0;
	s2=s3=s4=1;
	if(k4==0)
	{
		return '0';
	}

	if(k5==0)
	{
		return '1';
	}
}
 void display()
 { 	
	s1=0;
	s2=s3=s4=1;
	PORTB=a[r0];
	delay(2);
	s2=0;
	s1=s3=s4=1;
	PORTB=a[r1];
	delay(2);
	s3=0;
	s2=s1=s4=1;
	PORTB=a[r2];
	delay(2);
	s4=0;
	s2=s3=s1=1;
	PORTB=a[r3];
	delay(2);
 }


 void increment()
 {
 	r4=r3;
	r3=r2;
	r2=r1;
	r1=r0;
	r0++;
	if(r0==7)
	{
	r0=0; 
 	}
 }

 void decrement()
 {
 	r0=r1;
	r1=r2;
	r2=r3;
	r3=r4;
	r4--;
	if(r4==0)
	{
	r4=7; 
 	}
 }
