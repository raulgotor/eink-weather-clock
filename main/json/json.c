/*!
 *******************************************************************************
 * @file json.c
 *
 * @brief 
 *
 * @author Raúl Gotor (raul.gotor@midge-medical.com)
 * @date 26.10.22
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
#include <stdint.h>
#include <string.h>
#include <esp_log.h>

#include "jsmn/jsmn.h"
#include "json/json.h"

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

static bool json_get_value(char const * p_key, jsmntype_t const token_type, char const * p_buffer, size_t const buffer_len);

static int32_t json_get_token_id(char const * p_key);

static bool is_key(jsmntok_t const * const p_token);

static bool is_value(jsmntok_t const * const p_token);

static char * json_get_value_for_key(uint32_t const token_id, jsmntype_t const key_type, size_t * const p_length);


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

static char const * m_json_string = NULL;

static jsmn_parser m_jsmn_parser;

static jsmntok_t m_tokens_list[128];

static size_t m_tokens_list_size = 0;


/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */

bool json_load(char const * p_json_string)
{
        bool success = (NULL != p_json_string);

        if (success) {
                jsmn_init(&m_jsmn_parser);
                m_tokens_list_size = jsmn_parse(
                                &m_jsmn_parser,
                                p_json_string,
                                strlen(p_json_string),
                                m_tokens_list,
                                (sizeof(m_tokens_list) / sizeof(m_tokens_list[0])));
        }

        if ((success) &&
            (1 <= m_tokens_list_size) &&
            (JSMN_OBJECT == m_tokens_list[0].type)) {
                m_json_string = p_json_string;

        } else {
                success = false;
        }

        return success;
}

bool json_get_primitive_value(
                char const * p_key,
                char const * p_buffer,
                size_t const buffer_len) {
        return json_get_value(p_key, JSMN_PRIMITIVE, p_buffer, buffer_len);
}

bool json_get_string_value(
                char const * p_key,
                char const * p_buffer,
                size_t const buffer_len) {
        return json_get_value(p_key, JSMN_STRING, p_buffer, buffer_len);
}

/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

static int32_t json_get_token_id(char const * p_key)
{
        size_t i;
        int32_t result = -1;

        for (i = 1; (m_tokens_list_size > i) &&
                    (-1 == result) &&
                    (NULL != p_key); ++i) {


                if (0 == strncmp(m_json_string + m_tokens_list[i].start,
                                 p_key,
                                 m_tokens_list[i].end - m_tokens_list[i].start)) {

                        // warning, narrowing size
                        result = (int32_t)i;
                }
        }

        return result;
}

static bool is_key(jsmntok_t const * const p_token)
{
        return ((JSMN_STRING == p_token->type) && (0 != p_token->size));
}

static bool is_value(jsmntok_t const * const p_token)
{
        return (((JSMN_STRING == p_token->type) && (0 == p_token->size)) ||
                ((JSMN_PRIMITIVE == p_token->type) && (0 == p_token->size)) ||
                (JSMN_OBJECT == p_token->type) ||
                (JSMN_ARRAY == p_token->type));
}

static char * json_get_value_for_key(
                uint32_t const token_id,
                jsmntype_t const key_type,
                size_t * const p_length)
{
        char * p_string = NULL;
        uint32_t const value_token_id = token_id + 1;
        jsmntok_t value_token = m_tokens_list[value_token_id];
        jsmntok_t key_token = m_tokens_list[token_id];

        if ((NULL == p_length) ||
            (!is_key(&key_token)) ||
            (!is_value(&value_token)) ||
            (value_token.type != key_type)) {

                p_string = NULL;
        } else {
                *p_length = value_token.end - value_token.start;
                p_string = &m_json_string[value_token.start];
        }

        return p_string;
}


static bool json_get_value(
                char const * p_key,
                jsmntype_t const token_type,
                char const * p_buffer,
                size_t const buffer_len)
{
        bool success = (NULL != p_key) && (NULL != p_buffer) && (0 != buffer_len);

        size_t token_id = -1;
        size_t size;
        char * value_start = NULL;

        if (success) {
                token_id = json_get_token_id(p_key);

                success = (-1 != token_id);
        }

        if (success) {
                value_start = json_get_value_for_key(token_id, token_type, &size);

                success = ((NULL != value_start) && (buffer_len >= size));
        }

        if (success) {
                memcpy((void*)p_buffer, value_start, size);
                memset((void*)&(p_buffer[size]), '\0', 1);
        }

        return success;
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */





