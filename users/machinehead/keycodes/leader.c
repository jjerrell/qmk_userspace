// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "leader.h"

// Leader start
__attribute__((weak)) void leader_start_keymap(void) {}

void leader_start_user(void) {
    leader_start_keymap();
}

// Leader end
__attribute__((weak)) bool leader_end_keymap(void) {
    return true;
}

void leader_end_user(void) {
    if (leader_end_keymap()) {
        if (leader_sequence_one_key(KC_R)) {
            // Rebuild / Run
            SEND_STRING(SS_LGUI("r"));
        } else if (leader_sequence_two_keys(KC_B, KC_D)) {
            // Build info
            send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE),
                                     TAP_CODE_DELAY);
        }
    }
}
