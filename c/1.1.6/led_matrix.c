#include <stdio.h>
#include <wiringPi.h>

const int PIN__STO_CKL = 18;
const int PIN__SHF_CLK = 27;
const int PIN__SRL_DTA = 17;

const bool CHAR__SPACE[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};
const bool CHAR__LOVE[8][8] = {
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
};
const bool CHAR__I[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
};
const bool CHAR__U[8][8] = {
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0},
};

int led__rc[8][8];

void init();
void write(int data);
void write__char(const bool grid[8][8]);
void timing();
void timing__ui();

void main() {
    int setup = wiringPiSetupPinType(WPI_PIN_BCM);
    if (setup != 0) {
        printf("setup failed\n");
        return;
    }

    init();

    while (1) {
        write__char(CHAR__I);
        write__char(CHAR__LOVE);
        write__char(CHAR__U);
    }
}

void write__char(const bool grid[8][8]) {
    for (int i = 0; i < 1000; i++) {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (grid[r][c]) {
                    write(led__rc[r][c]);
                }
            }
        }
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

    timing();

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
    delayMicroseconds(10);
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
            write(led__rc[r][c]);
        }
    }

    write(0x00FF);
}
