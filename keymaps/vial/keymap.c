#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *       ┌───┬───┬───┐                   ┌───┬───┬───┐
     *       │   │   │GUI├───┐           ┌───┤Alt│   │   │
     *       └───┴───┴───┤Lwr├───┐   ┌───┤Rse├───┴───┴───┘
     *                   └───┤Spc│   │Ent├───┘
     *                       └───┘   └───┘
     */
    [_BASE] = LAYOUT_split_3x6_5(
        KC_TAB,     KC_Q,     KC_W,     KC_E,       KC_R,     KC_T,                     KC_Y,       KC_U,     KC_I,       KC_O,     KC_P,     KC_DEL,
        KC_LSFT,    KC_A,     KC_S,     KC_D,       KC_F,     KC_G,                     KC_H,       KC_J,     KC_K,       KC_L,     KC_SCLN,  KC_QUOT,
        KC_LCTL,    KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,                     KC_N,       KC_M,     KC_COMM,    KC_DOT,   KC_SLSH,  KC_RSFT,
                    KC_NO,  KC_LALT,  MO(_LOWER), KC_SPC,   KC_BSPC,                  KC_ENT,    KC_SPC,   MO(_RAISE), KC_LGUI,  KC_NO
    ),

    [_LOWER] = LAYOUT_split_3x6_5(
        KC_TILD,     KC_1,     KC_2,     KC_3,       KC_4,     KC_5,                     KC_6,       KC_7,     KC_8,       KC_9,     KC_0,     KC_ESC,
       KC_GRV,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_PSCR,                  KC_MINS,    KC_PLUS,   KC_LCBR,    KC_RCBR,  KC_PIPE,  KC_TRNS,
        KC_CAPS,    KC_MPRV,  KC_MPLY,  KC_MNXT,    KC_VOLD,  KC_VOIU,                  KC_UNDS,    KC_EQL,  KC_LBRC,    KC_RBRC,  KC_BSLS,  KC_TRNS,
                    KC_TRNS,  KC_RALT,  MO(_LOWER), KC_TRNS,   KC_TRNS,                  KC_TRNS,    KC_TRNS,   MO(_RAISE), KC_RGUI,  KC_TRNS
    ),
    
    [_RAISE] = LAYOUT_split_3x6_5(
        KC_TRNS,     KC_EXLM,  KC_AT,    KC_HASH,    KC_DLR,   KC_PERC,                  KC_CIRC,    KC_AMPR,     KC_ASTR,    KC_LPRN,  KC_RPRN,  KC_BSPC,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_BRID,  KC_BRIU,                  KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                    KC_TRNS,  KC_TRNS,  MO(_LOWER), KC_TRNS,   KC_TRNS,                 KC_TRNS,    KC_TRNS,   MO(_RAISE), KC_TRNS,  KC_TRNS
    ),

    [_ADJUST] = LAYOUT_split_3x6_5(
        KC_F1,      KC_F2,    KC_F3,    KC_F4,      KC_F5,    KC_F6,                    KC_F7,      KC_F8,    KC_F9,      KC_F10,   KC_F11,   KC_F12,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,                  KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                   KC_TRNS,  KC_TRNS,  MO(_LOWER), KC_TRNS,   KC_TRNS,                  KC_TRNS,    KC_TRNS,   MO(_RAISE), KC_TRNS,  KC_TRNS
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

