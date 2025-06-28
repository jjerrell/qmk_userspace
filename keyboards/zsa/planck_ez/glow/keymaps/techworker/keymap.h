// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "techworker.h"

#define LAYOUT_4x12_base(...) LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_4x12_mods(...) LAYOUT_4x12_base(WRAP_MODIFIERS_4x12_wide(__VA_ARGS__))