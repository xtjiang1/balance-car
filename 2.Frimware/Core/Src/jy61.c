/*
 * jy61.c
 *
 *  Created on: 2022年12月23日
 *      Author: jxt
 */


#include "usart.h"
#include "PID.h"
#include "Data_To_Matlab.h"


uint8_t Jy61_Rx;	//串口接收到的单个hex数据
uint8_t Jy61_Data[11];	//串口接收到的通信协议完整数据包
uint8_t Jy61_Angle_Data[11];	//翻滚角度串口接收到的原始数据
uint32_t Rx_Count;	//进入串口中断的次数，用于判断数据包是否打包完成
float Jy61_X_Angle;		//jy61x轴翻滚角度
float Jy61_Angle_Temp;


//==================================================================
//函 数 名：Jy61_Cal
//功能描述：计算串口接收到jy61的数据
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/24
//版    本：1.0
//==================================================================
void Jy61_Cal(void)
{
	Jy61_Angle_Temp=Jy61_Angle_Data[3]<<8|Jy61_Angle_Data[2];	//x轴hex数据高八位低八位计算
	Jy61_X_Angle=Jy61_Angle_Temp/32768*180;		//x轴翻滚角计算
	if(Jy61_X_Angle>180)
		Jy61_X_Angle=Jy61_X_Angle-360;
	pid.Pv=Jy61_X_Angle;
	//Dec_To_Hex(Jy61_X_Angle);
}

//==================================================================
//函 数 名：Jy61_RXData
//功能描述：串口接收jy61所发的数据
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/24
//版    本：1.0
//==================================================================
void Jy61_RXData(void)
{
	Jy61_Data[Rx_Count]=Jy61_Rx;	//将接收到的单个hex数据存储

	if(Jy61_Data[0]==0x55)		//判断是否读取到包头，读取到包头后进入
	{
		Rx_Count++;
		if(Rx_Count>=11)	//判断数据包是否打包好
		{
			Rx_Count=0;		//计数清零
			switch(Jy61_Data[1])	//判断接收到的数据内容是什么
			{
				case 0x53:		//接收到翻滚角
				{
					for(Rx_Count=0;Rx_Count<11;Rx_Count++)		//存储到Jy61_Angle_Data中
						Jy61_Angle_Data[Rx_Count]=Jy61_Data[Rx_Count];
					Jy61_Cal();		//计算数据
					for(Rx_Count=0;Rx_Count<11;Rx_Count++)
						Jy61_Data[Rx_Count]=0;		//存储空间清零
				}
			}
		}
	}
	else if(Jy61_Data[0]!=0x55)		//未接收到包头
	{
		Rx_Count=0;
	}
}
