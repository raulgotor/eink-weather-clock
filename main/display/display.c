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

static bool display_send_message(display_msg_type_t const type, void * value);

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

#include <time.h>


bool display_set_time(time_t const time)
{
        return display_send_message(
                        DISPLAY_MSG_SET_TIME,
                        (void *)time);
}


bool display_set_weather(weather_t const weather)
{
        bool success = display_send_message(
                                DISPLAY_MSG_SET_WEATHER,
                                (void *)weather);

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

static bool display_send_message(display_msg_type_t const type, void * value)
{
        display_msg_t * p_message = NULL;
        BaseType_t queue_result;
        bool success;

        p_message = pvPortMalloc(sizeof(display_msg_t));

        if (NULL == p_message) {
                success = false;

        } else {
                p_message->type = type;

                switch (type) {

                case DISPLAY_MSG_SET_TIME:
                        p_message->time = (time_t)value;
                        break;

                case DISPLAY_MSG_SET_WEATHER:
                        p_message->weather = (weather_t)value;
                        break;

                case DISPLAY_MSG_SET_TEMPERATURE:
                        p_message->temperature = (temperature_t *)value;
                        break;

                case DISPLAY_MSG_SET_HUMIDITY:
                        p_message->humidity = (int32_t)value;
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

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */

static void display_task(void * p_parameters)
{

        display_msg_t * p_message = NULL;
        BaseType_t queue_result;

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

                                time_p = localtime(&p_message->time);

                                sprintf(buff,
                                        "%.2i%.2i",
                                        time_p->tm_hour,
                                        time_p->tm_min);

                                gui_control_main_set_time(buff);

                                break;
                        case DISPLAY_MSG_SET_WEATHER:
                                break;
                        case DISPLAY_MSG_SET_TEMPERATURE:
                                break;
                        case DISPLAY_MSG_SET_HUMIDITY:
                                break;
                        case DISPLAY_MSG_COUNT:
                                break;
                        }

                }

                ESP_LOGD(TAG,"Task usage: %d of %d bytes", TASK_STACK_DEPTH - uxTaskGetStackHighWaterMark(NULL), TASK_STACK_DEPTH);

                vPortFree(p_message);
                p_message = NULL;
        }

}
