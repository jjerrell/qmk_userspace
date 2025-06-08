/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#include "keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = LAYOUT_moonlander_mods(
        KC_GRV,  ________________NUMBER_LEFT________________,       ________________NUMBER_RIGHT_______________, KC_EQL,
        KC_TAB,  _________________WORKMAN_L1________________,       _________________WORKMAN_R1________________, KC_BSLS,
        CW_TOGG, _________________WORKMAN_L2________________,       _________________WORKMAN_R2________________, KC_QUOT,
        KC_LSFT, _________________WORKMAN_L3________________,       _________________WORKMAN_R3________________, KC_RSFT
    ),
    [_LOWER] = LAYOUT_moonlander_mods(
        KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,    KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
        _______, _________________LOWER_L1__________________,       _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________,       _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________,       _________________LOWER_R3__________________, _______
    ),
    [_RAISE] = LAYOUT_moonlander_mods(
        _______, _______________UNICODE_MOJIS_______________,       KC_NORM, KC_SUPR, KC_SCPT, KC_AUSS, KC_WIDE, KC_BLCK,
        _______, _________________RAISE_L1__________________,       _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________,       _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________,       _________________RAISE_R3__________________, _______
    ),
    [_ADJUST] = LAYOUT_moonlander_base(
        _______, ___________________BLANK___________________,       ___________________BLANK___________________, _______,
        _______, _________________ADJUST_L1_________________,       _________________ADJUST_R1_________________, KC_RGBT,
        _______, _________________ADJUST_L2_________________,       _________________ADJUST_R2_________________, RGB_TOG,
        _______, _________________ADJUST_L3_________________,       _________________ADJUST_R3_________________, RM_TOGG
    )
};

#ifdef RGB_MATRIX_ENABLE
#    if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
const uint8_t led_mapping[RGBLIGHT_LED_COUNT] = {0,  1,  2,  3,  4,  9,  14, 19, 24, 29, 30, 31, 32, 33, 34, 35,
                                                 71, 70, 69, 68, 67, 66, 65, 60, 55, 50, 45, 40, 39, 38, 37, 36};
#    endif
#endif // RGB_MATRIX_ENABLE

// void housekeeping_task_user(void) {
//     if (!is_transport_connected()) {
//         // TODO: set game layer
//     }
// }