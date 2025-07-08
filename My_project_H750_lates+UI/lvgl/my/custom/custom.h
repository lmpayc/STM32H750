/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"
#include "gui_guider.h"

void custom_init(lv_ui *ui);
void setup_setting_ui(lv_ui *ui);
void setup_debug_ui(lv_ui *ui);
void Power_show(lv_obj_t * bar_1, uint8_t power);  //电量显示
void Wifi_show(lv_ui *ui, uint8_t wifi_connect_flag);  //wifi显示    
void img_event_cb(lv_event_t *e);
void setting_event_cb(lv_event_t *e);
void btn_event_cb(lv_event_t * e);
void switch_event_cb(lv_event_t * e);  //开关回调
void hide_pop_cnt(void);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
