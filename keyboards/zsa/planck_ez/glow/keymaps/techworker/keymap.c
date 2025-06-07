// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_WORKMAN] = LAYOUT_4x12_mods(
         _________________WORKMAN_L1________________, KC_ARRW,  KC_MINS, _________________WORKMAN_R1________________,
         _________________WORKMAN_L2________________, KC_LPRN,  KC_RPRN, _________________WORKMAN_R2________________,
         _________________WORKMAN_L3________________, KC_LBRC,  KC_RBRC, _________________WORKMAN_R3________________,
         ___________HOME_L_MINI____________, LWR_BSP, SFT_SPC,  XXXXXXX, RSE_ENT, ___________HOME_R_MINI____________
     ),
     [_LOWER] = LAYOUT_4x12_mods(
         _________________LOWER_L1__________________, _______, _______, _________________LOWER_R1__________________,
         _________________LOWER_L2__________________, _______, _______, _________________LOWER_R2__________________,
         _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________,
         ___________LOWER_L_MINI___________, _______, SFT_SPC, XXXXXXX, RSE_ENT, ___________LOWER_R_MINI___________
     ),
     [_RAISE] = LAYOUT_4x12_mods(
         _________________RAISE_L1__________________, _______, _______, _________________RAISE_R1__________________,
         _________________RAISE_L2__________________, _______, _______, _________________RAISE_R2__________________,
         _________________RAISE_L3__________________, _______, _______, _________________RAISE_R3__________________,
         ___________RAISE_L_MINI___________, LWR_BSP, SFT_SPC, XXXXXXX, _______, ___________RAISE_R_MINI___________
     ),
     [_ADJUST] = LAYOUT_4x12_base(
         _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________,
         _________________ADJUST_L2_________________, _______, _______, _________________ADJUST_R2_________________,
         _________________ADJUST_L3_________________, _______, _______, _________________ADJUST_R3_________________,
         ___________________BLANK___________________, _______, XXXXXXX, ___________________BLANK___________________
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
}
