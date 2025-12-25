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


void setup_scr_menuDemo(lv_ui *ui)
{
    //Write codes menuDemo
    ui->menuDemo = lv_obj_create(NULL);
    lv_obj_set_size(ui->menuDemo, 480, 272);
    lv_obj_set_scrollbar_mode(ui->menuDemo, LV_SCROLLBAR_MODE_OFF);

    //Write style for menuDemo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_dashboard_menu
    ui->menuDemo_dashboard_menu = lv_menu_create(ui->menuDemo);
    lv_obj_set_pos(ui->menuDemo_dashboard_menu, -1, 0);
    lv_obj_set_size(ui->menuDemo_dashboard_menu, 480, 320);
    lv_obj_set_scrollbar_mode(ui->menuDemo_dashboard_menu, LV_SCROLLBAR_MODE_OFF);

    //Create sidebar page for menu menuDemo_dashboard_menu
    ui->menuDemo_dashboard_menu_sidebar_page = lv_menu_page_create(ui->menuDemo_dashboard_menu, "Dashboard");
    lv_menu_set_sidebar_page(ui->menuDemo_dashboard_menu, ui->menuDemo_dashboard_menu_sidebar_page);
    lv_obj_set_scrollbar_mode(ui->menuDemo_dashboard_menu_sidebar_page, LV_SCROLLBAR_MODE_OFF);

    //Create subpage for menuDemo_dashboard_menu
    lv_obj_t * menuDemo_dashboard_menu_subpage_1 = lv_menu_page_create(ui->menuDemo_dashboard_menu, NULL);
    ui->menuDemo_dashboard_menu_subpage_1_cont = lv_menu_cont_create(menuDemo_dashboard_menu_subpage_1);
    lv_obj_set_layout(ui->menuDemo_dashboard_menu_subpage_1_cont, LV_LAYOUT_NONE);
    ui->menuDemo_dashboard_menu_cont_1 = lv_menu_cont_create(ui->menuDemo_dashboard_menu_sidebar_page);
    ui->menuDemo_dashboard_menu_label_1 = lv_label_create(ui->menuDemo_dashboard_menu_cont_1);
    lv_label_set_text(ui->menuDemo_dashboard_menu_label_1, "Battery");
    lv_obj_set_size(ui->menuDemo_dashboard_menu_label_1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->menuDemo_dashboard_menu_label_1, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(menuDemo_dashboard_menu_subpage_1, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->menuDemo_dashboard_menu, ui->menuDemo_dashboard_menu_cont_1, menuDemo_dashboard_menu_subpage_1);

    //Create subpage for menuDemo_dashboard_menu
    lv_obj_t * menuDemo_dashboard_menu_subpage_2 = lv_menu_page_create(ui->menuDemo_dashboard_menu, NULL);
    ui->menuDemo_dashboard_menu_subpage_2_cont = lv_menu_cont_create(menuDemo_dashboard_menu_subpage_2);
    lv_obj_set_layout(ui->menuDemo_dashboard_menu_subpage_2_cont, LV_LAYOUT_NONE);
    ui->menuDemo_dashboard_menu_cont_2 = lv_menu_cont_create(ui->menuDemo_dashboard_menu_sidebar_page);
    ui->menuDemo_dashboard_menu_label_2 = lv_label_create(ui->menuDemo_dashboard_menu_cont_2);
    lv_label_set_text(ui->menuDemo_dashboard_menu_label_2, "Radio");
    lv_obj_set_size(ui->menuDemo_dashboard_menu_label_2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->menuDemo_dashboard_menu_label_2, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(menuDemo_dashboard_menu_subpage_2, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->menuDemo_dashboard_menu, ui->menuDemo_dashboard_menu_cont_2, menuDemo_dashboard_menu_subpage_2);

    //Create subpage for menuDemo_dashboard_menu
    lv_obj_t * menuDemo_dashboard_menu_subpage_3 = lv_menu_page_create(ui->menuDemo_dashboard_menu, NULL);
    ui->menuDemo_dashboard_menu_subpage_3_cont = lv_menu_cont_create(menuDemo_dashboard_menu_subpage_3);
    lv_obj_set_layout(ui->menuDemo_dashboard_menu_subpage_3_cont, LV_LAYOUT_NONE);
    ui->menuDemo_dashboard_menu_cont_3 = lv_menu_cont_create(ui->menuDemo_dashboard_menu_sidebar_page);
    ui->menuDemo_dashboard_menu_label_3 = lv_label_create(ui->menuDemo_dashboard_menu_cont_3);
    lv_label_set_text(ui->menuDemo_dashboard_menu_label_3, "Phone");
    lv_obj_set_size(ui->menuDemo_dashboard_menu_label_3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->menuDemo_dashboard_menu_label_3, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(menuDemo_dashboard_menu_subpage_3, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->menuDemo_dashboard_menu, ui->menuDemo_dashboard_menu_cont_3, menuDemo_dashboard_menu_subpage_3);

    //Create subpage for menuDemo_dashboard_menu
    lv_obj_t * menuDemo_dashboard_menu_subpage_4 = lv_menu_page_create(ui->menuDemo_dashboard_menu, NULL);
    ui->menuDemo_dashboard_menu_subpage_4_cont = lv_menu_cont_create(menuDemo_dashboard_menu_subpage_4);
    lv_obj_set_layout(ui->menuDemo_dashboard_menu_subpage_4_cont, LV_LAYOUT_NONE);
    ui->menuDemo_dashboard_menu_cont_4 = lv_menu_cont_create(ui->menuDemo_dashboard_menu_sidebar_page);
    ui->menuDemo_dashboard_menu_label_4 = lv_label_create(ui->menuDemo_dashboard_menu_cont_4);
    lv_label_set_text(ui->menuDemo_dashboard_menu_label_4, "A/C");
    lv_obj_set_size(ui->menuDemo_dashboard_menu_label_4, LV_PCT(100), LV_SIZE_CONTENT);
    lv_label_set_long_mode(ui->menuDemo_dashboard_menu_label_4, LV_LABEL_LONG_CLIP);
    lv_obj_set_scrollbar_mode(menuDemo_dashboard_menu_subpage_4, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->menuDemo_dashboard_menu, ui->menuDemo_dashboard_menu_cont_4, menuDemo_dashboard_menu_subpage_4);

    //Write style for menuDemo_dashboard_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_dashboard_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menuDemo_dashboard_menu, lv_color_hex(0x082142), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menuDemo_dashboard_menu, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->menuDemo_dashboard_menu, lv_color_hex(0x3d516b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->menuDemo_dashboard_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->menuDemo_dashboard_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_dashboard_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_dashboard_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menuDemo_dashboard_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_margin_ver(ui->menuDemo_dashboard_menu_sidebar_page, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menuDemo_dashboard_menu_sidebar_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_dashboard_menu_sidebar_page, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_dashboard_menu_sidebar_page, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_menuDemo_dashboard_menu_extra_option_btns_main_default
    static lv_style_t style_menuDemo_dashboard_menu_extra_option_btns_main_default;
    ui_init_style(&style_menuDemo_dashboard_menu_extra_option_btns_main_default);

    lv_style_set_text_color(&style_menuDemo_dashboard_menu_extra_option_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_menuDemo_dashboard_menu_extra_option_btns_main_default, &lv_font_montserratMedium_16);
    lv_style_set_text_opa(&style_menuDemo_dashboard_menu_extra_option_btns_main_default, 255);
    lv_style_set_text_align(&style_menuDemo_dashboard_menu_extra_option_btns_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_top(&style_menuDemo_dashboard_menu_extra_option_btns_main_default, 10);
    lv_style_set_pad_bottom(&style_menuDemo_dashboard_menu_extra_option_btns_main_default, 10);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_4, &style_menuDemo_dashboard_menu_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_3, &style_menuDemo_dashboard_menu_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_2, &style_menuDemo_dashboard_menu_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_1, &style_menuDemo_dashboard_menu_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_menuDemo_dashboard_menu_extra_option_btns_main_checked
    static lv_style_t style_menuDemo_dashboard_menu_extra_option_btns_main_checked;
    ui_init_style(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked);

    lv_style_set_text_color(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, lv_color_hex(0xa5efff));
    lv_style_set_text_font(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, &lv_font_montserratMedium_16);
    lv_style_set_text_opa(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, 255);
    lv_style_set_text_align(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, LV_TEXT_ALIGN_CENTER);
    lv_style_set_border_width(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, 0);
    lv_style_set_radius(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, 5);
    lv_style_set_bg_opa(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, 60);
    lv_style_set_bg_color(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, lv_color_hex(0x19a5ff));
    lv_style_set_bg_grad_dir(&style_menuDemo_dashboard_menu_extra_option_btns_main_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_4, &style_menuDemo_dashboard_menu_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_3, &style_menuDemo_dashboard_menu_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_2, &style_menuDemo_dashboard_menu_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->menuDemo_dashboard_menu_cont_1, &style_menuDemo_dashboard_menu_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_menuDemo_dashboard_menu_extra_main_title_main_default
    static lv_style_t style_menuDemo_dashboard_menu_extra_main_title_main_default;
    ui_init_style(&style_menuDemo_dashboard_menu_extra_main_title_main_default);

    lv_style_set_text_color(&style_menuDemo_dashboard_menu_extra_main_title_main_default, lv_color_hex(0x6a94b6));
    lv_style_set_text_font(&style_menuDemo_dashboard_menu_extra_main_title_main_default, &lv_font_montserratMedium_18);
    lv_style_set_text_opa(&style_menuDemo_dashboard_menu_extra_main_title_main_default, 255);
    lv_style_set_text_align(&style_menuDemo_dashboard_menu_extra_main_title_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_opa(&style_menuDemo_dashboard_menu_extra_main_title_main_default, 0);
    lv_style_set_pad_hor(&style_menuDemo_dashboard_menu_extra_main_title_main_default, 5);
    lv_style_set_pad_ver(&style_menuDemo_dashboard_menu_extra_main_title_main_default, 10);
    lv_menu_t * menuDemo_dashboard_menu_menu= (lv_menu_t *)ui->menuDemo_dashboard_menu;
    lv_obj_t * menuDemo_dashboard_menu_title = menuDemo_dashboard_menu_menu->sidebar_header_title;
    lv_obj_set_size(menuDemo_dashboard_menu_title, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(lv_menu_get_sidebar_header(ui->menuDemo_dashboard_menu), &style_menuDemo_dashboard_menu_extra_main_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes menuDemo_battery_label
    ui->menuDemo_battery_label = lv_label_create(ui->menuDemo_dashboard_menu_subpage_1_cont);
    lv_obj_set_pos(ui->menuDemo_battery_label, 40, 22);
    lv_obj_set_size(ui->menuDemo_battery_label, 279, 49);
    lv_label_set_text(ui->menuDemo_battery_label, "The Battery Condition");
    lv_label_set_long_mode(ui->menuDemo_battery_label, LV_LABEL_LONG_WRAP);

    //Write style for menuDemo_battery_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_battery_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_battery_label, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_battery_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menuDemo_battery_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_battery_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_battery_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_battery_img
    ui->menuDemo_battery_img = lv_image_create(ui->menuDemo_dashboard_menu_subpage_1_cont);
    lv_obj_set_pos(ui->menuDemo_battery_img, 66, 82);
    lv_obj_set_size(ui->menuDemo_battery_img, 200, 74);
    lv_obj_add_flag(ui->menuDemo_battery_img, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->menuDemo_battery_img, &_battery_RGB565A8_200x74);
    lv_image_set_pivot(ui->menuDemo_battery_img, 50,50);
    lv_image_set_rotation(ui->menuDemo_battery_img, 0);

    //Write style for menuDemo_battery_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_battery_img, 145, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->menuDemo_battery_img, lv_color_hex(0x38fe49), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->menuDemo_battery_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_battery_spangroup
    ui->menuDemo_battery_spangroup = lv_spangroup_create(ui->menuDemo_dashboard_menu_subpage_1_cont);
    lv_obj_set_pos(ui->menuDemo_battery_spangroup, 58, 175);
    lv_obj_set_size(ui->menuDemo_battery_spangroup, 237, 65);
    lv_spangroup_set_align(ui->menuDemo_battery_spangroup, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->menuDemo_battery_spangroup, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->menuDemo_battery_spangroup, LV_SPAN_MODE_BREAK);
    //create span
    ui->menuDemo_battery_spangroup_span = lv_spangroup_new_span(ui->menuDemo_battery_spangroup);
    lv_span_set_text(ui->menuDemo_battery_spangroup_span, "Distance :    ");
    lv_style_set_text_color(lv_span_get_style(ui->menuDemo_battery_spangroup_span), lv_color_hex(0xffffff));
    lv_style_set_text_decor(lv_span_get_style(ui->menuDemo_battery_spangroup_span), LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(lv_span_get_style(ui->menuDemo_battery_spangroup_span), &lv_font_Alatsi_Regular_20);
    ui->menuDemo_battery_spangroup_span = lv_spangroup_new_span(ui->menuDemo_battery_spangroup);
    lv_span_set_text(ui->menuDemo_battery_spangroup_span, "267");
    lv_style_set_text_color(lv_span_get_style(ui->menuDemo_battery_spangroup_span), lv_color_hex(0x5dfd44));
    lv_style_set_text_decor(lv_span_get_style(ui->menuDemo_battery_spangroup_span), LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(lv_span_get_style(ui->menuDemo_battery_spangroup_span), &lv_font_Alatsi_Regular_45);
    ui->menuDemo_battery_spangroup_span = lv_spangroup_new_span(ui->menuDemo_battery_spangroup);
    lv_span_set_text(ui->menuDemo_battery_spangroup_span, "  Km");
    lv_style_set_text_color(lv_span_get_style(ui->menuDemo_battery_spangroup_span), lv_color_hex(0xffffff));
    lv_style_set_text_decor(lv_span_get_style(ui->menuDemo_battery_spangroup_span), LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(lv_span_get_style(ui->menuDemo_battery_spangroup_span), &lv_font_Alatsi_Regular_20);

    //Write style state: LV_STATE_DEFAULT for &style_menuDemo_battery_spangroup_main_main_default
    static lv_style_t style_menuDemo_battery_spangroup_main_main_default;
    ui_init_style(&style_menuDemo_battery_spangroup_main_main_default);

    lv_style_set_border_width(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_radius(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_bg_opa(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_pad_top(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_pad_right(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_pad_bottom(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_pad_left(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_style_set_shadow_width(&style_menuDemo_battery_spangroup_main_main_default, 0);
    lv_obj_add_style(ui->menuDemo_battery_spangroup, &style_menuDemo_battery_spangroup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->menuDemo_battery_spangroup);



    //Write codes menuDemo_radio_slider
    ui->menuDemo_radio_slider = lv_slider_create(ui->menuDemo_dashboard_menu_subpage_2_cont);
    lv_obj_set_pos(ui->menuDemo_radio_slider, 16, 149);
    lv_obj_set_size(ui->menuDemo_radio_slider, 300, 81);
    lv_slider_set_range(ui->menuDemo_radio_slider, 0, 90);
    lv_slider_set_mode(ui->menuDemo_radio_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->menuDemo_radio_slider, 40, LV_ANIM_OFF);

    //Write style for menuDemo_radio_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_radio_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_radio_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->menuDemo_radio_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->menuDemo_radio_slider, &_radio_bg_RGB565A8_300x81, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->menuDemo_radio_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->menuDemo_radio_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_radio_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menuDemo_radio_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_radio_slider, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_radio_slider, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for menuDemo_radio_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_radio_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->menuDemo_radio_slider, &_radio_play_RGB565A8_91x91, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->menuDemo_radio_slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->menuDemo_radio_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_radio_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes menuDemo_radio_spangroup
    ui->menuDemo_radio_spangroup = lv_spangroup_create(ui->menuDemo_dashboard_menu_subpage_2_cont);
    lv_obj_set_pos(ui->menuDemo_radio_spangroup, 93, 38);
    lv_obj_set_size(ui->menuDemo_radio_spangroup, 135, 53);
    lv_spangroup_set_align(ui->menuDemo_radio_spangroup, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->menuDemo_radio_spangroup, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->menuDemo_radio_spangroup, LV_SPAN_MODE_BREAK);
    //create span
    ui->menuDemo_radio_spangroup_span = lv_spangroup_new_span(ui->menuDemo_radio_spangroup);
    lv_span_set_text(ui->menuDemo_radio_spangroup_span, "104.0");
    lv_style_set_text_color(lv_span_get_style(ui->menuDemo_radio_spangroup_span), lv_color_hex(0xffffff));
    lv_style_set_text_decor(lv_span_get_style(ui->menuDemo_radio_spangroup_span), LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(lv_span_get_style(ui->menuDemo_radio_spangroup_span), &lv_font_Alatsi_Regular_40);
    ui->menuDemo_radio_spangroup_span = lv_spangroup_new_span(ui->menuDemo_radio_spangroup);
    lv_span_set_text(ui->menuDemo_radio_spangroup_span, "MHz");
    lv_style_set_text_color(lv_span_get_style(ui->menuDemo_radio_spangroup_span), lv_color_hex(0xbbbbbb));
    lv_style_set_text_decor(lv_span_get_style(ui->menuDemo_radio_spangroup_span), LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(lv_span_get_style(ui->menuDemo_radio_spangroup_span), &lv_font_montserratMedium_12);

    //Write style state: LV_STATE_DEFAULT for &style_menuDemo_radio_spangroup_main_main_default
    static lv_style_t style_menuDemo_radio_spangroup_main_main_default;
    ui_init_style(&style_menuDemo_radio_spangroup_main_main_default);

    lv_style_set_border_width(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_radius(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_bg_opa(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_pad_top(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_pad_right(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_pad_bottom(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_pad_left(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_style_set_shadow_width(&style_menuDemo_radio_spangroup_main_main_default, 0);
    lv_obj_add_style(ui->menuDemo_radio_spangroup, &style_menuDemo_radio_spangroup_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->menuDemo_radio_spangroup);

    //Write codes menuDemo_radio_label
    ui->menuDemo_radio_label = lv_label_create(ui->menuDemo_dashboard_menu_subpage_2_cont);
    lv_obj_set_pos(ui->menuDemo_radio_label, 62, 100);
    lv_obj_set_size(ui->menuDemo_radio_label, 182, 32);
    lv_label_set_text(ui->menuDemo_radio_label, "HipPop Music Radio");
    lv_label_set_long_mode(ui->menuDemo_radio_label, LV_LABEL_LONG_WRAP);

    //Write style for menuDemo_radio_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_radio_label, lv_color_hex(0xb8b8b8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_radio_label, &lv_font_Alatsi_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_radio_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_radio_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes menuDemo_phone_label
    ui->menuDemo_phone_label = lv_label_create(ui->menuDemo_dashboard_menu_subpage_3_cont);
    lv_obj_set_pos(ui->menuDemo_phone_label, 49, 14);
    lv_obj_set_size(ui->menuDemo_phone_label, 233, 30);
    lv_label_set_text(ui->menuDemo_phone_label, "");
    lv_label_set_long_mode(ui->menuDemo_phone_label, LV_LABEL_LONG_WRAP);

    //Write style for menuDemo_phone_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_phone_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_phone_label, &lv_font_Alatsi_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_phone_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_phone_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_phone_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_phone_btnm
    ui->menuDemo_phone_btnm = lv_buttonmatrix_create(ui->menuDemo_dashboard_menu_subpage_3_cont);
    lv_obj_set_pos(ui->menuDemo_phone_btnm, 85, 43);
    lv_obj_set_size(ui->menuDemo_phone_btnm, 164, 175);
    static const char *menuDemo_phone_btnm_text_map[] = {"1", "2", "3", "\n", "4", "5", "6", "\n", "7", "8", "9", "\n", "*", "0", "#", "",};
    lv_buttonmatrix_set_map(ui->menuDemo_phone_btnm, menuDemo_phone_btnm_text_map);

    //Write style for menuDemo_phone_btnm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_phone_btnm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_phone_btnm, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_phone_btnm, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_phone_btnm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_phone_btnm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui->menuDemo_phone_btnm, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui->menuDemo_phone_btnm, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_phone_btnm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_phone_btnm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menuDemo_phone_btnm, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_phone_btnm, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_phone_btnm, lv_color_hex(0x9a9a9a), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_phone_btnm, &lv_font_montserratMedium_18, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_phone_btnm, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_phone_btnm, 34, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_phone_btnm, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menuDemo_phone_btnm, lv_color_hex(0x0e2537), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menuDemo_phone_btnm, LV_GRAD_DIR_HOR, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->menuDemo_phone_btnm, lv_color_hex(0x52687b), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->menuDemo_phone_btnm, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->menuDemo_phone_btnm, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_phone_btnm, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes menuDemo_imgbtn_call
    ui->menuDemo_imgbtn_call = lv_imagebutton_create(ui->menuDemo_dashboard_menu_subpage_3_cont);
    lv_obj_set_pos(ui->menuDemo_imgbtn_call, 149, 216);
    lv_obj_set_size(ui->menuDemo_imgbtn_call, 37, 36);
    lv_obj_add_flag(ui->menuDemo_imgbtn_call, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->menuDemo_imgbtn_call, LV_IMAGEBUTTON_STATE_RELEASED, &_phone_card_RGB565A8_37x36, NULL, NULL);
    lv_imagebutton_set_src(ui->menuDemo_imgbtn_call, LV_IMAGEBUTTON_STATE_PRESSED, &_phone_card_RGB565A8_37x36, NULL, NULL);
    lv_imagebutton_set_src(ui->menuDemo_imgbtn_call, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_end_call_RGB565A8_37x36, NULL, NULL);
    lv_imagebutton_set_src(ui->menuDemo_imgbtn_call, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_end_call_RGB565A8_37x36, NULL, NULL);
    ui->menuDemo_imgbtn_call_label = lv_label_create(ui->menuDemo_imgbtn_call);
    lv_label_set_text(ui->menuDemo_imgbtn_call_label, "");
    lv_label_set_long_mode(ui->menuDemo_imgbtn_call_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menuDemo_imgbtn_call_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menuDemo_imgbtn_call, 0, LV_STATE_DEFAULT);

    //Write style for menuDemo_imgbtn_call, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->menuDemo_imgbtn_call, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_imgbtn_call, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_imgbtn_call, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_imgbtn_call, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_imgbtn_call, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menuDemo_imgbtn_call, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_imgbtn_call, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->menuDemo_imgbtn_call, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->menuDemo_imgbtn_call, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->menuDemo_imgbtn_call, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->menuDemo_imgbtn_call, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->menuDemo_imgbtn_call, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for menuDemo_imgbtn_call, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_imgbtn_call, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->menuDemo_imgbtn_call, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->menuDemo_imgbtn_call, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->menuDemo_imgbtn_call, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->menuDemo_imgbtn_call, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->menuDemo_imgbtn_call, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for menuDemo_imgbtn_call, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_imgbtn_call, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->menuDemo_imgbtn_call, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes menuDemo_btn_del
    ui->menuDemo_btn_del = lv_button_create(ui->menuDemo_dashboard_menu_subpage_3_cont);
    lv_obj_set_pos(ui->menuDemo_btn_del, 261, 13);
    lv_obj_set_size(ui->menuDemo_btn_del, 28, 26);
    ui->menuDemo_btn_del_label = lv_label_create(ui->menuDemo_btn_del);
    lv_label_set_text(ui->menuDemo_btn_del_label, "");
    lv_label_set_long_mode(ui->menuDemo_btn_del_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menuDemo_btn_del_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menuDemo_btn_del, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menuDemo_btn_del_label, LV_PCT(100));

    //Write style for menuDemo_btn_del, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_btn_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menuDemo_btn_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_btn_del, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_btn_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->menuDemo_btn_del, &_delete_RGB565A8_28x26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->menuDemo_btn_del, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->menuDemo_btn_del, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->menuDemo_btn_del, 166, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_btn_del, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_btn_del, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_btn_del, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_btn_del, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_phone_calling
    ui->menuDemo_phone_calling = lv_label_create(ui->menuDemo_dashboard_menu_subpage_3_cont);
    lv_obj_set_pos(ui->menuDemo_phone_calling, 94, 120);
    lv_obj_set_size(ui->menuDemo_phone_calling, 148, 33);
    lv_obj_add_flag(ui->menuDemo_phone_calling, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui->menuDemo_phone_calling, "Calling...");
    lv_label_set_long_mode(ui->menuDemo_phone_calling, LV_LABEL_LONG_WRAP);

    //Write style for menuDemo_phone_calling, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_phone_calling, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_phone_calling, &lv_font_Alatsi_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_phone_calling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menuDemo_phone_calling, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_phone_calling, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_phone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_phone_callnum
    ui->menuDemo_phone_callnum = lv_label_create(ui->menuDemo_dashboard_menu_subpage_3_cont);
    lv_obj_set_pos(ui->menuDemo_phone_callnum, 47, 62);
    lv_obj_set_size(ui->menuDemo_phone_callnum, 244, 41);
    lv_obj_add_flag(ui->menuDemo_phone_callnum, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui->menuDemo_phone_callnum, "");
    lv_label_set_long_mode(ui->menuDemo_phone_callnum, LV_LABEL_LONG_WRAP);

    //Write style for menuDemo_phone_callnum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_phone_callnum, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_phone_callnum, &lv_font_Alatsi_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_phone_callnum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_phone_callnum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_phone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes menuDemo_tileview_1
    ui->menuDemo_tileview_1 = lv_tileview_create(ui->menuDemo_dashboard_menu_subpage_4_cont);
    lv_obj_set_pos(ui->menuDemo_tileview_1, 39, 88);
    lv_obj_set_size(ui->menuDemo_tileview_1, 260, 140);
    lv_obj_set_scrollbar_mode(ui->menuDemo_tileview_1, LV_SCROLLBAR_MODE_OFF);
    ui->menuDemo_tileview_1_tile = lv_tileview_add_tile(ui->menuDemo_tileview_1, 0, 0, LV_DIR_RIGHT);
    ui->menuDemo_tileview_1_tile_1 = lv_tileview_add_tile(ui->menuDemo_tileview_1, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->menuDemo_tileview_1_tile_2 = lv_tileview_add_tile(ui->menuDemo_tileview_1, 2, 0, LV_DIR_LEFT);

    //Write style for menuDemo_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_tileview_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_tileview_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->menuDemo_tileview_1, lv_color_hex(0x9da5ab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->menuDemo_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->menuDemo_tileview_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->menuDemo_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->menuDemo_tileview_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for menuDemo_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menuDemo_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes menuDemo_img_mode_1
    ui->menuDemo_img_mode_1 = lv_image_create(ui->menuDemo_tileview_1_tile);
    lv_obj_set_pos(ui->menuDemo_img_mode_1, 80, 20);
    lv_obj_set_size(ui->menuDemo_img_mode_1, 100, 100);
    lv_obj_add_flag(ui->menuDemo_img_mode_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->menuDemo_img_mode_1, &_mode1_RGB565A8_100x100);
    lv_image_set_pivot(ui->menuDemo_img_mode_1, 50,50);
    lv_image_set_rotation(ui->menuDemo_img_mode_1, 0);

    //Write style for menuDemo_img_mode_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_img_mode_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->menuDemo_img_mode_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes menuDemo_img_mode_2
    ui->menuDemo_img_mode_2 = lv_image_create(ui->menuDemo_tileview_1_tile_1);
    lv_obj_set_pos(ui->menuDemo_img_mode_2, 80, 20);
    lv_obj_set_size(ui->menuDemo_img_mode_2, 100, 100);
    lv_obj_add_flag(ui->menuDemo_img_mode_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->menuDemo_img_mode_2, &_mode2_RGB565A8_100x100);
    lv_image_set_pivot(ui->menuDemo_img_mode_2, 50,50);
    lv_image_set_rotation(ui->menuDemo_img_mode_2, 0);

    //Write style for menuDemo_img_mode_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_img_mode_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->menuDemo_img_mode_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes menuDemo_img_mode_3
    ui->menuDemo_img_mode_3 = lv_image_create(ui->menuDemo_tileview_1_tile_2);
    lv_obj_set_pos(ui->menuDemo_img_mode_3, 80, 20);
    lv_obj_set_size(ui->menuDemo_img_mode_3, 100, 100);
    lv_obj_add_flag(ui->menuDemo_img_mode_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->menuDemo_img_mode_3, &_mode3_RGB565A8_100x100);
    lv_image_set_pivot(ui->menuDemo_img_mode_3, 50,50);
    lv_image_set_rotation(ui->menuDemo_img_mode_3, 0);

    //Write style for menuDemo_img_mode_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->menuDemo_img_mode_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->menuDemo_img_mode_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menuDemo_conditioner_label
    ui->menuDemo_conditioner_label = lv_label_create(ui->menuDemo_dashboard_menu_subpage_4_cont);
    lv_obj_set_pos(ui->menuDemo_conditioner_label, 19, 26);
    lv_obj_set_size(ui->menuDemo_conditioner_label, 293, 45);
    lv_label_set_text(ui->menuDemo_conditioner_label, "Conditioner Mode");
    lv_label_set_long_mode(ui->menuDemo_conditioner_label, LV_LABEL_LONG_WRAP);

    //Write style for menuDemo_conditioner_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menuDemo_conditioner_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menuDemo_conditioner_label, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menuDemo_conditioner_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menuDemo_conditioner_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menuDemo_conditioner_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menuDemo_conditioner_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of menuDemo.


    //Update current screen layout.
    lv_obj_update_layout(ui->menuDemo);

    //Init events for screen.
    events_init_menuDemo(ui);
}
