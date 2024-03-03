/* Copyright 2015-2021 Jack Humbert
 * Copyright 2021-2024 Jacob Jerrell <@jjerrell>
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

#ifdef KEYBOARD_planck_ez_glow
#    undef PRODUCT
#    define PRODUCT "Planck EZ Glow - Modified by <@jjerrell>"
#endif

#define LEADER_NO_TIMEOUT

// Get some keycodes and functionality for free See qmk_firmware/keyboards/planck/ez/ez.c
#define ORYX_CONFIGURATOR
#define PLANCK_EZ_USER_LEDS

#define CUSTOM_RGB_INDICATORS

/*
 * Default Planck config
 */

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(WORKMAN_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
// #define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
// #define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
