/*
* Copyright 2024 NXP
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
// #include "ui_helpers.h"  // 包含图片声明

static bool show_first = true;

static void switch_image_timer_cb(lv_timer_t * t)
{
    lv_obj_t * img = guider_ui.screen_img_1;  // 替换为你的 Image ID

    if (show_first) {
        lv_img_set_src(img, &_1f60e_RGB565A8_100x100);
        show_first = false;
    } else {
        lv_img_set_src(img, &_1f60d_RGB565A8_100x100);
        show_first = true;
    }
}

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

#include "lv_event.h"

// void btn_event_cb1(lv_event_t * e){
//     lv_event_code_t code = lv_event_get_code(e);

//     static  led_state = 0;
//     led_state = (led_state + 1) % 3;

//     // 根据状态设置 LED 颜色
//     lv_color_t color;
//     switch (led_state) {
//         case 0: color.blue = 0x00; color.green = 0x00; color.red = 0xFF;  break;
//         case 1: color.blue = 0x00; color.green = 0xFF; color.red = 0x00;  break;
//         case 2: color.blue = 0xFF; color.green = 0x00; color.red = 0x00;  break;
//         default: color.blue = 0x00; color.green = 0x00; color.red = 0xFF;  break;
//     }

//     // 更新虚拟 LED 的背景色
//     lv_led_set_color(guider_ui.screen_led_1, color);
//     // lv_obj_set_style_bg_color(guider_ui.screen_led_1, color, LV_PART_MAIN);
// }

// void btn_event_cb2(lv_event_t * e){
//     lv_event_code_t code = lv_event_get_code(e);

//     static  led_state = 0;
//     led_state = (led_state + 1) % 3;

//     // 根据状态设置 LED 颜色
//     lv_color_t color;
//     switch (led_state) {
//         case 0: color.blue = 0x00; color.green = 0x00; color.red = 0xFF;  break;
//         case 1: color.blue = 0x00; color.green = 0xFF; color.red = 0x00;  break;
//         case 2: color.blue = 0xFF; color.green = 0x00; color.red = 0x00;  break;
//         default: color.blue = 0x00; color.green = 0x00; color.red = 0xFF;  break;
//     }

//     // 更新虚拟 LED 的背景色
//     lv_led_set_color(guider_ui.screen_led_2, color);
//     // lv_obj_set_style_bg_color(guider_ui.screen_led_1, color, LV_PART_MAIN);
// }

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    // lv_obj_add_event_cb(ui->screen_btn_1, btn_event_cb1, LV_EVENT_SHORT_CLICKED, NULL);
    // lv_obj_add_event_cb(ui->screen_btn_1, btn_event_cb2, LV_EVENT_LONG_PRESSED, NULL);
    lv_timer_create(switch_image_timer_cb, 2000, NULL); // 每2秒切换
}

