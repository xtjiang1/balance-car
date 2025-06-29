/*
 * Speed_Ring_PID.h
 *
 *  Created on: Jan 26, 2023
 *      Author: jxt
 */

#ifndef INC_SPEED_RING_PID_H_
#define INC_SPEED_RING_PID_H_

#include "main.h"

typedef struct
{
	float Speed_Ring_Sv;	//用户设定值
	float Speed_Ring_Pv;	//当前数值

	float Speed_Ring_Kp;	//比例系数
	float Speed_Ring_Ki;	//积分系数
	float Speed_Ring_Kd;	//微分系数
	float Speed_Ring_T;		//PID计算周期

	float Speed_Ring_Ek;	//时间序列中此时刻的偏差
	float Speed_Ring_Ek_1;	//时间序列中上一时刻的偏差
	float Speed_Ring_Sek;	//历史偏差之和

	float Speed_Ring_OUT0;
	float Speed_Ring_OUT;	//PID输出

	uint32_t Speed_Ring_1ms;
	uint32_t Speed_Ring_PWM_T;

}Speed_Ring_PID;

void Speed_Ring_PID_Init(void);
float Speed_Ring_PID_Cal(void);

extern Speed_Ring_PID sp_pid;	//存储PID算法所需数据

#endif /* INC_SPEED_RING_PID_H_ */
