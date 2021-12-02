#include <Arduino.h>
#include <STM32FreeRTOS.h>
#include <task_controller_x.h>
#include <task_fft.h>
#include <task_imu_data_x.h>
#include <task_imu_data_y.h>
#include <shares.h>
#include <taskshare.h>
#include <taskqueue.h>
#include <complex>
#include <fft.h>
#include <MPU6050.h>


#define LED_PIN 13
bool blinkState = false;

MPU6050 mpu;

//Share<float> imu_share_gx ("gx Data");

//Share<float> fft_share_gx ("FFT gx Data");

//Queue<float> imu_queue_gx (256, "gx Data");

void setup() 
{
 #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif

    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(115200);

    // initialize device
    Serial.println("Initializing I2C devices...");
    mpu.initialize();

    delay(4000);

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    // use the code below to change accel/gyro offset values
    /*
    Serial.println("Updating internal sensor offsets...");
    // -76	-2359	1688	0	0	0
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    accelgyro.setXGyroOffset(220);
    accelgyro.setYGyroOffset(76);
    accelgyro.setZGyroOffset(-85);
    Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
    Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
    Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
    Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
    Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
    Serial.print("\n");
    */

    // configure Arduino LED pin for output
    pinMode(LED_PIN, OUTPUT);

  xTaskCreate(task_imu_data_x,
              "Data Acq.",
              1024,
              NULL,
              1,
              NULL);
  
  xTaskCreate(task_controller_x,
              "Control",
              1024,
              NULL,
              2,
              NULL);

  xTaskCreate(task_fft,
              "FFT",
              512,
              NULL,
              6,
              NULL);

//   complex *gxfft = new complex[queue_size];
//   complex *gyfft = new complex[queue_size];
//   complex gxnew;
//   complex gynew;

//     //Fill the complex arrays with imu data
//     for (uint8_t index = 0; index < queue_size; index++)
//     {
//       gxfft[index] = gx[index];
//       gyfft[index] = gy[index];
//     }

//     //Performing forward FFT on x and y gyro data
//     CFFT::Forward(gxfft, queue_size);
//     CFFT::Forward(gyfft, queue_size);

//     //Getting real values
//     for(uint8_t index = 0; index < queue_size; index++)
//     {
//       gxnewnewre[index] = gxfft->re();
//       gxnewnewim[index] = gxfft->im();

//     }
    
// Serial.println(gxnewnewre[1]);
// Serial.println(gxnewnewim[1]);

}

void loop() {
  
}