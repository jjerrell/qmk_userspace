// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "rgb_matrix.h"
#include "techworker_util.h"
#include <ctype.h>
#include "lib/lib8tion/lib8tion.h"

// LED mappings (Defined in each keymap)
extern uint8_t home_led_mapping[HOME_LED_COUNT];
extern uint8_t mod_led_mapping[MOD_LED_COUNT];
extern uint8_t arrow_led_mapping[ARROW_LED_COUNT];
extern uint8_t numpad_led_mapping[NUMPAD_LED_COUNT];
extern uint8_t fn_led_mapping[FN_LED_COUNT];

// Lookup helpers
led_bitmap_t home_bitmap, mod_bitmap, arrow_bitmap, numpad_bitmap, fn_bitmap;

void build_led_bitmap(led_bitmap_t *bitmap, const uint8_t *group, uint8_t count) {
    // Clear bitmap
    memset(bitmap->lookup, false, sizeof(bitmap->lookup));
    
    // Set bits for group members
    for (uint8_t i = 0; i < count; i++) {
        if (group[i] < 256) {  // Bounds check
            bitmap->lookup[group[i]] = true;
        }
    }
}

bool led_in_group(const led_bitmap_t *bitmap, uint8_t led_index) {
    return (led_index < 256) ? bitmap->lookup[led_index] : false;
}

void init_led_bitmaps(void) {
    build_led_bitmap(&home_bitmap, home_led_mapping, HOME_LED_COUNT);
    build_led_bitmap(&mod_bitmap, mod_led_mapping, MOD_LED_COUNT);
    build_led_bitmap(&arrow_bitmap, arrow_led_mapping, ARROW_LED_COUNT);
    build_led_bitmap(&numpad_bitmap, numpad_led_mapping, NUMPAD_LED_COUNT);
    build_led_bitmap(&fn_bitmap, fn_led_mapping, FN_LED_COUNT);
}

void enable_mappings(
    led_bitmap_t bitmap, 
    uint8_t group_size,
    uint8_t led_min, 
    uint8_t led_max,
    uint8_t r, 
    uint8_t g, 
    uint8_t b
) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if (led_in_group(&bitmap, i)) {
            rgb_matrix_set_color(i, r, g, b);
        } 
        // else {
        //     rgb_matrix_set_color(i, RGB_OFF);
        // }
    }
    // for (uint8_t i = 0; i < group_size; i++) {
    //     if (mapping[i] >= led_min && mapping[i] < led_max) {
    //         rgb_matrix_set_color(mapping[i], r, g, b);
    //     }
    // }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // New implementation (better)
    // home_bitmap, mod_bitmap, arrow_bitmap, numpad_bitmap, fn_bitmap;
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _WORKMAN:
            enable_mappings(home_bitmap, HOME_LED_COUNT, led_min, led_max, RGB_ORANGE);
            enable_mappings(mod_bitmap, MOD_LED_COUNT, led_min, led_max, RGB_BLUE);
            break;
        case _LOWER:
            enable_mappings(arrow_bitmap, ARROW_LED_COUNT, led_min, led_max, RGB_BLUE);
            enable_mappings(numpad_bitmap, NUMPAD_LED_COUNT, led_min, led_max, RGB_GOLD);
            break;
        case _RAISE:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_BLUE);
            }
            break;
        case _ADJUST:
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_ORANGE);
            }
            break;
        default:
            break;
    }
    return false;
}

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void keyboard_post_init_rgb_matrix(void) {
    init_led_bitmaps();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

void housekeeping_task_rgb_matrix(void) {}

void rgb_matrix_shutdown(bool jump_to_bootloader) {
    void rgb_matrix_update_pwm_buffers(void);
    rgb_matrix_set_color_all(rgb_matrix_get_val(), 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
}