// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "rgb_matrix_custom.h"
#include "lib/lib8tion/lib8tion.h"

extern rgb_config_t rgb_matrix_config;
extern led_config_t g_led_config;

// LED mappings (Defined in each keymap. See the readme section for "Layer Indication".)
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

#pragma region SIMPLE_LAYER_INDICATION

/** Helper to set the color of all LEDs in a group */
void enable_simple_mappings(
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
    }
}

void simple_layer_indication(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case _WORKMAN:
            enable_simple_mappings(
                mod_bitmap, MOD_LED_COUNT,
                led_min, led_max,
                RGB_ORANGE
            );
            break;
        case _LOWER:
            enable_simple_mappings(
                arrow_bitmap, ARROW_LED_COUNT,
                led_min, led_max, 
                RGB_BLUE
            );
            enable_simple_mappings(
                numpad_bitmap, NUMPAD_LED_COUNT,
                led_min, led_max, 
                RGB_GOLD
            );
            break;
        case _RAISE:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
                    rgb_matrix_set_color(i, RGB_BLUE);
                }
            }
            break;
        case _ADJUST:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
                    rgb_matrix_set_color(i, RGB_ORANGE);
                }
            }
            break;
    }
}
#pragma endregion SIMPLE_LAYER_INDICATION

#pragma region ANIMATED_LAYER_INDICATION
void breathing_group_animation(
    uint8_t led_min, uint8_t led_max,
    led_bitmap_t bitmap, uint8_t group_size,
    uint8_t hue, uint8_t sat, uint8_t val
) {
    static uint16_t cycle_timer = 0;
    static uint8_t hue_offset = 0;
    
    // Update hue every 100ms
    if (timer_elapsed(cycle_timer) > 100) {
        hue_offset += 8; // Adjust speed as needed
        cycle_timer = timer_read();
    }
    
    for (uint8_t i = led_min; i < led_max; i++) {
        if (led_in_group(&bitmap, i)) {
            // Create rainbow wave effect
            uint8_t new_hue = hue_offset + (hue / (led_max - led_min));
            hsv_t   hsv  = {new_hue, sat, val};
            rgb_t   rgb  = hsv_to_rgb(hsv);
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

void breathing_group_animation_all(
    uint8_t led_min, uint8_t led_max,
    uint8_t hue, uint8_t sat, uint8_t val
) {
    static uint16_t cycle_timer = 0;
    static uint8_t hue_offset = 0;
    
    // Update hue every 100ms
    if (timer_elapsed(cycle_timer) > 100) {
        hue_offset += 8; // Adjust speed as needed
        cycle_timer = timer_read();
    }
    
    for (uint8_t i = led_min; i < led_max; i++) {
        // Create rainbow wave effect
        uint8_t new_hue = hue_offset + (hue / (led_max - led_min));
        hsv_t   hsv  = {new_hue, sat, val};
        rgb_t   rgb  = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

void animated_layer_indication(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case _WORKMAN:
            breathing_group_animation(
                led_min, led_max,
                mod_bitmap, MOD_LED_COUNT,
                HSV_ORANGE
            );
            break;
        case _LOWER:
            breathing_group_animation(
                led_min, led_max,
                arrow_bitmap, ARROW_LED_COUNT,
                HSV_BLUE
            );
            breathing_group_animation(
                led_min, led_max,
                numpad_bitmap, NUMPAD_LED_COUNT,
                HSV_GOLDENROD
            );
            break;
        case _RAISE: 
            breathing_group_animation_all(
                led_min, led_max,
                HSV_ORANGE
            );
            break;
        case _ADJUST:      
            breathing_group_animation_all(
                led_min, led_max,
                HSV_RED
            );
            break;
        default:
            break;
    }
}
#pragma endregion ANIMATED_LAYER_INDICATION

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

// Layer indication integration
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) {
        return false;
    }
#ifdef ANIMATED_LAYER_INDICATION
    animated_layer_indication(led_min, led_max);
#elif defined(SIMPLE_LAYER_INDICATION) // ANIMATED_LAYER_INDICATION
    simple_layer_indication(led_min, led_max);
#endif // SIMPLE_LAYER_INDICATION
    return false;
}

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/** Called during `keyboard_post_init_user` */
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