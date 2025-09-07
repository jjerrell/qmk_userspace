// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include QMK_KEYBOARD_H
#include "machinehead.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
#define LAYOUT_base(                                                        \
    k00, k01, k02, k03, k04, k05,             k26, k27, k28, k29, k30, k31, \
    k06, k07, k08, k09, k10, k11,             k32, k33, k34, k35, k36, k37, \
    k12, k13, k14, k15, k16, k17,             k38, k39, k40, k41, k42, k43, \
    k18, k19, k20, k21, k22, k23,             k44, k45, k46, k47, k48, k49  \
) \
    LAYOUT_wrapper(                                                             \
        k00, k01, k02, k03, k04, k05,             k26, k27, k28, k29, k30, k31, \
        k06, k07, k08, k09, k10, k11,             k32, k33, k34, k35, k36, k37, \
        k12, k13, k14, k15, k16, k17,             k38, k39, k40, k41, k42, k43, \
        k18, k19, k20, k21, k22, k23,             k44, k45, k46, k47, k48, k49, \
                    ____THUMBS_L____,             ____THUMBS_R____              \
    )
// clang-format on

#define LAYOUT_base_wrapper(...)      LAYOUT_base(__VA_ARGS__)
#define LAYOUT_modifiers_wrapper(...) LAYOUT_base_wrapper(WRAP_MODIFIERS_4x12(__VA_ARGS__))
