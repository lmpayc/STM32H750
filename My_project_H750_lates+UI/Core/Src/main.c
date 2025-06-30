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
#include "i2c.h"
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
#include "gui_guider.h"           // Gui Guider 生成的界面和控件的声明
#include "events_init.h"          // Gui Guider 生成的初始化事件、回调函数
#include "custom.h"       // Gui Guider 自定义的事件
#include "lv_port_indev.h"
#include "sd.h"
#include "mgc3130.h" 
#include "nfc.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define	NumOf_Blocks	64
#define FRAME_HEADER 0xAA 
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
//串口相关
uint8_t uart1_buf_recv[BUFFER_SIZE];
uint8_t uart2_buf_recv[256];
uint8_t uart3_buf_recv[256];

UartQueue uart1_queue;

//gensture相关  
MGC3130_t mgc3130_dev;  // MGC3130 设备结构体

// FatFs相关句柄
int32_t SD_Status ; 		// SD卡状态
FATFS SDFatFs;     // 文件系统对象
FIL MyFile;        // 文件对象
char SDPath[4];    // SD卡逻辑驱动器路径

char current_filename[32]; // 当前文件名
uint8_t file_open_flag = 0; // 文件是否打开的标志
TimeData current_time;  // 当前时间数据结构体
TimeData start_time;  // 开始时间数据结构体
uint8_t time_received_flag = 0;


//lvgl相关对象
uint32_t last_tick = 0;
extern lv_obj_t * info_label;
extern lv_obj_t * sensor_label; 
extern lv_obj_t * SD_label;
extern lv_obj_t * label_time;
extern uint8_t button_cnt; 
lv_ui  main_ui;// 声明 界面对象
lv_ui  setting_ui; //设置界面对象
lv_ui  debug_ui; //调试界面对象
lv_group_t *group;   // 组对象
lv_group_t *setting_group;   // 组对象
lv_indev_t *gesture_indev; // 手势输入设备
volatile  uint16_t servo_pwm = SEVERO_PWM_MIN;  // 初始化 PWM 值

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
uint8_t gensture;
float tempure;
float Power;
uint8_t read_power_flag = 0;
uint8_t Power_Percent = 0; //电量百分比 

uint8_t username[3] = { 'L', 'P', 'C' };    //当前用户名
uint8_t Temp_WriteBuffer[512];  // 临时SD卡写入缓冲区
uint16_t temp_data_index;
uint8_t Temp_Readbuffer[REAED_BUFFER_SIZE];   //临时SD卡读取缓冲区

uint16_t tim1_cnt = 0;  // 定时器1计数器    
uint8_t timer1_pause = 1;  //定时器1暂停标志
uint8_t wifi_connect_flag; //wifi连接标志
uint8_t last_wifi_connect_flag; //上次wifi连接标志

uint8_t start_flag = 0;   //开始学习标志
uint8_t last_start_flag = 0;   //上次学习标志
bool pause_time_flag = false; //暂停学习标志
bool last_pause_time_flag = false; //记录上次暂停学习标志
uint8_t Real_time_Data[10]= {0};  //实时数据
uint16_t right_sitted_time = 0; //坐姿正确时长

bool led_switch_flag = 0;
bool led_auto_flag = 0;

uint8_t set_studytime = 0; //app传来的设定学习时间
uint8_t light_ref=30;  //led参考光照值（默认30）
uint8_t voice_command[20]= {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0xEE,0xEF}; //语音命令
bool volume_switch_flag = false; //音量开关标志

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2){   //1min周期
        read_power_flag = 1;
    }

    if (htim->Instance == TIM1)  //1s周期
    {
      Real_time_Data[0] =light;
      Real_time_Data[1] = (uint8_t)tempure;
      Real_time_Data[2] = (uint8_t) ((tempure-Real_time_Data[1])*100);
      Real_time_Data[3] = (uint8_t)(Power);
      Real_time_Data[4] = (uint8_t)((Power-Real_time_Data[3])*100);
      Real_time_Data[5] = gensture; //坐姿
      Real_time_Data[6] = start_time.study_time; //本次学习时间
      Real_time_Data[7] = noise; //噪音

      //时钟更新,电源adc采样
      static uint8_t update_time_cnt =0; 
      update_time_cnt++;
      if(update_time_cnt==10){
          sendStringData(&huart1, (char*)"ctime?"); //每隔10s更新当前时间  
          update_time_cnt = 0;  
          return;     //更新时钟时,不更新实时数据
      }

      if(start_flag&&timer1_pause){     //开始学习状态下才更新传感器状态
        if(tim1_cnt==30){   //每隔存到sd卡
          tim1_cnt = 0;
          Temp_WriteBuffer[temp_data_index]= light;
          Temp_WriteBuffer[temp_data_index+1]= (uint8_t)tempure;
          Temp_WriteBuffer[temp_data_index+2]= (uint8_t) ((tempure-Temp_WriteBuffer[temp_data_index+1])*100);
          Temp_WriteBuffer[temp_data_index+3]= gensture; //坐姿
          Temp_WriteBuffer[temp_data_index+4]= noise; //噪音

          temp_data_index += 5;  // 更新数据索引
          Append_Data_To_Session_File(Temp_WriteBuffer, temp_data_index); //将数据写入文件

          if(temp_data_index >= MAX_STUDY_TIME){  
            temp_data_index = 0;  // 重置索引
          }
          LED1_Toggle;
				}
        sendBinaryData(&huart1,Real_time_Data,8);
        tim1_cnt++; 
      }

			if(timer1_pause&&wifi_connect_flag&&!start_flag){
        sendBinaryData(&huart1,Real_time_Data,8);
			}
	
      // // 翻转 PWM 值
      // if (servo_pwm == SEVERO_PWM_MIN){
      //     servo_pwm = SEVERO_PWM_MAX;
      // }else{
      //     servo_pwm = SEVERO_PWM_MIN;
      // }
      // __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, servo_pwm);

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
  HAL_UART_Transmit(huart, buffer, len + 4, 10);
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
      uint8_t tmp_data_1 = '1';
      HAL_UART_Transmit(&huart2, &tmp_data_1, 1, 10); //给推理端发信息
      sendStringData(&huart1, (char*)"stime?"); //发送时间请求
      pause_time_flag = false; // 重置暂停时间标志  
  }
  if(time_received_flag == 1){  //接收到时间
    Create_Study_Session_File(start_time, (char*)username);
    time_received_flag = 0; // 重置时间接收标志
  }


}
void stop_study(TimeData start_time){
  start_flag = 0;
  if (last_start_flag == 1 && start_flag == 0) {
    uint8_t tmp_data_0 = '0';
    HAL_UART_Transmit(&huart2, &tmp_data_0, 1, HAL_MAX_DELAY);
    pause_time_flag = true; // 设置暂停时间标志
    Close_Study_Session_File(start_time,temp_data_index); //保存并关闭
        // ======= 加入姿态评估播报（根据 posture_ratio） =======
    if (volume_switch_flag && start_time.study_time > 0) {
        float final_posture_ratio = (float)right_sitted_time / (start_time.study_time * 60.0f) * 100.0f;
        uint8_t voice_id = (final_posture_ratio >= 85.0f) ? 12 : 13;  // VOICE_GENERAL_GOOD / BAD
        HAL_UART_Transmit(&huart3, &voice_id, 1, 1);
    }
    // 如果学习时间小于5分钟，则删除文件
    if (start_time.study_time < 5) {
      f_unlink(current_filename); // 删除文件
      lv_label_set_text_fmt(SD_label, "study time too short,delete: %s", current_filename);
    }

    save_user_config((char*)username); //保存用户配置
    tim1_cnt = 0;
    temp_data_index = 0;  // 重置索引
    start_time.study_time=0;   //重置学习时长
		right_sitted_time = 0; //重置坐姿正确时长
    memset(current_filename, 0, sizeof(current_filename)); //清空文件名
    memset(Temp_WriteBuffer, 0xFF, sizeof(Temp_WriteBuffer));

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
  // 初始化结构体成员
  mgc3130_dev.hi2c      = &hi2c1;               // 设置 I2C 句柄
  mgc3130_dev.resetPort = GPIOE;               // 设置 RESET 引脚端口
  mgc3130_dev.resetPin  = GPIO_PIN_2;          // 设置 RESET 引脚编号
  mgc3130_dev.tsPort    = GPIOE;               // 设置 TS 引脚端口
  mgc3130_dev.tsPin     = GPIO_PIN_3;          // 设置 TS 引脚编号


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
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USART3_UART_Init();
  MX_TIM12_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1); //开启PWM对应的通道
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1); //开启PWM对应的通道

  HAL_GPIO_WritePin(ESP8266_RST_GPIO_Port, ESP8266_RST_Pin, GPIO_PIN_SET);  //重启esp8266
  HAL_Delay(200);



	SPI_LCD_Init();   
  SD_Status = BSP_SD_Init(SD_Instance);	
  SD_Init();  //初始化FAtFs文件系统

  
  MX_USART1_UART_Init();   //重启串口1
  HAL_UARTEx_ReceiveToIdle_IT(&huart1, uart1_buf_recv, sizeof(uart1_buf_recv));

  lv_init();
	lv_port_disp_init();
  lv_port_indev_init();    // 初始化输入设备

	setup_ui(&main_ui);           // 初始化 UI   
	events_init(&main_ui);       // 初始化 事件
  setup_setting_ui(&setting_ui);
  setup_debug_ui(&debug_ui);
  custom_init(&main_ui);      // 初始化 自定义事件
  ui_init();
  load_user_config((char*)username); //加载用户配置

 
  MGC3130_Init(&mgc3130_dev);  // 初始化MGC3130设备
  MGC3130_EnableGestures(&mgc3130_dev);
  HAL_Delay(50);
  MGC3130_EnableTouchDetection(&mgc3130_dev);      // 使能触摸检测
  HAL_Delay(50);
  // MGC3130_EnableAirWheel(&mgc3130_dev);  // 使能AirWheel
  // HAL_Delay(50);

  char buf[64];
  char genstuere_buf[128]; 
  
  Read_File_Test(info_label,"0:/test.txt");  //读取文件测试
  lv_label_set_text_fmt(info_label, "txt: %s", Temp_Readbuffer);


  HAL_TIM_Base_Start_IT(&htim1);   //启动定时器1
  HAL_TIM_Base_Start_IT(&htim2);   //启动定时器2


  Power = Read_Power()*3.08f;   //电源电压
  Power_Percent = (Power - 7.4f) / (8.4f - 7.4f) * 100.0f;
  Power_show(main_ui.main_power_bar, Power_Percent);  //电量显示 //电量显示
  tempure = atk_ntc_get_temp();
  
  nfc_init();  //初始化nfc
  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, SEVERO_PWM_MIN);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  { 
    uint32_t now = lv_tick_get();
    if (lv_tick_elaps(last_tick) >= 5)  // 每 5ms 执行一次 loop
    {
      last_tick = now;

      if(read_power_flag){
        Power = Read_Power()*3.08f;   //电源电压
        Power_Percent = (Power - 7.4f) / (8.4f - 7.4f) * 100.0f;
        Power_show(main_ui.main_power_bar, Power_Percent);  //电量显示
        read_power_flag = 0;
      }
      if(button_cnt %2 == 1){
        start_study(start_time);
      }
      else{
        stop_study(start_time); 
      }

      snprintf(buf, sizeof(buf), "Power:%2.2f,noise:%2d",Power,noise);
      lv_label_set_text(sensor_label, buf);
        
      UART_Process_Data();  //处理串口数据

      MGC3130_ReceiveSensorData(&mgc3130_dev);  //接收传感器数据
      handle_gesture_input(&mgc3130_dev);  //处理手势输入转化为GUI事件
      sprintf(genstuere_buf, "gesture:%d,touch:%d,position:%d,air:%d", (mgc3130_dev.info.gestureInfo&0xFF), (mgc3130_dev.info.touchInfo& 0xFFFF), mgc3130_dev.position, mgc3130_dev.info.airWheelInfo);
      // if(mgc3130_dev.info.gestureInfo != 0 || mgc3130_dev.info.touchInfo != 0|| mgc3130_dev.info.airWheelInfo != 0|| mgc3130_dev.position!= 0){
      //   // lv_label_set_text(info_label, genstuere_buf);  //更新手势数据
      // }  
    

      if(last_wifi_connect_flag!=wifi_connect_flag){
        Wifi_show(&main_ui, wifi_connect_flag);  //更新wifi状态
      }
      last_wifi_connect_flag =  wifi_connect_flag;
      last_start_flag = start_flag;  
      lv_task_handler();

    }
    //HAL_Delay(5);
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
