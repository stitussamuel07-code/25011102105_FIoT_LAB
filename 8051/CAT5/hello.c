#include <reg51.h>

void UART(){
	
	
	TMOD= 0x20;
	

	TH1=0xFD;
	
	TL1=0xFD;
	TR1=1; //start timer
	SCON=0x50;

	
	
	
	
}
void sendChar(char str[]){
	int i;
	for(i=0;i<5;i++){
	       SBUF=str[i];
		
	
	}
	if(T1==0){
	T1=0;
	
	}
}

void SendChar(char c){
	SBUF=c;
	if(T1==0){
	TI=0;
	}
}
	
void sendStirng(char* st){
	while(*st!='/0'){
		sendChar(*st);
		st++;
	}
	sendChar('\r');
	sendChar('\n');

}
void main(){

	UART();
	while(1){
		//SendChar('a');
    sendString("Hello from 8051");
	}
	while(1){
	}


}