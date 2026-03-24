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

#define GPIO_17 0
#define GPIO_27 2
#define GPIO_22 3

#define DELAY_MS 1000

const int on = 1;
const int ff = 0;

void ledInit(void)
{
    softPwmCreate(GPIO_17, ff, on);
    softPwmCreate(GPIO_27, ff, on);
    softPwmCreate(GPIO_22, ff, on);
}

void ledColorSet(int r_val, int g_val, int b_val)
{
    softPwmWrite(GPIO_17, r_val);
    softPwmWrite(GPIO_27, g_val);
    softPwmWrite(GPIO_22, b_val);
}

int main(void)
{
    if (wiringPiSetup() == -1)
    {
        printf("setup wiringPi failed !");
        return 1;
    }

    ledInit();

    int rgb_run[7][3] = {
        {on, ff, ff}, // red
        {ff, on, ff}, // green
        {ff, ff, on}, // blue
        {on, on, ff}, // yellow
        {on, ff, on}, // purple
        {ff, on, on}, // cyan
        {ff, ff, ff}  // black
    };

    while (1)
    {
        for (int i = 0; i < sizeof(rgb_run) / sizeof(rgb_run[0]); i++)
        {
            ledColorSet(rgb_run[i][0], rgb_run[i][1], rgb_run[i][2]);
            delay(DELAY_MS);
        }
    }

    return 0;
}
