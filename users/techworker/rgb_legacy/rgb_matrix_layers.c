// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "rgb_matrix_layers.h"

// TODO: Incomplete and not integrated

// LED arrays
rgb_t home_leds[HOME_LED_COUNT] = {0};
rgb_t mod_leds[MOD_LED_COUNT] = {0};
rgb_t arrow_leds[ARROW_LED_COUNT] = {0};
rgb_t numpad_leds[NUMPAD_LED_COUNT] = {0};
rgb_t fn_leds[FN_LED_COUNT] = {0};

// LED mappings (Defined in each keymap)
extern uint8_t home_led_mapping[HOME_LED_COUNT];
extern uint8_t mod_led_mapping[MOD_LED_COUNT];
extern uint8_t arrow_led_mapping[ARROW_LED_COUNT];
extern uint8_t numpad_led_mapping[NUMPAD_LED_COUNT];
extern uint8_t fn_led_mapping[FN_LED_COUNT];

// Group definitions
rgb_group_t home_group = {home_leds, home_led_mapping, HOME_LED_COUNT};
rgb_group_t modifier_group = {mod_leds, mod_led_mapping, MOD_LED_COUNT};
rgb_group_t arrow_group = {arrow_leds, arrow_led_mapping, ARROW_LED_COUNT};
rgb_group_t numpad_group = {numpad_leds, numpad_led_mapping, NUMPAD_LED_COUNT};
rgb_group_t fn_group = {fn_leds, fn_led_mapping, FN_LED_COUNT};

// Helper functions to set led/group colors
void led_group_set_color(rgb_group_t *group, int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < group->count) {
        group->array[index].r = r;
        group->array[index].g = g;
        group->array[index].b = b;
    }
}

void led_group_set_all(rgb_group_t *group, uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < group->count; i++) {
        led_group_set_color(group, i, r, g, b);
    }
}

void led_group_apply(rgb_group_t *group) {
    for (uint8_t i = 0; i < group->count; i++) {
        RGB_MATRIX_INDICATOR_SET_COLOR(group->mapping[i], 
                                      group->array[i].r, 
                                      group->array[i].g, 
                                      group->array[i].b);
    }
}

void led_group_clear(rgb_group_t *group) {
    led_group_set_all(group, 0, 0, 0);
}

// Helper to apply multiple groups
void apply_groups(rgb_group_t *groups[], uint8_t count) {
    for (uint8_t i = 0; i < count; i++) {
        led_group_apply(groups[i]);
    }
}

// Usage examples:
void update_leds_for_layer(uint8_t layer) {
    // Clear all first
    led_group_clear(&home_group);
    led_group_clear(&modifier_group);
    led_group_clear(&arrow_group);
    led_group_clear(&numpad_group);
    led_group_clear(&fn_group);
    
    switch (layer) {
        case _WORKMAN:
            // Normal typing - subtle modifier indicators
            led_group_set_all(&modifier_group, 50, 50, 50);
            break;
            
        case _LOWER:
            led_group_set_all(&numpad_group, 0, 100, 255);
            led_group_set_all(&arrow_group, 0, 255, 100);
            break;
        case _RAISE:
            led_group_set_all(&fn_group, 255, 150, 0);
            break;
    }
    
    // Apply specific groups based on conditions
    rgb_group_t *active_groups[] = {
        &home_group,
        &modifier_group,
        &arrow_group,
        &numpad_group,
        &fn_group
    };
    apply_groups(active_groups, 5);
}

// Or reference specific collections for specific features
void highlight_active_mods(uint8_t mods) {
    led_group_clear(&modifier_group);
    
    if (mods & MOD_MASK_SHIFT) {
        led_group_set_all(&modifier_group, 0, 255, 0); // Helper to apply multiple groups
        led_group_set_color(&modifier_group, 0, 255, 0, 0);  // First LED for shift
        void apply_groups(rgb_group_t *groups[], uint8_t count) {
            for (uint8_t i = 0; i < count; i++) {
                led_group_apply(groups[i]);
            }
        }
        
        // Usage examples:
        void update_leds_for_layer(uint8_t layer) {
            // Clear all first
            led_group_clear(&modifier_group);
            led_group_clear(&arrow_group);
            led_group_clear(&numpad_group);
            led_group_clear(&fn_group);
            led_group_clear(&alpha_group);
            
            switch (layer) {
                case _WORKMAN:
                    // Normal typing - subtle modifier indicators
                    led_group_set_all(&modifier_group, 50, 50, 50);
                    break;
                    
                case _LOWER:
                    // Function layer - highlight F keys and arrows
                    led_group_set_all(&numpad_group, 0, 100, 255);
                    led_group_set_all(&arrow_group, 0, 255, 100);
                    break;
                    
                case _RAISE:
                    // Number layer - highlight numpad
                    led_group_set_all(&fn_group, 255, 150, 0);
                    break;

                case _ADJUST:
                    // Number layer - highlight numpad
                    led_group_set_all(&fn_group, 255, 0, 0);
                    break;
            }
            
            // Apply specific groups based on conditions
            rgb_group_t *active_groups[] = {
                &modifier_group,
                &arrow_group,
                &numpad_group,
                &fn_group,
                &alpha_group
            };
            apply_groups(active_groups, 5);
        }
        
        // Or reference specific collections for specific features
        void highlight_active_mods(uint8_t mods) {
            led_group_clear(&modifier_group);
            
            if (mods & MOD_MASK_SHIFT) {
                led_group_set_color(&modifier_group, 0, 255, 0, 0);  // First LED for shift
                led_group_set_color(&modifier_group, 7, 255, 0, 0);  // Last LED for shift
            }
            if (mods & MOD_MASK_CTRL) {
                led_group_set_color(&modifier_group, 1, 0, 255, 0);  // Ctrl positions
            }
            // etc...
            
            led_group_apply(&modifier_group);
        }t_color(&modifier_group, 7, 255, 0, 0);  // Last LED for shift
    }
    if (mods & MOD_MASK_CTRL) {
        led_group_set_color(&modifier_group, 1, 0, 255, 0);  // Ctrl positions
    }
    // etc...
    
    led_group_apply(&modifier_group);
}