/**********************************************************************
* Filename    : 1.1.2_rgbLed.c
* Description : Make a RGB LED emits various color.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Daisy    2019/08/02
**********************************************************************/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define uchar    unsigned char

#define GPIO_17  0
#define GPIO_27  2
#define GPIO_22  3

#define DELAY_MS 1000

void ledInit(void){
    softPwmCreate(GPIO_17, 0, 100);
    softPwmCreate(GPIO_27, 0, 100);
    softPwmCreate(GPIO_22, 0, 100);
}

void ledColorSet(uchar r_val, uchar g_val, uchar b_val){
    softPwmWrite(GPIO_17, r_val);
    softPwmWrite(GPIO_27, g_val);
    softPwmWrite(GPIO_22, b_val);
}

int main(void){
    if(wiringPiSetup() == -1) {
        printf("setup wiringPi failed !");
        return 1;
    }

    ledInit();

    uchar rgb_run[6][3] = {
        { 0xff, 0x00, 0x00 }, // red,
        { 0x00, 0xff, 0x00 }, // green,
        { 0x00, 0x00, 0xff }, // blue,
        { 0xff, 0xff, 0x00 }, // yellow,
        { 0xff, 0x00, 0xff }, // purple,
        { 0x00, 0xff, 0xff } // cyan
    };

    while (1) {
        for (int i = 0; i < sizeof(rgb_run) / sizeof(rgb_run[0]); i++) {
            ledColorSet(rgb_run[i][0], rgb_run[i][1], rgb_run[i][2]);
            delay(DELAY_MS);
        }
    }

    return 0;
}
