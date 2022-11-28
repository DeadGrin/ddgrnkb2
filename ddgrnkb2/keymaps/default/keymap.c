#include QMK_KEYBOARD_H

enum combo_events {
    W_LANG,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM lt_w_lang[] = { KC_LALT, KC_LSFT, COMBO_END };

combo_t key_combos[] = {
  [W_LANG] = COMBO_ACTION(lt_w_lang),
};

void process_combo_event(uint16_t combo_index, bool pressed) 
{
    switch (combo_index) {
    case W_LANG:
        if (pressed) {
            tap_code16(S(KC_LALT));
            layer_invert(1);
        }
        break;
    }
}

void keyboard_pre_init_user(void) {
    setPinOutput(GP28);  
    setPinOutput(GP26);  
}

layer_state_t layer_state_set_user(layer_state_t state) {

if(IS_LAYER_ON_STATE(state, 1))
{
     writePinHigh(GP28);
}
else
{
    writePinLow(GP28);

}
if(IS_LAYER_ON_STATE(state, 2))
{
    writePinHigh(GP26);
}
else
{
    writePinLow(GP26);
}
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ - │ * │ / │ NL│ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │PRT│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ 7 │ 8 │ 9 │TAB│ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ ; │ [ │ ] │ ` │
     * │ + ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ 4 │ 5 │ 6 │CAP│ A │ R │ S │ T │ D │ H │ N │ E │ I │ O │ ' │ e │ e │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │ 1 │ 2 │ 3 │SHT│ Z │ X │ C │ V │ B │ K │ M │ , │ . │ / │ \ │ │ │SHT│
     * │ENT├───┴───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │   │   0   │ . │CTR│WIN│ALT│ F │BCK│   │   │DEL│ F │ALT│CTR│ ─ │ │ │ ─ │
     * └───┴───────┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x18(
        KC_PMNS, KC_PAST, KC_PSLS, KC_NUM, KC_ESC,   KC_1,    KC_2,    KC_3,  KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PSCR, 
                 KC_P7,   KC_P8,   KC_P9,   KC_TAB,  KC_Q,    KC_W,    KC_F,  KC_P,    KC_G,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_GRAVE, 
        KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_CAPS, KC_A,    KC_R,    KC_S,  KC_T,    KC_D,   KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,  KC_ENT, 
        KC_PENT, KC_P1,   KC_P2,   KC_P3,   KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,   KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, KC_UP,   KC_RSFT, 
                 KC_P0,            KC_PDOT, KC_LCTL, KC_LGUI, KC_LALT, TG(1), KC_BSPC, KC_SPC, KC_SPC, KC_DEL, TG(2),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [1] = LAYOUT_ortho_5x18(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                 KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [2] = LAYOUT_ortho_5x18(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, 
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
    
};

