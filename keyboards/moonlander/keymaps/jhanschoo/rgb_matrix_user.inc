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

    RGB effect_rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint8_t layer = biton32(layer_state);
        HSV layer_hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        RGB rgb = rgb_matrix_hsv_to_rgb(layer_hsv);

        uint8_t sum_opacity = 0;
        for (uint8_t j = 0; j < g_last_hit_tracker.count; ++j) {
            int16_t dx = (g_led_config.point[i].x - g_last_hit_tracker.x[j]);
            int16_t dy = (g_led_config.point[i].y - g_last_hit_tracker.y[j]);
            uint16_t adx = dx < 0 ? -dx : dx;
            uint16_t ady = dy < 0 ? -dy : dy;
            int16_t dist = sqrt16(adx * adx + ady * ady);

            // at the fastest speed, maximum tick is close to 65536 before raw tick is forgotten
            // at the speed=1, maximum tick is close to 256 before raw tick is forgotten
            // hence we choose to saturate at UINT8_MAX; all animations related to the current
            // keypress should be completed by then
            // of course, at speed=0, maximum tick is 0 before raw tick is forgotten.
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], rgb_matrix_config.speed);
            if (tick > UINT8_MAX) {
                tick = UINT8_MAX;
            }

            // wavefront design: regardless of wave shape, last key
            // distance 256 away must start animation before, close to 
            // time 128 and
            // ground-zero-key must have ended animation

            // current wavefront choice:
            // transparency = min(255, 4 * |2 * t - d|)

            uint16_t transparency = 2 * tick; // [0, 512)
            if (dist > transparency) {
                transparency = dist - transparency;
            } else {
                transparency -= dist;
            }
            transparency *= 4; // [0, 2048)
            uint8_t opacity = transparency > UINT8_MAX ? 0 : (UINT8_MAX - transparency);

            // radial surface wave amplitude is proportional to 1/sqrt(radius)
            // we scale by 1/sqrt(radius / 32 + 1), and at distance 128 we have a bit less than roughly 1/3
            // equivalent to scaling by 256 * 4 / sqrt(radius/2 + 16) / 256
            // we maintain same amplitude in the cross pattern
            if (adx != 0 && ady != 0) {
                opacity = scale8(opacity, (uint8_t) scale16by8(1023, sqrt16(dist / 2 + 16)));
            }
            sum_opacity = qadd8(sum_opacity, opacity);
        }
        rgb.r = blend8(rgb.r, effect_rgb.r, sum_opacity);
        rgb.g = blend8(rgb.g, effect_rgb.g, sum_opacity);
        rgb.b = blend8(rgb.b, effect_rgb.b, sum_opacity);

        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#        endif

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // RGB_MATRIX_KEYREACTIVE_ENABLED
