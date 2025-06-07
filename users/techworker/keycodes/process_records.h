// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2025 Jacob Jerrell (@jjerrell)

#pragma once

#include "action.h"

enum userspace_custom_keycodes {
    KC_MAKE = QK_USER, // Runs the keyboard's make command
    KC_ARRW,           // ->
    KC_VRSN,           // Print QMK Firmware and board info
    KC_CCCV,           // Copy-pasta button
    KC_RGB_T,          // Toggles RGB Layer Indication mode
    RGB_IDL,           // RGB Idling animations
    MACRO_1,           // Test
    MACRO_2,           // Test
    MACRO_3,           // Test
    MACRO_4,           // Test
    MACRO_5,           // Test
    UC_FLIP,           // (ಠ痊ಠ)┻━┻
    UC_TABL,           // ┬─┬ノ( º _ ºノ)
    UC_SHRG,           // ¯\_(ツ)_/¯
    UC_DISA,           // ಠ_ಠ
    UC_IRNY,
    UC_CLUE,

    KC_QWERTY,
    KC_WRKMAN,
    KC_GAME,
    DF_WORK,

    LAYER_LOCK,

    USER_SAFE_RANGE
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool pre_process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);
#ifdef CUSTOM_UNICODE_ENABLE
bool process_record_unicode(uint16_t keycode, keyrecord_t *record);
#endif // CUSTOM_UNICODE_ENABLE
void rgb_layer_indication_toggle(void);

#define KC_SEC1 MACRO_1
#define KC_SEC2 MACRO_2
#define KC_SEC3 MACRO_3
#define KC_SEC4 MACRO_4
#define KC_SEC5 MACRO_5

#define CTL_SPC CTL_T(KC_SPC)

#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)

#define LWR_BSP LT(_LOWER, KC_BSPC)

#define RSE_TAB LT(_RAISE, KC_TAB)
#define RSE_ENT LT(_RAISE, KC_ENT)

#ifndef COMMUNITY_MODULE_KEYBOARD_LOCK_ENABLE
#    define KEYLOCK KC_NO
#endif // COMMUNITY_MODULE_KEYBOARD_LOCK_ENABLE
#ifndef COMMUNITY_MODULE_UNICODE_TYPING_ENABLE
#    define KC_NOMODE   KC_NO
#    define KC_WIDE     KC_NO
#    define KC_SCRIPT   KC_NO
#    define KC_BLOCKS   KC_NO
#    define KC_REGIONAL KC_NO
#    define KC_AUSSIE   KC_NO
#    define KC_ZALGO    KC_NO
#    define KC_SUPER    KC_NO
#    define KC_COMIC    KC_NO
#endif // COMMUNITY_MODULE_UNICODE_TYPING_ENABLE
