// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2025 Jacob Jerrell (@jjerrell)

#pragma once
#include QMK_KEYBOARD_H

#include "keycodes/wrappers.h"
#include "keycodes/layouts.h"
#include "keycodes/process_records.h"
#include "callbacks.h"
#include "techworker_runtime.h"
#include "techworker_layers.h"
#include "techworker_util.h"
#ifdef CUSTOM_TAP_DANCE_ENABLE
#    include "keyrecords/custom_tap_dance.h"
#endif // CUSTOM_TAP_DANCE_ENABLE

// TODO: Possibly superfluous?
// #if defined(RGB_MATRIX_ENABLE)
// void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type,
//                              uint8_t led_min, uint8_t led_max);
// #endif // defined(RGB_MATRIX_ENABLE)

void     matrix_scan_rate_task(void);
uint32_t get_matrix_scan_rate(void);

#ifdef AUDIO_ENABLE
void set_doom_song(layer_state_t state);
#endif // AUDIO_ENABLE