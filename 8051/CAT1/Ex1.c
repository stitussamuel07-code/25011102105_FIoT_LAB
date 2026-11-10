#include <reg51.h>

sbit led1=P1^4;
sbit led2=P1^0;
void delay(){
	int i,j;
	for(i=0;i<400;i++){
		for(j=0;j<400;j++){
		}
	}
}
void main(){
	while(1){
	led1=1;
	delay();
	led1=0;
	delay();
	led2=1;
		delay();
		led2=0;
		delay();
	}
}