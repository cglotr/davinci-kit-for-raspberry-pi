#include <wiringPi.h>
#include <stdio.h>

#define GPIO_17 17
#define GPIO_18 18
#define GPIO_22 22
#define GPIO_27 27

const int D1 = GPIO_17;
const int D2 = GPIO_18;
const int D3 = GPIO_27;
const int D4 = GPIO_22;

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

    printf("--- pin mode\n");
    pin_mode(D1);
    pin_mode(D2);
    pin_mode(D3);
    pin_mode(D4);

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
    }

    return 0;
}
