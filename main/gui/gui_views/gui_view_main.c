/*!
 *******************************************************************************
 * @file gui_view_main.c
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

/*
 *******************************************************************************
 * #include Statements                                                         *
 *******************************************************************************
 */

#include "lvgl/lvgl.h"
#include "gui_view_main.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */

LV_FONT_DECLARE(flipclock_110);


/*
 *******************************************************************************
 * Data types                                                                  *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Constants                                                                   *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Private Function Prototypes                                                 *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Public Data Declarations                                                    *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Static Data Declarations                                                    *
 *******************************************************************************
 */

static gui_view_main_t m_main_view;
static lv_style_t m_style_line;


/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

void gui_view_main_init(void)
{
        lv_style_init(&m_style_line);
        lv_style_set_line_width(&m_style_line, 1);
        lv_style_set_line_color(&m_style_line, lv_color_black());
        lv_style_set_line_rounded(&m_style_line, true);
        lv_style_set_text_font(&m_style_line, &flipclock_110);

        m_main_view.clock.label = lv_label_create(lv_scr_act());
        lv_obj_set_align(m_main_view.clock.label, LV_ALIGN_CENTER);
/*
        m_main_view.weather.weather_icon = lv_img_create(lv_scr_act());
        m_main_view.weather.humidity_label = lv_label_create(lv_scr_act());
        m_main_view.weather.temperature_label = lv_label_create(lv_scr_act());
        m_main_view.weather.temperature_max_label = lv_label_create(lv_scr_act());
        m_main_view.weather.temperature_min_label = lv_label_create(lv_scr_act());


        lv_obj_align_to(m_main_view.weather.temperature_max_label,
                        m_main_view.weather.temperature_min_label,
                        LV_ALIGN_OUT_RIGHT_MID, 0, 0);

        lv_obj_align_to(m_main_view.weather.temperature_label,
                        m_main_view.weather.humidity_label,
                        LV_ALIGN_OUT_LEFT_MID, 0, 0);

        lv_obj_align_to(m_main_view.weather.humidity_label,
                        m_main_view.weather.weather_icon,
                        LV_ALIGN_OUT_TOP_MID, 0, 0);

        lv_obj_align_to(m_main_view.weather.temperature_min_label,
                        m_main_view.weather.weather_icon,
                        LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

        lv_obj_align(m_main_view.weather.weather_icon, LV_ALIGN_CENTER, 0, 0);
        lv_obj_align(m_main_view.weather.temperature_label, LV_ALIGN_CENTER, 100, 0);
        lv_obj_align(m_main_view.weather.humidity_label, LV_ALIGN_CENTER, -100, 0);

        lv_label_set_text(m_main_view.weather.temperature_min_label, "15C");
        lv_label_set_text(m_main_view.weather.temperature_max_label, "24C");
        lv_label_set_text(m_main_view.weather.temperature_label, "20C");
        lv_label_set_text(m_main_view.weather.humidity_label, "55C");
*/
        lv_obj_add_style(m_main_view.clock.label, &m_style_line, 0);

}

void gui_view_main_get_view(gui_view_main_t * p_main_view) {
        *p_main_view = m_main_view;
}

/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */
