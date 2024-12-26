// Copyright (C) 2023 Jerrell, Jacob <@jjerrell>
//
// This file is part of qmk_firmware.
//
// qmk_firmware is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// qmk_firmware is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.

#include "led_custom.h"

void moonlander_led_all(bool status) {
    ML_LED_L1(status);
    ML_LED_L2(status);
    ML_LED_L3(status);
    ML_LED_R1(status);
    ML_LED_R2(status);
    ML_LED_R3(status);
}

void game_mode_led_indication(void) {
    uint8_t indication_loop = 0;

    while (game_mode_notify(indication_loop)) {
        indication_loop++;
    }

    indication_loop = 0;
}

bool game_mode_notify(uint8_t indicator_loop) {
    switch (indicator_loop) {
        case 0:
            ML_LED_L1(true);
            ML_LED_L2(false);
            ML_LED_L3(false);
            ML_LED_R1(false);
            ML_LED_R2(false);
            ML_LED_R3(true);
            return true;
            break;
        case 1:
            ML_LED_L1(false);
            ML_LED_R3(false);
            ML_LED_L2(true);
            ML_LED_R2(true);
            return true;
            break;
        case 2:
            ML_LED_L2(false);
            ML_LED_R2(false);
            ML_LED_L3(true);
            ML_LED_R1(true);
            return true;
            break;
        case 3:
            ML_LED_L3(false);
            ML_LED_R1(false);
            return true;
            break;
        default:
            return false;
            break;
    }
}
