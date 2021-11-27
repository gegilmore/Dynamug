#ifndef _SHARES_H_
#define _SHARES_H_

#include <taskqueue.h>
#include <taskshare.h>

extern Share<int16_t> imu_share_gx;
extern Share<int16_t> imu_share_gy;

extern Queue<int16_t> imu_queue_gx;
extern Queue<int16_t> imu_queue_gy;

#endif