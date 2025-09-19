#include QMK_KEYBOARD_H
#include "version.h"
//#include "keymap_br_abnt2.h"
#include "keymap_bepo.h"
//#include "keymap_contributions.h"
#include "keymap_us_international.h"
// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"

#include "common_brtcst.h"


extern bool is_launching;


// pour les dictionnaires de combos (combos.def)
#include "g/keymap_combo.h"


char chordal_hold_handedness(keypos_t key) {
    //if (key.col == 0 || key.col == MATRIX_COLS - 1) {
    //    return '*';  // Exempt the outer columns.
    //}
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

tap_dance_action_t tap_dance_actions[] = TAP_DANCE_LIST;

const key_override_t *key_overrides[] = {
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_1,KC_1),
  &ko_make_basic(MOD_MASK_SA,KC_KP_1,LSFT(RALT(KC_1))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_1,RALT(KC_1)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_2,KC_2),
  &ko_make_basic(MOD_MASK_SA,KC_KP_2,LSFT(RALT(KC_2))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_2,RALT(KC_2)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_3,KC_3),
  &ko_make_basic(MOD_MASK_SA,KC_KP_3,LSFT(RALT(KC_3))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_3,RALT(KC_3)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_4,KC_4),
  &ko_make_basic(MOD_MASK_SA,KC_KP_4,LSFT(RALT(KC_4))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_4,RALT(KC_4)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_5,KC_5),
  &ko_make_basic(MOD_MASK_SA,KC_KP_5,LSFT(RALT(KC_5))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_5,RALT(KC_5)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_6,KC_6),
  &ko_make_basic(MOD_MASK_SA,KC_KP_6,LSFT(RALT(KC_6))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_6,RALT(KC_6)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_7,KC_7),
  &ko_make_basic(MOD_MASK_SA,KC_KP_7,LSFT(RALT(KC_7))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_7,RALT(KC_7)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_8,KC_8),
  &ko_make_basic(MOD_MASK_SA,KC_KP_8,LSFT(RALT(KC_8))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_8,RALT(KC_8)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_9,KC_9),
  &ko_make_basic(MOD_MASK_SA,KC_KP_9,LSFT(RALT(KC_9))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_9,RALT(KC_9)),
  &ko_make_basic(MOD_MASK_SHIFT,KC_KP_0,KC_0),
  &ko_make_basic(MOD_MASK_SA,KC_KP_0,LSFT(RALT(KC_0))),
  &ko_make_basic(MOD_BIT(KC_RALT),KC_KP_0,RALT(KC_0))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    // Left Hand                                                                   // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    top_row[0], top_row[1], top_row[2], top_row[3], top_row[4], top_row[5], top_row[6],              top_row[7], top_row[8], top_row[9], top_row[10], top_row[11], top_row[12], top_row[13],
    mid_row[0], mid_row[1], mid_row[2], mid_row[3], mid_row[4], mid_row[5], mid_row[6],                mid_row[7], mid_row[8], mid_row[9], mid_row[10], mid_row[11], mid_row[12], mid_row[13],
    bot_row[0], bot_row[1], bot_row[2], bot_row[3], bot_row[4], bot_row[5],                                        bot_row[6], bot_row[7], bot_row[8], bot_row[9], bot_row[10], bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,    thumb_row[0],    thumb_row[1],           LGUI(BP_SCLN),       TD(D_2),                thumb_row[4],    thumb_row[5],     CMC_SLASH,  XXXXXXX, XXXXXXX,
                                                    thumb_row[2],  SH_MON,     XXXXXXX,              XXXXXXX,    XXXXXXX,    thumb_row[3]
  ),
  [GAMING] = LAYOUT_moonlander( // Gaming layer
    // Left Hand                                                                   // Right Hand
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, BP_AT,                BP_PERC,    BP_AT,      BP_PLUS,    BP_MINS,    BP_SLSH,    BP_ASTR,    BP_EQL,
    BP_W, _______, _______, _______, _______, _______, BP_DCIR,              TD(D_4),  _______, _______, _______, _______, _______, _______,
    BP_CCED, BP_A,    BP_U,    BP_I,    BP_E,     _______, KC_ENTER,                      _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                     _______, _______, _______, _______, _______, _______,
    KC_LCTL,    KC_LGUI,    KC_LALT,    _______,    KC_TAB,                _______,              TD(D_4),                KC_BSPC,    KC_DEL,     CMC_SLASH,  XXXXXXX, KC_RCTL,
                                                    KC_SPC,    _______,    _______,              _______,    _______,    _______
  ),
  [NUMPAD] = LAYOUT_moonlander( // Numpad layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,              LGUI(LALT(BP_B)), XXXXXXX, XXXXXXX    ,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    DM_REC1,    DM_REC2,    DM_RSTP,   DM_PLY1,    DM_PLY2, XXXXXXX,   XXXXXXX,               QK_LLCK, KC_NUM, KC_KP_7, KC_KP_8, KC_KP_9, BP_EQL, BP_PERC,
    XXXXXXX,    KC_RALT,    KC_LALT,   KC_LCTL,    KC_LSFT, XXXXXXX,  XXXXXXX,                XXXXXXX, KC_PPLS, RSFT_T(KC_KP_4), RCTL_T(KC_KP_5), LALT_T(KC_KP_6), RALT_T(KC_PAST), XXXXXXX,
    XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX, CMC_COLON, XXXXXXX,                                               KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, XXXXXXX,
    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,  XXXXXXX,                XXXXXXX,                    XXXXXXX,                    BP_DLR,     KC_KP_0,    BP_DOT,     BP_COMM,    XXXXXXX,
                                                                MO(CONFIG), XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX
  ),
    // QK_DYNAMIC_TAPPING_TERM_PRINT	DT_PRNT	Types the current tapping term, in milliseconds
    // QK_DYNAMIC_TAPPING_TERM_UP	DT_UP	Increases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default)
    // QK_DYNAMIC_TAPPING_TERM_DOWN	DT_DOWN
  [FXARROWS] = LAYOUT_moonlander( // Arrows layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,      XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,        XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    TD(D_F1_F13),   TD(D_F2_F14),   TD(D_F3_F15),   TD(D_F4_F16),XXXXXXX,    KC_MUTE,  TG(LOCK),                  XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_PGUP,    XXXXXXX,    XXXXXXX,
    TD(D_F5_F17),   TD(D_F6_F18),   TD(D_F7_F19),   TD(D_F8_F20),TD(D_COPY_CUT), KC_VOLU,  KC_CAPS,            XXXXXXX,    KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_DEL,     XXXXXXX,
    TD(D_F9_F21),   TD(D_F10_F22),  TD(D_F11_F23),  TD(D_F12_F24),LCTL(BP_V),    KC_VOLD,                                   XXXXXXX,    KC_END,     XXXXXXX,    KC_PGDN,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,                    XXXXXXX,              XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                                    XXXXXXX,        XXXXXXX,   XXXXXXX,              XXXXXXX, TD(D_20),MO(CONFIG)
  ),
  [CONFIG] = LAYOUT_moonlander( // Arrows & Macros layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    DB_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RM_VALU,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RM_VALD,                                      XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,              XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX
  ),
  [LOCK] = LAYOUT_moonlander( // Arrows & Macros layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TD(D_UNLOCK),              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,              XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX
  )
};


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /*switch (combo_index) {
        case COMBO_30:
            return layer_state_is(0) || layer_state_is(1);
        default:
            // all combos on layer 0
            return layer_state_is(0);
    }*/
    // no combos on layer 1 (gaming)
    return !layer_state_is(GAMING);
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

void keyboard_post_init_user(void) {
    //rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    //rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

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
    } else if (leader_sequence_four_keys(BP_U, BP_N, BP_L, BP_U)) {
        // désactiver la couche lock
        layer_off(LOCK);
    }

}

#define MAX_LEDS 72
static hsv_t color_table[MAX_LEDS] = {[0 ... MAX_LEDS-1] = {HSV_BLACK}};

void set_key_color(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    color_table[index] = (hsv_t){h, s, v};
}
bool rgb_matrix_indicators_user() {
    // MOITIÉ GAUCHE
    // LEDs commencent à 0 en haut à gauche, puis vers le bas
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
            set_key_color(3, RGB_RED);
            set_key_color(39, RGB_RED);
        }
    }

      for (int i = 0; i < MAX_LEDS; i++)
  {
    set_key_color(i, HSV_BLACK);
  }

    hsv_t caps_color = {0, 0, 0};
    if (is_caps_word_on()) {
        caps_color = host_keyboard_led_state().caps_lock ? (hsv_t){HSV_PURPLE} : (hsv_t){HSV_BLUE};
    } else if (host_keyboard_led_state().caps_lock) {
        caps_color = (hsv_t){HSV_RED};
    }

    if (caps_color.h || caps_color.s || caps_color.v) {
        set_key_color(31, caps_color.h, caps_color.s, caps_color.v);
    }

    switch(get_highest_layer(layer_state)) {
            case GAMING:
                set_key_color(71, HSV_RED);
                break;
            case NUMPAD:
              set_key_color(47, HSV_GREEN); //numpad
              set_key_color(48, HSV_GREEN);
              set_key_color(49, HSV_GREEN);
              set_key_color(52, HSV_GREEN);
              set_key_color(53, HSV_GREEN);
              set_key_color(54, HSV_GREEN );
              set_key_color(55, HSV_GREEN);
              set_key_color(57, HSV_GREEN);
              set_key_color(58, HSV_GREEN);
              set_key_color(59, HSV_GREEN );
              set_key_color(62, HSV_RED ); //numlock

              // macros
              set_key_color(1, HSV_RED);
              set_key_color(6, HSV_RED);
              set_key_color(11, HSV_ORANGE);
              set_key_color(16, HSV_GREEN);
              set_key_color(21, HSV_GREEN);
              
              // layer lock
              set_key_color(66, HSV_PURPLE);
              break;
            case FXARROWS:
              set_key_color(48, HSV_RED); // arrows
              set_key_color(52, HSV_RED);
              set_key_color(53, HSV_RED);
              set_key_color(58, HSV_RED );
              set_key_color(57, HSV_YELLOW ); // home
              set_key_color(59, HSV_YELLOW ); // end
              set_key_color(47, HSV_YELLOW ); // pgup
              set_key_color(49, HSV_YELLOW ); // pgdn

              // fn
              set_key_color(1, HSV_BLUE);
              set_key_color(2, HSV_BLUE);
              set_key_color(3, HSV_BLUE);
              set_key_color(6, HSV_BLUE);
              set_key_color(7, HSV_BLUE);
              set_key_color(8, HSV_BLUE);
              set_key_color(11, HSV_BLUE);
              set_key_color(12, HSV_BLUE);
              set_key_color(13, HSV_BLUE);
              set_key_color(16, HSV_BLUE);
              set_key_color(17, HSV_BLUE);
              set_key_color(18, HSV_BLUE);

              //copy paste
              set_key_color(22, HSV_CYAN);
              set_key_color(23, HSV_CYAN);

              // media
              set_key_color(19, HSV_GREEN);
              set_key_color(24, HSV_GREEN);
              set_key_color(26, HSV_GREEN);
              set_key_color(27, HSV_GREEN);
              set_key_color(28, HSV_GREEN);

              set_key_color(31, HSV_RED); // caps lock
              break;
            case CONFIG:
               set_key_color(1, HSV_RED); // bootloader
               set_key_color(2, HSV_YELLOW); // bootloader
               
               // brightness
               set_key_color(27, HSV_YELLOW);
               set_key_color(28, HSV_YELLOW);
              break;
            case LOCK:
               set_key_color(30, HSV_YELLOW);
               break;
            default:
                break;
        }

  for (size_t i = 0; i < MAX_LEDS; i++) {
    hsv_t hsv = color_table[i];
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
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
    case CONFIG:
        ML_LED_1(false);
        ML_LED_2(false);
        ML_LED_3(false);
        ML_LED_4(true);
        break;
    case LOCK:
      ML_LED_1(true);
        ML_LED_2(false);
        ML_LED_3(false);
        ML_LED_4(false);
    default: //  for any other layers, or the default layer
        break;
    }

  rgb_matrix_indicators_user();
  return state;
}

void process_record_brtcst(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_brtcst(keycode, record);
  return true;
}
