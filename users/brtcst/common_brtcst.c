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

// Le flow-tap est sur les touches qwerty par défaut, il faut l’adapter au bépo
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
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

        case BP_DCIR:
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
        case BP_DOT:
        case BP_COMM:
            return true;
    }
    return false;
}

// Permissive hold sur les MT incluant Shift, pas sur les autres, pour éviter les faux mods et accélérer l’affichage des caractères
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    /*switch (keycode) {
        case BP_E_MOD:
        case BP_T_MOD:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }*/
    return true;
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

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    dprint("taggle");
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(keycode));
  if ((mod & MOD_LSFT) != 0) {
    return true;
  }
  return false;
}
