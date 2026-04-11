#include <stdio.h>
#include <wiringPi.h>

const int PIN__STO_CKL = 18;
const int PIN__SHF_CLK = 27;
const int PIN__SRL_DTA = 17;

const int LED__R01_C01 = 0b1000000001111111;
const int LED__R01_C02 = 0b1000000010111111;
const int LED__R01_C03 = 0x80DF;

int led__rc[8][8];

void init();
void write(int data);
void timing();
void timing__ui();

void main() {
    int setup = wiringPiSetupPinType(WPI_PIN_BCM);
    if (setup != 0) {
        printf("setup failed\n");
        return;
    }

    init();

    for (;;) {
        write(LED__R01_C01);
        write(LED__R01_C02);
        write(LED__R01_C03);
    }
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

    digitalWrite(PIN__STO_CKL, LOW);
    timing();
    digitalWrite(PIN__STO_CKL, HIGH);
    timing();

    timing__ui();
}

void timing() {
    delayMicroseconds(1);
}

void timing__ui() {
    delayMicroseconds(100000);
}

void init() {
    pinMode(PIN__STO_CKL, OUTPUT);
    pinMode(PIN__SHF_CLK, OUTPUT);
    pinMode(PIN__SRL_DTA, OUTPUT);

    digitalWrite(PIN__STO_CKL, LOW);
    digitalWrite(PIN__SHF_CLK, LOW);
    digitalWrite(PIN__SRL_DTA, LOW);

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            led__rc[r][c] = 0x00FF;
            led__rc[r][c] |= 1 << (8 + 7-r);
            led__rc[r][c] &= (0xFFFF) ^ (1 << (7-c));
            printf("%016b\n", led__rc[r][c]);
            write(led__rc[r][c]);
        }
    }
}
