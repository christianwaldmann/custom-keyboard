#include QMK_KEYBOARD_H


enum layers {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD,
    _RIGHT,
    _LEFT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,           KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LSFT,          LT(_LEFT,KC_SPC),                 LT(_RIGHT,KC_BSPC), TO(_FIRST)
        // ----------------------------------------------------------------------------------------------
    ),

    [_FIRST] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_NO,   KC_NO,   KC_PGUP, KC_NO,   KC_NO,          KC_TRNS,    KC_COPY, KC_PSTE, KC_CUT,  KC_NO,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_NO,          KC_TRNS,    KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT,
        KC_NO,   KC_HOME, KC_PGDN, KC_END,  KC_NO,          KC_TRNS,    KC_UNDO, KC_AGIN, KC_FIND, KC_NO,
                 TO(_BASE),        KC_TRNS,                             KC_TRNS,          TO(_SECOND)
        // ----------------------------------------------------------------------------------------------
    ),

    [_SECOND] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLU,        KC_BRIU,  KC_BTN1, KC_BTN3, KC_BTN2, KC_NO,
        KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_VOLD,        KC_BRID,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_ACL0, KC_BTN2, KC_BTN3, KC_BTN1, KC_WBAK,        KC_WFWD,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                 TO(_BASE),        KC_BTN1,                           KC_BTN2,          TO(_THIRD)
        // ----------------------------------------------------------------------------------------------
    ),

    [_THIRD] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
        KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_F11,         KC_F12,   KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT,
                 TO(_BASE),        LT(_LEFT,KC_SPC),                  LT(_RIGHT,KC_BSPC), TO(_BASE)
        // ----------------------------------------------------------------------------------------------
    ),

    [_RIGHT] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_MINS,  KC_ENT,  KC_SCLN, KC_LBRC, KC_RBRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_EQL,   KC_RALT, KC_RGUI, KC_RCTL, KC_BSLS,
                 KC_LSFT,          KC_SPC,                            KC_NO,            KC_NO
        // ----------------------------------------------------------------------------------------------
    ),

    [_LEFT] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_EXLM, KC_LPRN, KC_RPRN, KC_TAB,  KC_GRV,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 OSM(MOD_HYPR),    KC_NO,                             KC_BSPC,          KC_DEL
        // ----------------------------------------------------------------------------------------------
    )
};

