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
        // Obtain x and y gyro data
        mpu.getRotationX();
        mpu.getRotationY();

        // Put gyro data for x and y into shared variable
        imu_share_gx.put(gx);
        imu_share_gy.put(gy);

        // Put gyro data for x and y into queues
        imu_queue_gx.put(gx);
        imu_queue_gy.put(gy);
    }
}
