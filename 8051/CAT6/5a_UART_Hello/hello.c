#include <reg51.h>

/* UART setup: Timer 1 mode 2 (8-bit auto-reload) as baud rate generator.
   TH1 = 0xFD -> 9600 baud with an 11.0592 MHz crystal. */
void UART_Init(void)
{
    TMOD = 0x20;   /* Timer 1, mode 2 */
    TH1  = 0xFD;   /* 9600 baud */
    TL1  = 0xFD;
    SCON = 0x50;   /* serial mode 1, receive enabled */
    TR1  = 1;      /* start Timer 1 */
}

void sendChar(char c)
{
    SBUF = c;
    while (TI == 0);   /* wait until byte is sent */
    TI = 0;
}

void sendString(char *str)
{
    while (*str != '\0')
    {
        sendChar(*str);
        str++;
    }
    sendChar('\r');
    sendChar('\n');
}

void main(void)
{
    UART_Init();
    while (1)
    {
        sendString("Hello from 8051");
    }
}
