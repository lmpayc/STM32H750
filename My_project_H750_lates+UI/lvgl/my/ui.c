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


// 环境阈值（可根据实际需要调整）
#define MIN_LIGHT 10          // 最小光照
#define MAX_TEMP  30.0f       // 最高温度
#define MIN_TEMP  18.0f       // 最低温度
#define MAX_NOISE 60          // 最大噪音（单位dB）

extern TimeData current_time;
extern uint8_t voice_command[20]; //语音命令
extern bool volume_switch_flag;

lv_obj_t *btn;
lv_obj_t * info_label;
lv_obj_t * sensor_label; 
lv_obj_t * SD_label;
lv_obj_t * uart1_label;
lv_obj_t *label_time;
lv_timer_t* scroll_timer = NULL;
int scroll_velocity = 0;  // 当前速度

study_last_time_t study_last_time; //学习持续时间结构体
extern bool pause_time_flag; //暂停时间标志
extern TimeData start_time;  // 开始时间数据结构体
extern uint8_t start_flag;
extern uint8_t wifi_connect_flag;
extern bool show_sitting_pos_flag;

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
extern uint8_t light; //光照实际值
float filtered_output = 0;

extern float tempure;  //温度值
extern uint8_t noise;  //噪音值
extern uint8_t gensture; //实时坐姿
extern uint16_t right_sitted_time;  //坐姿正确时长
float posture_ratio;

extern MGC3130_t mgc3130_dev; 
static uint32_t prevAirWheelInfo = 0;
int32_t led_value;
int32_t volum_value;
uint8_t prev_vol_level = 0;
//LED PID 参数（根据实际情况调整）
float kp = 0.8f;
float ki = 0.1f;
float kd = 0.1f;
float prev_error = 0;
float prev_prev_error = 0;
float pid_output = 0;

bool servo_switch_flag = false; //舵机开关标志
bool servo_auto_flag = false; //舵机自动控制标志
extern uint16_t servo_ref; //舵机参考值
extern uint16_t servo_feedback; //舵机反馈值
uint32_t servo_pid_start_tick = 0;  //舵机 PID 控制起始时间戳
float servo_filtered_output  = 0;     // 滤波后的PWM值
float servo_filtered_feedback = 0;
extern uint16_t servo_pwm;
float servo_pid_error_prev       = 0.0f;
float servo_pid_error_prev_prev  = 0.0f;


static bool     hold_active     = false;
static uint32_t hold_start_tick = 0;
static uint32_t last_step_tick   = 0;      /* 上一次步进的时间戳 */

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
    
    lv_timer_t *led_timer = lv_timer_create(led_timer_cb, 250, NULL);   //LED控制定时器
    lv_timer_t *updatetime_timer = lv_timer_create(updatetim_timer_cb, 1000, NULL);   //更新定时器
    lv_timer_t *adc_timer = lv_timer_create(adc_timer_cb, 5000, NULL);   //ADC采样定时器
    lv_timer_t *nfc_timer = lv_timer_create(nfc_timer_cb, 500, NULL);   //nfc读取
    lv_timer_t *airwheel_timer = lv_timer_create(airwheel_timer_cb, 100, NULL);   //airwheel定时器
    lv_timer_t *sitting_timer = lv_timer_create(sitting_timer_cb, 500, NULL);   //airwheel定时器
    lv_timer_t *posture_env_timer = lv_timer_create(posture_env_eval_cb, 1000, NULL);  // 坐姿与环境评估定时器
    // lv_timer_t *auto_servo_timer = lv_timer_create(servo_pid_timer_cb, 100, NULL);  // 每 100ms 更新一次

    // 设置初始触发偏移：延迟 200ms 和 300ms
    led_timer->last_run = lv_tick_get() + 10;
    updatetime_timer->last_run = lv_tick_get() + 222;
    adc_timer->last_run = lv_tick_get() + 111;
    nfc_timer->last_run = lv_tick_get() + 171;
    sitting_timer->last_run = lv_tick_get() + 43;
    posture_env_timer->last_run = lv_tick_get() + 77;
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
// 通用显示/隐藏函数
static void set_visible(lv_obj_t* obj, bool visible) {
    if (visible) lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
    else lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
}
void sitting_timer_cb(lv_timer_t * timer){
    if(start_flag){    //如果开始学习(暂停学习这里面加)
        if(!pause_time_flag){    
            if (show_sitting_pos_flag) {            
                bool is_right = gensture;
                set_visible(main_ui.main_large_sitting_right_img, is_right);
                set_visible(main_ui.main_sitting_right_label, is_right);
                set_visible(main_ui.main_large_sitting_wrong_img, !is_right);
                set_visible(main_ui.main_sitting_wrong_label, !is_right);
            }else {
                // 都不显示
                set_visible(main_ui.main_large_sitting_right_img, false);
                set_visible(main_ui.main_sitting_right_label, false);
                set_visible(main_ui.main_large_sitting_wrong_img, false);
                set_visible(main_ui.main_sitting_wrong_label, false);
            }
        }
        else{
            if(show_sitting_pos_flag){
                set_visible(main_ui.main_large_sitting_rest_image, show_sitting_pos_flag);
                set_visible(main_ui.main_sitting_rest_label, show_sitting_pos_flag);
            }else{
                // 都不显示
                set_visible(main_ui.main_large_sitting_rest_image, false);
                set_visible(main_ui.main_sitting_rest_label, false);
            }
        }

    }
    else{  //未开始学习
        if(show_sitting_pos_flag){
            set_visible(main_ui.main_large_sitting_rest_image, show_sitting_pos_flag);
            set_visible(main_ui.main_sitting_rest_label, show_sitting_pos_flag);
        }else{
            // 都不显示
            set_visible(main_ui.main_large_sitting_rest_image, false);
            set_visible(main_ui.main_sitting_rest_label, false);
        }
    }
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
void posture_env_eval_cb(lv_timer_t *timer)
{
    /*===================== 秒级计数器 =====================*/
    static uint32_t sec_cnt               = 0;
    static uint16_t light_low_cnt         = 0;   // 光照持续低计数
    static uint16_t noise_high_cnt        = 0;   // 噪声持续高计数
    static uint16_t light_high_cnt        = 0;
    static uint16_t light_cd              = 0;   // 光照提示冷却计数
    static uint16_t noise_cd              = 0;   // 噪声提示冷却计数
    static uint16_t glare_cd              = 0; 
    static uint16_t yawn_cd             = 0; 

        /*----------------- 早退：未学习或已暂停 -----------------*/
    if (!(start_flag && !pause_time_flag)) {
        /*复位所有计数器并提前返回 =======*/
        sec_cnt = 0;
        light_low_cnt =0;light_high_cnt =0;noise_high_cnt = 0;
        light_cd = 0;glare_cd = 0;noise_cd = 0;
        return;
    }    
    sec_cnt++;
    
    //打哈欠检测
    if (gensture == 2) {                  // 2 = 打哈欠
        if (yawn_cd == 0) {               // 只有冷却结束才播报
            uint8_t id = VOICE_YAWN;
            if (volume_switch_flag)
                HAL_UART_Transmit(&huart3, &id, 1, 1);
            yawn_cd = YAWN_COOLDOWN_SEC;  // 重新进入冷却期
        }
    }
    if (yawn_cd) yawn_cd--;               // 每秒递减冷却

    /*===================== 坐姿统计 =====================*/
    // 每秒更新姿势正确率
    posture_ratio = (float) right_sitted_time /
                (start_time.study_time * 60.0f + study_last_time.study_time_second ) * 100.0f;
    char buf[32];
    snprintf(buf, sizeof(buf), "posture_ratio: %.2f", posture_ratio);
    lv_label_set_text(info_label, buf);
    //每分钟进行播报显示
    if (sec_cnt % 60 == 0 ) {
        //按姿势正确率决定是否播报
        posture_voice_assessor(start_time.study_time,posture_ratio,volume_switch_flag);

    }

    /*===================== 光照评估 =====================*/
    if (light < LIGHT_MIN) {
        if (light_cd == 0 && ++light_low_cnt >= LIGHT_PERSIST_SEC) {
            uint8_t id = VOICE_LIGHT_LOW;
            if (volume_switch_flag)                              // 语音开关判定
                HAL_UART_Transmit(&huart3, &id, 1, 1);
            light_low_cnt = 0;
            light_cd      = COOLDOWN_SEC;
        }
    } else {
        light_low_cnt = 0;
    }
    if (light_cd)  light_cd--;

    if (light > LIGHT_MAX) {
        if (glare_cd == 0 && ++light_high_cnt >= LIGHT_PERSIST_SEC) {
            uint8_t id = VOICE_LIGHT_GLARE;        // ID = 4
            if (volume_switch_flag)
                HAL_UART_Transmit(&huart3, &id, 1, 1);
            light_high_cnt = 0;
            glare_cd       = COOLDOWN_SEC;
        }
    } else {
        light_high_cnt = 0;
    }
    if (glare_cd) glare_cd--;


    /*===================== 噪声评估 =====================*/
    if (noise > NOISE_MAX) {
        if (noise_cd == 0 && ++noise_high_cnt >= NOISE_PERSIST_SEC) {
            uint8_t id = VOICE_NOISE_HIGH;
            if (volume_switch_flag)                              // 语音开关判定
                HAL_UART_Transmit(&huart3, &id, 1, 1);
            noise_high_cnt = 0;
            noise_cd       = COOLDOWN_SEC;
        }
    } else {
        noise_high_cnt = 0;
    }
    if (noise_cd)  noise_cd--;
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
    uint8_t position = dev->position & 0xFF; // 表示是否hold
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
            if (lv_scr_act() == setting_ui.setting) {
                lv_coord_t current_scroll = lv_obj_get_scroll_y(setting_ui.setting_backgroud_cont);
                if (current_scroll < 320) {  // 只有不在顶部时才能向上滚动
                    lv_obj_scroll_by(setting_ui.setting_backgroud_cont, 0, -150, LV_ANIM_ON);
                }   
                else{
                    lv_obj_scroll_to_y(setting_ui.setting_backgroud_cont, 320, LV_ANIM_ON); // 滚动到顶部
                }
                
            } else {
                
                lv_scr_load_anim(debug_ui.debug, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, false);
            }
            break;
        case 5:   //下 
            if (lv_scr_act() == setting_ui.setting) {
                lv_coord_t current_scroll = lv_obj_get_scroll_y(setting_ui.setting_backgroud_cont);
                if(current_scroll>-5){
                    lv_obj_scroll_by(setting_ui.setting_backgroud_cont, 0, 150, LV_ANIM_ON);
                        
                } else {
                    lv_obj_scroll_to_y(setting_ui.setting_backgroud_cont, 0, LV_ANIM_ON);
                }   
            }
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
                if (focused != main_ui.main_start && focused != main_ui.main_start_red){
                    lv_event_send(focused, LV_EVENT_CLICKED, NULL);
                }      
            }
        }
    }

    else if(touch &DOUBLE_TAP_CENTER){
        lv_obj_t *focused = lv_group_get_focused(current_group);
        if (focused == main_ui.main_start || focused == main_ui.main_start_red) {
            lv_event_send(focused, LV_EVENT_CLICKED, NULL);
        }
    }

    //上TAP
    else if (touch & TAP_UP)
    {
        if(lv_scr_act() == setting_ui.setting){
          lv_group_focus_prev(setting_group); // 用于向上切换设置焦点
        }
    }
    // 下TAP
    else if (touch & TAP_DOWN)
    {
        if(lv_scr_act() == main_ui.main){
            hide_pop_cnt(); 
        }
        if(lv_scr_act() == setting_ui.setting){
            lv_group_focus_next(setting_group); // 用于向下切换焦点
        }
    }
    // 左TAP
    else if (touch & TAP_LEFT)
    {
        if(lv_scr_act() == main_ui.main){
          lv_group_focus_prev(group); // 用于向左切换焦点
        }

         
    }
    // 右TAP
    else if (touch & TAP_RIGHT)
    {
        if(lv_scr_act() == main_ui.main){
            lv_group_focus_next(group); //用于向右切换焦点
        }
    }

    // 处理 Hold 状态：长按箭头按钮
    lv_obj_t *focused = lv_group_get_focused(current_group);
    if(!touch&&!gesture&&servo_switch_flag){
            process_hold_arrow_and_drive_servo(position, focused);
    }


}

void process_hold_arrow_and_drive_servo(uint8_t position, lv_obj_t *focused)
{
    /*========= 进入 Hold（手指悬停） =========*/
    if(position)
    {
        bool is_up_arrow   = (focused == setting_ui.setting_up_arrow);
        bool is_down_arrow = (focused == setting_ui.setting_down_arrow);

        /* 仅当焦点在上下箭头时才处理 */
        if(is_up_arrow || is_down_arrow)
        {
            /* 第一次进入 Hold：初始化计时 */
            if(!hold_active) {
                hold_active     = true;
                hold_start_tick = lv_tick_get();
                last_step_tick  = hold_start_tick;   // 先清零上一次步进
            }

            uint32_t now = lv_tick_get();

            /* 已超过0.3s 的“启动延迟” */
            if(lv_tick_elaps(hold_start_tick) >= 500)
            {
                /* 每隔 50 ms 连发一次 */
                if(lv_tick_elaps(last_step_tick) >= 25) {
                    servo_step(is_up_arrow ? +1 : -1);
                    last_step_tick = now;
                }
            }
        }
        /* 焦点已经离开箭头 → 立即取消 Hold 状态 */
        else {
            hold_active = false;
        }
    }
    /*========= 松手 / 退出 Hold =========*/
    else {
        hold_active = false;
    }
}

void servo_step(int dir)
{
    const uint16_t step_size = 6;  // 每次步进的增量（你可以根据需求调整）

    if (dir > 0) {
        // 向上：增加 PWM 值
        if (servo_pwm + step_size <= SEVERO_PWM_MAX)
            servo_pwm += step_size;
        else
            servo_pwm = SEVERO_PWM_MAX;
    } else if (dir < 0) {
        // 向下：减小 PWM 值
        if (servo_pwm >= SEVERO_PWM_MIN + step_size)
            servo_pwm -= step_size;
        else
            servo_pwm = SEVERO_PWM_MIN;
    }

    // 更新 PWM 输出，具体取决于你的使用场景
    // 例如通过 __HAL_TIM_SET_COMPARE 更新占空比：
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, servo_pwm);
}


void scroll_inertia_cb(lv_timer_t* timer) {
    lv_obj_t* obj = (lv_obj_t*)timer->user_data;

    if (scroll_velocity == 0) {
        lv_timer_del(scroll_timer);
        scroll_timer = NULL;
        return;
    }

    lv_obj_scroll_by(obj, 0, scroll_velocity, LV_ANIM_ON);

    // 逐步减速
    if (scroll_velocity > 0) scroll_velocity -= 4;
    else scroll_velocity += 4;

    if (abs(scroll_velocity) < 4) scroll_velocity = 0;
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
        uint8_t vol_level = (value * 6) / 100 + 1;   /* 整数运算，结果必在 1~7 */

        if(vol_level > 7) vol_level = 7;             /* 双保险，防止四舍五入带来 8 */

        if((vol_level != prev_vol_level) && volume_switch_flag) {
            if(vol_level > prev_vol_level) {
                HAL_UART_Transmit(&huart3, &voice_command[15], 1, 1);  // 音量增大
            } else {
                HAL_UART_Transmit(&huart3, &voice_command[16], 1, 1);  // 音量减小
            }
            prev_vol_level = vol_level;  // 更新段位记录
        }
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
    if (delta > 15) delta = 15;
    if (delta < -15) delta = -15;
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

void posture_voice_assessor(uint16_t study_min,
                            float ratio,
                            bool  vol_switch)
{
    /* ----------- 1. 学习不足 3 分钟 / 静音：直接退出 ----------- */
    if (study_min < 3 || !vol_switch) return;

    /* ----------- 2. 内部状态 & 等级判定 ----------- */
    PostureLevel cur_level = (ratio >= POSTURE_GOOD_TH) ? POST_GOOD : POST_BAD;

    /* 用 static 保存跨次调用状态（每分钟调用一次即可） */
    static PostureLevel last_level        = POST_UNKNOWN;
    static uint8_t      hold_min_cnt      = 0;   // 等级保持计数
    static uint8_t      bad_remind_cnt    = 0;   // BAD 提醒间隔

    if (cur_level == last_level) {
        hold_min_cnt++;
        if (cur_level == POST_BAD) bad_remind_cnt++;
    } else {
        last_level      = cur_level;
        hold_min_cnt    = 1;
        bad_remind_cnt  = (cur_level == POST_BAD) ? 1 : 0;
    }

    /* ----------- 3. 播报判定 ----------- */
    uint8_t voice_id   = 0;
    bool  need_voice = false;

    /* a) 等级稳定 CHANGE_STABLE_MIN 分钟后播一次 */
    if (hold_min_cnt == CHANGE_STABLE_MIN) {
        voice_id   = (cur_level == POST_GOOD) ? VOICE_GOOD_POSTURE
                                              : VOICE_BAD_POSTURE;
        need_voice = true;
    }

    /* b) BAD 连续存在，每 BAD_REMIND_MIN 分钟重复提醒 */
    if (cur_level == POST_BAD && bad_remind_cnt >= BAD_REMIND_MIN) {
        voice_id        = VOICE_BAD_POSTURE;
        need_voice      = true;
        bad_remind_cnt  = 0;          // 清零重新计数
    }

    /* ----------- 4. 发送 ----------- */
    if (need_voice) {
        if ((voice_id == VOICE_GOOD_POSTURE && gensture == POST_GOOD) ||
            (voice_id == VOICE_BAD_POSTURE  && gensture == 0)) {
             HAL_UART_Transmit(&huart3, &voice_id, 1, 1);
        }
    }
}

// void servo_pid_timer_cb(lv_timer_t* timer) {
//     if (!servo_auto_flag) return;  // 未启用自动控制

//     uint32_t now = lv_tick_get();

//     // 如果超过 3 秒，停止自动控制
//     if (lv_tick_elaps(servo_pid_start_tick) > 3000) {
//         servo_auto_flag = false;
//         uint8_t tmp_data = '4';  //推理端发送结束自动控制
//         HAL_UART_Transmit(&huart2, &tmp_data, 1, 10); //给推理端发信息
//         return;
//     }

//     servo_pid_update(servo_ref, servo_feedback);  // 每次迭代 PID 调整
// }

// void servo_pid_update(uint8_t target, uint8_t feedback) {
//     // PID参数（可视情况改为可调）
//     static float kp = 0.1f;
//     static float ki = 0.03f;
//     static float kd = 0.02f;

//     // 状态变量（保留局部）
//     static float servo_pid_output = 0;     // 累计控制量

//     // 输入端滤波器
//     const float alpha_in  = 0.9f;
//     const float alpha_out = 0.9f;

//     // ===== 输入滤波 =====
//     servo_filtered_feedback = alpha_in * servo_filtered_feedback + (1.0f - alpha_in) * feedback;

//     // ===== PID误差与增量计算 =====
//     float error = (float)target - servo_filtered_feedback;
//     float delta = kp * (error - servo_pid_error_prev)
//                 + ki * error
//                 + kd * (error - 2 * servo_pid_error_prev + servo_pid_error_prev_prev);

//     // 限制增量大小
//     if (delta > 4) delta = 4;
//     if (delta < -4) delta = -4;

//     // ===== 累计PID控制输出 =====
//     servo_pid_output += delta;

//     // 限制输出范围
//     if (servo_pid_output > SEVERO_PWM_MAX) servo_pid_output = SEVERO_PWM_MAX;
//     if (servo_pid_output < SEVERO_PWM_MIN) servo_pid_output = SEVERO_PWM_MIN;

//     // ===== 输出端滤波 =====
//     servo_filtered_output = alpha_out * servo_filtered_output + (1.0f - alpha_out) * servo_pid_output;

//     // ===== 写回PWM =====
//     servo_pwm = (uint16_t)servo_filtered_output;
//     __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, servo_pwm);

//     // ===== 更新误差历史（全局） =====
//     servo_pid_error_prev_prev = servo_pid_error_prev;
//     servo_pid_error_prev      = error;
// }



