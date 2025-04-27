#ifndef __SD_H
#define __SD_H

#include "main.h"  
#include "ff.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include "lvgl.h"
#include <stdio.h>
#include <string.h>



// 函数声明
void SD_Init(void);
void Create_Study_Session_File(TimeData currentTime, char* username);
void Append_Data_To_Session_File(uint8_t* buffer, uint32_t data_size);
void Close_Study_Session_File(TimeData start_tisme, uint32_t total_records);
uint32_t Read_Latest_Session_Data(uint8_t* buffer, uint32_t buffer_size);


FRESULT Create_FileSystem(void);    //格式化SD卡,创建FatFs文件系统
void FatFs_Init(void); // 初始化FatFs
FRESULT Read_File_Test(lv_obj_t* label ,const char *filepath); // 读取文件测试函数

#endif /* __SD_H */
