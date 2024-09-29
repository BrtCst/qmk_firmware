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
  CMC_6,
  BP_LSPO,
  BP_RSPC,
  CMC_END_RETURN,
  CMC_SLASH
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

static tap dance_state[5];

enum tap_dance_codes {
  D_ESCAPE_LOCK,
  D_ALTSP_LAYERGAMING,
  D_INSER_PRTSCR,
  D_MEDIA_PLAY_STOP,
  D_END_HOME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, QK_LEAD,              BP_PERC, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,
    TD(D_END_HOME), BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV, XXXXXXX,             BP_W,    BP_DCIR, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
    KC_CAPS, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, XXXXXXX,              BP_CCED, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                   BP_QUOT, BP_Q,    BP_G,    BP_H,    BP_F,    KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_TAB, MO(3),         LGUI(BP_SCLN),       TD(D_ALTSP_LAYERGAMING),          KC_BSPC, KC_DEL,  CMC_SLASH, MO(4),   KC_RCTL,
                                        KC_SPC,  SH_MON,  TD(D_ESCAPE_LOCK),              TD(D_INSER_PRTSCR), MO(2),   KC_RALT
  ),
  [1] = LAYOUT_moonlander( //gaming
    _______, _______, _______, _______, _______, _______, BP_AT,                _______, _______, _______, _______, _______, _______, _______,
    KC_TAB,  _______, _______, _______, _______, _______, BP_DCIR,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_ENTER,             _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, KC_LALT, _______, _______,          _______,              TD(D_ALTSP_LAYERGAMING),          _______, _______, _______, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
  ),
  [2] = LAYOUT_moonlander( //numpad
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_VAI,              LGUI(LALT(BP_B)), XXXXXXX, KC_NUM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, XXXXXXX,              LSFT(LALT(LCTL(KC_F18))), XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
    BP_PERC, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,               LSFT(LALT(LCTL(KC_F17))), KC_PPLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, CMC_6,   XXXXXXX,                                KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,              _______ ,_______, KC_KP_0, BP_DOT, BP_COMM, XXXXXXX,
                                        RALT(LSFT(KC_SPC)),_______, _______,    _______, _______, _______
    ),
  [3] = LAYOUT_moonlander( // Fx & arrows
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_VOLU,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_F1, KC_F2, KC_F3, KC_F4, XXXXXXX,KC_VOLD,               XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_PGUP,  XXXXXXX, XXXXXXX,
    _______, KC_F5, KC_F6, KC_F7, KC_F8, XXXXXXX, XXXXXXX,         XXXXXXX, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), XXXXXXX,
    _______, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,                            XXXXXXX, KC_END, XXXXXXX , KC_PGDN, XXXXXXX, _______,
    _______, _______, _______, _______, _______,           XXXXXXX,             LGUI(LCTL(KC_F4)),          LCTL(KC_BSPC),XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
                                        KC_MPRV, TD(D_MEDIA_PLAY_STOP), KC_MNXT,             LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_D)), LGUI(LCTL(KC_RIGHT))
    ),
  [4] = LAYOUT_moonlander( // arrows & macros
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DM_REC1, DM_RSTP, DM_PLY1, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DM_REC2, DM_RSTP, DM_PLY2, _______, _______,              _______, _______, _______, _______, KC_PGUP, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, TD(D_END_HOME),KC_UP,   KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______,          _______,              _______,          KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
    )
};

enum combo_events {
  ST_HYPHEN,
  OÉP_LBRACKET,
  VLD_RBRACKET,
  PO_LPARENTHESIS,
  VD_LPARENTHESIS,
  ÉP_LCURL,
  DL_RCURL,
  IDOT_CMC_0,
  QS_CMC_1,
  CT_PLUS,
  SR_ASTERISK,
  ECOMMA_SEMICOLON,
  TSR_EQUALS,
  UI_HASSH,
  PE_LCHEVRON,
  TD_RCHEVRON,
  HOME_UO_PGUP,
  LEFT_DOWN_PGDN,
  QUOTE_T_ALTCOMMA,
  CV_DOUBLEQUOTE,
  EK_BACKTICK,
  SL_AROBASE,
  CTS_DEMICADRATIN,
  UIE_DOLLAR,
  KDOT_COLON,
  QGH_END_RETURN,
  YX_ENTER,
  GH_ENTER
};

const uint16_t PROGMEM st_combo[] = { BP_T, BP_S, COMBO_END}; //short term
const uint16_t PROGMEM oép_combo[] = { BP_O, BP_EACU, BP_P, COMBO_END};
const uint16_t PROGMEM vld_combo[] = { BP_V, BP_L, BP_D, COMBO_END};
const uint16_t PROGMEM po_combo[] = { BP_P, BP_O, COMBO_END};
const uint16_t PROGMEM vd_combo[] = { BP_V, BP_D, COMBO_END};
const uint16_t PROGMEM ép_combo[] = { BP_EACU, BP_P, COMBO_END};
const uint16_t PROGMEM dl_combo[] = { BP_D, BP_L, COMBO_END};
const uint16_t PROGMEM idot_combo[] = { BP_I, BP_DOT, COMBO_END};
const uint16_t PROGMEM qs_combo[] = { BP_Q, BP_S, COMBO_END};
const uint16_t PROGMEM ct_combo[] = { BP_C, BP_T, COMBO_END};
const uint16_t PROGMEM sr_combo[] = { BP_S, BP_R, COMBO_END}; //short term
const uint16_t PROGMEM ecomma_combo[] = { BP_E, BP_COMM, COMBO_END};
const uint16_t PROGMEM tsr_combo[] = { BP_T, BP_S, BP_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = { BP_U, BP_I, COMBO_END}; //short term
const uint16_t PROGMEM pe_combo[] = { BP_P, BP_E, COMBO_END};
const uint16_t PROGMEM td_combo[] = { BP_T, BP_D, COMBO_END};
const uint16_t PROGMEM home_up_combo[] = { KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM left_down_combo[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM quote_t_combo[] = { BP_QUOT, BP_T, COMBO_END};
const uint16_t PROGMEM cv_combo[] = { BP_C, BP_V, COMBO_END};
const uint16_t PROGMEM ek_combo[] = { BP_E, BP_K, COMBO_END};
const uint16_t PROGMEM sl_combo[] = { BP_S, BP_L, COMBO_END}; //short term
const uint16_t PROGMEM cts_combo[] = { BP_C, BP_T, BP_S, COMBO_END};
const uint16_t PROGMEM uie_combo[] = { BP_U, BP_I, BP_E, COMBO_END};
const uint16_t PROGMEM kdot_combo[] = { BP_K, BP_DOT, COMBO_END};
const uint16_t PROGMEM qgh_combo[] = { BP_Q, BP_G, BP_H, COMBO_END};
const uint16_t PROGMEM yx_combo[] = { BP_Y, BP_X, COMBO_END};
const uint16_t PROGMEM gh_combo[] = { BP_G, BP_H, COMBO_END};

combo_t key_combos[] = {
  [ST_HYPHEN] = COMBO(st_combo, BP_MINS),
  [OÉP_LBRACKET] = COMBO(oép_combo, BP_LBRC),
  [VLD_RBRACKET] = COMBO(vld_combo, BP_RBRC),
  [PO_LPARENTHESIS] = COMBO(po_combo, BP_LPRN),
  [VD_LPARENTHESIS] = COMBO(vd_combo, BP_RPRN),
  [ÉP_LCURL] = COMBO(ép_combo, BP_LCBR),
  [DL_RCURL] = COMBO(dl_combo, BP_RCBR),
  [IDOT_CMC_0] = COMBO(idot_combo, CMC_0),
  [QS_CMC_1] = COMBO(qs_combo, CMC_1),
  [CT_PLUS] = COMBO(ct_combo, BP_PLUS),
  [SR_ASTERISK] = COMBO(sr_combo, BP_ASTR),
  [ECOMMA_SEMICOLON] = COMBO(ecomma_combo, BP_SCLN),
  [TSR_EQUALS] = COMBO(tsr_combo, BP_EQL),
  [UI_HASSH] = COMBO(ui_combo, BP_HASH),
  [PE_LCHEVRON] = COMBO(pe_combo, BP_LABK),
  [TD_RCHEVRON] = COMBO(td_combo, BP_RABK),
  [HOME_UO_PGUP] = COMBO(home_up_combo, KC_PGUP),
  [LEFT_DOWN_PGDN] = COMBO(left_down_combo, KC_PGDN),
  [QUOTE_T_ALTCOMMA] = COMBO(quote_t_combo, RALT(BP_COMM)),
  [CV_DOUBLEQUOTE] = COMBO(cv_combo, BP_DQUO),
  [EK_BACKTICK] = COMBO(ek_combo, BP_GRV),
  [SL_AROBASE] = COMBO(sl_combo, BP_AT),
  [CTS_DEMICADRATIN] = COMBO(cts_combo, BP_NDSH),
  [UIE_DOLLAR] = COMBO(uie_combo, BP_DLR),
  [KDOT_COLON] = COMBO(kdot_combo, BP_COLN),
  [QGH_END_RETURN] = COMBO(qgh_combo, CMC_END_RETURN),
  [YX_ENTER] = COMBO(yx_combo, KC_ENTER),
  [GH_ENTER] = COMBO(gh_combo, KC_ENTER),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /*switch (combo_index) {
        case COMBO_30:
            return layer_state_is(0) || layer_state_is(1);
        default:
            // all combos on layer 0
            return layer_state_is(0);
    }*/
    // no combos on layer 1 (gaming)
    return !layer_state_is(1);
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    /*switch (combo->keycode) {
        case BP_LCBR:
        case BP_RCBR:
            return COMBO_TERM_SHORT;
    }*/

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case ST_HYPHEN:
        case SR_ASTERISK:
        case UI_HASSH:
        case SL_AROBASE:
            return COMBO_TERM_SHORT;
    }
    return COMBO_TERM;
}

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
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_BRTCST_CUSTOM);
  //led_update_ports(host_keyboard_led_state());
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
};

void on_dance_escape_lock(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_escape_lock_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[D_ESCAPE_LOCK].step = dance_step(state);
    switch (dance_state[D_ESCAPE_LOCK].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(LGUI(BP_L)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_escape_lock_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_ESCAPE_LOCK].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(BP_L)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[D_ESCAPE_LOCK].step = 0;
}

void on_dance_inser_prtscr(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
        tap_code16(KC_INSERT);
    }
    if(state->count > 3) {
        tap_code16(KC_INSERT);
    }
}

void dance_inser_prtscr_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[D_INSER_PRTSCR].step = dance_step(state);
    switch (dance_state[D_INSER_PRTSCR].step) {
        case SINGLE_TAP: register_code16(KC_INSERT); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(BP_S))); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(BP_A))); break;
        case DOUBLE_HOLD: register_code16(KC_PSCR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_INSERT); register_code16(KC_INSERT);
    }
}

void dance_inser_prtscr_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[D_INSER_PRTSCR].step) {
        case SINGLE_TAP: unregister_code16(KC_INSERT); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(BP_S))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(BP_A))); break;
        case DOUBLE_HOLD: unregister_code16(KC_PSCR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_INSERT); break;
    }
    dance_state[D_INSER_PRTSCR].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [D_ESCAPE_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_escape_lock, dance_escape_lock_finished, dance_escape_lock_reset),
        [D_ALTSP_LAYERGAMING] = ACTION_TAP_DANCE_LAYER_TOGGLE(LALT(KC_SPACE), 1),
        [D_INSER_PRTSCR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_inser_prtscr, dance_inser_prtscr_finished, dance_inser_prtscr_reset),
        [D_MEDIA_PLAY_STOP] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP),
        [D_END_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_HOME)
};

/* custom */



void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(BP_M, BP_B)) {
        SEND_STRING("- [ ]");
        //tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(BP_AT)) {
        SEND_STRING("@brtcst.net");
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

// pour stockage de l’état des modificateurs (shift, alt, ctrl…)
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMC_0:
      if (record->event.pressed) {
        // '« '
        SEND_STRING(SS_TAP(X_2) SS_DELAY(5) SS_LSFT(SS_RALT(SS_TAP(X_SPACE))));
      }
      break;
    case CMC_1:
      if (record->event.pressed) {
        // ' »'
        SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_TAP(X_3));
      }
      break;
    case CMC_6:
      // ' :'
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_LSFT(SS_TAP(X_V)));
      }
      break;
    case CMC_END_RETURN:
      // END puis enter
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
      }
      break;
    case CMC_SLASH:
      // / si pas de modifier
      // \ si altGr
      static bool agrav_registered;
      static bool slash_registered;
      if (record->event.pressed) {
        mod_state = get_mods();
        if (mod_state == MOD_BIT(KC_RALT)) {
          // le backslash est sur altgr+à, on s’évite de désactiver un modifier altGr inutilement
          // puisqu’il est activé ici
          register_code(BP_AGRV);
          agrav_registered = true;
        } else if (mod_state == 0) {
          register_code(BP_SLSH);
          slash_registered = true;
        }
        return false;
      } else {
        if (agrav_registered) {
          unregister_code(BP_AGRV);
          agrav_registered = false;
        }
        if (slash_registered) {
          unregister_code(BP_SLSH);
          slash_registered = false;
        }
      }
      break;
    case TD(D_MEDIA_PLAY_STOP):
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
    case TD(D_END_HOME):
      // END si tap, HOME si double tap
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
