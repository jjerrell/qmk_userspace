// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once
#include QMK_KEYBOARD_H
#include "keycodes/process_records.h"
#include "techworker_runtime.h"
#include "techworker_layers.h"
#include "techworker_util.h"
#include "rgb_matrix.h"

// typedef struct PACKED {
//     hsv_t primary;
//     hsv_t secondary;
// } dual_hsv_t;

// For efficient array lookups
typedef struct {
    bool lookup[256];  // Supports LED indices 0-255
} led_bitmap_t;

// Callbacks and hooks
bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record);

void keyboard_post_init_rgb_matrix(void);
void housekeeping_task_rgb_matrix(void);

void rgb_matrix_shutdown(bool jump_to_bootloader);

// Keymap level overrides
bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
