/*!
 *******************************************************************************
 * @file display.h
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

#ifndef DISPLAY_H
#define DISPLAY_H

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

typedef struct {
        uint8_t hours;
        uint8_t min;
} my_time_t;

typedef struct {
        int32_t maximum;
        int32_t minimum;
        int32_t current;
} temperature_t;

typedef enum {
        WEATHER_SUNNY = 0,
        WEATHER_PARTLY_CLOUDY,
        WEATHER_CLOUDY,
        WEATHER_OVERCAST,
        WEATHER_CLOUDY_LIGHT_SHOWERS,
        WEATHER_CLOUDY_SHOWERS,
        WEATHER_CLOUDY_HEAVY,
        WEATHER_PARTLY_CLOUDY_LIGHT_SHOWERS,
        WEATHER_PARTLY_CLOUDY_SHOWERS,
        WEATHER_PARTLY_CLOUDY_HEAVY,
        WEATHER_THUNDERSTORM,
        WEATHER_LIGHT_SNOW_SHOWER,
        WEATHER_HEAVY_SNOW_SHOWER,
        WEATHER_MIST,
        WEATHER_COUNT
} weather_type_t;

typedef struct {
        weather_type_t type;
        struct {
                char * data;
                size_t size;
        } description_s;
        struct {
                char * data;
                size_t size;
        } icon_id_s;
} weather_t;

typedef enum {
        DISPLAY_MSG_SET_TIME = 0,
        DISPLAY_MSG_SET_WEATHER,
        DISPLAY_MSG_SET_TEMPERATURE,
        DISPLAY_MSG_SET_HUMIDITY,
        DISPLAY_MSG_SET_PRESSURE,
        DISPLAY_MSG_COUNT
} display_msg_type_t;

typedef struct {
        display_msg_type_t type;
        union {
                time_t time;
                weather_t * p_weather;
                temperature_t * p_temperature;
                int32_t humidity;
                int32_t pressure;
        };
} display_msg_t;

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

bool display_init(void);

bool display_set_time(time_t const p_time);

bool display_set_weather(weather_t * const p_weather);

bool display_set_temperature(temperature_t const * p_temperature);

bool display_set_humidity(int32_t const humidity);

bool display_set_pressure(int32_t const pressure);

#endif //DISPLAY_H