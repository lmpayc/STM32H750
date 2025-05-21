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
uint8_t button_cnt = 0;   //开始学习标志
extern lv_group_t *group;   // 组对象
/**********************
 *  STATIC PROTOTYPES
 **********************/

static void btn_event_cb(lv_event_t * e) {
    lv_obj_t * temp_btn = lv_event_get_target(e);
    if(e->code == LV_EVENT_CLICKED) {
        button_cnt++;		
        LED1_Toggle;

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
        lv_obj_clear_flag(ui->screen_wifi_img, LV_OBJ_FLAG_HIDDEN);   //显示wifi连接
    }
    else{
        lv_obj_add_flag(ui->screen_wifi_img, LV_OBJ_FLAG_HIDDEN);
    }
}

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    lv_obj_add_flag(ui->screen_wifi_img, LV_OBJ_FLAG_HIDDEN); //隐藏wifi连接
    lv_obj_add_event_cb(guider_ui.screen_start_btn, btn_event_cb, LV_EVENT_ALL, NULL);    //绑定回调函数

    group = lv_group_create();
    lv_group_add_obj(group, ui->screen_start_btn);
    lv_group_add_obj(group, ui->screen_power_bar);
    
    
    static lv_style_t style_focus;  // 焦点样式
    lv_style_init(&style_focus);
    lv_style_set_outline_color(&style_focus, lv_palette_main(LV_PALETTE_BLUE)); // 蓝色轮廓
    lv_style_set_outline_width(&style_focus, 3);
    lv_style_set_outline_pad(&style_focus, 2); // 距离控件外边缘一点
    lv_style_set_radius(&style_focus, 6);      // 圆角
    lv_obj_add_style(ui->screen_start_btn, &style_focus, LV_STATE_FOCUSED);
    lv_obj_add_style(ui->screen_power_bar, &style_focus, LV_STATE_FOCUSED);

    lv_group_focus_obj(ui->screen_start_btn); // 设置焦点

    lv_group_focus_next(group);

    /* Add your codes here */
}

