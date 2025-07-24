// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "rgb_matrix.h"
#include "techworker_util.h"
#include <ctype.h>
#include "lib/lib8tion/lib8tion.h"
#ifdef RGBLIGHT_ENABLE
#    include "rgblight.h"
#endif

rgb_t           rgb_matrix_hsv_to_rgb(hsv_t hsv);

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
    bool shifted = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#endif
    switch (keycode) {
        // TODO: Eval for usage and implement as needed
        // case RGB_IDL: // This allows me to use underglow as layer indication, or as normal
        //     if (record->event.pressed) {
        //         rgb_matrix_idle_anim_toggle();
        //     }
        //     break;
// Ensure the two features synchronize if both are enabled
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
        case QK_RGB_MATRIX_VALUE_DOWN:
        case QK_UNDERGLOW_VALUE_DOWN:
            if (record->event.pressed) {
                shifted ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), rgb_matrix_get_val());
            }
            return false;
        case QK_RGB_MATRIX_VALUE_UP:
        case QK_UNDERGLOW_VALUE_UP:
            if (record->event.pressed) {
                shifted ? rgb_matrix_decrease_val() : rgb_matrix_increase_val();
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), rgb_matrix_get_val());
            }
            return false;
#endif // RGBLIGHT_ENABLE && RGBLIGHT_CUSTOM
    }
    return true;
}

// TODO: Evaluate (currently broken on RGB_MATRIX_REST_MODE)
void housekeeping_task_rgb_matrix(void) {
// #if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
//     if (userspace_config.rgb.idle_anim && rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP &&
//         sync_timer_elapsed32(hypno_timer) > 15000) {
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
//     }
// #endif // RGB_MATRIX_FRAMEBUFFER_EFFECTS
}

#pragma region RGB_LAYER_INDICATION
// LED arrays
rgb_t home_leds[HOME_LED_COUNT] = {};
rgb_t mod_leds[MOD_LED_COUNT] = {};
rgb_t arrow_leds[ARROW_LED_COUNT] = {};
rgb_t numpad_leds[NUMPAD_LED_COUNT] = {};
rgb_t fn_leds[FN_LED_COUNT] = {};

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

 // TODO: Evaluate (currently broken on RGB_MATRIX_REST_MODE)
void keyboard_post_init_rgb_matrix(void) {
    rgb_group_set_all(&home_group, 50, 50, 50);
    rgb_group_set_all(&modifier_group, 50, 100, 50);
    rgb_group_set_all(&arrow_group, 50, 50, 50);
    rgb_group_set_all(&numpad_group, 50, 100, 50);
    rgb_group_set_all(&fn_group, 175, 50, 100);
    rgb_group_set_all(&home_group, 200, 200, 200);
// #if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
//     if (userspace_config.rgb.idle_anim) {
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
//     }
// #endif // RGB_MATRIX_FRAMEBUFFER_EFFECTS
    if (userspace_config.rgb.layer_change) {
        rgb_matrix_set_flags_noeeprom(LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR);
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
        rgblight_enable_noeeprom();
#endif
    } else {
        rgb_matrix_set_flags_noeeprom(LED_FLAG_ALL);
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_CUSTOM)
        rgblight_disable_noeeprom();
#endif
    }
}

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

void rgb_group_apply(rgb_group_t *group, uint8_t led_min, uint8_t led_max) {
    if (group->count <= 0) {
        return;
    }
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
    return false;
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

void rgb_matrix_layer_helper(uint8_t mode, uint8_t speed, rgb_group_t group,
                             uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = 0; i < group.count; i++) {
        RGB_MATRIX_INDICATOR_SET_COLOR(group.mapping[i], group.array[i].r, group.array[i].g, group.array[i].b);
    }
    // for (uint8_t i = led_min; i < group.count; i++) {
    //     rgb_t rgb = group.array[i];
    //     rgb_matrix_set_color(group.mapping[i], rgb.r, rgb.g, rgb.b);
    // }
    // // Map the color values
    // hsv_t   hsv  = {hue, sat, val};
    // rgb_t   rgb  = {0};
    // uint8_t time = scale16by8(g_rgb_timer, qadd8(speed / 4, 1));
    // if (hsv.v > rgb_matrix_get_val()) {
    //     hsv.v = rgb_matrix_get_val();
    // }

    // switch (mode) {
    //     case 1: // breathing
    //         for (uint8_t i = led_min; i < led_max && i < group.count; i++) {
    //             if (!HAS_FLAGS(g_led_config.flags[i], LED_FLAG_NONE)) {
    //                 hsv.v     = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    //                 rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
    //                 rgb_matrix_set_color(group.array[i], rgb.r, rgb.g, rgb.b);
    //             }
    //         }
    //         break;
    //     case 2: // Rainbow Mood
    //         for (uint8_t i = led_min; i < led_max && i < group.count; i++) {
    //             hsv.h = time;
    //             if (!HAS_FLAGS(g_led_config.flags[i], LED_FLAG_NONE)) {
    //                 rgb = rgb_matrix_hsv_to_rgb(hsv);
    //                 rgb_matrix_set_color(group.array[i], rgb.r, rgb.g, rgb.b);
    //             }
    //         }
    //         break;
    //     case 3: // Rainbow Swirl
    //         for (uint8_t i = led_min; i < led_max && i < group.count; i++) {
    //             if (!HAS_FLAGS(g_led_config.flags[i], LED_FLAG_NONE)) {
    //                 hsv.h = g_led_config.point[i].x - time;
    //                 rgb   = rgb_matrix_hsv_to_rgb(hsv);
    //                 rgb_matrix_set_color(group.array[i], rgb.r, rgb.g, rgb.b);
    //             }
    //         }
    //         break;
    //     case 4: // Snek
    //         for (uint8_t i = led_min; i < led_max && i < group.count; i++) {
    //             if (!HAS_FLAGS(g_led_config.flags[i], LED_FLAG_NONE)) {
    //                 int16_t v = hsv.v - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    //                 hsv.v     = scale8(v < 0 ? 0 : v, hsv.v);
    //                 rgb       = rgb_matrix_hsv_to_rgb(hsv);
    //                 rgb_matrix_set_color(group.array[i], rgb.r, rgb.g, rgb.b);
    //             }
    //         }
    //         break;
    //     default: // Solid Color
    //         for (uint8_t i = led_min; i < led_max && i < group.count; i++) {
    //             if (!HAS_FLAGS(g_led_config.flags[i], LED_FLAG_NONE)) {
    //                 rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
    //                 rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    //             }
    //         }
    //         break;
    // }
}

/**
 * @brief Render the RGB Matrix layer indicators
 *
 * @param led_min
 * @param led_max
 */
void rgb_matrix_indicators_render_layer(uint8_t led_min, uint8_t led_max) {
    // if (userspace_config.rgb.layer_change) {       
#ifdef RGB_MATRIX_CUSTOM_USER
#    if defined(SPLIT_KEYBOARD) && defined(SPLIT_LAYER_STATE_ENABLE)
        static layer_state_t old_layer_state = (layer_state_t)~0, old_default_layer_state = (layer_state_t)~0;
        if (!is_keyboard_master()) {
            if (layer_state != old_layer_state) {
                old_layer_state = layer_state_set_rgb_light(layer_state);
            }
            if (default_layer_state != old_default_layer_state) {
                old_default_layer_state = default_layer_state_set_rgb_light(default_layer_state);
            }
        }
#    endif // SPLIT_KEYBOARD && SPLIT_LAYER_STATE_ENABLE
        rgb_matrix_set_color_all(RGB_OFF);
        // TODO: Update vars by layer if needed
        uint8_t mode = 0;
        uint8_t speed = 1;
        rgb_matrix_layer_helper(mode, speed, modifier_group, led_min, led_max);
        // switch (get_highest_layer(layer_state)) {
        //     case 0:
        //         // rgb_matrix_layer_helper(mode, speed, home_group, led_min, led_max);
        //         rgb_matrix_layer_helper(mode, speed, modifier_group, led_min, led_max);
        //         break;
        //     case _LOWER:
        //         rgb_matrix_layer_helper(mode, speed, arrow_group, led_min, led_max);
        //         rgb_matrix_layer_helper(mode, speed, numpad_group, led_min, led_max);
        //         break;
        //     case _RAISE:
        //         rgb_matrix_layer_helper(mode, speed, fn_group, led_min, led_max);
        //         break;
        //     case _ADJUST:
        //         rgb_matrix_layer_helper(mode, speed, home_group, led_min, led_max);
        //         break;
        // }
        // // Clear all LEDs
        // rgb_group_clear(&home_group);
        // rgb_group_clear(&modifier_group);
        // rgb_group_clear(&arrow_group);
        // rgb_group_clear(&numpad_group);
        // rgb_group_clear(&fn_group);
        // // Set the appropriate groups
        // switch (get_highest_layer(layer_state)) {
            // case 0:
            //     rgb_group_set_all(&home_group, 50, 50, 50);
            //     rgb_group_set_all(&modifier_group, 50, 100, 50);
            //     break;
            // case _LOWER:
            //     rgb_group_set_all(&arrow_group, 50, 50, 50);
            //     rgb_group_set_all(&numpad_group, 50, 100, 50);
            //     break;
            // case _RAISE:
            //     rgb_group_set_all(&fn_group, 175, 50, 100);
            //     break;
            // case _ADJUST:
            //     rgb_group_set_all(&home_group, 200, 200, 200);
            //     break;
        // }
        // // Apply the groups
        // rgb_group_apply(&home_group, led_min, led_max);
        // rgb_group_apply(&modifier_group, led_min, led_max);
        // rgb_group_apply(&arrow_group, led_min, led_max);
        // rgb_group_apply(&numpad_group, led_min, led_max);
        // rgb_group_apply(&fn_group, led_min, led_max);
#endif  // RGB_MATRIX_CUSTOM_USER
    // }
}

void rgb_matrix_idle_anim_toggle(void) {
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
    userspace_config.rgb.idle_anim ^= 1;
    dprintf("RGB Matrix Idle Animation [EEPROM]: %u\n", userspace_config.rgb.idle_anim);
    // eeconfig_update_user_datablock_handler(&userspace_config, 0, EECONFIG_USER_DATA_SIZE);
    if (userspace_config.rgb.idle_anim) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
    }
#endif // RGB_MATRIX_ENABLE && RGB_MATRIX_FRAMEBUFFER_EFFECTS
}

void rgb_matrix_shutdown(bool jump_to_bootloader) {
    void rgb_matrix_update_pwm_buffers(void);
    rgb_matrix_set_color_all(rgb_matrix_get_val(), 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
}