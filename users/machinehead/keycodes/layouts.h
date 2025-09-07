// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright 2025 Jacob Jerrell (@jjerrell)

// clang-format off

/*
 * Used for layouts with a lower macro-row and no num-row.
 * 
 * In current practice, this is intended for the Voyager which feels more comfortable
 * to me if my home-row is higher on the board.
 */
#define WRAP_MODIFIERS_4x12(                                           \
    K00, K01, K02, K03, K04, K05,        K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,        K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,        K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33, K34, K35,        K36, K37, K38, K39, K3A, K3B  \
) \
     K00,       K01,        K02,        K03,        K04,  K05,         K06,       K07,        K08,        K09,        K0A,  K0B, \
     K10,       K11,  SFT_T(K12), GUI_T(K13), ALT_T(K14), K15,         K16, ALT_T(K17), GUI_T(K18), SFT_T(K19),       K1A,  K1B, \
     K20, CTL_T(K21),       K22,        K23,        K24,  K25,         K26,       K27,        K28,        K29,  CTL_T(K2A), K2B, \
     K30,       K31,        K32,        K33,        K34,  K35,         K36,       K37,        K38,        K39,        K3A,  K3B

/*
 * Used for layouts with an upper num-/macro-row.
 *
 * In current practice, this is for the Moonlander which is a pretty comfortable fit
 * with an upper non-alpha row. The lower macro-row is abstracted away at the keymap
 * level.
 */
#define WRAP_MODIFIERS_4x12_tall(                                      \
    K00, K01, K02, K03, K04, K05,        K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,        K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,        K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33, K34, K35,        K36, K37, K38, K39, K3A, K3B  \
) \
    K00,        K01,        K02,        K03,         K04,   K05,         K06,       K07,        K08,        K09,        K0A,  K0B, \
     K10,       K11,        K12,        K13,         K14,   K15,         K16,       K17,        K18,        K19,        K1A,  K1B, \
     K20,       K21,  SFT_T(K22), GUI_T(K23),  ALT_T(K24),  K25,         K26, ALT_T(K27), GUI_T(K28), SFT_T(K29),       K2A,  K2B, \
     K30, CTL_T(K31),       K32,        K33,         K34,   K35,         K36,       K37,        K38,        K39,  CTL_T(K3A), K3B

/*
 * Generally used to make the Planck feel just a little bit wider.
 */
#define WRAP_MODIFIERS_4x12_wide(                                      \
    K00, K01, K02, K03, K04, K05,        K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,        K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,        K26, K27, K28, K29, K2A, K2B, \
    K30, K31, K32, K33, K34, K35,        K36, K37, K38, K39, K3A, K3B  \
) \
           K00,        K01,        K02,        K03,  K04, K05,         K06, K07,       K08,        K09,        K0A,        K0B,  \
           K10,  SFT_T(K11), GUI_T(K12), ALT_T(K13), K14, K15,         K16, K17, ALT_T(K18), GUI_T(K19), SFT_T(K1A),       K1B,  \
     CTL_T(K20),       K21,        K22,        K23,  K24, K25,         K26, K27,       K28,        K29,        K2A,  CTL_T(K2B), \
           K30,        K31,        K32,        K33,  K34, K35,         K36, K37,       K38,        K39,        K3A,        K3B
    
// cland-format on