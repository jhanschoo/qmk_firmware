#include QMK_KEYBOARD_H
#include "sofle_v2.h"
#include "keymap.h"

#define LED_FLAG_HOME_ROW 0x10
#define LED_FLAG_MOVEMENT 0x20

// c.f. .build/obj_splitkb_aurora_sofle_v2_rev1_jhanschoo/src/default_keyboard.c
#define LED_INDEX_LOWER 32  // [4, 3]
#define LED_INDEX_RAISE 67  // [9, 3]

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t l = get_highest_layer(layer_state | default_layer_state);
    switch (l) {
        case _DEFAULT:
            // fallthrough
        case _COLEMAKDH: {
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i == LED_INDEX_LOWER) {
                    rgb_matrix_set_color(i, RGB_BLUE_USER);
                    continue;
                }
                if (i == LED_INDEX_RAISE) {
                    rgb_matrix_set_color(i, RGB_AMBER_USER);
                    continue;
                }

                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    rgb_matrix_set_color(i, RGB_WHITE_USER);
                } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_HOME_ROW)) {
                    continue;
                } else {
                    rgb_matrix_set_color(i, RGB_WHITE_DIM_USER);
                }
            }
            break;
        }
        case _GAME: {
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i == LED_INDEX_LOWER) {
                    rgb_matrix_set_color(i, RGB_BLUE_USER);
                    continue;
                }
                if (i == LED_INDEX_RAISE) {
                    rgb_matrix_set_color(i, RGB_AMBER_USER);
                    continue;
                }

                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    continue;
                } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
                    rgb_matrix_set_color(i, RGB_RED_USER);
                    continue;
                } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MOVEMENT)) {
                    rgb_matrix_set_color(i, RGB_WHITE_USER);
                    continue;
                } else {
                    continue;
                }
            }
            break;
        }
        case _LOWER: {
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i == LED_INDEX_RAISE) {
                    rgb_matrix_set_color(i, RGB_GREEN_USER);
                    continue;
                }

                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    rgb_matrix_set_color(i, RGB_BLUE_USER);
                } else {
                    rgb_matrix_set_color(i, RGB_LIGHT_BLUE_USER);
                }
            }
            break;
        }
        case _RAISE: {
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i == LED_INDEX_LOWER) {
                    rgb_matrix_set_color(i, RGB_GREEN_USER);
                    continue;
                }

                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    rgb_matrix_set_color(i, RGB_AMBER_USER);
                } else {
                    rgb_matrix_set_color(i, RGB_LIGHT_AMBER_USER);
                }
            }
            break;
        }
        case _ADJUST: {
            for (uint8_t i = led_min; i < led_max; i++) {
                if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                    rgb_matrix_set_color(i, RGB_GREEN_USER);
                } else {
                    rgb_matrix_set_color(i, RGB_LIGHT_GREEN_USER);
                }
            }
            break;
        }
        default:
            break;
    }
    return false;
}
