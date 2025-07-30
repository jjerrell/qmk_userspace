// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef RGB_MATRIX_CUSTOM_USER
// Default LED counts
#   ifndef HOME_LED_COUNT
#      define HOME_LED_COUNT 0
#   endif
#   ifndef FN_LED_COUNT
#      define FN_LED_COUNT 0
#   endif
#   ifndef MOD_LED_COUNT
#      define MOD_LED_COUNT 8
#   endif
#   ifndef ARROW_LED_COUNT
#      define ARROW_LED_COUNT 4
#   endif
#   ifndef NUMPAD_LED_COUNT
#      define NUMPAD_LED_COUNT 10
#   endif
#endif // RGB_MATRIX_CUSTOM_USER

#ifndef RGB_MATRIX_REST_MODE
#    if defined(SPLIT_KEYBOARD) || defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_zsa)
#        define RGB_MATRIX_REST_MODE RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    else // defined(SPLIT_KEYBOARD) || defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_zsa)
#        define RGB_MATRIX_REST_MODE RGB_MATRIX_CYCLE_OUT_IN
#    endif // defined(SPLIT_KEYBOARD) || defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_zsa)
#endif     // RGB_MATRIX_REST_MODE

#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_REST_MODE

#ifndef RGB_MATRIX_LED_PROCESS_LIMIT
#    define RGB_MATRIX_LED_PROCESS_LIMIT 5
#endif // RGB_MATRIX_LED_PROCESS_LIMIT
#ifndef RGB_MATRIX_LED_FLUSH_LIMIT
#    define RGB_MATRIX_LED_FLUSH_LIMIT 26
#endif // RGB_MATRIX_LED_FLUSH_LIMIT