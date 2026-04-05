#include <stdio.h>
#include <wiringPi.h>

const int in_1 = 11;
const int in_2 = 13;
const int en = 15;

void init() {
    pinMode(in_1, OUTPUT);
    pinMode(in_2, OUTPUT);
    pinMode(en, OUTPUT);
}

void power_motor(bool y) {
    if (y) {
        digitalWrite(en, HIGH);
    } else {
        digitalWrite(en, LOW);
    }
    digitalWrite(in_1, HIGH);
    digitalWrite(in_2, LOW);
}

void main() {
    if (wiringPiSetupPinType(WPI_PIN_PHYS) != 0) {
        printf("pi setup failed\n");
    }
    init();
    bool is_power = true;
    int counter = 0;
    while (counter < 3) {
        if (is_power) {
            power_motor(true);
        } else {
            power_motor(false);
        }
        if (is_power) {
            counter += 1;
            printf(" run: %ds\n", counter);
            delay(1000 * counter);
        } else {
            printf("stop: 1s\n");
            delay(1000);
        }
        is_power = !is_power;
    }
    power_motor(false);
}
