#include <Arduino.h>
#include <task_imu_data.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <STM32FreeRTOS.h>
#include <task_fft.h>
#include <fft.h>
#include <shares.h>

int16_t gx[1024], gy[1024];

void task_fft(void* newgxdata, void* newgydata)
{

    for(;;) 
    {
        for (uint16_t index = 0; index < 1024; index++)
        {
            gx[index] = imu_queue_gx.get();
            gy[index] = imu_queue_gy.get();

            

            complex *gx = new complex[1024];
            complex *gy = new complex[1024];

            CFFT::Forward(gx, 1024);
            CFFT::Forward(gy, 1024);
        }
    }
        
}