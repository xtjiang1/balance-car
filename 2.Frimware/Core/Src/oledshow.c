/*
 * oledshow.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Xintong Jiang
 */

#include "main.h"
#include "oled.h"
#include "encoder.h"
#include "Get_digits.h"
#include "usart.h"
#include "stdio.h"
#include "PID.h"
#include "Speed_Ring_PID.h"

uint8_t Show_R_Encoder_Cot[]="RM=";
uint8_t Show_L_Encoder_Cot[]="LM=";
uint8_t Show_Point[]=".";
uint8_t Show_cm_s[]="cm/s";
uint8_t Show_xAngle[]="xAng=";
uint8_t Show_minus[]="-";
uint8_t show_blank[]=" ";
uint8_t Show_AKp[]="AKp=",Show_AKd[]="AKd=";
uint8_t Show_SKp[]="SKp=",Show_SKi[]="SKi";

float Encoder_Speed_R_Show,Encoder_Speed_L_Show;	//Encoder_Speed_R：右轮速度显示中间变量; Encoder_Speed_L：左轮速度显示中间变量
uint32_t Encoder_Speed_R_Show_1,Encoder_Speed_R_Show_2;	//Encoder_Speed_R_Show_1：float类型变量Encoder_Speed_R_Show小数点后1位；Encoder_Speed_R_Show_2：float类型变量Encoder_Speed_R_Show小数点后2位
uint32_t Encoder_Speed_L_Show_1,Encoder_Speed_L_Show_2;	//Encoder_Speed_L_Show_1：float类型变量Encoder_Speed_L_Show小数点后1位；Encoder_Speed_L_Show_2：float类型变量Encoder_Speed_L_Show小数点后2位

extern float Jy61_X_Angle;	//jy61x轴翻滚角度
float Jy61_X_Angle_Show;	//jy61X轴翻滚角显示中间变量
uint32_t Jy61_X_Angle_Show_1,Jy61_X_Angle_Show_2;	//Jy61_X_Angle_Show_1：float类型变量Jy61_X_Angle_Show小数点后1位；Jy61_X_Angle_Show_2：float类型变量Jy61_X_Angle_Show小数点后2位

float Ang_Ring_Kp,Ang_Ring_Kd,Ang_Ring_OUT;
uint32_t Ang_Ring_Kp_1,Ang_Ring_Kd_1;
float Sp_Ring_Kp,Sp_Ring_Ki,Ang_Ring_OUT;
uint32_t Sp_Ring_Kp_1,Sp_Ring_Ki_1;

extern uint32_t Tim2_Count_0_2;	//TIM2执行的次数

//==================================================================
//函 数 名：Show_Encoder
//功能描述：编码器电机相关信息显示函数
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
void Show_Encoder(void)
{
	Encoder_Speed_R_Show=Get_Encoder_Speed_R();
	Encoder_Speed_L_Show=Get_Encoder_Speed_L();
	Encoder_Speed_R_Show_1=Get_digits(Encoder_Speed_R_Show, 1);
	Encoder_Speed_L_Show_1=Get_digits(Encoder_Speed_L_Show, 1);
	Encoder_Speed_R_Show_2=Get_digits(Encoder_Speed_R_Show, 2);
	Encoder_Speed_L_Show_1=Get_digits(Encoder_Speed_L_Show, 2);

	OLED_ShowString(0, 0, Show_R_Encoder_Cot, 8);
	OLED_ShowString(0, 1, Show_L_Encoder_Cot, 8);

	OLED_ShowNum(30, 0, Encoder_Speed_R_Show, 3, 8);
	OLED_ShowNum(30, 1, Encoder_Speed_L_Show, 3, 8);
	OLED_ShowString(45, 0, Show_Point, 8);
	OLED_ShowString(45, 1, Show_Point, 8);
	OLED_ShowNum(53, 0, Encoder_Speed_R_Show_1, 2, 8);
	OLED_ShowNum(53, 1, Encoder_Speed_L_Show_1, 2, 8);
	OLED_ShowNum(63, 0, Encoder_Speed_R_Show_2, 2, 8);
	OLED_ShowNum(63, 1, Encoder_Speed_L_Show_2, 2, 8);

	OLED_ShowString(73, 0, Show_cm_s, 8);
	OLED_ShowString(73, 1, Show_cm_s, 8);
}

//==================================================================
//函 数 名：Show_Jy61
//功能描述：Jy61相关信息显示函数
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/24
//版    本：0.0
//==================================================================
void Show_Jy61()
{
	Jy61_X_Angle_Show=Jy61_X_Angle;
	Jy61_X_Angle_Show_1=Get_digits(Jy61_X_Angle_Show, 1);
	Jy61_X_Angle_Show_2=Get_digits(Jy61_X_Angle_Show, 2);

	OLED_ShowString(0, 2, Show_xAngle, sizeof(Show_xAngle));

	if(Jy61_X_Angle_Show>=0)
	{
		OLED_ShowString(35, 2, show_blank, 12);
		OLED_ShowNum(40, 2, Jy61_X_Angle_Show,3 , 12);
		OLED_ShowString(60, 2, Show_Point, 12);
		OLED_ShowNum(65, 2, Jy61_X_Angle_Show_1,1 , 12);
		OLED_ShowNum(73, 2, Jy61_X_Angle_Show_2,1 , 12);
	}
	else if(Jy61_X_Angle_Show<=0)
	{
		Jy61_X_Angle_Show=-Jy61_X_Angle_Show;
		OLED_ShowString(35, 2, Show_minus, 12);
		OLED_ShowNum(40, 2, Jy61_X_Angle_Show,3 , 12);
		OLED_ShowString(60, 2, Show_Point, 12);
		OLED_ShowNum(65, 2, Jy61_X_Angle_Show_1,1 , 12);
		OLED_ShowNum(73, 2, Jy61_X_Angle_Show_2,1 , 12);
	}

}

//==================================================================
//函 数 名：Show_PID
//功能描述：位置式PID参数显示程序
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/1/29
//版    本：0.1
//==================================================================
void Show_PID(void)
{
	Ang_Ring_Kp=sp_pid.Speed_Ring_Kp;
	Ang_Ring_Kp_1=Get_digits(Ang_Ring_Kp, 1);
	Ang_Ring_Kd=pid.Kd;
	Ang_Ring_Kd_1=Get_digits(Ang_Ring_Kd, 1);

	OLED_ShowString(0, 3, Show_AKp, sizeof(Show_AKp));
	OLED_ShowNum(30, 3, Ang_Ring_Kp, 3, 12);
	OLED_ShowString(50, 3, Show_Point, 12);
	OLED_ShowNum(55, 3, Ang_Ring_Kp_1, 1, 12);
	OLED_ShowString(62, 3, Show_AKd, sizeof(Show_AKd));
	OLED_ShowNum(90, 3, Ang_Ring_Kd, 3, 12);
	OLED_ShowString(110, 3, Show_Point, 12);
	OLED_ShowNum(115, 3, Ang_Ring_Kd_1, 1, 12);



}

//==================================================================
//函 数 名：OLED_Show
//功能描述：OLED显示函数
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/05
//版    本：0.0
//==================================================================
void OLED_Show(void)
{
	Show_Encoder();
	Show_Jy61();
	Show_PID();
}
