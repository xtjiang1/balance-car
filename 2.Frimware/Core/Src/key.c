/*
 * key.c
 *
 *  Created on: Jan 28, 2023
 *      Author: jxt
 */


#include "main.h"
#include "pid.h"
#include "Speed_Ring_PID.h"

#define Key1 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)
#define Key2 HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)

//==================================================================
//函 数 名：Key_Scan
//功能描述：K1 K2按键扫描函数
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/1/29
//版    本：1.0
//==================================================================
void Key_Scan(void)
{
	if(Key1==GPIO_PIN_RESET)
	{
		HAL_Delay(10);
		if(Key1==GPIO_PIN_RESET)
		{
			while(Key1==GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			sp_pid.Speed_Ring_Kp=sp_pid.Speed_Ring_Kp+0.03;
			HAL_Delay(10);
		}
	}

	if(Key2==GPIO_PIN_RESET)
	{
		HAL_Delay(10);
		if(Key2==GPIO_PIN_RESET)
		{
			while(Key2==GPIO_PIN_RESET);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			sp_pid.Speed_Ring_Kp=sp_pid.Speed_Ring_Kp-0.03;
			HAL_Delay(10);
		}
	}
}
