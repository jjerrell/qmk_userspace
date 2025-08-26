// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)

#include "techworker.h"
#include "techworker_util.h"
#include <string.h>
#ifdef UNICODE_COMMON_ENABLE
#    include "keycodes/unicode.h"
#endif // UNICODE_COMMON_ENABLE
#ifdef LEADER_ENABLE
#    include "keycodes/leader.h"
#endif

userspace_config_t userspace_config;

#if defined(AUTOCORRECT_ENABLE)
#    if defined(AUDIO_ENABLE)
#        ifdef USER_SONG_LIST
float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
#        else  // USER_SONG_LIST
float autocorrect_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#        endif // USER_SONG_LISTq
#    endif
// 2 strings, 2q chars each + null terminator. max autocorrect length is 19 chars but 128px/6 supports 21 chars
char autocorrected_str[2][21]     = {"    automatically\0", "      corrected\0"};
char autocorrected_str_raw[2][21] = {"automatically\0", "corrected\0"};
bool autocorrect_str_has_changed  = false;

bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
    strncpy(autocorrected_str_raw[0], typo, sizeof(autocorrected_str_raw[0]) - 1);
    strncpy(autocorrected_str_raw[1], correct, sizeof(autocorrected_str_raw[1]) - 1);

    center_text(typo, autocorrected_str[0], sizeof(autocorrected_str[0]) - 1);
    center_text(correct, autocorrected_str[1], sizeof(autocorrected_str[1]) - 1);
    // printf("Autocorrected %s to %s (original: %s)\n", typo, correct, str);
    autocorrect_str_has_changed = true;

#    if defined(AUDIO_ENABLE)
    audio_play_melody(&autocorrect_song, NOTE_ARRAY_SIZE(autocorrect_song), false);
#    endif // AUDIO_ENABLE
    return true;
}
#endif

#if defined(CAPS_WORD_ENABLE)
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_MINS:
            if (!keymap_config.swap_lctl_lgui) {
                return true;
            }
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

#    if !defined(NO_ACTION_ONESHOT)
void oneshot_locked_mods_changed_user(uint8_t mods) {
    if (mods == MOD_BIT_LSHIFT || mods == MOD_BIT_RSHIFT) {
        del_mods(MOD_MASK_SHIFT);
        set_oneshot_locked_mods(~MOD_MASK_SHIFT & get_oneshot_locked_mods());
        caps_word_on();
    }
}
#    endif // !NO_ACTION_ONESHOT
#endif     // CAPS_WORD_ENABLE

#if defined(OS_DETECTION_ENABLE)
typedef struct {
    bool swap_ctl_gui;
#    ifdef UNICODE_COMMON_ENABLE
    uint8_t unicode_input_mode;
#    endif // UNICODE_COMMON_ENABLE
} os_detection_config_t;

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (is_keyboard_master()) {
        os_detection_config_t os_detection_config = {
            .swap_ctl_gui = false,
#    ifdef UNICODE_COMMON_ENABLE
            .unicode_input_mode = UNICODE_MODE_WINCOMPOSE,
#    endif // UNICODE_COMMON_ENABLE
        };
        switch (detected_os) {
            case OS_UNSURE:
                xprintf("unknown OS Detected\n");
                break;
            case OS_LINUX:
                xprintf("Linux Detected\n");
                os_detection_config = (os_detection_config_t){
                    .swap_ctl_gui = true,
#    ifdef UNICODE_COMMON_ENABLE
                    .unicode_input_mode = UNICODE_MODE_LINUX,
#    endif // UNICODE_COMMON_ENABLE
                };
                break;
            case OS_WINDOWS:
                xprintf("Windows Detected\n");
                os_detection_config = (os_detection_config_t){
                    .swap_ctl_gui = true,
                };
                break;
#    if 0
            case OS_WINDOWS_UNSURE:
                xprintf("Windows? Detected\n");
                break;
#    endif
            case OS_MACOS:
            case OS_IOS:
                xprintf("Apple OS Detected\n");
                os_detection_config = (os_detection_config_t){
                    .swap_ctl_gui = true,
#    ifdef UNICODE_COMMON_ENABLE
                    .unicode_input_mode = UNICODE_MODE_MACOS,
#    endif // UNICODE_COMMON_ENABLE
                };
                break;
#    if 0
            case OS_PS5:
                xprintf("PlayStation 5 Detected\n");
#        ifdef UNICODE_COMMON_ENABLE
                os_detection_config.unicode_input_mode = UNICODE_MODE_LINUX;
#        endif // UNICODE_COMMON_ENABLE
                break;
            case OS_HANDHELD:
                xprintf("Nintend Switch/Quest 2 Detected\n");
#        ifdef UNICODE_COMMON_ENABLE
                os_detection_config.unicode_input_mode = UNICODE_MODE_LINUX;
#        endif
                break;
#    endif
            default:
                xprintf("Unknown OS Detected\n");
                break;
        }
        keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = os_detection_config.swap_ctl_gui;
        eeconfig_update_keymap(keymap_config.raw);
#    ifdef UNICODE_COMMON_ENABLE
        set_unicode_input_mode_soft(os_detection_config.unicode_input_mode);
#    endif // UNICODE_COMMON_ENABLE
    }

    return true;
}
#endif // OS_DETECTION_ENABLE
