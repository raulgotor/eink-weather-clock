/*!
 *******************************************************************************
 * @file http.h
 *
 * @brief 
 *
 * @author Raúl Gotor (raulgotor@gmail.com)
 * @date 10.04.22
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2022 Raúl Gotor
 * All rights reserved.
 *******************************************************************************
 */

#ifndef HTTP_H
#define HTTP_H

/*
 *******************************************************************************
 * Public Macros                                                               *
 *******************************************************************************
 */


#include <stdint-gcc.h>

/*
 *******************************************************************************
 * Public Data Types                                                           *
 *******************************************************************************
 */

typedef enum {
        HTTP_MSG_GET_TIME = 0,
        HTTP_MSG_GET_WEATHER,
        HTTP_MSG_COUNT
} http_msg_type_t;

typedef struct
{
        http_msg_type_t type;
} http_msg_t;

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

bool http_request_weather(weather_t * const p_weather,
                          temperature_t * const p_temperature,
                          int32_t * const p_humidity,
                          int32_t * const p_pressure);

bool http_request_time(time_t * const p_time);

#endif //HTTP_H