/**********************************************************************
* Filename    : 1.1.5_4-Digit.c
* Description : Control 4 Digit 7-Segment Display
* Author      : sunfounder
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : 2019/08/02
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <wiringShift.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

#define SDI   23
#define RCLK  25
#define SRCLK 5

const int placePin[] = {
    22,
    27,
    18,
    17
};
unsigned char number[] = {
    0xc0,
    0xf9,
    0xa4,
    0xb0,
    0x99,
    0x92,
    0x82,
    0xf8,
    0x80,
    0x90
};

int counter = 0;

void pickDigit(int digit) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(placePin[i], 0);
    }
    digitalWrite(placePin[digit], 1);
}

void hc595_shift(int8_t data) {
    int i;
    for (i = 0; i < 8; i++) {
        digitalWrite(SDI, 0x80 & (data << i));
        digitalWrite(SRCLK, 1);
        delayMicroseconds(1);
        digitalWrite(SRCLK, 0);
    }
    digitalWrite(RCLK, 1);
    delayMicroseconds(1);
    digitalWrite(RCLK, 0);
}

void clearDisplay() {
    int i;
    for (i = 0; i < 8; i++) {
        digitalWrite(SDI, 1);
        digitalWrite(SRCLK, 1);
        delayMicroseconds(1);
        digitalWrite(SRCLK, 0);
    }
    digitalWrite(RCLK, 1);
    delayMicroseconds(1);
    digitalWrite(RCLK, 0);
}

void loop() {
    while (1) {
        clearDisplay();
        pickDigit(0);
        hc595_shift(number[counter % 10]);

        clearDisplay();
        pickDigit(1);
        hc595_shift(number[counter % 100 / 10]);

        clearDisplay();
        pickDigit(2);
        hc595_shift(number[counter % 1000 / 100]);

        clearDisplay();
        pickDigit(3);
        hc595_shift(number[counter % 10000 / 1000]);
    }
}

void timer(int t) {
    if (t == SIGALRM) {
        counter++;
        counter = counter % 10000;
    }
}

void main(void) {
    if (wiringPiSetupPinType(WPI_PIN_BCM) != 0) {
        return;
    }

    pinMode(SDI,   OUTPUT);
    pinMode(RCLK,  OUTPUT);
    pinMode(SRCLK, OUTPUT);

    for (int i = 0; i < 4; i++) {
        pinMode(placePin[i], OUTPUT);
        digitalWrite(placePin[i], HIGH);
    }

    signal(SIGALRM, timer);

    struct itimerval timer_val;
    timer_val.it_interval.tv_sec = 1;
    timer_val.it_interval.tv_usec = 0;
    timer_val.it_value.tv_sec = 1;
    timer_val.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer_val, NULL);

    loop();
}
