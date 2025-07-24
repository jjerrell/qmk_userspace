// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef RGB_MATRIX_CUSTOM_USER
#   define MOD_LED_COUNT 8
#   define ARROW_LED_COUNT 4
#   define NUMPAD_LED_COUNT 10
#endif // RGB_MATRIX_CUSTOM_USER

#if defined(RGBLIGHT_ENABLE) && !defined(RGBLED_NUM)
#    define RGBLIGHT_HUE_STEP             12
#    define RGBLIGHT_SAT_STEP             12
#    define RGBLIGHT_VAL_STEP             12
#    define RGBLIGHT_EFFECT_KNIGHT_LENGTH 2
#    define RGBLIGHT_EFFECT_SNAKE_LENGTH  2
#    ifdef RGB_MATRIX_ENABLE
#        define RGBLIGHT_DISABLE_KEYCODES
#    endif
#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses (will slow down matrix scan by a lot)
// #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (not recommened)
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined
// maximum brightness is set to 255
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    undef RGB_MATRIX_LED_PROCESS_LIMIT
#    undef RGB_MATRIX_LED_FLUSH_LIMIT
#endif

#undef NO_USB_STARTUP_CHECK