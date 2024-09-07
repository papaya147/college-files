#include <reg51.h>
#include <stdlib.h>

// * bluetooth module connected to UART
// * using external interrupt 0 to start/stop process

bool run = false;

sbit DHT = P1 ^ 0; // * pin P1.0 connected to DHT sensor
int I_RH, D_RH, I_Temp, D_Temp, CheckSum;

void uart_init()
{
    SCON = 0x50;
    TMOD = 0x21; // * setting timer 1 to mode 2 and timer 0 to mode 1
    TH1 = 0xFD;
    TR1 = 1;
}

void transmit_char(char c)
{
    SBUF = c;
    while (TI == 0)
        ;
    TI = 0;
}

void transmit_string(char *s)
{
    int i;
    for (i = 0; s[i] != 0; i++)
        transmit_char(s[i]);
}

void transmit_int(int i)
{
    char s[10];
    itoa(i, s);
    transmit_string(s);
}

void transmit_float(float f)
{
    char s[10];
    ftoa(f, s);
    transmit_string(s);
}

void ext_int_init()
{
    EA = 1;
    EX0 = 1;
    IT0 = 1;
}

void ext_int_isr() interrupt 1
{
    run = !run;
}

void dht_req_delay()
{
    // * creating 20ms delay
    TH0 = 0xBB;
    TL0 = 0x0C;
    TR0 = 1;
    while (TF0 == 1)
        ;
    TR0 = 0;
    TF0 = 0;
}

void dht_reception_delay()
{
    // * creating 30us delay
    TH0 = 0xFF;
    TL0 = 0xF1;
    TR0 = 1;
    while (TF0 == 0)
        ;
    TR0 = 0;
    TF0 = 0;
}

void dht_request()
{
    DHT = 0;
    dht_req_delay();
    DHT = 1;
}

void dht_response()
{
    while (DHT == 1)
        ;
    while (DHT == 0)
        ;
    while (DHT == 1)
        ;
}

int dht_read()
{
    int q, c = 0;
    for (q = 0; q < 8; q++)
    {
        while (DHT == 0)
            ;
        dht_reception_delay();
        if (DHT == 1)
            c = (c << 1) | (0x01);
        else
            c = (c << 1);
        while (DHT == 1)
            ;
    }
    return c;
}

void init()
{
    uart_init();
    ext_int_init();
    run = true;
}

void main()
{
    init();
    while (true)
    {
        if (run)
        {
            dht_request();  // * request data from DHT
            dht_response(); // * wait for response from DHT

            I_RH = dht_read();     // * store integer part of humidity
            D_RH = dht_read();     // * store decimal part of humidity
            I_Temp = dht_read();   // * store integer part of temperature
            D_Temp = dht_read();   // * store decimal part of temperature
            CheckSum = dht_read(); // * store checksum

            // * check if data is valid
            if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
            {
                transmit_string("checksum error\n");
                continue;
            }

            // * send data to bluetooth module
            transmit_string("RH: ");
            transmit_int(I_RH);
            transmit_string(".");
            transmit_int(D_RH);
            transmit_string("\n");

            transmit_string("Temp: ");
            transmit_int(I_Temp);
            transmit_string(".");
            transmit_int(D_Temp);
            transmit_string("\n");
        }
    }
}