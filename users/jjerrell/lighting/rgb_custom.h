/* Copyright 2024 Jacob Jerrell <@jjerrell>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jjerrell.h"

bool rgb_indicators_process_keymap(uint8_t led_min, uint8_t led_max);
bool rgb_indicators_process_layer_user(uint8_t layer, uint8_t active_mods);
bool rgb_indicators_process_modifiers_keymap(uint8_t active_mods, uint8_t layer);
bool rgb_indicators_process_modifiers_user(uint8_t active_mods, uint8_t layer);

const uint8_t RGB_LIST_ARROWS[] = {
#if defined(KEYBOARD_planck_ez_glow)
    2, 13, 14, 15
#elif defined(KEYBOARD_moonlander)
    12, 16, 17, 22
#endif
};

const uint8_t RGB_LIST_NUMPAD[] = {
#if defined(KEYBOARD_planck_ez_glow)
    8,  9,  10, 20, 21, 22,
    32, 33, 34, 43
#elif defined(KEYBOARD_moonlander)
    47, 48, 49, 52, 53, 54,
    57, 58, 59, 60
#endif
};

// clang-format off
#define INDEX_LSFT   0
#define INDEX_RSFT   1
#define INDEX_CWORD  2

#define INDEX_LCMD   3
#define INDEX_RCMD   4

#define INDEX_LOPT   5
#define INDEX_ROPT   6

#define INDEX_LCTL   7
#define INDEX_RCTL   8
// clang-format on

/* Order is important. This list will be explicitly accessed by index */
const uint8_t RGB_LIST_MODIFIERS[] = {
#if defined(KEYBOARD_planck_ez_glow)
    // shift
    13, // 0
    22, // 1
    // caps word
    39,
    // command
    14, 21,
    // option/alt
    15, 20,
    // control
    24, 35
#elif defined(KEYBOARD_moonlander)
    // shift
    12, 48,
    // caps word
    2,
    // command
    17, 53,
    // option/alt
    22, 58,
    // control
    8, 44
#endif
};
