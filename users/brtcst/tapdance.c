#include "tapdance.h"
#include "keymap_bepo.h"


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
        
        // Caractères spéciaux utiles qui ne désactivent pas Caps Word
        case KC_BACKSPACE: // Pour corriger
        case KC_DELETE:    // Pour corriger
        
        // Modificateurs autorisés (ne désactivent pas Caps Word)
        case KC_LSFT:
        case KC_RSFT:
            return true;
    }
    
    // Par défaut, on continue Caps Word
    return true;
}