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
#include "dcmi.h"
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
#include "lv_demos.h"
#include "ui.h"
#include "lv_port_indev.h"
#include "sd.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define	NumOf_Blocks	64
#define FRAME_HEADER 0xAA 
#define USERNAME_LEN 3
#define INDEX_SECTOR 0
#define USER_SECTOR_RANGE 10000 
#define INDEX_SECTOR 0
#define INDEX_FLAG 0xAA55
#define SECTOR_SIZE 512
#define MAX_STUDY_TIME 300 // 最大学习时间


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int32_t SD_Status ; 		 
uint8_t uart1_buf_recv[BUFFER_SIZE];
TimeData current_time;  // 当前时间数据结构体
TimeData start_time;  // 开始时间数据结构体
uint8_t time_received_flag = 0;

// FatFs相关句柄
FATFS SDFatFs;     // 文件系统对象
FIL MyFile;        // 文件对象
char SDPath[4];    // SD卡逻辑驱动器路径

// FRESULT res;       // 返回结果
// UINT bw;           // 已写入的字节数

char current_filename[32]; // 当前文件名
uint8_t file_open_flag = 0; // 文件是否打开的标志




//lvgl相关对象
extern lv_obj_t * info_label;
extern lv_obj_t * sensor_label; 
extern lv_obj_t * SD_label;
extern lv_obj_t * label_time;
extern uint8_t button_cnt; 



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
/* USER CODE BEGIN PFP */
void MPU_Config(void);		


void start_study(TimeData start_time);
void stop_study(TimeData start_time);


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

	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);	
}
uint8_t light;
uint8_t noise;
float tempure;
float Power;
uint8_t username[3] = { 'L', 'P', 'C' };    //当前用户名
uint8_t Temp_WriteBuffer[512];  // 临时SD卡写入缓冲区
uint16_t temp_data_index;
uint8_t Temp_Readbuffer[512];   //临时SD卡读取缓冲区
uint16_t tim1_cnt = 0;  // 定时器1计数器    
uint8_t start_flag = 0;   //开始学习标志
uint8_t last_start_flag = 0;   //上次学习标志
uint8_t Real_time_Data[5]= {0};  //实时数据


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2){   //1min周期
      if(start_flag){
        start_time.study_time+=1;
      }
      sendBinaryData(&huart1,Temp_Readbuffer,100); //发送学习时间数据
    }


    if (htim->Instance == TIM1)  //1s周期
    {
      if(start_flag){     //开始学习状态下才更新传感器状态
        if(tim1_cnt==30){   //每隔存到sd卡
          tim1_cnt = 0;
          Temp_WriteBuffer[temp_data_index]= light;
          Temp_WriteBuffer[temp_data_index+1]= (uint8_t)tempure;
          Temp_WriteBuffer[temp_data_index+2]= (uint8_t) ((tempure-Temp_WriteBuffer[temp_data_index+1])*100);
          Temp_WriteBuffer[temp_data_index+3]= 0xEE; //测试保留
          Temp_WriteBuffer[temp_data_index+4]= 0xEE; //测试保留
          temp_data_index += 5;  // 更新数据索引
          Append_Data_To_Session_File(Temp_WriteBuffer, temp_data_index); //将数据写入文件

          if(temp_data_index >= MAX_STUDY_TIME){  
            temp_data_index = 0;  // 重置索引
          }
          LED1_Toggle;

          return;

        }
        else{
          Real_time_Data[0] =light;
          Real_time_Data[1] = (uint8_t)tempure;
					Real_time_Data[2] = (uint8_t) ((tempure-Real_time_Data[1])*100);
					Real_time_Data[3] = (uint8_t)(Power);
          Real_time_Data[4] = (uint8_t)((Power-Real_time_Data[3])*100);
          sendBinaryData(&huart1,Real_time_Data,5);
          tim1_cnt++;
        }
      }

      static uint8_t update_time_cnt =0; 
      update_time_cnt++;
      if(update_time_cnt==10){
          sendStringData(&huart1, (char*)"ctime?"); //每隔10s更新当前时间  
          update_time_cnt = 0;  
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

// 发送二进制数据(一次最多100个字节)
void sendBinaryData(UART_HandleTypeDef *huart, uint8_t *data, uint16_t len) {
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

void start_study(TimeData start_time){
  start_flag = 1;
  if (last_start_flag == 0 && start_flag == 1) {
      sendStringData(&huart1, (char*)"stime?"); //发送时间请求  
  }
  if(time_received_flag == 1){  //接收到时间
    Create_Study_Session_File(start_time, username);
    time_received_flag = 0; // 重置时间接收标志
  }


}
void stop_study(TimeData start_time){
  start_flag = 0;
  if (last_start_flag == 1 && start_flag == 0) {
    Close_Study_Session_File(start_time,temp_data_index); //保存并关闭

    tim1_cnt = 0;
    temp_data_index = 0;  // 重置索引
    start_time.study_time=0;   //重置学习时长
    memset(current_filename, 0, sizeof(current_filename)); //清空文件名
    memset(Temp_WriteBuffer, 0xFF, sizeof(Temp_WriteBuffer));
    //HAL_Delay(100);
    
  }
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
  MX_USART2_UART_Init();
  MX_DCMI_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(ESP8266_RST_GPIO_Port, ESP8266_RST_Pin, GPIO_PIN_SET);  //重启esp8266
  HAL_Delay(100);

  HAL_TIM_Base_Start_IT(&htim1);   //启动定时器1
  HAL_TIM_Base_Start_IT(&htim2);   //启动定时器2


	SPI_LCD_Init();   
  SD_Status = BSP_SD_Init(SD_Instance);	
  SD_Init();  //初始化FAtFs文件系统

  // if (Create_FileSystem() == FR_OK)    //格式化文件系统
  // {
  //   FatFs_Init();  //初始化文件系统
  // }
  
  MX_USART1_UART_Init();   //重启串口1
  HAL_UARTEx_ReceiveToIdle_IT(&huart1, uart1_buf_recv, sizeof(uart1_buf_recv));



  lv_init();
	lv_port_disp_init();
  lv_port_indev_init();    // 初始化输入设备

  ui_init();

 

  if (FATFS_LinkDriver(&SD_Driver, SDPath) != 0)
  {
    lv_label_set_text(info_label, "Link Driver Error!");
  }

  char buf[64];

  
  Read_File_Test(info_label,"0:/test.txt");  //读取文件测试
  lv_label_set_text_fmt(info_label, "txt: %s", Temp_Readbuffer);

  Read_Latest_Session_Data(Temp_Readbuffer, sizeof(Temp_Readbuffer));  //读取最新文件测试



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		Power = Read_Power()*3.08f;   //电源电压
    
    if(button_cnt %2 == 1){ 
    light =  Atk_Light_Get_Val();
    tempure = atk_ntc_get_temp();
    noise = adc_get_nosie();
      start_study(start_time);
    }
    else{
      stop_study(start_time); 
    }
    

    // // HAL_UART_Transmit(&huart2, "test huart2", sizeof("test huart2"), 100);

    snprintf(buf, sizeof(buf), "light:%03d,tempure:%2.2f,Power:%2.2f,noise:%2d", light, tempure,Power,noise);
		lv_label_set_text(sensor_label, buf);
    last_start_flag = start_flag;    
	

		lv_task_handler();
    HAL_Delay(10);
		 
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
