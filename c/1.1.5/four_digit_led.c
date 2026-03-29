#include <wiringPi.h>
#include <stdio.h>

#define D_PIN_SZ 4
#define LED_N_SZ 10
#define D_SZ     8

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

void pin_mode(int gpio) {
    pinMode(gpio, OUTPUT);
}

void digital_write(int gpio, int value) {
    digitalWrite(gpio, value);
}

void output_number(int led_in) {
    digital_write(SRCLK, LOW);
    digital_write(RCLK, LOW);

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

int main() {
    int setup = wiringPiSetupPinType(WPI_PIN_BCM);
    if (setup != 0) {
        return setup;
    }

    pin_mode(D1);
    pin_mode(D2);
    pin_mode(D3);
    pin_mode(D4);

    pin_mode(SER);
    pin_mode(RCLK);
    pin_mode(SRCLK);

    int count = 0;

    while (1) {
        digital_write(D1, HIGH);
        output_number(LED_N[count % 10]);
        count = count + 1;
        delay(1000);
    }

    return 0;
}
