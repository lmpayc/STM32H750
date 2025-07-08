// ui.h

#ifndef UI_H
#define UI_H

#include "lvgl.h"
#include "mgc3130.h"



/*=========================================================
 *  语音 ID（示例）——对照你截图里 1~14 的 ID
 *=========================================================*/
enum {
    VOICE_BAD_POSTURE   = 1,   // 坐姿不标准
    VOICE_POSTURE_WARN2 = 2,   // 第 3 次提醒……
    VOICE_LIGHT_LOW     = 3,   // 环境光线偏暗
    VOICE_LIGHT_GLARE   = 4,   // 光线刺眼（如果用得到）
    VOICE_NOISE_HIGH    = 5,   // 环境噪声大
    VOICE_REST_EYES     = 6,   // 休息眼睛
    VOICE_EXERCISE      = 7,   // 伸展运动
    VOICE_WELCOME       = 8,   // 欢迎回来
    VOICE_EYE_EX        = 9,   // 做眼保健操
    VOICE_GOOD_POSTURE  = 10,  // 坐姿很标准
    VOICE_CAMERA_OCCLUSION  = 11,  // 摄像头被遮挡
    VOICE_GENERAL_GOOD = 12,  // 总评标准
    VOICE_GENERAL_BAD  = 13,  // 总评不标准
    // ……以此类推
};

/*=========================================================
 *  环境/坐姿阈值与计数器阈值
 *=========================================================*/
#define LIGHT_MIN            10      // 环境光照过低阈值
#define LIGHT_MAX            50     // 环境光照过高阈值
#define NOISE_MAX            35      // 噪声过高阈值 (dB)

#define LIGHT_PERSIST_SEC    10      // 光照需连续 20 s 才提示
#define NOISE_PERSIST_SEC    5      // 噪声需连续 10 s 过高才提示
#define COOLDOWN_SEC         30      // 同类提示冷却期 60 s

#define POSTURE_CHECK_SEC    30      // 每 30 s 给一次坐姿提示
#define CORRECT_POSTURE_ID    1      // 正确坐姿的实时姿态编号

#define YAWN_COOLDOWN_SEC   30        // 冷却 10 s
#define VOICE_YAWN          9         // 打哈欠语音 ID（如需改请统一宏）

#define POSTURE_GOOD_TH      80.0f     // GOOD ≥80%
#define CHANGE_STABLE_MIN    2         // 等级切换需连 2 分钟
#define BAD_REMIND_MIN       1        // BAD 每 5 分钟再提醒

typedef enum { POST_UNKNOWN = 0, POST_GOOD, POST_BAD } PostureLevel;

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
void sitting_timer_cb(lv_timer_t * timer);
static void set_visible(lv_obj_t* obj, bool visible);
void scroll_inertia_cb(lv_timer_t* timer);
void posture_env_eval_cb(lv_timer_t *timer);
void posture_voice_assessor(uint16_t study_min,float ratio,bool vol_switch);
void process_hold_arrow_and_drive_servo(uint8_t position, lv_obj_t *focused);
void servo_step(int dir);
void servo_pid_timer_cb(lv_timer_t* timer);
void servo_pid_update(uint8_t target, uint8_t feedback);

#endif // UI_H
