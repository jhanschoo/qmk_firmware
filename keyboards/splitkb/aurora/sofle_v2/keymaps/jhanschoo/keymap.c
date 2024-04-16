#include QMK_KEYBOARD_H
#include "sofle_v2.h"
#include "keymap.h"

// // BEGIN tap dance code, this was formerly in the tap_dance.c file
// typedef struct {
//     int l1;
//     int l2;
// } tap_dance_bi_layer_t;

// void tap_dance_bi_layer_on_each_tap(tap_dance_state_t *state, void *user_data) {
//     tap_dance_bi_layer_t *layer_data = (tap_dance_bi_layer_t *) user_data;

//     if (state->count >= 2) {
//         layer_on(layer_data->l2);
//         layer_off(layer_data->l1);
//         state->finished = true;
//     }
// }

// void tap_dance_bi_layer_finished(tap_dance_state_t *state, void *user_data) {
//     tap_dance_bi_layer_t *layer_data = (tap_dance_bi_layer_t *) user_data;

//     if (state->count == 1) {
//         layer_on(layer_data->l1);
//         layer_off(layer_data->l2);
//     }
// }

// #define ACTION_TAP_DANCE_BI_LAYER(l1, l2) { .fn = {tap_dance_bi_layer_on_each_tap, tap_dance_bi_layer_finished, NULL}, .user_data = (void *)&((tap_dance_bi_layer_t){l1, l2}), }

// tap_dance_action_t tap_dance_actions[] = {
//     /* [TD_L_ACTION] = ACTION_TAP_DANCE_TRIPLE(KC_LBRC, KC_LPRN, KC_LABK),
//     [TD_R_ACTION] = ACTION_TAP_DANCE_TRIPLE(KC_RBRC, KC_RPRN, KC_RABK), */
//     [TD_FN_ACTION] = ACTION_TAP_DANCE_BI_LAYER(_DEFAULT, _GAME),
// };
// // END tap dance code

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

#define LC_SPC C(KC_SPC)

// #define TD_L TD(TD_L_ACTION)
// #define TD_R TD(TD_R_ACTION)
// #define TD_FN TD(TD_FN_ACTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [_DEFAULT] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_EQL,
        KC_BSPC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
            KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_ENT,
        KC_RALT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_ESC,
            LC_SPC, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_LWIN,
        KC_LEFT,KC_DOWN,MO_L,   KC_SPC, KC_LCTL,
            KC_RALT,KC_LSFT, MO_R,   KC_UP,  KC_RGHT
    ),
    // game layer
    [_GAME] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
            KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_EQL,
        KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
            KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
        KC_LCTL,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_ESC,
            LC_SPC, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_CAPS,
        KC_LALT,KC_ESC, MO_L,  KC_SPC, KC_BSPC,
            KC_LWIN,KC_ENT, MO_R,   KC_LBRC,KC_RBRC
    ),
    // Lower layer
    [_LOWER] = LAYOUT(
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
            KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        _______,_______,_______,_______,_______,KC_DQUO,
            KC_DQUO,_______,_______,_______,_______,KC_F12,
        KC_DEL, KC_LABK,KC_LCBR,KC_LBRC,KC_LPRN,KC_QUOT,
            KC_QUOT,KC_RPRN,KC_RBRC,KC_RCBR,KC_RABK,KC_INS,
        _______,_______,_______,_______,_______,KC_BSLS,_______,
            _______,KC_PIPE,_______,_______,_______,KC_BSLS,_______,
        KC_HOME,KC_PGDN, _______,_______,_______,
            _______,_______,MO_A,   KC_PGUP,KC_END
    ),
    // Raise layer
    [_RAISE] = LAYOUT(
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
            KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        KC_TILD,_______,_______,_______,_______,KC_DQUO,
            KC_DQUO,_______,_______,_______,_______,KC_F12,
        KC_DEL, KC_LABK,KC_LCBR,KC_LBRC,KC_LPRN,KC_QUOT,
            KC_QUOT,KC_RPRN,KC_RBRC,KC_RCBR,KC_RABK,KC_INS,
        _______,_______,_______,_______,_______,KC_BSLS,_______,
            _______,KC_PIPE,_______,_______,_______,KC_PIPE,_______,
        KC_PSCR,KC_PAUS,MO_A,   _______,_______,
            _______,_______,_______,KC_CAPS,KC_SCRL
    ),
    // Adjust layer
    [_ADJUST] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,KC_NUM, KC_PSLS,KC_PAST,KC_PMNS,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
        XXXXXXX,RM_TOGG,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,KC_P4,  KC_P5,  KC_P6,  KC_PENT,
        XXXXXXX,RM_NEXT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,KC_P1,  KC_P2,  KC_P3,  KC_PENT,
        _______,_______,_______,_______,_______,
            _______,_______,_______,KC_P0,  KC_PDOT
    )
};

static size_t locale_num = 0;

#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    static const uint16_t num_keys[] = {
        [0] = S(A(KC_1)),
        [1] = S(A(KC_2)),
        [2] = S(A(KC_3)),
        [3] = S(A(KC_4)),
        [4] = S(A(KC_5)),
        [5] = S(A(KC_6)),
        [6] = S(A(KC_7)),
        [7] = S(A(KC_8)),
        [8] = S(A(KC_9)),
        [9] = S(A(KC_0))
    };
    if (index == 0) { /* First encoder */
        if (clockwise) {
            locale_num = 0;
            layer_on(_GAME);
        } else {
            locale_num = 1;
            layer_off(_GAME);
        }
        tap_code16(num_keys[locale_num]);
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            locale_num = locale_num % 8 + 1;
        } else {
            locale_num = (locale_num + 8 - 1) % 8;
        }
        tap_code16(num_keys[locale_num]);
    }
    return false;
}
#endif


#if defined(OLED_ENABLE)
void render_blank_line_user(void) {
    oled_write_P(PSTR("    "), false);
}

void render_layer_state_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LOWER:
            oled_write_P(PSTR("LWR LWR LWR "), true);
            break;
        case _RAISE:
            oled_write_P(PSTR(" RSE RSE RSE"), true);
            break;
        case _ADJUST:
            oled_write_P(PSTR("AD   JU   ST"), true);
            break;
        default:
            oled_write_P(PSTR("            "), false);
    }
}

void render_mod_status_user(uint8_t modifiers) {
    oled_write_P(PSTR(modifiers & MOD_MASK_SHIFT ? "SHFT" : "    "), false);
    oled_write_P(PSTR(modifiers & MOD_MASK_CTRL ? "CTRL" : "    "), false);
    oled_write_P(PSTR(modifiers & MOD_MASK_ALT ? "ALT " : "    "), false);
    oled_write_P(PSTR(modifiers & MOD_MASK_GUI ? "GUI " : "    "), false);
}

void render_led_state_user(void) {
    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR(led_usb_state.num_lock ? "NUM " : "    "), led_usb_state.num_lock);
    oled_write_P(PSTR(led_usb_state.caps_lock ? "CAPS" : "    "), led_usb_state.caps_lock);
    oled_write_P(PSTR(led_usb_state.scroll_lock ? "SCRL" : "    "), led_usb_state.scroll_lock);
}

void render_locale_state_user(void) {
    switch (locale_num) {
        case 0:
            oled_write_P(PSTR("ENUSQWER"), false);
            break;
        case 1:
            oled_write_P(PSTR("ENUSCLMK"), false);
            break;
        case 2:
            oled_write_P(PSTR("ENUSEURL"), false);
            break;
        case 3:
            oled_write_P(PSTR("ZHCNHYPY"), false);
            break;
        case 4:
            oled_write_P(PSTR("ZHTWBPMF"), false);
            break;
        case 5:
            oled_write_P(PSTR("JPJPKANA"), false);
            break;
        case 6:
            oled_write_P(PSTR("ELGRPOLY"), false);
            break;
        case 7:
            oled_write_P(PSTR("SKINITRN"), false);
            break;
        default:
            oled_write_P(PSTR("UNKNUNKN"), false);
    }
}

bool oled_task_user() {
    if (is_keyboard_master()) {
        render_locale_state_user();
        render_locale_state_user();
    } else {
        oled_write_P(PSTR("SPLIT.KBSOFLE_v2"), false);
    }
    render_layer_state_user();
    render_mod_status_user(get_mods()|get_weak_mods()|get_oneshot_mods());
    render_blank_line_user();
    render_led_state_user();
    return false;
}
#endif
