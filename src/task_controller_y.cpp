// /*  This task needs to take all of the data and decide what to do with it.
//     All direct 

// */
// #include <Arduino.h>
// #include <task_imu_data_y.h>
// #include <I2Cdev.h>
// #include <MPU6050.h>
// #include <STM32FreeRTOS.h>
// #include <shares.h>
// #include <task_controller_y.h>
// #include <Motor.h>

// Motor motor1;
// Motor motor2;

// const int16_t queue_size = 256;
// int16_t theta_x[queue_size], theta_y[queue_size];
// float omega_x[queue_size], omega_y[queue_size];

// void task_controller_y(void* gydata)
// {
//     for(;;)
//     {
//         // Get imu queue data
//         *theta_y = imu_queue_gy.get();

//         // Calculate angualar velocity, put values into new array
//         for (uint8_t index = 1; index < queue_size; index++)
//         {
//             omega_y[index] = (theta_y[index] - theta_y[index-1])*(180/3.14)/100;
//         }

//         // Input share data into motor class to get output value
//         //int16_t gx = motor1.change(gx_queue);
//         //int16_t gy = motor2.change(gy_queue);

//         // Get FFT data
//         int16_t gx_fft = fft_share_gx.get();
//         int16_t gy_fft = fft_share_gy.get();

        
//     }
// }