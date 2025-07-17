#include "sd.h"

FRESULT res;
UINT bw;

// 外部变量声明
extern FATFS SDFatFs;
extern FIL MyFile;
extern char SDPath[4];
extern uint8_t file_open_flag;
extern char current_filename[100];
extern lv_obj_t *SD_label;
extern uint8_t Temp_Readbuffer[REAED_BUFFER_SIZE];
extern uint8_t username[3];

// 初始化SD卡和文件系统
void SD_Init(void)
{
    // 设置逻辑驱动器路径
    FATFS_LinkDriver(&SD_Driver, SDPath);
    
    // 挂载文件系统
    res = f_mount(&SDFatFs, (TCHAR const*)SDPath, 1);
    if (res != FR_OK)
    {
        // 初始化失败处理
        lv_label_set_text(SD_label, "SD Card Mount Failed!");
    }
}

// 创建新的学习会话数据文件
void Create_Study_Session_File(TimeData currentTime, char* username)
{
    // 使用用户名、日期和时间作为文件名
    sprintf(current_filename, "%s_%02u%02u%02u_%02u%02u.txt", 
            username,
            currentTime.year + 2000, 
            currentTime.month, 
            currentTime.day, 
            currentTime.hour, 
            currentTime.minute);
    
    // 创建文件
    res = f_open(&MyFile, current_filename, FA_CREATE_ALWAYS | FA_WRITE);
    if (res != FR_OK)
    {
        lv_label_set_text(SD_label, "File Creation Failed!");
        return;
    }
    else
    {
        lv_label_set_text_fmt(SD_label, "File Created Successfully: %s", current_filename);
    }
    
    // 写入文件头
    char header[300];
    sprintf(header, "学习姿态监护系统数据记录\r\n"
                    "用户: %s\r\n"
                    "日期: 20%02u年%02u月%02u日\r\n"
                    "开始时间: %02u:%02u\r\n"
                    "计划学习时长: %u分钟\r\n"
                    "采样周期: 30秒\r\n"
                    "格式:光照,温度,保留1,保留2\r\n"
                    "---数据开始---\r\n",
                    username,
                    2000 + currentTime.year, 
                    currentTime.month, 
                    currentTime.day,
                    currentTime.hour, 
                    currentTime.minute,
                    currentTime.study_time);
    
    f_write(&MyFile, header, strlen(header), &bw);

    file_open_flag = 1;  // 标记文件已打开
}

// 将缓冲区数据追加到当前学习会话文件
void Append_Data_To_Session_File(uint8_t* buffer, uint32_t data_size)
{
    if (!file_open_flag)
    {
        lv_label_set_text(SD_label, "No open file to append data");
        return;
    }
    
    char line[60];
    uint32_t i = 0;
    
    // 每5个字节为一组数据
    while (i < data_size)
    {
        if (i + 5 <= data_size)
        {
            uint8_t light = buffer[i];
            float temp = buffer[i+1] + buffer[i+2]/100.0f;
            uint8_t reserve1 = buffer[i+3];
            uint8_t reserve2 = buffer[i+4];
            
            // 格式化为CSV格式
            sprintf(line, "%u,%.2f,%u,%u\r\n", 
                    light, temp, reserve1, reserve2);

            f_write(&MyFile, line, strlen(line), &bw);

            i += 5;
        }
        else
        {
            break;  // 数据不足一组
        }
    }
    
    // 确保数据写入到SD卡
    f_sync(&MyFile);
}


void Close_Study_Session_File(TimeData start_time, uint32_t total_records)
{
    if(!file_open_flag) {
        return;
    }
    
    // 计算实际学习时间（分钟）
    uint8_t actual_study_minutes = start_time.study_time; //学习时长
    uint8_t studt_hour = actual_study_minutes / 60; //学习小时
    
    
    // 写入总结信息
    char summary[200];
    sprintf(summary, 
            "\r\n---数据结束---\r\n"
            "结束时间: %02u:%02u\r\n"
            "实际学习时间: %u分钟\r\n"
            "记录数据条数: %u\r\n"
            "学习姿态评分: %u/100\r\n",  // 此处可根据数据分析结果填入评分
            (start_time.hour)+ studt_hour, 
            (start_time.minute)+ (actual_study_minutes%60),
            actual_study_minutes,
            total_records,
            85);  // 示例评分，实际应根据数据分析得出
    
    f_write(&MyFile, summary, strlen(summary), &bw);
    
    // 关闭文件
    f_close(&MyFile);
    file_open_flag = 0;
    lv_label_set_text_fmt(SD_label,"File Closed Successfully:%s", current_filename);
   
}


// 读取最近的学习会话数据到缓冲区
uint32_t Read_Latest_Session_Data(uint8_t* buffer, uint32_t buffer_size)
{
    DIR dir;
    FILINFO fno;
    char latest_file[100] = {0};
    uint32_t latest_time = 0;
    uint32_t bytes_read = 0;
    FIL temp_file;
    char current_username[4] = {0};
    memcpy(current_username, username, 3);

    // 打开目录
    res = f_opendir(&dir, "/");
    if (res != FR_OK) {
        lv_label_set_text(SD_label, "Failed to open directory");
        return 0;
    }
    
    // 查找最新的学习会话文件
    while (1) {
        res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == 0) break; // 没有更多文件或出错
        
        // 检查是否为txt文件且符合命名格式
        if (!(fno.fattrib & AM_DIR)) {
            char *ext = strrchr(fno.fname, '.');
            if (ext && strcmp(ext, ".txt") == 0) {
                if (strncmp(fno.fname, current_username, 3) != 0) {
                    continue; // 文件不是当前用户名，跳过

                }

                // 从文件名中提取时间戳信息
                uint32_t year, month, day, hour, minute;

                // 使用sscanf解析文件名格式 "username_YYYYMMDD_HHMM.txt"
                if(sscanf(fno.fname, "%*[^_]_%4u%2u%2u_%2u%2u.txt", 
                        &year, &month, &day, &hour, &minute) == 5) {
                            
                    // 计算时间戳（简化计算，仅用于比较）
                    uint32_t timestamp = year*100000000 + month*1000000 + day*10000 + hour*100 + minute;
                    
                  if (strcmp(fno.fname, current_filename) == 0) {
                      continue;
                  }        


                    // 如果是最新的文件，更新记录
                    if (timestamp > latest_time) {
                        latest_time = timestamp;
                        strcpy(latest_file, fno.fname);
                    }
                }
            }
        }
    }
    
    f_closedir(&dir);
    
    // 如果找到最新文件，读取其内容
    if (latest_file[0] != 0) {
        res = f_open(&temp_file, latest_file, FA_READ);
        if (res != FR_OK) {
            lv_label_set_text_fmt(SD_label, "Failed to open file: %s", latest_file);
            return 0;
        }
        
        lv_label_set_text_fmt(SD_label, "Reading latest file: %s", latest_file);
        
        // 跳过文件头部分，直接读取数据部分
        char line[100];
        int is_data_section = 0;
        uint32_t offset = 1;   //从1开始，保留第一个字节用于记录数据条数
        
        // 读取文件，逐行处理
        while (f_gets(line, sizeof(line), &temp_file) && offset < buffer_size - 5) {
        
        
            if(strstr(line, "记录数据条数")) {
                uint32_t count;
                if (sscanf(line, "记录数据条数: %u", &count) == 1){
                    buffer[0] = count; // 将数据条数存入第一个字节
                }
                break; 
            }
            
            
            // 检查是否到达数据部分 
            if (strstr(line, "---数据开始---")) {
                is_data_section = 1;
                continue;
            }
            
            // 检查是否到达数据结束部分
            if (strstr(line, "---数据结束---")) {
                is_data_section = 0;
                continue;
            }


            // 只处理数据部分的行
            if (is_data_section) {
                // 解析CSV格式的数据行：光照,温度,保留1,保留2
                uint32_t light;
                float temp;
                uint32_t reserve1, reserve2;
                
                if (sscanf(line, "%u,%f,%u,%u", &light, &temp, &reserve1, &reserve2) == 4) {
                    // 将数据存入缓冲区，与写入格式对应
                    buffer[offset++] = (uint8_t)light;
                    
                    // 将浮点温度拆分为整数和小数部分
                    uint8_t temp_int = (uint8_t)temp;
                    uint8_t temp_frac = (uint8_t)((temp - temp_int) * 100);
                    
                    buffer[offset++] = temp_int;
                    buffer[offset++] = temp_frac;
                    buffer[offset++] = (uint8_t)reserve1;
                    buffer[offset++] = (uint8_t)reserve2;
                    
                    bytes_read += 5;
                }
            }
        
            
        
        }
        
        f_close(&temp_file);
        return bytes_read;
    } else {
        lv_label_set_text(SD_label, "No session files found");
        return 0;
    }
}


FRESULT Create_FileSystem(void)    //格式化SD卡,创建FatFs文件系统
{
    FRESULT res;
    BYTE workBuffer[FF_MAX_SS];  // 用作工作区，必须是静态或全局变量

    // 注册驱动器
    if (FATFS_LinkDriver(&SD_Driver, SDPath) != 0)
    {
        return FR_NOT_READY;
    }

    // 格式化文件系统（使用默认参数）
    res = f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, workBuffer, sizeof(workBuffer));
    if (res != FR_OK)
    {
        return res;
    }

    // 格式化后挂载文件系统
    res = f_mount(&SDFatFs, (TCHAR const*)SDPath, 1);
    if (res != FR_OK)
    {
        return res;
    }

    return FR_OK;
}


void FatFs_Init(void)
{
    // 注册SD卡驱动器
    if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
    {
        // 挂载文件系统
        if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 1) == FR_OK)
        {
            // 成功挂载，你可以创建/读取文件
            if(f_open(&MyFile, "test.txt", FA_CREATE_ALWAYS | FA_WRITE) == FR_OK)
            {
                uint32_t written;
                char data[] = "Hello STM32 with FatFs!";
                f_write(&MyFile, data, sizeof(data) - 1, (UINT*)&written);
                f_close(&MyFile);
            }

            //f_mount(NULL, (TCHAR const*)SDPath, 1); // 可选：卸载
        }
        else
        {
            // 挂载失败
        }
    }
}


FRESULT Read_File_Test(lv_obj_t* label ,const char *filepath)
{
    FIL file;             // 文件对象
    FRESULT res;          // 操作结果
    UINT bytesRead;

    // 打开文件（只读）
    res = f_open(&file, filepath, FA_READ);
    if (res != FR_OK)
    {
        return res;
    }

    // 读取内容并打印
    do
    {
        res = f_read(&file, Temp_Readbuffer, sizeof(Temp_Readbuffer) - 1, &bytesRead);
        if (res != FR_OK)
        {
            break;
        }
    } while (bytesRead > 0);

    // 关闭文件
    f_close(&file);

    return FR_OK;
}
