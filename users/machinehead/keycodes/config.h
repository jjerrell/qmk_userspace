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

#if defined(COMMUNITY_MODULE_ACHORDION_ENABLE)
#    define PERMISSIVE_HOLD
#    define QUICK_TAP_TERM_PER_KEY
#else
#   define TAPPING_TERM 220
#   define QUICK_TAP_TERM 120
#   define TAPPING_TERM_PER_KEY
#endif // COMMUNITY_MODULE_ACHORDION_ENABLE

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif // !TAPPING_TOGGLE

#define ENABLE_COMPILE_KEYCODE

#define ENABLE_RAISE_MIGRATION