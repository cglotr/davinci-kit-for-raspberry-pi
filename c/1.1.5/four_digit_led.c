#include <wiringPi.h>
#include <stdio.h>

#define GPIO_5  5
#define GPIO_6  6
#define GPIO_12 12
#define GPIO_17 17
#define GPIO_18 18
#define GPIO_22 22
#define GPIO_24 24
#define GPIO_25 25
#define GPIO_27 27

const int D1 = GPIO_17;
const int D2 = GPIO_18;
const int D3 = GPIO_27;
const int D4 = GPIO_22;

const int SER   = GPIO_24;
const int OE_C    = GPIO_25;
const int RCLK  = GPIO_5;
const int SRCLK = GPIO_6;
const int SRCLR_C = GPIO_12;

void pin_mode(int gpio) {
    printf("pin mode output: gpio=%d\n", gpio);
    pinMode(gpio, OUTPUT);
}

void digital_write(int gpio, int value) {
    printf("digital write: gpio=%d, value=%d\n", gpio, value);
    digitalWrite(gpio, value);
}

int main() {
    int setup = wiringPiSetupPinType(WPI_PIN_BCM);
    if (setup != 0) {
        return setup;
    }

    int d_pins[4] = {D1, D2, D3, D4};

    printf("--- pin mode\n");
    pin_mode(D1);
    pin_mode(D2);
    pin_mode(D3);
    pin_mode(D4);

    pin_mode(SER);
    pin_mode(OE_C);
    pin_mode(RCLK);
    pin_mode(SRCLK);
    pin_mode(SRCLR_C);

    digital_write(SER, HIGH);
    digital_write(OE_C, LOW);
    digital_write(RCLK, HIGH);
    digital_write(SRCLK, HIGH);
    digital_write(SRCLR_C, HIGH);

    while (1) {
        printf("--- digital write: low\n");
        digital_write(D1, LOW);
        digital_write(D2, LOW);
        digital_write(D3, LOW);
        digital_write(D4, LOW);

        delay(1000);

        printf("--- digital write: high\n");
        digital_write(D1, HIGH);
        digital_write(D2, HIGH);
        digital_write(D3, HIGH);
        digital_write(D4, HIGH);

        delay(1000);

        for (int i = 0; i < sizeof(d_pins) / sizeof(int); i++) {
            digital_write(d_pins[i], LOW);

            delay(1000);
        }
    }

    return 0;
}
