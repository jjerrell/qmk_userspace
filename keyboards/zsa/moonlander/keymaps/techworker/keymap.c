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
// clang-format on

#ifdef MOONLANDER_USER_LEDS
layer_state_t layer_state_set_keymap(layer_state_t state) {
    // All off by default
    ML_LED_L1(false);
    ML_LED_L2(false);
    ML_LED_L3(false);
    ML_LED_R1(false);
    ML_LED_R2(false);
    ML_LED_R3(false);
    
    // Enable LEDs based on layer activations
    if (IS_LAYER_ON_STATE(state, _LOWER)) {
        ML_LED_L1(true);
        ML_LED_R3(true);
    }

    if (IS_LAYER_ON_STATE(state, _RAISE)) {
        ML_LED_L2(true);
        ML_LED_R2(true);
    }
    
    if (IS_LAYER_ON_STATE(state, _ADJUST)) {
        ML_LED_L3(true);
        ML_LED_R1(true);
    }
    
    return state;
}
#endif // MOONLANDER_USER_LEDS

#ifdef RGB_MATRIX_CUSTOM_USER
const uint8_t home_led_mapping[] = {};
const uint8_t fn_led_mapping[] = {};
const uint8_t mod_led_mapping[] = {
    // shift
    12,
    48,
    // command
    17,
    53,
    // option/alt
    22,
    58,
    // control
    8,
    44
};
const uint8_t arrow_led_mapping[] = {12, 16, 17, 22};
const uint8_t numpad_led_mapping[] = { 47, 48, 49, 52, 53, 54, 57, 58, 59, 60 };
#endif // RGB_MATRIX_CUSTOM_USER

// void housekeeping_task_user(void) {
//     if (!is_transport_connected()) {
//         // TODO: set game layer
//     }
// }
