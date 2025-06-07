// Copyright 2024 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <util.h>
#include <quantum/color.h>
#include <action_layer.h>
#include <keycode_config.h>
#include <led.h>
#include "debug.h"

typedef struct PACKED {
    hsv_t primary;
    hsv_t secondary;
} dual_hsv_t;

typedef union PACKED {
    uint8_t raw[EECONFIG_USER_DATA_SIZE];
    struct {
        struct {
            bool layer_change : 1;
            bool idle_anim    : 1;
        } rgb;
        struct {
            bool i2c_scanner_enable : 1;
            bool matrix_scan_print  : 1;
            bool console_keylogger  : 1;
        } debug;
        bool nuke_switch : 1;
        bool check       : 1;
    };
} userspace_config_t;

_Static_assert(sizeof(userspace_config_t) <= EECONFIG_USER_DATA_SIZE, "User EECONFIG block is not large enough.");

extern userspace_config_t userspace_config;

#if defined(COMMUNITY_MODULE_DISPLAY_MENU_ENABLE)
#    include "display_menu.h"
#else
typedef struct PACKED {
    bool    is_in_menu;
    uint8_t selected_child;
    uint8_t menu_stack[8];
} menu_state_t;

typedef struct PACKED {
    bool dirty        : 1;
    bool has_rendered : 1;
} menu_state_runtime_t;
#endif // CUSTOM_QUANTUM_PAINTER_ENABLE

typedef struct PACKED {
    uint8_t mods;
    uint8_t weak_mods;
    uint8_t oneshot_mods;
    uint8_t oneshot_locked_mods;
} sync_mods_t;

typedef struct PACKED {
    layer_state_t layer_state;
    layer_state_t default_layer_state;
} sync_layer_t;

typedef struct PACKED {
    uint8_t wpm_count : 8;
    uint8_t wpm_peak  : 8;
    uint8_t wpm_avg   : 8;
} wpm_sync_data_t;

typedef struct PACKED {
    struct {
        bool  enable        : 1;
        bool  clicky_enable : 1;
        bool  music_enable  : 1;
        float clicky_freq;
        float clicky_rand;
    } audio;
    struct {
        bool tap_toggling         : 1;
        bool swap_hands           : 1;
        bool host_driver_disabled : 1;
        bool is_caps_word         : 1;
        bool is_device_suspended  : 1;
    } internals;
    struct {
        uint8_t mode        : 3;
        uint8_t typing_mode : 4;
    } unicode;
    struct {
        menu_state_t         menu_state;
        menu_state_runtime_t menu_state_runtime;
    } display;
    sync_mods_t     mods;
    sync_layer_t    layers;
    led_t           leds;
    keymap_config_t keymap_config;
    debug_config_t  debug_config;
    wpm_sync_data_t wpm;
    uint16_t        last_keycode : 16;
    keyevent_t      last_key_event;
} user_runtime_config_t;

extern user_runtime_config_t userspace_runtime_state;
