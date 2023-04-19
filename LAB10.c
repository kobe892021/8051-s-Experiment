#include <regx51.h>

void printMsg(char*);
void write(char, int);
void delay(unsigned int);
int i;

void main(){
	write(0x38, 0);
	write(0x0f, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	printMsg("N96114297");
	
	write(0x40, 0);
	write(0x00, 1);
	write(0x41, 0);
	write(0x0e, 1);
	write(0x42, 0);
	write(0x1f, 1);
	write(0x43, 0);
	write(0x15, 1);
	write(0x44, 0);
	write(0x0e, 1);
	write(0x45, 0);
	write(0x0e, 1);
	write(0x46, 0);
	write(0x00, 1);
	write(0x47, 0);
	write(0x00, 1);
	
	write(0xc0, 0);
	write(0x00, 1);
	
	while(1);
}

void printMsg(char *msg){
	for(; *msg != '\0'; msg++){
		write(*msg, 1);
	}
}

void write(char cmd, int rs_value){
	P1 = cmd;
	P3_0 = rs_value;
	P3_1 = 1;
	delay(100);
	P3_1 = 0;
}

void delay(unsigned int i){
	while(i--);
}