/*
 * encoder.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Xintong Jiang
 */
#include "main.h"
#include "tim.h"

short Encoder_Cot_R,Encoder_Cot_L;	//Encoder_Cot_R：右轮的编码器边缘数目; Encoder_Cot_L：左轮的编码器边缘数目
float Encoder_Speed_R,Encoder_Speed_L;	//Encoder_Speed_R：右轮速度; Encoder_Speed_L：左轮速度
uint8_t Encoder_Dir_R,Encoder_Dir_L;	//Encoder_Dir_R：右轮的转动方向; Encoder_Dir_L：左轮的转动方向
uint32_t Encoder_Speed_R_1,Encoder_Speed_R_2;		//Encoder_Speed_R_1:float类型变量Encoder_Speed_R小数点后1位; Encoder_Speed_R_2：float类型变量Encoder_Speed_R小数点后2位
uint32_t Encoder_Speed_L_1,Encoder_Speed_L_2;		//Encoder_Speed_L_1:float类型变量Encoder_Speed_L小数点后1位; Encoder_Speed_L_2：float类型变量Encoder_Speed_L小数点后2位

extern uint8_t R_Encoder_Speed_Judge;	//判断是否进入右轮电机测速程序（0/1）
extern uint8_t L_Encoder_Speed_Judge;	//判断是否进入左轮电机测速程序（0/1）

extern float Jy61_X_Angle;

//==================================================================
//函 数 名：Get_Encoder_Cot_R
//功能描述：右轮编码器捕捉到的边沿数
//输入参数：void
//返 回 值：Encoder_Cot_R
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
short Get_Encoder_Cot_R(void)
{
	Encoder_Cot_R= (short)__HAL_TIM_GET_COUNTER(&htim4);


	__HAL_TIM_SET_COUNTER(&htim4,0);	//计数清零

	Encoder_Cot_R=-1*Encoder_Cot_R;

	return Encoder_Cot_R;
}

//==================================================================
//函 数 名：Get_Encoder_Cot_L
//功能描述：左轮编码器捕捉到的边沿数
//输入参数：void
//返 回 值：Encoder_Cot_L
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
short Get_Encoder_Cot_L(void)
{
	Encoder_Cot_L= (short)__HAL_TIM_GET_COUNTER(&htim3);

	__HAL_TIM_SET_COUNTER(&htim3,0);	//计数清零

	return Encoder_Cot_L;
}

//==================================================================
//函 数 名：Get_Encoder_Dir_R
//功能描述：右轮编码器方向
//输入参数：void
//返 回 值：Encoder_Dir_R
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
uint8_t Get_Encoder_Dir_R(void)
{
	Encoder_Dir_R= __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim4);

	return Encoder_Dir_R;
}

//==================================================================
//函 数 名：Get_Encoder_Dir_L
//功能描述：左轮编码器方向
//输入参数：void
//返 回 值：Encoder_Dir_L
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
uint8_t Get_Encoder_Dir_L(void)
{
	Encoder_Dir_L= __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3);

	return Encoder_Dir_L;
}

//==================================================================
//函 数 名：Get_Encoder_Speed_R
//功能描述：获取右轮速度
//输入参数：Cot_In 右轮编码器捕捉到的边沿数
//返 回 值：Encoder_Speed_R
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.2
//==================================================================
float Get_Encoder_Speed_R(void)
{
	if(R_Encoder_Speed_Judge==1)		//每0.2s 变量R_Encoder_Speed_Judge置为1进行计算。
	{
		Encoder_Speed_R = (0.013 * Get_Encoder_Cot_R()) / 0.02;
		R_Encoder_Speed_Judge=0;
	}
	else if(R_Encoder_Speed_Judge==0)
		Encoder_Speed_R=Encoder_Speed_R;

	return Encoder_Speed_R;
}

//==================================================================
//函 数 名：Get_Encoder_Speed_L
//功能描述：获取左轮速度
//输入参数：Cot_In 左轮编码器捕捉到的边沿数
//返 回 值：Encoder_Speed_L
//作    者：蒋欣桐
//日    期：2022/12/06
//版    本：0.0
//==================================================================
float Get_Encoder_Speed_L(void)
{
	if(L_Encoder_Speed_Judge==1)
	{
		Encoder_Speed_L = (0.013 * Get_Encoder_Cot_L()) / 0.02;
		L_Encoder_Speed_Judge=0;
	}
	else if(L_Encoder_Speed_Judge==0)
		Encoder_Speed_L=Encoder_Speed_L;

	return Encoder_Speed_L;
}
