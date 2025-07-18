// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once
#include "quantum.h"

typedef struct {
    rgb_t *array;
    const uint8_t *mapping;
    uint8_t count;
} rgb_group_t;

// Feature helpers
void rgb_group_set_color(rgb_group_t *group, int index, uint8_t r, uint8_t g, uint8_t b);
void rgb_group_set_all(rgb_group_t *group, uint8_t r, uint8_t g, uint8_t b);
void rgb_group_apply(rgb_group_t *group);
void rgb_group_clear(rgb_group_t *group);

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
bool rgb_matrix_indicators_keymap(void);