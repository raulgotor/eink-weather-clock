/*!
 *******************************************************************************
 * @file flip_clock.c
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

#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <driver/spi_master.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "drivers/EPD_2in9_V2/EPD_2in9_V2.h"
#include "drivers/Config/DEV_Config.h"

#include "lvgl/lvgl.h"

#include "hal/GUI/GUI_Paint.h"

#include "gui/gui.h"
#include "time/time_tracker.h"
#include "display/display.h"
#include "wifi.h"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "http/http.h"

#include "lvgl/lvgl.h"
#include "tasks_config.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */



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

static void lvgl_task(void * parameters);

/*
 *******************************************************************************
 * Public Data Declarations                                                    *
 *******************************************************************************
 */

extern QueueHandle_t http_q;

/*
 *******************************************************************************
 * Static Data Declarations                                                    *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */
bool flip_clock_app_start(void);

void app_main(void)
{
        flip_clock_app_start();
}


bool flip_clock_app_start(void) {


        spi_init();

        bool success = display_init();

        success = success && wifi_init();

        success = success && http_init();

        assert(success && "Modules initialization failed");

        time_tracker_init();
        BaseType_t result;

        if (success) {
                result = xTaskCreate(lvgl_task,
                                     "lvgl_task",
                                     TASKS_CONFIG_LVGL_STACK_DEPTH,
                                     NULL,
                                     0,
                                     NULL);

                success = (pdPASS == result);
        }

        return success;
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

static void lvgl_task(void * parameters)
{

        for (;;){

                lv_task_handler();
                lv_tick_inc(1000);
                vTaskDelay(1000 / portTICK_PERIOD_MS);

        }
}
