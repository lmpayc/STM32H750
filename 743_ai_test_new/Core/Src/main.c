#define GLOBALS
#include "main.h"

#include "lcd_169_drv.h"
#include "dcmi_ov2640.h"

#include "memorymap.h"
#include "gpio.h"
#include "app_x-cube-ai.h"
#include "mod_image.h"
#include "tim.h"

#include <stdint.h>

#define CAMERA_BUFFER_SIZE (Display_Width* Display_Height* 2)

uint16_t Process_Buffer[Modified_Height][Modified_Width];
uint8_t uart_rx_data;
uint8_t allow_infer;
//uint8_t allow_headshot;
//uint8_t allow_send;
uint16_t line_buffer[Display_Width];
//#define Camera_Buffer 0x240481e0 // 摄像头图像缓冲区
__attribute__((section(".RAM_D2"))) __attribute__((aligned(32)))
uint8_t camera_buffer[CAMERA_BUFFER_SIZE];

/********************************************** 函数声明 *******************************************/

void SystemClock_Config(void);		// 时钟初始化
void MPU_Config(void);					// MPU配置

//-----------液晶背光控制脚配置------------------------------
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
   __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  
  /*Configure GPIO pin : PA7 背景光控制*/
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);	
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);   //打开液晶背光
	

	/*Configure GPIO pin : PE12 补光LED控制*/
	GPIO_InitStruct.Pin = GPIO_PIN_12;                   
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	

	//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);   //补光LED
	
}
/***************************************************************************************************
*	函 数 名: main
*
*	说    明: 主程序
*
****************************************************************************************************/

int main(void)
{ 
	MPU_Config();				  // MPU配置   用于配置内存保护单元 0x24000000开始的内存
	SCB_EnableICache();		// 使能ICache  通过启用指令缓存来加速程序执行和减少内存访问延迟
	SCB_EnableDCache();		// 使能DCache  通过启用数据缓存来加速数据访问和减少内存带宽消耗
	HAL_Init();					  // 初始化HAL库
	SystemClock_Config();	// 配置系统时钟，主频400MHz
	LED_Init();					  // 初始化LED引脚
	USART1_Init();				// USART1初始化	
	HAL_UART_Receive_IT(&huart1, &uart_rx_data, 1);
	MX_GPIO_Init();       //液晶背光和摄像头补光LED控制
	HAL_Delay(10);
 	SPI_LCD_Init();      	// 液晶屏以及SPI初始化 
	LCD_SetBackColor(0x000000);
	LCD_SetColor(0xFFFFFF);
 	LCD_DisplayString(10 ,130,"Initializing");
	MX_GPIO_Init();
  MX_X_CUBE_AI_Init();
	DCMI_OV2640_Init();   			 	// DCMI以及OV2640初始化
	MX_TIM2_Init(); //定时器中断初始化
	OV2640_DMA_Transmit_Continuous((uint32_t)camera_buffer, OV2640_BufferSize);  // 启动DMA连续传输
	
	LCD_ClearRect(0, 0, 280, 240);
	
	inferring=0;
	allow_infer=0;
	//allow_headshot=0;
	//allow_send=0;
	HAL_TIM_Base_Start_IT(&htim2);  
	
	while (1)
	{
		if ( DCMI_FrameState == 1 ){		
  		DCMI_FrameState = 0;		// 清标志位
			Copy_Camera_Buffer(Process_Buffer, (uint16_t *)camera_buffer);
			//Copy_Process_to_Display(Display_Buffer,Process_Buffer);
			//LCD_CopyBuffer(0,0,Display_Width,Display_Height, Display_Buffer);
			
			Display_Process_Buffer_Directly(Process_Buffer);
			//LCD_CopyBuffer(20,30,Display_Width,Display_Height, (uint16_t *)camera_buffer);
			LCD_DisplayString( 45 ,210,"DPS:");
			LCD_DisplayNumber( 95 ,210, OV2640_FPS,2) ;
			//if(allow_headshot){
				//Locate_Largest_Component();
				//LCD_SetColor(0xFF0000);
				//LCD_FillCircle((uint16_t)(20+1.0*center_y/Modified_Width*Display_Width),(uint16_t)(1.0*center_x/Modified_Height*Display_Height),5);
				//LCD_DisplayNumber(45,190,(int32_t)center_x,3);
				//LCD_DisplayNumber(95,190,(int32_t)center_y,3);
				//if(allow_send){
					//uint8_t trans_data=(uint8_t)(center_x+100);
					//HAL_UART_Transmit(&huart1, &trans_data, 1, 100);
					//allow_send=0;
				//}
				//LCD_SetColor(0xFFFFFF);
			//}
			if(inferring){
				LCD_ClearRect(145, 210, 280, 240);
				MX_X_CUBE_AI_Process();
				inferring=0;
			}
			
		}	
	}
}

/****************************************************************************************************/
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 400000000 (CPU Clock)
  *            HCLK(Hz)                       = 200000000 (AXI and AHBs Clock)
  *            AHB Prescaler                  = 2
  *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
  *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
  *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
  *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
  *            HSE Frequency(Hz)              = 24000000
  *            PLL_M                          = 3
  *            PLL_N                          = 100
  *            PLL_P                          = 2
  *            PLL_Q                          = 2
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 3;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);    
  
}

//	配置MPU
//
void MPU_Config(void)
{
	MPU_Region_InitTypeDef MPU_InitStruct;

	HAL_MPU_Disable();		// 先禁止MPU

	MPU_InitStruct.Enable 				= MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress 		= 0x24000000;
	MPU_InitStruct.Size 					= MPU_REGION_SIZE_1MB;
	MPU_InitStruct.AccessPermission 	= MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable 		= MPU_ACCESS_BUFFERABLE;
	MPU_InitStruct.IsCacheable 		= MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable 		= MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number 				= MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField 		= MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable 	= 0x00;
	MPU_InitStruct.DisableExec 		= MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);	

	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);	// 使能MPU
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
