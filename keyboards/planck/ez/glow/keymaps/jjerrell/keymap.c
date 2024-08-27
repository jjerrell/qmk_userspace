/* Copyright 2015-2021 Jack Humbert
 * Copyright 2024 Jacob Jerrell <@jjerrell>
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

#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif
#include "layouts.h"

#define LYR_TGL TOGGLE_LAYER_COLOR

enum planck_keycodes {
  BACKLIT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Default - Workman layout
    * ,-----------------------------------------------------------------------------------.
    * |   Q  |   D  |  R   |   W  |   B  |  ->  |  -   |   J  |   F  |   U  |   P  |  ;   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   A  |   S  |  H   |   T  |   G  |   (  |  )   |   Y  |   N  |   E  |   O  |  I   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   Z  |   X  |  M   |   C  |   V  |   [  |  ]   |   K  |   L  |   ,  |   .  |  /   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LEAD | HYPR |      | SCAP | BSPC |    Space    | ENTR |  RGB |LYR_TG|  MEH |LED_CG|
    * `-----------------------------------------------------------------------------------'
    */
    [_WORKMAN] = KEYMAP_planck_modifiers(
        _________________WORKMN_L1_________________, KC_ARROW, KC_MINS, _________________WORKMN_R1_________________,
        _________________WORKMN_L2_________________, KC_LPRN,  KC_RPRN, _________________WORKMN_R2_________________,
        _________________WORKMN_L3_________________, KC_LBRC,  KC_RBRC, _________________WORKMN_R3_________________,
        QK_LEAD, KC_HYPR, XXXXXXX, CW_TOGG, KC_BSPC,      KC_SPC,       KC_ENT, RGB_TOG, LYR_TGL, KC_MEH, LED_LEVEL
    ),
    /* Lower - Nav/Select/Nums
    * ,-----------------------------------------------------------------------------------.
    * | PGUP | BSPC |  UP  | DEL  | PGDN |      |      |      |   7  |   8  |   9  |  *   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | HOME | LEFT | DOWN | RGHT | END  |      |      |      |   4  |   5  |   6  |  /   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | ESC  | TAB  | CUT  | ENTR |CpyPst|      |      |      |   1  |   2  |   3  |  -   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | held |    SPACE    | ENTR |   0  |   .  |   ,  |  +   |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = KEYMAP_planck_modifiers(
        _________________LOWER_L1__________________, _______, _______, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _______, _______, _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________,
        _______, _______,  _______,  _______, KC_BSPC,     KC_SPC,     KC_ENT,  _____________LOWER_R4_____________
    ),
    /* Raise - Symbols
    * ,-----------------------------------------------------------------------------------.
    * |   |  |   -  |   [  |   ]  |   &  |      |      |   !  |   <  |   >  |   _  |  :   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   \  |   /  |   (  |   )  |   *  |      |      |   ?  |   {  |   }  |   =  |  ;   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   #  |   $  |   %  |   ~  |   `  |      |      |   @  |   '  |   "  |   +  |  ^   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | BSPC |    SPACE    | held |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = KEYMAP_planck_modifiers(
        _________________RAISE_L1__________________, _______, _______, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _______, _______, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _______, _______, _________________RAISE_R3__________________,
        _______, _______, _______, _______, KC_BSPC,       KC_SPC,     KC_ENT,  _______, _______, _______, _______
    ),
    /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * | Make | Debug| Reset|QWERTY|WRKMAN|      |      |MusNxt|Mus On|MusOff|MidiOn|MidOff|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Mute | Vol- | Vol+ | Play | Skip |      |      |AudNxt| HUE+ | HUE- | SAT+ | SAT- |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Vrsn | AudOn|AudOff|CGswap|CGnorm|      |      |AudPrv|RGBTog|RGBMod|BRGHT+|BRGHT-|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | held |             | held |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = KEYMAP_planck_layers(
        _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _______, _______, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _______, _______, _________________ADJUST_R3_________________,
        _______, _______, _______, _______, _______,     XXXXXXX,      _______, _______, _______, _______, _______
    )
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_keymap(layer_state_t state) {
    planck_ez_right_led_level(10);
    planck_ez_left_led_level(10);
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    switch (get_highest_layer(state)) {
        case _LOWER:
            planck_ez_left_led_on();
            break;
        case _RAISE:
            planck_ez_right_led_on();
            break;
        case _ADJUST:
            planck_ez_right_led_on();
            planck_ez_left_led_on();
            break;
        default:
            break;
    }
    return state;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LYR_TGL:
      if (record->event.pressed) {
          // extending TOGGLE_LAYER_COLOR to also toggle rgb_matrix
          rgb_matrix_toggle_noeeprom();
      }
      // keep processing for normal funtionality
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool rgb_indicators_process_keymap(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color_all(RGB_OFF);
    switch (get_highest_layer(layer_state)) {
        case 0:
            // Thumb keys
            rgb_matrix_set_color(40, RGB_WHITE);
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case _LOWER:
            // Thumb keys
            rgb_matrix_set_color(40, RGB_OFF);
            rgb_matrix_set_color(42, RGB_RED);
            break;
        case _RAISE:
            // light up the alpha key ranges
            for (uint16_t i = 0; i <= 46; i++) {
                switch (i) {
                    case 0 ... 4:
                    case 7 ... 16:
                    case 19 ... 28:
                    case 31 ... 35:
                        rgb_matrix_set_color(i, RGB_MAGENTA);
                        break;
                    default:
                        rgb_matrix_set_color(i, RGB_OFF);
                        break;
                }
            }
            // Thumb keys
            rgb_matrix_set_color(40, RGB_RED);
            rgb_matrix_set_color(42, RGB_OFF);
            break;
        case _ADJUST:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }
    return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_keymap(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case _RAISE:
    case _LOWER:
      return false;
    default:
      return true;
  }
}
