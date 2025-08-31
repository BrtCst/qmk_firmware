void on_dance_custom(tap_dance_state_t *state, void *user_data);

void dance_custom_finished(tap_dance_state_t *state, void *user_data);

void dance_custom_reset(tap_dance_state_t *state, void *user_data);


enum dance_taps {
    NONE,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};
typedef struct {
    uint16_t single_tap;
    uint16_t single_hold;
    uint16_t double_tap;
    uint16_t double_hold;
    int state;
} tap_dance_custom_t;


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
  D_20,
  D_COPY_CUT,
  D_PASTE_LSFT
};

enum layers {
    BASE,
    GAMING,
    NUMPAD,
    FXARROWS,
    ARROWSMACROS
};


static const uint16_t top_row[14] = {XXXXXXX, BP_B, BP_EACU, BP_P, BP_O, BP_EGRV, QK_LEAD, TD(D_2), BP_DCIR, BP_V, BP_D, BP_L, BP_J, BP_Z};
static const uint16_t mid_row[14] = {XXXXXXX, BP_A_MOD, BP_U_MOD, BP_I_MOD, BP_E_MOD, BP_COMM, TD(D_ESC_LOCK), TD(D_3), BP_C, BP_T_MOD, BP_S_MOD, BP_R_MOD, BP_N_MOD, BP_M_MOD};
static const uint16_t bot_row[14] = {CW_TOGG, BP_AGRV, BP_Y, BP_X, BP_DOT, BP_K, BP_QUOT, BP_Q, BP_G, BP_H, BP_F, BP_SLSH};

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){single_tap_keycode, single_hold_keycode, double_tap_keycode, double_hold_keycode, NONE}), }

#define CUSTOM_ACTION_TAP_DANCE_KEYCODES(tap_keycode, hold_keycode) \
    { .fn = {on_dance_custom, dance_custom_finished, dance_custom_reset, NULL}, .user_data = (void *)&((tap_dance_custom_t){tap_keycode, hold_keycode, tap_keycode, hold_keycode, NONE}), }


