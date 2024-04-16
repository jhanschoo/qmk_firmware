#include QMK_KEYBOARD_H
#include "sofle_v2.h"
#include "keymap.h"

typedef struct {
    uint16_t kc1;
    uint16_t kc2;
    uint16_t kc3;
} tap_dance_triple_t;

typedef struct {
    int l1;
    int l2;
} tap_dance_bi_layer_t;

void tap_dance_triple_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_triple_t *triple = (tap_dance_triple_t *) user_data;

    if (state->count == 3) {
        register_code16(triple->kc3);
        state->finished = true;
    }
}

void tap_dance_triple_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_triple_t *triple = (tap_dance_triple_t *) user_data;

    if (state->count == 1) {
        register_code16(triple->kc1);
    } else if (state->count == 2) {
        register_code16(triple->kc2);
    }
}

void tap_dance_triple_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_triple_t *triple = (tap_dance_triple_t *) user_data;

    if (state->count == 1) {
        wait_ms(TAP_CODE_DELAY);
        unregister_code16(triple->kc1);
    } else if (state->count == 2) {
        wait_ms(TAP_CODE_DELAY);
        unregister_code16(triple->kc2);
    } else if (state->count == 3) {
        unregister_code16(triple->kc3);
    }
}

#define ACTION_TAP_DANCE_TRIPLE(kc1, kc2, kc3) \
    { .fn = {tap_dance_triple_on_each_tap, tap_dance_triple_finished, tap_dance_triple_reset}, .user_data = (void *)&((tap_dance_triple_t){kc1, kc2, kc3}), }

void tap_dance_bi_layer_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_bi_layer_t *layer_data = (tap_dance_bi_layer_t *) user_data;

    if (state->count >= 2) {
        layer_on(layer_data->l2);
        layer_off(layer_data->l1);
        state->finished = true;
    }
}

void tap_dance_bi_layer_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_bi_layer_t *layer_data = (tap_dance_bi_layer_t *) user_data;

    if (state->count == 1) {
        layer_on(layer_data->l1);
        layer_off(layer_data->l2);
    }
}

#define ACTION_TAP_DANCE_BI_LAYER(l1, l2) \
    { .fn = {tap_dance_bi_layer_on_each_tap, tap_dance_bi_layer_finished, NULL}, .user_data = (void *)&((tap_dance_bi_layer_t){l1, l2}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_L_ACTION] = ACTION_TAP_DANCE_TRIPLE(KC_LBRC, KC_LPRN, KC_LABK),
    [TD_R_ACTION] = ACTION_TAP_DANCE_TRIPLE(KC_RBRC, KC_RPRN, KC_RABK),
    [TD_FN_ACTION] = ACTION_TAP_DANCE_BI_LAYER(_DEFAULT, _QWERTY),
};
