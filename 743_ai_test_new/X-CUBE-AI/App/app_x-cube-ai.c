
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\[user_name]\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "network_cifar10.h"
#include "network_cifar10_data.h"

#include "mod_image.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_NETWORK_CIFAR10_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_NETWORK_CIFAR10_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_NETWORK_CIFAR10_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_NETWORK_CIFAR10_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_NETWORK_CIFAR10_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_NETWORK_CIFAR10_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_NETWORK_CIFAR10_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_NETWORK_CIFAR10_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_NETWORK_CIFAR10_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle network_cifar10 = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;
bool send = 0;
float last_prob_0=0,last_prob_1=0,last_prob_2=0;
float prob_0=0,prob_1=0,prob_2=0;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_network_cifar10_create_and_init(&network_cifar10, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_network_cifar10_create_and_init");
    return -1;
  }

  ai_input = ai_network_cifar10_inputs_get(network_cifar10, NULL);
  ai_output = ai_network_cifar10_outputs_get(network_cifar10, NULL);

#if defined(AI_NETWORK_CIFAR10_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_NETWORK_CIFAR10_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_NETWORK_CIFAR10_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_NETWORK_CIFAR10_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_NETWORK_CIFAR10_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_NETWORK_CIFAR10_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_network_cifar10_run(network_cifar10, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_network_cifar10_get_error(network_cifar10),
        "ai_network_cifar10_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_i8* data[])
{
  float* in_f32 = (float*) data[0];
  uint16_t i, j;
  uint16_t pixel;
  uint8_t r, g, b;
  uint32_t idx = 0;

  for(i = 0; i < Modified_Height; i++) {
    for(j = 0; j < Modified_Width; j++) {
      pixel = Process_Buffer[i][j];  // RGB565 格式

      // 从RGB565中提取R、G、B通道（5:6:5位）
      r = (uint8_t)((pixel >> 11) & 0x1F);
      g = (uint8_t)((pixel >> 5) & 0x3F);
      b = (uint8_t)(pixel & 0x1F);

      // 扩展到8位（0~255）
      r = (r << 3) | (r >> 2);  // 5位扩展为8位
      g = (g << 2) | (g >> 4);  // 6位扩展为8位
      b = (b << 3) | (b >> 2);  // 5位扩展为8位

      // 归一化到[-1.0, 1.0]并按通道顺序写入
      in_f32[idx++] = ((float)r / 127.5f) - 1.0f;  // R
      in_f32[idx++] = ((float)g / 127.5f) - 1.0f;  // G
      in_f32[idx++] = ((float)b / 127.5f) - 1.0f;  // B
    }
  }

  return 0;
}

int post_process(ai_i8* data[])
{
  float* out_f32 = (float*) data_outs[0];
	send=~send;

	last_prob_0=prob_0;last_prob_1=prob_1;last_prob_2=prob_2;
  prob_0=out_f32[0];prob_1=out_f32[1];prob_2=out_f32[2];
	
	if(send){
		float ave_0=(last_prob_0+prob_0)/2,ave_1=(last_prob_1+prob_1)/2,ave_2=(last_prob_2+prob_2)/2;
		float max_prob=ave_0;
		uint8_t res = 0;
		if(ave_1>max_prob){
			max_prob=ave_1;
			res=1;
		}
		if(ave_2>max_prob){
			max_prob=ave_2;
			res=2;
		}
		// 构造字符串并显示分类结果
		char buf[16];
		sprintf(buf, "C%d", res);
		LCD_DisplayString(145, 210, buf);

		// 可选：显示置信度（如果想启用，可以取消注释）
		//sprintf(buf, "Conf: %.2f", max_prob);
		//LCD_DisplayString(0, 215, buf);

		// 将分类结果通过 UART 发送
		HAL_UART_Transmit(&huart1, &res, 1, HAL_MAX_DELAY);
	}

  return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  //printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(data_activations0);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
  int res = -1;

  //printf("TEMPLATE - run - main loop\r\n");

  if (network_cifar10) {
		/* 1 - acquire and pre-process input data */
    res = acquire_and_process_data(data_ins);
		/* 2 - process the data - call inference engine */
		if (res == 0)
			res = ai_run();
		/* 3- post-process the predictions */
		if (res == 0)
			res = post_process(data_outs);
		else{
			ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
			ai_log_err(err, "Process has FAILED");
			LCD_DisplayString(175, 215, "AI Failed!");
		}
  }
  /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
