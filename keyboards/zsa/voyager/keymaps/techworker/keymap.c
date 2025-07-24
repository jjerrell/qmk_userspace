// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = LAYOUT_modifiers_wrapper(
        KC_GRV,  _________________WORKMAN_L1________________,        _________________WORKMAN_R1________________, KC_BSLS,
        CW_TOGG, _________________WORKMAN_L2________________,        _________________WORKMAN_R2________________, KC_QUOT,
        KC_LSFT, _________________WORKMAN_L3________________,        _________________WORKMAN_R3________________, KC_RSFT,
        TOG_LWR, _______, _______, _______, _______, QK_LEAD,        KC_SEC1, _______, _______, _______, _______, TOG_RSE
    ),
    [_LOWER] = LAYOUT_modifiers_wrapper(
        _______, _________________LOWER_L1__________________,        _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________,        _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________,        _________________LOWER_R3__________________, _______,
        KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,    KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12
    ),
    [_RAISE] = LAYOUT_modifiers_wrapper(
        _______, _________________RAISE_L1__________________,        _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________,        _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________,        _________________RAISE_R3__________________, _______,
        _______, _______________UNICODE_MOJIS_______________,        KC_NORM, KC_SUPR, KC_SCPT, KC_AUSS, KC_WIDE, KC_BLCK
    ),
    [_ADJUST] = LAYOUT_base_wrapper(
        _______, _________________ADJUST_L1_________________,        _________________ADJUST_R1_________________, _______,
        _______, _________________ADJUST_L2_________________,        _________________ADJUST_R2_________________, KC_RGBT,
        _______, _________________ADJUST_L3_________________,        _________________ADJUST_R3_________________, RGB_TOG,
        _______, ___________________BLANK___________________,        ___________________BLANK___________________, RM_TOGG
    )
};
// clang-format on

#ifdef VOYAGER_USER_LEDS
layer_state_t layer_state_set_keymap(layer_state_t state) {
    // All indicators OFF
    STATUS_LED_1(false);
    STATUS_LED_2(false);
    STATUS_LED_3(false);
    STATUS_LED_4(false);

    switch (get_highest_layer(state)) {
        case _LOWER:
            STATUS_LED_2(true); // Left-bottom indicator ON
            STATUS_LED_4(true); // Right-bottom indicator ON
            break;
        case _RAISE:
            STATUS_LED_1(true); // Left-top indicator ON
            STATUS_LED_3(true); // Right-top indicator ON
            break;
        case _ADJUST:
            // All indicators ON
            STATUS_LED_1(true);
            STATUS_LED_2(true);
            STATUS_LED_3(true);
            STATUS_LED_4(true);
            break;
        default:
            break;
    }

    return state;
}
#endif

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
const uint8_t led_mapping[RGBLIGHT_LED_COUNT] = {0, 6, 12, 18, 24, 25, 31, 37, 43, 49, 50, 51};
#endif

#ifdef RGB_MATRIX_CUSTOM_USER
const uint8_t home_led_mapping[] = {}; // Non-empty requires HOME_LED_COUNT definiton
const uint8_t fn_led_mapping[] = {}; // Non-empty requires HOME_LED_COUNT definiton
const uint8_t mod_led_mapping[] = {24, 29, 30, 31};
const uint8_t arrow_led_mapping[] = {32, 33, 34, 35, 71, 70, 69, 68};
const uint8_t numpad_led_mapping[] = {36, 37, 38, 39};
#endif // RGB_MATRIX_CUSTOM_USER