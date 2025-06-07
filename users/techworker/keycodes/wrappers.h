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

#define ___________HOME_L_MINI____________             QK_LEAD, RGB_TOG, _______, _______
#define ___________HOME_R_MINI____________             _______, _______, KC_RGB_T, KC_SEC1

#define _______________HOME_L_EXTRA________________    RGB_TOG, _______, _______, _______, QK_LEAD
#define _______________HOME_R_EXTRA________________    KC_SEC1, _______, _______, _______, KC_RGB_T

#define ____THUMBS_L____                               CTL_SPC, LWR_BSP
#define ____THUMBS_R____                               RSE_TAB, SFT_ENT

// Pre-defines
#define ________________NUMBER_LEFT________________    KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________    KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________NAV_PAD_1_________________    KC_PGUP, KC_TAB,  KC_UP,   KC_ENT,  KC_PGDN
#define _________________NAV_PAD_2_________________    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _________________NAV_PAD_3_________________    KC_ESC,  KC_BSPC, KC_CUT,  KC_DEL,  KC_CCCV

#define ________NUM_PAD_1________                      KC_7,    KC_8,    KC_9
#define ________NUM_PAD_2________                      KC_4,    KC_5,    KC_6
#define ________NUM_PAD_3________                      KC_1,    KC_2,    KC_3
#define ________NUM_PAD_4________                      KC_0,    KC_DOT,  KC_COMM

#define ___________________BLANK___________________    _______, _______, _______, _______, _______

#define _______________UNICODE_MOJIS_______________  UC_FLIP, UC_TABL, UC_SHRG, UC_DISA, UC_IRNY
#define _______________UNICODE_TYPE1_______________  KC_NORM, KC_WIDE, KC_SCPT, KC_BLCK, KC_REG
#define _______________UNICODE_TYPE2_______________  KC_AUSS, KC_ZALG, KC_SUPR, KC_FRAK, KC_DBSK

// Lower
#define _________________LOWER_L1__________________    _________________NAV_PAD_1_________________
#define _________________LOWER_L2__________________    _________________NAV_PAD_2_________________
#define _________________LOWER_L3__________________    _________________NAV_PAD_3_________________


#define _________________LOWER_R1__________________    KC_ARRW, ________NUM_PAD_1________, _______
#define _________________LOWER_R2__________________    _______, ________NUM_PAD_2________, _______   
#define _________________LOWER_R3__________________    _______, ________NUM_PAD_3________, _______

#define ___________LOWER_L_MINI___________             MACRO_1, _______, _______, _______
#define ___________LOWER_R_MINI___________             ________NUM_PAD_4________, _______

#define _______________LOWER_L_EXTRA_______________    MACRO_1, _______, _______, _______, _______
#define _______________LOWER_R_EXTRA_______________    _______, ________NUM_PAD_4________, _______

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

#define ___________RAISE_L_MINI___________           UC_FLIP, UC_TABL, UC_SHRG, UC_DISA
#define ___________RAISE_R_MINI___________           KC_NORM, KC_WIDE, KC_SCPT, KC_BLCK

#define _______________RAISE_L_EXTRA_______________    _________________FUNC_LEFT_________________
#define _______________RAISE_R_EXTRA_______________    _________________FUNC_RIGHT________________

// Adjust
#define _________________ADJUST_L1_________________  KC_MAKE, DB_TOGG, QK_BOOT, KC_QWERTY, KC_WRKMAN
#define _________________ADJUST_L2_________________  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,   KC_MNXT
#define _________________ADJUST_L3_________________  KC_VRSN, AU_ON,   AU_OFF,  CG_SWAP,   CG_NORM

#define _________________ADJUST_R1_________________  MU_NEXT, MU_ON,   MU_OFF,  MI_ON,     MI_OFF
#define _________________ADJUST_R2_________________  AU_NEXT, RGB_HUI, RGB_HUD, RGB_SAI,   RGB_SAD
#define _________________ADJUST_R3_________________  AU_PREV, RGB_TOG, RGB_MOD, RGB_VAI,   RGB_VAD

#define ______________ADJUST_L_EXTRA_______________    _______________UNICODE_MOJIS_______________
#define ______________ADJUST_R_EXTRA_______________    _______________UNICODE_TYPE1_______________
// clang-format on
