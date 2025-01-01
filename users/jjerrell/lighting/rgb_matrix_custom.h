// Copyright (C) 2025 Jerrell, Jacob <@jjerrell>
//
// This file is part of qmk_firmware.
//
// qmk_firmware is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// qmk_firmware is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include QMK_KEYBOARD_H
#include "jjerrell.h"

const uint8_t RGB_LIST_ARROWS[4];
const uint8_t RGB_LIST_NUMPAD[10];
const uint8_t RGB_LIST_MODIFIERS[8];

#define INDEX_LSFT   0
#define INDEX_RSFT   1

#define INDEX_LCMD   2
#define INDEX_RCMD   3

#define INDEX_LOPT   4
#define INDEX_ROPT   5

#define INDEX_LCTL   6
#define INDEX_RCTL   7

bool rgb_indicators_process_layer_keymap(uint8_t layer, uint8_t active_mods);
bool rgb_indicators_process_layer_user(uint8_t layer, uint8_t active_mods);

void keyboard_post_init_keymap(void);
