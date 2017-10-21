/*
 HardwareSerial.cpp - esp8266 UART support

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

 Modified 31 March 2015 by Markus Sattler (rewrite the code for UART0 + UART1 support in ESP8266)
 Modified 25 April 2015 by Thomas Flayols (add configuration different from 8N1 in ESP8266)
 Modified 3 May 2015 by Hristo Gochkov (change register access methods)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "HardwareSerial.h"


HardwareSerial::HardwareSerial()
{}

void HardwareSerial::begin(unsigned long baud, SerialConfig config, SerialMode mode, uint8_t tx_pin)
{
    _peek_char = -1;
}

void HardwareSerial::end()
{
}

bool HardwareSerial::isTxEnabled(void)
{
    return uart_tx_enabled(NULL);
}

bool HardwareSerial::isRxEnabled(void)
{
    return uart_rx_enabled(NULL);
}

int HardwareSerial::available(void)
{
    return uart_rx_enabled(NULL);
}

int HardwareSerial::peek(void)
{
    // this may return -1, but that's okay
    return uart_read_char(NULL);
}

int HardwareSerial::read(void)
{
    if (_peek_char != -1) {
        auto tmp = _peek_char;
        _peek_char = -1;
        return tmp;
    }
    return uart_read_char(NULL);
}

int HardwareSerial::availableForWrite(void)
{
    if(!uart_tx_enabled(NULL)) {
        return 0;
    }

    return static_cast<int>(uart_tx_free(NULL));
}

void HardwareSerial::flush()
{
    if(!uart_tx_enabled(NULL)) {
        return;
    }

    uart_wait_tx_empty(NULL);
}

size_t HardwareSerial::write(uint8_t c)
{
    if(!uart_tx_enabled(NULL)) {
        return 0;
    }

    uart_write_char(NULL, c);
    return 1;
}

HardwareSerial::operator bool() const
{
    return 1;
}


HardwareSerial Serial;
