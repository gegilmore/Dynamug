#include <Arduino.h>
#include <task_controller.h>
#include <task_fft.h>
#include <task_imu_data.h>
#include <shares.h>
#include <taskshare.h>
#include <taskqueue.h>

Share<bool> begin_recording ("Recording");

Queue<int16_t> data_queue (1024, "Queue Data");

Share<int16_t> data_share ("Share Data");

void setup() 
{
  Serial.begin(115200);
  delay(3000);

  // xTaskCreate(task_imu_data,
  //             "Data Acq.",
  //             1024,
  //             NULL,
  //             1,
  //             NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
}