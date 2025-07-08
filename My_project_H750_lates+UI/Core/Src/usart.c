/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "lvgl.h"
#include "ui.h"
#include "sd.h"
#include "gui_guider.h"

extern uint8_t uart1_buf_recv[BUFFER_SIZE];
extern UartQueue uart1_queue;
extern uint8_t uart2_buf_recv[256];
extern uint8_t uart3_buf_recv[256];

extern TimeData start_time;
extern TimeData current_time;
extern lv_obj_t * uart1_label;
extern lv_obj_t * label_time;

extern uint8_t timer1_pause;
extern uint8_t time_update_flag;
extern uint8_t time_received_flag;
extern  uint8_t wifi_connect_flag; 

extern uint8_t Temp_Readbuffer[REAED_BUFFER_SIZE];
uint8_t Packed_Data[REAED_BUFFER_SIZE];
uint16_t Packed_Len  = 0;   


extern uint8_t light_ref;  //led参考光照值
extern lv_ui  setting_ui; //设置界面对象
extern lv_ui main_ui; //主界面对象
extern uint8_t set_studytime; //app传来的设定学习时间
extern lv_obj_t * info_label;
extern uint16_t servo_feedback; //舵机参考值
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */
  
  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
  UART_Queue_Init();  // 初始化队列
  //HAL_UARTEx_ReceiveToIdle_IT(&huart1, uart1_buf_recv, sizeof(uart1_buf_recv));

  /* USER CODE END USART1_Init 2 */

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */
  HAL_UARTEx_ReceiveToIdle_IT(&huart2, uart2_buf_recv, sizeof(uart2_buf_recv));
  /* USER CODE END USART2_Init 2 */

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
  HAL_UARTEx_ReceiveToIdle_IT(&huart3, uart3_buf_recv, sizeof(uart3_buf_recv));


  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 DMA Init */
    /* USART1_RX Init */
    hdma_usart1_rx.Instance = DMA1_Stream0;
    hdma_usart1_rx.Init.Request = DMA_REQUEST_USART1_RX;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_CIRCULAR;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart1_rx);

    /* USART1_TX Init */
    hdma_usart1_tx.Instance = DMA1_Stream1;
    hdma_usart1_tx.Init.Request = DMA_REQUEST_USART1_TX;
    hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_tx.Init.Mode = DMA_NORMAL;
    hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart1_tx);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART2;
    PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
    PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);
    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PD8     ------> USART3_TX
    PD9     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_8|GPIO_PIN_9);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

// 队列初始化函数
void UART_Queue_Init(void)
{
    // 初始化队列参数
    uart1_queue.read_index = 0;
    uart1_queue.write_index = 0;
    uart1_queue.count = 0;
    uart1_queue.busy = 0;
}

// 添加消息到队列
uint8_t UART_Queue_Put(UartQueue* queue, uint8_t* data, uint16_t size)
{
    // 如果队列已满，返回错误
    if (queue->count >= UART_QUEUE_SIZE) {
        return 0; // 队列已满
    }
    
    // 禁用中断，防止并发访问
    __disable_irq();
    
    // 复制数据到队列中
    if (size > MAX_MESSAGE_SIZE) {
        size = MAX_MESSAGE_SIZE;
    }
    
    memcpy(queue->messages[queue->write_index].data, data, size);
    queue->messages[queue->write_index].size = size;
    
    // 更新写指针
    queue->write_index = (queue->write_index + 1) % UART_QUEUE_SIZE;
    queue->count++;
    
    // 重新启用中断
    __enable_irq();
    
    return 1; // 成功
}
// 从队列中获取消息
uint8_t UART_Queue_Get(UartQueue* queue, uint8_t* data, uint16_t* size)
{
    // 如果队列为空，返回错误
    if (queue->count == 0) {
        return 0; // 队列为空
    }
    
    // 禁用中断，防止并发访问
    __disable_irq();
    
    // 复制数据出队列
    memcpy(data, queue->messages[queue->read_index].data, queue->messages[queue->read_index].size);
    *size = queue->messages[queue->read_index].size;
    
    // 更新读指针
    queue->read_index = (queue->read_index + 1) % UART_QUEUE_SIZE;
    queue->count--;
    
    // 重新启用中断
    __enable_irq();
    
    return 1; // 成功
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART1) // 确保是 USART1
    {
        if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_FE)) {   //检查并清除错误标志
          __HAL_UART_CLEAR_FLAG(&huart1, UART_CLEAR_FEF);
        }

        if (Size >= BUFFER_SIZE)  
        {
            memset(uart1_buf_recv, 0, BUFFER_SIZE);
            // 丢弃数据，并重新开启接收
            HAL_UARTEx_ReceiveToIdle_IT(huart, uart1_buf_recv, BUFFER_SIZE);
            return;
        }

        if (Size > 0 && Size < BUFFER_SIZE)  // 确保收到数据
        {
            uart1_buf_recv[Size] = '\0'; // 确保字符串结尾
            // 将接收到的数据放入队列
            UART_Queue_Put(&uart1_queue, uart1_buf_recv, Size + 1); // +1 包含结束符
        }
        else {
            // 处理错误情况
            // 可以在这里添加错误处理代码
        }
        
        // 重新启动接收
        HAL_UARTEx_ReceiveToIdle_IT(huart, uart1_buf_recv, sizeof(uart1_buf_recv));
    }

    if (huart->Instance == USART2) // 确保是 USART2
    {
			if (Size >= 1 && start_flag && (!pause_time_flag)) 
			{ 
        if(uart2_buf_recv[0]<100){
          gensture = uart2_buf_recv[0];
          right_sitted_time+=(gensture==1);
        }
			}

      if(uart2_buf_recv[0]>100){
          servo_feedback=uart2_buf_recv[0]-100;
          lv_label_set_text_fmt(info_label, "servo_feedback: %d", servo_feedback);
      }


			HAL_UARTEx_ReceiveToIdle_IT(huart, uart2_buf_recv, sizeof(uart2_buf_recv));
      
    }

    if (huart->Instance == USART3) // 确保是 USART3
    {
      //HAL_UART_Transmit(&huart3, uart3_buf_recv, Size, 10); // 将接收到的数据回传
      HAL_UARTEx_ReceiveToIdle_IT(huart, uart3_buf_recv, sizeof(uart3_buf_recv));
    }
}




// 处理UART数据的函数（在主循环中调用）
void UART_Process_Data(void)
{
    uint8_t temp_buffer[MAX_MESSAGE_SIZE];
    uint16_t size;
    
    // 如果队列中有数据，进行处理
    while (UART_Queue_Get(&uart1_queue, temp_buffer, &size)) {
        // 确保字符串结尾
        temp_buffer[size - 1] = '\0';
        
        // 处理接收到的数据
        if (strncmp((char*)temp_buffer, "MQTT time", 9) == 0) {
            sendStringData(&huart1, (char*)"ctime?"); // 发送当前时间请求
            wifi_connect_flag = 0; // WIFI连接标志
        }
        else if (strncmp((char*)temp_buffer, "stime", 5) == 0) {
            // 获取时间消息
            sscanf((char*)temp_buffer + 5, "%2hhu%2hhu%2hhu%2hhu:%2hhu",
                &start_time.year, &start_time.month, &start_time.day,
                &start_time.hour, &start_time.minute);
            time_received_flag = 1; // 时间接收标志
            lv_label_set_text_fmt(uart1_label, "starttime: %s", temp_buffer);
        }
        else if (strncmp((char*)temp_buffer, "ctime", 5) == 0) {
            sscanf((char*)temp_buffer + 5, "%2hhu%2hhu%2hhu%2hhu:%2hhu",
                &current_time.year, &current_time.month, &current_time.day,
                &current_time.hour, &current_time.minute);
            char time_str[20];
            snprintf(time_str, sizeof(time_str), "%02d:%02d",current_time.hour, current_time.minute);
            lv_label_set_text(label_time, time_str);
            wifi_connect_flag = 1; // WIFI连接标志
        }

        else if (strncmp((char*)temp_buffer, "WIFI:", 5) == 0) {
              // 处理WIFI消息
              char *wifi_data = (char*)temp_buffer + 5;
              if(strncmp(wifi_data, "count", 5) == 0){   //统计指令匹配
                timer1_pause = 0; //暂停定时器
                
                Read_Latest_Session_Data(Temp_Readbuffer, sizeof(Temp_Readbuffer));  //读取最新文件
                
                Reorder_And_Compress(Temp_Readbuffer, Packed_Data,&Packed_Len); //重排数据
                Send_With_Header(&huart1, Packed_Data, Packed_Len,0x01); //发送类型1包数据

                timer1_pause = 1; //恢复定时器
              }
              // 处理 WIFI:light:<value> 指令
              else if (strncmp(wifi_data, "light:", 6) == 0) {
                  int value = atoi(wifi_data + 6);  // 提取数值部分
                  if (value >= 0 && value <= 100) { // 可加合法性判断
                      light_ref = value;
                      lv_slider_set_value(setting_ui.setting_light_slider, light_ref, LV_ANIM_OFF);
                  }
              }
        
              else if (strncmp(wifi_data, "study:", 6) == 0) {
                int value = atoi(wifi_data + 6);          // 取 <value>
                set_studytime = value;                // 更新目标学习时长（分钟）
                lv_label_set_text_fmt(main_ui.main_learning_time_setting_data, "%d", set_studytime);              
              }
        }      
        else {
            // MQTT消息
            lv_label_set_text_fmt(uart1_label, "uart1: %s", temp_buffer);
        }
    }
}



void Reorder_And_Compress(uint8_t *input, uint8_t *output, uint16_t *out_len)
{
    uint8_t N = input[0];
    uint16_t i;
    // 初始化目标数据各个段的起始位置
    uint16_t light_offset = 0;
    uint16_t temp_offset  = light_offset + N;
    uint16_t pose_offset  = temp_offset + (2 * N); // temp占2字节
    uint16_t time_offset  = pose_offset + N;
    
    for (i = 0; i < N; i++)
    {
        uint8_t light   = input[1 + i * 5 + 0];
        uint8_t t_int   = input[1 + i * 5 + 1];
        uint8_t t_dec   = input[1 + i * 5 + 2];
        uint8_t pose    = input[1 + i * 5 + 3];
        uint8_t noise = input[1 + i * 5 + 4];

        // 写入 light
        output[light_offset + i] = light;

        // 写入 temp（2字节）
        uint16_t temp_combined = t_int * 100 + t_dec;
        output[temp_offset + i * 2 + 0] = (uint8_t)(temp_combined >> 8);
        output[temp_offset + i * 2 + 1] = (uint8_t)(temp_combined & 0xFF);

        // 写入 pose
        output[pose_offset + i] = pose;

        // 写入 time
        output[time_offset + i] = noise;
    }

    // 输出总长度
    *out_len = time_offset + N;
}

void Send_With_Header(UART_HandleTypeDef *huart, uint8_t *data, uint16_t total_len,uint8_t packet_type)
{
    const uint8_t MAX_PAYLOAD = 94; // 剩下6字节用于头信息
    uint8_t total_packets = (total_len + MAX_PAYLOAD - 1) / MAX_PAYLOAD;
    uint8_t packet_id = 0;
    uint16_t offset = 0;

    while (offset < total_len)
    {
        uint8_t packet[100] = {0};
        uint8_t payload_len = (total_len - offset > MAX_PAYLOAD) ? MAX_PAYLOAD : (total_len - offset);
        
        // 构建包头
        packet[0] = PACKAGE_HEADER;                // 起始标志
        packet[1] = packet_id;           // 包编号
        packet[2] = total_packets;       // 总包数
        packet[3] = payload_len;         // 本包数据长度
        packet[4] = packet_type;       // 包类型
        // 可选：你也可以添加时间戳、校验和等
        
        memcpy(&packet[5], data + offset, payload_len);

        // 可选校验
        uint8_t checksum = 0;
        for (int i = 0; i < 5 + payload_len; i++) {
            checksum ^= packet[i];
        }
        packet[5 + payload_len] = checksum; // 第5位校验

        sendBinaryData(huart, packet, 6 + payload_len); // 总长度：5头 + payload + 1校验

        offset += payload_len;
        packet_id++;

        HAL_Delay(100); // 根据情况调整
    }
}


/* USER CODE END 1 */
