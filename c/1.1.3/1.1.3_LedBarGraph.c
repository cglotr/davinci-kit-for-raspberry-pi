/**********************************************************************
 * Filename    : 1.1.3_LedBarGraph.c
 * Description : The LEDs on the LED bar lit one by one from left to right, and then lit one by one from right to left..
 * Author      : Robot
 * E-mail      : support@sunfounder.com
 * website     : www.sunfounder.com
 * Update      : Daisy    2019/08/02
 **********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LED_SZ 10

const int ON = LOW;
const int FF = HIGH;
const int DELAY_MS = 1000;

int pin[LED_SZ] = {0, 1, 2, 3, 4, 5, 6, 8, 9, 10};
int on_off[LED_SZ] = {FF, FF, FF, FF, FF, FF, FF, FF, FF, FF};

void init();
void led_bar(int on_off[]);
void led_bar__eo(bool even);
void led_bar__on(bool is_on);

void led_bar(int on_off[])
{
    for (int i = 0; i < LED_SZ; i++)
    {
        digitalWrite(pin[i], on_off[i]);
    }
}

void led_bar__on(bool is_on)
{
    for (int i = 0; i < LED_SZ; i++)
    {
        if (is_on)
        {
            on_off[i] = ON;
        }
        else
        {
            on_off[i] = FF;
        }
    }

    led_bar(on_off);
}

void led_bar__eo(bool even)
{
    for (int i = 0; i < LED_SZ; i++)
    {
        bool is_even = (i % 2) == 0;
        if (even)
        {
            if (is_even)
            {
                on_off[i] = ON;
            }
            else
            {
                on_off[i] = FF;
            }
        }
        else
        {
            if (!is_even)
            {
                on_off[i] = ON;
            }
            else
            {
                on_off[i] = FF;
            }
        }
    }

    led_bar(on_off);
}

void init()
{
    for (int i = 0; i < 10; i++)
    {
        pinMode(pin[i], OUTPUT);
    }
}

int main(void)
{
    if (wiringPiSetup() == -1)
    {
        printf("setup wiringPi failed !");
        return 1;
    }

    init();

    while (1)
    {
        led_bar__eo(true);

        delay(DELAY_MS);

        led_bar__eo(false);

        delay(DELAY_MS);

        led_bar__on(true);

        delay(DELAY_MS);
    }

    return 0;
}
