/*
 * motor.c
 *
 *  Created on: Dec 12, 2022
 *      Author: jxt
 */


#include "main.h"
#include "gpio.h"
#include "tim.h"

#define Right_Motor_IN1_Hight HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);	//右侧电机IN1给高
#define Right_Motor_IN1_Low HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);	//右侧电机IN1给低
#define Right_Motor_IN2_Hight HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);	//右边侧电机IN2给高
#define Right_Motor_IN2_Low HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);	//右侧电机IN2给低
#define Light_Motor_IN1_Hight HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);	//左侧电机IN1给高
#define Light_Motor_IN1_Low HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);	//左侧电机IN1给低
#define Light_Motor_IN2_Hight HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);	//左侧电机IN2给高
#define Light_Motor_IN2_Low HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);	//左侧电机IN2给低

//RM1:PB12 RM2:PB13
//LM1：PA11 LM2:PA12

//==================================================================
//函 数 名：Right_Motor_Foward
//功能描述：右轮向前转
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/12
//版    本：0.0
//==================================================================
void Right_Motor_Foward(void)
{
	Right_Motor_IN1_Hight;
	Right_Motor_IN2_Low;
}

//==================================================================
//函 数 名：Right_Motor_Reverse
//功能描述：右轮向后转
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/12
//版    本：0.0
//==================================================================
void Right_Motor_Reverse(void)
{
	Right_Motor_IN1_Low;
	Right_Motor_IN2_Hight;
}

//==================================================================
//函 数 名：Right_Motor_PWM_Set
//功能描述：右轮设定PWM
//输入参数：Right_Motor_PWM
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/13
//版    本：0.0
//==================================================================
void Right_Motor_PWM_Set(uint32_t Right_Motor_PWM)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,Right_Motor_PWM);
}

//==================================================================
//函 数 名：Light_Motor_Foward
//功能描述：左轮向前转
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/13
//版    本：0.0
//==================================================================
void Light_Motor_Foward(void)
{
	Light_Motor_IN1_Low;
	Light_Motor_IN2_Hight;
}

//==================================================================
//函 数 名：Light_Motor_Reverse
//功能描述：左轮向后转
//输入参数：void
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/13
//版    本：0.0
//==================================================================
void Light_Motor_Reverse(void)
{
	Light_Motor_IN1_Hight;
	Light_Motor_IN2_Low;

}

//==================================================================
//函 数 名：Light_Motor_PWM_Set
//功能描述：左轮设定PWM
//输入参数：Light_Motor_PWM
//返 回 值：void
//作    者：蒋欣桐
//日    期：2022/12/13
//版    本：0.0
//==================================================================
void Light_Motor_PWM_Set(uint32_t Light_Motor_PWM)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,Light_Motor_PWM);
}
