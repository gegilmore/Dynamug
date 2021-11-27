#include <Arduino.h>
#include <task_imu_data.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <STM32FreeRTOS.h>
#include <shares.h>

MPU6050 mpu;

int16_t gx, gy, gz;

void task_imu_data(void* gxdata, void* gydata)
{
    for (;;)
    {
        mpu.getRotation(&gx, &gy, &gz);

        if (gx > 1000 || gx < -1000)    // Arbitrary condition. Need to somehow determine when data should be put share vs. queue
        {
            imu_share_gx.put(gx);
        }
        else
        {
            imu_queue_gx.put(gx);
        }
        
        if (gx > 1000 || gx < -1000)
        {
            imu_share_gy.put(gy);
        }
        else
        {
            imu_queue_gy.put(gy);
        }
        
    }
}
