/*
 HardwareSerial.h - Hardware serial library for Wiring
 Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

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

 Modified 28 September 2010 by Mark Sproul
 Modified 14 August 2012 by Alarus
 Modified 3 December 2013 by Matthijs Kooijman
 Modified 18 December 2014 by Ivan Grokhotkov (esp8266 platform support)
 Modified 31 March 2015 by Markus Sattler (rewrite the code for UART0 + UART1 support in ESP8266)
 Modified 25 April 2015 by Thomas Flayols (add configuration different from 8N1 in ESP8266)
 */

#ifndef HardwareSerial_h
#define HardwareSerial_h

#include <inttypes.h>
#include <termios.h>
#include "Stream.h"

class HardwareSerial: public Stream
{
public:
    HardwareSerial();
    virtual ~HardwareSerial() {}

    void begin();
    void end();

    int available(void) override;
    int peek(void) override;
    int read(void) override;
    int availableForWrite(void);
    void flush(void) override;
    size_t write(uint8_t) override;
    inline size_t write(unsigned long n)
    {
        return write((uint8_t) n);
    }
    inline size_t write(long n)
    {
        return write((uint8_t) n);
    }
    inline size_t write(unsigned int n)
    {
        return write((uint8_t) n);
    }
    inline size_t write(int n)
    {
        return write((uint8_t) n);
    }
    using Print::write; // pull in write(str) and write(buf, size) from Print
    operator bool() const;

    bool isTxEnabled(void);
    bool isRxEnabled(void);
    int  baudRate(void);

protected:
    int _peek_char = -1;
    struct termios old_tio;
};

extern HardwareSerial Serial;

#endif
