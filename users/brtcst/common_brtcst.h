#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#include "keymap_bepo.h"

typedef struct {
    uint16_t single_tap;
    uint16_t single_hold;
    uint16_t double_tap;
    uint16_t double_hold;
    int state;
} tap_dance_custom_t;

enum layers {
    BASE = 0,
    GAMING,
    NUMPAD,
    ARROWS,
    FN,
    CONFIG,
    LOCK
};

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  CMC_CHEVRON_L,
  CMC_CHEVRON_R,
  CMC_COLON,
  BP_LSPO,
  BP_RSPC,
  CMC_END_RETURN,
  CMC_SLASH,
  CMC_CCED,
  CMC_COPY,
  CMC_PASTE,
  CMC_QUESTION,
  CMC_EXCLAMATION
};

enum dance_taps {
    NONE = 0,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

enum tap_dance_codes {
  D_0 = 0,
  D_ESC_LOCK,
  D_2,
  D_3,
  D_4,
  D_5,
  D_F1_F13,
  D_F2_F14,
  D_F3_F15,
  D_F4_F16,
  D_F5_F17,
  D_F6_F18,
  D_F7_F19,
  D_F8_F20,
  D_F9_F21,
  D_F10_F22,
  D_F11_F23,
  D_F12_F24,
  D_PLAY_STOP,
  D_PREV_NEXT,
  D_20,
  D_COPY_CUT,
  D_PASTE_LSFT,
  D_UNLOCK
};

// on peut aussi écrire LSFT_T(BP_E)
#define BP_E_MOD MT(MOD_RALT, BP_E)
#define BP_T_MOD MT(MOD_RALT, BP_T)
#define BP_I_MOD MT(MOD_LSFT, BP_I)
#define BP_S_MOD MT(MOD_RSFT, BP_S)
#define BP_U_MOD MT(MOD_LCTL, BP_U)
#define BP_R_MOD MT(MOD_RCTL, BP_R)
#define BP_A_MOD MT(MOD_LALT, BP_A)
#define BP_N_MOD MT(MOD_RALT, BP_N)
#define BP_M_MOD MT(MOD_RGUI, BP_M)
#define BP_SPC_LT LT(ARROWS, KC_SPC)
#define BP_TAB_MOD LT(FN, KC_TAB)

void on_dance_custom(tap_dance_state_t *state, void *user_data);

void dance_custom_finished(tap_dance_state_t *state, void *user_data);

void dance_custom_reset(tap_dance_state_t *state, void *user_data);

void dance_unlock(tap_dance_state_t *state, void *user_data);

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode, NONE}), }

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES(tap_keycode, hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){tap_keycode, hold_keycode, tap_keycode, hold_keycode, NONE}), }

static const uint16_t top_row[14] = {XXXXXXX, BP_B, BP_EACU, BP_P, BP_O, BP_EGRV, QK_LEAD, TD(D_2), BP_DCIR, BP_V, BP_D, BP_L, BP_J, BP_Z};
static const uint16_t mid_row[14] = {CMC_SLASH, BP_A_MOD, BP_U_MOD, BP_I_MOD, BP_E_MOD, BP_COMM, TD(D_ESC_LOCK), TD(D_3), BP_C, BP_T_MOD, BP_S_MOD, BP_R_MOD, BP_N_MOD, BP_M};
static const uint16_t bot_row[14] = {SH_T(BP_W), BP_AGRV, BP_Y, BP_X, BP_DOT, BP_K, BP_QUOT, BP_Q, BP_G, BP_H, BP_F, BP_CCED};
static const uint16_t thumb_row[6] = {KC_LGUI, BP_TAB_MOD,  BP_SPC_LT, LT(NUMPAD, KC_BSPC), KC_DEL, XXXXXXX};

#define TAP_DANCE_LIST {\
        [D_0] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(LCTL(KC_TAB), LALT(LCTL(KC_TAB)), LCTL(LSFT(KC_TAB)), LGUI(KC_TAB)),\
        [D_ESC_LOCK] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_ESCAPE, KC_ESCAPE, KC_ESCAPE, LGUI(BP_L)),\
        [D_2] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), GAMING),\
        [D_3] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_INSERT, LGUI(LSFT(BP_S)), LGUI(LALT(BP_K)), KC_PSCR),\
        [D_4] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), BASE),\
        [D_5] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS_LOCK, KC_ENTER),\
        [D_F1_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F13),\
        [D_F2_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F14),\
        [D_F3_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F15),\
        [D_F4_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F16),\
        [D_F5_F17] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F17),\
        [D_F6_F18] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F18),\
        [D_F7_F19] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F19),\
        [D_F8_F20] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F20),\
        [D_F9_F21] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F21),\
        [D_F10_F22] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F22),\
        [D_F11_F23] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F23),\
        [D_F12_F24] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_F24),\
        [D_PLAY_STOP] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP),\
        [D_PREV_NEXT] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),\
        [D_20] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(LCTL(LGUI(BP_D)), LCTL(LGUI(KC_F4))),\
        [D_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(LCTL(BP_C), LCTL(BP_X)),\
        [D_PASTE_LSFT] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(LCTL(BP_V), KC_LSFT),\
        [D_UNLOCK] = ACTION_TAP_DANCE_FN(dance_unlock)\
}

#endif
