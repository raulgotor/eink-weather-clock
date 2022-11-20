/*!
 *******************************************************************************
 * @file time_tracker.c
 *
 * @brief 
 *
 * @author Raúl Gotor (raul.gotor@midge-medical.com)
 * @date 25.10.22
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
#include <time.h>
#include <esp_log.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

#include "display/display.h"
#include "time_tracker.h"
#include "wifi.h"
#include "http/http.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */

#define TIME_TRACKER_REFRESH_TICKS_FAST     pdMS_TO_TICKS(10 /*sec*/ * 1000 /*ms*/)
#define TIME_TRACKER_REFRESH_TICKS_SLOW     pdMS_TO_TICKS(60 /*min*/* 60 /*sec*/ * 1000 /*ms*/)

#define WEATHER_DESCRIPTION_BUFFER_LEN      (40)
#define WEATHER_ICON_ID_BUFFER_LEN          (10)

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

#define TAG "time_tracker"

/*
 *******************************************************************************
 * Private Function Prototypes                                                 *
 *******************************************************************************
 */

static void time_resync(void);

static void time_tracker(void);

static void time_tracker_update_time(time_t const time);

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

static char m_weather_description[WEATHER_DESCRIPTION_BUFFER_LEN];

static char m_weather_icon_id[WEATHER_ICON_ID_BUFFER_LEN];

static uint32_t m_base_time_s = 0;

static uint32_t m_last_update_mcu_time_s = 0;

static TimerHandle_t m_time_tracker_h = NULL;

static TimerHandle_t m_time_resync_h = NULL;

static bool m_time_was_set_once = false;

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

bool time_tracker_init(void)
{
        bool success = true;
        BaseType_t timer_result;

        if (success) {
                m_time_tracker_h = xTimerCreate("time_tracker",
                                                pdMS_TO_TICKS(1000),
                                                pdTRUE,
                                                NULL,
                                                time_tracker);

                success = (NULL != m_time_tracker_h);
        }

        if (success) {
                m_time_resync_h = xTimerCreate("time_resync",
                                               pdMS_TO_TICKS(10000),
                                               pdTRUE,
                                               NULL,
                                               time_resync);

                success = (NULL != m_time_resync_h);
        }

        if (success) {
                timer_result = xTimerStart(m_time_resync_h, 0);

                success = (pdPASS == timer_result);
        }

        if (success) {
                timer_result = xTimerStart(m_time_tracker_h, 0);

                success = (pdPASS == timer_result);
        }

        return success;
}

/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

static void time_tracker_update_time(time_t const time)
{
        ESP_LOGI(TAG, "Updating time to %d time", (uint32_t )time);

        uint32_t const mcu_time_now_s = xTaskGetTickCount() / 1000;

        m_time_was_set_once = true;
        m_base_time_s = time;
        m_last_update_mcu_time_s = mcu_time_now_s;
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */

static void time_resync(void) {

        bool weather_success = false;
        bool temp_success = false;
        weather_t * p_weather = NULL;
        temperature_t * p_temperature = NULL;

        bool success;
        bool time_success;
        time_t time;
        int32_t humidity;
        int32_t pressure;

        if ((WIFI_STATUS_CONNECTED == wifi_get_status())) {//} && (m_time_was_set_once)) {

                ESP_LOGI(TAG, "Sending time request");

                time_success = http_request_time(&time);

                if (time_success) {
                        time_tracker_update_time(time);
                }

                p_temperature = pvPortMalloc(sizeof(temperature_t));

                success = (NULL != p_temperature);

                if (success) {
                        p_weather = pvPortMalloc(sizeof(weather_t));

                        success = (NULL != p_weather);
                }

                if (success) {
                        p_weather->description_s.data = m_weather_description;
                        p_weather->description_s.size = WEATHER_DESCRIPTION_BUFFER_LEN;
                        p_weather->icon_id_s.data = m_weather_icon_id;
                        p_weather->icon_id_s.size = WEATHER_ICON_ID_BUFFER_LEN;

                        success = http_request_weather(p_weather,
                                                       p_temperature,
                                                       &humidity,
                                                       &pressure);
                }

                if (success) {
                        (void)display_set_pressure(pressure);
                        (void)display_set_humidity(humidity);
                        temp_success = display_set_temperature(p_temperature);

                        if (!temp_success) {
                                vPortFree(p_temperature);
                                p_temperature = NULL;
                        }

                        weather_success = display_set_weather(p_weather);
                }

                if ((NULL != p_weather) && (!weather_success)) {
                        vPortFree(p_weather);
                        p_weather = NULL;
                }

                if ((NULL != p_temperature) && (!temp_success)) {
                        vPortFree(p_temperature);
                        p_temperature = NULL;
                }

                if (success && time_success && m_time_was_set_once) {
                        xTimerChangePeriod(m_time_resync_h, TIME_TRACKER_REFRESH_TICKS_SLOW, 0);
                        ESP_LOGD(TAG, "setting period to %d seconds", TIME_TRACKER_REFRESH_TICKS_SLOW);
                }

        } else {
                xTimerChangePeriod(m_time_resync_h, TIME_TRACKER_REFRESH_TICKS_FAST, 0);
                ESP_LOGD(TAG, "setting period to %d sec, since WiFi status is %d", TIME_TRACKER_REFRESH_TICKS_FAST, wifi_get_status());
        }
}

static void time_tracker(void) {
        uint32_t const mcu_time_now_s = xTaskGetTickCount() / 1000;
        uint32_t elapsed_s = mcu_time_now_s - m_last_update_mcu_time_s;
        time_t current_time_unix_s = elapsed_s + m_base_time_s;
        bool success = true;

        if (m_time_was_set_once) {
                success = display_set_time(current_time_unix_s);
        }

        if (!success) {
                ESP_LOGW(TAG, "Display failed to update");
        }

        ESP_LOGD(TAG,"Task usage: %d of %d bytes", CONFIG_TIMER_TASK_STACK_DEPTH - uxTaskGetStackHighWaterMark(NULL), CONFIG_TIMER_TASK_STACK_DEPTH);
}

