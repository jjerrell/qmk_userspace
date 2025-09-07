// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2025 Jacob Jerrell (@jjerrell)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "machinehead.h"
#include "machinehead_runtime.h"
#include "sendchar.h"
#include "print.h"

#ifdef CUSTOM_UNICODE_ENABLE
void keyboard_post_init_unicode(void);
#endif // CUSTOM_UNICODE_ENABLE

#ifdef SPLIT_KEYBOARD
#    include "split_util.h"
#    include "split/transport_sync.h"
#endif // SPLIT_KEYBOARD

#if defined(RGB_MATRIX_CUSTOM_USER)
#    include "rgb/rgb_matrix_custom.h"
#endif // CUSTOM_RGB_MATRIX

user_runtime_config_t userspace_runtime_state;

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps

/**
 * @brief Keyboard Pre-Initialization
 *
 */
__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void                       keyboard_pre_init_user(void) {
    eeconfig_read_user_datablock_handler(&userspace_config, 0, EECONFIG_USER_DATA_SIZE);
    if (!eeconfig_is_user_datablock_valid() || !userspace_config.debug.check) {
        eeconfig_init_user();
    }
    keyboard_pre_init_keymap();
}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
#if defined(RGB_MATRIX_CUSTOM_USER)
    keyboard_post_init_rgb_matrix();
#endif // RGB_MATRIX_CUSTOM_USER
#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
    keyboard_post_init_transport_sync();
#endif // SPLIT_KEYBOARD && SPLIT_TRANSACTION_IDS_USER
#ifdef CUSTOM_UNICODE_ENABLE
    keyboard_post_init_unicode();
#endif // CUSTOM_UNICODE_ENABLE
#ifdef DEBUG_MATRIX_SCAN_RATE_ENABLE
    userspace_config.debug.matrix_scan_print = true;
#endif // DEBUG_MATRIX_SCAN_RATE_ENABLE

#if defined(BOOTLOADER_CATERINA) && defined(__AVR__) && defined(__AVR_ATmega32U4__)
    DDRD &= ~(1 << 5);
    PORTD &= ~(1 << 5);

    DDRB &= ~(1 << 0);
    PORTB &= ~(1 << 0);
#endif // BOOTLOADER_CATERINA && __AVR__ && __AVR_ATmega32U4__

    keyboard_post_init_keymap();
}

/**
 * @brief Callback for software shutdown
 *
 */
__attribute__((weak)) bool shutdown_keymap(bool jump_to_bootloader) {
    return true;
}

bool shutdown_user(bool jump_to_bootloader) {
    if (!shutdown_keymap(jump_to_bootloader)) {
        return false;
    }
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_shutdown(jump_to_bootloader);
#endif // RGB_MATRIX_ENABLE
    return true;
}

/**
 * @brief Suspend power down callback (constantly called when suspended)
 *
 */
__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) {
    set_is_device_suspended(true);
    if (layer_state_is(_GAMEPAD)) {
        layer_off(_GAMEPAD);
    }
#ifdef OLED_ENABLE
    oled_off();
#endif // OLED_ENABLE

#ifdef CUSTOM_QUANTUM_PAINTER_ENABLE
    suspend_power_down_quantum_painter();
#endif // CUSTOM_QUANTUM_PAINTER_ENABLE

    suspend_power_down_keymap();
}

/**
 * @brief Suspend wake-up callback (only called when actually waking up)
 *
 */
__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}
void                       suspend_wakeup_init_user(void) {
    // hack for re-enabling oleds/lights/etc when woken from usb
    void last_matrix_activity_trigger(void);
    last_matrix_activity_trigger();

    set_is_device_suspended(false);
#ifdef CUSTOM_QUANTUM_PAINTER_ENABLE
    suspend_wakeup_init_quantum_painter();
#endif // CUSTOM_QUANTUM_PAINTER_ENABLE
    suspend_wakeup_init_keymap();
}

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    state = layer_state_set_keymap(state);

    return state;
}

// Runs state check and changes underglow color and animation
__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state;
    }

    state = default_layer_state_set_keymap(state);

    return state;
}

/**
 * @brief EEPROM comfiguration initialization
 *
 */
__attribute__((weak)) void eeconfig_init_keymap(void) {}
void                       eeconfig_init_user(void) {
    memset(&userspace_config, 0, sizeof(userspace_config_t));
    userspace_config.debug.check      = true;
    userspace_config.rgb.layer_change = true;

    // ensure that nkro is enabled
    keymap_config.raw  = eeconfig_read_keymap();
    keymap_config.nkro = true;
    eeconfig_update_keymap(keymap_config.raw);

    eeconfig_init_keymap();
    eeconfig_update_user_datablock_handler(&userspace_config, 0, EECONFIG_USER_DATA_SIZE);
#ifdef COMMUNITY_MODULE_POINTING_DEVICE_ACCEL_ENABLE
    void eeconfig_init_pointing_device(void);
    eeconfig_init_pointing_device();
#endif // COMMUNITY_MODULE_POINTING_DEVICE_ACCEL_ENABLE
}

/**
 * @brief Matrix scan callback ... only use for matrix scan rate task
 *
 */
void matrix_scan_user(void) {}

/**
 * @brief Handle slave side scanning of keyboard
 *
 */
#ifdef SPLIT_KEYBOARD
__attribute__((weak)) void matrix_slave_scan_keymap(void) {}
void                       matrix_slave_scan_user(void) {
#    if defined(AUDIO_ENABLE) && defined(AUDIO_INIT_DELAY)
#        if defined(SPLIT_WATCHDOG_ENABLE) && !defined(SPLIT_WATCHDOG_TIMEOUT)
#            if defined(SPLIT_USB_TIMEOUT)
#                define SPLIT_WATCHDOG_TIMEOUT (SPLIT_USB_TIMEOUT + 100)
#            else
#                define SPLIT_WATCHDOG_TIMEOUT 3000
#            endif
#        endif
        if (!is_keyboard_master()) {
            static bool     delayed_tasks_run  = false;
            static uint16_t delayed_task_timer = 0;
            if (!delayed_tasks_run) {
                if (!delayed_task_timer) {
                    delayed_task_timer = timer_read();
                } else if (timer_elapsed(delayed_task_timer) > (SPLIT_WATCHDOG_TIMEOUT + 100) && is_transport_connected()) {
                    audio_startup();
                    delayed_tasks_run = true;
                }
            }
        }
#    endif // AUDIO_ENABLE && AUDIO_INIT_DELAY
    matrix_slave_scan_keymap();
}
#endif // SPLIT_KEYBOARD

/**
 * @brief Housekeyping task
 *
 * sets userspace_runtime_state config to be synced later or just used. Also runs other "every tick" tasks
 */
__attribute__((weak)) void housekeeping_task_keymap(void) {}
void                       housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        // we check if audio is enabled as it's only ran on master
#ifdef AUDIO_ENABLE
        userspace_runtime_state.audio.enable = is_audio_on();
#    ifdef AUDIO_CLICKY
        userspace_runtime_state.audio.clicky_enable = is_clicky_on();
        extern float clicky_freq;
        extern float clicky_rand;
        userspace_runtime_state.audio.clicky_freq = clicky_freq;
        userspace_runtime_state.audio.clicky_rand = clicky_rand;
#    endif // AUDIO_CLICKY
#    ifdef MUSIC_ENABLE
        userspace_runtime_state.audio.music_enable = is_music_on();
#    endif
#endif // AUDIO_ENABLE
    }
#if defined(RGB_MATRIX_CUSTOM_USER)
    housekeeping_task_rgb_matrix();
#endif // RGB_MATRIX_CUSTOM_USER
#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
    housekeeping_task_transport_sync();
#endif // SPLIT_KEYBOARD && SPLIT_TRANSACTION_IDS_USER
    housekeeping_task_keymap();
}
