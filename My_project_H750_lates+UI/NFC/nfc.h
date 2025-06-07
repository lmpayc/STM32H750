#ifndef NFC_H
#define NFC_H
#include "pn532.h"
#include "pn532_stm32f1.h"
#include "ff.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "ui.h"
//NFC
#define MAX_USERS         100
#define UID_LEN           3
#define USERNAME_LEN      4
typedef struct {
    uint8_t uid[UID_LEN];
    char username[USERNAME_LEN];
} User;

extern User myusers[MAX_USERS];  // 存储所有用户的数组
extern uint8_t count_user; // 当前用户数量


extern uint8_t NFC_Readbuffer[512]; // 临时读取缓冲区
extern uint8_t uid[MIFARE_UID_MAX_LENGTH];
extern int32_t uid_len;
extern PN532 pn532;


void nfc_init(void);
void nfc_dtect(void);
int is_uid_equal(uint8_t *uid1, uint8_t *uid2);
void uid_to_str(uint8_t *uid, char *str, size_t len);
void init_default_user(void);
void load_users_from_file(void);
FRESULT register_new_user(uint8_t *uid, const char *username);
char* find_username_by_uid(uint8_t *uid);  

#endif // UI_H
