#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

typedef struct {
    uint16_t single_tap;
    uint16_t single_hold;
    uint16_t double_tap;
    uint16_t double_hold;
} tap_dance_custom_t;

void on_dance_custom(tap_dance_state_t *state, void *user_data);

void dance_custom_finished(tap_dance_state_t *state, void *user_data);

void dance_custom_reset(tap_dance_state_t *state, void *user_data);

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode}), }

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES(tap_keycode, hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){tap_keycode, hold_keycode, tap_keycode, hold_keycode}), }

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

#endif
