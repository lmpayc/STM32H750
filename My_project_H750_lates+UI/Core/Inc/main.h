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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "lvgl.h"
#include "lv_port_disp.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

#define  REAED_BUFFER_SIZE 5120



typedef struct {
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minute;
  uint8_t study_time;  //本次学习时间
} TimeData;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t gensture;
extern uint8_t start_flag;
extern bool pause_time_flag;
extern uint16_t right_sitted_time;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
void sendStringData(UART_HandleTypeDef *huart, const char *str);
void sendBinaryData(UART_HandleTypeDef *huart, uint8_t *data, uint16_t len);


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Gesture_MCLRP_Pin GPIO_PIN_2
#define Gesture_MCLRP_GPIO_Port GPIOE
#define Gensture_DPin_Pin GPIO_PIN_3
#define Gensture_DPin_GPIO_Port GPIOE
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define Noise_AO_Pin GPIO_PIN_0
#define Noise_AO_GPIO_Port GPIOC
#define Vcc_Detect_Pin GPIO_PIN_3
#define Vcc_Detect_GPIO_Port GPIOC
#define Tempure_AO_Pin GPIO_PIN_4
#define Tempure_AO_GPIO_Port GPIOC
#define Water_AO_Pin GPIO_PIN_1
#define Water_AO_GPIO_Port GPIOB
#define ESP8266_RST_Pin GPIO_PIN_2
#define ESP8266_RST_GPIO_Port GPIOB
#define Servo_Pin GPIO_PIN_4
#define Servo_GPIO_Port GPIOB
#define NFC_RESET_Pin GPIO_PIN_5
#define NFC_RESET_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
