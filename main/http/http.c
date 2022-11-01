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

#include <stdint.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "tasks_config.h"

#include "esp_http_client.h"
#include "http/http.h"
#include "wifi.h"
#include "json/json.h"

#include "esp_log.h"

#include "display/display.h"
#include "time/time_tracker.h"

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

#define SERVER_URL                          CONFIG_CO2_MONITOR_DEVICE_URL
#define TOKEN                               CONFIG_CO2_MONITOR_DEVICE_TOKEN
#define ENDPOINT                            "/api/v1/" TOKEN "/telemetry"
#define URL                                 SERVER_URL ENDPOINT

#define HEADER_KEY                          "Content-Type"
#define HEADER_VALUE                        "application/json"




#define CITY "Berlin"
#define API_TOKEN "91a6a0c18796114d8b407b7fdb8fcbf9"
#define WHAT "weather?q="
#define WEATHER_ENDPOINT "https://api.openweathermap.org/data/2.5/"
#define WEATHER_URL WEATHER_ENDPOINT WHAT CITY "&appid=" API_TOKEN "&units=metric"

#define TIME_ENDPOINT "http://worldtimeapi.org"
#define TIME_PATH "/api/timezone"
#define TIME_QUERY "/Europe/Berlin"


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

_Noreturn static void http_task(void *pvParameter);

static esp_err_t http_event_handler(esp_http_client_event_t *evt);

static bool http_request_time(char const ** pp_response);

/*
 *******************************************************************************
 * Public Data Declarations                                                    *
 *******************************************************************************
 */

QueueHandle_t http_q = NULL;


/*
 *******************************************************************************
 * Static Data Declarations                                                    *
 *******************************************************************************
 */

char local_response_buffer[MAX_HTTP_OUTPUT_BUFFER] = {};

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

bool http_init(void) {

        bool success;

        BaseType_t task_result;
        TaskHandle_t http_task_h = NULL;

        http_q = xQueueCreate(3, sizeof(uint32_t *));

        success = (NULL != http_q);

        if (success) {

                task_result = xTaskCreate((TaskFunction_t)http_task,
                                          "http_task",
                                          TASK_STACK_DEPTH,
                                          NULL,
                                          TASK_PRIORITY,
                                          &http_task_h);

                success = (pdPASS == task_result);
        }

        return success;
}

bool http_send_message(http_msg_type_t const type, void * value)
{
        http_msg_t * p_message = NULL;
        BaseType_t queue_result;
        bool success;

        p_message = pvPortMalloc(sizeof(http_msg_t));

        if (NULL == p_message) {
                success = false;

        } else {
                p_message->type = type;

                switch (type) {

                case HTTP_MSG_GET_TIME:
                        break;
                case HTTP_MSG_GET_WEATHER:
                        break;
                case HTTP_MSG_COUNT:
                        break;
                }

                queue_result = xQueueSend(http_q, &p_message, 0);

                success = (pdPASS == queue_result);

                // FIXME: on co2monitor, if, please check
                if (!success) {
                        vPortFree(p_message);
                        p_message = NULL;
                }
        }

        return success;
}

/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

static bool http_request_time(char const ** pp_response)
{

        ESP_LOGI(TAG,"Sending data to %s", TIME_ENDPOINT);
        esp_err_t esp_result;
        int code;

        // TODO check for null pointer

        esp_http_client_config_t const http_config = {
                        .url = TIME_ENDPOINT TIME_PATH TIME_QUERY,
                        .event_handler = http_event_handler,
                        .user_data = local_response_buffer,
                        .buffer_size = 200,
                        .method = HTTP_METHOD_GET,
        };

        esp_http_client_handle_t client = esp_http_client_init(&http_config);

        esp_result = esp_http_client_perform(client);
        bool valid_time = false;
        if (ESP_OK == esp_result) {

                code = esp_http_client_get_status_code(client);

                if (200 == code) {
                        ESP_LOGI(TAG, "Response from server: %s", local_response_buffer);
                        *pp_response = local_response_buffer;
                        valid_time = true;
                }

                esp_result = esp_http_client_cleanup(client);
        } else {
                ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(esp_result));
        }

        return (ESP_OK == esp_result) && (valid_time);
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */

_Noreturn static void http_task(void *pvParameter)
{
        (void)pvParameter;
        http_msg_t * p_message;
        BaseType_t queue_result;
        wifi_status_t wifi_status;
        char const * p_response = NULL;
        bool success;
        char buffer[20];
        uint32_t unix_time = 0;
        uint32_t raw_offset_s;

        for (;;) {
                queue_result = xQueueReceive(http_q, &p_message, portMAX_DELAY);

                wifi_status = wifi_get_status();

                if (pdTRUE == ((queue_result) && (WIFI_STATUS_CONNECTED == wifi_status))) {

                        switch (p_message->type) {

                        case HTTP_MSG_GET_TIME:
                                success = http_request_time(&p_response);

                                if (success) {
                                        success = json_load(p_response);
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

                                        time_tracker_update_time(unix_time);

                                        ESP_LOGI(TAG, "Unixtime: %d", unix_time);

                                }

                                break;
                        case HTTP_MSG_GET_WEATHER:
                                break;
                        case HTTP_MSG_COUNT:
                                break;
                        }

                }

                if (pdTRUE == queue_result) {
                        vPortFree(p_message);
                }

                ESP_LOGI(TAG,"Max stack usage: %d of %d bytes", TASK_STACK_DEPTH - uxTaskGetStackHighWaterMark(NULL), TASK_STACK_DEPTH);
        }
}

static esp_err_t http_event_handler(esp_http_client_event_t *evt)
{
        static char *output_buffer;  // Buffer to store response of http request from event handler
        static int output_len;       // Stores number of bytes read
        switch(evt->event_id) {
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
                ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
                break;
        case HTTP_EVENT_ON_DATA:
                ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
                /*
                 *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
                 *  However, event handler can also be used in case chunked encoding is used.
                 */
                if (!esp_http_client_is_chunked_response(evt->client)) {
                        // If user_data buffer is configured, copy the response into the buffer
                        if (evt->user_data) {
                                memcpy(evt->user_data + output_len, evt->data, evt->data_len);
                        } else {
                                if (output_buffer == NULL) {
                                        output_buffer = (char *) malloc(esp_http_client_get_content_length(evt->client));
                                        output_len = 0;
                                        if (output_buffer == NULL) {
                                                ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                                                return ESP_FAIL;
                                        }
                                }
                                memcpy(output_buffer + output_len, evt->data, evt->data_len);
                        }
                        output_len += evt->data_len;
                }

                break;
        case HTTP_EVENT_ON_FINISH:
                ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
                if (output_buffer != NULL) {
                        // Response is accumulated in output_buffer. Uncomment the below line to print the accumulated response
                        // ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
                        free(output_buffer);
                        output_buffer = NULL;
                }
                output_len = 0;
                break;
        case HTTP_EVENT_DISCONNECTED:
                ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
                int mbedtls_err = 0;
                //TODO:
                /* esp_err_t err = esp_tls_get_and_clear_last_error(evt->data, &mbedtls_err, NULL);
                if (err != 0) {
                        ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
                        ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
                }
                if (output_buffer != NULL) {
                        free(output_buffer);
                        output_buffer = NULL;
                }
                output_len = 0;
                                  */

                break;
        }

        return ESP_OK;
}
