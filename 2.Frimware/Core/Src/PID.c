/*
 * PID.c
 *
 *  Created on: 2022年12月31日
 *      Author: jxt
 */


#include "PID.h"
#include "motor.h"
#include "Speed_Ring_PID.h"

float Dert_Ek;
float ti,ki;
float td,kd;
float Iout,Pout,Dout;
float OUT_Temp;

float PID_PWM;
float PID_PWM_Temp;

PID pid;	//存储PID算法所需数据

//==================================================================
//函 数 名：PID_Init
//功能描述：直立环位置式PID初始化程序
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/1/12
//版    本：0.0
//==================================================================
void PID_Init(void)
{
	pid.Sv=0;	//用户设定角度
	pid.T=2;	//PID计算周期(ms)
	pid.Kp=32.8*0.6;
	pid.Ki=0;
	pid.Kd=130.6*0.6;//98.8*0.6;
	pid.PWM_T=100;
}

//==================================================================
//函 数 名：PID_Cal
//功能描述：直立环位置式PID计算程序
//输入参数：void
//返 回 值：float
//作    者：蒋欣桐
//日    期：2022/1/12
//版    本：0.0
//==================================================================
float PID_Cal(void)	//PID计算
{
	if(pid.PID_1ms>=pid.T)	//判断是否到达计算周期
	{
		pid.Ek=pid.Sv-pid.Pv;	//得到当前的偏差
		Pout=pid.Kp*pid.Ek;	//比例输出

		pid.Sek+=pid.Ek;	//历史偏差总和
		Iout=pid.Ki*pid.Sek;	//积分项输出

		Dert_Ek=pid.Ek-pid.Ek_1;	//最近两次偏差之差
		Dout=pid.Kd*Dert_Ek;	//微分项输出

		OUT_Temp=Pout+Iout+Dout+pid.OUT0;	//本次计算结果

		pid.Ek_1=pid.Ek;

		pid.PID_1ms=0;	//计数清零
	}
	return OUT_Temp;
}

//==================================================================
//函 数 名：PID_Ang_Control
//功能描述：直立环位置式PID输出程序
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/1/12
//版    本：0.0
//==================================================================
void PID_Control(void)
{
	PID_PWM=PID_Cal()+Speed_Ring_PID_Cal();
	PID_PWM_Temp=PID_PWM;
	if(PID_PWM<0)
		PID_PWM=-PID_PWM;

	Right_Motor_PWM_Set(PID_PWM/10);
	Light_Motor_PWM_Set(PID_PWM/10);
	if(PID_PWM_Temp>=20)
	{
		Right_Motor_Reverse();
		Light_Motor_Reverse();
	}
	else if(PID_PWM_Temp<=-20)
	{
		Right_Motor_Foward();
		Light_Motor_Foward();
	}
}
