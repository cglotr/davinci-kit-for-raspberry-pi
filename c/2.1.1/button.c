#include <stdio.h>
#include <wiringPi.h>

const int PIN__BTN = 11;
const int PIN__LED = 12;

void init();

int main() {
    if (wiringPiSetupPinType(WPI_PIN_PHYS) != 0) {
        return 1;
    }
    init();
    while (true) {
        if (digitalRead(PIN__BTN) == HIGH) {
            digitalWrite(PIN__LED, HIGH);
        } else {
            digitalWrite(PIN__LED, LOW);
        }
    }
    return 0;
}

void init() {
    pinMode(PIN__BTN, INPUT);
    pinMode(PIN__LED, OUTPUT);
}
