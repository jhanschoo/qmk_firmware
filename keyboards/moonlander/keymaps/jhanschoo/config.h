/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
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

#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"Nyz9B/agJmb"
#define RGB_MATRIX_STARTUP_SPD 60
#define IGNORE_MOD_TAP_INTERRUPT
#define FASTLED_BLEND_FIXED 1

// clang-format off
#define LAYOUT_moonlander_split( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,      k53, \
                        k50, k51, k52, \
\
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
         k91, k92, k93, k94, k95, k96, \
    kb3,      ka2, ka3, ka4, ka5, ka6, \
    kb4, kb5, kb6                      \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06 }, \
    { k10, k11, k12, k13, k14, k15, k16 }, \
    { k20, k21, k22, k23, k24, k25, k26 }, \
    { k30, k31, k32, k33, k34, k35, KC_NO }, \
    { k40, k41, k42, k43, k44, KC_NO, KC_NO }, \
    { k50, k51, k52, k53, KC_NO, KC_NO, KC_NO }, \
\
    { k60, k61, k62, k63, k64, k65, k66 }, \
    { k70, k71, k72, k73, k74, k75, k76 }, \
    { k80, k81, k82, k83, k84, k85, k86 }, \
    { KC_NO,k91, k92, k93, k94, k95, k96 }, \
    { KC_NO, KC_NO, ka2, ka3, ka4, ka5, ka6 }, \
    { KC_NO, KC_NO, KC_NO, kb3, kb4, kb5, kb6  } \
}
// clang-format on

// c.f. the definition of `led_config_t g_led_config` in moonlander.c

// clang-format off
#define LEDMAP_moonlander_split( \
    k00, k01, k02, k03, k04, k05, k06, \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35,      \
    k40, k41, k42, k43, k44,      k53, \
                        k50, k51, k52, \
\
    k60, k61, k62, k63, k64, k65, k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
         k91, k92, k93, k94, k95, k96, \
    kb3,      ka2, ka3, ka4, ka5, ka6, \
    kb4, kb5, kb6                      \
) \
{ \
    k00, k10, k20, k30, k40, \
    k01, k11, k21, k31, k41, \
    k02, k12, k22, k32, k42, \
    k03, k13, k23, k34, k43, \
    k04, k14, k24, k34, k44, \
    k05, k15, k25, k35, \
    k06, k16, k26, \
    k50, k51, k52, k53, \
\
    k66, k76, k86, k96, ka6, \
    k65, k75, k85, k95, ka5, \
    k64, k74, k84, k94, ka4, \
    k63, k73, k83, k93, ka3, \
    k62, k72, k82, k92, ka2, \
    k61, k71, k81, k91, \
    k60, k70, k80, \
    kb6, kb5, kb4, kb3 \
}
// clang-format on

// default LED flags set by moonlander
// 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 0x01, 0x04, 0x04, 0x04, 0x04, 0x04,
// 0x01, 0x01, 0x01, 0x01, 0x01,       0x01,
//                         0x01, 0x01, 0x01,

// 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01,
// 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01,
// 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01,
//       0x04, 0x04, 0x04, 0x04, 0x04, 0x01,
// 0x01,       0x01, 0x01, 0x01, 0x01, 0x01,
// 0x01, 0x01, 0x01