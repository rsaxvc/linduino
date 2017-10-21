/*
 main.cpp - platform initialization and context switching
 emulation

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

//This may be used to change user task stack size:
//#define CONT_STACKSIZE 4096
#include <Arduino.h>
#include "Schedule.h"
#include <core_version.h>
#include <sched.h>

extern "C" {
extern const uint32_t __attribute__((section(".ver_number"))) core_version = ARDUINO_LINDUINO_GIT_VER;
const char* core_release = 
#ifdef ARDUINO_LINDUINO_RELEASE
    ARDUINO_LINDUINO_RELEASE;
#else
    NULL;
#endif
} // extern "C"

extern "C" void ets_update_cpu_frequency(int freqmhz);
void initVariant() __attribute__((weak));
void initVariant() {
}

extern void loop();
extern void setup();

extern void (*__init_array_start)(void);
extern void (*__init_array_end)(void);

extern "C" void yield(void)
{
sched_yield();
}

static void do_global_ctors(void) {
    void (**p)(void) = &__init_array_end;
    while (p != &__init_array_start)
        (*--p)();
}

extern "C" void _start(void) {
    init();

    initVariant();

    do_global_ctors();

    setup();
    while(1) {
        loop();
        run_scheduled_functions();
        sched_yield();
    }
}
