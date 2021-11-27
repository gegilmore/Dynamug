#include <Arduino.h>
#include <task_imu_data.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <STM32FreeRTOS.h>
#include <shares.h>
#include <task_controller.h>

void task_controller(void* gxdata, void* gydata);
{
    for(;;)
    {
        if(gxdata[0] > 1000 || gxdata[0] < 1000) 
        {
            data_share.put(*gxdata);

        }
    }
}