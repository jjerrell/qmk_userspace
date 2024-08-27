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


enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = KEYMAP_moonlander_modifiers(
        KC_ESC,  _________________NUMBERS_L_________________, KC_ARROW,    KC_MINS, _________________NUMBERS_R_________________, KC_EQL,
        KC_TAB,  _________________WORKMN_L1_________________, KC_LPRN,     KC_RPRN, _________________WORKMN_R1_________________, KC_BSLS,
        CW_TOGG, _________________WORKMN_L2_________________, KC_LBRC,     KC_RBRC, _________________WORKMN_R2_________________, KC_QUOT,
        KC_LSFT, _________________WORKMN_L3_________________,                       _________________WORKMN_R3_________________, KC_RSFT,
        QK_LEAD, XXXXXXX, XXXXXXX, KC_UP, KC_LEFT,            XXXXXXX,     XXXXXXX,         KC_RIGHT, KC_DOWN, XXXXXXX, XXXXXXX, KC_GAME,
                                             KC_SPC, KC_BSPC, QK_LEAD,     CW_TOGG, KC_TAB, KC_ENTER
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
           VRSN, _________________ADJUST_L3_________________,                      _________________ADJUST_R3_________________, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    )
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
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
