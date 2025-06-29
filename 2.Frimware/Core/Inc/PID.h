/*
 * PID.h
 *
 *  Created on: 2022年12月31日
 *      Author: jxt
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "main.h"

typedef struct
{
	float Sv;	//用户设定值
	float Pv;	//当前数值

	float Kp;	//比例系数
	float T;	//PID计算周期——采样周期
	float Ki;	//积分时间常数
	float Kd;	//微分系数

	float Ek;	//时间序列中此时刻的偏差
	float Ek_1;	//时间序列中上一次的偏差
	float Sek;	//历史偏差之和

	float OUT0;
	float OUT;	//输出的控制量

	uint32_t PID_1ms;
	uint32_t PWM_T;
}PID;

void PID_Init(void);
float PID_Cal(void);
void PID_Control(void);

extern PID pid;	//存储PID算法所需数据

#endif /* INC_PID_H_ */
