#include <reg51.h>

sbit row1 = P2^7;
sbit row2 = P2^6;
sbit row3 = P2^5;
sbit row4 = P2^4;

sbit column1 = P2^3;
sbit column2 = P2^2;
sbit column3 = P2^1;
sbit column4 = P2^0;

sbit led0 = P1^1;
sbit led1 = P1^2;
sbit led2 = P1^3;
sbit led3 = P1^4;

int mode;
mode = 0;
int num = 0;

void delay2(){
	int i;
	int j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 127; j++){
		}	
	}
}

int keypress(){
	row1 = 0;
	if(column1 == 0){
		delay2();
		
	}
	if(column1 == 0){
		while(column1 == 0);
		return 1;
	}
	return 0;
}

int intr(){
		if(keypress()){
			mode =(mode+1)%4;
			return 1;
		}	
		return 0;
}

int delay()
{
    int i;
		int j;

    for(i = 0; i < 250; i++){
			for(j = 0; j < 250; j++){
				if(intr()){
					return 1;
				}
			}
		}
		return 0;
}

void counter() {

    int a;

    if(intr()) return;

    a = num;

    led0 = a % 2;
    a /= 2;

    led1 = a % 2;
    a /= 2;

    led2 = a % 2;
    a /= 2;

    led3 = a % 2;

    if(delay())
        return;
}

void seq() {

    if(intr()) return;

    led0 = 1;
    led1 = 0;
    led2 = 0;
    led3 = 0;
    if(delay()) return;

    led0 = 0;
    led1 = 1;
    if(delay()) return;

    led1 = 0;
    led2 = 1;
    if(delay()) return;

    led2 = 0;
    led3 = 1;
    if(delay()) return;

    led3 = 0;
}


void pattern1() {

    if(intr()) return;

    led0 = 1;
    led1 = 0;
    led2 = 1;
    led3 = 0;

    if(delay()) return;

    led0 = 0;
    led1 = 1;
    led2 = 0;
    led3 = 1;

    if(delay()) return;
}

void pattern2() {

    if(intr()) return;

    led0 = 1;
    led1 = 1;
    led2 = 1;
    led3 = 1;

    if(delay()) return;

    led0 = 0;
    led1 = 0;
    led2 = 0;
    led3 = 0;

    if(delay()) return;
}

void main() {

    while(1) {
 
        if(intr())
            continue;

        switch(mode) {

            case 0:
                seq();
                break;

            case 1:
                num++;
						   if(num>15){num=0;}
                counter();
                break;

            case 2:
                pattern1();
                break;

            case 3:
                pattern2();
                break;
        }
    }
}