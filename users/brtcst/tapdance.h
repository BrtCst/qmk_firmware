#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

typedef struct {
    uint16_t single_tap;
    uint16_t single_hold;
    uint16_t double_tap;
    uint16_t double_hold;
    int state;
} tap_dance_custom_t;

enum layers {
    BASE,
    GAMING,
    NUMPAD,
    FXARROWS,
    ARROWSMACROS
};

enum {
    NONE,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

#define BP_E_MOD MT(MOD_LSFT, BP_E)
#define BP_T_MOD MT(MOD_RSFT, BP_T)
#define BP_I_MOD MT(MOD_LCTL, BP_I)
#define BP_S_MOD MT(MOD_RCTL, BP_S)
#define BP_U_MOD MT(MOD_LALT, BP_U)
#define BP_R_MOD MT(MOD_LALT, BP_R)
#define BP_A_MOD MT(MOD_RALT, BP_A)
#define BP_N_MOD MT(MOD_RALT, BP_N)
#define BP_TAB_MOD MT(MOD_LGUI, KC_TAB)
#define BP_M_MOD MT(MOD_RGUI, BP_M)
#define BP_SPC_LT LT(FXARROWS, KC_SPC)

void on_dance_custom(tap_dance_state_t *state, void *user_data);

void dance_custom_finished(tap_dance_state_t *state, void *user_data);

void dance_custom_reset(tap_dance_state_t *state, void *user_data);

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode, NONE}), }

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES(tap_keycode, hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){tap_keycode, hold_keycode, tap_keycode, hold_keycode, NONE}), }


#endif
