/* 
  digital.c - wiring digital implementation for esp8266

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
#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pins_arduino.h"

extern void __pinMode(uint8_t pin, uint8_t mode) {
}

extern void __digitalWrite(uint8_t pin, uint8_t val) {
}

extern int __digitalRead(uint8_t pin) {
  return 0;
}

void initPins() {
}

extern void pinMode(uint8_t pin, uint8_t mode) __attribute__ ((weak, alias("__pinMode")));
extern void digitalWrite(uint8_t pin, uint8_t val) __attribute__ ((weak, alias("__digitalWrite")));
extern int digitalRead(uint8_t pin) __attribute__ ((weak, alias("__digitalRead")));

