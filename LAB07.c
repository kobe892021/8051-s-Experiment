#include <regx51.h> // include header file for 8051
#define Timer0_int_exe_time 10 //the parameter can be changed
void delay(int t);
int counter;

void main( )
{
	TMOD = 0x09; 
	IP = 0x02; 
	IE = 0x82; 
	P2 = 0xfe;
	TL0 = (65536-50000)%256; 
	TH0 = (65536-50000)/256; //set TH0 & TL0
	TCON = 0x10; //enable timer0
	while(1);
}

void timer0_interrupt(void) interrupt 1 
{
	counter++;
	if (counter == Timer0_int_exe_time) //250clock cycle * 2000 = 0.5 second
	{
		//P2_1 = ~P2_1; inverse P2.0
		P2 = (P2 << 1)|(P2 >> 7);
		counter = 0;
		TL0 = (65536-50000)%256;
		TH0 = (65536-50000)/256;
	}
}