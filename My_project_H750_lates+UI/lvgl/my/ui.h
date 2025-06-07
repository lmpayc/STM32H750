// ui.h

#ifndef UI_H
#define UI_H

#include "lvgl.h"
#include "mgc3130.h"

typedef struct study_last_time_t {
    uint8_t study_time_hour; //学习时间小时
    uint8_t study_time_minute; //学习时间分钟
    uint8_t study_time_second; //学习时间秒
    uint8_t pause_time; //暂停时间
}study_last_time_t;

/**
 * @brief 初始化并创建屏幕上的 UI 元素
 *
 * 在 main 函数中，LVGL 和硬件驱动初始化完成后调用此函数，
 * 用于创建按钮、标签及其事件回调等。
 */
void ui_init(void);
void led_timer_cb(lv_timer_t * timer);
void updatetim_timer_cb(lv_timer_t * timer);
void control_led(bool led_switch_flag, bool led_auto_flag, uint8_t light_ref, uint8_t light_feedback);
void handle_gesture_input(const MGC3130_t *dev);
void adc_timer_cb(lv_timer_t * timer);
void nfc_timer_cb(lv_timer_t * timer);
void airwheel_timer_cb(lv_timer_t * timer);
void process_air_wheel(lv_obj_t *focused_obj, uint32_t airWheelInfo);
void led_pid_update(uint8_t target, uint8_t feedback);


#endif // UI_H
