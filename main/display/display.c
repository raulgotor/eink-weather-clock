/*!
 *******************************************************************************
 * @file display.c
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

#include <stdbool.h>
#include <stdio.h>
#include <esp_log.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "tasks_config.h"
#include "display.h"
#include "lvgl/lvgl.h"
#include "gui/gui.h"
#include "hal/e_ink/e_ink.h"

#include "freertos/queue.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */

#define TASK_STACK_DEPTH                    TASKS_CONFIG_DISPLAY_STACK_DEPTH
#define TASK_PRIORITY                       TASKS_CONFIG_DISPLAY_PRIORITY
#define TASK_REFRESH_RATE_TICKS             (pdMS_TO_TICKS(TASKS_CONFIG_DISPLAY_REFRESH_RATE_MS))
#define TAG                                 "Display task"

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

static bool display_send_message(display_msg_type_t const type, void * p_value);

static void display_task(void * p_parameters);

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

static QueueHandle_t m_display_q = NULL;

static bool is_valid_time(my_time_t const * const p_time);

static bool is_valid_temperature(temperature_t const * const p_temperature);

static bool is_valid_humidity(int32_t const humidiy);

static lv_disp_t * mp_display = NULL;

static void set_weather_label_and_icon(
                gui_view_main_t const * const p_view_main,
                weather_t const * const p_weather);

static void set_temperature_label(
                gui_view_main_t const * const p_view_main,
                temperature_t * const p_temperature);

static void set_humidity_label(
                gui_view_main_t const * const p_view_main,
                int32_t const humidity);

static void set_pressure_label(
                gui_view_main_t const * const p_view_main,
                int32_t const pressure);

typedef struct {
        lv_img_dsc_t const * p_image;
        char * p_image_id;
} display_icon_id_map_t;

static display_icon_id_map_t const m_icon_id_map[] = {
                {.p_image = &icon_00, "000"},
                {.p_image = &icon_01, "01n"},
                {.p_image = &icon_02, "02d"},
                {.p_image = &icon_02, "02n"},
                {.p_image = &icon_03, "03d"},
                {.p_image = &icon_03, "03n"},
                {.p_image = &icon_04, "04d"},
                {.p_image = &icon_04, "04n"},
                {.p_image = &icon_09, "09d"},
                {.p_image = &icon_09, "09n"},
                {.p_image = &icon_10, "10d"},
                {.p_image = &icon_10, "10n"},
                {.p_image = &icon_11, "11d"},
                {.p_image = &icon_11, "11n"},
                {.p_image = &icon_13, "13d"},
                {.p_image = &icon_13, "13n"},
                {.p_image = &icon_50, "50d"},
                {.p_image = &icon_50, "50n"}
};

static size_t const m_icon_id_map_len =
                sizeof(m_icon_id_map) /
                sizeof(m_icon_id_map[0]);

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

bool display_init(void)
{
        BaseType_t result;
        gui_view_main_t main_view;
        bool success;


        result = hal_e_ink_init(&mp_display);

        success = (0 == result);

        if (success) {
                success = gui_init(mp_display);
        }

        if (success) {


                gui_view_main_init();

                gui_view_main_get_view(&main_view);
                gui_control_main_init(&main_view);

                result = xTaskCreate(
                                display_task,
                                "display_task",
                                TASK_STACK_DEPTH,
                                NULL,
                                TASK_PRIORITY,
                                NULL);

                success = (pdPASS == result);
        }



        if (success) {
                m_display_q = xQueueCreate(
                                3,
                                sizeof(display_msg_t *));

                success = (NULL != m_display_q);
        }

        return success;
}



bool display_set_time(time_t const time)
{
        return display_send_message(
                        DISPLAY_MSG_SET_TIME,
                        (void *)time);
}


bool display_set_weather(weather_t * const p_weather)
{
        bool success = display_send_message(
                                DISPLAY_MSG_SET_WEATHER,
                                (void *)p_weather);

        return  success;
}

bool display_set_temperature(temperature_t const * p_temperature)
{
        bool success = true;

        if ((NULL == p_temperature) || (!is_valid_temperature(p_temperature))) {
                success = false;
        } else {
                success = display_send_message(
                                DISPLAY_MSG_SET_TEMPERATURE,
                                (void *)p_temperature);
        }

        return  success;
}

bool display_set_humidity(int32_t const humidity)
{
        bool success = true;

        if (!is_valid_humidity(humidity)) {
                success = false;
        } else {
                success = display_send_message(
                                DISPLAY_MSG_SET_HUMIDITY,
                                (void *)humidity);
        }

        return  success;
}

bool display_set_pressure(int32_t const pressure)
{
        bool success = true;

        if (!is_valid_humidity(pressure)) {
                success = false;
        } else {
                success = display_send_message(
                                DISPLAY_MSG_SET_PRESSURE,
                                (void *)pressure);
        }

        return  success;
}

/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

static bool is_valid_time(my_time_t const * const p_time)
{
        // TODO: implementme!
        return true;
}

static bool is_valid_temperature(temperature_t const * const p_temperature)
{
        // TODO: implementme!
        return true;
}

static bool is_valid_humidity(int32_t const humidiy)
{
        // TODO: implementme!
        return true;
}

static bool display_send_message(display_msg_type_t const type, void * p_value)
{
        display_msg_t * p_message = NULL;
        BaseType_t queue_result;
        bool success = (NULL != p_value);

        if (success) {
                p_message = pvPortMalloc(sizeof(display_msg_t));

                if (NULL == p_message) {
                        success = false;
                }
        }

        if (success) {
                p_message->type = type;

                switch (type) {

                case DISPLAY_MSG_SET_TIME:
                        p_message->time = (time_t)p_value;
                        break;

                case DISPLAY_MSG_SET_WEATHER:
                        p_message->p_weather = (weather_t *)p_value;
                        break;

                case DISPLAY_MSG_SET_TEMPERATURE:
                        p_message->p_temperature = (temperature_t *)p_value;
                        break;

                case DISPLAY_MSG_SET_HUMIDITY:
                        p_message->humidity = (int32_t)p_value;
                        break;

                case DISPLAY_MSG_SET_PRESSURE:
                        p_message->pressure = (int32_t)p_value;
                        break;

                case DISPLAY_MSG_COUNT:
                        // TODO: fail here
                        break;
                }

                queue_result = xQueueSend(m_display_q, &p_message, 0);

                success = (pdPASS == queue_result);

                // FIXME: possible memory leak on co2monitor repo, please check
                if (!success) {
                        vPortFree(p_message);
                        p_message = NULL;
                }
        }


        return success;
}

static void set_weather_label_and_icon(
                gui_view_main_t const * const p_view_main,
                weather_t const * const p_weather)
{
        bool const success = (NULL != p_view_main) && (NULL != p_weather);
        bool found = false;
        size_t i;

        if (success) {
                lv_label_set_text(p_view_main->weather.p_weather_label, p_weather->description_s.data);

                for (i = 0; (m_icon_id_map_len > i) && (!found); ++i) {

                        if (0 == strcmp(m_icon_id_map[i].p_image_id,
                                        p_weather->icon_id_s.data)) {

                                lv_img_set_src(p_view_main->weather.p_weather_icon,
                                               m_icon_id_map[i].p_image);

                                found = true;
                        }
                }
        }
}

static void set_temperature_label(
                gui_view_main_t const * const p_view_main,
                temperature_t * const p_temperature)
{

        bool const success = (NULL != p_view_main);
        char buffer[20];

        if (success) {
                sprintf(buffer, "%.1fºC", (float)(p_temperature->current) / 100);

                lv_label_set_text(p_view_main->weather.p_temperature_label, buffer);

#ifdef MAX_TEMP
                sprintf(buffer, "v%d", p_temperature->minimum / 100);
                lv_label_set_text(p_view_main->weather.p_temperature_min_label, buffer);

                sprintf(buffer, "\x7F%d", p_temperature->maximum / 100);
                lv_label_set_text(p_view_main->weather.p_temperature_max_label, buffer);
#endif
        }
}

static void set_humidity_label(
                gui_view_main_t const * const p_view_main,
                int32_t const humidity)
{
        bool const success = (NULL != p_view_main);
        char buffer[10];

        if (success) {
                sprintf(buffer, "RH %d%%", humidity);
                lv_label_set_text(p_view_main->weather.p_humidity_label, buffer);
        }
}

static void set_pressure_label(
                gui_view_main_t const * const p_view_main,
                int32_t const pressure)
{
        bool const success = (NULL != p_view_main);
        char buffer[10];

        if (success) {
                sprintf(buffer, "%d mbar", pressure);
                lv_label_set_text(p_view_main->weather.p_pressure_label, buffer);
        }
}

static lv_color_t m_icon_buffer[LV_CANVAS_BUF_SIZE_INDEXED_1BIT(70, 70)];


static void draw_icon(lv_obj_t * const p_canvas) {

        bool const success = (NULL != p_canvas);

        if (success) {
                lv_canvas_set_buffer(p_canvas,
                                     m_icon_buffer,
                                     (lv_coord_t)70,
                                     (lv_coord_t)70,
                                     LV_IMG_CF_INDEXED_1BIT);

                lv_canvas_fill_bg(p_canvas, lv_color_black(), LV_OPA_100);
        }
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */

static void display_task(void * p_parameters)
{

        display_msg_t * p_message = NULL;
        BaseType_t queue_result;
        gui_view_main_t main_view;

        gui_view_main_get_view(&main_view);

        (void)p_parameters;
        char buff[20];
        struct tm * time_p;

        for (;;) {

                queue_result = xQueueReceive(
                                m_display_q,
                                &p_message,
                                TASK_REFRESH_RATE_TICKS);

                if ((pdTRUE == queue_result) && (NULL != p_message)) {

                        switch (p_message->type) {
                        case DISPLAY_MSG_SET_TIME:

                                gui_view_enable_time(true);

                                time_p = localtime(&p_message->time);

                                sprintf(buff, "%.2i", time_p->tm_hour);
                                lv_label_set_text(main_view.clock.hr_label, buff);

                                sprintf(buff, "%.2i", time_p->tm_min);
                                lv_label_set_text(main_view.clock.min_label, buff);

                                break;
                        case DISPLAY_MSG_SET_WEATHER:

                                set_weather_label_and_icon(&main_view,
                                                      p_message->p_weather);

                                vPortFree(p_message->p_weather);
                                p_message->p_weather = NULL;


                                break;
                        case DISPLAY_MSG_SET_TEMPERATURE:

                                set_temperature_label(&main_view,
                                                      p_message->p_temperature);

                                vPortFree(p_message->p_temperature);
                                p_message->p_temperature = NULL;

                                break;
                        case DISPLAY_MSG_SET_HUMIDITY:

                                set_humidity_label(&main_view,
                                                   p_message->humidity);
                                break;
                        case DISPLAY_MSG_SET_PRESSURE:

                                set_pressure_label(&main_view,
                                                   p_message->pressure);
                                break;
                        case DISPLAY_MSG_COUNT:
                                break;
                        }

                        gui_view_main_relayout();

                }

                ESP_LOGD(TAG,"Task usage: %d of %d bytes", TASK_STACK_DEPTH - uxTaskGetStackHighWaterMark(NULL), TASK_STACK_DEPTH);

                vPortFree(p_message);
                p_message = NULL;
        }

}
