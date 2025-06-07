/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <string.h>

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define PACKAGE_HEADER 0xAB
#define PACKAGE_FOOTER 0x55
#define BUFFER_SIZE 1024
//定义队列结构和必要变量
#define UART_QUEUE_SIZE 10                    // 队列可以存储的消息数量
#define MAX_MESSAGE_SIZE BUFFER_SIZE          // 每条消息的最大尺寸

// 队列结构体定义
typedef struct {
    uint8_t data[MAX_MESSAGE_SIZE];           // 消息数据
    uint16_t size;                            // 消息长度
} UartMessage;

// 队列变量
typedef struct {
  UartMessage messages[UART_QUEUE_SIZE];    // 消息数组
  uint8_t read_index;                       // 读指针
  uint8_t write_index;                      // 写指针
  uint8_t count;                            // 当前队列中的消息数量
  volatile uint8_t busy;                    // 队列忙标志，用于防止并发访问
} UartQueue;




/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */
void UART_Queue_Init(void);
uint8_t UART_Queue_Put(UartQueue* queue, uint8_t* data, uint16_t size);
uint8_t UART_Queue_Get(UartQueue* queue, uint8_t* data, uint16_t* size);
void UART_Process_Data(void);
void Reorder_And_Compress(uint8_t *input, uint8_t *output, uint16_t *out_len);
void Send_With_Header(UART_HandleTypeDef *huart, uint8_t *data, uint16_t total_len,uint8_t packet_type);

// void HAL_UART_IDLECallback(UART_HandleTypeDef *huart);
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

