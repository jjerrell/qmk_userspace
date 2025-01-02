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

#include QMK_KEYBOARD_H
#include "version.h"
#include "jjerrell.h"
#include "layouts.h"
#include "led_custom.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = KEYMAP_moonlander_modifiers(
        KC_ESC,  _________________NUMBERS_L_________________, KC_ARROW,    KC_MINS, _________________NUMBERS_R_________________, KC_EQL,
        KC_TAB,  _________________WORKMN_L1_________________, KC_LPRN,     KC_RPRN, _________________WORKMN_R1_________________, KC_BSLS,
        CW_TOGG, _________________WORKMN_L2_________________, KC_LBRC,     KC_RBRC, _________________WORKMN_R2_________________, KC_QUOT,
        KC_LSFT, _________________WORKMN_L3_________________,                       _________________WORKMN_R3_________________, KC_RSFT,
        QK_LEAD, XXXXXXX, XXXXXXX, KC_UP, KC_LEFT,            XXXXXXX,     KC_GAME,         KC_RIGHT, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_SPC, KC_BSPC, QK_LEAD,     DF_HOME, KC_TAB, KC_ENTER
    ),

    [_HOME] = KEYMAP_moonlander_win_modifiers(
        KC_ESC,  _________________NUMBERS_L_________________, KC_ARROW,    KC_MINS, _________________NUMBERS_R_________________, KC_EQL,
        KC_TAB,  _________________WORKMN_L1_________________, KC_LPRN,     KC_RPRN, _________________WORKMN_R1_________________, KC_BSLS,
        CW_TOGG, _________________WORKMN_L2_________________, KC_LBRC,     KC_RBRC, _________________WORKMN_R2_________________, KC_QUOT,
        KC_LSFT, _________________WORKMN_L3_________________,                       _________________WORKMN_R3_________________, KC_RSFT,
        QK_LEAD, XXXXXXX, XXXXXXX, KC_UP, KC_LEFT,            XXXXXXX,     KC_GAME,         KC_RIGHT, KC_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
                                             KC_SPC, KC_BSPC, QK_LEAD,     DF_WORK, KC_TAB, KC_ENTER
    ),

    [_LOWER] = KEYMAP_moonlander_modifiers(
        _______, _______________________FROW_L_______________________,    _______________________FROW_R_______________________, _______,
        _______, _________________LOWER_L1__________________, _______,    _______, _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________, _______,    _______, _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________,                      _________________LOWER_R3__________________, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,    _______,          _____________LOWER_R4_____________, _______,
                                            _______, KC_BSPC, _______,    _______, KC_TAB,  KC_ENTER
    ),

    [_RAISE] = KEYMAP_moonlander_modifiers(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _________________RAISE_L1__________________, _______,    _______, _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________, _______,    _______, _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________,                      _________________RAISE_R3__________________, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            KC_SPC,  KC_BSPC, _______,    _______, KC_TAB,  _______
    ),

    [_ADJUST] = KEYMAP_moonlander_layers(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _________________ADJUST_L1_________________, _______,    _______, _________________ADJUST_R1_________________, _______,
        _______, _________________ADJUST_L2_________________, _______,    _______, _________________ADJUST_R2_________________, _______,
        _______, _________________ADJUST_L3_________________,                      _________________ADJUST_R3_________________, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),

    [_GAME] = KEYMAP_moonlander(
        KC_ESC,  _________________NUMBERS_L_________________, XXXXXXX,     XXXXXXX, _________________NUMBERS_L_________________, KC_BSPC,
        KC_TAB,  _________________QWERTY_L1_________________, XXXXXXX,     XXXXXXX, _________________QWERTY_R1_________________, KC_BSLS,
        KC_EQL,  _________________QWERTY_L2_________________, XXXXXXX,     XXXXXXX, _________________QWERTY_R2_________________, KC_QUOT,
        KC_LSFT, _________________QWERTY_L3_________________,                       _________________QWERTY_R3_________________, XXXXXXX,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,          KC_ESC,      KC_GAME,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
                                             KC_SPC, KC_PGDN, KC_PGUP,     XXXXXXX, XXXXXXX, KC_ENT
    )
};
// clang-format on

const uint8_t RGB_LIST_ARROWS[] = {
    12,
    16,
    17,
    22
};

const uint8_t RGB_LIST_NUMPAD[] = {
    47,
    48,
    49,
    52,
    53,
    54,
    57,
    58,
    59,
    60
};

/* Order is important. This list will be explicitly accessed by index */
const uint8_t RGB_LIST_MODIFIERS[] = {
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

void moonlander_led_all(bool status) {
    ML_LED_L1(status);
    ML_LED_L2(status);
    ML_LED_L3(status);
    ML_LED_R1(status);
    ML_LED_R2(status);
    ML_LED_R3(status);
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    moonlander_led_all(false);
    switch (get_highest_layer(state)) {
        case _LOWER:
            ML_LED_L1(true);
            ML_LED_R3(true);
            break;
        case _RAISE:
            ML_LED_L2(true);
            ML_LED_R2(true);
            break;
        case _ADJUST:
            ML_LED_L3(true);
            ML_LED_R1(true);
            break;
        default:
            break;
    }
    return state;
}

void set_thumbs_rgb(uint8_t rl, uint8_t gl, uint8_t bl, uint8_t rr, uint8_t gr, uint8_t br) {
    rgb_matrix_set_color(32, rl, gl, bl);
    rgb_matrix_set_color(33, rl, gl, bl);
    rgb_matrix_set_color(34, rl, gl, bl);
    rgb_matrix_set_color(35, rl, gl, bl);
    rgb_matrix_set_color(68, rr, gr, br);
    rgb_matrix_set_color(69, rr, gr, br);
    rgb_matrix_set_color(70, rr, gr, br);
    rgb_matrix_set_color(71, rr, gr, br);
}

bool rgb_indicators_process_layer_keymap(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color_all(RGB_OFF);
    switch (get_highest_layer(layer_state)) {
        case _WORKMAN:
        case _QWERTY:
            // Thumb keys
            set_thumbs_rgb(RGB_WHITE, RGB_WHITE);
            return true;
            break;
        case _HOME:
            // Thumb keys
            set_thumbs_rgb(HSV_GREEN, HSV_GREEN);
            return true;
            break;
        case _LOWER:
            // Thumb keys
            set_thumbs_rgb(RGB_GREEN, RGB_RED);
            return true;
            break;
        case _RAISE:
            // Thumb keys
            set_thumbs_rgb(RGB_RED, RGB_GREEN);
            return true;
            break;
        case _ADJUST:
            // Thumb keys
            set_thumbs_rgb(RGB_GREEN, RGB_GREEN);
            return true;
            break;
        case _GAME:
            // Thumbs
            set_thumbs_rgb(RGB_RED, RGB_OFF);
            // Esc & Tab
            rgb_matrix_set_color(0, RGB_RED);
            rgb_matrix_set_color(1, HSV_AZURE);
            // Reload
            rgb_matrix_set_color(21, RGB_RED);
            // Mods
            rgb_matrix_set_color(3, RGB_ORANGE);
            rgb_matrix_set_color(4, RGB_ORANGE);
            rgb_matrix_set_color(24, RGB_ORANGE);
            // Arrows
            rgb_matrix_set_color(11, RGB_GREEN);
            rgb_matrix_set_color(7, RGB_GREEN);
            rgb_matrix_set_color(12, RGB_GREEN);
            rgb_matrix_set_color(17, RGB_GREEN);
            return false;
            break;
        default:
            return true;
            break;
    }
}
