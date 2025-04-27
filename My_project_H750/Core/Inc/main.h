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
#define MAX_USERS 3
typedef struct {
  uint8_t username[3];  // 用户名
  uint32_t base_block;             // 用户扇区起始地址
  uint32_t next_offset;            // 当前写入偏移量（相对 base）
} UserIndex;

typedef struct {
  uint16_t flag;                   // 0xAA55
  UserIndex users[MAX_USERS];           // 用户索引(最多3个用户)
} IndexSector;
typedef struct {
  uint16_t flag;          // 标志位
  uint32_t next_block;    // 下一个写入扇区
  uint8_t username[MAX_USERS];    // 用户名
} IndexInfo; //扇区索引信息

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

/* USER CODE BEGIN Private defines */
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
