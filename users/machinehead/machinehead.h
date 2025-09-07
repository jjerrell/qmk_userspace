// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2025 Jacob Jerrell (@jjerrell)

#pragma once
#include QMK_KEYBOARD_H

#include "keycodes/wrappers.h"
#include "keycodes/layouts.h"
#include "keycodes/process_records.h"
#include "callbacks.h"
#include "machinehead_runtime.h"
#include "machinehead_layers.h"
#include "machinehead_util.h"
#ifdef CUSTOM_TAP_DANCE_ENABLE
#    include "keyrecords/custom_tap_dance.h"
#endif // CUSTOM_TAP_DANCE_ENABLE
#if defined(RGB_MATRIX_ENABLE)
#   include "rgb/rgb_matrix_custom.h"
#endif // RGB_MATRIX_ENABLE

#ifdef AUDIO_ENABLE
void set_doom_song(layer_state_t state);
#endif // AUDIO_ENABLE