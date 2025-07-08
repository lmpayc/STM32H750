/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "gui_guider.h" 

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
uint8_t button_cnt = 0;   //开始学习标志计数器
bool show_sitting_pos_flag = false; //显示坐姿标志

extern bool pause_time_flag; //暂停时间标志

extern uint8_t start_flag;
extern bool led_switch_flag; //led开关标志
extern bool led_auto_flag;   //led自动控制标志
extern float prev_error;
extern float prev_prev_error;
extern bool volume_switch_flag; //音量开关标志
extern bool servo_switch_flag; //舵机开关标志
extern bool servo_auto_flag; //舵机自动控制标志
extern uint32_t servo_pid_start_tick;  //舵机 PID 控制起始时间戳
extern uint16_t servo_ref; //舵机参考值
extern float servo_filtered_feedback;
extern float servo_filtered_output;     // 滤波后的PWM值    
extern uint16_t servo_pwm; //舵机PWM值
extern float servo_pid_error_prev;
extern float servo_pid_error_prev_prev; //舵机PID前一个误差值


extern lv_group_t *group;   // 组对象
extern lv_group_t *setting_group;   // 组对象
extern lv_group_t *current_group; //当前组对象
extern lv_indev_t *gesture_indev; // 手势输入设备
extern lv_ui  main_ui;// 声明 界面对象
extern lv_ui  setting_ui; //设置界面对象
extern lv_ui  debug_ui; //调试界面对象
/**********************
 *  STATIC PROTOTYPES
 **********************/
//学习按键
static void btn_event_cb(lv_event_t * e) {
    lv_obj_t * temp_btn = lv_event_get_target(e);
    if(e->code == LV_EVENT_CLICKED) {
        button_cnt++;		
        show_sitting_pos_flag = false; //隐藏坐姿标志
        hide_pop_cnt(); //隐藏弹出窗口
        if(!start_flag){
            lv_obj_clear_flag(main_ui.main_pop_cnt, LV_OBJ_FLAG_HIDDEN);  
            lv_obj_clear_flag(main_ui.main_large_time_img, LV_OBJ_FLAG_HIDDEN); 
            lv_obj_clear_flag(main_ui.main_learning_time_data, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_ui.main_learning_time_setting, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_ui.main_learning_time_setting_data, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_ui.main_learning_time_unit, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void img_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    hide_pop_cnt(); //隐藏弹出窗口
    lv_obj_clear_flag(main_ui.main_pop_cnt, LV_OBJ_FLAG_HIDDEN);   

    if(code == LV_EVENT_CLICKED) {
        show_sitting_pos_flag = false; //隐藏坐姿标志

        if(target == main_ui.main_learning_time_img) {
            pause_time_flag = !pause_time_flag;  //切换暂停时间标志
            if(!start_flag||pause_time_flag){   //如果未开始学习或暂停时间
                lv_obj_clear_flag(main_ui.main_large_pause_img,LV_OBJ_FLAG_HIDDEN); 
                    uint8_t tmp_data_1 = '0';
                    HAL_UART_Transmit(&huart2, &tmp_data_1, 1, 10); //给推理端发信息
            }
            else if(!pause_time_flag){  //如果正在学习
                lv_obj_add_flag(main_ui.main_large_pause_img,LV_OBJ_FLAG_HIDDEN); 
                uint8_t tmp_data_1 = '1';
                HAL_UART_Transmit(&huart2, &tmp_data_1, 1, 10); //给推理端发信息
            }
            lv_obj_clear_flag(main_ui.main_large_time_img, LV_OBJ_FLAG_HIDDEN); 
            lv_obj_clear_flag(main_ui.main_learning_time_data, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_ui.main_learning_time_setting, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_ui.main_learning_time_setting_data, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(main_ui.main_learning_time_unit, LV_OBJ_FLAG_HIDDEN);
        }
        else if(target == main_ui.main_light_on_img) {
            lv_obj_clear_flag(main_ui.main_large_light_on_img, LV_OBJ_FLAG_HIDDEN); 
            lv_obj_clear_flag(main_ui.main_light_data, LV_OBJ_FLAG_HIDDEN);

        }
        else if(target == main_ui.main_sitting_pos_rest_img) {
            show_sitting_pos_flag = true; //显示坐姿标志
            // if(!start_flag){ //如果未开始学习
            //     lv_obj_clear_flag(main_ui.main_large_sitting_rest_image,LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_clear_flag(main_ui.main_sitting_rest_label, LV_OBJ_FLAG_HIDDEN); 
            // }
        }
        else if(target == main_ui.main_temperature_img) {
            lv_obj_clear_flag(main_ui.main_large_temperature_img,LV_OBJ_FLAG_HIDDEN); 
            lv_obj_clear_flag(main_ui.main_temperature_data, LV_OBJ_FLAG_HIDDEN); 

        }
    }
}

void setting_event_cb(lv_event_t *e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        if(target == setting_ui.setting_auto_adjust_view){
            if(!servo_switch_flag){ //如果舵机开关为关
                    // uint8_t tmp_data = '3';  //推理端发送坐标
                    // HAL_UART_Transmit(&huart2, &tmp_data, 1, 10); //给推理端发信息
                    // servo_auto_flag = true; //舵机自动控制标志
                    // servo_filtered_feedback = servo_ref;
                    // servo_filtered_output = servo_pwm; 
                    // servo_pid_error_prev = 0.0f; // 重置 PID 控制器的误差   
                    // servo_pid_error_prev_prev = 0.0f; // 重置 PID 控制器的前一误差
                    // servo_pid_start_tick = lv_tick_get();  // 记录PID开始时间    
                }
        }
    }    
}



void hide_pop_cnt(void){ //隐藏弹出窗口
        show_sitting_pos_flag = false; //隐藏坐姿标志
        lv_obj_add_flag(main_ui.main_pop_cnt,LV_OBJ_FLAG_HIDDEN);
        //学习时间
        lv_obj_add_flag(main_ui.main_large_pause_img,LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_large_time_img, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_learning_time_data, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(main_ui.main_learning_time_setting, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(main_ui.main_learning_time_setting_data, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(main_ui.main_learning_time_unit, LV_OBJ_FLAG_HIDDEN);
            
        //灯光
        lv_obj_add_flag(main_ui.main_large_light_off_img,LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_large_light_on_img, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_light_data, LV_OBJ_FLAG_HIDDEN);
        //温度
        lv_obj_add_flag(main_ui.main_large_temperature_img,LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_temperature_data, LV_OBJ_FLAG_HIDDEN); 
 
        //坐姿
        lv_obj_add_flag(main_ui.main_large_sitting_rest_image,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(main_ui.main_sitting_rest_label,LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_large_sitting_right_img, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_sitting_right_label, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(main_ui.main_large_sitting_wrong_img, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_add_flag(main_ui.main_sitting_wrong_label, LV_OBJ_FLAG_HIDDEN);

}
void switch_event_cb(lv_event_t * e)  //开关回调
{
    lv_obj_t * target = lv_event_get_target(e);
    if(e->code == LV_EVENT_VALUE_CHANGED) {
        if(target == setting_ui.setting_light_auto_switch) {
            if(lv_obj_has_state(setting_ui.setting_light_auto_switch, LV_STATE_CHECKED)) {
                led_switch_flag = true;  //开
            }
            else {
                led_switch_flag = false;  //关
            }
            prev_error = 0;  //重置 PID 控制器的误差
            prev_prev_error = 0;  //重置 PID 控制器的前一误差
        }
        else if(target == setting_ui.setting_light_pid_switch) {
            if(lv_obj_has_state(setting_ui.setting_light_pid_switch, LV_STATE_CHECKED)) {
                led_auto_flag = true;  //自动控制
            }
            else {
                led_auto_flag = false;  //手动控制
            }
            prev_error = 0;  //重置 PID 控制器的误差
            prev_prev_error = 0;  //重置 PID 控制器的前一误差

        }
        else if(target == setting_ui.setting_volume__switch) {
            if(lv_obj_has_state(setting_ui.setting_volume__switch, LV_STATE_CHECKED)) {
                volume_switch_flag = true;  //音量开
            }
            else {
                volume_switch_flag = false;  //音量关
            }
        }

        else if(target == setting_ui.setting_view_lock_switch) {
            if(lv_obj_has_state(setting_ui.setting_view_lock_switch, LV_STATE_CHECKED)) {
                servo_switch_flag = true;  //舵机开
            }
            else {
                servo_switch_flag = false;  //舵机关
            }
        }


    }
}

void Power_show(lv_obj_t * power_bar, uint8_t power)  //电量显示
{
   if(power<=25){   //低电量红色
        lv_obj_set_style_bg_color(power_bar, lv_color_hex(0xFF3B30), LV_PART_INDICATOR|LV_STATE_DEFAULT);
   }
   else{    //其他时候为绿色
        lv_obj_set_style_bg_color(power_bar, lv_color_hex(0x76FF03), LV_PART_INDICATOR|LV_STATE_DEFAULT);
   }
    lv_bar_set_value(power_bar,power, LV_ANIM_OFF);
}   

void Wifi_show(lv_ui *ui, uint8_t wifi_connect_flag)  //wifi显示
{
    if(wifi_connect_flag){
        lv_obj_clear_flag(ui->main_wifi_img, LV_OBJ_FLAG_HIDDEN);   //显示wifi连接
        lv_obj_add_flag(ui->main_wifi_none_img, LV_OBJ_FLAG_HIDDEN);
    }
    else{
        lv_obj_add_flag(ui->main_wifi_img, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui->main_wifi_none_img, LV_OBJ_FLAG_HIDDEN);   //显示未连接
    }
}
void setup_setting_ui(lv_ui *ui)
{
    init_scr_del_flag(ui);
    setup_scr_setting(ui);
}
void setup_debug_ui(lv_ui *ui)
{
    init_scr_del_flag(ui);
    setup_scr_debug(ui);
}

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    //按钮回调
    lv_obj_add_event_cb(main_ui.main_start, btn_event_cb, LV_EVENT_ALL, NULL);    //绑定回调函数

    // 设置图片可点击并添加事件回调函数
    lv_obj_add_flag(main_ui.main_learning_time_img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(main_ui.main_learning_time_img, img_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_add_flag(main_ui.main_light_on_img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(main_ui.main_light_on_img, img_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_add_flag(main_ui.main_sitting_pos_rest_img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(main_ui.main_sitting_pos_rest_img, img_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_add_flag(main_ui.main_temperature_img, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(main_ui.main_temperature_img, img_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(setting_ui.setting_auto_adjust_view, setting_event_cb, LV_EVENT_CLICKED, NULL);


    //开关回调
    lv_obj_add_event_cb(setting_ui.setting_light_auto_switch, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(setting_ui.setting_light_pid_switch, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(setting_ui.setting_volume__switch, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(setting_ui.setting_view_lock_switch, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);




    group = lv_group_create();  //主界面组对象初始化
    lv_group_add_obj(group, main_ui.main_start);
    lv_group_add_obj(group, main_ui.main_learning_time_img);
    lv_group_add_obj(group, main_ui.main_light_on_img);
    lv_group_add_obj(group, main_ui.main_sitting_pos_rest_img);
    lv_group_add_obj(group, main_ui.main_temperature_img);
    setting_group = lv_group_create();  //设置界面组对象初始化
    lv_group_add_obj(setting_group, setting_ui.setting_light_slider);
    lv_group_add_obj(setting_group, setting_ui.setting_light_auto_switch);
    lv_group_add_obj(setting_group, setting_ui.setting_light_pid_switch);
    lv_group_add_obj(setting_group, setting_ui.setting_volume_slider);
    lv_group_add_obj(setting_group, setting_ui.setting_volume__switch);
    lv_group_add_obj(setting_group, setting_ui.setting_view_lock_switch);  
    lv_group_add_obj(setting_group, setting_ui.setting_up_arrow);
    lv_group_add_obj(setting_group, setting_ui.setting_down_arrow);
    lv_group_add_obj(setting_group, setting_ui.setting_auto_adjust_view);  


    static lv_style_t style_focus;  //焦点样式初始化
    lv_style_init(&style_focus);
    // 色彩更亮，更有科技感（浅蓝 + 半透明）
    lv_style_set_outline_color(&style_focus, lv_color_hex(0x87CEFA));  // 天蓝色
    lv_style_set_outline_opa(&style_focus, LV_OPA_80);  // 半透明边框，柔和感
    // 轮廓效果
    lv_style_set_outline_width(&style_focus, 4);       // 更明显的宽度
    lv_style_set_outline_pad(&style_focus, 3);         // 稍微远离控件，增加“发光”感
    // 圆角
    lv_style_set_radius(&style_focus, 8);              // 更圆润
    // 添加阴影，形成“聚焦”效果
    lv_style_set_shadow_width(&style_focus, 8);
    lv_style_set_shadow_spread(&style_focus, 2);       // 稍微扩散
    lv_style_set_shadow_color(&style_focus, lv_color_hex(0x87CEFA));
    lv_style_set_shadow_opa(&style_focus, LV_OPA_40);  // 柔和阴影

    //主界面组对象样式
    lv_obj_add_style(main_ui.main_start, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(main_ui.main_learning_time_img, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(main_ui.main_light_on_img, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(main_ui.main_sitting_pos_rest_img, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(main_ui.main_temperature_img, &style_focus, LV_STATE_FOCUSED);

    //设置界面组对象样式
    lv_obj_add_style(setting_ui.setting_light_auto_switch, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_light_slider, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_volume_slider, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_light_pid_switch, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_volume__switch, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_up_arrow, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_down_arrow, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_auto_adjust_view, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(setting_ui.setting_view_lock_switch, &style_focus, LV_STATE_FOCUSED);

    lv_group_focus_obj(main_ui.main_start); // 设置主界面焦点
    lv_group_focus_obj(setting_ui.setting_light_auto_switch); // 设置设置界面焦点

    lv_group_set_wrap(group, true); // 设置组对象可以循环焦点
    lv_group_set_wrap(setting_group, true); // 设置组对象可以循环焦点

    gesture_indev = lv_indev_get_next(NULL);
    lv_indev_set_group(gesture_indev, group);  //激活主界面组
    current_group = group;  //设置当前组对象为主界面组

    // lv_obj_set_size(setting_ui.setting_backgroud_cont, LV_PCT(100), LV_PCT(100));

    lv_obj_set_scroll_dir(setting_ui.setting_backgroud_cont, LV_DIR_VER);  // 启用竖向滚动
    lv_obj_set_scrollbar_mode(setting_ui.setting_backgroud_cont, LV_SCROLLBAR_MODE_ACTIVE);

    // 以下两行确保惯性滑动和弹性回弹启用（在LVGL 8.3中默认启用，这里显式添加）
    lv_obj_add_flag(setting_ui.setting_backgroud_cont, LV_OBJ_FLAG_SCROLL_ELASTIC);
    lv_obj_add_flag(setting_ui.setting_backgroud_cont, LV_OBJ_FLAG_SCROLL_MOMENTUM);// 开启惯性滑动

    // lv_obj_add_flag(setting_ui.setting_backgroud_cont, LV_OBJ_FLAG_SCROLL_ONE);
}

