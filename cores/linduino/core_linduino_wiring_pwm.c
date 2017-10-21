/*
  pwm.c - analogWrite implementation for esp8266

  Copyright (c) 2015 Hristo Gochkov. All rights reserved.
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
#include "pins_arduino.h"

uint32_t pwm_get_mask(uint16_t value){
    return 0;
}

void prep_pwm_steps(){
}

extern void __analogWrite(uint8_t pin, int value) {
}

extern void __analogWriteFreq(uint32_t freq){
}

extern void __analogWriteRange(uint32_t range){
}

extern void analogWrite(uint8_t pin, int val) __attribute__ ((weak, alias("__analogWrite")));
extern void analogWriteFreq(uint32_t freq) __attribute__ ((weak, alias("__analogWriteFreq")));
extern void analogWriteRange(uint32_t range) __attribute__ ((weak, alias("__analogWriteRange")));
