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



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 280, 240);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_AUTO);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_home_cnt
    ui->screen_home_cnt = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_home_cnt, 0, 0);
    lv_obj_set_size(ui->screen_home_cnt, 280, 240);
    lv_obj_set_scrollbar_mode(ui->screen_home_cnt, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_home_cnt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_home_cnt, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_home_cnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_home_cnt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_home_cnt, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_home_cnt, 26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_home_cnt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_home_cnt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_home_cnt, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_home_cnt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_start_btn
    ui->screen_start_btn = lv_btn_create(ui->screen);
    ui->screen_start_btn_label = lv_label_create(ui->screen_start_btn);
    lv_label_set_text(ui->screen_start_btn_label, "开始学习");
    lv_label_set_long_mode(ui->screen_start_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_start_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_start_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_start_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_start_btn, 107, 214);
    lv_obj_set_size(ui->screen_start_btn, 74, 24);

    //Write style for screen_start_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_start_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_start_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_start_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_start_btn, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_start_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_start_btn, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_start_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_start_btn, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_start_btn, &lv_font_SourceHanSerifSC_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_start_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_start_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_power_cont
    ui->screen_power_cont = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_power_cont, 232, 3);
    lv_obj_set_size(ui->screen_power_cont, 25, 12);
    lv_obj_set_scrollbar_mode(ui->screen_power_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_power_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_power_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_power_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_power_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_power_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_power_cont, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_power_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_power_cont, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_power_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_power_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_power_bar
    ui->screen_power_bar = lv_bar_create(ui->screen);
    lv_obj_set_style_anim_time(ui->screen_power_bar, 1000, 0);
    lv_bar_set_mode(ui->screen_power_bar, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_power_bar, 1, 100);
    lv_bar_set_value(ui->screen_power_bar, 52, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_power_bar, 233, 4);
    lv_obj_set_size(ui->screen_power_bar, 23, 10);

    //Write style for screen_power_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_power_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_power_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_power_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_power_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_power_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_power_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_power_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_power_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_wifi_img
    ui->screen_wifi_img = lv_img_create(ui->screen);
    lv_obj_add_flag(ui->screen_wifi_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_wifi_img, &_WIFI_alpha_13x13);
    lv_img_set_pivot(ui->screen_wifi_img, 50,50);
    lv_img_set_angle(ui->screen_wifi_img, 0);
    lv_obj_set_pos(ui->screen_wifi_img, 214, 2);
    lv_obj_set_size(ui->screen_wifi_img, 13, 13);
    lv_obj_add_flag(ui->screen_wifi_img, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_wifi_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_wifi_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_wifi_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_wifi_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_wifi_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
