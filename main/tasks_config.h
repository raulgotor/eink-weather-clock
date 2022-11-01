/*!
 *******************************************************************************
 * @file tasks_config.h
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

#ifndef TASKS_CONFIG_H
#define TASKS_CONFIG_H

/*
 *******************************************************************************
 * Public Macros                                                               *
 *******************************************************************************
 */


#define TASKS_CONFIG_DISPLAY_PRIORITY           (1)
#define TASKS_CONFIG_LVGL_PRIORITY              (2)
#define TASKS_CONFIG_HTTP_PRIORITY              (3)

#define TASKS_CONFIG_DISPLAY_STACK_DEPTH        (2 * 1024)
#define TASKS_CONFIG_LVGL_STACK_DEPTH           (4 * 1024)
#define TASKS_CONFIG_HTTP_STACK_DEPTH           (3 * 1024)

#define TASKS_CONFIG_DISPLAY_REFRESH_RATE_MS    (1000)
#define TASKS_CONFIG_LVGL_REFRESH_RATE_MS       (100)
#define TASKS_CONFIG_HTTP_REFRESH_RATE_MS       (100)



/*
 *******************************************************************************
 * Public Data Types                                                           *
 *******************************************************************************
 */

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

#endif //TASKS_CONFIG_H