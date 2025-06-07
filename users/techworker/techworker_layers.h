// Copyright 2024 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "action_layer.h"

/* Define layer names */
enum userspace_layers {
    _WORKMAN = 0,
    _GAMEPAD,
    _MOUSE,
    _MACRO,
    _LOWER,
    _RAISE,
    _ADJUST, // Max = 16.
};

#define DEFAULT_LAYER_1_HSV HSV_CYAN
#define DEFAULT_LAYER_2_HSV HSV_CHARTREUSE
#define DEFAULT_LAYER_3_HSV HSV_MAGENTA
#define DEFAULT_LAYER_4_HSV HSV_GOLDENROD

#define DEFAULT_LAYER_1_RGB RGB_CYAN
#define DEFAULT_LAYER_2_RGB RGB_CHARTREUSE
#define DEFAULT_LAYER_3_RGB RGB_MAGENTA
#define DEFAULT_LAYER_4_RGB RGB_GOLDENROD