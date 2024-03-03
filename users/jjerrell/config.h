/* Copyright 2024 Jacob Jerrell <@jjerrell>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING

#if defined(TAP_CODE_DELAY)
#    undef TAP_CODE_DELAY
#endif
#define TAP_CODE_DELAY 20

#ifdef RGB_MATRIX_ENABLE
#    define RGBLIGHT_SLEEP        // enable rgblight_suspend() and rgblight_wakeup() in keymap.c
#    define RGBLIGHT_TIMEOUT 6000 // ms to wait until rgblight time out
#endif                            // RGB_MATRIX_ENABLE

// Space savers
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define NO_ACTION_ONESHOT

#define NO_MUSIC_MODE

// https://docs.qmk.fm/#/feature_secure?id=secure