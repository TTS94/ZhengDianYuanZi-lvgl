/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

static char phone_number[20];

static void menuDemo_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_spangroup_set_align(guider_ui.menuDemo_radio_spangroup, LV_TEXT_ALIGN_RIGHT);

        lv_obj_send_event(guider_ui.menuDemo_dashboard_menu_cont_1, LV_EVENT_CLICKED, NULL);
        break;
    }
    default:
        break;
    }
}

static void menuDemo_radio_slider_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int32_t slider_value = lv_slider_get_value(guider_ui.menuDemo_radio_slider);
        lv_span_t * fre_span = lv_spangroup_get_child(guider_ui.menuDemo_radio_spangroup, 0);
        float radio_value = ((float)slider_value * 0.8) + 73.6;

        char textbuffer[6];
        snprintf(textbuffer, sizeof(textbuffer), "%.1f", radio_value);
        lv_span_set_text(fre_span, textbuffer);

        switch (slider_value) {
        case (10):
        {
            lv_label_set_text(guider_ui.menuDemo_radio_label, "Rock Music Radio");
            break;
        }
        case (20):
        {
            lv_label_set_text(guider_ui.menuDemo_radio_label, "Rap Music Radio");
            break;
        }
        case (40):
        {
            lv_label_set_text(guider_ui.menuDemo_radio_label, "HipPop Music Radio");
            break;
        }
        case (60):
        {
            lv_label_set_text(guider_ui.menuDemo_radio_label, "R&B Music Radio");
            break;
        }
        case (80):
        {
            lv_label_set_text(guider_ui.menuDemo_radio_label, "Classic Music Radio");
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void menuDemo_phone_btnm_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        uint32_t id = lv_buttonmatrix_get_selected_button(obj);
        int len = lv_strlen(phone_number);
        if (len <= 10)
        {
            lv_strcat(phone_number, lv_buttonmatrix_get_button_text(guider_ui.menuDemo_phone_btnm, id));
            lv_label_set_text(guider_ui.menuDemo_phone_label, phone_number);
        }
        break;
    }
    default:
        break;
    }
}

static void menuDemo_imgbtn_call_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (lv_obj_has_state(guider_ui.menuDemo_imgbtn_call, LV_STATE_CHECKED)) {
            lv_obj_set_style_opa(guider_ui.menuDemo_phone_btnm, 0, 0);
            lv_obj_set_style_opa(guider_ui.menuDemo_btn_del, 0, 0);
            lv_obj_set_style_opa(guider_ui.menuDemo_phone_label, 0, 0);

            lv_label_set_text(guider_ui.menuDemo_phone_callnum, phone_number);
            lv_obj_remove_flag(guider_ui.menuDemo_phone_callnum, LV_OBJ_FLAG_HIDDEN);
            lv_obj_remove_flag(guider_ui.menuDemo_phone_calling, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_set_style_opa(guider_ui.menuDemo_phone_btnm, 255, 0);
            lv_obj_set_style_opa(guider_ui.menuDemo_btn_del, 255, 0);
            lv_obj_set_style_opa(guider_ui.menuDemo_phone_label, 255, 0);

            lv_obj_add_flag(guider_ui.menuDemo_phone_callnum, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.menuDemo_phone_calling, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    default:
        break;
    }
}

static void menuDemo_btn_del_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        int p_len = lv_strlen(phone_number);
        if (p_len > 0)
        {
            phone_number[p_len-1] = '\0';
            lv_label_set_text(guider_ui.menuDemo_phone_label, phone_number);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_menuDemo (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->menuDemo, menuDemo_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menuDemo_radio_slider, menuDemo_radio_slider_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menuDemo_phone_btnm, menuDemo_phone_btnm_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menuDemo_imgbtn_call, menuDemo_imgbtn_call_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menuDemo_btn_del, menuDemo_btn_del_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
