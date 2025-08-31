#include QMK_KEYBOARD_H
#include "version.h"
//#include "keymap_br_abnt2.h"
#include "keymap_bepo.h"
//#include "keymap_contributions.h"
#include "keymap_us_international.h"
// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"

#include "common_brtcst.h"


extern bool is_launching;


// pour les dictionnaires de combos (combos.def)
#include "g/keymap_combo.h"


char chordal_hold_handedness(keypos_t key) {
    //if (key.col == 0 || key.col == MATRIX_COLS - 1) {
    //    return '*';  // Exempt the outer columns.
    //}
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

tap_dance_action_t tap_dance_actions[] = TAP_DANCE_LIST;

const key_override_t *key_overrides[] = {
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_1,KC_1),
  &ko_make_basic(MOD_MASK_SA,KC_KP_1,LSFT(RALT(KC_1))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_1,RALT(KC_1)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_2,KC_2),
  &ko_make_basic(MOD_MASK_SA,KC_KP_2,LSFT(RALT(KC_2))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_2,RALT(KC_2)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_3,KC_3),
  &ko_make_basic(MOD_MASK_SA,KC_KP_3,LSFT(RALT(KC_3))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_3,RALT(KC_3)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_4,KC_4),
  &ko_make_basic(MOD_MASK_SA,KC_KP_4,LSFT(RALT(KC_4))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_4,RALT(KC_4)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_5,KC_5),
  &ko_make_basic(MOD_MASK_SA,KC_KP_5,LSFT(RALT(KC_5))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_5,RALT(KC_5)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_6,KC_6),
  &ko_make_basic(MOD_MASK_SA,KC_KP_6,LSFT(RALT(KC_6))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_6,RALT(KC_6)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_7,KC_7),
  &ko_make_basic(MOD_MASK_SA,KC_KP_7,LSFT(RALT(KC_7))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_7,RALT(KC_7)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_8,KC_8),
  &ko_make_basic(MOD_MASK_SA,KC_KP_8,LSFT(RALT(KC_8))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_8,RALT(KC_8)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_9,KC_9),
  &ko_make_basic(MOD_MASK_SA,KC_KP_9,LSFT(RALT(KC_9))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_9,RALT(KC_9)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_0,KC_0),
  &ko_make_basic(MOD_MASK_SA,KC_KP_0,LSFT(RALT(KC_0))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_0,RALT(KC_0))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    // Left Hand                                                                   // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    top_row[0], top_row[1], top_row[2], top_row[3], top_row[4], top_row[5], top_row[6],              top_row[7], top_row[8], top_row[9], top_row[10], top_row[11], top_row[12], top_row[13],
    mid_row[0], mid_row[1], mid_row[2], mid_row[3], mid_row[4], mid_row[5], mid_row[6],                mid_row[7], mid_row[8], mid_row[9], mid_row[10], mid_row[11], mid_row[12], mid_row[13],
    bot_row[0], bot_row[1], bot_row[2], bot_row[3], bot_row[4], bot_row[5],                                        bot_row[6], bot_row[7], bot_row[8], bot_row[9], bot_row[10], bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    BP_TAB_MOD,           LGUI(BP_SCLN),       TD(D_2),                KC_BSPC,    KC_DEL,     CMC_SLASH,  XXXXXXX, XXXXXXX,
                                                    BP_SPC_LT,  SH_MON,     XXXXXXX,              XXXXXXX,    XXXXXXX,    MO(NUMPAD)
  ),
  [GAMING] = LAYOUT_moonlander( // Gaming layer
    // Left Hand                                                                   // Right Hand
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, BP_AT,                BP_PERC,    BP_AT,      BP_PLUS,    BP_MINS,    BP_SLSH,    BP_ASTR,    BP_EQL,
    BP_W, _______, _______, _______, _______, _______, BP_DCIR,              TD(D_4),  _______, _______, _______, _______, _______, _______,
    BP_CCED, BP_A,    BP_U,    BP_I,    BP_E,     _______, KC_ENTER,                      _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                     _______, _______, _______, _______, _______, _______,
    KC_LCTL,    KC_LGUI,    KC_LALT,    KC_TAB,    _______,                _______,              TD(D_4),                KC_BSPC,    KC_DEL,     CMC_SLASH,  XXXXXXX, KC_RCTL,
                                                    KC_SPC,    _______,    _______,              _______,    _______,    _______
  ),
  [NUMPAD] = LAYOUT_moonlander( // Numpad layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,              LGUI(LALT(BP_B)), XXXXXXX, XXXXXXX    ,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    TD(D_F1_F13),   TD(D_F2_F14),   TD(D_F3_F15),   TD(D_F4_F16), XXXXXXX,  XXXXXXX,              XXXXXXX, KC_NUM, KC_KP_7, KC_KP_8, KC_KP_9, BP_EQL, BP_PERC,
    XXXXXXX,    TD(D_F5_F17),   TD(D_F6_F18),   TD(D_F7_F19),   TD(D_F8_F20), XXXXXXX,  XXXXXXX,              XXXXXXX, KC_PPLS, KC_KP_4,KC_KP_5, KC_KP_6, KC_PAST, XXXXXXX,
    DM_RSTP,    TD(D_F9_F21),   TD(D_F10_F22),  TD(D_F11_F23),  TD(D_F12_F24), XXXXXXX,                                        KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, _______,
    _______,    _______,        _______,        XXXXXXX,        _______,                _______,              _______,                    BP_DLR,     KC_KP_0,    BP_DOT,     BP_COMM,    XXXXXXX,
                                                                MO(CONFIG), _______, XXXXXXX,        _______, _______, _______
  ),
    // QK_DYNAMIC_TAPPING_TERM_PRINT	DT_PRNT	Types the current tapping term, in milliseconds
    // QK_DYNAMIC_TAPPING_TERM_UP	DT_UP	Increases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default)
    // QK_DYNAMIC_TAPPING_TERM_DOWN	DT_DOWN
  [FXARROWS] = LAYOUT_moonlander( // Functions & Arrows layer
    // Left Hand                                                                       // Right Hand
    DT_UP,      DT_DOWN,    DT_PRNT,            XXXXXXX,            XXXXXXX,        XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,            KC_MPRV,        TD(D_PLAY_STOP),   KC_MNXT,    XXXXXXX,              XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_PGUP,    XXXXXXX,    XXXXXXX,
    _______,    KC_RALT,    KC_LALT,         TD(D_COPY_CUT),     TD(D_PASTE_LSFT), KC_VOLU,  XXXXXXX,              XXXXXXX,    KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_DEL,     XXXXXXX,
    KC_CAPS,    XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,        KC_VOLD,                                      XXXXXXX,    KC_END,     XXXXXXX,    KC_PGDN,    XXXXXXX,    _______,
    _______,    _______,    _______,            _______,            _______,                    XXXXXXX,              _______,                _______, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                                    XXXXXXX,        XXXXXXX,   XXXXXXX,              XXXXXXX, TD(D_20), MO(CONFIG)
  ),
  [CONFIG] = LAYOUT_moonlander( // Arrows & Macros layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    QK_BOOT,    XXXXXXX,    DM_REC1,    DM_RSTP,    DM_PLY1,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    DM_REC2,    DM_RSTP,    DM_PLY2,    RGB_VAI,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RGB_VAD,                                      XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,              XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX
  )
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
