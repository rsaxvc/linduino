/* 
 core_linduino_wiring.c - implementation of Wiring API for esp8266

 Copyright (c) 2017 Richard Allen. All rights reserved.
 This file is part of the linduino core for Arduino environment.
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

#include "wiring_private.h"

static struct timeval tv_start;

#include <unistd.h>
void delay(unsigned long ms) {

    usleep(1000*ms);
}

#include <sys/time.h>
unsigned long millis() {
    struct timeval tv;
    gettimeofday(&tv,NULL);

    if( tv_start.tv_sec == 0 && tv_start.tv_usec == 0 )
        tv_start = tv;

    return (tv.tv_sec-tv_start.tv_sec) * 1000 + (tv.tv_usec-tv_start.tv_usec) / 1000;
}

unsigned long micros() {
    struct timeval tv;
    gettimeofday(&tv,NULL);

    if( tv_start.tv_sec == 0 && tv_start.tv_usec == 0 )
        tv_start = tv;

    return (tv.tv_sec-tv_start.tv_sec) * 1000000 + tv.tv_usec - tv_start.tv_usec;
}

#include <unistd.h>
void delayMicroseconds(unsigned int us) {
    usleep(us);
}

void init() {
    initPins();
}
