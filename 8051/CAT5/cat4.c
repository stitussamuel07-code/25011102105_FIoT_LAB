#include <reg51.h>

sbit led0 = P1 ^ 1;
sbit led1 = P1 ^ 2;
sbit led2 = P1 ^ 3;
sbit led3 = P1 ^ 4;

sbit row1 = P2 ^ 7;
sbit row2 = P2 ^ 6;
sbit row3 = P2 ^ 5;
sbit col2 = P2 ^ 2;
sbit col1 = P2 ^ 3;
sbit col3 = P2 ^ 1;
sbit col4 = P2 ^ 0;

int combo;
int stat;
int mode = 0;
int num = 0;

void display_seg(int n)
{
    if (n == 0)
    {
        P0 = 0x3F;
        return;
    }
    else if (n == 1)
    {
        P0 = 0x06;
        return;
    }
    else if (n == 2)
    {
        P0 = 0x5B;
        return;
    }
    else if (n == 3)
    {
        P0 = 0x4F;
        return;
    }
    else if (n == 4)
    {
        P0 = 0x66;
        return;
    }
    else if (n == 5)
    {
        P0 = 0x6D;
        return;
    }
    else if (n == 6)
    {
        P0 = 0x7D;
        return;
    }
    else if (n == 7)
    {
        P0 = 0x07;
        return;
    }
    else if (n == 8)
    {
        P0 = 0x7F;
        return;
    }
    else if (n == 9)
    {
        P0 = 0x6F;
        return;
    }
    return;
}
void delay2()
{
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 127; j++)
            ;
}

int keypress()
{
    row1 = 0;
    row2 = 0;
    row3 = 0;
    stat = 0;

    if (col2 == 0 || col1 == 0 || col3 == 0 || col4 == 0)
    {
        delay2();

        row1 = 0;
        row2 = 1;
        row3 = 1;
        if (col1 == 0)
        {
            delay2();

            if (col1 == 0)
            {
                while (col1 == 0);
                stat = 1;
                return 1;
            }
        }
        else if (col2 == 0)
        {
            delay2();
            if (col2 == 0)
            {
                while (col2 == 0)
                    ;
                stat = 2;
                return 1;
            }
        }
        else if (col3 == 0)
        {
            delay2();
            if (col3 == 0)
            {
                while (col3 == 0)
                    ;
                stat = 3;
                return 1;
            }
        }
        else if (col4 == 0)
        {
            delay2();
            if (col4 == 0)
            {
                while (col4 == 0)
                    ;
                stat = 4;
                return 1;
            }
        }

        row1 = 1;
        row2 = 0;
        row3 = 1;
        if (col1 == 0)
        {
            delay2();

            if (col1 == 0)
            {
                while (col1 == 0)
                    ;
                stat = 5;
                return 1;
            }
        }
        else if (col2 == 0)
        {
            delay2();
            if (col2 == 0)
            {
                while (col2 == 0)
                    ;
                stat = 6;
                return 1;
            }
        }
        else if (col3 == 0)
        {
            delay2();
            if (col3 == 0)
            {
                while (col3 == 0)
                    ;
                stat = 7;
                return 1;
            }
        }
        else if (col4 == 0)
        {
            delay2();
            if (col4 == 0)
            {
                while (col4 == 0)
                    ;
                stat = 8;
                return 1;
            }
        }

        row1 = 1;
        row2 = 1;
        row3 = 0;
        if (col1 == 0)
        {
            delay2();
        }
        if (col1 == 0)
        {
            while (col1 == 0)
                ;
            stat = 9;
            return 1;
        }
    }
    return 0;
}

int intr()
{

    if (keypress())
    {
        if (stat == 1)
        {
            mode = 0;
            num = 0;
            return 1;
        }
        else if (stat == 2)
        {
            mode = 1;
            num = 0;
            return 1;
        }
        else if (stat == 3)
        {
            mode = 2;
            num = 0;
            return 1;
        }
        else if (stat == 4)
        {
            mode = 3;
            num = 0;
            return 1;
        }
        else if (stat == 5)
        {
            mode = 4;
            num = 0;
            return 1;
        }
        else if (stat == 6)
        {
            mode = 5;
            num = 0;
            return 1;
        }
        else if (stat == 7)
        {
            mode = 6;
            num = 0;
            return 1;
        }
        else if (stat == 8)
        {
            mode = 7;
            num = 0;
            return 1;
        }
        else if (stat == 9)
        {
            mode = 8;
            num = 0;
            return 1;
        }
    }

    return 0;
}

int delay()
{

    int i, j;

    for (i = 0; i < 300; i++)
    {

        for (j = 0; j < 400; j++)
            ;

        if (intr())
            return 1;
    }

    return 0;
}

void counter()
{

    int a;

    if (intr())
        return;

    a = num;

    led0 = a % 2;
    a /= 2;

    led1 = a % 2;
    a /= 2;

    led2 = a % 2;
    a /= 2;

    led3 = a % 2;

    if (delay())
        return;
}

void seq()
{

    if (intr())
        return;

    led0 = 1;
    led1 = 0;
    led2 = 0;
    led3 = 0;
    if (delay())
        return;

    led0 = 0;
    led1 = 1;
    if (delay())
        return;

    led1 = 0;
    led2 = 1;
    if (delay())
        return;

    led2 = 0;
    led3 = 1;
    if (delay())
        return;

    led3 = 0;
}

void pattern1()
{

    if (intr())
        return;

    led0 = 1;
    led1 = 0;
    led2 = 1;
    led3 = 0;

    if (delay())
        return;

    led0 = 0;
    led1 = 1;
    led2 = 0;
    led3 = 1;

    if (delay())
        return;
}

void pattern2()
{

    if (intr())
        return;

    led0 = 1;
    led1 = 1;
    led2 = 1;
    led3 = 1;

    if (delay())
        return;

    led0 = 0;
    led1 = 0;
    led2 = 0;
    led3 = 0;

    if (delay())
        return;
}

void main()
{
    while (1)
    {

        if (intr())
        {
            led0 = 0;
            led1 = 0;
            led2 = 0;
            led3 = 0;
            continue;
        }
        switch (mode)
        {

        case 0:
            display_seg(1);
            led0 = 1;
            break;
        case 1:
            display_seg(2);
            led1 = 1;
            break;
        case 2:
            display_seg(3);
            led2 = 1;
            break;
        case 3:
            display_seg(4);
            led3 = 1;
            break;
        case 4:
            display_seg(5);
            seq();
            break;

        case 5:
            display_seg(6);
            pattern1();
            break;
        case 6:
            display_seg(7);
            num++;
            if (num > 15)
            {
                num = 0;
            }
            counter();
            break;

        case 7:
            display_seg(8);
            pattern2();
            break;
        case 8:
            display_seg(9);
            led0 = 0;
            led1 = 0;
            led2 = 0;
            led3 = 0;
            break;
        case 9:
            display_seg(0);
            mode = 1;
            break;
        }
    }
}