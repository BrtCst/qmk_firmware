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
    NUM,
    NAV,
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
  CMC_EXCLAMATION,
  CMC_KC_5,
  CMC_KC_6
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
  D_PST_RALT,
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
#define BP_AGRV_MOD MT(MOD_RALT, BP_AGRV)
#define BP_Y_MOD MT(MOD_LSFT, BP_Y)
#define BP_X_MOD MT(MOD_LCTL, BP_X)
#define BP_DOT_MOD MT(MOD_LALT, BP_DOT)
#define BP_SPC_LT LT(NAV, KC_SPC)
#define BP_TAB_MOD LT(FN, KC_TAB)
#define BP_BKSP_MOD LT(NAV, KC_BSPC)
#define BP_KC_1_MOD LALT_T(KC_1)
#define BP_KC_2_MOD LCTL_T(KC_2)
#define BP_KC_3_MOD LSFT_T(KC_3)
#define BP_KC_4_MOD RALT_T(KC_4)
#define BP_KC_7_MOD RALT_T(KC_7)
#define BP_KC_8_MOD RCTL_T(KC_8)
#define BP_KC_9_MOD RSFT_T(KC_9)
#define BP_KC_0_MOD LALT_T(KC_0)

void on_dance_custom(tap_dance_state_t *state, void *user_data);

void dance_custom_finished(tap_dance_state_t *state, void *user_data);

void dance_custom_reset(tap_dance_state_t *state, void *user_data);

void dance_unlock(tap_dance_state_t *state, void *user_data);

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode, NONE}), }

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES(tap_keycode, hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){tap_keycode, hold_keycode, tap_keycode, hold_keycode, NONE}), }

static const uint16_t top_row[14]        = {BP_W,            BP_B,            BP_EACU,         BP_P,            BP_O,            BP_EGRV,         QK_LEAD,         /*********/ TD(D_2),         BP_DCIR,         BP_V,            BP_D,            BP_L,            BP_J,            BP_Z};
static const uint16_t mid_row[14]        = {CMC_SLASH,       BP_A_MOD,        BP_U_MOD,        BP_I_MOD,        BP_E_MOD,        BP_COMM,         TD(D_ESC_LOCK),  /*********/ TD(D_3),         BP_C,            BP_T_MOD,        BP_S_MOD,        BP_R_MOD,        BP_N_MOD,        BP_M};
static const uint16_t bot_row[14]        = {KC_LGUI,         BP_AGRV_MOD,     BP_Y_MOD,        BP_X_MOD,        BP_DOT_MOD,      BP_K,                             /*********/                  BP_QUOT,         BP_Q,            BP_G,            BP_H,            BP_F,            BP_CCED};
static const uint16_t thumb_row[6]       = {MO(FN),          SH_T(KC_TAB),    LT(NAV, KC_SPC), /*********/      LT(NUM, KC_BSPC),KC_DEL,          XXXXXXX};

static const uint16_t gaming_top_row[14] = {_______,         _______,         _______,         _______,         _______,         _______,         BP_DCIR,         /*********/ TD(D_4),         _______,         _______,         _______,         _______,         _______,         _______};
static const uint16_t gaming_mid_row[14] = {BP_CCED,         BP_A,            BP_U,            BP_I,            BP_E,            _______,         _______,         /*********/ _______,         _______,         _______,         _______,         _______,         _______,         _______};
static const uint16_t gaming_bot_row[14] = {KC_LSFT,         BP_AGRV,         BP_Y,            BP_X,            BP_DOT,          BP_K,                             /*********/                  _______,         _______,         _______,         _______,         _______,         _______};

static const uint16_t numpad_top_row[14] = {XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         /*********/ QK_LLCK,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         BP_PERC};
//static const uint16_t numpad_mid_row[14] = {KC_NUM,          LALT_T(KC_KP_1), LCTL_T(KC_KP_2), LSFT_T(KC_KP_3), RALT_T(KC_KP_4), KC_KP_5,         XXXXXXX,         /*********/ KC_PPLS,         KC_KP_6,         RALT_T(KC_KP_7), RSFT_T(KC_KP_8), RCTL_T(KC_KP_9), LALT_T(KC_KP_0), BP_EQL};
static const uint16_t numpad_mid_row[14] = {KC_NUM,          BP_KC_1_MOD, LCTL_T(KC_KP_2), LSFT_T(KC_KP_3), RALT_T(KC_KP_4), CMC_KC_5,         XXXXXXX,         /*********/ KC_PPLS,         CMC_KC_6,         RALT_T(KC_KP_7), RSFT_T(KC_KP_8), RCTL_T(KC_KP_9), LALT_T(KC_KP_0), BP_EQL};
static const uint16_t numpad_bot_row[14] = {XXXXXXX,         KC_RALT,         KC_LSFT,         KC_LCTL,         KC_LALT        , XXXXXXX,                          /*********/                  KC_PMNS,         XXXXXXX,         BP_DOT,          BP_COMM,         KC_PSLS,         XXXXXXX};

static const uint16_t arrows_top_row[14] = {XXXXXXX,         XXXXXXX,         KC_MPRV,         TD(D_PLAY_STOP), KC_MNXT,         KC_MUTE,         TG(LOCK),        /*********/ XXXXXXX,         XXXXXXX,         KC_HOME,         KC_UP,           KC_PGUP,         XXXXXXX,         XXXXXXX};
static const uint16_t arrows_mid_row[14] = {XXXXXXX,         LALT_T(KC_BSPC), LCTL_T(KC_DEL),  TD(D_COPY_CUT),  TD(D_PST_RALT),  KC_VOLU,         KC_CAPS,         /*********/ XXXXXXX,         KC_BSPC,         RSFT_T(KC_LEFT), RCTL_T(KC_DOWN), LALT_T(KC_RGHT), RALT_T(KC_DEL),  XXXXXXX};
static const uint16_t arrows_bot_row[14] = {XXXXXXX,         KC_RALT,         KC_LSFT,         KC_LCTL,         KC_LALT,         KC_VOLD,                          /*********/                  XXXXXXX,         KC_END,          XXXXXXX,         KC_PGDN,         XXXXXXX,         XXXXXXX};

static const uint16_t fn_top_row[14]     = {XXXXXXX,         TD(D_F1_F13),    TD(D_F2_F14),    TD(D_F3_F15),    TD(D_F4_F16),    XXXXXXX,         XXXXXXX,         /*********/ XXXXXXX,         DM_REC1,         DM_REC2,         DM_RSTP,         DM_PLY1,         DM_PLY2,         XXXXXXX};
static const uint16_t fn_mid_row[14]     = {XXXXXXX,         TD(D_F5_F17),    TD(D_F6_F18),    TD(D_F7_F19),    TD(D_F8_F20),    XXXXXXX,         XXXXXXX,         /*********/ XXXXXXX,         XXXXXXX,         KC_RALT,         KC_RSFT,         KC_RCTL,         KC_LALT,         XXXXXXX};
static const uint16_t fn_bot_row[14]     = {XXXXXXX,         TD(D_F9_F21),    TD(D_F10_F22),   TD(D_F11_F23),   TD(D_F12_F24),   XXXXXXX,                          /*********/                  XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX};

static const uint16_t config_top_row[14] = {QK_BOOT, DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX};
static const uint16_t config_mid_row[14] = {DB_TOGG, DT_UP,   XXXXXXX, XXXXXXX, XXXXXXX, RM_VALU, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX};
static const uint16_t config_bot_row[14] = {XXXXXXX, DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, RM_VALD,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX};

static const uint16_t lock_top_row[14]   = {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(D_UNLOCK),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX};
static const uint16_t lock_mid_row[14]   = {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX};
static const uint16_t lock_bot_row[14]   = {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX};

#define TAP_DANCE_LIST {\
        [D_0] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(LCTL(KC_TAB), LALT(LCTL(KC_TAB)), LCTL(LSFT(KC_TAB)), LGUI(KC_TAB)),\
        [D_ESC_LOCK] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_ESCAPE, KC_ESCAPE, KC_ESCAPE, LGUI(BP_L)),\
        [D_2] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), GAMING),\
        [D_3] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_INSERT, KC_PSCR, LGUI(LALT(BP_K)), LSFT(KC_PSCR)),\
        [D_4] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), BASE),\
        [D_5] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS_LOCK, KC_ENTER),\
        [D_F1_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F13),\
        [D_F2_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F14),\
        [D_F3_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F15),\
        [D_F4_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F16),\
        [D_F5_F17] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F5, KC_LALT, KC_F17, KC_LALT),\
        [D_F6_F18] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F6, KC_LCTL, KC_F18, KC_LCTL),\
        [D_F7_F19] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F7, KC_LSFT, KC_F19, KC_LSFT),\
        [D_F8_F20] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F8, KC_RALT, KC_F20, KC_RALT),\
        [D_F9_F21] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F9, KC_RALT, KC_F21, KC_RALT),\
        [D_F10_F22] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F10, KC_LSFT, KC_F22, KC_LSFT),\
        [D_F11_F23] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F11, KC_LCTL, KC_F23, KC_LCTL),\
        [D_F12_F24] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F12, KC_LALT, KC_F24, KC_LALT),\
        [D_PLAY_STOP] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP),\
        [D_PREV_NEXT] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK),\
        [D_20] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(LCTL(LGUI(BP_D)), LCTL(LGUI(KC_F4))),\
        [D_COPY_CUT] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(LCTL(BP_C),KC_LSFT, LCTL(BP_X),KC_LSFT),\
        [D_PST_RALT] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(LCTL(BP_V), KC_RALT, LCTL(BP_V), KC_RALT),\
        [D_UNLOCK] = ACTION_TAP_DANCE_FN(dance_unlock)\
}

#endif
