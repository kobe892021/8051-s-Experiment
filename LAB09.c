#include <regx51.h> // include header file for 8051
void main(){
	IT0 = 0;
	EX0 = 1;
	EA = 1;
	P3_4 = 0;
	P3_4 = 1;
	
	while(1);
}

void int_0(void) interrupt 0{
	P3_5 = 0;
	/*
	if(P1 == 256){P2 = 0;}
	else if(P1 > 256 * (7/8)){P2 = 0x80;}
	else if(P1 > 256 * (6/8)){P2 = 0xc0;}
	else if(P1 > 256 * (5/8)){P2 = 0xe0;}
	else if(P1 > 256 * (4/8)){P2 = 0xf0;}
	else if(P1 > 256 * (3/8)){P2 = 0xf8;}
	else if(P1 > 256 * (2/8)){P2 = 0xfc;}
	else if(P1 > 256 * (1/8)){P2 = 0xfe;}
	else{P2 = 255;}
	*/
	if(P1 > 250){P2 = 0x00;}
	else if(P1 > 224){P2 = 0x80;}
	else if(P1 > 192){P2 = 0xc0;}
	else if(P1 > 160){P2 = 0xe0;}
	else if(P1 > 128){P2 = 0xf0;}
	else if(P1 > 96){P2 = 0xf8;}
	else if(P1 > 63){P2 = 0xfc;}
	else if(P1 > 31){P2 = 0xfe;}
	else{P2 = 0xff;}
	/*
	if(P1 > 256 / 2){
			P2 = 0xf0;
		}
	else if(P1 > 256 / 4){P2 = 0xfc;}
	else{
			P2 = 0xff;
		}
	*/
	P3_5 = 1;
	P3_4 = 0;
	P3_4 = 1;
}