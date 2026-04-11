#include <stdio.h>
#include <wiringPi.h>

const int PIN__STO_CKL = 18;
const int PIN__SHF_CLK = 27;
const int PIN__SRL_DTA = 17;

void timing() {
    delayMicroseconds(1000);
}

void timing__sto() {
    delayMicroseconds(10000);
}

void timing__sec() {
    delayMicroseconds(1000000);
}

void init() {
    pinMode(PIN__STO_CKL, OUTPUT);
    pinMode(PIN__SHF_CLK, OUTPUT);
    pinMode(PIN__SRL_DTA, OUTPUT);

    digitalWrite(PIN__STO_CKL, LOW);
    digitalWrite(PIN__SHF_CLK, LOW);
    digitalWrite(PIN__SRL_DTA, LOW);
}

void write(int data) {
    for (int i = 0; i < 16; i++) {
        int b = data & 1;
        int d = b != 0 ? HIGH : LOW;

        digitalWrite(PIN__SRL_DTA, d);
        digitalWrite(PIN__SHF_CLK, LOW);
        timing();
        digitalWrite(PIN__SHF_CLK, HIGH);
        timing();

        data = data >> 1;
    }

    timing__sto();

    digitalWrite(PIN__STO_CKL, LOW);
    timing();
    digitalWrite(PIN__STO_CKL, HIGH);
    timing();

    timing__sec();
}

void main() {
    int setup = wiringPiSetupPinType(WPI_PIN_BCM);
    if (setup != 0) {
        printf("setup failed\n");
        return;
    }

    init();

    for (int i = 0;; i++) {
        write(0b1000000000000000);
        write(0b0100000000000000);
        write(0b0010000000000000);
        write(0b0001000000000000);
        write(0b0000100000000000);
        write(0b0000010000000000);
        write(0b0000001000000000);
        write(0b0000000100000000);
        write(0b1111111101111111);
        write(0b1111111110111111);
        write(0b1111111111011111);
        write(0b1111111111101111);
        write(0b1111111111110111);
        write(0b1111111111111011);
        write(0b1111111111111101);
        write(0b1111111111111110);
    }
}
