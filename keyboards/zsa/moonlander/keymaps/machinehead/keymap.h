// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "machinehead.h"

#define LAYOUT_moonlander_wrapper(...) LAYOUT_moonlander(__VA_ARGS__)

// clang-format off
#define WRAPPER_moonlander_base(                                          \
    K01, K02, K03, K04, K05, K06,           K07, K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15, K16,           K17, K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25, K26,           K27, K28, K29, K2A, K2B, K2C, \
    K31, K32, K33, K34, K35, K36,           K37, K38, K39, K3A, K3B, K3C  \
) \
    LAYOUT_moonlander_wrapper(                                                                                                                                  \
        K01,     K02,     K03,     K04,     K05,     K06,     KC_ARRW,                            KC_MINS,    K07,     K08,     K09,     K0A,     K0B,     K0C, \
        K11,     K12,     K13,     K14,     K15,     K16,     KC_LPRN,                            KC_RPRN,    K17,     K18,     K19,     K1A,     K1B,     K1C, \
        K21,     K22,     K23,     K24,     K25,     K26,     KC_LBRC,                            KC_RBRC,    K27,     K28,     K29,     K2A,     K2B,     K2C, \
        K31,     K32,     K33,     K34,     K35,     K36,                                                     K37,     K38,     K39,     K3A,     K3B,     K3C, \
        TOG_LWR, _______, _______, _______, QK_LEAD,                   _______,          _______,                  KC_CCCV, _______, _______, _______, TOG_RSE, \
                                                     ____THUMBS_L____, _______,          _______, ____THUMBS_R____                                              \
    )
// clang-format on

#define LAYOUT_moonlander_base(...) WRAPPER_moonlander_base(__VA_ARGS__)
#define LAYOUT_moonlander_mods(...) LAYOUT_moonlander_base(WRAP_MODIFIERS_4x12_tall(__VA_ARGS__))

#ifdef MOONLANDER_USER_LEDS
#   define ML_LED_L1(status) ML_LED_1((bool)status)
#   define ML_LED_L2(status) ML_LED_2((bool)status)
#   define ML_LED_L3(status) ML_LED_3((bool)status)

#   define ML_LED_R1(status) ML_LED_4((bool)status)
#   define ML_LED_R2(status) ML_LED_5((bool)status)
#   define ML_LED_R3(status) ML_LED_6((bool)status)
#endif