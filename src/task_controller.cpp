#include <Arduino.h>
#include <task_imu_data.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <STM32FreeRTOS.h>
#include <shares.h>
#include <task_controller.h>

void task_controller(void* gxdata, void* gydata)
{
    for(;;)
    {
        int16_t gx = imu_share_gx.get();
        int16_t gy = imu_share_gy.get();

        if(gx > 1000 || gx < 1000) 
        {

            

        }
    }
}