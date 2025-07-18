// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2018-2024 Nick Brassel (@tzarc)
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "techworker.h"
#include "process_records.h"
#include "version.h"

#if defined(RGBLIGHT_ENABLE)
#   include "rgb/light/rgb_light.h"
// #    include "rgb_legacy/rgb_stuff.h"
#endif // defined(RGBLIGHT_ENABLE)

#if defined(RGB_MATRIX_ENABLE)
#   include "rgb/matrix/rgb_matrix.h"
// #    include "rgb_legacy/rgb_matrix_stuff.h"
#endif // defined(RGB_MATRIX_ENABLE)

#ifdef UNICODE_COMMON_ENABLE
#    include "keycodes/unicode.h"
#endif // UNICODE_COMMON_ENABLE

#if defined(LEADER_ENABLE)
#    include "keycodes/leader.h"
#endif // LEADER_ENABLE

#if defined(AUDIO_ENABLE) && defined(OS_DETECTION_ENABLE)
#    include "audio.h"
#    ifndef CG_NORM_SONG
#        define CG_NORM_SONG SONG(AG_NORM_SOUND)
#    endif
#    ifndef CG_SWAP_SONG
#        define CG_SWAP_SONG SONG(AG_SWAP_SOUND)
#    endif
static float cg_norm_song[][2] = CG_NORM_SONG;
static float cg_swap_song[][2] = CG_SWAP_SONG;
#endif

uint16_t copy_paste_timer = 0;

// Defines actions for global custom keycodes, then runs
// the _keymap's record handier if not processed here

__attribute__((weak)) bool pre_process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pre_process_record_keymap(keycode, record);
}

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/*
    Fixes an issue with shifted keycodes being wrapped with MOD_T functions on the _RAISE layers.
    See https://docs.qmk.fm/#/mod_tap?id=intercepting-mod-taps for more info
*/
bool process_record_mod_intercept(uint16_t keycode, keyrecord_t *record) {
    // this could be a switch by getting highest layer if this becomes problematic on other layers
    if (IS_LAYER_ON(_RAISE)) {
        switch (keycode) {
            case CTL_T(KC_HASH):
            case CTL_T(KC_CIRC):
            case CTL_T(KC_QUES):
            case ALT_T(KC_RPRN):
            case ALT_T(KC_LCBR):
            case ALT_T(KC_RCBR):
            case GUI_T(KC_RCBR):
            case GUI_T(KC_LPRN):
            case GUI_T(KC_RPRN):
                // Check tap.count to make sure we aren't processing a modifier
                if (record->tap.count && record->event.pressed) {
                    // Apply shift
                    register_code(KC_LSFT);
                    // Using tap_code16 we can send the uint16_t keycode parameter
                    tap_code16(keycode);
                    // Release shift
                    unregister_code(KC_LSFT);
                    // stop processing this keycode or the firmware will send the unshifted keycode also
                    return false;
                }
                // Modifier processing or not enough time elapsed to determine if it's a tap
                break;
        }
    }
    return true;
}

/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!(process_record_mod_intercept(keycode, record) && process_record_keymap(keycode, record) &&
          process_record_secrets(keycode, record)
#ifdef CUSTOM_RGB_MATRIX
          && process_record_user_rgb_matrix(keycode, record)
#endif // CUSTOM_RGB_MATRIX
#ifdef CUSTOM_RGBLIGHT
          && process_record_user_rgb_light(keycode, record)
#endif // CUSTOM_RGBLIGHT
#ifdef CUSTOM_UNICODE_ENABLE
          && process_record_unicode(keycode, record)
#endif // CUSTOM_UNICODE_ENABLE
#if defined(CUSTOM_POINTING_DEVICE)
          && process_record_pointing(keycode, record)
#endif // CUSTOM_POINTING_DEVICE
#ifdef CUSTOM_DYNAMIC_MACROS_ENABLE
          && process_record_dynamic_macro(keycode, record)
#endif // CUSTOM_DYNAMIC_MACROS_ENABLE
          && true)) {
        return false; // Stop processing
    }

    switch (keycode) {
        case KC_MAKE:
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP), TAP_CODE_DELAY);
                send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
            }
            return false;
            break;
        case KC_ARRW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
            break;
        case KC_VRSN:
            if (record->event.pressed) {
                send_string_with_delay_P(
                    PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE), TAP_CODE_DELAY);
            }
            return false;
            break;
        case KC_CCCV: // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                // Hold, copy
                switch (detected_host_os()) {
                    case OS_LINUX:
                    case OS_WINDOWS:
                    case OS_UNSURE:
                        SEND_STRING(SS_LCTL("c"));
                        break;
                    default:
                        SEND_STRING(SS_LGUI("c"));
                        break;
                }
            } else {
                // Tap, paste
                switch (detected_host_os()) {
                    case OS_LINUX:
                    case OS_WINDOWS:
                    case OS_UNSURE:
                        SEND_STRING(SS_LCTL("v"));
                        break;
                    default:
                        SEND_STRING(SS_LGUI("v"));
                        break;
                }
            }
            return false;
            break;
        case KC_RGBT:
#if defined(CUSTOM_RGBLIGHT) || defined(CUSTOM_RGB_MATRIX)
            if (record->event.pressed) {
                rgb_layer_indication_toggle();
            }
#endif // CUSTOM_RGBLIGHT || CUSTOM_RGB_MATRIX
#if defined(OS_DETECTION_ENABLE)
        case QK_MAGIC_SWAP_LCTL_LGUI:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = true;
                clear_keyboard();
#    if defined(UNICODE_COMMON_ENABLE)
                set_unicode_input_mode_soft(keymap_config.swap_lctl_lgui ? UNICODE_MODE_MACOS
                                                                         : UNICODE_MODE_WINCOMPOSE);
#    endif
            }
            return false;
        case QK_MAGIC_SWAP_RCTL_RGUI:
            if (record->event.pressed) {
                keymap_config.swap_rctl_rgui = true;
                clear_keyboard();
            }
            return false;
        case QK_MAGIC_SWAP_CTL_GUI:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
#    ifdef AUDIO_ENABLE
                PLAY_SONG(cg_swap_song);
#    endif
                clear_keyboard();
#    if defined(UNICODE_COMMON_ENABLE)
                set_unicode_input_mode_soft(keymap_config.swap_lctl_lgui ? UNICODE_MODE_MACOS
                                                                         : UNICODE_MODE_WINCOMPOSE);
#    endif
            }
            return false;
        case QK_MAGIC_UNSWAP_LCTL_LGUI:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = false;
                clear_keyboard();
#    if defined(UNICODE_COMMON_ENABLE)
                set_unicode_input_mode_soft(keymap_config.swap_lctl_lgui ? UNICODE_MODE_MACOS
                                                                         : UNICODE_MODE_WINCOMPOSE);
#    endif
            }
            return false;
        case QK_MAGIC_UNSWAP_RCTL_RGUI:
            if (record->event.pressed) {
                keymap_config.swap_rctl_rgui = false;
                clear_keyboard();
            }
            return false;
        case QK_MAGIC_UNSWAP_CTL_GUI:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
#    ifdef AUDIO_ENABLE
                PLAY_SONG(cg_norm_song);
#    endif
                clear_keyboard();
#    if defined(UNICODE_COMMON_ENABLE)
                set_unicode_input_mode_soft(keymap_config.swap_lctl_lgui ? UNICODE_MODE_MACOS
                                                                         : UNICODE_MODE_WINCOMPOSE);
#    endif
            }
            return false;
        case QK_MAGIC_TOGGLE_CTL_GUI:
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
                keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;
#    ifdef AUDIO_ENABLE
                if (keymap_config.swap_rctl_rgui) {
                    PLAY_SONG(cg_swap_song);
                } else {
                    PLAY_SONG(cg_norm_song);
                }
#    endif
                clear_keyboard();
#    if defined(UNICODE_COMMON_ENABLE)
                set_unicode_input_mode_soft(keymap_config.swap_lctl_lgui ? UNICODE_MODE_MACOS
                                                                         : UNICODE_MODE_WINCOMPOSE);
#    endif
            }
            return false;
#endif // OS_DETECTION_ENABLE
    }
    return true; // Keep processing
}

bool process_autocorrect_user(uint16_t *keycode, keyrecord_t *record, uint8_t *typo_buffer_size, uint8_t *mods) {
    // See quantum_keycodes.h for reference on these matched ranges.
    switch (*keycode) {
        // Exclude these keycodes from processing.
        case KC_LSFT:
        case KC_RSFT:
        case KC_CAPS:
        case QK_TO ... QK_ONE_SHOT_LAYER_MAX:
        // case QK_LAYER_TAP_TOGGLE ... QK_LAYER_MOD_MAX: // LAYER_* is disabled for all boards
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
            return false;

        // Mask for base keycode from shifted keys.
        case QK_LSFT ... QK_LSFT + 255:
        case QK_RSFT ... QK_RSFT + 255:
            if (*keycode >= QK_LSFT && *keycode <= (QK_LSFT + 255)) {
                *mods |= MOD_LSFT;
            } else {
                *mods |= MOD_RSFT;
            }
            *keycode &= 0xFF; // Get the basic keycode.
            return true;
#ifndef NO_ACTION_TAPPING
        // Exclude tap-hold keys when they are held down
        // and mask for base keycode when they are tapped.
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
#    ifdef NO_ACTION_LAYER
            // Exclude Layer Tap, if layers are disabled
            // but action tapping is still enabled.
            return false;
#    endif
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            // Exclude hold if mods other than Shift is not active
            if (!record->tap.count) {
                return false;
            }
            *keycode &= 0xFF;
            break;
#else
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Exclude if disabled
            return false;
#endif
        // Exclude swap hands keys when they are held down
        // and mask for base keycode when they are tapped.
        case QK_SWAP_HANDS ... QK_SWAP_HANDS_MAX:
#ifdef SWAP_HANDS_ENABLE
            if (*keycode >= 0x56F0 || !record->tap.count) {
                return false;
            }
            *keycode &= 0xFF;
            break;
#else
            // Exclude if disabled
            return false;
#endif
    }

    // Disable autocorrect while a mod other than shift is active.
    if ((*mods & ~MOD_MASK_SHIFT) != 0) {
        *typo_buffer_size = 0;
        return false;
    }

    return true;
}

void rgb_layer_indication_toggle(void) {
    userspace_config.rgb.layer_change ^= 1;
    dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb.layer_change);
    eeconfig_update_user_datablock_handler(&userspace_config, 0, EECONFIG_USER_DATA_SIZE);
    if (userspace_config.rgb.layer_change) {
#if defined(CUSTOM_RGB_MATRIX)
        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW | LED_FLAG_KEYLIGHT | LED_FLAG_INDICATOR);
#    if defined(CUSTOM_RGBLIGHT)
        rgblight_enable_noeeprom();
#    endif                            // CUSTOM_RGBLIGHT
#endif                                // CUSTOM_RGB_MATRIX
        layer_state_set(layer_state); // This is needed to immediately set the layer color (looks better)
#if defined(CUSTOM_RGB_MATRIX)
    } else {
        rgb_matrix_set_flags(LED_FLAG_ALL);
#    if defined(CUSTOM_RGBLIGHT)
        rgblight_disable_noeeprom();
#    endif // CUSTOM_RGBLIGHT
#endif     // CUSTOM_RGB_MATRIX
    }
}
