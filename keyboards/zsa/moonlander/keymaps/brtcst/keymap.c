#include QMK_KEYBOARD_H
#include "version.h"
//#include "keymap_br_abnt2.h"
#include "keymap_bepo.h"
//#include "keymap_contributions.h"
#include "keymap_us_international.h"
// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  CMC_0,
  CMC_1,
  //CMC_2,
  //CMC_3,
  //CMC_4,
  //CMC_5,
  CMC_6,
  CMC_7,
  CMC_8,
  CMC_9,
  CMC_10,
  CMC_11,
  CMC_12,
  CMC_13,
  CMC_14,
  CMC_15,
  CMC_16,
  CMC_17,
  CMC_18,
  CMC_19,
  BP_LSPO,
  BP_RSPC,
  CMC_END_RETURN
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state[23];

enum tap_dance_codes {
  D_0,
  D_1,
  D_2,
  D_3,
  D_4,
  D_5, //dispo
  D_6,
  D_7,
  D_8,
  D_9,
  D_10,
  D_11,
  D_12,
  D_13,
  D_14,
  D_15,
  D_16,
  D_17,
  D_18,
  D_19,
  D_20,
  D_21,
  D_22
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, QK_LEAD,              BP_PERC, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,
    XXXXXXX, BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV, XXXXXXX,              TD(D_22),BP_DCIR, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
    KC_CAPS, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, BP_W,                 BP_CCED, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                   BP_QUOT, BP_Q,    BP_G,    BP_H,    BP_F,    KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_TAB,  TD(D_21),         LGUI(BP_SCLN),        TD(D_2),          KC_BSPC, KC_DEL, KC_LALT, MO(4),   KC_RCTL,
                                        KC_SPC,  SH_MON,  TD(D_1),              TD(D_3), MO(2),   KC_RALT
  ),
  [1] = LAYOUT_moonlander( //gaming
    _______, _______, _______, _______, _______, _______, BP_AT,                _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _______, _______, _______, _______, _______, BP_DCIR,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, KC_LALT, _______, _______,          _______,              TD(D_4),          _______, _______, _______, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
  ),
  [2] = LAYOUT_moonlander( //numpad
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, RGB_VAD, RGB_VAI,              LGUI(LALT(BP_B)), XXXXXXX, KC_NUM,  KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS,
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, XXXXXXX,              LSFT(LALT(LCTL(KC_F18))), XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
    BP_PERC, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,                LSFT(LALT(LCTL(KC_F17))), XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, CMC_6,   XXXXXXX,                                CMC_9,   KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,              _______ ,_______, KC_KP_0, BP_DOT, BP_COMM, XXXXXXX,
                                        RALT(LSFT(KC_SPC)),_______, _______,    _______, _______, _______
    ),
  [3] = LAYOUT_moonlander( // Fx & arrows
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_VOLU,               XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, TD(D_6), TD(D_7), TD(D_8), TD(D_9), XXXXXXX,KC_VOLD,               XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
    _______, TD(D_10), TD(D_11), TD(D_12), TD(D_13), XXXXXXX, TD(D_18),              XXXXXXX, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), XXXXXXX,
    _______, TD(D_14), TD(D_15), TD(D_16), TD(D_17), XXXXXXX,                            XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______,           XXXXXXX,             _______,          LCTL(KC_BSPC),XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
                                        KC_MPRV, TD(D_19), KC_MNXT,             LGUI(LCTL(KC_LEFT)),TD(D_20), LGUI(LCTL(KC_RIGHT))
    ),
  [4] = LAYOUT_moonlander( // arrows & macros
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DM_REC1, DM_RSTP, DM_PLY1, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DM_REC2, DM_RSTP, DM_PLY2, _______, _______,              _______, _______, _______, _______, KC_PGUP, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, TD(D_22),KC_UP,   KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______,          _______,              _______,          KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
    ),
  [5] = LAYOUT_moonlander(
    BP_EQL,  BP_ASTR, BP_SLSH, BP_MINS, BP_PLUS, BP_AT,   TO(0),                _______, _______, _______, _______, _______, _______, _______,
    BP_Z,    BP_J,    BP_L,    BP_D,    BP_V,    BP_DCIR, _______,              _______, CMC_10, CMC_11, CMC_12, CMC_13, _______, _______,
    BP_M,    BP_N,    BP_R,    BP_S,    BP_T,    BP_C,    _______,              _______, _______, CMC_14, XXXXXXX,CMC_15, _______, _______,
    OSM(MOD_LSFT), BP_F, BP_H, BP_G,    BP_Q,    BP_QUOT,                                CMC_16,  CMC_17,  CMC_18,  CMC_19,  _______, _______,
    _______, _______, _______, _______,  _______,          LGUI(LSFT(BP_CCED)),  _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
    ),
  [6] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,              _______,          _______, _______, _______, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
    ),
};

const uint16_t PROGMEM combo0[] = { BP_T, BP_S, COMBO_END};
const uint16_t PROGMEM combo1[] = { BP_O, BP_EACU, BP_P, COMBO_END};
const uint16_t PROGMEM combo2[] = { BP_V, BP_L, BP_D, COMBO_END};
const uint16_t PROGMEM combo3[] = { BP_P, BP_O, COMBO_END};
const uint16_t PROGMEM combo4[] = { BP_V, BP_D, COMBO_END};
const uint16_t PROGMEM combo5[] = { BP_EACU, BP_P, COMBO_END};
const uint16_t PROGMEM combo6[] = { BP_D, BP_L, COMBO_END};
const uint16_t PROGMEM combo7[] = { BP_I, BP_DOT, COMBO_END};
const uint16_t PROGMEM combo8[] = { BP_Q, BP_S, COMBO_END};
const uint16_t PROGMEM combo9[] = { BP_C, BP_T, COMBO_END};
const uint16_t PROGMEM combo10[] = { BP_S, BP_R, COMBO_END};
const uint16_t PROGMEM combo11[] = { BP_G, BP_R, COMBO_END};
const uint16_t PROGMEM combo12[] = { BP_E, BP_COMM, COMBO_END};
const uint16_t PROGMEM combo13[] = { BP_T, BP_S, BP_R, COMBO_END};
const uint16_t PROGMEM combo14[] = { BP_U, BP_I, COMBO_END};
//const uint16_t PROGMEM combo15[] = { BP_I, BP_E, COMBO_END};
const uint16_t PROGMEM combo16[] = { BP_S, BP_H, COMBO_END};
const uint16_t PROGMEM combo17[] = { BP_P, BP_E, COMBO_END};
const uint16_t PROGMEM combo18[] = { BP_T, BP_D, COMBO_END};
const uint16_t PROGMEM combo19[] = { KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM combo20[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo21[] = { BP_QUOT, BP_T, COMBO_END};
const uint16_t PROGMEM combo22[] = { BP_C, BP_V, COMBO_END};
const uint16_t PROGMEM combo23[] = { BP_E, BP_K, COMBO_END};
const uint16_t PROGMEM combo24[] = { BP_S, BP_L, COMBO_END};
const uint16_t PROGMEM combo27[] = { BP_C, BP_T, BP_S, COMBO_END};
const uint16_t PROGMEM combo28[] = { BP_U, BP_I, BP_E, COMBO_END};
const uint16_t PROGMEM combo29[] = { BP_X, BP_DOT, COMBO_END};
const uint16_t PROGMEM combo30[] = { BP_Q, BP_G, COMBO_END};
const uint16_t PROGMEM combo31[] = { BP_K, BP_DOT, COMBO_END};
const uint16_t PROGMEM combo32[] = { BP_Q, BP_G, BP_H, COMBO_END};

enum combo_events {
  COMBO_0,
  COMBO_1,
  COMBO_2,
  COMBO_3,
  COMBO_4,
  COMBO_5,
  COMBO_6,
  COMBO_7,
  COMBO_8,
  COMBO_9,
  COMBO_10,
  COMBO_11,
  COMBO_12,
  COMBO_13,
  COMBO_14,
//  COMBO_15,
  COMBO_16,
  COMBO_17,
  COMBO_18,
  COMBO_19,
  COMBO_20,
  COMBO_21,
  COMBO_22,
  COMBO_23,
  COMBO_24,
  COMBO_27,
  COMBO_28,
  COMBO_29,
  COMBO_30,
  COMBO_31,
  COMBO_32
};

combo_t key_combos[] = {
    [COMBO_0] = COMBO(combo0, BP_MINS),
    [COMBO_1] = COMBO(combo1, BP_LBRC),
    [COMBO_2] = COMBO(combo2, BP_RBRC),
    [COMBO_3] = COMBO(combo3, BP_LPRN),
    [COMBO_4] = COMBO(combo4, BP_RPRN),
    [COMBO_5] = COMBO(combo5, BP_LCBR),
    [COMBO_6] = COMBO(combo6, BP_RCBR),
    [COMBO_7] = COMBO(combo7, CMC_0),
    [COMBO_8] = COMBO(combo8, CMC_1),
    [COMBO_9] = COMBO(combo9, BP_PLUS),
    [COMBO_10] = COMBO(combo10, BP_ASTR),
    [COMBO_11] = COMBO(combo11, BP_SLSH),
    [COMBO_12] = COMBO(combo12, BP_SCLN),
    [COMBO_13] = COMBO(combo13, BP_EQL),
    [COMBO_14] = COMBO(combo14, BP_HASH),
    //[COMBO_15] = COMBO(combo15, KC_TAB),
    [COMBO_16] = COMBO(combo16, BP_BSLS),
    [COMBO_17] = COMBO(combo17, BP_LABK),
    [COMBO_18] = COMBO(combo18, BP_RABK),
    [COMBO_19] = COMBO(combo19, KC_PGUP),
    [COMBO_20] = COMBO(combo20, KC_PGDN),
    [COMBO_21] = COMBO(combo21, RALT(BP_COMM)),
    [COMBO_22] = COMBO(combo22, BP_DQUO),
    [COMBO_23] = COMBO(combo23, BP_GRV),
    [COMBO_24] = COMBO(combo24, BP_AT),
    [COMBO_27] = COMBO(combo27, BP_NDSH),
    [COMBO_28] = COMBO(combo28, BP_DLR),
    [COMBO_29] = COMBO(combo29, KC_ENTER),
    [COMBO_30] = COMBO(combo30, KC_ENTER),
    [COMBO_31] = COMBO(combo31, BP_COLN),
    [COMBO_32] = COMBO(combo32, CMC_END_RETURN),
};

// Combos plus complexe, code si besoin

// enum combo_events {
//   EM_EMAIL,
//   BSPC_LSFT_CLEAR,
// };

// const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
// const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};

// combo_t key_combos[] = {
//   [EM_EMAIL] = COMBO_ACTION(email_combo),
//   [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
// };
// /* COMBO_ACTION(x) is same as COMBO(x, XXXXXXX) */

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case EM_EMAIL:
//       if (pressed) {
//         SEND_STRING("john.doe@example.com");
//       }
//       break;
//     case BSPC_LSFT_CLEAR:
//       if (pressed) {
//         tap_code16(KC_END);
//         tap_code16(S(KC_HOME));
//         tap_code16(KC_BSPC);
//       }
//       break;
//   }
// }


void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  rgb_matrix_mode(RGB_MATRIX_CUSTOM_BRTCST_CUSTOM);
  led_update_ports(host_keyboard_led_state());
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMC_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2) SS_DELAY(5) SS_LSFT(SS_RALT(SS_TAP(X_SPACE))));
    }
    break;
    case CMC_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_TAP(X_3));
    }
    break;
    //case CMC_2:
    //if (record->event.pressed) {
    //  SEND_STRING(SS_TAP(X_2) SS_DELAY(5) SS_LSFT(SS_RALT(SS_TAP(X_SPACE))));
    //}
    //break;
    //case CMC_3:
    //if (record->event.pressed) {
    //  SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_TAP(X_3));
    //}
    //break;
    //case CMC_4:
    //if (record->event.pressed) {
    //  SEND_STRING(SS_LSFT(SS_TAP(X_SPACE)) SS_DELAY(5) SS_LSFT(SS_TAP(X_G)));
    //}
    //break;
    //case CMC_5:
    //if (record->event.pressed) {
    //  SEND_STRING(SS_TAP(X_END) SS_DELAY(5) SS_TAP(X_ENTER));
    //}
    break;
    case CMC_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_LSFT(SS_TAP(X_V)));
    }
    break;
    case CMC_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_F18)))) SS_DELAY(5) SS_LALT(SS_LGUI(SS_TAP(X_Q))));
    }
    break;
    case CMC_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_F17)))) SS_DELAY(5) SS_LALT(SS_LGUI(SS_TAP(X_Q))));
    }
    break;
    case CMC_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
    }
    break;
    case CMC_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SPACE)) SS_DELAY(5) SS_LSFT(SS_TAP(X_Y)));
    }
    break;
    case CMC_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6) ));
    }
    break;
    case CMC_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1) ));
    }
    break;
    case CMC_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_7) ));
    }
    break;
    case CMC_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_0) ));
    }
    break;
    case CMC_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_2) ));
    }
    break;
    case CMC_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SPACE)) SS_DELAY(5) SS_LSFT(SS_TAP(X_N)));
    }
    break;
    case CMC_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_9) ));
    }
    break;
    case CMC_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_3) ));
    }
    break;
    case CMC_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_PLUS) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_8) ));
    }
    break;
    case CMC_END_RETURN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
    }
    break;

    case TD(D_19):
    case TD(D_20):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    /*case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;*/
    case TD(D_21):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (record->event.pressed && !action->state.finished) {
            switch (action->state.count) {
                case 0: layer_on(3); break;
                case 1: layer_on(5); break;
            }
        }
        break;
    case TD(D_22):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && !action->state.finished) {
            switch (action->state.count) {
                case 1: tap_code16(KC_END); break;
                case 2: tap_code16(KC_HOME); break;
            }
        }
        break;
  }
  return true;
}


void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_TAB));
        tap_code16(LCTL(KC_TAB));
        tap_code16(LCTL(KC_TAB));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_TAB));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_TAB)); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(KC_TAB))); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_TAB))); break;
        case DOUBLE_HOLD: register_code16(LGUI(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_TAB)); register_code16(LCTL(KC_TAB));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(KC_TAB))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_TAB))); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(KC_TAB)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_TAB)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(LGUI(BP_L)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(BP_L)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SPACE));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: layer_on(1); break;
        case DOUBLE_TAP: layer_move(1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: layer_off(1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
    }
    if(state->count > 3) {
        tap_code16(KC_INSERT);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_INSERT); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(BP_S))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(BP_A))); break;
        case DOUBLE_HOLD: register_code16(KC_PSCR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_INSERT); register_code16(KC_INSERT);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_INSERT); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(BP_S))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(BP_A))); break;
        case DOUBLE_HOLD: unregister_code16(KC_PSCR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_INSERT); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SPACE));
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
        case DOUBLE_TAP: layer_move(0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {

}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {

}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F14); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F14); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F15); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F15); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_F16); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_F16); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_F17); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_F17); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_F18); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_F18); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_F19); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_F19); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_F20); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_F20); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_F21); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_F21); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_F22); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_F22); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F11);
        tap_code16(KC_F11);
        tap_code16(KC_F11);
    }
    if(state->count > 3) {
        tap_code16(KC_F11);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_TAP: register_code16(KC_F23); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F11); register_code16(KC_F11);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_TAP: unregister_code16(KC_F23); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F11); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F12);
        tap_code16(KC_F12);
        tap_code16(KC_F12);
    }
    if(state->count > 3) {
        tap_code16(KC_F12);
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_TAP: register_code16(KC_F24); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F12); register_code16(KC_F12);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_TAP: unregister_code16(KC_F24); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F12); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(LSFT(KC_F11))));
        tap_code16(LALT(LCTL(LSFT(KC_F11))));
        tap_code16(LALT(LCTL(LSFT(KC_F11))));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(LSFT(KC_F11))));
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(LSFT(KC_F11)))); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LSFT(KC_F12)))); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LSFT(KC_F10)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(LSFT(KC_F11)))); register_code16(LALT(LCTL(LSFT(KC_F11))));
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_F11)))); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LSFT(KC_F12)))); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_F10)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_F11)))); break;
    }
    dance_state[18].step = 0;
}

void dance_21_finished(tap_dance_state_t *state, void *user_data);
void dance_21_reset(tap_dance_state_t *state, void *user_data);

void dance_21_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
}

void dance_21_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    layer_off(3);
    layer_off(5);
    dance_state[21].step = 0;
}

void dance_22_finished(tap_dance_state_t *state, void *user_data);
void dance_22_reset(tap_dance_state_t *state, void *user_data);

void dance_22_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
}

void dance_22_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    dance_state[22].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [D_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [D_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [D_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [D_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [D_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [D_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [D_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [D_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [D_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [D_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [D_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [D_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [D_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [D_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [D_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [D_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [D_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [D_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [D_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [D_19] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP),
        [D_20] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LGUI(BP_D)), LCTL(LGUI(KC_F4))),
        [D_21] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_21_finished, dance_21_reset),
        [D_22] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_22_finished, dance_22_reset)
};

/* custom */
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        case COMBO_30:
            return layer_state_is(0) || layer_state_is(1);
        default:
            /* all combos on layer 0*/
            return layer_state_is(0);
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    switch (combo->keycode) {
        case BP_LCBR:
        case BP_RCBR:
            return COMBO_TERM_SHORT;
    }

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case COMBO_10:
        case COMBO_11:
        case COMBO_14:
        case COMBO_16:
            return COMBO_TERM_SHORT;
    }
    return COMBO_TERM;
}


void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(BP_M, BP_B)) {
        SEND_STRING("- [ ]");
        //tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(BP_AT)) {
        SEND_STRING("bertrand.castelli@gmail.com");
    } else if (leader_sequence_one_key(BP_D)) {
        // utilisé avec Autohotkey pour insérer la date du jour
        tap_code16(KC_F13);
    }
    
    /* else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }*/
}

/* Gestion des leds */
/*void led_update_ports(led_t led_state) {
    //ML_LED_5(led_state.num_lock);
    ML_LED_6(led_state.caps_lock);
}*/

/*bool led_update_user(led_t led_state) {
    ML_LED_5(led_state.num_lock);
    ML_LED_6(led_state.caps_lock);
    return false;
}*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        ML_LED_6(host_keyboard_led_state().caps_lock);
        ML_LED_5(!host_keyboard_led_state().num_lock);
	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 0:
        ML_LED_1(false);
        ML_LED_2(false);
        ML_LED_3(false);
        ML_LED_4(false);
        break;
    case 1:
        ML_LED_1(false);
        ML_LED_2(false);
        ML_LED_3(true);
        ML_LED_4(false);
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}
