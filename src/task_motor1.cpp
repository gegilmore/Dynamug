#include <Arduino.h>
#include <shares.h>
#include <task_motor1.h>
#include <Servo.h>
#include <Motor.h>

Servo servo1;

// Need to figure out how fast the motor should turn in each direction
void task_motor_1 (void* data)
{

    for (;;)
    {
        // Get fundamental frequency
        uint8_t hz = fft_share_gx.get();

        // Turn frequency into ms
        uint16_t x = 1000/hz;

        // Motor will change direction at equal speed every x ms
        vTaskDelay(x);


    }
}