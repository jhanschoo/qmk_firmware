#ifdef RGB_MATRIX_KEYREACTIVE_FRAMEBUFFER_ENABLED

#    ifndef DISABLE_RGB_MATRIX_JHANSCHOO
RGB_MATRIX_EFFECT(JHANSCHOO)
#    endif

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

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
        for (uint8_t j = 0; j < led_max; ++j) {
            int16_t dx = (g_led_config.point[i].x - g_led_config.point[j].x);
            int16_t dy = (g_led_config.point[i].y - g_led_config.point[j].y);
            uint16_t adx = dx < 0 ? -dx : dx;
            uint16_t ady = dy < 0 ? -dy : dy;
            int16_t dist = sqrt16(adx * adx + ady * ady);

            // at the fastest speed (speed=255), maximum tick is close to 65536 before raw tick is forgotten
            // at speed=1, maximum tick is close to 256 before raw tick is forgotten
            // hence we choose to saturate at UINT8_MAX; all animations related to the current
            // keypress should be completed by then
            // of course, at speed=0, maximum tick is 0 before raw tick is forgotten.
            uint16_t tick = scale16by8(g_rgb_reactive_framebuffer[j].released_tick, rgb_matrix_config.speed);
            if (g_rgb_reactive_framebuffer[j].pressed_tick < g_rgb_reactive_framebuffer[j].released_tick) {
                tick = 0;
            }
            if (tick > UINT8_MAX) {
                tick = UINT8_MAX;
            }
            if (dx == 0 || dy == 0) {
                // use a different, instantaneous pattern for the cross, 
                // which helps with feedback for gaming
                sum_opacity = qadd8(sum_opacity, UINT8_MAX - tick);
                continue;
            }

            // wavefront design: regardless of wave shape, last key
            // distance 256 away must start animation before, close to 
            // time 128 and
            // ground-zero-key must have ended animation

            // current wavefront choice:
            // transparency = min(255, 4 * |2 * tick - dist|)
            // you can plot on desmos to see how this looks like

            uint16_t transparency = 2 * tick; // [0, 512)
            if (dist > transparency) {
                transparency = dist - transparency;
            } else {
                transparency -= dist;
            }
            transparency *= 4; // [0, 2048)
            uint8_t opacity = transparency > UINT8_MAX ? 0 : (UINT8_MAX - transparency);

            // radial surface wave amplitude is proportional to 1/sqrt(radius)
            // we scale by 1/sqrt(radius / 32 + 1), and at distance 256 we have a bit less than roughly 1/3
            // equivalent to scaling by 256 * 4 / sqrt(radius/2 + 16) / 256, which we do instead to mitigate precision loss
            opacity = scale8(opacity, scale16by8(1023, sqrt16(dist / 2 + 16)));
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
#endif      // RGB_MATRIX_KEYREACTIVE_FRAMEBUFFER_ENABLED
