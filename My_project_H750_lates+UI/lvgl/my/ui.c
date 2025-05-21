// ui.c

#include "lvgl.h"
#include "ui.h"
#include <stdio.h>
#include "main.h"

#include "gui_guider.h"


extern TimeData current_time;

lv_obj_t *btn;
lv_obj_t * info_label;
lv_obj_t * sensor_label; 
lv_obj_t * SD_label;
lv_obj_t * uart1_label;
lv_obj_t *label_time;
extern lv_ui  guider_ui;// 声明 界面对象
extern lv_group_t *group;   // 组对象


/**
 * 初始化并创建 UI
 */
void ui_init(void)
{
    // 页面对象，当前活动屏幕
    lv_obj_t * scr =  guider_ui.screen;    //lv_scr_act();
   
    // 时间显示
    label_time = lv_label_create(scr);
    char time_str[8];
    snprintf(time_str, sizeof(time_str), "%02d:%02d", current_time.hour, current_time.minute);
    lv_label_set_text(label_time, time_str);
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_30, 0);
    lv_obj_align(label_time, LV_ALIGN_CENTER, 0, -10);


    uart1_label = lv_label_create(scr);
    lv_obj_align(uart1_label, LV_ALIGN_TOP_LEFT, 0, 160);
    lv_label_set_text(uart1_label, "uart1:");


    info_label = lv_label_create(scr);
    lv_obj_align(info_label, LV_ALIGN_TOP_LEFT, 0, 20);

    sensor_label = lv_label_create(scr);
    lv_obj_align(sensor_label, LV_ALIGN_TOP_LEFT, 0, 40);

    SD_label = lv_label_create(scr);
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

void handle_gesture_input(const MGC3130_t *dev)
{
    if (!dev || !group) return;

    uint8_t gesture = dev->info.gestureInfo & 0xFF;
    uint16_t touch = dev->info.touchInfo& 0xFFFF;
    uint8_t position = dev->position;

    // // 可选：如果手没有在感应区域，跳过处理
    // if (position == 0) return;

    // 处理上下左右手势
    switch (gesture)
    {
        case 3: // 上
            lv_group_focus_prev(group);
            break;
        case 4: // 下
            lv_group_focus_next(group);
            break;
        case 2: // 右
            lv_group_focus_next(group); // 或者用于页面切换
            break;
        case 5: // 左
            lv_group_focus_prev(group); // 或者用于页面返回
            break;
        default:
            break;
    }

    // 中心 TAP 表示“点击”
    if (touch & TAP_CENTER)
    {
        lv_obj_t *focused = lv_group_get_focused(group);
        if (focused)
        {
            lv_event_send(focused, LV_EVENT_CLICKED, NULL);
        }
    }
}


