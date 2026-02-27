/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#pragma once

#define TAPPING_TERM_PER_KEY

#define MOONLANDER_USER_LEDS

#define RGBLIGHT_LED_COUNT (16 + 16)
#define RGBLIGHT_STARTUP_ANIMATION

#define CHORDAL_HOLD_LAYOUT LAYOUT_moonlander_wrapper( \
    'L', 'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R', 'R', \
    'L', 'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R', 'R', \
    'L', 'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R', 'R', \
    'L', 'L', 'L', 'L', 'L', 'L',             'R', 'R', 'R', 'R', 'R', 'R', \
    'L', 'L', 'L', 'L', 'L',      '*',   '*',      'R', 'R', 'R', 'R', 'R', \
                        '*', '*', '*',   '*', '*', '*'                      \
)
