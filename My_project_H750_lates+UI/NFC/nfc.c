#include "nfc.h"
#include "ui.h"
#include "gui_guider.h"

#define CFG_MAX_SIZE   1024    /* 足够大即可，可按需调大 */

extern lv_obj_t *SD_label; 
extern lv_obj_t *info_label;
extern uint8_t username[3];
extern bool led_auto_flag; //led自动控制标志
extern bool led_switch_flag;  //led开关标志
extern bool volume_switch_flag; //音量开关标志
extern uint8_t light_ref;  //led参考光照值  
extern int32_t led_value; 
extern int32_t volum_value;//音量值

extern lv_ui setting_ui; //设置界面对象

User myusers[MAX_USERS];  // 存储所有用户的数组
uint8_t count_user; // 当前用户数量
char current_uid_str[50] = "";  // 当前活跃 UID 字符串

uint8_t NFC_Readbuffer[512]; // 临时读取缓冲区
uint8_t uid[MIFARE_UID_MAX_LENGTH];
int32_t uid_len;
PN532 pn532;

void nfc_init(void) {
  uint8_t  buff[32];
  init_default_user();//创建NFC_UID.txt文件

  PN532_I2C_Init(&pn532);
  PN532_GetFirmwareVersion(&pn532, buff);
  PN532_SamConfiguration(&pn532);
  load_users_from_file();	// 加载已有的用户列表到内存
}
void nfc_dtect(void) {
    char nfcbuff[50];
    uid_len = PN532_ReadPassiveTarget(&pn532, uid, PN532_MIFARE_ISO14443A, 40);
    if (uid_len != PN532_STATUS_ERROR) {
		uid_to_str(uid, nfcbuff, sizeof(nfcbuff));
        // lv_label_set_text(SD_label, nfcbuff);
        char *login_username = find_username_by_uid(uid);
        if (login_username != NULL) {
            // 登录成功

            if (is_new_uid(nfcbuff)) {
                strcpy(current_uid_str, nfcbuff);
                for (int i = 0; i < 3; i++) {
                    username[i] = login_username ? (uint8_t)login_username[i] : 0;
                }
                load_user_config(login_username);
            }
        } else {
            // 注册新用户
            char temp_username[20];
            snprintf(temp_username, 4, "%03u",count_user);
            
            register_new_user(uid, temp_username); // 这里可以改为动态输入用户名
            lv_label_set_text_fmt(info_label, "New User Detected %s", temp_username);
            load_users_from_file(); // 重新加载用户列表
        }
    } 

}

bool is_new_uid(const char* new_uid) {
    return strcmp(current_uid_str, new_uid) != 0;
}

/*  比较UID是否相等    */
int is_uid_equal(uint8_t *uid1, uint8_t *uid2) {
    return (memcmp(uid1, uid2, UID_LEN) == 0);
}
/*  转换UID为字符串形式    */
void uid_to_str(uint8_t *uid, char *str, size_t len) {
    snprintf(str, len, "%02X%02X%02X", uid[0], uid[1], uid[2]);
}
/*  初始化NFC_UID.txt文件    */
void init_default_user() {
    FIL file;
    FRESULT res;

    // 检查文件是否存在
    res = f_stat("0:/NFC_UID.txt", NULL);
    if (res != FR_OK) {
        // 文件不存在，创建并写入默认用户
        res = f_open(&file, "0:/NFC_UID.txt", FA_CREATE_ALWAYS | FA_WRITE);
        if (res == FR_OK) {
            uint8_t default_uid[UID_LEN] ={0xD2,0X5A,0XE};
            char line[64];
            char uid_str[20];
            uid_to_str(default_uid, uid_str, sizeof(uid_str));
            snprintf(line, sizeof(line), "UID:%s,NAME:%s\n", uid_str,"LPC");
            UINT bw;
            f_write(&file, line, strlen(line), &bw);
            f_close(&file);
        }
    }
}
/*  加载NFC_UID.txt文件    */
void load_users_from_file() {
	count_user=0;
    FIL file;
    FRESULT res;
    UINT bytesRead;
    char *line_start, *line_end;

    res = f_open(&file, "0:/NFC_UID.txt", FA_READ);
    if (res != FR_OK) return;

    while (f_read(&file, NFC_Readbuffer, sizeof(NFC_Readbuffer) - 1, &bytesRead) == FR_OK && bytesRead > 0) {
        NFC_Readbuffer[bytesRead] = '\0';
        line_start = (char*)NFC_Readbuffer;

        while ((line_end = strchr(line_start, '\n')) != NULL) {
            int line_len = line_end - line_start;
            char line[128];
            strncpy(line, line_start, line_len);
            line[line_len] = '\0';

            // 解析 UID 和 NAME
            if (strncmp(line, "UID:", 4) == 0) {
                char *uid_str = strstr(line, "UID:") + 4;
                char *name_str = strstr(line, ",NAME:");
                if (name_str) {
                    name_str += 6;
                    sscanf(uid_str, "%2hhx%2hhx%2hhx",
                           &myusers[count_user].uid[0],
                           &myusers[count_user].uid[1],
                           &myusers[count_user].uid[2]);
                    strncpy(myusers[count_user].username, name_str, USERNAME_LEN - 1);
					myusers[count_user].username[USERNAME_LEN - 1] = '\0';
                    count_user++;
                }
            }

            line_start = line_end + 1;
        }
    }

    f_close(&file);
}
/* 注册用户*/
FRESULT register_new_user(uint8_t *uid, const char *username) {
    FIL file;
    FRESULT res;
    UINT bw;
    char line[64];
    char uid_str[20];

    uid_to_str(uid, uid_str, sizeof(uid_str));
    snprintf(line, sizeof(line), "UID:%s,NAME:%s\n", uid_str,username);

    res = f_open(&file,"0:/NFC_UID.txt", FA_OPEN_APPEND | FA_WRITE);
    if (res == FR_OK) {
        f_write(&file, line, strlen(line), &bw);
        f_close(&file);
    }
    return res;
}
/*   登录判断   */
char* find_username_by_uid(uint8_t *uid) {
    for (int i = 0; i < count_user; i++) {
        if (is_uid_equal(myusers[i].uid, uid)) {
            return myusers[i].username;
        }
    }
    return NULL;
}

static inline void set_default_config(void)
{
    led_auto_flag      = 0;
    led_switch_flag    = 0;
    volume_switch_flag = 0;
    led_value          = 0;
    volum_value        = 0;
    light_ref          = 0;
}

/**
 * 文件每行格式:
 * <username>,<led_auto_flag>,<led_switch_flag>,
 * <volume_switch_flag>,<led_value>,<volum_value>,<light_ref>
 *
 * 例: 001,1,0,1,350,60,420
 */
void load_user_config(const char* username)
{
    FIL file;
    FRESULT res;
    bool found = false;
    char line[128];

    /* -------- 1. 以读写方式打开, 不存在就创建 -------- */
    res = f_open(&file, "0:/config.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
    if (res != FR_OK) {
        /* 连创建都失败 —— 保底清零 */
        set_default_config();
        lv_label_set_text_fmt(SD_label, "Failed to create config.txt");
        return;
    }

    /* 新创建的文件 size 为 0 => 直接写默认行并退出 */
    if (f_size(&file) == 0) {
        snprintf(line, sizeof(line), "%s,0,0,0,0,0,0\r\n", username);
        UINT bw;
        f_write(&file, line, strlen(line), &bw);
        f_close(&file);
        set_default_config();
        lv_label_set_text_fmt(SD_label, "config.txt created with default values for %s", username);
        return;
    }

    /* -------- 2. 遍历查找用户记录 -------- */
    f_lseek(&file, 0);                     // 回到文件开头
    while (f_gets(line, sizeof(line), &file)) {
        char     cfg_username[32];
        uint8_t  cfg_led_auto, cfg_led_sw, cfg_vol_sw, cfg_volum;
        uint16_t cfg_led_val,  cfg_light_ref;

        if (sscanf(line, "%[^,],%hhu,%hhu,%hhu,%hu,%hhu,%hu",
                   cfg_username,
                   &cfg_led_auto, &cfg_led_sw, &cfg_vol_sw,
                   &cfg_led_val,  &cfg_volum,  &cfg_light_ref) == 7)
        {
            if (strcmp(cfg_username, username) == 0) {
                /* 找到 —— 赋值 */
                led_auto_flag      = cfg_led_auto;
                led_switch_flag    = cfg_led_sw;
                volume_switch_flag = cfg_vol_sw;
                led_value          = cfg_led_val;
                volum_value        = cfg_volum;
                light_ref          = cfg_light_ref;
                found = true;
                break;
            }
        }
    }

    /* -------- 3. 未找到记录, 追加默认行 -------- */
    if (!found) {
        f_lseek(&file, f_size(&file));     // 跳到文件尾
        snprintf(line, sizeof(line), "%s,0,0,0,0,0,0\r\n", username);
        UINT bw;
        f_write(&file, line, strlen(line), &bw);
        f_sync(&file);                     // 刷新到 SD 卡
        set_default_config();
        lv_label_set_text_fmt(SD_label, "No config found for %s, created default", username);
    }
    else{
        apply_ui_config(); // 应用配置到 UI
        lv_label_set_text_fmt(SD_label, "Loaded config for %s successfully",username);
    }

    f_close(&file);
}

void apply_ui_config(void)
{
    /* 1. 滑动条 */
    lv_slider_set_value(setting_ui.setting_light_slider,
                        led_value,   LV_ANIM_OFF);
    lv_slider_set_value(setting_ui.setting_volume_slider,
                        volum_value, LV_ANIM_OFF);

    /* 2. LED 自动开关 */
    if (led_auto_flag)
        lv_obj_add_state(setting_ui.setting_light_pid_switch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(setting_ui.setting_light_pid_switch, LV_STATE_CHECKED);

    /* 3. LED 手动开关 */
    if (led_switch_flag)
        lv_obj_add_state(setting_ui.setting_light_auto_switch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(setting_ui.setting_light_auto_switch, LV_STATE_CHECKED);

    /* 4. 音量开关 */
    if (volume_switch_flag)
        lv_obj_add_state(setting_ui.setting_volume__switch, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(setting_ui.setting_volume__switch, LV_STATE_CHECKED);

    /* 5. 其它控件 (可选)
       // lv_label_set_text_fmt(label_light_ref, "%u lx", setting_ui.light_ref);
    */
}

void save_user_config(const char* username)
{
    FIL  file;
    FRESULT res;
    UINT br, bw;
    char  buf[CFG_MAX_SIZE];
    UINT  file_len = 0;
    bool  updated  = false;

    /* 打开或创建 config.txt（小写） */
    res = f_open(&file, "0:/config.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
    if (res != FR_OK) {
        return;
    }

    /* ---------- 1. 读完整文件到缓冲 ---------- */
    res = f_read(&file, buf, sizeof(buf)-1, &br);
    if (res != FR_OK) { f_close(&file); return; }
    buf[br] = '\0';       /* 确保以 0 结尾，方便字符串操作 */
    file_len = br;

    /* ---------- 2. 生成当前配置行 ---------- */
    char new_line[128];
    snprintf(new_line, sizeof(new_line), "%s,%u,%u,%u,%u,%u,%u\r\n",
             username,
             led_auto_flag,
             led_switch_flag,
             volume_switch_flag,
             led_value,
             volum_value,
             light_ref);

    /* ---------- 3. 在缓冲中查找并更新该用户名 ---------- */
    char* p   = buf;
    char* end = buf + file_len;

    /* 一行行扫描（按 '\n' 分隔） */
    while (p < end) {
        char* line_start = p;
        char* line_end   = strchr(p, '\n');          /* 找到行尾 */
        if (!line_end) line_end = end;               /* 文件末行没 \n 的情况 */

        /* 提取用户名 —— 找第一个逗号 */
        char* comma = memchr(line_start, ',', line_end - line_start);
        if (comma) {
            size_t user_len = comma - line_start;
            if (user_len < 32) {
                char old_user[32];
                memcpy(old_user, line_start, user_len);
                old_user[user_len] = '\0';

                if (strcmp(old_user, username) == 0) {
                    /* 找到目标行 —— 用新行替换 */
                    size_t new_len = strlen(new_line);
                    /* 先移动后面内容，确保有空间 */
                    size_t tail_len = end - (line_end + 1);
                    if (line_start + new_len + tail_len >= buf + sizeof(buf)) {
                        /* 理论上不会超；若真超，直接放弃写 */
                        f_close(&file);
                        return;
                    }
                    memmove(line_start + new_len, line_end + 1, tail_len);
                    memcpy(line_start, new_line, new_len);
                    end = line_start + new_len + tail_len;
                    updated = true;
                    break;
                }
            }
        }

        /* 跳到下一行 */
        p = (*line_end == '\n') ? line_end + 1 : line_end;
    }

    /* ---------- 4. 若未找到，则在缓冲尾追加新行 ---------- */
    if (!updated) {
        size_t new_len = strlen(new_line);
        if ((end - buf) + new_len >= sizeof(buf)) {  /* 溢出保护 */
            f_close(&file);
            return;
        }
        memcpy(end, new_line, new_len);
        end += new_len;
    }

    /* ---------- 5. 把缓冲写回文件 ---------- */
    f_lseek(&file, 0);                      /* 回到文件开头 */
    f_write(&file, buf, end - buf, &bw);    /* 写新内容      */
    f_truncate(&file);                      /* 截断旧尾巴    */
    f_close(&file);

    lv_label_set_text_fmt(SD_label, "Config for %s saved successfully", username);
}


