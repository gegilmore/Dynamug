// #include <Arduino.h>
// #include <STM32FreeRTOS.h>
// #include <task_imu_data_y.h>
// #include <I2Cdev.h>
// #include <MPU6050.h>
// #include <shares.h>
// #include <MPU6050_6Axis_MotionApps20.h>

// MPU6050 mpu;

// int16_t gx, gy, gz;

// uint8_t fifoBuffer[64];
// Quaternion q;
// float euler[3];

// void task_imu_data(void* imu_data_y)
// {
//     for (;;)
//     {
//         // Obtain x and y gyro data
//         //mpu.getRotationX();
//         //mpu.getRotationY();
//         mpu.dmpGetQuaternion(&q, fifoBuffer);
//         mpu.dmpGetEuler(euler, &q);

//         // Put gyro data for x and y into shared variable
//         imu_share_gy.put(euler[1]);

//         // Put gyro data for x and y into queues
//         imu_queue_gy.put(euler[1]);

//         vTaskDelay(10);
//     }
// }
