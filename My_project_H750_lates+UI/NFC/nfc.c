#include "nfc.h"
extern lv_obj_t *SD_label; 
extern lv_obj_t *info_label;

User myusers[MAX_USERS];  // 存储所有用户的数组
uint8_t count_user; // 当前用户数量

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
        lv_label_set_text(SD_label, nfcbuff);
        char *username = find_username_by_uid(uid);
        if (username != NULL) {
            // 登录成功
            lv_label_set_text_fmt(SD_label, "Welcome %s!", username);
        } else {
            // 注册新用户
            char temp_username[20];
            snprintf(temp_username, 4, "%03u",count_user);
            
            register_new_user(uid, temp_username); // 这里可以改为动态输入用户名
            lv_label_set_text(info_label, "New User Detected");
            load_users_from_file(); // 重新加载用户列表
        }
    } 
    else {
        snprintf((char*)nfcbuff, sizeof(nfcbuff), "NFC Read null");
        lv_label_set_text(SD_label, nfcbuff);
    }
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

