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

// #define ________________HOME_L_XTRA________________    QK_LEAD, _______,  _______, RGB_TOG, TOG_LWR
// #define ________________HOME_R_XTRA________________    TOG_RSE, KC_RGBT, _______, _______, KC_SEC1

#define ____THUMBS_L____                               GUI_SPC, LWR_BSP
#define ____THUMBS_R____                               RSE_TAB, SFT_ENT

// Pre-defines
#define ________________NUMBER_LEFT________________    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________    KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define ___________________BLANK___________________    _______, _______, _______, _______, _______

#define _______________UNICODE_MOJIS_______________  UC_FLIP, UC_TABL, UC_SHRG, UC_DISA, UC_IRNY

// #define ___________UC_MOJIS_MINI__________           UC_FLIP, UC_TABL, UC_SHRG, UC_DISA

// KC_NORM, KC_SUPR, KC_SCPT, KC_AUSS, KC_WIDE, KC_BLCK

// #define _______________UNICODE_TYPE1_______________  KC_NORM, KC_WIDE, KC_SCPT, KC_BLCK, KC_REG
// #define _______________UNICODE_TYPE2_______________  KC_AUSS, KC_ZALG, KC_SUPR, KC_FRAK, KC_DBSK

// #define ___________UC_TYPE_MINI___________           KC_NORM, KC_SUPR, KC_SCPT, KC_AUSS

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
#define _________________RAISE_L1__________________  KC_BSLS, KC_SLSH, KC_PIPE, KC_AMPR, KC_MINS
#define _________________RAISE_L2__________________  KC_LABK, KC_LBRC, KC_LPRN, KC_LCBR, KC_ARRW
#define _________________RAISE_L3__________________  KC_GRV,  KC_SCLN, KC_COLN, KC_PLUS, KC_EQL

#define _________________RAISE_R1__________________  KC_EXLM, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC
#define _________________RAISE_R2__________________  KC_AT,   KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK
#define _________________RAISE_R3__________________  KC_TILD, KC_DQUO, KC_QUOT, KC_UNDS, KC_QUES

// #define _______________RAISE_L_EXTRA_______________    _________________FUNC_LEFT_________________
// #define _______________RAISE_R_EXTRA_______________    _________________FUNC_RIGHT________________

// Adjust
#define _________________ADJUST_L1_________________  KC_MAKE, DB_TOGG, QK_BOOT, KC_QWERTY, KC_WRKMAN
#define _________________ADJUST_L2_________________  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,   KC_MNXT
#define _________________ADJUST_L3_________________  KC_VRSN, AU_ON,   AU_OFF,  CG_SWAP,   CG_NORM

#define _________________ADJUST_R1_________________  MU_NEXT, MU_ON,   MU_OFF,  MI_ON,     MI_OFF
#define _________________ADJUST_R2_________________  AU_NEXT, RGB_HUI, RGB_HUD, RGB_SAI,   RGB_SAD
#define _________________ADJUST_R3_________________  AU_PREV, RGB_TOG, RGB_MOD, RGB_VAI,   RGB_VAD

// #define __________ADJUST_L_MINI___________             ___________UC_MOJIS_MINI__________
// #define __________ADJUST_R_MINI___________             ___________UC_TYPE_MINI___________

// #define ______________ADJUST_L_EXTRA_______________    _______________UNICODE_MOJIS_______________
// #define ______________ADJUST_R_EXTRA_______________    _______________UNICODE_TYPE1_______________
// clang-format on
