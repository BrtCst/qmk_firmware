#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_bepo.h"

// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"

#include "tapdance.h"
enum layers {
    BASE,
    GAMING,
    NUMPAD,
    FXARROWS,
    ARROWSMACROS
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

/*
const key_override_t next_track_override = 
	ko_make_with_layers_negmods_and_options(
   		MOD_MASK_CTRL,       // Trigger modifiers: ctrl
    	KC_MPLY,             // Trigger key: play/pause
    	KC_MNXT,             // Replacement key
    	~0,                  // Activate on all layers
    	MOD_MASK_SA,         // Do not activate when shift or alt are pressed
    	ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting ctrl
      */
     
/*const key_override_t number_1_override = 
	ko_make_with_layers_negmods_and_options(
   		MOD_MASK_SHIFT,       // Trigger modifiers
    	KC_KP_1,             // Trigger key
    	KC_1,             // Replacement key
    	NUMPAD,                  // Activate on all layers
    	MOD_MASK_CTRL,         // Do not activate when *** are pressed
    	ko_option_no_reregister_trigger);*/

      const key_override_t number_1_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_1,KC_1);
      const key_override_t number_1b_override =ko_make_basic(MOD_MASK_SA,KC_KP_1,LSFT(RALT(KC_1)));
      const key_override_t number_1c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_1,RALT(KC_1));
      const key_override_t number_2_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_2,KC_2);
      const key_override_t number_2b_override =ko_make_basic(MOD_MASK_SA,KC_KP_2,LSFT(RALT(KC_2)));
      const key_override_t number_2c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_2,RALT(KC_2));
      const key_override_t number_3_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_3,KC_3);
      const key_override_t number_3b_override =ko_make_basic(MOD_MASK_SA,KC_KP_3,LSFT(RALT(KC_3)));
      const key_override_t number_3c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_3,RALT(KC_3));
      const key_override_t number_4_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_4,KC_4);
      const key_override_t number_4b_override =ko_make_basic(MOD_MASK_SA,KC_KP_4,LSFT(RALT(KC_4)));
      const key_override_t number_4c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_4,RALT(KC_4));
      const key_override_t number_5_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_5,KC_5);
      const key_override_t number_5b_override =ko_make_basic(MOD_MASK_SA,KC_KP_5,LSFT(RALT(KC_5)));
      const key_override_t number_5c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_5,RALT(KC_5));
      const key_override_t number_6_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_6,KC_6);
      const key_override_t number_6b_override =ko_make_basic(MOD_MASK_SA,KC_KP_6,LSFT(RALT(KC_6)));
      const key_override_t number_6c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_6,RALT(KC_6));
      const key_override_t number_7_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_7,KC_7);
      const key_override_t number_7b_override =ko_make_basic(MOD_MASK_SA,KC_KP_7,LSFT(RALT(KC_7)));
      const key_override_t number_7c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_7,RALT(KC_7));
      const key_override_t number_8_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_8,KC_8);
      const key_override_t number_8b_override =ko_make_basic(MOD_MASK_SA,KC_KP_8,LSFT(RALT(KC_8)));
      const key_override_t number_8c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_8,RALT(KC_8));
      const key_override_t number_9_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_9,KC_9);
      const key_override_t number_9b_override =ko_make_basic(MOD_MASK_SA,KC_KP_9,LSFT(RALT(KC_9)));
      const key_override_t number_9c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_9,RALT(KC_9));
      const key_override_t number_0_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_0,KC_0);
      const key_override_t number_0b_override =ko_make_basic(MOD_MASK_SA,KC_KP_0,LSFT(RALT(KC_0)));
      const key_override_t number_0c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_0,RALT(KC_0));
      

const key_override_t *key_overrides[] = {
  &number_0c_override,
  &number_0b_override,
  &number_0_override,
  &number_1c_override,
  &number_1b_override,
  &number_1_override,
  &number_2c_override,
  &number_2b_override,
  &number_2_override,
  &number_3c_override,
  &number_3b_override,
  &number_3_override,
  &number_4c_override,
  &number_4b_override,
  &number_4_override,
  &number_5c_override,
  &number_5b_override,
  &number_5_override,
  &number_6c_override,
  &number_6b_override,
  &number_6_override,
  &number_7c_override,
  &number_7b_override,
  &number_7_override,
  &number_8c_override,
  &number_8b_override,
  &number_8_override,
  &number_9c_override,
  &number_9b_override,
  &number_9_override
};

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

// pour les dictionnaires de combos (combos.def)
#include "g/keymap_combo.h"

// Permissive hold sur les MT incluant Shift, pas sur les autres, pour éviter les faux mods
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { 
    switch (keycode) {
        case BP_E_MOD:
        case BP_T_MOD:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// par rapport à la configuration par défaut, on désactive la touche espace
// https://docs.qmk.fm/tap_hold#flow-tap
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        //case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

extern bool is_launching;

enum tap_dance_codes {
  D_0,
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
  D_19,
  D_20,
  D_COPY_CUT,
  D_PASTE_LSFT
};

char chordal_hold_handedness(keypos_t key) {
    //if (key.col == 0 || key.col == MATRIX_COLS - 1) {
    //    return '*';  // Exempt the outer columns.
    //}
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    // Left Hand                                                                   // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    BP_B,       BP_EACU,    BP_P,       BP_O,       BP_EGRV,    TD(D_ESC_LOCK),              TD(D_2),    BP_DCIR,    BP_V,       BP_D,       BP_L,       BP_J,       BP_Z,
    TD(D_ESC_LOCK), BP_A_MOD,   BP_U_MOD,   BP_I_MOD,   BP_E_MOD,   BP_COMM,    QK_LEAD,              TD(D_3),    BP_C,       BP_T_MOD,   BP_S_MOD,   BP_R_MOD,   BP_N_MOD,   BP_M_MOD,
    CW_TOGG,    BP_AGRV,    BP_Y,       BP_X,       BP_DOT,     BP_K,                                         BP_QUOT,    BP_Q,       BP_G,       BP_H,       BP_F,       BP_SLSH,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    BP_TAB_MOD,           LGUI(BP_SCLN),       TD(D_2),                KC_BSPC,    KC_DEL,     CMC_SLASH,  XXXXXXX, XXXXXXX,
                                                    BP_SPC_LT,  SH_MON,     XXXXXXX,              XXXXXXX,    XXXXXXX,    MO(NUMPAD)
  ),
  [GAMING] = LAYOUT_moonlander( // Gaming layer
    // Left Hand                                                                   // Right Hand
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, BP_AT,                BP_PERC,    BP_AT,      BP_PLUS,    BP_MINS,    BP_SLSH,    BP_ASTR,    BP_EQL,
    BP_W,    BP_B,    BP_EACU, BP_P,    BP_O,    BP_EGRV, BP_DCIR,              _______,    BP_DCIR,    BP_V,       BP_D,       BP_L,       BP_J,       BP_Z,
    BP_CCED, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, KC_ENTER,             _______,    BP_C,       BP_T,   BP_S,   BP_R,   BP_N,   BP_M,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                      BP_QUOT,    BP_Q,       BP_G,       BP_H,       BP_F,       KC_RSFT,
    KC_LCTL,    _______,    KC_LALT,    KC_TAB,    _______,                _______,              TD(D_4),                KC_BSPC,    KC_DEL,     CMC_SLASH,  MO(ARROWSMACROS), KC_RCTL,
                                                    KC_SPC,    _______,    _______,              _______,    _______,    _______
  ),
  [NUMPAD] = LAYOUT_moonlander( // Numpad layer
    // Left Hand                                                                       // Right Hand
    QK_BOOT,    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,    RGB_VAD,    RGB_VAI,              LGUI(LALT(BP_B)), XXXXXXX,    KC_NUM,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    TD(D_F1_F13),   TD(D_F2_F14),   TD(D_F3_F15),   TD(D_F4_F16), XXXXXXX,  KC_VOLD,              XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, BP_EQL, BP_PERC,
    _______,    TD(D_F5_F17),   TD(D_F6_F18),   TD(D_F7_F19),   TD(D_F8_F20), XXXXXXX,  XXXXXXX,              XXXXXXX, KC_PPLS, KC_KP_4,KC_KP_5, KC_KP_6, KC_PAST, XXXXXXX,
    _______,    TD(D_F9_F21),   TD(D_F10_F22),  TD(D_F11_F23),  TD(D_F12_F24), XXXXXXX,                                        KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, _______,
    _______,    _______,        _______,        XXXXXXX,        _______,                _______,              _______,                    BP_DLR,     KC_KP_0,    BP_DOT,     BP_COMM,    XXXXXXX,
                                                                RALT(LSFT(KC_SPC)), _______, _______,        _______, _______, _______
  ),
    // QK_DYNAMIC_TAPPING_TERM_PRINT	DT_PRNT	Types the current tapping term, in milliseconds
    // QK_DYNAMIC_TAPPING_TERM_UP	DT_UP	Increases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default)
    // QK_DYNAMIC_TAPPING_TERM_DOWN	DT_DOWN
  [FXARROWS] = LAYOUT_moonlander( // Functions & Arrows layer
    // Left Hand                                                                       // Right Hand
    DT_UP,      DT_DOWN,    DT_PRNT,            XXXXXXX,            XXXXXXX,        XXXXXXX,    KC_VOLU,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,        XXXXXXX,    KC_VOLD,              XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_PGUP,    XXXXXXX,    XXXXXXX,
    _______,    XXXXXXX,    LCTL(BP_X),         TD(D_COPY_CUT),     TD(D_PASTE_LSFT), XXXXXXX,  XXXXXXX,              XXXXXXX,    KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_DEL,     XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,        XXXXXXX,                                      XXXXXXX,    KC_END,     XXXXXXX,    KC_PGDN,    XXXXXXX,    _______,
    _______,    _______,    _______,            _______,            _______,                    XXXXXXX,              _______,                _______, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                                    KC_MPRV,        TD(D_19),   KC_MNXT,              LGUI(LCTL(KC_LEFT)), TD(D_20), LGUI(LCTL(KC_RIGHT))
  ),
  [ARROWSMACROS] = LAYOUT_moonlander( // Arrows & Macros layer
    // Left Hand                                                                       // Right Hand
    _______,    _______,    _______,    _______,    _______,    _______,    _______,              _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    DM_REC1,    DM_RSTP,    DM_PLY1,    _______,    _______,              _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    DM_REC2,    DM_RSTP,    DM_PLY2,    _______,    _______,              _______,    _______,    _______,    _______,    KC_PGUP,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                                      _______,    KC_HOME,    KC_UP,      KC_PGDN,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,                _______,              _______,                KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,
                                                    _______,    _______,    _______,              _______,    _______,    _______
  )
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(GAMING))
    switch(combo_index) {
      case YX_ENTER:
      case GH_ENTER:
      case XDOT_W:
      case QG_Ç:
        return true;
      default:
        return false;
    }
  return true;
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


tap_dance_action_t tap_dance_actions[] = {
        [D_0] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(LCTL(KC_TAB), LALT(LCTL(KC_TAB)), LCTL(LSFT(KC_TAB)), LGUI(KC_TAB)),
        [D_ESC_LOCK] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_ESCAPE, KC_ESCAPE, KC_ESCAPE, LGUI(BP_L)),
        [D_2] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), GAMING),
        [D_3] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_INSERT, LGUI(LSFT(BP_S)), LGUI(LALT(BP_K)), KC_PSCR),
        [D_4] = ACTION_TAP_DANCE_LAYER_MOVE(LALT(KC_SPACE), BASE),
        [D_5] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS_LOCK, KC_ENTER),
        [D_F1_F13] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F1, KC_F13),
        [D_F2_F14] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F2, KC_F14),
        [D_F3_F15] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F3, KC_F15),
        [D_F4_F16] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F4, KC_F16),
        [D_F5_F17] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F5, KC_RALT, KC_F17, KC_RALT),
        [D_F6_F18] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F6, KC_LALT, KC_F18, KC_LALT),
        [D_F7_F19] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F7, KC_LCTL, KC_F19, KC_LCTL),
        [D_F8_F20] = CUSTOM_ACTION_TAP_DANCE_KEYCODES_ADVANCED(KC_F8, KC_LSFT, KC_F20, KC_LSFT),
        [D_F9_F21] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F9, KC_F21),
        [D_F10_F22] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F10, KC_F22),
        [D_F11_F23] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F11, KC_F23),
        [D_F12_F24] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_F12, KC_F24),
        [D_19] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP),
        [D_20] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(LCTL(LGUI(BP_D)), LCTL(LGUI(KC_F4))),
        [D_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(LCTL(BP_C), LCTL(BP_X)),
        [D_PASTE_LSFT] = CUSTOM_ACTION_TAP_DANCE_KEYCODES(LCTL(BP_V), KC_LSFT)
};

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
  // Stockage de l'état des modificateurs
  mod_state = get_mods();

  
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
