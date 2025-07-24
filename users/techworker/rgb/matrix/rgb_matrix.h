// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once
#include QMK_KEYBOARD_H
#include "keycodes/process_records.h"
#include "techworker_runtime.h"
#include "techworker_layers.h"

// Types
typedef struct {
    rgb_t *array;
    const uint8_t *mapping;
    uint8_t count;
} rgb_group_t;

// Callbacks and hooks
bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record);
void keyboard_post_init_rgb_matrix(void);
void housekeeping_task_rgb_matrix(void);

// Feature helpers
void rgb_matrix_set_color_all(uint8_t red, uint8_t green, uint8_t blue);
void rgb_matrix_layer_helper(uint8_t mode, uint8_t speed, rgb_group_t group,
                             uint8_t led_min, uint8_t led_max);

void rgb_matrix_indicators_render_layer(uint8_t led_min, uint8_t led_max);

// Keymap customisations
bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
bool rgb_matrix_indicators_keymap(void);

void rgb_matrix_shutdown(bool jump_to_bootloader);

void rgb_group_set_color(rgb_group_t *group, int index, uint8_t r, uint8_t g, uint8_t b);
void rgb_group_set_all(rgb_group_t *group, uint8_t r, uint8_t g, uint8_t b);
void rgb_group_apply(rgb_group_t *group, uint8_t led_min, uint8_t led_max);
void rgb_group_clear(rgb_group_t *group);
