/*
 * LiquidCrystal_I2C backward compatible API
 *
 * Copyright (C) 2019 Damian Wrobel <dwrobel@ertelnet.rybnik.pl>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once
#include "LiquidCrystal_PCF8574.h"

class LiquidCrystal_I2C : public LiquidCrystal_PCF8574 {
public:
    LiquidCrystal_I2C(const uint8_t addr, const uint8_t cols, const uint8_t rows, const uint8_t dotsize = LCD_5x8DOTS)
      : LiquidCrystal_PCF8574(addr)
      , cols(cols)
      , rows(rows)
      , dotsize(dotsize) {
    }

    void init() {
      begin(cols, rows, dotsize);
    }

    void backlight() {
        setBacklight(255);
    }

    void noBacklight() {
        setBacklight(0);
    }

protected:
  const uint8_t cols;
  const uint8_t rows;
  const uint8_t dotsize;
};
