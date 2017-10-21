/*
 uart.cpp - esp8266 UART HAL

 Copyright (c) 2014 Ivan Grokhotkov. All rights reserved.
 This file is part of the esp8266 core for Arduino environment.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

 */


/**
 *  UART GPIOs
 *
 * UART0 TX: 1 or 2
 * UART0 RX: 3
 *
 * UART0 SWAP TX: 15
 * UART0 SWAP RX: 13
 *
 *
 * UART1 TX: 7 (NC) or 2
 * UART1 RX: 8 (NC)
 *
 * UART1 SWAP TX: 11 (NC)
 * UART1 SWAP RX: 6 (NC)
 *
 * NC = Not Connected to Module Pads --> No Access
 *
 */
#include "Arduino.h"
#include "uart.h"
#include <stdio.h>
#include <assert.h>

void uart_write_char(uart_t* uart, char c)
{
    putchar( c );
}

void uart_write(uart_t* uart, const char* buf, size_t size)
{
    while(size--) {
        uart_write_char(uart, *buf++);
    }
}

int uart_read_char(uart_t* uart)
{
    if (!uart_rx_available(uart)) {
        return -1;
    }
    return getchar();
}

size_t uart_rx_available(uart_t* uart)
{
    return 1;
}

size_t uart_tx_free(uart_t* uart)
{
    return 1;
}

void uart_wait_tx_empty(uart_t* uart)
{
}

void uart_flush(uart_t* uart)
{
}

void uart_set_baudrate(uart_t* uart, int baud_rate)
{
}

int uart_get_baudrate(uart_t* uart)
{
    return 1;
}

uart_t* uart_init(int uart_nr, int baudrate, int config, int mode, int tx_pin)
{
    return NULL;
}

void uart_uninit(uart_t* uart)
{
    if(uart == NULL) {
        return;
    }
}

void uart_swap(uart_t* uart, int tx_pin)
{
}

void uart_set_tx(uart_t* uart, int tx_pin)
{
}

void uart_set_pins(uart_t* uart, int tx, int rx)
{
}

bool uart_tx_enabled(uart_t* uart)
{
    return true;
}

bool uart_rx_enabled(uart_t* uart)
{
    return true;
}


void uart_set_debug(int uart_nr)
{
}

int uart_get_debug()
{
    return 0;
}
