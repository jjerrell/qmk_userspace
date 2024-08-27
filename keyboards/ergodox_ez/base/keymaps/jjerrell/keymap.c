#include QMK_KEYBOARD_H
#include "version.h"
#include "layouts.h"

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | Esc    |   1  |   2  |   3  |   4  |   5  |  ->  |           |  -   |   6  |   7  |   8  |   9  |   0  |   =    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   D  |   R  |   W  |   B  |  (   |           |  )   |   J  |   F  |   U  |   P  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | CapWrd |   A  |S/Shft|H/Cmd |T/Alt |   G  |------|           |------|   Y  | N/Alt| E/Cmd|O/Shft|   I  |   '    |
    * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
    * | LShift |Z/Ctrl|   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |//Ctrl| RShift |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | Lead |      |      | Up   | Left |                                       | Right| Down |      |      | GAME |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+--------+------.
    *                                 |      |      |      |       |      |        |      |
    *                                 |Space |BckSpc|------|       |------|  Tab   | Enter|
    *                                 |      |      |RAISE |       | LOWER|        |      |
    *                                 `--------------------'       `----------------------'
    */
    [_WORKMAN] = KEYMAP_ergodox_modifiers(
        KC_ESC,  _________________NUMBERS_L_________________, KC_ARROW,    KC_MINS, _________________NUMBERS_R_________________, KC_EQL,
        KC_TAB,  _________________WORKMN_L1_________________, KC_LPRN,     KC_RPRN, _________________WORKMN_R1_________________, KC_BSLS,
        CW_TOGG, _________________WORKMN_L2_________________,                       _________________WORKMN_R2_________________, KC_QUOT,
        KC_LSFT, _________________WORKMN_L3_________________, KC_LBRC,     KC_RBRC, _________________WORKMN_R3_________________, KC_RSFT,
        QK_LEAD, XXXXXXX, XXXXXXX, KC_UP, KC_LEFT,                                          KC_RIGHT, KC_DOWN, XXXXXXX, XXXXXXX, KC_GAME,
                                                    XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                            XXXXXXX,     XXXXXXX, 
                                            KC_SPC, KC_BSPC, KC_RISE,     KC_LOWR, KC_TAB, KC_ENTER
    ),
    [_LOWER] = KEYMAP_ergodox_modifiers(
        KC_HYPR, _______________________FROW_L_______________________,     _______________________FROW_R_______________________, KC_MEH,
        _______, _________________LOWER_L1__________________, _______,     _______, _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________,                       _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________, _______,     _______, _________________LOWER_R3__________________, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             KC_0, KC_DOT, KC_COMM, KC_PLUS, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    ),
    [_RAISE] = KEYMAP_ergodox_modifiers(
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _________________RAISE_L1__________________, _______,     _______, _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________,                       _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________, _______,     _______, _________________RAISE_R3__________________, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    ),
    /* Adjust (Lower + Raise) */
    [_ADJUST] = KEYMAP_ergodox_layers(
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _________________ADJUST_L1_________________, _______,     _______, _________________ADJUST_R1_________________, _______,
        _______, _________________ADJUST_L2_________________,                       _________________ADJUST_R2_________________, _______,
           VRSN, _________________ADJUST_L3_________________, _______,     _______, _________________ADJUST_R3_________________, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    )
};

// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_keymap(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_DEFAULT);

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

/* 
    Setup to light up a combination of the 3 leds to indicate which modifiers are active.
    Note that if a layer change occurs, this will not override any changes from the resulting layer.
*/
void matrix_scan_keymap(void) {
    uint8_t modifiers = get_mods();
    uint8_t layer_is_default = layer_state_is(_WORKMAN) || layer_state_is(_QWERTY);

    if (modifiers && layer_is_default) {
        if (modifiers & MOD_MASK_CSAG) {
            // All modifiers are set
            ergodox_led_all_on();
            // Double LED 2's brightness since both control and command/win modifiers are active
            ergodox_right_led_2_set(LED_BRIGHTNESS_DEFAULT * 2);
        } else {
            // Individual if/else blocks so the lights shut off if multiple mods are registered and one is released
            if (modifiers & MOD_MASK_SHIFT) {
                ergodox_right_led_1_on();
            } else {
                ergodox_right_led_1_off();
            }

            if (modifiers & MOD_MASK_ALT) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }

            if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_GUI)) {
                // Control and CMD share a light. If both are held, the brightness is doubled
                ergodox_right_led_2_set(LED_BRIGHTNESS_DEFAULT * 2);
                ergodox_right_led_2_on();
            } else if ((modifiers & MOD_MASK_CTRL) || (modifiers & MOD_MASK_GUI)) {
                // Only one of Control and CMD are active, use default brightness
                ergodox_right_led_2_set(LED_BRIGHTNESS_DEFAULT);
                ergodox_right_led_2_on();
            } else {
                ergodox_right_led_2_off();
            }
        }
    } else if (layer_is_default) {
        // reset brightness and shutoff LEDs unless we're on an alternate layer
        ergodox_led_all_set(LED_BRIGHTNESS_DEFAULT);
        ergodox_led_all_off();
    }
};
