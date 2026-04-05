#!/bin/bash
set -e
gcc stepper_motor.c -lwiringPi
./a.out
