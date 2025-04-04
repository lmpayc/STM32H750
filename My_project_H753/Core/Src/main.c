/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "memorymap.h"
#include "rtc.h"
#include "sdmmc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "key.h"
#include <string.h>
#include "ff.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include "usbd_cdc_if.h"
#include "lcd_model.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define	NumOf_Blocks	64
#define FRAME_HEADER 0xAA

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int32_t SD_Status ; 		 

uint8_t uart1_buf_recv[BUFFER_SIZE];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */
void MPU_Config(void);					
void sendStringData(UART_HandleTypeDef *huart, const char *str);
void sendBinaryData(UART_HandleTypeDef *huart, uint8_t *data, uint8_t len);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//	
void MPU_Config(void)
{
	MPU_Region_InitTypeDef MPU_InitStruct;

	HAL_MPU_Disable();		

	MPU_InitStruct.Enable 				= MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress 		= 0x24000000;
	MPU_InitStruct.Size 					= MPU_REGION_SIZE_512KB;
	MPU_InitStruct.AccessPermission 	= MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable 		= MPU_ACCESS_BUFFERABLE;
	MPU_InitStruct.IsCacheable 		= MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable 		= MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number 				= MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField 		= MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable 	= 0x00;
	MPU_InitStruct.DisableExec 		= MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);	

	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);	// 
}
uint8_t light;
float tempure;
float Power;
uint8_t Light_WriteBuffer[256] = { 0 };  // 写入缓冲区
uint8_t Read_light_Buffer[256];
uint8_t light_index;
uint8_t start_flag = 0;   //开始学习标志
uint8_t Real_time_Data[5]= {0};  //实时数据
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM1)  // 确保是 TIM1 触发的
    {
      if(start_flag){     //开始学习状态下才更新传感器状态
        light_index++;
        if(light_index==256){   //存到sd卡上一块区域
          light_index = 0;
          Light_WriteBuffer[0]= light_index;
          BSP_SD_WriteBlocks(SD_Instance, (uint32_t*) Light_WriteBuffer , 0, 1);
        
        
          //HAL_UART_Transmit(&huart1, Light_WriteBuffer, 31, 1000);
          //BSP_SD_ReadBlocks(SD_Instance, (uint32_t*) Read_light_Buffer , 0, 1);
          LED1_Toggle;
          return;
        }
        else{
          Light_WriteBuffer[0]= light_index;
          Light_WriteBuffer[light_index]=light;
          Real_time_Data[0] =light;
          Real_time_Data[1] = (uint8_t)tempure;
					Real_time_Data[2] = (uint8_t) ((tempure-Real_time_Data[1])*100);
					Real_time_Data[3] = (uint8_t)(Power);
          Real_time_Data[4] = (uint8_t)((Power-Real_time_Data[3])*100);
          // HAL_UART_Transmit(&huart1, &Light_WriteBuffer[light_index], 1, 1000);
          //HAL_UART_Transmit(&huart1, "test", sizeof("test"), 1000);
          // sendStringData(&huart1,"test");
          sendBinaryData(&huart1,Real_time_Data,5);
        }
      }  
    }
}

void sendStringData(UART_HandleTypeDef *huart, const char *str) {
  uint8_t buffer[256];  
  uint8_t len = strlen(str);

  if (len > 250) len = 250;  // 避免超出缓冲区

  buffer[0] = FRAME_HEADER;  // 帧头
  buffer[1] = 0x01;          // 数据类型：字符串
  buffer[2] = len;           // 数据长度

  memcpy(&buffer[3], str, len);  // 复制数据
  
  // 计算校验和 (XOR)
  uint8_t checksum = buffer[0] ^ buffer[1] ^ buffer[2];
  for (uint8_t i = 0; i < len; i++) {
      checksum ^= buffer[3 + i];
  }
  buffer[3 + len] = checksum;  // 校验位

  // 发送整个数据帧
  HAL_UART_Transmit(huart, buffer, len + 4, 1000);
}

void sendBinaryData(UART_HandleTypeDef *huart, uint8_t *data, uint8_t len) {
  uint8_t buffer[256];  

  if (len > 250) len = 250;  // 避免超出缓冲区

  buffer[0] = FRAME_HEADER;  // 帧头
  buffer[1] = 0x02;          // 数据类型：二进制
  buffer[2] = len;           // 数据长度

  memcpy(&buffer[3], data, len);  // 复制数据

  // 计算校验和
  uint8_t checksum = buffer[0] ^ buffer[1] ^ buffer[2];
  for (uint8_t i = 0; i < len; i++) {
      checksum ^= buffer[3 + i];
  }
  buffer[3 + len] = checksum;  // 校验位

  // 发送整个数据帧
  HAL_UART_Transmit(huart, buffer, len + 4, 100);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  MPU_Config();				// 

  /* USER CODE END 1 */

  /* Enable the CPU Cache */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_RTC_Init();
  // MX_SDMMC1_SD_Init();
  MX_SPI4_Init();
  MX_USART1_UART_Init();
  MX_USB_DEVICE_Init();
  MX_ADC1_Init();
  MX_ADC3_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(ESP8266_RST_GPIO_Port, ESP8266_RST_Pin, GPIO_PIN_SET);  //重启esp8266
  HAL_Delay(100);

  HAL_TIM_Base_Start_IT(&htim1);


	KEY_Init();
	SPI_LCD_Init();   
  SD_Status = BSP_SD_Init(SD_Instance);	
  BSP_SD_CardInfo  SD_cardinfo; 

  //BSP_SD_ReadBlocks(SD_Instance, (uint32_t*) Read_light_index_Buffer , 0, 1);
  // light_index = Read_light_index_Buffer[0];   //查找上次

  MX_USART1_UART_Init();   //重启串口1
  HAL_UARTEx_ReceiveToIdle_IT(&huart1, uart1_buf_recv, sizeof(uart1_buf_recv));


	if( SD_Status == BSP_ERROR_NONE )	
  {		
    LCD_SetBackColor(LCD_BLACK); 				
    LCD_Clear(); 											
    LCD_SetColor(LIGHT_GREEN);				 	
    LCD_SetAsciiFont(&ASCII_Font20);		
    LCD_DisplayString(20,25,"SD Success");
    HAL_Delay(1000);
    LCD_Clear(); 
  }
  else
  {
    LCD_SetBackColor(LCD_BLACK); 				
    LCD_Clear(); 											 
    LCD_SetColor(LIGHT_GREEN);				
    LCD_SetAsciiFont(&ASCII_Font20);		
    LCD_DisplayString(20,25,"SD Error");
    HAL_Delay(1000);
    LCD_Clear(); 
  }
  
  LCD_ShowNumMode(Fill_Space);

  
  double cnt=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    uint8_t keyPressCount = KEY_Scan1();
    if(keyPressCount %2 == 1){ 
      light =  Atk_Light_Get_Val();
      tempure = atk_ntc_get_temp();
      LCD_DisplayString(10,0,"start study");
      start_flag = 1;
    }
    else{
      LCD_DisplayString(10,0,"stop study");
      start_flag = 0; 
    }
    LCD_DisplayString(0,50,"light:");
    LCD_DisplayNumber(65,50,light,5);

    LCD_DisplayString(0,70,"tempure:");
    LCD_DisplayDecimals(80,70,tempure,5,2);

    LCD_DisplayString(0,90, "SDinfo:");
    LCD_DisplayNumber(70,90,Light_WriteBuffer[0],3);
    LCD_DisplayNumber(100,90,Light_WriteBuffer[30],3);

    Power = Read_Power()*3.08f;   //电源电压
    LCD_DisplayString(0,110,"Power:");
    LCD_DisplayDecimals(70,110,Power,1,2);

    //LCD_DisplayNumber(65,70,SD_cardinfo.CardType,3);
    // LCD_DisplayNumber(100,70,SD_cardinfo.BlockSize,3);
    // LCD_DisplayNumber(0,90,SD_cardinfo.BlockNbr,3);



    //USB_printf(">>>\r\n%s\r\n",a);
    //LCD_DrawCircle((uint16_t) LCD_Width/2,(uint16_t) LCD_Height/2,(uint16_t) 5);
      
    cnt++;
    if(cnt==1000){
      LCD_Clear();
			cnt=0;
    }
    HAL_Delay(100);
		 



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSE
                              |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInitStruct.PLL2.PLL2M = 2;
  PeriphClkInitStruct.PLL2.PLL2N = 12;
  PeriphClkInitStruct.PLL2.PLL2P = 2;
  PeriphClkInitStruct.PLL2.PLL2Q = 2;
  PeriphClkInitStruct.PLL2.PLL2R = 2;
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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
    // LCD_Clear();
    // LCD_DisplayString(0,0,"ADC_ERROR");
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
