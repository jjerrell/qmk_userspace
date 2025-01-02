// Copyright (C) 2025 Jerrell, Jacob <@jjerrell>
//
// This file is part of qmk_firmware.
//
// qmk_firmware is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// qmk_firmware is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.

#include "rgb_matrix_custom.h"

__attribute__((weak)) bool rgb_indicators_process_layer_keymap(uint8_t layer, uint8_t active_mods) {
    rgb_matrix_set_color_all(RGB_OFF);
    return true;
}

bool rgb_indicators_process_layer_user(uint8_t layer, uint8_t active_mods) {
    if (rgb_indicators_process_layer_keymap(layer, active_mods)) {
        rgb_t default_color = (rgb_t){RGB_GREEN}; // Default to GOLD

        switch (layer) {
            case _WORKMAN:
                default_color = (rgb_t){RGB_GREEN};
                break;
            case _HOME:
                default_color = (rgb_t){RGB_BLUE};
                break;
            case _QWERTY:
                default_color = (rgb_t){RGB_RED};
                break;
        }

        switch (layer) {
            case _WORKMAN:
            case _HOME:
            case _QWERTY:
                for (uint8_t i = 0; i < ARRAY_SIZE(RGB_LIST_MODIFIERS); i++) {
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[i], default_color.r, default_color.g, default_color.b);
                }

                // process modifiers
                if (active_mods & MOD_MASK_CTRL) {
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LCTL], RGB_RED);
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_RCTL], RGB_RED);
                }

                if (active_mods & MOD_MASK_SHIFT || is_caps_word_on()) {
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LSFT], RGB_RED);
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_RSFT], RGB_RED);
                }

                if (active_mods & MOD_MASK_ALT) {
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LOPT], RGB_RED);
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_ROPT], RGB_RED);
                }

                if (active_mods & MOD_MASK_GUI) {
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LCMD], RGB_RED);
                    rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_RCMD], RGB_RED);
                }
                break;
            case _LOWER:
                // Arrow keys
                for (uint8_t i = 0; i < ARRAY_SIZE(RGB_LIST_ARROWS); i++) {
                    if (active_mods & MOD_MASK_SHIFT) {
                        rgb_matrix_set_color(RGB_LIST_ARROWS[i], RGB_RED);
                    } else {
                        rgb_matrix_set_color(RGB_LIST_ARROWS[i], RGB_WHITE);
                    }
                }
                // Numpad
                for (uint8_t i = 0; i < ARRAY_SIZE(RGB_LIST_NUMPAD); i++) {
                    if (active_mods & MOD_MASK_SHIFT) {
                        rgb_matrix_set_color(RGB_LIST_NUMPAD[i], RGB_TEAL);
                    } else {
                        rgb_matrix_set_color(RGB_LIST_NUMPAD[i], RGB_GREEN);
                    }
                }
                break;
            case _RAISE:
                rgb_matrix_set_color_all(RGB_TEAL);
                break;
            case _ADJUST:
                rgb_matrix_set_color_all(RGB_RED);
                break;
            default:
                break;
        }
    }
    return false;
}

/* The firmware's entry point into the custom RGB logic */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t active_mods   = get_mods();
    uint8_t highest_layer = get_highest_layer(layer_state);
    return rgb_indicators_process_layer_user(highest_layer, active_mods);
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

/* Called after keyboard init. Used here to disable RGB effects an avoid conflicts with layer indication. */
void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
