#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define D_PIN_SZ      4
#define LED_N_SZ      10
#define D_SZ          8
#define REFRESH_DELAY 1000

const int D1 = 17;
const int D2 = 18;
const int D3 = 27;
const int D4 = 22;

const int SER   = 23;
const int RCLK  = 25;
const int SRCLK = 5;

int D_PIN[D_PIN_SZ] = {D1, D2, D3, D4};
int LED_N[LED_N_SZ] = {
//    abcdefg
    0b11111100,
    0b01100000,
    0b11011010,
    0b11110010,
    0b01100110,
    0b10110110,
    0b10111110,
    0b11100000,
    0b11111110,
    0b11100110
};

int count = 0;

void pin_mode(int gpio) {
    pinMode(gpio, OUTPUT);
}

void digital_write(int gpio, int value) {
    digitalWrite(gpio, value);
}

void output_led(int led_in) {
    for (int i = 0; i < D_SZ; i++) {
        int v = !(HIGH & led_in);
        digital_write(SER, v);

        digital_write(SRCLK, HIGH);
        delayMicroseconds(1);
        digital_write(SRCLK, LOW);

        led_in = led_in >> 1;
    }

    digital_write(RCLK, HIGH);
    delayMicroseconds(1);
    digital_write(RCLK, LOW);
}

void init() {
    if (wiringPiSetupPinType(WPI_PIN_BCM) != 0) {
        return;
    }

    pin_mode(SER);
    pin_mode(RCLK);
    pin_mode(SRCLK);

    pin_mode(D1);
    pin_mode(D2);
    pin_mode(D3);
    pin_mode(D4);
}

void output_clear() {
    output_led(0b00000000);
}

void output_number(int number) {
    for (int i = 0; i < D_PIN_SZ; i++) {
        digital_write(D_PIN[i], LOW);
    }

    for (int i = 0; i < D_PIN_SZ; i++) {
        int d = number % 10;
        int pos = D_PIN_SZ-1-i;

        digital_write(D_PIN[pos], HIGH);
        output_led(LED_N[d]);
        delayMicroseconds(REFRESH_DELAY);
        digital_write(D_PIN[pos], LOW);
        output_clear();

        number = number / 10;
    }
}

void timer(int t) {
    if (t == SIGALRM) {
        count++;
        count = count % 10000;
        alarm(1);
    }
}

int main() {
    init();

    signal(SIGALRM, timer);
    alarm(1);

    while (1) {
        output_number(count);
    }

    return 0;
}
