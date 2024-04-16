// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(rainbow_diamond)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static HSV rainbow_diamond_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h += abs8(g_led_config.point[i].y - k_rgb_matrix_center.y) + abs8(g_led_config.point[i].x - k_rgb_matrix_center.x) - time;
    return hsv;
}

bool rainbow_diamond(effect_params_t* params) {
    return effect_runner_i(params, &rainbow_diamond_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
