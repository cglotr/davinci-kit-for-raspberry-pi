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

    while(1){
        light_rgb(1, 0, 0);
        delay(500);

        light_rgb(0, 1, 0);
        delay(500);

        light_rgb(0, 0, 1);
        delay(500);
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
