/* Copyright 2023 splitkb.com <support@splitkb.com>
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

// #define QUICK_TAP_TERM 0
// #define PERMISSIVE_HOLD

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 128
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#if defined(OLED_ENABLE)
    #undef OLED_FONT_H
    #define OLED_FONT_H "keyboards/splitkb/aurora/sofle_v2/keymaps/jhanschoo/glcdfont.c"
    #define OLED_FONT_WIDTH 8
    #define OLED_FONT_END 127

    // mitigate OLED burn-in
    #define OLED_SCROLL_TIMEOUT 2000
    #define OLED_SCROLL_TIMEOUT_RIGHT
#endif

