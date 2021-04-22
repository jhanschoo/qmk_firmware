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

// following are not necessary but provided for intellisense
#include "rgb_matrix_types.h"
#include "moonlander.h"
#include "../../config.h"
#include "config.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
  DUMMY = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_EQL,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,
            KC_RGHT,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,       
    KC_TAB,         LGUI_T(KC_Q),   LALT_T(KC_W),   LSFT_T(KC_E),   LCTL_T(KC_R),   KC_T,           TG(1),
            TG(1),          KC_Y,           RCTL_T(KC_U),   RSFT_T(KC_I),   RALT_T(KC_O),   RGUI_T(KC_P),   LT(2,KC_BSLS),
    KC_BSPC,        LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   KC_G,           KC_HYPR, 
            KC_MEH,         KC_H,           RCTL_T(KC_J),   RSFT_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),KC_QUOT,
    KC_DEL,         LGUI_T(KC_Z),   LALT_T(KC_X),   LSFT_T(KC_C),   LCTL_T(KC_V),   KC_B,
                            KC_N,           RCTL_T(KC_M),   RSFT_T(KC_COMM),RALT_T(KC_DOT), RGUI_T(KC_SLSH),KC_RSFT,      
    LT(1,KC_GRV),   WEBUSB_PAIR,    LALT(KC_LSFT),  KC_LEFT,        KC_RGHT,        LALT_T(KC_APP),
                            LCTL_T(KC_ESC), KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        MO(1),          
    KC_SPC,         KC_BSPC,        KC_LGUI,                                KC_LALT,        KC_TAB,         KC_ENT
  ),
  [SYMB] = LAYOUT_moonlander(
    KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,
            _______,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    _______,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        _______,
            _______,        KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    _______,        KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRV,         _______,
            _______,        KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PPLS,        _______, 
    _______,        KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,
                            _______,        KC_1,           KC_2,           KC_3,           KC_BSLS,        _______, 
    _______,        KC_COMM,        _______,        _______,        _______,        _______,
                            _______,        _______,        KC_DOT,         KC_0,           KC_EQL,         _______, 
    _______,        _______,        _______,                _______,        _______,        _______
  ),
  [MDIA] = LAYOUT_moonlander(
    AU_TOG,         _______,        _______,        _______,        _______,        _______,        _______,
            _______,        _______,        _______,        _______,        _______,        _______,        RESET,          
    MU_TOG,         _______,        _______,        KC_MS_U,        _______,        _______,        _______,
            _______,        _______,        _______,        _______,        _______,        _______,        _______, 
    MU_MOD,         _______,        KC_MS_L,        KC_MS_D,        KC_MS_R,        _______,        _______,
            _______,        _______,        _______,        _______,        _______,        _______,        KC_MPLY,
    _______,        _______,        _______,        _______,        _______,        _______,
                            _______,        _______,        KC_MPRV,        KC_MNXT,        _______,        _______, 
    _______,        _______,        _______,        KC_BTN1,        KC_BTN2,        _______,
                            _______,       KC_VOLU,         KC_VOLD,        KC_MUTE,        _______,        _______, 
    _______,        _______,        _______,                _______,        _______,        KC_WBAK
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = {
      {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127},
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case BASE:
      set_layer_color(BASE);
      break;
   default:
     if (rgb_matrix_get_flags() == LED_FLAG_NONE)
       rgb_matrix_set_color_all(0, 0, 0);
     break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // printf("%d %d %d %d %d %d %d\n", rgb_matrix_is_enabled(), rgb_matrix_get_mode(), rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val(), rgb_matrix_get_speed(), rgb_matrix_get_suspend_state());
  // switch (keycode) {
  //   case RGB_SLD:
  //     if (record->event.pressed) {
  //       rgblight_mode(1);
  //     }
  //     return false;
  //   case HSV_0_255_255:
  //     if (record->event.pressed) {
  //       rgblight_mode(1);
  //       rgblight_sethsv(0,255,255);
  //     }
  //     return false;
  //   case HSV_86_255_128:
  //     if (record->event.pressed) {
  //       rgblight_mode(1);
  //       rgblight_sethsv(86,255,128);
  //     }
  //     return false;
  //   case HSV_172_255_255:
  //     if (record->event.pressed) {
  //       rgblight_mode(1);
  //       rgblight_sethsv(172,255,255);
  //     }
  //     return false;
  // }
  return true;
}
