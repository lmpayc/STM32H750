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



void setup_scr_setting(lv_ui *ui)
{
    //Write codes setting
    ui->setting = lv_obj_create(NULL);
    lv_obj_set_size(ui->setting, 280, 240);
    lv_obj_set_scrollbar_mode(ui->setting, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_view_port
    ui->setting_view_port = lv_obj_create(ui->setting);
    lv_obj_set_pos(ui->setting_view_port, 0, 0);
    lv_obj_set_size(ui->setting_view_port, 290, 400);
    lv_obj_set_scrollbar_mode(ui->setting_view_port, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_view_port, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_view_port, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_view_port, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_view_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_view_port, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_view_port, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_view_port, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_view_port, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_view_port, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_view_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_view_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_view_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_view_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_view_port, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_backgroud_cont
    ui->setting_backgroud_cont = lv_obj_create(ui->setting_view_port);
    lv_obj_set_pos(ui->setting_backgroud_cont, 0, -1);
    lv_obj_set_size(ui->setting_backgroud_cont, 280, 240);
    lv_obj_set_scrollbar_mode(ui->setting_backgroud_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_backgroud_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_backgroud_cont, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_backgroud_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_backgroud_cont, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_backgroud_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_backgroud_cont, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_backgroud_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_backgroud_cont, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_backgroud_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_backgroud_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_backgroud_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_backgroud_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_backgroud_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_backgroud_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_config_cont
    ui->setting_config_cont = lv_obj_create(ui->setting_backgroud_cont);
    lv_obj_set_pos(ui->setting_config_cont, 18, 46);
    lv_obj_set_size(ui->setting_config_cont, 244, 340);
    lv_obj_set_scrollbar_mode(ui->setting_config_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_config_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_config_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_config_cont, 122, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_config_cont, lv_color_hex(0xacacac), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_config_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_config_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_config_cont, 38, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_config_cont, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_config_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_config_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_config_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_config_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_config_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_config_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_label_1
    ui->setting_label_1 = lv_label_create(ui->setting_config_cont);
    lv_label_set_text(ui->setting_label_1, "自动视角调整\n");
    lv_label_set_long_mode(ui->setting_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_label_1, 18, 274);
    lv_obj_set_size(ui->setting_label_1, 97, 15);

    //Write style for setting_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_label_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_label_1, &lv_font_SourceHanSerifSC_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_down_arrow
    ui->setting_down_arrow = lv_img_create(ui->setting_backgroud_cont);
    lv_obj_add_flag(ui->setting_down_arrow, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_down_arrow, &_down_alpha_25x25);
    lv_img_set_pivot(ui->setting_down_arrow, 50,50);
    lv_img_set_angle(ui->setting_down_arrow, 0);
    lv_obj_set_pos(ui->setting_down_arrow, 216, 275);
    lv_obj_set_size(ui->setting_down_arrow, 25, 25);

    //Write style for setting_down_arrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_down_arrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_down_arrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_down_arrow, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_down_arrow, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_up_arrow
    ui->setting_up_arrow = lv_img_create(ui->setting_backgroud_cont);
    lv_obj_add_flag(ui->setting_up_arrow, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_up_arrow, &_up_alpha_25x25);
    lv_img_set_pivot(ui->setting_up_arrow, 50,50);
    lv_img_set_angle(ui->setting_up_arrow, 0);
    lv_obj_set_pos(ui->setting_up_arrow, 216, 235);
    lv_obj_set_size(ui->setting_up_arrow, 25, 25);

    //Write style for setting_up_arrow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_up_arrow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_up_arrow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_up_arrow, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_up_arrow, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_auto_adjust_view
    ui->setting_auto_adjust_view = lv_img_create(ui->setting_backgroud_cont);
    lv_obj_add_flag(ui->setting_auto_adjust_view, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_auto_adjust_view, &_auto_adjust_alpha_25x25);
    lv_img_set_pivot(ui->setting_auto_adjust_view, 50,50);
    lv_img_set_angle(ui->setting_auto_adjust_view, 0);
    lv_obj_set_pos(ui->setting_auto_adjust_view, 216, 320);
    lv_obj_set_size(ui->setting_auto_adjust_view, 25, 25);

    //Write style for setting_auto_adjust_view, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_auto_adjust_view, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_auto_adjust_view, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_auto_adjust_view, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_auto_adjust_view, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_camer_view_hand
    ui->setting_camer_view_hand = lv_label_create(ui->setting_backgroud_cont);
    lv_label_set_text(ui->setting_camer_view_hand, "视角调整\n");
    lv_label_set_long_mode(ui->setting_camer_view_hand, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_camer_view_hand, 40, 255);
    lv_obj_set_size(ui->setting_camer_view_hand, 64, 15);

    //Write style for setting_camer_view_hand, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_camer_view_hand, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_camer_view_hand, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_camer_view_hand, &lv_font_SourceHanSerifSC_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_camer_view_hand, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_camer_view_hand, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_camer_view_hand, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_setting_image
    ui->setting_setting_image = lv_img_create(ui->setting_backgroud_cont);
    lv_obj_add_flag(ui->setting_setting_image, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_setting_image, &_setting_alpha_40x40);
    lv_img_set_pivot(ui->setting_setting_image, 50,50);
    lv_img_set_angle(ui->setting_setting_image, 0);
    lv_obj_set_pos(ui->setting_setting_image, 5, 5);
    lv_obj_set_size(ui->setting_setting_image, 40, 40);

    //Write style for setting_setting_image, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_setting_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_setting_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_setting_image, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_setting_image, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_light_slider
    ui->setting_light_slider = lv_slider_create(ui->setting_backgroud_cont);
    lv_slider_set_range(ui->setting_light_slider, 0, 100);
    lv_slider_set_mode(ui->setting_light_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->setting_light_slider, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->setting_light_slider, 85, 65);
    lv_obj_set_size(ui->setting_light_slider, 165, 7);

    //Write style for setting_light_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->setting_light_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_light_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_light_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_slider, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for setting_light_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_slider, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_light_img
    ui->setting_light_img = lv_img_create(ui->setting_backgroud_cont);
    lv_obj_add_flag(ui->setting_light_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_light_img, &_buble_light_alpha_35x35);
    lv_img_set_pivot(ui->setting_light_img, 50,50);
    lv_img_set_angle(ui->setting_light_img, 0);
    lv_obj_set_pos(ui->setting_light_img, 30, 50);
    lv_obj_set_size(ui->setting_light_img, 35, 35);

    //Write style for setting_light_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_light_img, 37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->setting_light_img, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_light_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_light_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_light_label
    ui->setting_light_label = lv_label_create(ui->setting_backgroud_cont);
    lv_label_set_text(ui->setting_light_label, "主动灯光");
    lv_label_set_long_mode(ui->setting_light_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_light_label, 40, 95);
    lv_obj_set_size(ui->setting_light_label, 60, 15);

    //Write style for setting_light_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_label, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_light_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_light_label, &lv_font_SourceHanSerifSC_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_light_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_light_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_light_auto_switch
    ui->setting_light_auto_switch = lv_switch_create(ui->setting_backgroud_cont);
    lv_obj_set_pos(ui->setting_light_auto_switch, 210, 91);
    lv_obj_set_size(ui->setting_light_auto_switch, 40, 20);

    //Write style for setting_light_auto_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_auto_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_auto_switch, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_auto_switch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_light_auto_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_auto_switch, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_light_auto_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_light_auto_switch, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->setting_light_auto_switch, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->setting_light_auto_switch, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_auto_switch, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->setting_light_auto_switch, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for setting_light_auto_switch, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_auto_switch, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_auto_switch, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_auto_switch, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_light_auto_switch, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_auto_switch, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_volume__switch
    ui->setting_volume__switch = lv_switch_create(ui->setting_backgroud_cont);
    lv_obj_set_pos(ui->setting_volume__switch, 210, 190);
    lv_obj_set_size(ui->setting_volume__switch, 40, 20);

    //Write style for setting_volume__switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_volume__switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_volume__switch, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_volume__switch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_volume__switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume__switch, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_volume__switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_volume__switch, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->setting_volume__switch, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->setting_volume__switch, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->setting_volume__switch, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->setting_volume__switch, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for setting_volume__switch, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_volume__switch, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_volume__switch, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_volume__switch, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_volume__switch, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume__switch, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_volume_img
    ui->setting_volume_img = lv_img_create(ui->setting_backgroud_cont);
    lv_obj_add_flag(ui->setting_volume_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_volume_img, &_volume_alpha_35x35);
    lv_img_set_pivot(ui->setting_volume_img, 50,50);
    lv_img_set_angle(ui->setting_volume_img, 0);
    lv_obj_set_pos(ui->setting_volume_img, 33, 152);
    lv_obj_set_size(ui->setting_volume_img, 35, 35);

    //Write style for setting_volume_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_volume_img, 38, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->setting_volume_img, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_volume_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_volume_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_volume_lable
    ui->setting_volume_lable = lv_label_create(ui->setting_backgroud_cont);
    lv_label_set_text(ui->setting_volume_lable, "音响");
    lv_label_set_long_mode(ui->setting_volume_lable, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_volume_lable, 40, 195);
    lv_obj_set_size(ui->setting_volume_lable, 30, 15);

    //Write style for setting_volume_lable, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_lable, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_volume_lable, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_volume_lable, &lv_font_SourceHanSerifSC_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_volume_lable, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_volume_lable, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_volume_slider
    ui->setting_volume_slider = lv_slider_create(ui->setting_backgroud_cont);
    lv_slider_set_range(ui->setting_volume_slider, 0, 100);
    lv_slider_set_mode(ui->setting_volume_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->setting_volume_slider, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->setting_volume_slider, 85, 165);
    lv_obj_set_size(ui->setting_volume_slider, 165, 7);

    //Write style for setting_volume_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_volume_slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_volume_slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_volume_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_slider, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->setting_volume_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_volume_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_volume_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_volume_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_volume_slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_volume_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_slider, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for setting_volume_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_volume_slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_volume_slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_volume_slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_slider, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_light_pid_switch
    ui->setting_light_pid_switch = lv_switch_create(ui->setting_backgroud_cont);
    lv_obj_set_pos(ui->setting_light_pid_switch, 210, 120);
    lv_obj_set_size(ui->setting_light_pid_switch, 40, 20);

    //Write style for setting_light_pid_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_pid_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_pid_switch, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_pid_switch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_light_pid_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_pid_switch, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_light_pid_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for setting_light_pid_switch, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->setting_light_pid_switch, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->setting_light_pid_switch, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_pid_switch, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->setting_light_pid_switch, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for setting_light_pid_switch, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_pid_switch, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_pid_switch, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_pid_switch, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->setting_light_pid_switch, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_pid_switch, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes setting_light_pid_lable
    ui->setting_light_pid_lable = lv_label_create(ui->setting_backgroud_cont);
    lv_label_set_text(ui->setting_light_pid_lable, "自动控制灯光");
    lv_label_set_long_mode(ui->setting_light_pid_lable, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_light_pid_lable, 40, 125);
    lv_obj_set_size(ui->setting_light_pid_lable, 90, 15);

    //Write style for setting_light_pid_lable, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_pid_lable, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_light_pid_lable, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_light_pid_lable, &lv_font_SourceHanSerifSC_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_light_pid_lable, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_light_pid_lable, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_light_pid_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of setting.


    //Update current screen layout.
    lv_obj_update_layout(ui->setting);

}
