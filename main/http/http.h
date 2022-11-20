/*!
 *******************************************************************************
 * @file http.h
 *
 * @brief This module contains functions to perform different HTTP requests to
 *        the servers of interest (basically time and weather provider servers)
 *        and other related stuff such as event handlers
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

//! @brief Perform a GET request to the weather provider server
bool http_request_weather(weather_t * const p_weather,
                          temperature_t * const p_temperature,
                          int32_t * const p_humidity,
                          int32_t * const p_pressure);

//! @brief Perform a GET request to the time provider server
bool http_request_time(time_t * const p_time);

#endif //HTTP_H