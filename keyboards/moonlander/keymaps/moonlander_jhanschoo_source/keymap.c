#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

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

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_APPLICATION,                                 KC_INSERT,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_GRAVE,       RGUI_T(KC_Q),   RALT_T(KC_W),   RSFT_T(KC_E),   RCTL_T(KC_R),   KC_T,           KC_ESCAPE,                                      KC_DELETE,      KC_Y,           LCTL_T(KC_U),   LSFT_T(KC_I),   LALT_T(KC_O),   LGUI_T(KC_P),   KC_BSLASH,      
    KC_BSPACE,      LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   KC_G,           KC_ENTER,                                                                       KC_SPACE,       KC_H,           RCTL_T(KC_J),   RSFT_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCOLON),KC_QUOTE,       
    KC_TAB,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_LBRACKET,    
    KC_CAPSLOCK,    KC_HYPR,        KC_LEFT,        KC_RIGHT,       KC_SPACE,       TT(4),                                                                                                          TO(1),          KC_ENTER,       KC_DOWN,        KC_UP,          KC_MEH,         KC_RBRACKET,    
    TT(3),          KC_LCTRL,       KC_LALT,                        KC_LGUI,        KC_LSHIFT,      TO(1)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_LSHIFT,      KC_A,           KC_S,           KC_D,           KC_F,           KC_TRANSPARENT, MO(3),                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_LCTRL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LGUI,        KC_LALT,        KC_TAB,         KC_BSPACE,      KC_TRANSPARENT, KC_UP,                                                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_END,         KC_HOME,        KC_PSCREEN,     KC_TRANSPARENT, 
    KC_LEFT,        KC_DOWN,        KC_RIGHT,                       KC_PGDOWN,      KC_PGUP,        TO(2)
  ),
  [2] = LAYOUT_moonlander(
    KC_EQUAL,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_GRAVE,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_B,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT, 
    KC_LSHIFT,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_5,                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT, 
    KC_LCTRL,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_4,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LGUI,        KC_LALT,        KC_1,           KC_2,           KC_3,           KC_BSPACE,                                                                                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_PSCREEN,                                     KC_LSHIFT,      KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_HOME,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_SCROLLLOCK,                                  KC_LCTRL,       KC_NUMLOCK,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_SLASH,    KC_F12,         
    KC_PGUP,        KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_LGUI,        KC_LALT,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_ASTERISK, KC_TRANSPARENT, 
    KC_PGDOWN,      KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_END,         KC_AMPR,        KC_ASTR,        KC_LABK,        KC_RABK,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    KC_KP_PLUS,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,                                    DYN_MACRO_PLAY1,DYN_REC_STOP,   DYN_REC_START1, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 DYN_MACRO_PLAY2,DYN_REC_STOP,   DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_MOD,         KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,63}, {0,0,0}, {0,0,0}, {0,0,63} },

    [1] = { {86,255,63}, {86,255,63}, {172,255,255}, {172,255,255}, {172,255,255}, {86,255,63}, {86,255,63}, {0,0,255}, {86,255,63}, {172,255,255}, {86,255,63}, {0,0,255}, {0,0,255}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {0,0,255}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {0,255,255}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63} },

    [2] = { {86,255,63}, {86,255,63}, {172,255,255}, {172,255,255}, {172,255,255}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {172,255,255}, {86,255,63}, {86,255,63}, {0,0,255}, {86,255,63}, {14,255,255}, {86,255,63}, {0,0,255}, {0,0,255}, {86,255,63}, {14,255,255}, {86,255,63}, {86,255,63}, {0,0,255}, {86,255,63}, {14,255,255}, {86,255,63}, {86,255,63}, {86,255,63}, {14,255,255}, {86,255,63}, {86,255,63}, {14,255,255}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63}, {86,255,63} },

    [3] = { {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {86,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {86,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {86,255,255}, {215,255,255}, {43,255,255}, {129,255,255}, {21,255,255}, {86,255,255}, {215,255,255}, {43,255,255}, {129,255,255}, {21,255,255}, {86,255,255}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {86,255,255}, {86,255,255}, {172,255,63}, {172,255,63}, {172,255,63}, {86,255,255}, {0,0,127}, {0,0,127}, {0,0,127}, {0,0,127}, {86,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {86,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {86,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {86,255,255}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63}, {172,255,63} },

    [4] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,0,255}, {0,255,63}, {0,255,63}, {0,255,63}, {0,0,255}, {0,0,255}, {0,255,63}, {0,0,255}, {0,255,63}, {0,255,63}, {0,0,255}, {0,255,63}, {0,0,255}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {21,255,255}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,255}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,255,255}, {0,0,127}, {0,0,127}, {0,0,127}, {43,255,255}, {43,255,255}, {43,255,255}, {0,255,255}, {86,255,255}, {86,255,255}, {86,255,255}, {0,255,63}, {0,255,63}, {0,255,63}, {0,255,63} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
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
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

