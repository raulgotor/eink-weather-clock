/*!
 *******************************************************************************
 * @file spi.h
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

#ifndef SPI_H
#define SPI_H

/*
 *******************************************************************************
 * Public Macros                                                               *
 *******************************************************************************
 */

#define SPI_CLK                         (17)

#define SPI_MOSI                        (33)
#define SPI_CS                          (16)
#define SPI_RST                         (26) //TODO:
#define SPI_BUSY                        (12) //TODO: right pin
#define SPI_DC                          (27)



/*
 *******************************************************************************
 * Public Data Types                                                           *
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Public Constants          zx                                                  *
 *******************************************************************************
 */


/*
 *******************************************************************************
 * Public Function Prototypes                                                  *
 *******************************************************************************
 */

bool spi_init(void);

//! @brief Wrapper function for generic transfer function with handle
bool eink_spi_xfer(uint8_t const * const rx_buffer, size_t const size);



#endif //SPI_H

