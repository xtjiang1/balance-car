/*
 * encoder.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Xintong Jiang
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

uint32_t Get_Encoder_Cot_R(void);	//右轮编码器捕捉到的边沿数
uint8_t Get_Encoder_Dir_R(void);	//右轮编码器方向

uint32_t Get_Encoder_Cot_L(void);	//左轮编码器捕捉到的边沿数
uint8_t Get_Encoder_Dir_L(void);	//左轮编码器方向

float Get_Encoder_Speed_R(void);	//获取右轮速度
float Get_Encoder_Speed_L(void);	//获取左轮速度

#endif /* INC_ENCODER_H_ */
