#include <stdio.h>
#include <wiringPi.h>

const int PIN_A = 12;
const int PIN_B = 16;
const int PIN_C = 18;
const int PIN_D = 22;

const int PIN_LIST[4] = {PIN_A, PIN_B, PIN_C, PIN_D};

void write(int word) {
    int p = 0b1000;
    for (int i = 0; i < sizeof(PIN_LIST)/sizeof(int); i++) {
        if (((p >> i) & word) > 0) {
            digitalWrite(PIN_LIST[i], HIGH);
            printf("1");
        } else {
            digitalWrite(PIN_LIST[i], LOW);
            printf("0");
        }
    }
    printf("\n");
    delayMicroseconds(2000);
}

void init() {
    for (int i = 0; i < sizeof(PIN_LIST)/sizeof(int); i++) {
        pinMode(PIN_LIST[i], OUTPUT);
    }
}

int main() {
    int spt = wiringPiSetupPinType(WPI_PIN_PHYS);
    if (spt != 0) {
        printf("pi setup failed!\n");
        return 1;
    }
    init();
    while (true) {
        write(0b1100);
        write(0b0110);
        write(0b0011);
        write(0b1001);
    }
    return 0;
}
