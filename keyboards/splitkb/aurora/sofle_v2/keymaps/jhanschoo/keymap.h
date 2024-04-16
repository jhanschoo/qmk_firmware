#pragma once
#include QMK_KEYBOARD_H
#include "sofle_v2.h"

enum tap_dance_action_keys {
    TD_L_ACTION,
    TD_R_ACTION,
    TD_FN_ACTION
};

// colors (all normalized to 0x00-0x80)
#define RGB_WHITE_USER 0x80, 0x80, 0x80
#define RGB_WHITE_DIM_USER 0x40, 0x40, 0x40

#define RGB_AMBER_USER 0x80, 0x60, 0x00
#define RGB_LIGHT_AMBER_USER 0x80, 0x70, 0x40

#define RGB_RED_USER 0x80, 0x00, 0x00
#define RGB_PINK_USER 0x80, 0x40, 0x40

#define RGB_GREEN_USER 0x00, 0x80, 0x00
#define RGB_LIGHT_GREEN_USER 0x40, 0x80, 0x40

#define RGB_BLUE_USER 0x00, 0x00, 0x80
#define RGB_LIGHT_BLUE_USER 0x40, 0x40, 0x80

#define HSV_RED_USER 0x00, 0xFF, 0x80

#if defined(OLED_ENABLE)
void render_blank_line_user(void);
void render_layer_state_user(void);
void render_mod_status_user(uint8_t modifiers);
void render_led_state_user(void);
void render_locale_state_user(void);
#endif