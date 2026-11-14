#include <reg52.h>

sbit EN = P3^3;
sbit RS = P3^2;

void delay(unsigned int ms)
{
    unsigned int i, j;

    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void lcd_nibble(unsigned char n)
{
   
    P3 = (P3 & 0x0F) | (n & 0xF0);

    EN = 1;
    delay(1);
    EN = 0;
}

void lcd_cmd(unsigned char cmd)
{
    RS = 0;

    lcd_nibble(cmd);       
    lcd_nibble(cmd << 4); 

    delay(2);
}

void lcd_data(unsigned char ch)
{
    RS = 1;

    lcd_nibble(ch);        /* Upper nibble */
    lcd_nibble(ch << 4);   /* Lower nibble */

    delay(1);
}

void lcd_init()
{
    EN = 0;
    RS = 0;

    delay(20);

    /* Force LCD into 8-bit mode first */
    P3 = (P3 & 0x0F) | 0x30;
    EN = 1;
    delay(1);
    EN = 0;

    delay(5);

    P3 = (P3 & 0x0F) | 0x30;
    EN = 1;
    delay(1);
    EN = 0;

    delay(1);

    P3 = (P3 & 0x0F) | 0x30;
    EN = 1;
    delay(1);
    EN = 0;

    delay(1);

    /* Select 4-bit mode */
    P3 = (P3 & 0x0F) | 0x20;
    EN = 1;
    delay(1);
    EN = 0;

    delay(1);

    /* 4-bit, 2-line, 5x8 font */
    lcd_cmd(0x28);

    /* Display ON, cursor OFF */
    lcd_cmd(0x0C);

    /* Cursor moves right */
    lcd_cmd(0x06);

    /* Clear display */
    lcd_cmd(0x01);

    delay(2);
}

void lcd_puts(char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void main()
{
    P3 = 0x00;

    lcd_init();

    /* First row */
    lcd_cmd(0x80);
    lcd_puts("Hello");

    /* Second row */
    lcd_cmd(0xCA);
    lcd_puts("World");

    while(1);
}