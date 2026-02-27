// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2025 Jacob Jerrell (@jjerrell)

#pragma once

// clang-format off
#define _________________WORKMAN_L1________________    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B
#define _________________WORKMAN_L2________________    KC_A,    KC_S,    KC_H,    KC_T,    KC_G
#define _________________WORKMAN_L3________________    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V

#define _________________WORKMAN_R1________________    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________QWERTY_L1_________________    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________    KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ____THUMBS_L____                               GUI_SPC, LWR_BSP
#define ____THUMBS_R____                               RSE_TAB, SFT_ENT

// Pre-defines
#define ________________NUMBER_LEFT________________    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________    KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define ___________________BLANK___________________    _______, _______, _______, _______, _______

// Lower
#define _________________LOWER_L1__________________    KC_PGUP, KC_TAB,  KC_UP,   KC_ENT,  KC_PGDN
#define _________________LOWER_L2__________________    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _________________LOWER_L3__________________    KC_ESC,  KC_BSPC, KC_CUT,  KC_DEL,  KC_CCCV


#define _________________LOWER_R1__________________    KC_MINS, KC_7,    KC_8,    KC_9,    KC_PLUS
#define _________________LOWER_R2__________________    KC_ASTR, KC_4,    KC_5,    KC_6,    KC_SLSH   
#define _________________LOWER_R3__________________    KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT

// Raise
/*
,-------------------------------------------------------------------------------.
|   \   |   /   |   |   |   &   |   -   |   !   |   #   |   $   |   %   |   ^   |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
|   <   |   [   |   (   |   {   |  ->   |   @   |   }   |   )   |   ]   |   >   |
|-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
|   `   |   ;   |   :   |   +   |   =   |   ~   |   "   |   '   |   _   |   ?   |
`-------------------------------------------------------------------------------'
*/

/* RAISE - Alt
,---------------------------------------.  ,---------------------------------------.
|   \   |   @   |   #   |   &   |   !   |  |   =   |   |   |   $   |   *   |   ^   |
|-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
|   <   |   >   |   (   |   )   |  ->   |  |   :   |   {   |   }   |   [   |   ]   |
|-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
|   /   |   %   |   -   |   "   |   `   |  |   ~   |   '   |   +   |   _   |   ;   |
`---------------------------------------'  `---------------------------------------'
* Theory (Index/Middle = Primary; Ring/Pinky = Secondary):
* - Home row
*   - Rolling function signatures on primaries: `():`, `() {`, `() ->`, etc
*   - Consistent accessors on secondaries:  `<>`, `[]`
* - Top row
*   - Rolling or consistent operands on primaries: `!=`, `&&`, `||`
*   - Common symbols in programming
* - Bottom row
*   - Common general use symbols.
*/
#ifdef ENABLE_RAISE_MIGRATION
#   define _________________RAISE_L1__________________  KC_BSLS, KC_AT,   KC_HASH, KC_AMPR, KC_EXLM
#   define _________________RAISE_L2__________________  KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_ARRW
#   define _________________RAISE_L3__________________  KC_SLSH, KC_PERC, KC_MINS, KC_DQUO, KC_GRV

#   define _________________RAISE_R1__________________  KC_EQL,  KC_PIPE, KC_DLR,  KC_ASTR, KC_CIRC
#   define _________________RAISE_R2__________________  KC_COLN, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC
#   define _________________RAISE_R3__________________  KC_TILD, KC_QUOT, KC_PLUS, KC_UNDS, KC_SCLN
#else // !ENABLE_RAISE_MIGRATION
#   define _________________RAISE_L1__________________  KC_BSLS, KC_SLSH, KC_PIPE, KC_AMPR, KC_MINS
#   define _________________RAISE_L2__________________  KC_LABK, KC_LBRC, KC_LPRN, KC_LCBR, KC_ARRW
#   define _________________RAISE_L3__________________  KC_GRV,  KC_SCLN, KC_COLN, KC_PLUS, KC_EQL

#   define _________________RAISE_R1__________________  KC_EXLM, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC
#   define _________________RAISE_R2__________________  KC_AT,   KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK
#   define _________________RAISE_R3__________________  KC_TILD, KC_DQUO, KC_QUOT, KC_UNDS, KC_QUES
#endif // ENABLE_RAISE_MIGRATION

// Adjust
#define _________________ADJUST_L1_________________  QK_MAKE, DB_TOGG, QK_BOOT, KC_QWERTY, KC_WRKMAN
#define _________________ADJUST_L2_________________  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,   KC_MNXT
#define _________________ADJUST_L3_________________  KC_VRSN, AU_ON,   AU_OFF,  CG_SWAP,   CG_NORM

#define _________________ADJUST_R1_________________  MU_NEXT, MU_ON,   MU_OFF,  MI_ON,     MI_OFF
#define _________________ADJUST_R2_________________  AU_NEXT, RGB_HUI, RGB_HUD, RGB_SAI,   RGB_SAD
#define _________________ADJUST_R3_________________  AU_PREV, RGB_TOG, RGB_MOD, RGB_VAI,   RGB_VAD
// clang-format on
