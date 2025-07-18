// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "rgb_matrix.h"

#pragma region RGB_LAYER_INDICATION
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

/**
 * The above setup requires that keymaps provide definitions such as:
 * ```
 * const uint8_t home_led_mapping[] = {}; // Non-empty requires HOME_LED_COUNT definiton
 * const uint8_t fn_led_mapping[] = {}; // Non-empty requires HOME_LED_COUNT definiton
 * const uint8_t mod_led_mapping[] = {24, 29, 30, 31};
 * const uint8_t arrow_led_mapping[] = {32, 33, 34, 35, 71, 70, 69, 68};
 * const uint8_t numpad_led_mapping[] = {36, 37, 38, 39};
 * ```
 */

// Feature helpers
void rgb_group_set_color(rgb_group_t *group, int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < group->count) {
        group->array[index].r = r;
        group->array[index].g = g;
        group->array[index].b = b;
    }
}

void rgb_group_set_all(rgb_group_t *group, uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < group->count; i++) {
        rgb_group_set_color(group, i, r, g, b);
    }
}

void rgb_group_apply(rgb_group_t *group) {
    for (uint8_t i = 0; i < group->count; i++) {
        RGB_MATRIX_INDICATOR_SET_COLOR(group->mapping[i], 
                                      group->array[i].r, 
                                      group->array[i].g, 
                                      group->array[i].b);
    }
}

void rgb_group_clear(rgb_group_t *group) {
    rgb_group_set_all(group, 0, 0, 0);
}
#pragma endregion RGB_LAYER_INDICATION

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) {
        return false;
    }
    rgb_matrix_indicators_render_layer(led_min, led_max);
    return false;
}

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) {
    return true;
}

bool rgb_matrix_indicators_user(void) {
    return rgb_matrix_indicators_keymap();
}

/**
 * @brief Render the RGB Matrix layer indicators
 *
 * @param led_min
 * @param led_max
 */
void rgb_matrix_indicators_render_layer(uint8_t led_min, uint8_t led_max) {
    if (userspace_config.rgb.layer_change) {
        // TODO: Implement layer checks and use the above `rgb_group_*` funcs accordingly

        
#       pragma region DRASHNA
// #if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
// #    if defined(SPLIT_KEYBOARD) && defined(SPLIT_LAYER_STATE_ENABLE)
//         static layer_state_t old_layer_state = (layer_state_t)~0, old_default_layer_state = (layer_state_t)~0;
//         if (!is_keyboard_master()) {
//             if (layer_state != old_layer_state) {
//                 old_layer_state = layer_state_set_rgb_light(layer_state);
//             }
//             if (default_layer_state != old_default_layer_state) {
//                 old_default_layer_state = default_layer_state_set_rgb_light(default_layer_state);
//             }
//         }
// #    endif // SPLIT_KEYBOARD && SPLIT_LAYER_STATE_ENABLE
//         for (uint8_t i = 0; i < RGBLIGHT_LED_COUNT; i++) {
//             RGB_MATRIX_INDICATOR_SET_COLOR(led_mapping[i], led_array[i].r, led_array[i].g, led_array[i].b);
//         }
// #else  // RGBLIGHT_ENABLE && RGBLIGHT_CUSTOM
//         switch (get_highest_layer(layer_state & ~((layer_state_t)1 << _MOUSE))) {
//             case _GAMEPAD:
//                 rgb_matrix_layer_helper(HSV_ORANGE, 4, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
//                 break;
//             case _RAISE:
//                 rgb_matrix_layer_helper(HSV_YELLOW, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
//                 break;
//             case _LOWER:
//                 rgb_matrix_layer_helper(HSV_GREEN, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
//                 break;
//             case _ADJUST:
//                 rgb_matrix_layer_helper(HSV_RED, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min, led_max);
//                 break;
//             default:
//                 if (layer_state_is(_MOUSE)) {
//                     rgb_matrix_layer_helper(HSV_PURPLE, 1, rgb_matrix_config.speed, LED_FLAG_MODIFIER, led_min,
//                                             led_max);
//                 } else {
//                     switch (get_highest_layer(default_layer_state)) {
//                         case _WORKMAN:
//                             rgb_matrix_layer_helper(DEFAULT_LAYER_1_HSV, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER,
//                                                     led_min, led_max);
//                             break;
//                         case _MACRO:
//                             rgb_matrix_layer_helper(DEFAULT_LAYER_2_HSV, 0, rgb_matrix_config.speed, LED_FLAG_MODIFIER,
//                                                     led_min, led_max);
//                             break;
//                     }
//                 }
//                 break;
//         }
// #endif // RGBLIGHT_ENABLE && RGBLIGHT_CUSTOM
#       pragma endregion DRASHNA
    }
}