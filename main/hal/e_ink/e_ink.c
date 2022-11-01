/*!
 *******************************************************************************
 * @file e_ink.c
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
#include "drivers/EPD_2in9_V2/EPD_2in9_V2.h"
#include "lvgl/lvgl.h"
#include "hal/GUI/GUI_Paint.h"

#include "e_ink.h"

/*
 *******************************************************************************
 * Private Macros                                                              *
 *******************************************************************************
 */

#define HAL_E_INK_DISPLAY_HORIZONTAL_RES    (296)
#define HAL_E_INK_DISPLAY_VERTICAL_RES      (128)

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

static void hal_e_ink_send_image();

static void hal_e_ink_flush(
                lv_disp_drv_t * p_display_driver,
                const lv_area_t * p_area,
                lv_color_t * p_color);

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

static lv_disp_draw_buf_t m_draw_buffer;

static lv_color_t m_buffer[HAL_E_INK_DISPLAY_HORIZONTAL_RES * HAL_E_INK_DISPLAY_VERTICAL_RES];                        /*Declare a buffer for 1/10 screen size*/

static lv_disp_drv_t m_display_driver;

static uint8_t * m_canvas = NULL;



/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */


int32_t hal_e_ink_init(lv_disp_t ** pp_display)
{

        uint16_t const image_size = ((EPD_2IN9_V2_WIDTH % 8 == 0) ?
                        (EPD_2IN9_V2_WIDTH / 8 ) :
                        (EPD_2IN9_V2_WIDTH / 8 + 1)) * EPD_2IN9_V2_HEIGHT;

        int32_t result = 0;

        EPD_2IN9_V2_Init();
        EPD_2IN9_V2_Clear();


        m_canvas = (uint8_t *)malloc(image_size);

        // e-ink Hal init
        if ((NULL == m_canvas) || (NULL == pp_display) || (NULL != *pp_display)) {
                result = -1;
        } else {
                Paint_NewImage(m_canvas,
                               EPD_2IN9_V2_WIDTH,
                               EPD_2IN9_V2_HEIGHT,
                               90,
                               WHITE);

                Paint_SelectImage(m_canvas);
                Paint_Clear(WHITE);

                lv_init();

                lv_disp_draw_buf_init(
                                &m_draw_buffer,
                                m_buffer,
                                NULL,
                                (HAL_E_INK_DISPLAY_HORIZONTAL_RES *
                                 HAL_E_INK_DISPLAY_VERTICAL_RES));

                lv_disp_drv_init(&m_display_driver);
                m_display_driver.flush_cb = hal_e_ink_flush;
                m_display_driver.draw_buf = &m_draw_buffer;
                m_display_driver.hor_res = HAL_E_INK_DISPLAY_HORIZONTAL_RES;
                m_display_driver.ver_res = HAL_E_INK_DISPLAY_VERTICAL_RES;
                m_display_driver.antialiasing = 0;
                lv_disp_drv_register(&m_display_driver);

                *pp_display = lv_disp_drv_register(&m_display_driver);

        }

        return result;
}

/*
 *******************************************************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

static void hal_e_ink_send_image()
{
        EPD_2IN9_V2_Display_Partial(m_canvas);

}

static void hal_e_ink_flush(
                lv_disp_drv_t * p_display_driver,
                const lv_area_t * p_area,
                lv_color_t * p_color)
{
        int32_t x, y;

        /*It's a very slow but simple implementation.
         *`set_pixel` needs to be written by you to a set pixel on the screen*/

        for(y = p_area->y1; y <= p_area->y2; y++) {
                for(x = p_area->x1; x <= p_area->x2; x++) {

                        bool color;

                        if (p_color->full != 0) {
                                color = true;
                        } else {
                                color = false;
                        }

                        Paint_SetPixel(x, y, color);
                        p_color++;
                }
        }

        hal_e_ink_send_image();
        lv_disp_flush_ready(p_display_driver);
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */
