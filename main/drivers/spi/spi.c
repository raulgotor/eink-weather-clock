/*!
 *******************************************************************************
 * @file spi.c
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

#include <driver/spi_master.h>
#include <driver/gpio.h>
#include <esp_log.h>
#include <string.h>

#include "spi.h"

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

static spi_bus_config_t const m_buscfg = {
                .miso_io_num = -1,
                .mosi_io_num = SPI_MOSI,
                .sclk_io_num = SPI_CLK,
                .quadwp_io_num = -1,
                .quadhd_io_num = -1,
                .max_transfer_sz= 296 * 128 * 2,//16*320*2+8
};
static spi_device_interface_config_t const m_spi_interface_config={
                .clock_speed_hz = 10 * 1000 * 1000,
                .mode = 0,
                .spics_io_num = SPI_CS,
                .queue_size = 7,
                //.pre_cb=lcd_spi_pre_transfer_callback,
};



/*
 *******************************************************************************
 * Private Function Prototypes                                                 *
 *******************************************************************************
 */

//! @brief Generic transfer function for MAX6675
static bool spi_xfer(uint8_t const * const tx_buffer,
                     size_t const size,
                     spi_device_handle_t const handle);


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

static spi_device_handle_t m_spi_device_handle;

/*
 *******************************************************************************
 * Public Function Bodies                                                      *
 *******************************************************************************
 */


void lcd_spi_pre_transfer_callback(spi_transaction_t *t)
{
        int dc=(int)t->user;
        gpio_set_level(21, dc);
}

bool spi_init(void)
{

        esp_err_t esp_result = ESP_OK;

        esp_result = spi_bus_initialize(HSPI_HOST, &m_buscfg, SPI_DMA_CH_AUTO);

        if (ESP_OK == esp_result) {

                gpio_set_direction(SPI_RST, GPIO_MODE_OUTPUT);
                gpio_set_direction(SPI_BUSY, GPIO_MODE_INPUT);
                gpio_set_direction(SPI_CS, GPIO_MODE_OUTPUT);
                gpio_set_direction(SPI_DC, GPIO_MODE_OUTPUT);

                esp_result = spi_bus_add_device(HSPI_HOST, &m_spi_interface_config, &m_spi_device_handle);
        }


        return (ESP_OK == esp_result);
}

//TODO: eink naming doesn't belong here
/*!
 * @brief Wrapper function for generic transfer function with handle
 *
 * @param[out]          p_rx_buffer         Pointer to a buffer where to read
 *                                          the data to
 * @param[in]           size                Number of bytes to read
 *
 * @return              bool                Operation result*
 */
bool eink_spi_xfer(uint8_t const * const rx_buffer, size_t const size)
{
        return spi_xfer(rx_buffer, size, m_spi_device_handle);
}

/*
 *************************************º******************************************
 * Private Function Bodies                                                     *
 *******************************************************************************
 */

/*!
 * @brief Generic SPI transfer function
 *
 * @param[out]          p_rx_buffer         Pointer to a buffer where to read
 *                                          the data to
 * @param[in]           size                Number of bytes to read
 * @param[in]           handle              Handle to an esp-idf spi device
 *
 * @return              bool                Operation result*
 */
static bool spi_xfer(uint8_t const * const tx_buffer,
                     size_t const size,
                     spi_device_handle_t const handle)
{

        bool success = (NULL != tx_buffer) && (0 != size);
        esp_err_t esp_result;

        if (success) {

                spi_transaction_t t;
                memset(&t, 0, sizeof(t));       //Zero out the transaction
                t.length = size * 8;                     //Command is 8 bits
                t.tx_buffer = tx_buffer;               //The data is the cmd itself

                //t.user=(void*)0;                //D/C needs to be set to 0
                esp_result = spi_device_polling_transmit(m_spi_device_handle, &t);  //Transmit!

                success = (ESP_OK == esp_result);
        }

        return success;
}

/*
 *******************************************************************************
 * Interrupt Service Routines / Tasks / Thread Main Functions                  *
 *******************************************************************************
 */


