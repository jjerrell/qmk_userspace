// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_WORKMAN] = LAYOUT_4x12_mods(
         _________________WORKMAN_L1________________, KC_ARRW,  KC_MINS, _________________WORKMAN_R1________________,
         _________________WORKMAN_L2________________, KC_LPRN,  KC_RPRN, _________________WORKMAN_R2________________,
         _________________WORKMAN_L3________________, KC_LBRC,  KC_RBRC, _________________WORKMAN_R3________________,
         TOG_LWR, _______, _______, QK_LEAD, LWR_BSP, SFT_SPC,  XXXXXXX, RSE_ENT, KC_SEC1, _______, _______, TOG_RSE
     ), // Has F-Keys in non-standard locations
     [_LOWER] = LAYOUT_4x12_mods(
         _________________LOWER_L1__________________, KC_F1,   KC_F2,   _________________LOWER_R1__________________,
         _________________LOWER_L2__________________, KC_F3,   KC_F4,   _________________LOWER_R2__________________,
         _________________LOWER_L3__________________, KC_F5,   KC_F6,   _________________LOWER_R3__________________,
         _______, KC_F11,   KC_F9,   KC_F7,  _______, SFT_SPC, XXXXXXX, RSE_ENT,  KC_F8,  KC_F10,  KC_F12,  _______
     ), // Has unicode in non-standard locations
     [_RAISE] = LAYOUT_4x12_mods(
         _________________RAISE_L1__________________, UC_FLIP, UC_TABL, _________________RAISE_R1__________________,
         _________________RAISE_L2__________________, UC_SHRG, _______, _________________RAISE_R2__________________,
         _________________RAISE_L3__________________, UC_DISA, UC_IRNY, _________________RAISE_R3__________________,
         _______, KC_NORM, KC_SUPR, KC_SCPT, LWR_BSP, SFT_SPC, XXXXXXX, _______, KC_AUSS, KC_WIDE, KC_BLCK, _______
     ), // Has toggles in the center column
     [_ADJUST] = LAYOUT_4x12_base(
         _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________,
         _________________ADJUST_L2_________________, RM_TOGG, KC_RGBT, _________________ADJUST_R2_________________,
         _________________ADJUST_L3_________________, RGB_TOG, KC_SEC1, _________________ADJUST_R3_________________,
         _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
     )
 };
// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    planck_ez_right_led_level(10);
    planck_ez_left_led_level(10);
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    switch (get_highest_layer(state)) {
        case _LOWER:
            planck_ez_left_led_on();
            break;
        case _RAISE:
            planck_ez_right_led_on();
            break;
        case _ADJUST:
            planck_ez_right_led_on();
            planck_ez_left_led_on();
            break;
        default:
            break;
    }
    return state;
};

#ifdef RGB_MATRIX_CUSTOM_USER
const uint8_t home_led_mapping[] = {}; // Non-empty requires HOME_LED_COUNT definiton
const uint8_t fn_led_mapping[] = {}; // Non-empty requires HOME_LED_COUNT definiton
const uint8_t mod_led_mapping[] = {
    // shift
    13,
    22,
    // command
    14,
    21,
    // option/alt
    15,
    20,
    // control
    24,
    35
};
const uint8_t arrow_led_mapping[] = {2, 13, 14, 15};
const uint8_t numpad_led_mapping[] = {8, 9, 10, 20, 21, 22, 32, 33, 34, 43};
#endif // RGB_MATRIX_CUSTOM_USER