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
    _ADJUST, // Current = 7; Max = 16.
};
