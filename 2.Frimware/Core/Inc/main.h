/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define MOTOR_R_PWM_Pin GPIO_PIN_0
#define MOTOR_R_PWM_GPIO_Port GPIOA
#define MOTOR_L_PWM_Pin GPIO_PIN_1
#define MOTOR_L_PWM_GPIO_Port GPIOA
#define MPU_TX_Pin GPIO_PIN_2
#define MPU_TX_GPIO_Port GPIOA
#define MPU_RX_Pin GPIO_PIN_3
#define MPU_RX_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_4
#define KEY1_GPIO_Port GPIOA
#define KEY2_Pin GPIO_PIN_5
#define KEY2_GPIO_Port GPIOA
#define L_ENCODER_A_Pin GPIO_PIN_6
#define L_ENCODER_A_GPIO_Port GPIOA
#define L_ENCODER_B_Pin GPIO_PIN_7
#define L_ENCODER_B_GPIO_Port GPIOA
#define RMO1_Pin GPIO_PIN_12
#define RMO1_GPIO_Port GPIOB
#define RMO2_Pin GPIO_PIN_13
#define RMO2_GPIO_Port GPIOB
#define OLED_SCL_Pin GPIO_PIN_14
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_15
#define OLED_SDA_GPIO_Port GPIOB
#define LMO1_Pin GPIO_PIN_11
#define LMO1_GPIO_Port GPIOA
#define LMO2_Pin GPIO_PIN_12
#define LMO2_GPIO_Port GPIOA
#define key_Pin GPIO_PIN_4
#define key_GPIO_Port GPIOB
#define R_ENCODER_A_Pin GPIO_PIN_6
#define R_ENCODER_A_GPIO_Port GPIOB
#define R_ENCODER_B_Pin GPIO_PIN_7
#define R_ENCODER_B_GPIO_Port GPIOB
#define MPU6050_SCL_Pin GPIO_PIN_8
#define MPU6050_SCL_GPIO_Port GPIOB
#define MPU6050_SDA_Pin GPIO_PIN_9
#define MPU6050_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
