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

    //Write codes setting_cont_1
    ui->setting_cont_1 = lv_obj_create(ui->setting);
    lv_obj_set_pos(ui->setting_cont_1, 0, 0);
    lv_obj_set_size(ui->setting_cont_1, 280, 240);
    lv_obj_set_scrollbar_mode(ui->setting_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for setting_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_cont_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->setting_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->setting_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->setting_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_cont_1, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_setting_image
    ui->setting_setting_image = lv_img_create(ui->setting);
    lv_obj_add_flag(ui->setting_setting_image, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_setting_image, &_setting_alpha_30x30);
    lv_img_set_pivot(ui->setting_setting_image, 50,50);
    lv_img_set_angle(ui->setting_setting_image, 0);
    lv_obj_set_pos(ui->setting_setting_image, 10, 5);
    lv_obj_set_size(ui->setting_setting_image, 30, 30);

    //Write style for setting_setting_image, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_setting_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_setting_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_setting_image, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_setting_image, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_setting_label
    ui->setting_setting_label = lv_label_create(ui->setting);
    lv_label_set_text(ui->setting_setting_label, "设置");
    lv_label_set_long_mode(ui->setting_setting_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_setting_label, 45, 15);
    lv_obj_set_size(ui->setting_setting_label, 21, 12);

    //Write style for setting_setting_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_setting_label, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_setting_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_setting_label, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_setting_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_setting_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_setting_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_light_slider
    ui->setting_light_slider = lv_slider_create(ui->setting);
    lv_slider_set_range(ui->setting_light_slider, 0, 100);
    lv_slider_set_mode(ui->setting_light_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->setting_light_slider, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->setting_light_slider, 89, 68);
    lv_obj_set_size(ui->setting_light_slider, 158, 4);

    //Write style for setting_light_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->setting_light_slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->setting_light_slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->setting_light_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_slider, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
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
    ui->setting_light_img = lv_img_create(ui->setting);
    lv_obj_add_flag(ui->setting_light_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_light_img, &_buble_light_alpha_30x30);
    lv_img_set_pivot(ui->setting_light_img, 50,50);
    lv_img_set_angle(ui->setting_light_img, 0);
    lv_obj_set_pos(ui->setting_light_img, 10, 50);
    lv_obj_set_size(ui->setting_light_img, 30, 30);

    //Write style for setting_light_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_light_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_light_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_light_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_light_label
    ui->setting_light_label = lv_label_create(ui->setting);
    lv_label_set_text(ui->setting_light_label, "灯光");
    lv_label_set_long_mode(ui->setting_light_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_light_label, 45, 50);
    lv_obj_set_size(ui->setting_light_label, 20, 10);

    //Write style for setting_light_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_light_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_label, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_light_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_light_label, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
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
    ui->setting_light_auto_switch = lv_switch_create(ui->setting);
    lv_obj_set_pos(ui->setting_light_auto_switch, 43, 68);
    lv_obj_set_size(ui->setting_light_auto_switch, 26, 12);

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

    //Write codes setting_light_data
    ui->setting_light_data = lv_label_create(ui->setting);
    lv_label_set_text(ui->setting_light_data, "0");
    lv_label_set_long_mode(ui->setting_light_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_light_data, 257, 63);
    lv_obj_set_size(ui->setting_light_data, 9, 12);

    //Write style for setting_light_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_light_data, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_light_data, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_light_data, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_light_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_light_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_light_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_volume_img
    ui->setting_volume_img = lv_img_create(ui->setting);
    lv_obj_add_flag(ui->setting_volume_img, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->setting_volume_img, &_volume_alpha_30x30);
    lv_img_set_pivot(ui->setting_volume_img, 50,50);
    lv_img_set_angle(ui->setting_volume_img, 0);
    lv_obj_set_pos(ui->setting_volume_img, 10, 95);
    lv_obj_set_size(ui->setting_volume_img, 30, 30);

    //Write style for setting_volume_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->setting_volume_img, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->setting_volume_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_img, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->setting_volume_img, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes setting_volume_lable
    ui->setting_volume_lable = lv_label_create(ui->setting);
    lv_label_set_text(ui->setting_volume_lable, "音量");
    lv_label_set_long_mode(ui->setting_volume_lable, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_volume_lable, 45, 104);
    lv_obj_set_size(ui->setting_volume_lable, 22, 10);

    //Write style for setting_volume_lable, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_volume_lable, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_lable, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_volume_lable, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_volume_lable, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
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
    ui->setting_volume_slider = lv_slider_create(ui->setting);
    lv_slider_set_range(ui->setting_volume_slider, 0, 100);
    lv_slider_set_mode(ui->setting_volume_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->setting_volume_slider, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->setting_volume_slider, 89, 108);
    lv_obj_set_size(ui->setting_volume_slider, 158, 4);

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

    //Write codes setting_volume_data
    ui->setting_volume_data = lv_label_create(ui->setting);
    lv_label_set_text(ui->setting_volume_data, "0");
    lv_label_set_long_mode(ui->setting_volume_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->setting_volume_data, 257, 104);
    lv_obj_set_size(ui->setting_volume_data, 9, 12);

    //Write style for setting_volume_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->setting_volume_data, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->setting_volume_data, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->setting_volume_data, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->setting_volume_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->setting_volume_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->setting_volume_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of setting.


    //Update current screen layout.
    lv_obj_update_layout(ui->setting);

}
