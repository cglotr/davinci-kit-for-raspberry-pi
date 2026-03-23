/**********************************************************************
* Filename    : 1.1.1_BlinkingLed.c
* Description : Make an led blinking.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Daisy    2019/08/02
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define GPIO_17    0
#define GPIO_27    2
#define GPIO_22    3

#define RGB_RUN    4

const int DELAY_MS = 100;

void led_on();
void led_off();
void light_rgb(int r, int g, int b);
void led_light(int led_pin, int status);

int main(void)
{
    if(wiringPiSetup() == -1){
        printf("setup wiringPi failed !");
        return 1;
    }

    pinMode(GPIO_17, OUTPUT);
    pinMode(GPIO_27, OUTPUT);
    pinMode(GPIO_22, OUTPUT);

    int rgb_run[RGB_RUN][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0},
    };

    while(1){
        for (int i = 0; i < RGB_RUN; i++) {
            light_rgb(rgb_run[i][0], rgb_run[i][1], rgb_run[i][2]);
            delay(DELAY_MS);
        }
    }

    return 0;
}

void light_rgb(int r, int g, int b) {
    led_light(GPIO_17, r);
    led_light(GPIO_27, g);
    led_light(GPIO_22, b);
}

void led_light(int led_pin, int status) {
    if (status == 1) {
        led_on(led_pin);
    } else {
        led_off(led_pin);
    }
}

void led_on(int led_pin) {
    digitalWrite(led_pin, LOW);
}

void led_off(int led_pin) {
    digitalWrite(led_pin, HIGH);
}
