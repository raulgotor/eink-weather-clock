/*!
 *******************************************************************************
 * @file gui_view_main.h
 *
 * @brief 
 *
 * @author Raúl Gotor (raul.gotor@midge-medical.com)
 * @date 24.10.22
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2022 Midge Medical GmbH
 * All rights reserved.
 *******************************************************************************
 */

#ifndef GUI_VIEW_MAIN_H
#define GUI_VIEW_MAIN_H

/*
 *******************************************************************************
 * Public Macros                                                               *
 *******************************************************************************
 */

LV_IMG_DECLARE(icon_00)
LV_IMG_DECLARE(icon_01)
LV_IMG_DECLARE(icon_02)
LV_IMG_DECLARE(icon_03)
LV_IMG_DECLARE(icon_04)
LV_IMG_DECLARE(icon_09)
LV_IMG_DECLARE(icon_10)
LV_IMG_DECLARE(icon_11)
LV_IMG_DECLARE(icon_13)
LV_IMG_DECLARE(icon_50)
LV_IMG_DECLARE(wait)


/*
 *******************************************************************************
 * Public Data Types                                                           *
 *******************************************************************************
 */

typedef struct
{
        struct clock_s
        {
                lv_obj_t * hr_label;
                lv_obj_t * min_label;
                lv_obj_t * sq;
                lv_obj_t * sq2;
                lv_obj_t * p_wait_icon;
                lv_obj_t * wait_label;

        } clock;


        struct info_bar_s
        {
                lv_obj_t * info_bar;

        } info_bar;

        struct weather_s
        {
                lv_obj_t * p_weather_icon;
                lv_obj_t * p_weather_label;
                lv_obj_t * p_temperature_label;
                lv_obj_t * p_temperature_max_label;
                lv_obj_t * p_temperature_min_label;
                lv_obj_t * p_humidity_label;
                lv_obj_t * p_pressure_label;

        } weather;


} gui_view_main_t;


/*
 *******************************************************************************
 * Public Constants                                                            *
 *******************************************************************************
 */


/*
 *******************************************************************************
 * Public Function Prototypes                                                  *
 *******************************************************************************
 */

void gui_view_main_init(void);

void gui_view_main_get_view(gui_view_main_t * p_main_view);

void gui_view_main_relayout(void);

void gui_view_enable_time(bool const enable);

#endif //GUI_VIEW_MAIN_H