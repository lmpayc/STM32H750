#include "stm32h7xx_hal.h"
#ifdef GLOBALS 
#define EXT
#else
#define EXT extern 
#endif

#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "lcd_169_drv.h"
#include "dcmi_ov2640.h"

#define Modified_Width 80
#define Modified_Height 60

#define LED_OFF 	  	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET)		// 输出低电平，点亮LED1	
#define LED_ON 	  		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET)			// 输出高电平，关闭LED1	
#define LED_Toggle	  HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_3);										  // 翻转IO口状态

EXT UART_HandleTypeDef huart1;  // UART_HandleTypeDef 结构体变量
extern uint16_t Process_Buffer[Modified_Height][Modified_Width];
extern uint8_t uart_rx_data;
extern uint8_t allow_infer;
//extern uint8_t allow_headshot;
//extern uint8_t allow_send;
extern uint16_t line_buffer[Display_Width];  // 用于存放每一行缩放后图像

void LED_Init(void);
void Error_Handler(void);
