// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

// Use to control migration to the new symbol layout
#define MIGRATE_SYMBOLS

#ifndef ONESHOT_TAP_TOGGLE
#    define ONESHOT_TAP_TOGGLE 2
#endif // !ONESHOT_TAP_TOGGLE

#ifndef ONESHOT_TIMEOUT
#    define ONESHOT_TIMEOUT 3000
#endif // !ONESHOT_TIMEOUT

#if defined(PER_KEY_TAPPING)
#    define PERMISSIVE_HOLD_PER_KEY
#    define QUICK_TAP_TERM_PER_KEY
#    define HOLD_ON_OTHER_KEY
#    define RETRO_TAPPING_PER_KEY
#    define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    define TAPPING_TERM_PER_KEY
#elif defined(COMMUNITY_MODULE_ACHORDION_ENABLE)
#    define PERMISSIVE_HOLD
#    define QUICK_TAP_TERM_PER_KEY
#endif // PER_KEY_TAPPING

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif // !TAPPING_TOGGLE

#define ENABLE_COMPILE_KEYCODE
