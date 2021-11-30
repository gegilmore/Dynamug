#ifndef _SHARES_H_
#define _SHARES_H_

#include <taskqueue.h>
#include <taskshare.h>

extern Share<int16_t> imu_share_gx ("gx Data");
extern Share<int16_t> imu_share_gy ("gy Data");

extern Queue<int16_t> imu_queue_gx (256, "gx Data");
extern Queue<int16_t> imu_queue_gy (256, "gy Data");

#endif