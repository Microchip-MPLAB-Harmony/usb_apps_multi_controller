/*
 * Instance header file for PIC32CK2051GC01144
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2024-04-02T09:16:01Z */
#ifndef _PIC32CKGC01_SERCOM3_INSTANCE_
#define _PIC32CKGC01_SERCOM3_INSTANCE_


/* ========== Instance Parameter definitions for SERCOM3 peripheral ========== */
#define SERCOM3_CLK_REDUCTION                    (1)        /* Reduce clock options to pin 1 for SPI and USART */
#define SERCOM3_DMA                              (1)        /* DMA support implemented? */
#define SERCOM3_DMAC_ID_RX                       (11)       /* Index of DMA RX trigger */
#define SERCOM3_DMAC_ID_TX                       (12)       /* Index of DMA TX trigger */
#define SERCOM3_FIFO_IMPLEMENTED                 (1)        /* FIFO Rx/Tx implemented? */
#define SERCOM3_FIFO_SIZE                        (8)        /* Rx-Tx FIFO size in bytes */
#define SERCOM3_FSYNC_IMPLEMENTED                (1)        /* SPI Frame Synch mode implemented? */
#define SERCOM3_GCLK_ID_CORE                     (22)       
#define SERCOM3_GCLK_ID_SLOW                     (18)       
#define SERCOM3_I2C_0_INT_SRC                    (62)       /* USART/SPI/I2C Error */
#define SERCOM3_I2C_1_INT_SRC                    (65)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM3_I2C_2_INT_SRC                    (66)       /* USART Receive Start/ SPI Slave Select Low/ I2C TX FIFO Empty */
#define SERCOM3_I2C_3_INT_SRC                    (67)       /* USART Clear To Send Input Change/ I2C RX FIFO Full */
#define SERCOM3_INSTANCE_ID                      (43)       /* Instance index for SERCOM3 */
#define SERCOM3_MCLK_ID_APB                      (74)       /* Index for SERCOM3 APB clock */
#define SERCOM3_PAC_ID                           (43)       /* Index for SERCOM3 registers write protection */
#define SERCOM3_SPI                              (1)        /* SPI mode implemented? */
#define SERCOM3_SPI_RX_INT_SRC                   (65)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM3_SPI_TX_COMPLETE_INT_SRC          (64)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM3_SPI_TX_READY_INT_SRC             (63)       /* USART-SPI Data Register Empty/ I2C Stop Received */
#define SERCOM3_TWIM                             (1)        /* TWI Master mode implemented? */
#define SERCOM3_TWIS                             (1)        /* TWI Slave mode implemented? */
#define SERCOM3_ULTRA_IMPLEMENTATION             (0)        /* ULTRA platform compatibility? */
#define SERCOM3_USART                            (1)        /* USART mode implemented? */
#define SERCOM3_USART_AUTOBAUD                   (1)        /* USART autobaud implemented? */
#define SERCOM3_USART_ERROR_INT_SRC              (62)       /* USART/SPI/I2C Error */
#define SERCOM3_USART_IRDA                       (1)        /* USART IrDA implemented? */
#define SERCOM3_USART_ISO7816                    (1)        /* USART ISO7816 mode implemented? */
#define SERCOM3_USART_LIN_MASTER                 (1)        /* USART LIN Master mode implemented? */
#define SERCOM3_USART_RS485                      (1)        /* USART RS485 mode implemented? */
#define SERCOM3_USART_RX_INT_SRC                 (65)       /* USART-SPI Receive Complete/ I2C Data Ready */
#define SERCOM3_USART_TX_COMPLETE_INT_SRC        (64)       /* USART-SPI Transmit Complete/ I2C Address Match */
#define SERCOM3_USART_TX_READY_INT_SRC           (63)       /* USART-SPI Data Register Empty/ I2C Stop Received */

#endif /* _PIC32CKGC01_SERCOM3_INSTANCE_ */
