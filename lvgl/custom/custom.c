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
#include "lv_draw.h"  // 包含绘图相关函数
#include <stdlib.h>   // 提供 rand() 和 srand()
#include <time.h>     // 提供 time() 函数，用于设置随机种子

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



// 模拟获取电压值（单位：mV）
int read_voltage(void)
{
    // 示例：返回 0~3300 的随机值
    // static int fake_volt = 5000;
    int fake_volt = 5000;
    fake_volt += lv_rand(0, 100) - 50; // 微小波动
    // if (fake_volt < 0) fake_volt = 0;
    // if (fake_volt > 3300) fake_volt = 3300;
    return fake_volt;
}
#include  <stdio.h>
lv_obj_t * line = NULL;
static void show_voltage(lv_timer_t * t)
{
    #define MAX_POINTS  250  // 最多显示50个点
    static uint8_t      data_index = 0;
    static bool         data_full = false;
    static lv_point_precise_t  *points = NULL;

    if(points == NULL){
        points = lv_malloc(MAX_POINTS*sizeof(points[0]));
        for(int i = 0; i < MAX_POINTS; i++){
            points[i].x = i;
        }
    }
    data_full = data_index >= MAX_POINTS ? true : false;
    data_index = data_index >= MAX_POINTS ? MAX_POINTS-1 : data_index;
    if(data_full){
        for(int i = 0; i < data_index; i++){
            points[i].y = points[i+1].y;
        }
    }
    int     voltage = read_voltage();
    int     voltage_base = 4500;
    points[data_index].y = 80-(voltage-voltage_base)*60/600;

    char    buf[8];
    sprintf(buf, "%.3f", (float)voltage/1000.0f);
    lv_label_set_text_fmt(guider_ui.screen_voltageVal, "%s", buf);
    // lv_label_set_text_fmt(guider_ui.screen_voltageVal, "%d", voltage);
    // printf("%d\r\n", points[data_index].y);

    data_index ++;
    lv_line_set_points(line, points, data_index);
}

void custom_init(lv_ui *ui)
{
    lv_rand_set_seed(1234);



    lv_obj_t * chart_area = guider_ui.screen_cont_2;

    // printf("chart_area x1: %d, y1: %d, x2: %d, y2: %d\r\n", chart_area->coords.x1, chart_area->coords.y1,
    //         chart_area->coords.x2, chart_area->coords.y2);
    line = lv_line_create(chart_area);
    lv_obj_set_size(line, 200, 80); // 比最大坐标稍大一些
    lv_obj_set_style_line_width(line, 2, 0); // 设置线宽为 2 像素
    lv_obj_set_style_line_color(line, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align(line, LV_ALIGN_BOTTOM_LEFT, 100, 0);

    /* Add your codes here */
    // lv_obj_add_event_cb(ui->screen_btn_1, btn_event_cb1, LV_EVENT_SHORT_CLICKED, NULL);
    // lv_obj_add_event_cb(ui->screen_btn_1, btn_event_cb2, LV_EVENT_LONG_PRESSED, NULL);
    lv_timer_create(show_voltage, 500, NULL); // 每2秒切换
    lv_timer_create(switch_image_timer_cb, 1000, NULL); // 每2秒切换
}

