/* Copyright 2024 Jacob Jerrell <@jjerrell>
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

#include "jjerrell.h"

#define ML_LED_L1(status) ML_LED_1((bool)status)
#define ML_LED_L2(status) ML_LED_2((bool)status)
#define ML_LED_L3(status) ML_LED_3((bool)status)

#define ML_LED_R1(status) ML_LED_4((bool)status)
#define ML_LED_R2(status) ML_LED_5((bool)status)
#define ML_LED_R3(status) ML_LED_6((bool)status)

void moonlander_led_all(bool status);