/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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

void SetMotorPWM(uint8_t motor, uint8_t percentage);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MotorID_Left_Up 0x0
#define MotorID_Left_Low 0x4
#define MotorID_Right_Up 0x8
#define MotorID_Right_Low 0xC
#define Status_LED_Pin GPIO_PIN_13
#define Status_LED_GPIO_Port GPIOC
#define Landing_Lights_Pin GPIO_PIN_14
#define Landing_Lights_GPIO_Port GPIOC
#define Right_Up_Pot_Pin GPIO_PIN_0
#define Right_Up_Pot_GPIO_Port GPIOA
#define Right_Low_Front_Pot_Pin GPIO_PIN_1
#define Right_Low_Front_Pot_GPIO_Port GPIOA
#define Right_Low_Back_Pot_Pin GPIO_PIN_2
#define Right_Low_Back_Pot_GPIO_Port GPIOA
#define Left_Up_Pot_Pin GPIO_PIN_3
#define Left_Up_Pot_GPIO_Port GPIOA
#define Left_Low_Front_Pot_Pin GPIO_PIN_4
#define Left_Low_Front_Pot_GPIO_Port GPIOA
#define Left_Low_Back_Pot_Pin GPIO_PIN_5
#define Left_Low_Back_Pot_GPIO_Port GPIOA
#define Left_Low_Lock_Pin GPIO_PIN_10
#define Left_Low_Lock_GPIO_Port GPIOB
#define Left_Up_Lock_Pin GPIO_PIN_11
#define Left_Up_Lock_GPIO_Port GPIOB
#define Right_Low_Lock_Pin GPIO_PIN_12
#define Right_Low_Lock_GPIO_Port GPIOB
#define Right_Up_Lock_Pin GPIO_PIN_13
#define Right_Up_Lock_GPIO_Port GPIOB
#define Suspension_Lock_Pin GPIO_PIN_14
#define Suspension_Lock_GPIO_Port GPIOB
#define Left_Low_Motor_Pin GPIO_PIN_8
#define Left_Low_Motor_GPIO_Port GPIOA
#define Left_Up_Motor_Pin GPIO_PIN_9
#define Left_Up_Motor_GPIO_Port GPIOA
#define Right_Low_Motor_Pin GPIO_PIN_10
#define Right_Low_Motor_GPIO_Port GPIOA
#define Right_Up_Motor_Pin GPIO_PIN_11
#define Right_Up_Motor_GPIO_Port GPIOA
#define MSP_TX_Pin GPIO_PIN_6
#define MSP_TX_GPIO_Port GPIOB
#define MSP_RX_Pin GPIO_PIN_7
#define MSP_RX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
