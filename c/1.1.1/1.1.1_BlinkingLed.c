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
        led_on(GPIO_17);
        led_off(GPIO_27);
        led_off(GPIO_22);
        delay(500);

        led_off(GPIO_17);
        led_on(GPIO_27);
        led_off(GPIO_22);
        delay(500);

        led_off(GPIO_17);
        led_off(GPIO_27);
        led_on(GPIO_22);
        delay(500);
    }

    return 0;
}

void led_on(int led_pin) {
    digitalWrite(led_pin, LOW);
}

void led_off(int led_pin) {
    digitalWrite(led_pin, HIGH);
}
