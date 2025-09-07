// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "leader.h"

// Leader start
__attribute__((weak)) void leader_start_keymap(void) {}
__attribute__((weak)) void leader_start_secret(void) {}

void leader_start_user(void) {
#ifndef NO_SECRETS
    leader_start_secret();
#endif
    leader_start_keymap();
}

// Leader end
__attribute__((weak)) bool leader_end_keymap(void) {
    return true;
}
__attribute__((weak)) bool leader_end_secret(void) {
    return true;
}

void leader_end_user(void) {
    // only run the process if the keymap or secret implementation did not find a match
    if (leader_end_keymap() && leader_end_secret()) {
        if (leader_sequence_one_key(KC_R)) {
            // Rebuild / Run
            switch (detected_host_os()) {
                case OS_MACOS:
                case OS_IOS:
                    SEND_STRING(SS_LGUI("r"));
                    break;
                default:
                    tap_code16(KC_F5);
                    break;
            }
        } else if (leader_sequence_two_keys(KC_B, KC_D)) {
            // Build info
            send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE),
                                     TAP_CODE_DELAY);
        }
    }
}