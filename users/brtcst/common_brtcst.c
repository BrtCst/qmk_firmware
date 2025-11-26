#include "common_brtcst.h"
#include "keymap_bepo.h"

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {return SINGLE_HOLD;}
        else return SINGLE_TAP;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_custom(tap_dance_state_t *state, void *user_data) {
    tap_dance_custom_t *dance = (tap_dance_custom_t *)user_data;
    if(state->count == 3 || state->count > 3) {
        tap_code16(dance->single_tap);
        tap_code16(dance->single_tap);
        tap_code16(dance->single_tap);
    }
}

void dance_custom_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_custom_t *dance = (tap_dance_custom_t *)user_data;
    dance->state = dance_step(state);
    switch (dance->state) {
        case SINGLE_TAP: register_code16(dance->single_tap); break;
        case SINGLE_HOLD: register_code16(dance->single_hold); break;
        case DOUBLE_TAP: register_code16(dance->double_tap); break;
        case DOUBLE_HOLD: register_code16(dance->double_hold); break;
        case DOUBLE_SINGLE_TAP: tap_code16(dance->single_tap); register_code16(dance->single_tap);
    }
}

void dance_custom_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_custom_t *dance = (tap_dance_custom_t *)user_data;
    //wait_ms(10);
    switch (dance->state) {
        case SINGLE_TAP: unregister_code16(dance->single_tap); break;
        case SINGLE_HOLD: unregister_code16(dance->single_hold); break;
        case DOUBLE_TAP: unregister_code16(dance->double_tap); break;
        case DOUBLE_HOLD: unregister_code16(dance->double_hold); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(dance->single_tap); break;
    }
    dance->state = NONE;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Lettres en BÉPO (basées sur leur position physique QWERTY)
        
        // Rangée du haut (BÉPO: bépoè)
        case BP_B:     // b en BÉPO
        case BP_EACU:     // é en BÉPO  
        case BP_P:     // p en BÉPO
        case BP_O:     // o en BÉPO
        case BP_EGRV: // è en BÉPO
        
        // Rangée du milieu (BÉPO: auie,)
        case BP_A:     // a en BÉPO
        case BP_U:     // u en BÉPO
        case BP_I:     // i en BÉPO
        case BP_E:     // e en BÉPO
            
        // Rangée du bas (BÉPO: àyx.k)
        case BP_AGRV: // à en BÉPO
        case BP_Y:         // y en BÉPO
        case BP_X:         // x en BÉPO
        case BP_K:         // k en BÉPO
        
        // Autres lettres importantes en BÉPO
        case BP_W:
        case BP_CCED:

        
        case BP_V:
        case BP_D:
        case BP_L:
        case BP_J:
        case BP_Z:

        case BP_C:
        case BP_T:
        case BP_S:
        case BP_R:
        case BP_N:
        case BP_M:

        case BP_Q:
        case BP_G:
        case BP_H:
        case BP_F:
        add_weak_mods(MOD_BIT(KC_LSFT));
        return true;
        
        // Caractères spéciaux utiles qui ne désactivent pas Caps Word
        case BP_DCIR:
        case KC_BACKSPACE: // Pour corriger
        case KC_DELETE:    // Pour corriger
        case KC_KP_0: //numpad
        case KC_KP_1:
        case KC_KP_2:
        case KC_KP_3:
        case KC_KP_4:
        case KC_KP_5:
        case KC_KP_6:
        case KC_KP_7:
        case KC_KP_8:
        case KC_KP_9:
        case KC_KP_MINUS: //tirets
        case BP_MINS:
        
        // Modificateurs autorisés (ne désactivent pas Caps Word)
        case KC_LSFT:
        case KC_RSFT:
        case KC_RALT: // Autoriser RALT seul
            return true;

        case KC_SPC:
            // Autoriser seulement KC_SPC avec RALT
            if (get_mods() & MOD_BIT(KC_RALT)) {
                return true;
            }
            return false;
    }
    
    return false;
}

bool is_flow_tap_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
      case BP_E:
      case BP_T:
      case BP_E_MOD:
      case BP_T_MOD:
      case BP_A:
      case BP_U:
      case BP_A_MOD:
      case BP_U_MOD:
      case BP_I:
      case BP_S:
      case BP_I_MOD:
      case BP_S_MOD:
      case BP_R:
      case BP_N:
      case BP_R_MOD:
      case BP_N_MOD:
      
      case KC_SPC:
      
      case BP_B:
      case BP_EACU:
      case BP_P:
      case BP_O:
      case BP_EGRV:
      case BP_COMM:
      case BP_DCIR:
      case BP_V:
      case BP_D:
      case BP_L:
      case BP_J:
      case BP_Z:

      case BP_C:

      case BP_M:
          
      // Rangée du bas
      case BP_AGRV:
      case BP_Y:
      case BP_X:
      //case BP_DOT:
      case BP_K:
      case BP_Q:
      case BP_G:
      case BP_H:
      case BP_F:

      case BP_W:
      case BP_CCED:
          return true;
    }
    return false;
}

// Le flow-tap est sur les touches qwerty par défaut, il faut l’adapter au bépo
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
    switch (get_tap_keycode(keycode)) {
      // short term pour shift et ralt
      case BP_I:
      case BP_S:
      case BP_I_MOD:
      case BP_S_MOD:
      case BP_E:
      case BP_T:
      case BP_E_MOD:
      case BP_T_MOD:
        return FLOW_TAP_TERM_SHORT;
      break;
      case KC_SPC:
      case BP_SPC_LT:
        return 0;
      break;
      default:
            return FLOW_TAP_TERM;
    }
  }
    return 0;
}

// Permissive hold
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      // pas de permissive pour ctrl et alt, pour éviter les raccourcis clavier intempestifs
        case BP_U_MOD:
        case BP_R_MOD:
        case BP_A_MOD:
        case BP_N_MOD:
            return false;
        default:
            return true;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (get_highest_layer(layer_state)) {
        case BASE:
            // on renvoie vers la règle par défaut
            return get_chordal_hold_default(tap_hold_record, other_record);
        default:
            // on désactive pour les autres couche, pour éviter des déclenchements
            // sur des appuis de deux touche mod-tap du même côté
            // ex : altgr + shift du même côté du clavier sur la couche numpad
            return false;
    }
}

void dance_unlock(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 3) {
        layer_invert(LOCK);
    }
 }

// pour stockage de l’état des modificateurs (shift, alt, ctrl…)
uint8_t mod_state;

// Mutualisation de la gestion des frappes clavier custom
void process_record_brtcst(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  #endif 
  // Stockage de l'état des modificateurs
  mod_state = get_mods();
  
  switch (keycode) {
    case CMC_CHEVRON_L:
      if (record->event.pressed) {
        // '« '
        SEND_STRING(SS_TAP(X_2) SS_DELAY(5) SS_LSFT(SS_RALT(SS_TAP(X_SPACE))));
      }
      break;
    case CMC_CHEVRON_R:
      if (record->event.pressed) {
        // ' »'
        SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_TAP(X_3));
      }
      break;
    case CMC_COLON:
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
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(mod_state);
          register_code16(RALT(BP_AGRV));
          set_mods(mod_state);
        } else {
          register_code16(BP_SLSH);
        }
      } else {
        if (mod_state & MOD_MASK_SHIFT) {
          unregister_code16(RALT(BP_AGRV));
        } else {
          unregister_code16(BP_SLSH);
        }
      }
      break;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BP_E_MOD:
        case BP_T_MOD:
        case BP_I_MOD:
        case BP_S_MOD:
          return TAPPING_TERM;
        case BP_U_MOD:
        case BP_R_MOD:
        case BP_A_MOD:
        case BP_N_MOD:
            return TAPPING_TERM;
        case BP_TAB_MOD:
        case BP_SPC_LT:
        case LT(NUMPAD, KC_BSPC):
            return TAPPING_TERM_SHORT;
        default:
            return TAPPING_TERM;
    }
}
