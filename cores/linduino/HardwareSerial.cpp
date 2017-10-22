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
#include <unistd.h>
#include <termios.h>
#include "Arduino.h"
#include "HardwareSerial.h"


HardwareSerial::HardwareSerial()
{}

void HardwareSerial::begin()
{
    _peek_char = -1;

    struct termios new_tio;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    cfmakeraw( &new_tio );

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
}

void HardwareSerial::end()
{
    /* restore the former settings */
    tcsetattr( STDIN_FILENO, TCSANOW, &old_tio );
}

bool HardwareSerial::isTxEnabled(void)
{
    return 1;
}

bool HardwareSerial::isRxEnabled(void)
{
    return 1;
}

int HardwareSerial::available(void)
{
    return 1;
}

int HardwareSerial::peek(void)
{
    // this may return -1, but that's okay
    return getchar();
}

int HardwareSerial::read(void)
{
    if (_peek_char != -1) {
        auto tmp = _peek_char;
        _peek_char = -1;
        return tmp;
    }
    return getchar();
}

int HardwareSerial::availableForWrite(void)
{
    return 1;
}

void HardwareSerial::flush()
{
}

size_t HardwareSerial::write(uint8_t c)
{
    putchar(c);
    return 1;
}

HardwareSerial Serial;
