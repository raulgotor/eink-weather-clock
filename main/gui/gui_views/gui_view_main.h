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


/*
 *******************************************************************************
 * Public Data Types                                                           *
 *******************************************************************************
 */

typedef struct
{
        struct clock_s
        {
                lv_obj_t * label;

        } clock;


        struct info_bar_s
        {
                lv_obj_t * info_bar;

        } info_bar;

        struct weather_s
        {
                lv_obj_t * weather_icon;
                lv_obj_t * temperature_label;
                lv_obj_t * temperature_max_label;
                lv_obj_t * temperature_min_label;
                lv_obj_t * humidity_label;

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

#endif //GUI_VIEW_MAIN_H