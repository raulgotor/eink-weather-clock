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
LV_FONT_DECLARE(flipclock_48);
LV_FONT_DECLARE(flipclock_24);
LV_FONT_DECLARE(atariST_16);

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
static lv_style_t m_clock_style;
static lv_style_t m_temperature_style;
static lv_style_t m_clock_dot_style;
static lv_style_t m_small_style;
static lv_style_t m_icon_style;

static bool m_time_is_enabled = false;

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

void gui_view_main_init(void)
{
        lv_style_init(&m_clock_style);
        lv_style_set_line_width(&m_clock_style, 1);
        lv_style_set_line_color(&m_clock_style, lv_color_black());
        lv_style_set_line_rounded(&m_clock_style, true);
        lv_style_set_text_font(&m_clock_style, &flipclock_110);
        lv_style_set_border_color(&m_clock_style, lv_color_black());

        lv_style_init(&m_temperature_style);
        lv_style_set_line_width(&m_temperature_style, 1);
        lv_style_set_line_color(&m_temperature_style, lv_color_black());
        lv_style_set_line_rounded(&m_temperature_style, true);
        lv_style_set_text_font(&m_temperature_style, &flipclock_24);

#if defined(GUI_VIEW_BORDERS_DEBUG) && (0 != GUI_VIEW_BORDERS_DEBUG)
        lv_style_set_border_color(&m_temperature_style, lv_color_black());
        lv_style_set_bg_opa(&m_temperature_style, LV_OPA_0);
        lv_style_set_border_width(&m_temperature_style, 1);
#endif // defined(GUI_VIEW_BORDERS_DEBUG)

        lv_style_init(&m_clock_dot_style);
        lv_style_set_line_rounded(&m_clock_dot_style, false);
        lv_style_set_radius(&m_clock_dot_style, 0);
        lv_style_set_border_color(&m_clock_dot_style, lv_color_black());
        lv_style_set_bg_color(&m_clock_dot_style, lv_color_black());
        lv_style_set_border_width(&m_clock_dot_style, 1);

        lv_style_init(&m_small_style);
        lv_style_set_line_width(&m_small_style, 1);
        lv_style_set_line_color(&m_small_style, lv_color_black());
        lv_style_set_line_rounded(&m_small_style, true);
        lv_style_set_text_font(&m_small_style, &atariST_16);

        lv_style_init(&m_icon_style);
        lv_style_set_line_width(&m_icon_style, 1);
        lv_style_set_border_color(&m_icon_style, lv_color_black());
        lv_style_set_line_rounded(&m_icon_style, true);
        lv_style_set_text_font(&m_icon_style, &atariST_16);

        m_main_view.clock.hr_label = lv_label_create(lv_scr_act());
        m_main_view.clock.min_label = lv_label_create(lv_scr_act());
        m_main_view.weather.p_weather_icon = lv_img_create(lv_scr_act());
        m_main_view.weather.p_weather_label = lv_label_create(lv_scr_act());
        m_main_view.weather.p_humidity_label = lv_label_create(lv_scr_act());
        m_main_view.weather.p_pressure_label = lv_label_create(lv_scr_act());
        m_main_view.weather.p_temperature_label = lv_label_create(lv_scr_act());
        m_main_view.clock.sq = lv_obj_create(lv_scr_act());
        m_main_view.clock.sq2 = lv_obj_create(lv_scr_act());

#if defined(GUI_VIEW_MAX_TEMP) && (0 != GUI_VIEW_MAX_TEMP)
        m_main_view.weather.p_temperature_max_label = lv_label_create(lv_scr_act());
        m_main_view.weather.p_temperature_min_label = lv_label_create(lv_scr_act());
#endif

        lv_obj_add_style(m_main_view.clock.hr_label, &m_clock_style, 0);
        lv_obj_add_style(m_main_view.clock.min_label, &m_clock_style, 0);
        lv_obj_add_style(m_main_view.weather.p_weather_icon, &m_clock_style, 0);
        lv_obj_add_style(m_main_view.weather.p_weather_label, &m_small_style, 0);
        lv_obj_add_style(m_main_view.weather.p_humidity_label, &m_small_style, 0);
        lv_obj_add_style(m_main_view.weather.p_pressure_label, &m_small_style, 0);

#if defined(GUI_VIEW_MAX_TEMP) && (0 != GUI_VIEW_MAX_TEMP)
        lv_obj_add_style(m_main_view.weather.p_temperature_min_label, &m_small_style, 0);
        lv_obj_add_style(m_main_view.weather.p_temperature_max_label, &m_small_style, 0);
#endif
        lv_obj_add_style(m_main_view.weather.p_temperature_label, &m_temperature_style, 0);

        lv_label_set_text(m_main_view.clock.hr_label,"");
        lv_label_set_text(m_main_view.clock.min_label,"");
        lv_label_set_text(m_main_view.weather.p_weather_label,"");
        lv_label_set_text(m_main_view.weather.p_humidity_label,"");
        lv_label_set_text(m_main_view.weather.p_pressure_label,"");
        lv_label_set_text(m_main_view.weather.p_temperature_label,"");

#if defined(GUI_VIEW_MAX_TEMP) && (0 != GUI_VIEW_MAX_TEMP)
        lv_label_set_text(m_main_view.weather.p_temperature_min_label,"");
        lv_label_set_text(m_main_view.weather.p_temperature_max_label,"");
#endif

        lv_obj_set_size(m_main_view.clock.sq, 10, 10);
        lv_obj_set_size(m_main_view.clock.sq2, 10, 10);

        lv_obj_add_style(m_main_view.clock.sq, &m_clock_dot_style, 0);
        lv_obj_add_style(m_main_view.clock.sq2, &m_clock_dot_style, 0);

#if defined(GUI_VIEW_FLIP_CLOCK_LINE) && (0 != GUI_VIEW_FLIP_CLOCK_LINE)
        lv_obj_t * sq = lv_obj_create(lv_scr_act());
        lv_obj_t * sq2 = lv_obj_create(lv_scr_act());
        lv_obj_t * sq3 = lv_obj_create(lv_scr_act());
        lv_obj_add_style(sq, &m_temperature_style, 0);
        lv_obj_add_style(sq2, &m_temperature_style, 0);
        lv_obj_add_style(sq3, &m_temperature_style, 0);

        lv_obj_set_size(sq, 110, 100);
        lv_obj_set_size(sq2, 110, 100);
        lv_obj_set_size(sq3, 220, 1);
        lv_obj_set_align(sq3, LV_ALIGN_LEFT_MID);

        lv_obj_set_align(sq, LV_ALIGN_LEFT_MID);
        lv_obj_align_to(sq2, sq, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
#endif

        lv_img_set_src(m_main_view.weather.p_weather_icon, &icon_00);
        gui_view_main_relayout();

}

void gui_view_main_relayout(void)
{
        if (m_time_is_enabled) {
                lv_obj_clear_flag(m_main_view.clock.sq, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(m_main_view.clock.sq2, LV_OBJ_FLAG_HIDDEN);
        } else {
                lv_obj_add_flag(m_main_view.clock.sq, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(m_main_view.clock.sq2, LV_OBJ_FLAG_HIDDEN);
        }

        lv_obj_set_align(m_main_view.clock.hr_label, LV_ALIGN_LEFT_MID);
        lv_obj_set_align(m_main_view.clock.min_label, LV_ALIGN_LEFT_MID);

        lv_obj_align_to(m_main_view.clock.min_label,
                        m_main_view.clock.hr_label, LV_ALIGN_OUT_RIGHT_MID, 10 , 0 );

        lv_obj_align_to(m_main_view.clock.sq,
                        m_main_view.clock.hr_label, LV_ALIGN_OUT_RIGHT_MID, 0, 15 );

        lv_obj_align_to(m_main_view.clock.sq2,
                        m_main_view.clock.hr_label, LV_ALIGN_OUT_RIGHT_MID, 0, -15 );

        lv_obj_align(m_main_view.weather.p_weather_icon, LV_ALIGN_RIGHT_MID, 0, 0);

        lv_obj_align(m_main_view.weather.p_weather_label, LV_ALIGN_BOTTOM_LEFT, 0, 0);


        lv_obj_align_to(m_main_view.weather.p_temperature_label,
                        m_main_view.weather.p_weather_icon, LV_ALIGN_OUT_TOP_MID, 0 , 0 );

#if 0
        lv_obj_align_to(m_main_view.weather.p_temperature_min_label,
                        m_main_view.weather.p_temperature_label,
                        LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

        lv_obj_align_to(m_main_view.weather.p_temperature_max_label,
                        m_main_view.weather.p_temperature_label,
                        LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 0);
#endif

        lv_obj_align_to(m_main_view.weather.p_humidity_label,
                        m_main_view.weather.p_weather_icon,
                        LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

        lv_obj_align_to(m_main_view.weather.p_pressure_label,
                        m_main_view.weather.p_humidity_label,
                        LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
}

void gui_view_main_get_view(gui_view_main_t * p_main_view) {
        *p_main_view = m_main_view;
}

void gui_view_enable_time(bool const enable)
{
        m_time_is_enabled = enable;
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
