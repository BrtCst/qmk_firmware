#include "tapdance.h"

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
    switch (dance_step(state)) {
        case SINGLE_TAP: register_code16(dance->single_tap); break;
        case SINGLE_HOLD: register_code16(dance->single_hold); break;
        case DOUBLE_TAP: register_code16(dance->double_tap); break;
        case DOUBLE_HOLD: register_code16(dance->double_hold); break;
        case DOUBLE_SINGLE_TAP: tap_code16(dance->single_tap); register_code16(dance->single_tap);
    }
}

void dance_custom_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_custom_t *dance = (tap_dance_custom_t *)user_data;
    wait_ms(10);
    switch (dance_step(state)) {
        case SINGLE_TAP: unregister_code16(dance->single_tap); break;
        case SINGLE_HOLD: unregister_code16(dance->single_hold); break;
        case DOUBLE_TAP: unregister_code16(dance->double_tap); break;
        case DOUBLE_HOLD: unregister_code16(dance->double_hold); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(dance->single_tap); break;
    }
}