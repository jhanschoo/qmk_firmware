#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED

#    ifndef DISABLE_RGB_MATRIX_JHANSCHOO
RGB_MATRIX_EFFECT(JHANSCHOO)
#    endif

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// static HSV JHANSCHOO_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
//     uint16_t effect = tick + dist;
//     dx              = dx < 0 ? dx * -1 : dx;
//     dy              = dy < 0 ? dy * -1 : dy;
//     dx              = dx * 16 > 255 ? 255 : dx * 16;
//     dy              = dy * 16 > 255 ? 255 : dy * 16;
//     effect += dx > dy ? dy : dx;
//     if (effect > 255) effect = 255;
//     hsv.v = qadd8(hsv.v, 255 - effect);
//     return hsv;
// }

#        ifndef DISABLE_RGB_MATRIX_JHANSCHOO

#include "ledmap.inc"

bool JHANSCHOO(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint8_t layer = biton32(layer_state);
        HSV layer_hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        RGB layer_rgb = hsv_to_rgb(layer_hsv);
        rgb_matrix_set_color(i, layer_rgb.r, layer_rgb.g, layer_rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#        endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // RGB_MATRIX_KEYREACTIVE_ENABLED
