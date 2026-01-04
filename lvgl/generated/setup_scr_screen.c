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
#include <stdio.h>


int screen_digital_clock_1_min_value = 25;
int screen_digital_clock_1_hour_value = 11;
int screen_digital_clock_1_sec_value = 50;
int screen_analog_clock_1_hour_value = 3;
int screen_analog_clock_1_min_value = 20;
int screen_analog_clock_1_sec_value = 50;
void setup_scr_screen(lv_ui *ui)
{
    printf("%s Start!\r\n", __func__);
    printf("%s Write codes screen\r\n", __func__);
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    printf("%s Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_menu_1\r\n", __func__);
    ui->screen_menu_1 = lv_menu_create(ui->screen);
    if(ui->screen_menu_1 == NULL){
        printf("%s: lv_menu_create return NULL\r\n", __func__);
        return;
    }
    lv_obj_set_pos(ui->screen_menu_1, 0, 0);
    lv_obj_set_size(ui->screen_menu_1, 480, 320);
    lv_obj_center(ui->screen_menu_1);
    lv_obj_set_scrollbar_mode(ui->screen_menu_1, LV_SCROLLBAR_MODE_OFF);

    printf("%s Create sidebar page for menu screen_menu_1\r\n", __func__);
    ui->screen_menu_1_sidebar_page = lv_menu_page_create(ui->screen_menu_1, "menu");
    lv_menu_set_sidebar_page(ui->screen_menu_1, ui->screen_menu_1_sidebar_page);
    lv_obj_set_scrollbar_mode(ui->screen_menu_1_sidebar_page, LV_SCROLLBAR_MODE_OFF);

    printf("%s Create subpage for screen_menu_1\r\n", __func__);
    lv_obj_t * screen_menu_1_subpage_1 = lv_menu_page_create(ui->screen_menu_1, NULL);
    ui->screen_menu_1_subpage_1_cont = lv_menu_cont_create(screen_menu_1_subpage_1);
    lv_obj_set_layout(ui->screen_menu_1_subpage_1_cont, LV_LAYOUT_NONE);
    ui->screen_menu_1_cont_1 = lv_menu_cont_create(ui->screen_menu_1_sidebar_page);
    ui->screen_menu_1_label_1 = lv_label_create(ui->screen_menu_1_cont_1);
    lv_label_set_text(ui->screen_menu_1_label_1, "Power");
    lv_obj_set_size(ui->screen_menu_1_label_1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->screen_menu_1_label_1, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(screen_menu_1_subpage_1, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_1, ui->screen_menu_1_cont_1, screen_menu_1_subpage_1);

    printf("%s Create subpage for screen_menu_1\r\n", __func__);
    lv_obj_t * screen_menu_1_subpage_2 = lv_menu_page_create(ui->screen_menu_1, NULL);
    ui->screen_menu_1_subpage_2_cont = lv_menu_cont_create(screen_menu_1_subpage_2);
    lv_obj_set_layout(ui->screen_menu_1_subpage_2_cont, LV_LAYOUT_NONE);
    ui->screen_menu_1_cont_2 = lv_menu_cont_create(ui->screen_menu_1_sidebar_page);
    ui->screen_menu_1_label_2 = lv_label_create(ui->screen_menu_1_cont_2);
    lv_label_set_text(ui->screen_menu_1_label_2, "Calendar");
    lv_obj_set_size(ui->screen_menu_1_label_2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->screen_menu_1_label_2, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(screen_menu_1_subpage_2, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_1, ui->screen_menu_1_cont_2, screen_menu_1_subpage_2);

    printf("%s Create subpage for screen_menu_1\r\n", __func__);
    lv_obj_t * screen_menu_1_subpage_3 = lv_menu_page_create(ui->screen_menu_1, NULL);
    ui->screen_menu_1_subpage_3_cont = lv_menu_cont_create(screen_menu_1_subpage_3);
    lv_obj_set_layout(ui->screen_menu_1_subpage_3_cont, LV_LAYOUT_NONE);
    ui->screen_menu_1_cont_3 = lv_menu_cont_create(ui->screen_menu_1_sidebar_page);
    ui->screen_menu_1_label_3 = lv_label_create(ui->screen_menu_1_cont_3);
    lv_label_set_text(ui->screen_menu_1_label_3, "Button");
    lv_obj_set_size(ui->screen_menu_1_label_3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->screen_menu_1_label_3, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(screen_menu_1_subpage_3, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_1, ui->screen_menu_1_cont_3, screen_menu_1_subpage_3);

    printf("%s Write style for screen_menu_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen_menu_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write style for screen_menu_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_margin_hor(ui->screen_menu_1_sidebar_page, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_margin_ver(ui->screen_menu_1_sidebar_page, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_1_sidebar_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_1_sidebar_page, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_1_sidebar_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu_1_sidebar_page, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu_1_sidebar_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write style state: LV_STATE_DEFAULT for &style_screen_menu_1_extra_option_btns_main_default\r\n", __func__);
    static lv_style_t style_screen_menu_1_extra_option_btns_main_default;
    ui_init_style(&style_screen_menu_1_extra_option_btns_main_default);

    lv_style_set_text_color(&style_screen_menu_1_extra_option_btns_main_default, lv_color_hex(0x151212));
    lv_style_set_text_font(&style_screen_menu_1_extra_option_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_menu_1_extra_option_btns_main_default, 255);
    lv_style_set_text_align(&style_screen_menu_1_extra_option_btns_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_top(&style_screen_menu_1_extra_option_btns_main_default, 10);
    lv_style_set_pad_bottom(&style_screen_menu_1_extra_option_btns_main_default, 10);
    lv_obj_add_style(ui->screen_menu_1_cont_3, &style_screen_menu_1_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_menu_1_cont_2, &style_screen_menu_1_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_menu_1_cont_1, &style_screen_menu_1_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write style state: LV_STATE_CHECKED for &style_screen_menu_1_extra_option_btns_main_checked\r\n", __func__);
    static lv_style_t style_screen_menu_1_extra_option_btns_main_checked;
    ui_init_style(&style_screen_menu_1_extra_option_btns_main_checked);

    lv_style_set_text_color(&style_screen_menu_1_extra_option_btns_main_checked, lv_color_hex(0x9ab700));
    lv_style_set_text_font(&style_screen_menu_1_extra_option_btns_main_checked, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_menu_1_extra_option_btns_main_checked, 255);
    lv_style_set_text_align(&style_screen_menu_1_extra_option_btns_main_checked, LV_TEXT_ALIGN_CENTER);
    lv_style_set_border_width(&style_screen_menu_1_extra_option_btns_main_checked, 0);
    lv_style_set_radius(&style_screen_menu_1_extra_option_btns_main_checked, 5);
    lv_style_set_bg_opa(&style_screen_menu_1_extra_option_btns_main_checked, 60);
    lv_style_set_bg_color(&style_screen_menu_1_extra_option_btns_main_checked, lv_color_hex(0x19a5ff));
    lv_style_set_bg_grad_dir(&style_screen_menu_1_extra_option_btns_main_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_menu_1_cont_3, &style_screen_menu_1_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->screen_menu_1_cont_2, &style_screen_menu_1_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->screen_menu_1_cont_1, &style_screen_menu_1_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);

    printf("%s Write style state: LV_STATE_DEFAULT for &style_screen_menu_1_extra_main_title_main_default\r\n", __func__);
    static lv_style_t style_screen_menu_1_extra_main_title_main_default;
    ui_init_style(&style_screen_menu_1_extra_main_title_main_default);

    lv_style_set_text_color(&style_screen_menu_1_extra_main_title_main_default, lv_color_hex(0x41485a));
    lv_style_set_text_font(&style_screen_menu_1_extra_main_title_main_default, &lv_font_montserratMedium_14);
    lv_style_set_text_opa(&style_screen_menu_1_extra_main_title_main_default, 255);
    lv_style_set_text_align(&style_screen_menu_1_extra_main_title_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_opa(&style_screen_menu_1_extra_main_title_main_default, 0);
    lv_style_set_pad_hor(&style_screen_menu_1_extra_main_title_main_default, 5);
    lv_style_set_pad_ver(&style_screen_menu_1_extra_main_title_main_default, 5);
    lv_menu_t * screen_menu_1_menu= (lv_menu_t *)ui->screen_menu_1;
    lv_obj_t * screen_menu_1_title = screen_menu_1_menu->sidebar_header_title;
    lv_obj_set_size(screen_menu_1_title, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(lv_menu_get_sidebar_header(ui->screen_menu_1), &style_screen_menu_1_extra_main_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_cont_1\r\n", __func__);
    ui->screen_cont_1 = lv_obj_create(ui->screen_menu_1_subpage_1_cont);
    lv_obj_set_pos(ui->screen_cont_1, 0, 0);
    lv_obj_set_size(ui->screen_cont_1, 310, 300);
    lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    printf("%s Write style for screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_PowerPower\r\n", __func__);
    ui->screen_PowerPower = lv_obj_create(ui->screen_cont_1);
    lv_obj_set_pos(ui->screen_PowerPower, 5, 154);
    lv_obj_set_size(ui->screen_PowerPower, 114, 28);
    lv_obj_set_scrollbar_mode(ui->screen_PowerPower, LV_SCROLLBAR_MODE_OFF);

    printf("%s Write style for screen_PowerPower, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_PowerPower, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_PowerPower, 110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_PowerPower, lv_color_hex(0xff9600), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_PowerPower, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_PowerPower, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_PowerPower, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_PowerPower, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_PowerPower, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_PowerPower, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_PowerPower, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_PowerPower, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_PowerPower, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_PowerPower, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_powerVal\r\n", __func__);
    ui->screen_powerVal = lv_label_create(ui->screen_PowerPower);
    lv_obj_set_pos(ui->screen_powerVal, 49, 8);
    lv_obj_set_size(ui->screen_powerVal, 40, 12);
    lv_label_set_text(ui->screen_powerVal, "2.507");
    lv_label_set_long_mode(ui->screen_powerVal, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_powerVal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_powerVal, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_powerVal, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_powerVal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_powerVal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_powerVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_powerUint\r\n", __func__);
    ui->screen_powerUint = lv_label_create(ui->screen_PowerPower);
    lv_obj_set_pos(ui->screen_powerUint, 85, 8);
    lv_obj_set_size(ui->screen_powerUint, 24, 10);
    lv_label_set_text(ui->screen_powerUint, "W");
    lv_label_set_long_mode(ui->screen_powerUint, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_powerUint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_powerUint, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_powerUint, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_powerUint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_powerUint, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_powerUint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_PowerFlag\r\n", __func__);
    ui->screen_PowerFlag = lv_label_create(ui->screen_PowerPower);
    lv_obj_set_pos(ui->screen_PowerFlag, 7, 7);
    lv_obj_set_size(ui->screen_PowerFlag, 44, 12);
    lv_label_set_text(ui->screen_PowerFlag, "Power:");
    lv_label_set_long_mode(ui->screen_PowerFlag, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_PowerFlag, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_PowerFlag, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_PowerFlag, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_PowerFlag, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_PowerFlag, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_PowerFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_PowerCurrent\r\n", __func__);
    ui->screen_PowerCurrent = lv_obj_create(ui->screen_cont_1);
    if(ui->screen_PowerCurrent == NULL){
        printf("NULL\r\n");
        return;
    }
    lv_obj_set_pos(ui->screen_PowerCurrent, 4, 89);
    lv_obj_set_size(ui->screen_PowerCurrent, 122, 28);
    lv_obj_set_scrollbar_mode(ui->screen_PowerCurrent, LV_SCROLLBAR_MODE_OFF);

    printf("%s Write style for screen_PowerCurrent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_PowerCurrent, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_PowerCurrent, 90, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_PowerCurrent, lv_color_hex(0x00fffc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_PowerCurrent, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT | LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_PowerCurrent, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_PowerCurrent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_PowerCurrent, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_PowerCurrent, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_PowerCurrent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_PowerCurrent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_PowerCurrent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_PowerCurrent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_PowerCurrent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_currentVal\r\n", __func__);
    ui->screen_currentVal = lv_label_create(ui->screen_PowerCurrent);
    lv_obj_set_pos(ui->screen_currentVal, 60, 7);
    lv_obj_set_size(ui->screen_currentVal, 40, 12);
    lv_label_set_text(ui->screen_currentVal, "0.505");
    lv_label_set_long_mode(ui->screen_currentVal, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_currentVal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_currentVal, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_currentVal, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_currentVal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_currentVal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_currentVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_currentUnit\r\n", __func__);
    ui->screen_currentUnit = lv_label_create(ui->screen_PowerCurrent);
    lv_obj_set_pos(ui->screen_currentUnit, 93, 7);
    lv_obj_set_size(ui->screen_currentUnit, 24, 10);
    lv_label_set_text(ui->screen_currentUnit, "A");
    lv_label_set_long_mode(ui->screen_currentUnit, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_currentUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_currentUnit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_currentUnit, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_currentUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_currentUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_currentUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_currentFlag\r\n", __func__);
    ui->screen_currentFlag = lv_label_create(ui->screen_PowerCurrent);
    lv_obj_set_pos(ui->screen_currentFlag, 8, 6);
    lv_obj_set_size(ui->screen_currentFlag, 56, 12);
    lv_label_set_text(ui->screen_currentFlag, "Current:");
    lv_label_set_long_mode(ui->screen_currentFlag, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_currentFlag, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_currentFlag, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_currentFlag, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_currentFlag, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_currentFlag, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_currentFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_PowerVoltage\r\n", __func__);
    ui->screen_PowerVoltage = lv_obj_create(ui->screen_cont_1);
    lv_obj_set_pos(ui->screen_PowerVoltage, 4, 27);
    lv_obj_set_size(ui->screen_PowerVoltage, 119, 28);
    lv_obj_set_scrollbar_mode(ui->screen_PowerVoltage, LV_SCROLLBAR_MODE_OFF);

    printf("%s Write style for screen_PowerVoltage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_PowerVoltage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_PowerVoltage, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_PowerVoltage, lv_color_hex(0xff00e9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_PowerVoltage, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_PowerVoltage, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_PowerVoltage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_PowerVoltage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_PowerVoltage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_PowerVoltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_PowerVoltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_PowerVoltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_PowerVoltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_PowerVoltage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_voltageVal\r\n", __func__);
    ui->screen_voltageVal = lv_label_create(ui->screen_PowerVoltage);
    lv_obj_set_pos(ui->screen_voltageVal, 56, 7);
    lv_obj_set_size(ui->screen_voltageVal, 41, 12);
    lv_label_set_text(ui->screen_voltageVal, "5.003");
    lv_label_set_long_mode(ui->screen_voltageVal, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_voltageVal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_voltageVal, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_voltageVal, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_voltageVal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_voltageVal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_voltageVal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_voltageUnit\r\n", __func__);
    ui->screen_voltageUnit = lv_label_create(ui->screen_PowerVoltage);
    lv_obj_set_pos(ui->screen_voltageUnit, 98, 7);
    lv_obj_set_size(ui->screen_voltageUnit, 10, 12);
    lv_label_set_text(ui->screen_voltageUnit, "V");
    lv_label_set_long_mode(ui->screen_voltageUnit, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_voltageUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_voltageUnit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_voltageUnit, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_voltageUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_voltageUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_voltageUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_voltageFlag\r\n", __func__);
    ui->screen_voltageFlag = lv_label_create(ui->screen_PowerVoltage);
    lv_obj_set_pos(ui->screen_voltageFlag, 4, 6);
    lv_obj_set_size(ui->screen_voltageFlag, 59, 13);
    lv_label_set_text(ui->screen_voltageFlag, "Voltage:");
    lv_label_set_long_mode(ui->screen_voltageFlag, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_voltageFlag, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_voltageFlag, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_voltageFlag, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_voltageFlag, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_voltageFlag, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_voltageFlag, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_digital_clock_1\r\n", __func__);
    static bool screen_digital_clock_1_timer_enabled = false;
    ui->screen_digital_clock_1 = lv_label_create(ui->screen_cont_1);
    lv_obj_set_pos(ui->screen_digital_clock_1, 189, 28);
    lv_obj_set_size(ui->screen_digital_clock_1, 121, 30);
    lv_label_set_text(ui->screen_digital_clock_1, "11:25:50");
    if (!screen_digital_clock_1_timer_enabled) {
        lv_timer_create(screen_digital_clock_1_timer, 1000, NULL);
        screen_digital_clock_1_timer_enabled = true;
    }

    printf("%s Write style for screen_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_radius(ui->screen_digital_clock_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_digital_clock_1, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_digital_clock_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_digital_clock_1, 97, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_digital_clock_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_img_1\r\n", __func__);
    ui->screen_img_1 = lv_image_create(ui->screen_cont_1);
    lv_obj_set_pos(ui->screen_img_1, 196, 72);
    lv_obj_set_size(ui->screen_img_1, 100, 100);
    lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_1, &_1f60e_RGB565A8_100x100);
    lv_image_set_pivot(ui->screen_img_1, 50,50);
    lv_image_set_rotation(ui->screen_img_1, 0);

    printf("%s Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_image_recolor_opa(ui->screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_cont_2\r\n", __func__);
    ui->screen_cont_2 = lv_obj_create(ui->screen_cont_1);
    lv_obj_set_pos(ui->screen_cont_2, -1, 205);
    lv_obj_set_size(ui->screen_cont_2, 307, 89);
    lv_obj_set_scrollbar_mode(ui->screen_cont_2, LV_SCROLLBAR_MODE_OFF);

    printf("%s Write style for screen_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_2, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_vol_num\r\n", __func__);
    ui->screen_vol_num = lv_label_create(ui->screen_cont_2);
    lv_obj_set_pos(ui->screen_vol_num, 153, -29);
    lv_obj_set_size(ui->screen_vol_num, 37, 16);
    lv_label_set_text(ui->screen_vol_num, "0");
    lv_label_set_long_mode(ui->screen_vol_num, LV_LABEL_LONG_WRAP);

    printf("%s Write style for screen_vol_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_border_width(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_vol_num, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_vol_num, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_vol_num, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_vol_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_vol_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_vol_num, 99, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_vol_num, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_vol_num, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_vol_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_vol_line\r\n", __func__);
    ui->screen_vol_line = lv_line_create(ui->screen_cont_2);
    lv_obj_set_pos(ui->screen_vol_line, 5, 0);
    lv_obj_set_size(ui->screen_vol_line, 294, 85);
    static lv_point_precise_t screen_vol_line[] = {};
    lv_line_set_points(ui->screen_vol_line, screen_vol_line, 0);

    printf("%s Write style for screen_vol_line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_line_width(ui->screen_vol_line, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_vol_line, lv_color_hex(0xff003b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_vol_line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_vol_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_analog_clock_1\r\n", __func__);
    static bool screen_analog_clock_1_timer_enabled = false;
    static const char * screen_analog_clock_1_hour_ticks[] = {"12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", NULL};
    ui->screen_analog_clock_1 = lv_scale_create(ui->screen_menu_1_subpage_2_cont);
    lv_obj_set_pos(ui->screen_analog_clock_1, 90, 99);
    lv_obj_set_size(ui->screen_analog_clock_1, 135, 135);
    lv_scale_set_mode(ui->screen_analog_clock_1, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_angle_range(ui->screen_analog_clock_1, 360U);
    lv_scale_set_range(ui->screen_analog_clock_1, 0U, 60U);
    lv_scale_set_rotation(ui->screen_analog_clock_1, 270U);
    lv_obj_set_style_radius(ui->screen_analog_clock_1, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_clip_corner(ui->screen_analog_clock_1, true, LV_PART_MAIN);
    lv_obj_set_style_arc_width(ui->screen_analog_clock_1, 0, LV_PART_MAIN);

    lv_scale_set_total_tick_count(ui->screen_analog_clock_1, 61);

    lv_scale_set_major_tick_every(ui->screen_analog_clock_1, 5);
    lv_scale_set_text_src(ui->screen_analog_clock_1, screen_analog_clock_1_hour_ticks);
    lv_obj_update_layout(ui->screen_analog_clock_1);
    ui->screen_analog_clock_1_hour_needle = lv_line_create(ui->screen_analog_clock_1);
    lv_obj_set_style_line_width(ui->screen_analog_clock_1_hour_needle, 4, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->screen_analog_clock_1_hour_needle, lv_color_hex(0x00ff00), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->screen_analog_clock_1_hour_needle, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->screen_analog_clock_1, ui->screen_analog_clock_1_hour_needle, 30, screen_analog_clock_1_hour_value * 5);
    ui->screen_analog_clock_1_min_needle = lv_line_create(ui->screen_analog_clock_1);
    lv_obj_set_style_line_width(ui->screen_analog_clock_1_min_needle, 3, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->screen_analog_clock_1_min_needle, lv_color_hex(0xE1FF00), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->screen_analog_clock_1_min_needle, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->screen_analog_clock_1, ui->screen_analog_clock_1_min_needle, 40, screen_analog_clock_1_min_value);
    ui->screen_analog_clock_1_sec_needle = lv_line_create(ui->screen_analog_clock_1);
    lv_obj_set_style_line_width(ui->screen_analog_clock_1_sec_needle, 2, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->screen_analog_clock_1_sec_needle, lv_color_hex(0xE1FF00), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->screen_analog_clock_1_sec_needle, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->screen_analog_clock_1, ui->screen_analog_clock_1_sec_needle, 60, screen_analog_clock_1_sec_value);
    printf("%s  create timer\r\n", __func__);
    if (!screen_analog_clock_1_timer_enabled) {
        lv_timer_create(screen_analog_clock_1_timer, 1000, NULL);
        screen_analog_clock_1_timer_enabled = true;
    }

    printf("%s Write style for screen_analog_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen_analog_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_analog_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write style for screen_analog_clock_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_text_color(ui->screen_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_analog_clock_1, &lv_font_montserratMedium_14, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_analog_clock_1, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_analog_clock_1, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_length(ui->screen_analog_clock_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    printf("%s Write style for screen_analog_clock_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_line_width(ui->screen_analog_clock_1, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_analog_clock_1, lv_color_hex(0x000000), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_analog_clock_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->screen_analog_clock_1, true, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_length(ui->screen_analog_clock_1, 6, LV_PART_ITEMS|LV_STATE_DEFAULT);

    printf("%s Write codes screen_datetext_1\r\n", __func__);
    ui->screen_datetext_1 = lv_label_create(ui->screen_menu_1_subpage_2_cont);
    lv_obj_set_pos(ui->screen_datetext_1, 91, 41);
    lv_obj_set_size(ui->screen_datetext_1, 132, 28);
    lv_label_set_text(ui->screen_datetext_1, "2025/12/31");
    lv_obj_set_style_text_align(ui->screen_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->screen_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->screen_datetext_1, screen_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    printf("%s Write style for screen_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_radius(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_datetext_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_datetext_1, 111, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_datetext_1, lv_color_hex(0xf2bc00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_datetext_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_datetext_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_datetext_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write codes screen_slider_1\r\n", __func__);
    ui->screen_slider_1 = lv_slider_create(ui->screen_menu_1_subpage_3_cont);
    lv_obj_set_pos(ui->screen_slider_1, 31, 270);
    lv_obj_set_size(ui->screen_slider_1, 277, 25);
    lv_slider_set_range(ui->screen_slider_1, 0, 100);
    lv_slider_set_mode(ui->screen_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->screen_slider_1, 50, LV_ANIM_OFF);

    printf("%s Write style for screen_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write style for screen_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    printf("%s Write style for screen_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    printf("%s Write codes screen_meter_1\r\n", __func__);
    ui->screen_meter_1 = lv_scale_create(ui->screen_menu_1_subpage_3_cont);
    lv_obj_set_pos(ui->screen_meter_1, 28, 53);
    lv_obj_set_size(ui->screen_meter_1, 80, 80);
    lv_obj_update_layout(ui->screen_meter_1);
    lv_scale_set_mode(ui->screen_meter_1, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_total_tick_count(ui->screen_meter_1, 41);
    lv_scale_set_major_tick_every(ui->screen_meter_1, 8);
    lv_scale_set_label_show(ui->screen_meter_1, true);
    lv_scale_set_range(ui->screen_meter_1, 0, 100);
    lv_scale_set_angle_range(ui->screen_meter_1, 300);
    lv_scale_set_rotation(ui->screen_meter_1, 90);
    lv_scale_set_post_draw(ui->screen_meter_1, true);


    printf("%s Write style for screen_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_bg_opa(ui->screen_meter_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meter_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meter_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meter_1, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->screen_meter_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_meter_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_meter_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->screen_meter_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meter_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meter_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meter_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    printf("%s Write style for screen_meter_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_length(ui->screen_meter_1, 5, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_meter_1, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_meter_1, lv_color_hex(0x757575), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_meter_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);

    printf("%s Write style for screen_meter_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.\r\n", __func__);
    lv_obj_set_style_length(ui->screen_meter_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_meter_1, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_meter_1, lv_color_hex(0x757575), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_meter_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    printf("%s Write codes screen_led_1\r\n", __func__);
    ui->screen_led_1 = lv_led_create(ui->screen_menu_1_subpage_3_cont);
    lv_obj_set_pos(ui->screen_led_1, 219, 66);
    lv_obj_set_size(ui->screen_led_1, 40, 40);
    lv_led_set_brightness(ui->screen_led_1, 255);
    lv_led_set_color(ui->screen_led_1, lv_color_hex(0x00a1b5));

    printf("%s The custom code of screen.\r\n", __func__);


    printf("%s Update current screen layout.\r\n", __func__);
    lv_obj_update_layout(ui->screen);
    printf("%s End\r\n",  __func__);
}
