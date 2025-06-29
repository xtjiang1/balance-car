/*
 * Speed_Ring_PID.c
 *
 *  Created on: Jan 26, 2023
 *      Author: jxt
 */


#include "Speed_Ring_PID.h"
#include "encoder.h"
#include "motor.h"

float Speed_Ring_OUT_Temp;
float Speed_Ring_Pout,Speed_Ring_Iout,Speed_Ring_Dout;
float Speed_Ring_DertEk;
float PID_Speed_Ring_PWM;

Speed_Ring_PID sp_pid;

//==================================================================
//函 数 名：Speed_Ring_PID_Init
//功能描述：速度环环位置式PID初始化程序
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/1/28
//版    本：0.0
//==================================================================
void Speed_Ring_PID_Init(void)
{
	sp_pid.Speed_Ring_Sv=0;
	sp_pid.Speed_Ring_T=2;
	sp_pid.Speed_Ring_Kp=5.26;
	sp_pid.Speed_Ring_Ki=sp_pid.Speed_Ring_Kp/200;
	sp_pid.Speed_Ring_Kd=0;
	sp_pid.Speed_Ring_PWM_T=100;
}

//==================================================================
//函 数 名：Speed_Ring_PID_Cal
//功能描述：速度环环位置式PID计算程序
//输入参数：void
//返 回 值：float Speed_Ring_OUT_Temp；
//作    者：蒋欣桐
//日    期：2022/1/28
//版    本：0.0
//==================================================================
float Speed_Ring_PID_Cal(void)
{
	if(sp_pid.Speed_Ring_1ms>sp_pid.Speed_Ring_T)
	{
		sp_pid.Speed_Ring_Pv=Get_Encoder_Speed_L()+Get_Encoder_Speed_R();

		sp_pid.Speed_Ring_Ek=sp_pid.Speed_Ring_Sv-sp_pid.Speed_Ring_Pv;
		Speed_Ring_Pout=sp_pid.Speed_Ring_Kp*sp_pid.Speed_Ring_Ek;

		sp_pid.Speed_Ring_Sek+=sp_pid.Speed_Ring_Ek;
		Speed_Ring_Iout=sp_pid.Speed_Ring_Ki*sp_pid.Speed_Ring_Sek;

		Speed_Ring_DertEk=sp_pid.Speed_Ring_Ek-sp_pid.Speed_Ring_Ek_1;
		Speed_Ring_Dout=Speed_Ring_DertEk*sp_pid.Speed_Ring_Kd;

		Speed_Ring_OUT_Temp=Speed_Ring_Pout+Speed_Ring_Iout+Speed_Ring_Dout+sp_pid.Speed_Ring_OUT0;

		sp_pid.Speed_Ring_Ek_1=sp_pid.Speed_Ring_Ek;
		sp_pid.Speed_Ring_1ms=0;
	}
	return Speed_Ring_OUT_Temp;
}
