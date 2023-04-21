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


#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"
#include "keymap_us_international.h"

// begin intellisense block
// #include "moonlander.h"
// #include "../../config.h"
// #include "rgb_matrix_types.h"
// end intellisense block

#define MOON_LED_LEVEL LED_LEVEL

#include "layers_enum.h"

enum custom_keycodes {
  DUMMY = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander_split(
    KC_EQL,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_APP,
    KC_GRV,         RGUI_T(KC_Q),   RALT_T(KC_W),   RSFT_T(KC_E),   RCTL_T(KC_R),   KC_T,           KC_ESC,
    KC_BSPC,        LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   KC_G,           KC_ENT,
    KC_TAB,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,
    KC_CAPS,        KC_HYPR,        KC_LEFT,        KC_RGHT,        KC_SPC,                         TT(MDIA),
                                                                    TT(SYMB),       KC_LCTL,        KC_LALT,

    KC_INS,         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
    KC_DEL,         KC_Y,           LCTL_T(KC_U),   LSFT_T(KC_I),   LALT_T(KC_O),   LGUI_T(KC_P),   KC_BSLS,
    KC_SPC,         KC_H,           RCTL_T(KC_J),   RSFT_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),KC_QUOT,
                    KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_LBRC,
    TO(BASE),                       KC_ENT,         KC_DOWN,        KC_UP,          KC_MEH,         KC_RBRC,
    KC_LGUI,        KC_LSFT,        TT(NORM)
  ),
  [NORM] = LAYOUT_moonlander_split(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        KC_Q,           KC_W,           KC_E,           KC_R,           _______,        _______,
    KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           _______,        MO(SYMB),
    KC_LCTL,        _______,        _______,        _______,        _______,        _______,
    KC_LALT,        KC_TAB,         KC_LGUI,        KC_BSPC,        _______,                        KC_UP,
                                                                    KC_LEFT,        KC_DOWN,        KC_RGHT,

    _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        KC_U,           KC_I,           KC_O,           KC_P,           _______,
    KC_CAPS,        _______,        KC_J,           KC_K,           KC_L,           KC_SCLN,        _______,
                    _______,        _______,        _______,        _______,        _______,        _______,
    _______,                        _______,        KC_END,         KC_HOME,        KC_PSCR,        _______,
    KC_PGDN,        KC_PGUP,        _______
  ),
  [SYMB] = LAYOUT_moonlander_split(
    KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_PSCR,
    KC_HOME,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        _______,        KC_SCRL,
    KC_PGUP,        KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        _______,        KC_PAUS,
    KC_PGDN,        KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        _______,
    KC_END,         KC_AMPR,        KC_ASTR,        KC_LABK,        KC_RABK,                        _______,
                                                                    _______,        _______,        _______,

    KC_LSFT,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_LCTL,        KC_NUM,         KC_P7,          KC_P8,          KC_P9,          KC_PSLS,        KC_F12,
    KC_LGUI,        KC_LALT,        KC_P4,          KC_P5,          KC_P6,          KC_PAST,        _______,
                    _______,        KC_P1,          KC_P2,          KC_P3,          KC_PMNS,        _______,
    _______,                        KC_P0,          KC_PDOT,        KC_PENT,        KC_PPLS,        _______,
    _______,        _______,        _______
  ),
  [MDIA] = LAYOUT_moonlander_split(
    AU_TOGG,        _______,        _______,        _______,        _______,        _______,        _______,
    MU_TOGG,        _______,        _______,        KC_MS_U,        _______,        _______,        _______,
    MU_NEXT,        _______,        KC_MS_L,        KC_MS_D,        KC_MS_R,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        KC_BTN1,        KC_BTN2,                        _______,
                                                                    _______,        _______,        _______,

    DM_PLY1,        DM_RSTP,        DM_REC1,        _______,        _______,        _______,        QK_BOOT,
    DM_PLY2,        DM_RSTP,        DM_REC2,        _______,        _______,        _______,        _______,
    KC_MPLY,        KC_MSTP,        KC_MPRV,        KC_MNXT,        _______,        _______,        _______,
                    KC_MUTE,        KC_VOLD,        KC_VOLU,        _______,        _______,        _______,
    _______,                        KC_BRID,        KC_BRIU,        _______,        _______,        _______,
    _______,        _______,        _______
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_JHANSCHOO);
  rgb_matrix_set_speed_noeeprom(120);
  rgb_matrix_sethsv_noeeprom(0, 0, 255);
}

// void set_layer_color(int layer) {
//   for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//     HSV hsv = {
//       .h = pgm_read_byte(&ledmap[layer][i][0]),
//       .s = pgm_read_byte(&ledmap[layer][i][1]),
//       .v = pgm_read_byte(&ledmap[layer][i][2]),
//     };
//     if (!hsv.h && !hsv.s && !hsv.v) {
//         rgb_matrix_set_color( i, 0, 0, 0 );
//     } else {
//         RGB rgb = hsv_to_rgb( hsv );
//         float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//         rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
//     }
//   }
// }

// void rgb_matrix_indicators_user(void) {
//   return;
//   // if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
// }
