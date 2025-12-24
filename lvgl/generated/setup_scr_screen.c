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
#include "lv_menu_private.h"



int screen_digital_clock_1_min_value = 25;
int screen_digital_clock_1_hour_value = 11;
int screen_digital_clock_1_sec_value = 50;
void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_menu_1
    ui->screen_menu_1 = lv_menu_create(ui->screen);
    lv_obj_set_pos(ui->screen_menu_1, 4, 6);
    lv_obj_set_size(ui->screen_menu_1, 473, 315);
    lv_obj_set_scrollbar_mode(ui->screen_menu_1, LV_SCROLLBAR_MODE_OFF);

    //Create sidebar page for menu screen_menu_1
    ui->screen_menu_1_sidebar_page = lv_menu_page_create(ui->screen_menu_1, "menu");
    lv_menu_set_sidebar_page(ui->screen_menu_1, ui->screen_menu_1_sidebar_page);
    lv_obj_set_scrollbar_mode(ui->screen_menu_1_sidebar_page, LV_SCROLLBAR_MODE_OFF);

    //Create subpage for screen_menu_1
    lv_obj_t * screen_menu_1_subpage_1 = lv_menu_page_create(ui->screen_menu_1, NULL);
    ui->screen_menu_1_subpage_1_cont = lv_menu_cont_create(screen_menu_1_subpage_1);
    lv_obj_set_layout(ui->screen_menu_1_subpage_1_cont, LV_LAYOUT_NONE);
    ui->screen_menu_1_cont_1 = lv_menu_cont_create(ui->screen_menu_1_sidebar_page);
    ui->screen_menu_1_label_1 = lv_label_create(ui->screen_menu_1_cont_1);
    lv_label_set_text(ui->screen_menu_1_label_1, "Button-Led");
    lv_obj_set_size(ui->screen_menu_1_label_1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->screen_menu_1_label_1, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(screen_menu_1_subpage_1, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_1, ui->screen_menu_1_cont_1, screen_menu_1_subpage_1);

    //Create subpage for screen_menu_1
    lv_obj_t * screen_menu_1_subpage_2 = lv_menu_page_create(ui->screen_menu_1, NULL);
    ui->screen_menu_1_subpage_2_cont = lv_menu_cont_create(screen_menu_1_subpage_2);
    lv_obj_set_layout(ui->screen_menu_1_subpage_2_cont, LV_LAYOUT_NONE);
    ui->screen_menu_1_cont_2 = lv_menu_cont_create(ui->screen_menu_1_sidebar_page);
    ui->screen_menu_1_label_2 = lv_label_create(ui->screen_menu_1_cont_2);
    lv_label_set_text(ui->screen_menu_1_label_2, "Clock");
    lv_obj_set_size(ui->screen_menu_1_label_2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->screen_menu_1_label_2, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(screen_menu_1_subpage_2, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_1, ui->screen_menu_1_cont_2, screen_menu_1_subpage_2);

    //Create subpage for screen_menu_1
    lv_obj_t * screen_menu_1_subpage_3 = lv_menu_page_create(ui->screen_menu_1, NULL);
    ui->screen_menu_1_subpage_3_cont = lv_menu_cont_create(screen_menu_1_subpage_3);
    lv_obj_set_layout(ui->screen_menu_1_subpage_3_cont, LV_LAYOUT_NONE);
    ui->screen_menu_1_cont_3 = lv_menu_cont_create(ui->screen_menu_1_sidebar_page);
    ui->screen_menu_1_label_3 = lv_label_create(ui->screen_menu_1_cont_3);
    lv_label_set_text(ui->screen_menu_1_label_3, "Display");
    lv_obj_set_size(ui->screen_menu_1_label_3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->screen_menu_1_label_3, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(screen_menu_1_subpage_3, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->screen_menu_1, ui->screen_menu_1_cont_3, screen_menu_1_subpage_3);

    //Write style for screen_menu_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_menu_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_menu_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_menu_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_margin_hor(ui->screen_menu_1_sidebar_page, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_margin_ver(ui->screen_menu_1_sidebar_page, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_menu_1_sidebar_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_menu_1_sidebar_page, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_menu_1_sidebar_page, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_menu_1_sidebar_page, lv_color_hex(0xf6f6f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_menu_1_sidebar_page, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_menu_1_extra_option_btns_main_default
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

    //Write style state: LV_STATE_CHECKED for &style_screen_menu_1_extra_option_btns_main_checked
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

    //Write style state: LV_STATE_DEFAULT for &style_screen_menu_1_extra_main_title_main_default
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



    //Write codes screen_btn_1
    ui->screen_btn_1 = lv_button_create(ui->screen_menu_1_subpage_1_cont);
    lv_obj_set_pos(ui->screen_btn_1, 118, 202);
    lv_obj_set_size(ui->screen_btn_1, 100, 50);
    ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
    lv_label_set_text(ui->screen_btn_1_label, "Button");
    lv_label_set_long_mode(ui->screen_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_1_label, LV_PCT(100));

    //Write style for screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_led_1
    ui->screen_led_1 = lv_led_create(ui->screen_menu_1_subpage_1_cont);
    lv_obj_set_pos(ui->screen_led_1, 66, 86);
    lv_obj_set_size(ui->screen_led_1, 40, 40);
    lv_led_set_brightness(ui->screen_led_1, 255);
    lv_led_set_color(ui->screen_led_1, lv_color_hex(0x00a1b5));

    //Write codes screen_led_2
    ui->screen_led_2 = lv_led_create(ui->screen_menu_1_subpage_1_cont);
    lv_obj_set_pos(ui->screen_led_2, 232, 92);
    lv_obj_set_size(ui->screen_led_2, 40, 40);
    lv_led_set_brightness(ui->screen_led_2, 255);
    lv_led_set_color(ui->screen_led_2, lv_color_hex(0x00a1b5));



    //Write codes screen_digital_clock_1
    static bool screen_digital_clock_1_timer_enabled = false;
    ui->screen_digital_clock_1 = lv_label_create(ui->screen_menu_1_subpage_2_cont);
    lv_obj_set_pos(ui->screen_digital_clock_1, 101, 197);
    lv_obj_set_size(ui->screen_digital_clock_1, 130, 36);
    lv_label_set_text(ui->screen_digital_clock_1, "11:25:50");
    if (!screen_digital_clock_1_timer_enabled) {
        lv_timer_create(screen_digital_clock_1_timer, 1000, NULL);
        screen_digital_clock_1_timer_enabled = true;
    }

    //Write style for screen_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_digital_clock_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_digital_clock_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_datetext_1
    ui->screen_datetext_1 = lv_label_create(ui->screen_menu_1_subpage_2_cont);
    lv_obj_set_pos(ui->screen_datetext_1, 103, 106);
    lv_obj_set_size(ui->screen_datetext_1, 130, 36);
    lv_label_set_text(ui->screen_datetext_1, "2024/04/22");
    lv_obj_set_style_text_align(ui->screen_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->screen_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->screen_datetext_1, screen_datetext_1_event_handler, LV_EVENT_ALL, NULL);

    //Write style for screen_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_datetext_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_datetext_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
