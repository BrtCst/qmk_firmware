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
  switch (key.row) {
    // thumbs (espace 5:0)
    case 5:
     if (key.col == 0 || key.col == 1 || key.col == 2) {
        return '*';
     }
     break;
    case 11:
      if (key.col == 4 || key.col == 5 || key.col == 6) {
        return '*';
     }
  }
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
  &ko_make_basic(MOD_MASK_SHIFT,RALT_T(KC_KP_4),KC_4),
  &ko_make_basic(MOD_MASK_SA,RALT_T(KC_KP_4),LSFT(RALT(KC_4))),
  &ko_make_basic(MOD_BIT(KC_RALT),RALT_T(KC_KP_4),RALT(KC_4)),
  &ko_make_basic(MOD_MASK_SHIFT,RSFT_T(KC_KP_5),KC_5),
  &ko_make_basic(MOD_MASK_SA,RSFT_T(KC_KP_5),LSFT(RALT(KC_5))),
  &ko_make_basic(MOD_BIT(KC_RALT),RSFT_T(KC_KP_5),RALT(KC_5)),
  &ko_make_basic(MOD_MASK_SHIFT,LALT_T(KC_KP_6),KC_6),
  &ko_make_basic(MOD_MASK_SA,LALT_T(KC_KP_6),LSFT(RALT(KC_6))),
  &ko_make_basic(MOD_BIT(KC_RALT),LALT_T(KC_KP_6),RALT(KC_6)),
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
    base_top_row[0], base_top_row[1], base_top_row[2], base_top_row[3], base_top_row[4], base_top_row[5], base_top_row[6],              base_top_row[7], base_top_row[8], base_top_row[9], base_top_row[10], base_top_row[11], base_top_row[12], base_top_row[13],
    base_mid_row[0], base_mid_row[1], base_mid_row[2], base_mid_row[3], base_mid_row[4], base_mid_row[5], base_mid_row[6],                base_mid_row[7], base_mid_row[8], base_mid_row[9], base_mid_row[10], base_mid_row[11], base_mid_row[12], base_mid_row[13],
    base_bot_row[0], base_bot_row[1], base_bot_row[2], base_bot_row[3], base_bot_row[4], base_bot_row[5],                                        base_bot_row[6], base_bot_row[7], base_bot_row[8], base_bot_row[9], base_bot_row[10], base_bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,    base_thumb_row[0],    base_thumb_row[1],           LGUI(BP_SCLN),       TD(D_2),                base_thumb_row[4],    base_thumb_row[5],     XXXXXXX,  XXXXXXX, XXXXXXX,
                                                    base_thumb_row[2],  SH_MON,     XXXXXXX,              XXXXXXX,    XXXXXXX,    base_thumb_row[3]
  ),
  [GAMING] = LAYOUT_moonlander( // Gaming layer
    // Left Hand                                                                   // Right Hand
    BP_DLR,  BP_DQUO, BP_LDAQ, BP_RDAQ, BP_LPRN, BP_RPRN, BP_AT,                BP_PERC,    BP_AT,      BP_PLUS,    BP_MINS,    BP_SLSH,    BP_ASTR,    BP_EQL,
    gaming_top_row[0], gaming_top_row[1], gaming_top_row[2], gaming_top_row[3], gaming_top_row[4], gaming_top_row[5], gaming_top_row[6],   gaming_top_row[7], gaming_top_row[8], gaming_top_row[9], gaming_top_row[10], gaming_top_row[11], gaming_top_row[12], gaming_top_row[13],
    gaming_mid_row[0], gaming_mid_row[1], gaming_mid_row[2], gaming_mid_row[3], gaming_mid_row[4], gaming_mid_row[5], gaming_mid_row[6],   gaming_mid_row[7], gaming_mid_row[8], gaming_mid_row[9], gaming_mid_row[10], gaming_mid_row[11], gaming_mid_row[12], gaming_mid_row[13],
    gaming_bot_row[0], gaming_bot_row[1], gaming_bot_row[2], gaming_bot_row[3], gaming_bot_row[4], gaming_bot_row[5],                      gaming_bot_row[6], gaming_bot_row[7], gaming_bot_row[8], gaming_bot_row[9], gaming_bot_row[10], gaming_bot_row[11],
    KC_LCTL,    KC_LGUI,    KC_LALT,    gaming_thumb_row[0],    gaming_thumb_row[1],                _______,              TD(D_4),                gaming_thumb_row[4],    gaming_thumb_row[5],     _______,  _______, KC_RCTL,
                                                    gaming_thumb_row[2],    MO(NAV),    KC_ESC,              _______,    _______,    gaming_thumb_row[3]
  ),
  [NUM] = LAYOUT_moonlander( // Numpad layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,              LGUI(LALT(BP_B)), XXXXXXX, XXXXXXX    ,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    num_top_row[0], num_top_row[1], num_top_row[2], num_top_row[3], num_top_row[4], num_top_row[5], num_top_row[6],   num_top_row[7], num_top_row[8], num_top_row[9], num_top_row[10], num_top_row[11], num_top_row[12], num_top_row[13],
    num_mid_row[0], num_mid_row[1], num_mid_row[2], num_mid_row[3], num_mid_row[4], num_mid_row[5], num_mid_row[6],   num_mid_row[7], num_mid_row[8], num_mid_row[9], num_mid_row[10], num_mid_row[11], num_mid_row[12], num_mid_row[13],
    num_bot_row[0], num_bot_row[1], num_bot_row[2], num_bot_row[3], num_bot_row[4], num_bot_row[5],                      num_bot_row[6], num_bot_row[7], num_bot_row[8], num_bot_row[9], num_bot_row[10], num_bot_row[11],
    XXXXXXX,    XXXXXXX,        XXXXXXX,        num_thumb_row[0],  num_thumb_row[1],                XXXXXXX,                    XXXXXXX,                    num_thumb_row[4],     num_thumb_row[5],    XXXXXXX,     XXXXXXX,    XXXXXXX,
                                                                num_thumb_row[2], XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, num_thumb_row[3]
  ),
    // QK_DYNAMIC_TAPPING_TERM_PRINT	DT_PRNT	Types the current tapping term, in milliseconds
    // QK_DYNAMIC_TAPPING_TERM_UP	DT_UP	Increases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default)
    // QK_DYNAMIC_TAPPING_TERM_DOWN	DT_DOWN
  [NAV] = LAYOUT_moonlander( // fn layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,      XXXXXXX, LALT(LCTL(LSFT(KC_F9))), LALT(LCTL(LSFT(KC_F10))), LALT(LCTL(LSFT(KC_F11))),        XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    nav_top_row[0], nav_top_row[1], nav_top_row[2], nav_top_row[3], nav_top_row[4], nav_top_row[5], nav_top_row[6],   nav_top_row[7], nav_top_row[8], nav_top_row[9], nav_top_row[10], nav_top_row[11], nav_top_row[12], nav_top_row[13],
    nav_mid_row[0], nav_mid_row[1], nav_mid_row[2], nav_mid_row[3], nav_mid_row[4], nav_mid_row[5], nav_mid_row[6],   nav_mid_row[7], nav_mid_row[8], nav_mid_row[9], nav_mid_row[10], nav_mid_row[11], nav_mid_row[12], nav_mid_row[13],
    nav_bot_row[0], nav_bot_row[1], nav_bot_row[2], nav_bot_row[3], nav_bot_row[4], nav_bot_row[5],                      nav_bot_row[6], nav_bot_row[7], nav_bot_row[8], nav_bot_row[9], nav_bot_row[10], nav_bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,            nav_thumb_row[0],            nav_thumb_row[1],                    XXXXXXX,              XXXXXXX,                nav_thumb_row[4], nav_thumb_row[5], XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                                    nav_thumb_row[2],        XXXXXXX,   XXXXXXX,              XXXXXXX, TD(D_20), nav_thumb_row[3]
  ),
  [FN] = LAYOUT_moonlander( // Functions & Arrows layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    fn_top_row[0], fn_top_row[1], fn_top_row[2], fn_top_row[3], fn_top_row[4], fn_top_row[5], fn_top_row[6],   fn_top_row[7], fn_top_row[8], fn_top_row[9], fn_top_row[10], fn_top_row[11], fn_top_row[12], fn_top_row[13],
    fn_mid_row[0], fn_mid_row[1], fn_mid_row[2], fn_mid_row[3], fn_mid_row[4], fn_mid_row[5], fn_mid_row[6],   fn_mid_row[7], fn_mid_row[8], fn_mid_row[9], fn_mid_row[10], fn_mid_row[11], fn_mid_row[12], fn_mid_row[13],
    fn_bot_row[0], fn_bot_row[1], fn_bot_row[2], fn_bot_row[3], fn_bot_row[4], fn_bot_row[5],                  fn_bot_row[6], fn_bot_row[7], fn_bot_row[8], fn_bot_row[9], fn_bot_row[10], fn_bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,    fn_thumb_row[0],    fn_thumb_row[1],                XXXXXXX,              XXXXXXX,                fn_thumb_row[4],    fn_thumb_row[5],    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    fn_thumb_row[2],    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    fn_thumb_row[3]
  ),
  [CONFIG] = LAYOUT_moonlander( // Arrows & Macros layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    config_top_row[0], config_top_row[1], config_top_row[2], config_top_row[3], config_top_row[4], config_top_row[5], config_top_row[6],   config_top_row[7], config_top_row[8], config_top_row[9], config_top_row[10], config_top_row[11], config_top_row[12], config_top_row[13],
    config_mid_row[0], config_mid_row[1], config_mid_row[2], config_mid_row[3], config_mid_row[4], config_mid_row[5], config_mid_row[6],   config_mid_row[7], config_mid_row[8], config_mid_row[9], config_mid_row[10], config_mid_row[11], config_mid_row[12], config_mid_row[13],
    config_bot_row[0], config_bot_row[1], config_bot_row[2], config_bot_row[3], config_bot_row[4], config_bot_row[5],                      config_bot_row[6], config_bot_row[7], config_bot_row[8], config_bot_row[9], config_bot_row[10], config_bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,    config_thumb_row[0],    config_thumb_row[1],                XXXXXXX,              XXXXXXX,                config_thumb_row[4],    config_thumb_row[5],    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    config_thumb_row[2],    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    config_thumb_row[3]
  ),
  [LOCK] = LAYOUT_moonlander( // Arrows & Macros layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    lock_top_row[0], lock_top_row[1], lock_top_row[2], lock_top_row[3], lock_top_row[4], lock_top_row[5], lock_top_row[6],   lock_top_row[7], lock_top_row[8], lock_top_row[9], lock_top_row[10], lock_top_row[11], lock_top_row[12], lock_top_row[13],
    lock_mid_row[0], lock_mid_row[1], lock_mid_row[2], lock_mid_row[3], lock_mid_row[4], lock_mid_row[5], lock_mid_row[6],   lock_mid_row[7], lock_mid_row[8], lock_mid_row[9], lock_mid_row[10], lock_mid_row[11], lock_mid_row[12], lock_mid_row[13],
    lock_bot_row[0], lock_bot_row[1], lock_bot_row[2], lock_bot_row[3], lock_bot_row[4], lock_bot_row[5],                    lock_bot_row[6], lock_bot_row[7], lock_bot_row[8], lock_bot_row[9], lock_bot_row[10], lock_bot_row[11],
    XXXXXXX,    XXXXXXX,    XXXXXXX,    lock_thumb_row[0],    lock_thumb_row[1],                XXXXXXX,              XXXXXXX,                lock_thumb_row[4],    lock_thumb_row[5],    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                    lock_thumb_row[2],    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    lock_thumb_row[3]
  )
};


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(GAMING)) {
    switch (combo_index) {
      case XDOT_W:
      case GH_ENTER:
        return true;
      default:
        return false;
    }
  }
  return true;
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
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
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
typedef struct {
    bool set;
    hsv_t hsv;
} led_color_t;
static led_color_t color_table[MAX_LEDS] = {[0 ... MAX_LEDS-1] = {false, {HSV_BLACK}}};

void set_key_color(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    color_table[index] = (led_color_t){true, {h, s, v}};
}
bool rgb_matrix_indicators_user() {
/*
 * Moonlander Mark I — RGB LED index map
 *
 * Left half                                    Right half
 * .-----.-----.-----.-----.-----.-----.-----.  .-----.-----.-----.-----.-----.-----.-----.
 * | 0   | 5   | 10  | 15  | 20  | 25  | 29  |  | 65  | 61  | 56  | 51  | 46  | 41  | 36  |
 * +-----+-----+-----+-----+-----+-----+-----+  +-----+-----+-----+-----+-----+-----+-----+
 * | 1   | 6   | 11  | 16  | 21  | 26  | 30  |  | 66  | 62  | 57  | 52  | 47  | 42  | 37  |
 * +-----+-----+-----+-----+-----+-----+-----+  +-----+-----+-----+-----+-----+-----+-----+
 * | 2   | 7   | 12  | 17  | 22  | 27  | 31  |  | 67  | 63  | 58  | 53  | 48  | 43  | 38  |
 * +-----+-----+-----+-----+-----+-----+-----'  '-----+-----+-----+-----+-----+-----+-----+
 * | 3   | 8   | 13  | 18  | 23  | 28  |              | 64  | 59  | 54  | 49  | 44  | 39  |
 * +-----+-----+-----+-----+-----+-----+/\          /\+-----+-----+-----+-----+-----+-----+
 * | 4   | 9   | 14  | 19  | 24  |     /  \        /  \     | 60  | 55  | 50  | 45  | 40  |
 * '-----'-----'-----'-----+-----’    /\35 \      /71 /\    ’-----+-----'-----'-----'-----'
 *                                   /  \   \    /   /  \
 *                                  /32 /\  /    \  /\68 \
 *                                  \  /  \/      \/  \  /
 *                                   \/33 /\      /\69 \/
 *                                    \  /  \    /  \  /
 *                                     \/34 /    \70 \/
 *                                      \  /      \  /
 *                                       \/        \/
 */
    ML_LED_5(false);
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
    color_table[i].set = false;
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
            case NUM:
              set_key_color(67, HSV_RED ); //numlock
              
              // layer lock
              set_key_color(66, HSV_PURPLE);
              break;
            case NAV:
              set_key_color(48, HSV_RED); // arrows
              set_key_color(52, HSV_RED);
              set_key_color(53, HSV_RED);
              set_key_color(58, HSV_RED );
              set_key_color(57, HSV_YELLOW ); // home
              set_key_color(59, HSV_YELLOW ); // end
              set_key_color(47, HSV_YELLOW ); // pgup
              set_key_color(49, HSV_YELLOW ); // pgdn

              //copy paste
              set_key_color(22, HSV_CYAN);
              set_key_color(17, HSV_CYAN);

              // media
              set_key_color(11, HSV_GREEN);
              set_key_color(16, HSV_GREEN);
              set_key_color(21, HSV_GREEN);
              set_key_color(26, HSV_GREEN);
              set_key_color(27, HSV_GREEN);
              set_key_color(28, HSV_GREEN);

              set_key_color(31, HSV_RED); // caps lock
              break;
            case FN:
              // fn
              set_key_color(6, HSV_BLUE);
              set_key_color(7, HSV_BLUE);
              set_key_color(8, HSV_BLUE);
              set_key_color(11, HSV_BLUE);
              set_key_color(12, HSV_BLUE);
              set_key_color(13, HSV_BLUE);
              set_key_color(16, HSV_BLUE);
              set_key_color(17, HSV_BLUE);
              set_key_color(18, HSV_BLUE);
              set_key_color(21, HSV_BLUE);
              set_key_color(22, HSV_BLUE);
              set_key_color(23, HSV_BLUE);

              // macros
              set_key_color(62, HSV_RED);
              set_key_color(57, HSV_RED);
              set_key_color(52, HSV_ORANGE);
              set_key_color(47, HSV_GREEN);
              set_key_color(42, HSV_GREEN);
              break;
            case CONFIG:
               set_key_color(1, HSV_RED); // bootloader
               set_key_color(2, HSV_YELLOW); // bootloader

               // dynamic tap term
               //set_key_color(6, HSV_CYAN);
               //set_key_color(7, HSV_CYAN);
               //set_key_color(8, HSV_CYAN);
               
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
    if (!color_table[i].set) {
        rgb_matrix_set_color(i, 0, 0, 0);
        continue;
    }
    hsv_t hsv = color_table[i].hsv;
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
    case 0:
        ML_LED_1(false);
        ML_LED_2(false);
        ML_LED_3(false);
        ML_LED_4(false);
        break;
    case 1:
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
        break;
    default: //  for any other layers, or the default layer
        break;
    }

  rgb_matrix_indicators_user();
  return state;
}

bool process_record_brtcst(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_brtcst(keycode, record);
}
