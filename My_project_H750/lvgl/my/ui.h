// ui.h

#ifndef UI_H
#define UI_H

#include "lvgl.h"


/**
 * @brief 初始化并创建屏幕上的 UI 元素
 *
 * 在 main 函数中，LVGL 和硬件驱动初始化完成后调用此函数，
 * 用于创建按钮、标签及其事件回调等。
 */
void ui_init(void);
static void btn_event_cb(lv_event_t * e);
#endif // UI_H
