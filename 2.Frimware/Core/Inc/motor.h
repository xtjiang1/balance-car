/*
 * motor.h
 *
 *  Created on: Dec 12, 2022
 *      Author: HP
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

void Right_Motor_Foward(void);
void Right_Motor_Reverse(void);
void Right_Motor_PWM_Set(uint32_t Right_Motor_PWM);
void Light_Motor_Foward(void);
void Light_Motor_Reverse(void);
void Light_Motor_PWM_Set(uint32_t Light_Motor_PWM);

#endif /* INC_MOTOR_H_ */
