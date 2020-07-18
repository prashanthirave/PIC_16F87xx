/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/


#include<PIC.H>
void tx(unsigned char ch);
void string(unsigned char *p);
void main()
{
   TRISB=0x80;//select rx(RA7) as input and  TX(RA6) as output
   TXSTA=0X24;
   RCSTA=0X80;
   SPBRG=25;//baudrate 9600
   string("DOT HEX Technology");
   
   while(1);
}

void string(unsigned char *p)
{
   do{ tx(*p);
       p++;
			}
   while(*p!='\0');

}
void tx(unsigned char ch)
{
  while(TXIF==0);
  TXREG=ch;
  TXIF=0;
}
