// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)

#pragma once

#ifdef IS_COMMAND
#    undef IS_COMMAND
#endif // IS_COMMAND
#define IS_COMMAND() (((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT)

#define FLOW_TAP_TERM 150

#define TAP_CODE_DELAY 5

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif // LOCKING_SUPPORT_ENABLE
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif // LOCKING_RESYNC_ENABLE

#ifdef LEADER_ENABLE
#    define LEADER_TIMEOUT 250
#    define LEADER_PER_KEY_TIMING
#endif

#ifndef NO_PRINT
#    define NO_PRINT
#endif
