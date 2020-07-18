/*
Organisation name	: DOT HEX Technology.
Controller			: PIC16F876A.
Compiler			: HITECH-C or XC-8.
IDE					: MPLAB V8.53 or MPLAB-X.
*/

/* Header file for delay */



void delay(unsigned int time)
{				  
unsigned int i;
unsigned char j;
		 for(i=0;i<time;i++)
		 {
		 	for(j=0;j<40;j++);
		 }					   
}
