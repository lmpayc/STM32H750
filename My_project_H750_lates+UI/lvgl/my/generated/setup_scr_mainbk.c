/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_main(lv_ui *ui)
{
    //Write codes main
    ui->main = lv_obj_create(NULL);
    lv_obj_set_size(ui->main, 280, 240);
    lv_obj_set_scrollbar_mode(ui->main, LV_SCROLLBAR_MODE_AUTO);

    //Write style for main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_home_cnt
    ui->main_home_cnt = lv_obj_create(ui->main);
    lv_obj_set_pos(ui->main_home_cnt, 0, 0);
    lv_obj_set_size(ui->main_home_cnt, 280, 240);
    lv_obj_set_scrollbar_mode(ui->main_home_cnt, LV_SCROLLBAR_MODE_OFF);

    //Write style for main_home_cnt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_home_cnt, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_home_cnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_home_cnt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_home_cnt, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_home_cnt, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_home_cnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_home_cnt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_home_cnt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_power_cont
    ui->main_power_cont = lv_obj_create(ui->main);
    lv_obj_set_pos(ui->main_power_cont, 240, 8);
    lv_obj_set_size(ui->main_power_cont, 29, 20);
    lv_obj_set_scrollbar_mode(ui->main_power_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for main_power_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_power_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_power_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_power_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_power_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_power_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_power_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_power_cont, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_power_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_power_bar
    ui->main_power_bar = lv_bar_create(ui->main);
    lv_obj_set_style_anim_time(ui->main_power_bar, 1000, 0);
    lv_bar_set_mode(ui->main_power_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->main_power_bar, 1, 100);
    lv_bar_set_value(ui->main_power_bar, 100, LV_ANIM_OFF);
    lv_obj_set_pos(ui->main_power_bar, 241, 9);
    lv_obj_set_size(ui->main_power_bar, 27, 18);

    //Write style for main_power_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_power_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_power_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_power_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for main_power_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->main_power_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_power_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_power_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_power_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes main_wifi_none_img
    ui->main_wifi_none_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_wifi_none_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_wifi_none_img, &_WIFI_none_alpha_25x25);
    lv_img_set_pivot(ui->main_wifi_none_img, 50,50);
    lv_img_set_angle(ui->main_wifi_none_img, 0);
    lv_obj_set_pos(ui->main_wifi_none_img, 210, 5);
    lv_obj_set_size(ui->main_wifi_none_img, 25, 25);

    //Write style for main_wifi_none_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_wifi_none_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_wifi_none_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_wifi_none_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_wifi_none_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_wifi_img
    ui->main_wifi_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_wifi_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_wifi_img, &_WIFI_alpha_25x25);
    lv_img_set_pivot(ui->main_wifi_img, 50,50);
    lv_img_set_angle(ui->main_wifi_img, 0);
    lv_obj_set_pos(ui->main_wifi_img, 210, 5);
    lv_obj_set_size(ui->main_wifi_img, 25, 25);
    lv_obj_add_flag(ui->main_wifi_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_wifi_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_wifi_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_wifi_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_wifi_img, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_wifi_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_Time_label
    ui->main_Time_label = lv_label_create(ui->main);
    lv_label_set_text(ui->main_Time_label, "12:00");
    lv_label_set_long_mode(ui->main_Time_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_Time_label, 35, 54);
    lv_obj_set_size(ui->main_Time_label, 209, 73);

    //Write style for main_Time_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_Time_label, 73, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_Time_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_Time_label, &lv_font_montserratMedium_80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_Time_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_Time_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_Time_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_pop_cnt
    ui->main_pop_cnt = lv_obj_create(ui->main);
    lv_obj_set_pos(ui->main_pop_cnt, 20, 44);
    lv_obj_set_size(ui->main_pop_cnt, 233, 99);
    lv_obj_set_scrollbar_mode(ui->main_pop_cnt, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->main_pop_cnt, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_pop_cnt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_pop_cnt, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->main_pop_cnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->main_pop_cnt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->main_pop_cnt, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_pop_cnt, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_pop_cnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->main_pop_cnt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->main_pop_cnt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_pop_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_pop_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_pop_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_pop_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_pop_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_split_line
    ui->main_split_line = lv_line_create(ui->main);
    static lv_point_t main_split_line[] = {{0, 0},{280, 0},};
    lv_line_set_points(ui->main_split_line, main_split_line, 2);
    lv_obj_set_pos(ui->main_split_line, 4, 165);
    lv_obj_set_size(ui->main_split_line, 269, 1);

    //Write style for main_split_line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->main_split_line, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->main_split_line, lv_color_hex(0x77C3B9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->main_split_line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->main_split_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_sitting_pos_wrong_img
    ui->main_sitting_pos_wrong_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_sitting_pos_wrong_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_sitting_pos_wrong_img, &_sitting_wrong_alpha_45x45);
    lv_img_set_pivot(ui->main_sitting_pos_wrong_img, 50,50);
    lv_img_set_angle(ui->main_sitting_pos_wrong_img, 0);
    lv_obj_set_pos(ui->main_sitting_pos_wrong_img, 15, 175);
    lv_obj_set_size(ui->main_sitting_pos_wrong_img, 45, 45);
    lv_obj_add_flag(ui->main_sitting_pos_wrong_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_sitting_pos_wrong_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_sitting_pos_wrong_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_sitting_pos_wrong_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_sitting_pos_wrong_img, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_sitting_pos_wrong_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_sitting_pos_right_img
    ui->main_sitting_pos_right_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_sitting_pos_right_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_sitting_pos_right_img, &_sitting_right_alpha_45x45);
    lv_img_set_pivot(ui->main_sitting_pos_right_img, 50,50);
    lv_img_set_angle(ui->main_sitting_pos_right_img, 0);
    lv_obj_set_pos(ui->main_sitting_pos_right_img, 15, 175);
    lv_obj_set_size(ui->main_sitting_pos_right_img, 45, 45);
    lv_obj_add_flag(ui->main_sitting_pos_right_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_sitting_pos_right_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_sitting_pos_right_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_sitting_pos_right_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_sitting_pos_right_img, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_sitting_pos_right_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_sitting_pos_rest_img
    ui->main_sitting_pos_rest_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_sitting_pos_rest_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_sitting_pos_rest_img, &_sitting_not_learning_alpha_45x45);
    lv_img_set_pivot(ui->main_sitting_pos_rest_img, 50,50);
    lv_img_set_angle(ui->main_sitting_pos_rest_img, 0);
    lv_obj_set_pos(ui->main_sitting_pos_rest_img, 15, 175);
    lv_obj_set_size(ui->main_sitting_pos_rest_img, 45, 45);

    //Write style for main_sitting_pos_rest_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_sitting_pos_rest_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_sitting_pos_rest_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_sitting_pos_rest_img, 36, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_sitting_pos_rest_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_learning_time_img
    ui->main_learning_time_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_learning_time_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_learning_time_img, &_learning_time_alpha_45x45);
    lv_img_set_pivot(ui->main_learning_time_img, 50,50);
    lv_img_set_angle(ui->main_learning_time_img, 0);
    lv_obj_set_pos(ui->main_learning_time_img, 178, 175);
    lv_obj_set_size(ui->main_learning_time_img, 45, 45);

    //Write style for main_learning_time_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_learning_time_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_learning_time_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_learning_time_img, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_learning_time_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_pause_img
    ui->main_pause_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_pause_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_pause_img, &_pause_alpha_10x10);
    lv_img_set_pivot(ui->main_pause_img, 50,50);
    lv_img_set_angle(ui->main_pause_img, 0);
    lv_obj_set_pos(ui->main_pause_img, 215, 207);
    lv_obj_set_size(ui->main_pause_img, 10, 10);

    //Write style for main_pause_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_pause_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_pause_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_pause_img, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_pause_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_temperature_img
    ui->main_temperature_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_temperature_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_temperature_img, &_temperature_alpha_45x45);
    lv_img_set_pivot(ui->main_temperature_img, 50,50);
    lv_img_set_angle(ui->main_temperature_img, 0);
    lv_obj_set_pos(ui->main_temperature_img, 65, 175);
    lv_obj_set_size(ui->main_temperature_img, 45, 45);

    //Write style for main_temperature_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_temperature_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_temperature_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_temperature_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_temperature_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_light_down_img
    ui->main_light_down_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_light_down_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_light_down_img, &_buble_dark_alpha_25x50);
    lv_img_set_pivot(ui->main_light_down_img, 50,50);
    lv_img_set_angle(ui->main_light_down_img, 0);
    lv_obj_set_pos(ui->main_light_down_img, 240, 172);
    lv_obj_set_size(ui->main_light_down_img, 25, 50);
    lv_obj_add_flag(ui->main_light_down_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_light_down_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_light_down_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_light_down_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_light_down_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_light_down_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_light_on_img
    ui->main_light_on_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_light_on_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_light_on_img, &_buble_light_alpha_37x50);
    lv_img_set_pivot(ui->main_light_on_img, 50,50);
    lv_img_set_angle(ui->main_light_on_img, 0);
    lv_obj_set_pos(ui->main_light_on_img, 234, 173);
    lv_obj_set_size(ui->main_light_on_img, 37, 50);

    //Write style for main_light_on_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_light_on_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_light_on_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_light_on_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_light_on_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_setting
    ui->main_setting = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_setting, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_setting, &_setting_alpha_25x25);
    lv_img_set_pivot(ui->main_setting, 50,50);
    lv_img_set_angle(ui->main_setting, 0);
    lv_obj_set_pos(ui->main_setting, 10, 5);
    lv_obj_set_size(ui->main_setting, 25, 25);

    //Write style for main_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_setting, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_setting, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_date
    ui->main_date = lv_label_create(ui->main);
    lv_label_set_text(ui->main_date, "XXXX-X-X");
    lv_label_set_long_mode(ui->main_date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_date, 36, 7);
    lv_obj_set_size(ui->main_date, 58, 23);

    //Write style for main_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_date, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_date, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_date, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_start
    ui->main_start = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_start, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_start, &_start_alpha_45x45);
    lv_img_set_pivot(ui->main_start, 50,50);
    lv_img_set_angle(ui->main_start, 0);
    lv_obj_set_pos(ui->main_start, 118, 175);
    lv_obj_set_size(ui->main_start, 45, 45);

    //Write style for main_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_start, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_start, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_sitting_wrong_label
    ui->main_sitting_wrong_label = lv_label_create(ui->main);
    lv_label_set_text(ui->main_sitting_wrong_label, "坐姿错误");
    lv_label_set_long_mode(ui->main_sitting_wrong_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_sitting_wrong_label, 113, 73);
    lv_obj_set_size(ui->main_sitting_wrong_label, 127, 37);
    lv_obj_add_flag(ui->main_sitting_wrong_label, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_sitting_wrong_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_sitting_wrong_label, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_sitting_wrong_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_sitting_wrong_label, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_sitting_wrong_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_sitting_wrong_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_sitting_wrong_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_sitting_wrong_img
    ui->main_large_sitting_wrong_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_sitting_wrong_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_sitting_wrong_img, &_sitting_wrong_alpha_60x60);
    lv_img_set_pivot(ui->main_large_sitting_wrong_img, 50,50);
    lv_img_set_angle(ui->main_large_sitting_wrong_img, 0);
    lv_obj_set_pos(ui->main_large_sitting_wrong_img, 31, 60);
    lv_obj_set_size(ui->main_large_sitting_wrong_img, 60, 60);
    lv_obj_add_flag(ui->main_large_sitting_wrong_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_sitting_wrong_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_sitting_wrong_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_sitting_wrong_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_sitting_wrong_img, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_sitting_wrong_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_sitting_right_label
    ui->main_sitting_right_label = lv_label_create(ui->main);
    lv_label_set_text(ui->main_sitting_right_label, "坐姿正确");
    lv_label_set_long_mode(ui->main_sitting_right_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_sitting_right_label, 113, 73);
    lv_obj_set_size(ui->main_sitting_right_label, 127, 37);
    lv_obj_add_flag(ui->main_sitting_right_label, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_sitting_right_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_sitting_right_label, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_sitting_right_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_sitting_right_label, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_sitting_right_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_sitting_right_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_sitting_right_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_sitting_right_img
    ui->main_large_sitting_right_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_sitting_right_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_sitting_right_img, &_sitting_right_alpha_60x60);
    lv_img_set_pivot(ui->main_large_sitting_right_img, 50,50);
    lv_img_set_angle(ui->main_large_sitting_right_img, 0);
    lv_obj_set_pos(ui->main_large_sitting_right_img, 31, 60);
    lv_obj_set_size(ui->main_large_sitting_right_img, 60, 60);
    lv_obj_add_flag(ui->main_large_sitting_right_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_sitting_right_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_sitting_right_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_sitting_right_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_sitting_right_img, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_sitting_right_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_sitting_rest_label
    ui->main_sitting_rest_label = lv_label_create(ui->main);
    lv_label_set_text(ui->main_sitting_rest_label, "休息中");
    lv_label_set_long_mode(ui->main_sitting_rest_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_sitting_rest_label, 113, 73);
    lv_obj_set_size(ui->main_sitting_rest_label, 110, 38);
    lv_obj_add_flag(ui->main_sitting_rest_label, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_sitting_rest_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_sitting_rest_label, 38, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_sitting_rest_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_sitting_rest_label, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_sitting_rest_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_sitting_rest_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_sitting_rest_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_sitting_rest_image
    ui->main_large_sitting_rest_image = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_sitting_rest_image, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_sitting_rest_image, &_sitting_not_learning_alpha_60x59);
    lv_img_set_pivot(ui->main_large_sitting_rest_image, 50,50);
    lv_img_set_angle(ui->main_large_sitting_rest_image, 0);
    lv_obj_set_pos(ui->main_large_sitting_rest_image, 31, 60);
    lv_obj_set_size(ui->main_large_sitting_rest_image, 60, 59);
    lv_obj_add_flag(ui->main_large_sitting_rest_image, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_sitting_rest_image, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_sitting_rest_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_sitting_rest_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_sitting_rest_image, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_sitting_rest_image, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_learning_time_data
    ui->main_learning_time_data = lv_label_create(ui->main);
    lv_label_set_text(ui->main_learning_time_data, "00:00:00");
    lv_label_set_long_mode(ui->main_learning_time_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_learning_time_data, 120, 73);
    lv_obj_set_size(ui->main_learning_time_data, 126, 32);
    lv_obj_add_flag(ui->main_learning_time_data, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_learning_time_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_learning_time_data, 32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_learning_time_data, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_learning_time_data, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_learning_time_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_learning_time_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_learning_time_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_time_img
    ui->main_large_time_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_time_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_time_img, &_learning_time_alpha_60x60);
    lv_img_set_pivot(ui->main_large_time_img, 50,50);
    lv_img_set_angle(ui->main_large_time_img, 0);
    lv_obj_set_pos(ui->main_large_time_img, 31, 60);
    lv_obj_set_size(ui->main_large_time_img, 60, 60);
    lv_obj_add_flag(ui->main_large_time_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_time_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_time_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_time_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_time_img, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_time_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_pause_img
    ui->main_large_pause_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_pause_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_pause_img, &_pause_alpha_25x25);
    lv_img_set_pivot(ui->main_large_pause_img, 50,50);
    lv_img_set_angle(ui->main_large_pause_img, 0);
    lv_obj_set_pos(ui->main_large_pause_img, 85, 98);
    lv_obj_set_size(ui->main_large_pause_img, 25, 25);
    lv_obj_add_flag(ui->main_large_pause_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_pause_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_pause_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_pause_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_pause_img, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_pause_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_temperature_data
    ui->main_temperature_data = lv_label_create(ui->main);
    lv_label_set_text(ui->main_temperature_data, "26.00℃");
    lv_label_set_long_mode(ui->main_temperature_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_temperature_data, 112, 66);
    lv_obj_set_size(ui->main_temperature_data, 153, 48);
    lv_obj_add_flag(ui->main_temperature_data, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_temperature_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_temperature_data, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_temperature_data, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_temperature_data, &lv_font_SourceHanSerifSC_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_temperature_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_temperature_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_temperature_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_temperature_img
    ui->main_large_temperature_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_temperature_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_temperature_img, &_temperature_alpha_80x80);
    lv_img_set_pivot(ui->main_large_temperature_img, 50,50);
    lv_img_set_angle(ui->main_large_temperature_img, 0);
    lv_obj_set_pos(ui->main_large_temperature_img, 31, 48);
    lv_obj_set_size(ui->main_large_temperature_img, 80, 80);
    lv_obj_add_flag(ui->main_large_temperature_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_temperature_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_temperature_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_temperature_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_temperature_img, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_temperature_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_light_data
    ui->main_light_data = lv_label_create(ui->main);
    lv_label_set_text(ui->main_light_data, "0");
    lv_label_set_long_mode(ui->main_light_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->main_light_data, 126, 66);
    lv_obj_set_size(ui->main_light_data, 91, 59);
    lv_obj_add_flag(ui->main_light_data, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_light_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_light_data, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->main_light_data, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->main_light_data, &lv_font_SourceHanSerifSC_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->main_light_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->main_light_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->main_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_light_on_img
    ui->main_large_light_on_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_light_on_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_light_on_img, &_buble_light_alpha_61x80);
    lv_img_set_pivot(ui->main_large_light_on_img, 50,50);
    lv_img_set_angle(ui->main_large_light_on_img, 0);
    lv_obj_set_pos(ui->main_large_light_on_img, 31, 48);
    lv_obj_set_size(ui->main_large_light_on_img, 61, 80);
    lv_obj_add_flag(ui->main_large_light_on_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_light_on_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_light_on_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_light_on_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_light_on_img, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_light_on_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes main_large_light_off_img
    ui->main_large_light_off_img = lv_img_create(ui->main);
    lv_obj_add_flag(ui->main_large_light_off_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->main_large_light_off_img, &_buble_dark_alpha_40x80);
    lv_img_set_pivot(ui->main_large_light_off_img, 50,50);
    lv_img_set_angle(ui->main_large_light_off_img, 0);
    lv_obj_set_pos(ui->main_large_light_off_img, 42, 48);
    lv_obj_set_size(ui->main_large_light_off_img, 40, 80);
    lv_obj_add_flag(ui->main_large_light_off_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for main_large_light_off_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->main_large_light_off_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->main_large_light_off_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->main_large_light_off_img, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->main_large_light_off_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of main.


    //Update current screen layout.
    lv_obj_update_layout(ui->main);

}
