// ui.c

#include "lvgl.h"
#include "ui.h"
#include <stdio.h>
#include "main.h"

extern TimeData current_time;
uint8_t button_cnt = 0;   //开始学习标志

lv_obj_t *btn;
lv_obj_t * info_label;
lv_obj_t * sensor_label; 
lv_obj_t * SD_label;
lv_obj_t * uart1_label;
lv_obj_t *label_time;

/**
 * 按钮事件回调函数
 */
static void btn_event_cb(lv_event_t * e) {
    lv_obj_t * temp_btn = lv_event_get_target(e);
    if(e->code == LV_EVENT_CLICKED) {
        if(temp_btn == btn) {
            lv_label_set_text_fmt(info_label, "Button clicked %d", button_cnt++);
        } 
    }
}


/**
 * 初始化并创建 UI
 */
void ui_init(void)
{
    // 页面对象，当前活动屏幕
    lv_obj_t * scr = lv_scr_act();
   
    // 时间显示
    label_time = lv_label_create(scr);
    char time_str[8];
    snprintf(time_str, sizeof(time_str), "%02d:%02d", current_time.hour, current_time.minute);
    lv_label_set_text(label_time, time_str);
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_30, 0);
    lv_obj_align(label_time, LV_ALIGN_CENTER, 0, -10);


    // 创建按钮1
    btn = lv_btn_create(scr); // 在默认屏幕上创建按钮
    lv_obj_set_size(btn, 60, 30);     //
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 110, 210);   // 把按钮放在 (110,210)，对准物理按键
    
    lv_obj_t *button_label = lv_label_create(btn);         // 给按钮加个文字
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, NULL);  // 添加事件回调函数

    lv_label_set_text(button_label, "start study");
    lv_obj_center(button_label);  // 文字居中对齐

    uart1_label = lv_label_create(lv_scr_act());
    lv_obj_align(uart1_label, LV_ALIGN_TOP_LEFT, 10, 0);
    lv_label_set_text(uart1_label, "uart1:");


    info_label = lv_label_create(lv_scr_act());
    lv_obj_align(info_label, LV_ALIGN_TOP_LEFT, 0, 20);

    sensor_label = lv_label_create(lv_scr_act());
    lv_obj_align(sensor_label, LV_ALIGN_TOP_LEFT, 0, 40);

    SD_label = lv_label_create(lv_scr_act());
    lv_obj_align(SD_label, LV_ALIGN_TOP_LEFT, 0, 80);
    lv_label_set_text(SD_label, "SD:");

    //自动换行设置
    // lv_label_set_long_mode(uart1_label, LV_LABEL_LONG_WRAP);
    // lv_obj_set_width(uart1_label, 240);  // 设置最大显示宽度
  
    lv_label_set_long_mode(info_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(info_label, 280);  // 设置最大显示宽度

    lv_label_set_long_mode(sensor_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(sensor_label, 280);  // 设置最大显示宽度

    lv_label_set_long_mode(SD_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(SD_label, 280);  // 设置最大显示宽度
    
   
}
