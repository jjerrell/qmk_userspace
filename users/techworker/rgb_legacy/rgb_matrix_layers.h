// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once
#include "quantum.h"

typedef struct {
    rgb_t *array;
    const uint8_t *mapping;
    uint8_t count;
} led_group_t;

// Function declarations
void led_group_set_color(led_group_t *group, int index, uint8_t r, uint8_t g, uint8_t b);
void led_group_set_all(led_group_t *group, uint8_t r, uint8_t g, uint8_t b);
void led_group_apply(led_group_t *group);
void led_group_clear(led_group_t *group);
