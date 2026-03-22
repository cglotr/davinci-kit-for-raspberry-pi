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
#define LedPin      0

void led_on();
void led_off();

int main(void)
{
    if(wiringPiSetup() == -1){
        printf("setup wiringPi failed !");
        return 1;
    }
    pinMode(LedPin, OUTPUT);
    while(1){
        led_on();
        delay(500);

        led_off();
        delay(500);
    }
    return 0;
}

void led_on() {
    digitalWrite(LedPin, LOW);
}

void led_off() {
    digitalWrite(LedPin, HIGH);
}
