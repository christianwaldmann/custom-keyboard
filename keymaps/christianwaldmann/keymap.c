#include QMK_KEYBOARD_H


enum layers {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD,
    _RIGHT,
    _LEFT
};


// Custom keys so I can write german "Umlaute" with US international layout
// -> sends RALT when holding the switch-layer-up key
//
// mostly needed for:
// ä -> RALT + q
// ö -> RALT + p
// ü -> RALT + y
// ß -> RALT + s
enum custom_keycodes {
    TO1_RALT = SAFE_RANGE,
    TO2_RALT,
    TO3_RALT,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,           KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LSFT,          LT(_LEFT,KC_SPC),                 LT(_RIGHT,KC_BSPC), TO1_RALT
        // ----------------------------------------------------------------------------------------------
    ),

    [_FIRST] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_NO,   KC_NO,   KC_PGUP, KC_NO,   KC_NO,          KC_TRNS,    KC_COPY, KC_PSTE, KC_CUT,  KC_NO,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_NO,          KC_TRNS,    KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT,
        KC_NO,   KC_HOME, KC_PGDN, KC_END,  KC_NO,          KC_TRNS,    KC_UNDO, KC_AGIN, KC_FIND, KC_NO,
                 TO(_BASE),        KC_TRNS,                             KC_TRNS,          TO2_RALT
        // ----------------------------------------------------------------------------------------------
    ),

    [_SECOND] = LAYOUT_split_3x5_2(
        // ----------------------------------------------------------------------------------------------
        KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_VOLU,        KC_BRIU,  KC_BTN1, KC_BTN3, KC_BTN2, KC_NO,
        KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_VOLD,        KC_BRID,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        KC_ACL0, KC_BTN2, KC_BTN3, KC_BTN1, KC_WBAK,        KC_WFWD,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                 TO(_BASE),        KC_BTN1,                           KC_BTN2,          TO3_RALT
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


// ----- Logic for sending RALT when holding the switch-layer-up keys
typedef struct {
    uint16_t timer;
    bool is_held;
    bool is_pressed;
} hold_key_state_t;

static hold_key_state_t to1 = {0, false, false};
static hold_key_state_t to2 = {0, false, false};
static hold_key_state_t to3 = {0, false, false};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    hold_key_state_t *state = NULL;

    switch (keycode) {
        case TO1_RALT: state = &to1; break;
        case TO2_RALT: state = &to2; break;
        case TO3_RALT: state = &to3; break;
        default: return true;
    }

    if (record->event.pressed) {
        state->timer = timer_read();
        state->is_held = false;
        state->is_pressed = true;
    } else {
        if (state->is_held) {
            unregister_code(KC_RALT);
        } else {
            switch (keycode) {
                case TO1_RALT: layer_move(1); break;
                case TO2_RALT: layer_move(2); break;
                case TO3_RALT: layer_move(3); break;
            }
        }
        state->is_pressed = false;
    }

    return false; // Skip default behavior
}


void matrix_scan_user(void) {
    hold_key_state_t *states[] = { &to1, &to2, &to3 };
    for (int i = 0; i < 3; i++) {
        hold_key_state_t *state = states[i];
        if (state->is_pressed && !state->is_held && timer_elapsed(state->timer) > TAPPING_TERM) {
            state->is_held = true;
            register_code(KC_RALT);
        }
    }
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TO1_RALT:
        case TO2_RALT:
        case TO3_RALT:
            return 80;
    }
    return TAPPING_TERM;
}
