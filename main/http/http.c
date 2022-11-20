/*!
 *******************************************************************************
 * @file http.c
 *
 * @brief 
 *
 * @author Raúl Gotor (raulgotor@gmail.com)
 * @date 10.04.22
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2022 Raúl Gotor
 * All rights reserved.
 * *******************************************************************************
 */

/*
 *******************************************************************************
 * #include Statements                                                         *
 *******************************************************************************
 */

#include <stdbool.h>
#include <esp_tls.h>

#include "tasks_config.h"

#include "esp_http_client.h"
#include "esp_log.h"

#include "json/json.h"
#include "display/display.h"

#include "http/http.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */

#define TAG                                 "http"

#define TASK_REFRESH_RATE_TICKS             (pdMS_TO_TICKS(TASKS_CONFIG_HTTP_REFRESH_RATE_MS))
#define TASK_STACK_DEPTH                    TASKS_CONFIG_HTTP_STACK_DEPTH
#define TASK_PRIORITY                       TASKS_CONFIG_HTTP_PRIORITY


#define MAX_HTTP_OUTPUT_BUFFER              (500)

#define WEATHER_ENDPOINT                    "http://api.openweathermap.org/data/2.5/"
#define WEATHER_LANGUAGE                    CONFIG_APPLICATION_LANGUAGE
#define WEATHER_CONTINENT                   CONFIG_APPLICATION_CONTINENT
#define WEATHER_CITY                        CONFIG_APPLICATION_CITY
#define WEATHER_API_KEY                     CONFIG_APPLICATION_API_KEY //"91a6a0c18796114d8b407b7fdb8fcbf9"
#define WEATHER_URL                         WEATHER_ENDPOINT "weather?q=" WEATHER_CITY "&appid=" WEATHER_API_KEY "&units=metric&lang=" WEATHER_LANGUAGE

#define TIME_ENDPOINT                       "http://worldtimeapi.org"
#define TIME_PATH                           "/api/timezone"
#define TIME_URL                            "/" WEATHER_CONTINENT "/" WEATHER_CITY

#define JSON_VALUES_BUFFER_LEN 40

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

//! @brief Event handler function for HTTP events
static esp_err_t http_event_handler(esp_http_client_event_t *p_event);

static bool execute_get_request(char const * p_url);

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

//! @brief Buffer for storing the HTTP response
char m_response_buffer[MAX_HTTP_OUTPUT_BUFFER] = {};

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

bool http_request_time(time_t * const p_time)
{
        bool success = (NULL != p_time);
        uint32_t unix_time = 0;

        char buffer[JSON_VALUES_BUFFER_LEN];
        uint32_t raw_offset_s;

        if (success) {
                success = execute_get_request(TIME_ENDPOINT TIME_PATH TIME_URL);
        }

        if (success) {
                success = json_load(m_response_buffer);
        }

        if (success) {
                success = json_get_primitive_value("unixtime", buffer, 20);
        }

        if (success) {
                //TODO: change to strol
                unix_time = atoi(buffer);
                success = json_get_primitive_value("raw_offset", buffer, 20);
        }

        if (success) {
                raw_offset_s = atoi(buffer);
                unix_time += raw_offset_s;

                *p_time = unix_time;

                ESP_LOGI(TAG, "Unixtime: %d", unix_time);

        }

        return success;
}

bool http_request_weather(weather_t * const p_weather,
                          temperature_t * const p_temperature,
                          int32_t * const p_humidity,
                          int32_t * const p_pressure)
{

        bool success = (NULL != p_weather) &&
                       (NULL != p_temperature) &&
                       (NULL != p_humidity) &&
                       (NULL != p_pressure);

        char buffer[JSON_VALUES_BUFFER_LEN];

        if (success) {
                success = execute_get_request(WEATHER_URL);
        }

        if (success) {
                success = json_load(m_response_buffer);
        }

        if (success) {
                success = json_get_primitive_value(
                                "pressure",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                //TODO: change to strol
                *p_pressure = atoi(buffer);
                ESP_LOGD(TAG, "Pressure: %d", *p_pressure);
                success = json_get_primitive_value(
                                "humidity",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                //TODO: change to strol
                *p_humidity = atoi(buffer);
                ESP_LOGD(TAG, "Humidity: %d", *p_humidity);
                success = json_get_primitive_value(
                                "temp",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                //TODO: change to strol
                p_temperature->current = atof(buffer) * 100;
                ESP_LOGD(TAG, "Temperature: %d", p_temperature->current);

                success = json_get_primitive_value(
                                "temp_min",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                //TODO: change to strol
                p_temperature->minimum = atof(buffer) * 100;
                ESP_LOGD(TAG, "Temperature_min: %d", p_temperature->minimum);

                success = json_get_primitive_value(
                                "temp_max",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                //TODO: change to strol
                p_temperature->maximum = atof(buffer) * 100;
                ESP_LOGD(TAG, "Temperature_max: %d", p_temperature->maximum);

                success = json_get_string_value(
                                "description",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                memcpy(p_weather->description_s.data,
                       buffer,
                       p_weather->description_s.size);

                ESP_LOGD(TAG,
                         "Weather description: %s",
                         p_weather->description_s.data);

                success = json_get_string_value(
                                "icon",
                                buffer,
                                JSON_VALUES_BUFFER_LEN);
        }

        if (success) {
                memcpy(p_weather->icon_id_s.data,
                       buffer,
                       p_weather->icon_id_s.size);

                ESP_LOGD(TAG,
                         "Weather description: %s",
                         p_weather->icon_id_s.data);
        }

        return success;
}


/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

static bool execute_get_request(char const * p_url)
{
        esp_http_client_config_t const http_config = {
                        .url = p_url,
                        .event_handler = http_event_handler,
                        .user_data = m_response_buffer,
                        .buffer_size = MAX_HTTP_OUTPUT_BUFFER,
                        .method = HTTP_METHOD_GET,
        };

        esp_http_client_handle_t client = esp_http_client_init(&http_config);
        bool success = (NULL != p_url);
        esp_err_t esp_result = ESP_OK;
        int response_code = 0;

        if (success) {
                esp_result = esp_http_client_perform(client);

                success = (ESP_OK == esp_result);
        }

        if (!success) {
                ESP_LOGE(TAG, "HTTP GET request failed: %s",
                         esp_err_to_name(esp_result));

        } else {
                response_code = esp_http_client_get_status_code(client);
                esp_result = esp_http_client_cleanup(client);

                ESP_LOGI(TAG, "Response from server: %s, code %d",
                         m_response_buffer,
                         response_code);

                success = (ESP_OK == esp_result);
        }

        return (success && (200 == response_code));
}

static esp_err_t http_event_handler(esp_http_client_event_t *evt)
{
        static char * p_output_buffer;
        static int output_len;

        switch(p_event->event_id) {
        case HTTP_EVENT_ERROR:
                ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
                break;
        case HTTP_EVENT_ON_CONNECTED:
                ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
                break;
        case HTTP_EVENT_HEADER_SENT:
                ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
                break;
        case HTTP_EVENT_ON_HEADER:
                ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s",
                         p_event->header_key,
                         p_event->header_value);

                break;
        case HTTP_EVENT_ON_DATA:
                ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", p_event->data_len);
                /*
                 *  Check for chunked encoding is added as the URL for chunked
                 *  encoding used in this example returns binary data.
                 *  However, event handler can also be used in case chunked
                 *  encoding is used.
                 */
                if (!esp_http_client_is_chunked_response(p_event->client)) {
                        // If user_data buffer is configured, copy the response
                        // into the buffer
                        if (p_event->user_data) {
                                memcpy(p_event->user_data + output_len,
                                       p_event->data,
                                       p_event->data_len);
                        } else {
                                if (p_output_buffer == NULL) {
                                        p_output_buffer = (char *) malloc(
                                                        esp_http_client_get_content_length(p_event->client));

                                        output_len = 0;
                                        if (p_output_buffer == NULL) {
                                                ESP_LOGE(TAG,
                                                         "Failed to allocate memory for output buffer");

                                                return ESP_FAIL;
                                        }
                                }
                                memcpy(p_output_buffer + output_len,
                                       p_event->data,
                                       p_event->data_len);
                        }
                        output_len += p_event->data_len;
                }

                break;
        case HTTP_EVENT_ON_FINISH:
                ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");

                if (p_output_buffer != NULL) {
                        // Response is accumulated in output_buffer. Uncomment
                        // the below line to print the accumulated response
                        // ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
                        free(p_output_buffer);
                        p_output_buffer = NULL;
                }

                output_len = 0;
                break;

        case HTTP_EVENT_DISCONNECTED:
                ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
                int mbedtls_err = 0;

                esp_err_t err = esp_tls_get_and_clear_last_error(
                                p_event->data,
                                &mbedtls_err, NULL);

                if (err != 0) {
                        ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
                        ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
                }

                if (p_output_buffer != NULL) {
                        free(p_output_buffer);
                        p_output_buffer = NULL;
                }

                output_len = 0;
                break;
        }

        return ESP_OK;
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */


