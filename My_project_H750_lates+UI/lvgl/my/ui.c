// ui.c

#include "lvgl.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "tim.h"
#include "adc.h"
#include "gui_guider.h"
#include "custom.h"
#include "nfc.h"

extern TimeData current_time;

lv_obj_t *btn;
lv_obj_t * info_label;
lv_obj_t * sensor_label; 
lv_obj_t * SD_label;
lv_obj_t * uart1_label;
lv_obj_t *label_time;

study_last_time_t study_last_time; //学习持续时间结构体
extern bool pause_time_flag; //暂停时间标志
extern TimeData start_time;  // 开始时间数据结构体
extern uint8_t start_flag;
extern uint8_t wifi_connect_flag;
extern lv_ui  main_ui;// 声明 界面对象
extern lv_ui  setting_ui; //设置界面对象
extern lv_ui  debug_ui; //调试界面对象
extern lv_group_t *group;   // 主界面组对象
extern lv_group_t *setting_group;   // 设置界面组对象
lv_group_t *current_group;  //当前组对象
extern lv_indev_t *gesture_indev; // 手势输入设备

extern bool led_switch_flag;  //led开关标志
extern bool led_auto_flag;    //led自动控制标志
extern uint8_t light_ref;  //led参考光照值
extern uint8_t light; //光照反馈值
float filtered_output = 0;

extern float tempure;  //温度值
extern uint8_t noise;  //噪音值

extern MGC3130_t mgc3130_dev; 
static uint32_t prevAirWheelInfo = 0;
int32_t led_value;
int32_t volum_value;
// PID 参数（根据实际情况调整）
float kp = 0.5f;
float ki = 0.01f;
float kd = 0.1f;
float prev_error = 0;
float prev_prev_error = 0;
float pid_output = 0;

/**
 * 初始化并创建 UI
 */
void ui_init(void)
{
    // 页面对象，当前活动屏幕
    lv_obj_t * scr = debug_ui.debug;//lv_obj_create(NULL); 
    // 时间显示
    label_time = lv_label_create(scr);
    char time_str[20];
    snprintf(time_str, sizeof(time_str), "%d/%d/%d\n%02d:%02d", current_time.year+2000,current_time.month,current_time.day,current_time.hour, current_time.minute);
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
    
    lv_timer_t *led_timer = lv_timer_create(led_timer_cb, 100, NULL);   //LED控制定时器
    lv_timer_t *updatetime_timer = lv_timer_create(updatetim_timer_cb, 1000, NULL);   //更新定时器
    lv_timer_t *adc_timer = lv_timer_create(adc_timer_cb, 5000, NULL);   //ADC采样定时器
    lv_timer_t *nfc_timer = lv_timer_create(nfc_timer_cb, 500, NULL);   //nfc读取
    lv_timer_t *airwheel_timer = lv_timer_create(airwheel_timer_cb, 100, NULL);   //airwheel定时器

    // 设置初始触发偏移：延迟 200ms 和 300ms
    led_timer->last_run = lv_tick_get() + 10;
    updatetime_timer->last_run = lv_tick_get() + 200;
    adc_timer->last_run = lv_tick_get() + 300;
    nfc_timer->last_run = lv_tick_get() + 100;

}
void led_timer_cb(lv_timer_t * timer){
    control_led(led_switch_flag, led_auto_flag, light_ref,light);
    light =  Atk_Light_Get_Val();  //100ms获取一次光照值
}
void updatetim_timer_cb(lv_timer_t * timer){
    static int last_min = -1;
    char time_str[20];
    char light_str[10];
    char tempure_str[20];
    char study_time_str[20];

    snprintf(time_str, sizeof(time_str), "%02d:%02d", 
        current_time.hour, current_time.minute);
    if ((current_time.minute != last_min)&&wifi_connect_flag) {
        lv_label_set_text_fmt(main_ui.main_date, "%d-%d-%d",  
            current_time.year+2000, current_time.month, current_time.day);
        lv_label_set_text(main_ui.main_Time_label, time_str);
        last_min = current_time.minute;
    }

    snprintf(light_str, sizeof(light_str), "%d", light);
    lv_label_set_text(main_ui.main_light_data, light_str);
    snprintf(tempure_str, sizeof(tempure_str), "%.2f\xE2\x84\x83", tempure);
    lv_label_set_text(main_ui.main_temperature_data, tempure_str);

    if(start_flag){    //如果开始学习(暂停学习这里面加)
        if(!pause_time_flag){
            study_last_time.study_time_second ++;
            if(study_last_time.study_time_second >= 60){
                study_last_time.study_time_second = 0;
                study_last_time.study_time_minute++;
                start_time.study_time++;   //sd卡记录的学习时间
                if(study_last_time.study_time_minute >= 60){
                    study_last_time.study_time_minute = 0;
                    study_last_time.study_time_hour++;
                }
            }
        }    
    }
    else{ //停止学习
        study_last_time.study_time_minute = 0;  
        study_last_time.study_time_second = 0;
        study_last_time.study_time_hour = 0;
        study_last_time.pause_time=0;
        start_time.study_time = 0;
    }
    snprintf(study_time_str, sizeof(study_time_str), "%02d:%02d:%02d", 
        study_last_time.study_time_hour, study_last_time.study_time_minute, study_last_time.study_time_second);
    lv_label_set_text(main_ui.main_learning_time_data, study_time_str);

}
void adc_timer_cb(lv_timer_t * timer){
    noise = adc_get_nosie();
    tempure = atk_ntc_get_temp();
}
void nfc_timer_cb(lv_timer_t * timer){
    nfc_dtect();  //nfc检测用户
}
void airwheel_timer_cb(lv_timer_t * timer){
    lv_obj_t *focused = lv_group_get_focused(current_group);
    process_air_wheel(focused, mgc3130_dev.info.airWheelInfo);  //处理airwheel
}


void control_led(bool led_switch_flag,bool led_auto_flag,uint8_t light_ref,uint8_t light_feedback){
    if(led_switch_flag){

        if(led_auto_flag){   //pid控制led亮度
            led_pid_update(light_ref, light_feedback);
            lv_slider_set_value(setting_ui.setting_light_slider, led_value, LV_ANIM_OFF);
            __HAL_TIM_SetCompare(&htim12, TIM_CHANNEL_1, led_value);
        }
        else{   //手动控制,控制灯变亮或变暗
            led_value=lv_slider_get_value(setting_ui.setting_light_slider);
            __HAL_TIM_SetCompare(&htim12, TIM_CHANNEL_1, led_value);
            filtered_output = led_value; // 重置 PID 输出
            
        }
    }
    else{
            __HAL_TIM_SetCompare(&htim12, TIM_CHANNEL_1,0); 
    }


}
void handle_gesture_input(const MGC3130_t *dev)
{
    if (!dev || !group) return;

    uint8_t gesture = dev->info.gestureInfo & 0xFF;
    uint16_t touch = dev->info.touchInfo& 0xFFFF;
    // 处理上下左右手势
    switch (gesture)
    {
        case 2:   //右
            lv_scr_load_anim(setting_ui.setting, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false);  //设置界面 
            lv_indev_set_group(gesture_indev, setting_group); 
            current_group = setting_group; 
            break;
        case 3:   //左
            lv_scr_load_anim(main_ui.main, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false);   //主界面
            lv_indev_set_group(gesture_indev, group); 
            current_group = group;
            break;
        case 4:   //上
            lv_scr_load_anim(debug_ui.debug, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, false);   //主界面
            break;
        case 5:   //下  
            break;
        default:
            break;
    }


    // 中心 TAP 表示“点击”
    if (touch & TAP_CENTER)
    {
        lv_obj_t *focused = lv_group_get_focused(current_group);
        if (focused)
        {
            // 是 switch 就切换开关状态，否则发送点击事件
            if (lv_obj_check_type(focused, &lv_switch_class)) {
                bool checked = lv_obj_has_state(focused, LV_STATE_CHECKED);
                    lv_obj_clear_state(focused, LV_STATE_CHECKED); // 清除当前状态
                if (!checked) {
                    lv_obj_add_state(focused, LV_STATE_CHECKED); // 设为开
                }
                // 触发绑定的 VALUE_CHANGED 事件回调
                lv_event_send(focused, LV_EVENT_VALUE_CHANGED, NULL);
            } else {
                lv_event_send(focused, LV_EVENT_CLICKED, NULL);
            }
        }
    }

    //上TAP
    else if (touch & TAP_UP)
    {

    }
    // 下TAP
    else if (touch & TAP_DOWN)
    {
        hide_pop_cnt();
    }
    // 左TAP
    else if (touch & TAP_LEFT)
    {
        if(lv_scr_act() == main_ui.main){
          lv_group_focus_prev(group); // 用于向左切换焦点
        }
        if(lv_scr_act() == setting_ui.setting){
          lv_group_focus_prev(setting_group); // 用于向左切换焦点
        }
         
    }
    // 右TAP
    else if (touch & TAP_RIGHT)
    {
        if(lv_scr_act() == main_ui.main){
            lv_group_focus_next(group); //用于向右切换焦点
        }
        if(lv_scr_act() == setting_ui.setting){
            lv_group_focus_next(setting_group); // 用于向左切换焦点
        }

    }

}

void process_air_wheel(lv_obj_t *focused_obj, uint32_t airWheelInfo)
{
    // 检查控件是否为 slider
    if(focused_obj == NULL || !lv_obj_check_type(focused_obj, &lv_slider_class)) {
        prevAirWheelInfo = airWheelInfo; // 更新历史值
        return;
    }

    int32_t delta = (int32_t)airWheelInfo - (int32_t)prevAirWheelInfo;

    // 处理环绕（因为 airWheelInfo 是 0~256 环绕的）
    if(delta > 128) {
        delta -= 256;
    } else if(delta < -128) {
        delta += 256;
    }

        // 过滤突变：如果增量过大，不处理（说明识别错误）
    if (abs(delta) > 20) {
        prevAirWheelInfo = airWheelInfo;  // 更新历史值但不做处理
        return;
    }

    if(delta == 0) return; // 无旋转

    // 获取当前 slider 值和范围
    int32_t value = lv_slider_get_value(focused_obj);
    int32_t min = lv_slider_get_min_value(focused_obj);
    int32_t max = lv_slider_get_max_value(focused_obj);

    // 定义步进值（你可以调整这个系数让滑动更快/慢）
    int step = delta / 3;  // 每 5 个 airWheel 单位变化 1（你可以调）

    value += step;
    if(value < min) value = min;
    if(value > max) value = max;

    if(focused_obj == setting_ui.setting_light_slider){
        if(!led_auto_flag){
            led_value = value;
        }
        
    }
    else if(focused_obj==setting_ui.setting_volume_slider){
        volum_value = value;
    }

    // 更新 slider
    lv_slider_set_value(focused_obj, value, LV_ANIM_OFF);

    prevAirWheelInfo = airWheelInfo;
}

void led_pid_update(uint8_t target, uint8_t feedback) {
    float error = target - feedback;
    float delta = kp * (error - prev_error)
                + ki * error
                + kd * (error - 2 * prev_error + prev_prev_error);
    // 限制增量，防止亮度突变
    if (delta > 10) delta = 10;
    if (delta < -10) delta = -10;
    pid_output += delta;
    // 限制最终输出范围
    if (pid_output > 100) pid_output = 100;
    if (pid_output < 0) pid_output = 0;
    // 低通滤波器平滑输出
    filtered_output = 0.1f * pid_output + 0.9f* filtered_output;
    if (filtered_output < 1.0f) {
        filtered_output = 0;
    }
    // 更新误差历史
    prev_prev_error = prev_error;
    prev_error = error;
    led_value = (uint32_t)filtered_output;
}

