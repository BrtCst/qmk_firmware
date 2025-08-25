#include QMK_KEYBOARD_H
#include "version.h"
//#include "keymap_br_abnt2.h"
#include "keymap_bepo.h"
//#include "keymap_contributions.h"
#include "keymap_us_international.h"
// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"
#include "tapdance.h"

#define BP_E_MOD MT(MOD_LSFT, BP_E)
#define BP_T_MOD MT(MOD_RSFT, BP_T)
#define BP_I_MOD MT(MOD_LCTL, BP_I)
#define BP_S_MOD MT(MOD_RCTL, BP_S)
#define BP_U_MOD MT(MOD_LALT, BP_U)
#define BP_R_MOD MT(MOD_LALT, BP_R)
#define BP_A_MOD MT(MOD_LGUI, BP_A)
#define BP_N_MOD MT(MOD_RGUI, BP_N)


// Permissive hold sur les MT incluant Shift, pas sur les autres, pour éviter les faux mods
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { 
    switch (keycode) {
        case BP_E_MOD:
        case BP_T_MOD:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// par rapport à la configuration par défaut, on désactive la touche espace
// https://docs.qmk.fm/tap_hold#flow-tap
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        //case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

extern bool is_launching;

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

enum tap_dance_codes {
  D_0,
  D_1,
  D_2,
  D_3,
  D_4,
  D_5,
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
  D_19,
  D_20
};

enum layers {
    BASE,
    GAMING,
    NUMPAD,
    FXARROWS,
    ARROWSMACROS
};

char chordal_hold_handedness(keypos_t key) {
    //if (key.col == 0 || key.col == MATRIX_COLS - 1) {
    //    return '*';  // Exempt the outer columns.
    //}
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, QK_LEAD,              BP_PERC, BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,
    XXXXXXX,    BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV, XXXXXXX,              XXXXXXX, BP_DCIR, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,
    KC_TAB, BP_A_MOD,    BP_U_MOD,    BP_I_MOD,    BP_E_MOD,    BP_COMM, TD(D_5),              XXXXXXX, BP_C,    BP_T_MOD,    BP_S_MOD,    BP_R_MOD,    BP_N_MOD,    BP_M,
    CW_TOGG, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                   BP_QUOT, BP_Q,    BP_G,    BP_H,    BP_F,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,MO(3),         LGUI(BP_SCLN),       TD(D_2),          KC_BSPC, KC_DEL,  CMC_SLASH, MO(4),   XXXXXXX,
                                        KC_SPC,  SH_MON,  TD(D_1),              TD(D_3), MO(2),   KC_RALT
  ),
  [GAMING] = LAYOUT_moonlander( //gaming
    _______, _______, _______, _______, _______, _______, BP_AT,                _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, BP_DCIR,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_ENTER,             _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, KC_LALT, _______, _______,          _______,              TD(D_4),          _______, _______, _______, _______, _______,
                                        _______, _______, _______,              _______, _______, _______
  ),
  [NUMPAD] = LAYOUT_moonlander( //numpad
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI,              LGUI(LALT(BP_B)), XXXXXXX, KC_NUM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______,  _______, _______, _______, _______, _______, XXXXXXX,              LSFT(LALT(LCTL(KC_F18))), XXXXXXX, BP_PLUS, BP_MINS, BP_SLSH, BP_EQL, BP_PERC,
    _______, _______,   _______, _______, _______, _______, BP_EQL,               LSFT(LALT(LCTL(KC_F17))), KC_PPLS, BP_LPRN,BP_RPRN, BP_AT, KC_PAST, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, CMC_6,   XXXXXXX,                                KC_PMNS, BP_DQUO, BP_LDAQ, BP_RDAQ, KC_PSLS, _______,
    _______, _______, _______, XXXXXXX, _______,          _______,              _______ ,_______, BP_ASTR, BP_DOT, BP_COMM, XXXXXXX,
                                        RALT(LSFT(KC_SPC)),_______, _______,    _______, _______, _______
    ),
    // QK_DYNAMIC_TAPPING_TERM_PRINT	DT_PRNT	Types the current tapping term, in milliseconds
    // QK_DYNAMIC_TAPPING_TERM_UP	DT_UP	Increases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default)
    // QK_DYNAMIC_TAPPING_TERM_DOWN	DT_DOWN
  [FXARROWS] = LAYOUT_moonlander( // Fx & arrows
    DT_UP, DT_DOWN, DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX,KC_VOLU,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, TD(D_6), TD(D_7), TD(D_8), TD(D_9), LCTL(BP_X),KC_VOLD,               XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_PGUP,  XXXXXXX, XXXXXXX,
    _______, TD(D_10), TD(D_11), TD(D_12), TD(D_13), LCTL(BP_C), XXXXXXX,         XXXXXXX, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCTL(KC_RIGHT), XXXXXXX,
    _______, TD(D_14), TD(D_15), TD(D_16), TD(D_17), LCTL(BP_V),                            XXXXXXX, KC_END, XXXXXXX , KC_PGDN, XXXXXXX, _______,
    _______, _______, _______, _______, _______,           XXXXXXX,             _______,          LCTL(KC_BSPC),XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
                                        KC_MPRV, TD(D_19), KC_MNXT,             LGUI(LCTL(KC_LEFT)),TD(D_20), LGUI(LCTL(KC_RIGHT))
    ),
  [ARROWSMACROS] = LAYOUT_moonlander( // arrows & macros
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DM_REC1, DM_RSTP, DM_PLY1, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
    _______, _______, DM_REC2, DM_RSTP, DM_PLY2, _______, _______,              _______, _______, _______, _______, KC_PGUP, _______, _______,
    _______, _______, _______, _______, _______, _______,                                _______, KC_HOME,KC_UP,   KC_PGDN, _______, _______,
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
  GH_ENTER,
  XDOT_W,
  QG_Ç
};

const uint16_t PROGMEM st_combo[] = { BP_T_MOD, BP_S_MOD, COMBO_END}; //short term
const uint16_t PROGMEM oép_combo[] = { BP_O, BP_EACU, BP_P, COMBO_END};
const uint16_t PROGMEM vld_combo[] = { BP_V, BP_L, BP_D, COMBO_END};
const uint16_t PROGMEM po_combo[] = { BP_P, BP_O, COMBO_END};
const uint16_t PROGMEM vd_combo[] = { BP_V, BP_D, COMBO_END};
const uint16_t PROGMEM ép_combo[] = { BP_EACU, BP_P, COMBO_END};
const uint16_t PROGMEM dl_combo[] = { BP_D, BP_L, COMBO_END};
const uint16_t PROGMEM idot_combo[] = { BP_I_MOD, BP_DOT, COMBO_END};
const uint16_t PROGMEM qs_combo[] = { BP_Q, BP_S_MOD, COMBO_END};
const uint16_t PROGMEM ct_combo[] = { BP_C, BP_T_MOD, COMBO_END};
const uint16_t PROGMEM sr_combo[] = { BP_S_MOD, BP_R_MOD, COMBO_END}; //short term
const uint16_t PROGMEM ecomma_combo[] = { BP_E_MOD, BP_COMM, COMBO_END};
const uint16_t PROGMEM tsr_combo[] = { BP_T_MOD, BP_S_MOD, BP_R_MOD, COMBO_END};
const uint16_t PROGMEM ui_combo[] = { BP_U_MOD, BP_I_MOD, COMBO_END}; //short term
const uint16_t PROGMEM pe_combo[] = { BP_P, BP_E_MOD, COMBO_END};
const uint16_t PROGMEM td_combo[] = { BP_T_MOD, BP_D, COMBO_END};
const uint16_t PROGMEM home_up_combo[] = { KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM left_down_combo[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM quote_t_combo[] = { BP_QUOT, BP_T_MOD, COMBO_END};
const uint16_t PROGMEM cv_combo[] = { BP_C, BP_V, COMBO_END};
const uint16_t PROGMEM ek_combo[] = { BP_E_MOD, BP_K, COMBO_END};
const uint16_t PROGMEM sl_combo[] = { BP_S_MOD, BP_L, COMBO_END}; //short term
const uint16_t PROGMEM cts_combo[] = { BP_C, BP_T_MOD, BP_S_MOD, COMBO_END};
const uint16_t PROGMEM uie_combo[] = { BP_U, BP_I_MOD, BP_E_MOD, COMBO_END};
const uint16_t PROGMEM kdot_combo[] = { BP_K, BP_DOT, COMBO_END};
const uint16_t PROGMEM qgh_combo[] = { BP_Q, BP_G, BP_H, COMBO_END};
const uint16_t PROGMEM yx_combo[] = { BP_Y, BP_X, COMBO_END};
const uint16_t PROGMEM gh_combo[] = { BP_G, BP_H, COMBO_END};
const uint16_t PROGMEM xdot_combo[] = { BP_X, BP_DOT, COMBO_END};
const uint16_t PROGMEM qg_combo[] = { BP_Q, BP_G, COMBO_END};

combo_t key_combos[] = {
  [ST_HYPHEN] = COMBO(st_combo, MT(MOD_RSFT|MOD_RCTL, BP_MINS)),
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
  [XDOT_W] = COMBO(xdot_combo, BP_W),
  [QG_Ç] = COMBO(qg_combo, BP_CCED),
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
    return !layer_state_is(GAMING);
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
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}


tap_dance_action_t tap_dance_actions[] = {
        [D_0] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(LCTL(KC_TAB), LALT(LCTL(KC_TAB)), LCTL(LSFT(KC_TAB)), LGUI(KC_TAB)),
        [D_1] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_ESCAPE, KC_ESCAPE, KC_ESCAPE, LGUI(BP_L)),
        [D_2] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), GAMING),
        [D_3] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_INSERT, LGUI(LSFT(BP_S)), LGUI(LALT(BP_K)), KC_PSCR),
        [D_4] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), BASE),
        [D_5] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS_LOCK, KC_ENTER),
        [D_6] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F1, KC_F13),
        [D_7] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F2, KC_F14),
        [D_8] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F3, KC_F15),
        [D_9] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F4, KC_F16),
        [D_10] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F5, KC_F17),
        [D_11] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F6, KC_F18),
        [D_12] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F7, KC_F19),
        [D_13] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F8, KC_F20),
        [D_14] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F9, KC_F21),
        [D_15] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F10, KC_F22),
        [D_16] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F11, KC_F23),
        [D_17] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F12, KC_F24),
        [D_19] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP),
        [D_20] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(LCTL(LGUI(BP_D)), LCTL(LGUI(KC_F4)))
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
    // MOITIÉ GAUCHE
    // LEDs commencent à 0 en haut à gauche
    // les thumbs noirs sont 32, 33, 34
    // le thumb rouge est 35
    // MOITIÉ DROITE
    // LEDs commencent à 36 en haut à droite
    // les thumbs noirs sont 68, 69, 70
    // le thumb rouge est 71
    if (!is_launching) {
        ML_LED_6(host_keyboard_led_state().caps_lock);
        ML_LED_5(!host_keyboard_led_state().num_lock);

        if (host_keyboard_led_state().caps_lock) {
            rgb_matrix_set_color(3, RGB_RED);
            rgb_matrix_set_color(39, RGB_RED);
        }
    }
    switch(get_highest_layer(layer_state)) {
            case GAMING:
                rgb_matrix_set_color(71, RGB_RED);
                break;
            default:
                break;
        }
	return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case BASE:
        ML_LED_1(false);
        ML_LED_2(false);
        ML_LED_3(false);
        ML_LED_4(false);
        break;
    case GAMING:
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
  // Stockage de l'état des modificateurs
  mod_state = get_mods();

  
  switch (keycode) {
// Inversion du modificateur shift pour la ligne des chiffres
    case BP_DQUO:  // "1"
    case BP_LDAQ:  // «2
    case BP_RDAQ:  // 3»
    case BP_LPRN:  // (4
    case BP_RPRN:  // 5)
    case BP_AT:    // @6
    case BP_PLUS:  // +7
    case BP_MINS:  // -8
    case BP_SLSH:  // /9
    case BP_ASTR:  // *0
      if (layer_state_is(NUMPAD)) {
        if (record->event.pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
            // Si shift est pressé, l'enlever et envoyer le keycode normal
            del_mods(MOD_MASK_SHIFT);
            register_code(keycode);
            set_mods(mod_state);
          } else {
            // Si shift n'est pas pressé, l'ajouter et envoyer le keycode
            add_mods(MOD_MASK_SHIFT);
            register_code(keycode);
            del_mods(MOD_MASK_SHIFT);
          }
          return false;
        } else {
          unregister_code(keycode);
          return false;
        }
      }
      break;
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
        } else if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          set_mods(MOD_RALT);
          register_code(BP_AGRV);
          del_mods(MOD_RALT);
          agrav_registered = true;
        } else if (mod_state == 0 ) {
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
    /*case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;*/
  }
  return true;
}
