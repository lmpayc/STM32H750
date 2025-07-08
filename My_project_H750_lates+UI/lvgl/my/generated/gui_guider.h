/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *main;
	bool main_del;
	lv_obj_t *main_home_cnt;
	lv_obj_t *main_power_cont;
	lv_obj_t *main_power_bar;
	lv_obj_t *main_wifi_none_img;
	lv_obj_t *main_wifi_img;
	lv_obj_t *main_Time_label;
	lv_obj_t *main_pop_cnt;
	lv_obj_t *main_split_line;
	lv_obj_t *main_sitting_pos_wrong_img;
	lv_obj_t *main_sitting_pos_right_img;
	lv_obj_t *main_sitting_pos_rest_img;
	lv_obj_t *main_learning_time_img;
	lv_obj_t *main_pause_img;
	lv_obj_t *main_temperature_img;
	lv_obj_t *main_light_down_img;
	lv_obj_t *main_light_on_img;
	lv_obj_t *main_setting;
	lv_obj_t *main_date;
	lv_obj_t *main_start;
	lv_obj_t *main_sitting_wrong_label;
	lv_obj_t *main_large_sitting_wrong_img;
	lv_obj_t *main_sitting_right_label;
	lv_obj_t *main_large_sitting_right_img;
	lv_obj_t *main_sitting_rest_label;
	lv_obj_t *main_large_sitting_rest_image;
	lv_obj_t *main_learning_time_data;
	lv_obj_t *main_learning_time_unit;
	lv_obj_t *main_learning_time_setting;
	lv_obj_t *main_learning_time_setting_data;
	lv_obj_t *main_large_time_img;
	lv_obj_t *main_large_pause_img;
	lv_obj_t *main_temperature_data;
	lv_obj_t *main_large_temperature_img;
	lv_obj_t *main_light_data;
	lv_obj_t *main_large_light_on_img;
	lv_obj_t *main_large_light_off_img;
	lv_obj_t *setting;
	bool setting_del;
	lv_obj_t *setting_view_port;
	lv_obj_t *setting_backgroud_cont;
	lv_obj_t *setting_config_cont;
	lv_obj_t *setting_view_lock_switch;
	lv_obj_t *setting_auto_adjust_label;
	lv_obj_t *setting_down_arrow;
	lv_obj_t *setting_up_arrow;
	lv_obj_t *setting_auto_adjust_view;
	lv_obj_t *setting_camer_view_hand;
	lv_obj_t *setting_setting_image;
	lv_obj_t *setting_light_slider;
	lv_obj_t *setting_light_img;
	lv_obj_t *setting_light_label;
	lv_obj_t *setting_light_auto_switch;
	lv_obj_t *setting_volume__switch;
	lv_obj_t *setting_volume_img;
	lv_obj_t *setting_volume_lable;
	lv_obj_t *setting_volume_slider;
	lv_obj_t *setting_light_pid_switch;
	lv_obj_t *setting_light_pid_lable;
	lv_obj_t *debug;
	bool debug_del;
	lv_obj_t *debug_cont_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_main(lv_ui *ui);
void setup_scr_setting(lv_ui *ui);
void setup_scr_debug(lv_ui *ui);
LV_IMG_DECLARE(_WIFI_none_alpha_25x25);
LV_IMG_DECLARE(_WIFI_alpha_25x25);
LV_IMG_DECLARE(_sitting_wrong_alpha_45x45);
LV_IMG_DECLARE(_sitting_right_alpha_45x45);
LV_IMG_DECLARE(_sitting_not_learning_alpha_45x45);
LV_IMG_DECLARE(_learning_time_alpha_45x45);
LV_IMG_DECLARE(_pause_alpha_10x10);
LV_IMG_DECLARE(_temperature_alpha_45x45);
LV_IMG_DECLARE(_buble_dark_alpha_25x50);
LV_IMG_DECLARE(_buble_light_alpha_37x50);
LV_IMG_DECLARE(_setting_alpha_25x25);
LV_IMG_DECLARE(_start_alpha_45x45);
LV_IMG_DECLARE(_sitting_wrong_alpha_60x60);
LV_IMG_DECLARE(_sitting_right_alpha_60x60);
LV_IMG_DECLARE(_sitting_not_learning_alpha_60x59);
LV_IMG_DECLARE(_learning_time_alpha_60x60);
LV_IMG_DECLARE(_pause_alpha_25x25);
LV_IMG_DECLARE(_temperature_alpha_80x80);
LV_IMG_DECLARE(_buble_light_alpha_61x80);
LV_IMG_DECLARE(_buble_dark_alpha_40x80);
LV_IMG_DECLARE(_down_alpha_25x25);
LV_IMG_DECLARE(_up_alpha_25x25);
LV_IMG_DECLARE(_auto_adjust_alpha_25x25);
LV_IMG_DECLARE(_setting_alpha_40x40);
LV_IMG_DECLARE(_buble_light_alpha_35x35);
LV_IMG_DECLARE(_volume_alpha_35x35);

LV_FONT_DECLARE(lv_font_montserratMedium_80)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_10)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_30)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_15)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_40)


#ifdef __cplusplus
}
#endif
#endif
