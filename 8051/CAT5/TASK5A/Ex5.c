#include <reg51.h>

sbit LED = P1^1;

unsigned int count = 0;

void timer0_ISR(void) interrupt 1
{
    TH0 = 0xF1;
    TL0 = 0x99;

    count++;

    if(count == 250)
    {
        LED = ~LED;
        count = 0;
    }
}

void main()
{
    LED = 0;

    TMOD = 0x01;      // Timer 0, Mode 1

    TH0 = 0xF1;
    TL0 = 0x99;

    ET0 = 1;           // Enable Timer 0 interrupt
    EA = 1;            // Enable global interrupt

    TR0 = 1;           // Start Timer 0

    while(1)
    {
    }
}