#include QMK_KEYBOARD_H
#include "sofle_v2.h"
#include "keymap.h"

// BEGIN tap dance code, this was formerly in the tap_dance.c file
typedef struct {
    int l1;
    int l2;
} tap_dance_bi_layer_t;

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
    /* [TD_L_ACTION] = ACTION_TAP_DANCE_TRIPLE(KC_LBRC, KC_LPRN, KC_LABK),
    [TD_R_ACTION] = ACTION_TAP_DANCE_TRIPLE(KC_RBRC, KC_RPRN, KC_RABK), */
    [TD_FN_ACTION] = ACTION_TAP_DANCE_BI_LAYER(_DEFAULT, _QWERTY),
};
// END tap dance code

// layer shorthand
#define MO_L MO(_LOWER)
#define MO_R MO(_RAISE)
#define MO_A MO(_ADJUST)

// Home row mods
// Base layer
// #define RG_Q RGUI_T(KC_Q)
// #define RA_W RALT_T(KC_W)
// #define RS_F RSFT_T(KC_F)
// #define RC_P RCTL_T(KC_P)

// #define RC_L RCTL_T(KC_L)
// #define RS_U RSFT_T(KC_U)
// #define RA_Y RALT_T(KC_Y)
// #define RG_SCLN RGUI_T(KC_SCLN)

// #define LG_A LGUI_T(KC_A)
// #define LA_R LALT_T(KC_R)
// #define LS_S LSFT_T(KC_S)
// #define LC_T LCTL_T(KC_T)

// #define LC_N LCTL_T(KC_N)
// #define LS_E LSFT_T(KC_E)
// #define LA_I LALT_T(KC_I)
// #define LG_O LGUI_T(KC_O)

// Lower layer
// #define LG_1 LGUI_T(KC_1)
// #define LA_2 LALT_T(KC_2)
// #define LS_3 LSFT_T(KC_3)
// #define LC_4 LCTL_T(KC_4)

// #define RC_7 RCTL_T(KC_7)
// #define RS_8 RSFT_T(KC_8)
// #define RA_9 RALT_T(KC_9)
// #define RG_0 RGUI_T(KC_0)

#define LSA_1 LSA(KC_1)
#define LSA_2 LSA(KC_2)
#define LSA_3 LSA(KC_3)
#define LSA_4 LSA(KC_4)
#define LSA_5 LSA(KC_5)
#define LSA_6 LSA(KC_6)
#define LSA_7 LSA(KC_7)
#define LSA_8 LSA(KC_8)
#define LSA_9 LSA(KC_9)
#define LSA_0 LSA(KC_0)
#define LGS LGUI(KC_SPC)

// #define TD_L TD(TD_L_ACTION)
// #define TD_R TD(TD_R_ACTION)
#define TD_FN TD(TD_FN_ACTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [_DEFAULT] = LAYOUT(
        KC_EQL, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        QK_GESC,KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,
            KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSLS,
        KC_BSPC,KC_A,   KC_R,   KC_S,   KC_T,   KC_G,
            KC_M,   KC_N,   KC_E,   KC_I,   KC_O,   KC_ENT,
        KC_TAB, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V, TD_FN,
            KC_LWIN,KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,KC_QUOT,
        KC_LEFT,KC_RGHT,MO_L,   KC_SPC, KC_LCTL,
            KC_LALT,KC_LSFT, MO_R,   KC_DOWN,KC_UP
    ),
    // qwerty layer
    [_QWERTY] = LAYOUT(
        KC_EQL, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_GRV, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSLS,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
            KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_LCTL,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, TD_FN,
            KC_LWIN,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_CAPS,
        KC_LALT,KC_TAB, MO_L,  KC_SPC, KC_BSPC,
            KC_ESC, KC_ENT, MO_R,   KC_LBRC,KC_RBRC
    ),
    // Lower layer
    [_LOWER] = LAYOUT(
        LGS,    LSA_1,  LSA_2,  LSA_3,  LSA_4,  LSA_5,
            LSA_6,  LSA_7,  LSA_8,  LSA_9,  LSA_0,_______,
        KC_GRV, KC_LWIN,KC_LALT,KC_LSFT,KC_LCTL,_______,
            _______,KC_LCTL,KC_LSFT,KC_LALT,KC_LWIN,KC_APP,
        KC_DEL, KC_LABK,KC_LCBR,KC_LBRC,KC_LPRN,KC_SLSH,
            KC_BSLS,KC_RPRN,KC_RBRC,KC_RCBR,KC_RABK,KC_INS,
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  _______,
            _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
        KC_HOME,KC_END, _______,_______,KC_LALT,
            KC_RALT,_______,MO_A,   KC_PGDN,KC_PGUP
    ),
    // Raise layer
    [_RAISE] = LAYOUT(
        LGS,    LSA_1,  LSA_2,  LSA_3,  LSA_4,  LSA_5,
            LSA_6,  LSA_7,  LSA_8,  LSA_9,  LSA_0,_______,
        KC_GRV, KC_RWIN,KC_RALT,KC_RSFT,KC_RCTL,_______,
            _______,KC_RCTL,KC_RSFT,KC_RALT,KC_RWIN,_______,
        KC_DEL, KC_LABK,KC_LCBR,KC_LBRC,KC_LPRN,KC_SLSH,
            KC_BSLS,KC_RPRN,KC_RBRC,KC_RCBR,KC_RABK,KC_INS,
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  _______,
            _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
        KC_CAPS,KC_PSCR,MO_A,   _______,KC_RCTL,
            KC_LCTL,_______,_______,KC_SCRL,  KC_PAUS
    ),
    // Adjust layer
    [_ADJUST] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,RGB_TOG,RGB_HUI, RGB_SAI,RGB_VAI,XXXXXXX,
            XXXXXXX,KC_VOLD,KC_MUTE,KC_VOLU,XXXXXXX,XXXXXXX,
        XXXXXXX,RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,XXXXXXX,
        _______,_______,_______,_______,KC_LWIN,
            KC_RWIN,_______,_______,_______,_______
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_QWERTY]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_LOWER]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_RAISE]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_ADJUST]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

layer_state_t layer_state_set_user(layer_state_t state) {
    rgb_matrix_sethsv_noeeprom(HSV_RED_USER);
    return state;
}
