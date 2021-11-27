#include <Arduino.h>
#include <STM32FreeRTOS.h>

#ifndef _TASK_IMU_DATA_
#define _TASK_IMU_DATA_

void task_imu_data(void* gxdata, void* gydata);

#endif