/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

#include<PIC.H>
void rx();
void display();
void string(unsigned char *p);
unsigned int ch=0;
unsigned int arr[]={0xfc,0x60,0xDA,0xF2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6};
void main()
{  TRISA1=0;
   TRISC=0X80;//select rx(RA7) as input and  TX(RA6)   
   TRISB=0x00;
   TXSTA=0X24;
   RCSTA=0X90;
   SPBRG=25;//baudrate 9600
  while(1)
  	{ 
  		rx();
	  
	}
   
   
}
 void display()
{

  RA1=0;
  PORTC=0X07;
  PORTB=arr[ch-'0'];
}

void rx()
{ 
  while(RCIF==0);
  ch=RCREG;
display();
  RCIF=0;
  
  
}
