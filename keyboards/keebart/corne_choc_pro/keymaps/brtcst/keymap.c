#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_bepo.h"

// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"

#include "common_brtcst.h"
#include "transactions.h"



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
      const key_override_t number_4_override =ko_make_basic(MOD_MASK_SHIFT,RSFT_T(KC_KP_4),KC_4);
      const key_override_t number_4b_override =ko_make_basic(MOD_MASK_SA,RSFT_T(KC_KP_4),LSFT(RALT(KC_4)));
      const key_override_t number_4c_override =ko_make_basic(MOD_BIT(KC_RALT),RSFT_T(KC_KP_4),RALT(KC_4));
      const key_override_t number_5_override =ko_make_basic(MOD_MASK_SHIFT,RCTL_T(KC_KP_5),KC_5);
      const key_override_t number_5b_override =ko_make_basic(MOD_MASK_SA,RCTL_T(KC_KP_5),LSFT(RALT(KC_5)));
      const key_override_t number_5c_override =ko_make_basic(MOD_BIT(KC_RALT),RCTL_T(KC_KP_5),RALT(KC_5));
      const key_override_t number_6_override =ko_make_basic(MOD_MASK_SHIFT,LALT_T(KC_KP_6),KC_6);
      const key_override_t number_6b_override =ko_make_basic(MOD_MASK_SA,LALT_T(KC_KP_6),LSFT(RALT(KC_6)));
      const key_override_t number_6c_override =ko_make_basic(MOD_BIT(KC_RALT),LALT_T(KC_KP_6),RALT(KC_6));
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

// pour les dictionnaires de combos (combos.def)
#include "g/keymap_combo.h"

char chordal_hold_handedness(keypos_t key) {
    if (key.col == 5 || key.row == 3) { // espace
        return '*';  // Exempt the outer columns.
    }
    if (key.col == 5 || key.row == 7) { // touche longue droite
        return '*';  // Exempt the outer columns.
    }
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R'; // vérifié en mode debug
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.
        //,-----------------------------------------------------.
        base_top_row[0], base_top_row[1], base_top_row[2], base_top_row[3], base_top_row[4], base_top_row[5], base_top_row[6],                base_top_row[7], base_top_row[8], base_top_row[9], base_top_row[10], base_top_row[11], base_top_row[12], base_top_row[13],
        //|--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------|
        base_mid_row[0], base_mid_row[1], base_mid_row[2], base_mid_row[3], base_mid_row[4], base_mid_row[5], base_mid_row[6],                base_mid_row[7], base_mid_row[8], base_mid_row[9], base_mid_row[10], base_mid_row[11], base_mid_row[12], base_mid_row[13],
        //|--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------|
        base_bot_row[0], base_bot_row[1], base_bot_row[2], base_bot_row[3], base_bot_row[4], base_bot_row[5],                                                  base_bot_row[6], base_bot_row[7], base_bot_row[8], base_bot_row[9], base_bot_row[10], base_bot_row[11],
        //|--------+--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------+--------|
        base_thumb_row[0], base_thumb_row[1], base_thumb_row[2], base_thumb_row[3], base_thumb_row[4], base_thumb_row[5]
        //`--------------------------'  `--------------------------'
        ),
  [GAMING] = LAYOUT_split_3x6_3_ex2( // Gaming layer
    gaming_top_row[0], gaming_top_row[1], gaming_top_row[2], gaming_top_row[3], gaming_top_row[4], gaming_top_row[5], gaming_top_row[6],   gaming_top_row[7],  gaming_top_row[8],  gaming_top_row[9],  gaming_top_row[10], gaming_top_row[11], gaming_top_row[12], gaming_top_row[13],
    gaming_mid_row[0], gaming_mid_row[1], gaming_mid_row[2], gaming_mid_row[3], gaming_mid_row[4], gaming_mid_row[5], gaming_mid_row[6],   gaming_mid_row[7],  gaming_mid_row[8],  gaming_mid_row[9],  gaming_mid_row[10], gaming_mid_row[11], gaming_mid_row[12], gaming_mid_row[13],
    gaming_bot_row[0], gaming_bot_row[1], gaming_bot_row[2], gaming_bot_row[3], gaming_bot_row[4], gaming_bot_row[5],                      gaming_bot_row[6],  gaming_bot_row[7],  gaming_bot_row[8],  gaming_bot_row[9],  gaming_bot_row[10], gaming_bot_row[11],
    gaming_thumb_row[0], gaming_thumb_row[1], gaming_thumb_row[2], gaming_thumb_row[3], gaming_thumb_row[4], gaming_thumb_row[5]
  ),
  [NUM] = LAYOUT_split_3x6_3_ex2( // num layer
    num_top_row[0], num_top_row[1], num_top_row[2], num_top_row[3], num_top_row[4], num_top_row[5], num_top_row[6],   num_top_row[7],  num_top_row[8],  num_top_row[9],  num_top_row[10], num_top_row[11], num_top_row[12], num_top_row[13],
    num_mid_row[0], num_mid_row[1], num_mid_row[2], num_mid_row[3], num_mid_row[4], num_mid_row[5], num_mid_row[6],   num_mid_row[7],  num_mid_row[8],  num_mid_row[9],  num_mid_row[10], num_mid_row[11], num_mid_row[12], num_mid_row[13],
    num_bot_row[0], num_bot_row[1], num_bot_row[2], num_bot_row[3], num_bot_row[4], num_bot_row[5],                      num_bot_row[6],  num_bot_row[7],  num_bot_row[8],  num_bot_row[9],  num_bot_row[10], num_bot_row[11],
    num_thumb_row[0], num_thumb_row[1], num_thumb_row[2], num_thumb_row[3], num_thumb_row[4], num_thumb_row[5]
  ),
  [NAV] = LAYOUT_split_3x6_3_ex2( // Functions & nav layer
    nav_top_row[0], nav_top_row[1], nav_top_row[2], nav_top_row[3], nav_top_row[4], nav_top_row[5], nav_top_row[6],   nav_top_row[7],  nav_top_row[8],  nav_top_row[9],  nav_top_row[10], nav_top_row[11], nav_top_row[12], nav_top_row[13],
    nav_mid_row[0], nav_mid_row[1], nav_mid_row[2], nav_mid_row[3], nav_mid_row[4], nav_mid_row[5], nav_mid_row[6],   nav_mid_row[7],  nav_mid_row[8],  nav_mid_row[9],  nav_mid_row[10], nav_mid_row[11], nav_mid_row[12], nav_mid_row[13],
    nav_bot_row[0], nav_bot_row[1], nav_bot_row[2], nav_bot_row[3], nav_bot_row[4], nav_bot_row[5],                      nav_bot_row[6],  nav_bot_row[7],  nav_bot_row[8],  nav_bot_row[9],  nav_bot_row[10], nav_bot_row[11],
    nav_thumb_row[0], nav_thumb_row[1], nav_thumb_row[2], nav_thumb_row[3], nav_thumb_row[4], nav_thumb_row[5]
  ),
  [FN] = LAYOUT_split_3x6_3_ex2( // Functions & nav layer
    fn_top_row[0], fn_top_row[1], fn_top_row[2], fn_top_row[3], fn_top_row[4], fn_top_row[5], fn_top_row[6],   fn_top_row[7],  fn_top_row[8],  fn_top_row[9],  fn_top_row[10], fn_top_row[11], fn_top_row[12], fn_top_row[13],
    fn_mid_row[0], fn_mid_row[1], fn_mid_row[2], fn_mid_row[3], fn_mid_row[4], fn_mid_row[5], fn_mid_row[6],   fn_mid_row[7],  fn_mid_row[8],  fn_mid_row[9],  fn_mid_row[10], fn_mid_row[11], fn_mid_row[12], fn_mid_row[13],
    fn_bot_row[0], fn_bot_row[1], fn_bot_row[2], fn_bot_row[3], fn_bot_row[4], fn_bot_row[5],                  fn_bot_row[6],  fn_bot_row[7],  fn_bot_row[8],  fn_bot_row[9],  fn_bot_row[10], fn_bot_row[11],
    fn_thumb_row[0], fn_thumb_row[1], fn_thumb_row[2], fn_thumb_row[3], fn_thumb_row[4], fn_thumb_row[5]
  ),
  [CONFIG] = LAYOUT_split_3x6_3_ex2( // CONFIG
    config_top_row[0], config_top_row[1], config_top_row[2], config_top_row[3], config_top_row[4], config_top_row[5], config_top_row[6],   config_top_row[7],  config_top_row[8],  config_top_row[9],  config_top_row[10], config_top_row[11], config_top_row[12], config_top_row[13],
    config_mid_row[0], config_mid_row[1], config_mid_row[2], config_mid_row[3], config_mid_row[4], config_mid_row[5], config_mid_row[6],   config_mid_row[7],  config_mid_row[8],  config_mid_row[9],  config_mid_row[10], config_mid_row[11], config_mid_row[12], config_mid_row[13],
    config_bot_row[0], config_bot_row[1], config_bot_row[2], config_bot_row[3], config_bot_row[4], config_bot_row[5],                      config_bot_row[6],  config_bot_row[7],  config_bot_row[8],  config_bot_row[9],  config_bot_row[10], config_bot_row[11],
    config_thumb_row[0], config_thumb_row[1], config_thumb_row[2], config_thumb_row[3], config_thumb_row[4], config_thumb_row[5]
  ),
  [LOCK] = LAYOUT_split_3x6_3_ex2( // lock layer
    lock_top_row[0], lock_top_row[1], lock_top_row[2], lock_top_row[3], lock_top_row[4], lock_top_row[5], lock_top_row[6],   lock_top_row[7],  lock_top_row[8],  lock_top_row[9],  lock_top_row[10], lock_top_row[11], lock_top_row[12], lock_top_row[13],
    lock_mid_row[0], lock_mid_row[1], lock_mid_row[2], lock_mid_row[3], lock_mid_row[4], lock_mid_row[5], lock_mid_row[6],   lock_mid_row[7],  lock_mid_row[8],  lock_mid_row[9],  lock_mid_row[10], lock_mid_row[11], lock_mid_row[12], lock_mid_row[13],
    lock_bot_row[0], lock_bot_row[1], lock_bot_row[2], lock_bot_row[3], lock_bot_row[4], lock_bot_row[5],                    lock_bot_row[6],  lock_bot_row[7],  lock_bot_row[8],  lock_bot_row[9],  lock_bot_row[10], lock_bot_row[11],
    lock_thumb_row[0], lock_thumb_row[1], lock_thumb_row[2], lock_thumb_row[3], lock_thumb_row[4], lock_thumb_row[5]
    )
};

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  // Left
	{{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
	{{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
	{{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
	{{0, 0}, {0, 0}, {0, 0}, {3, 7}, {4, 7}, {5, 7}, {0, 0}},
	// Right
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
	{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
	{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
	{{0, 0}, {0, 0}, {0, 0}, {5, 3}, {4, 3}, {3, 3}, {0, 0}}
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
    switch (index) {
        case ST_HYPHEN:
        case SR_ASTERISK:
        case UI_HASSH:
        case SL_AROBASE:
            return COMBO_TERM_SHORT;
    }
    return COMBO_TERM;
}

// Handler pour la synchro de l’état de caps_word entre les deux moitiés, qui ne fonctionne pas par défaut
void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
       bool caps_word_active = *(bool*)initiator2target_buffer;
       if (caps_word_active) {
        caps_word_on();
       } else {
        caps_word_off();
       }
  }

void keyboard_post_init_user(void) {
    //rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // enregistrement de la synchro de caps_word, qui ne fonctionne pas par défaut
    transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);


}

tap_dance_action_t tap_dance_actions[] = TAP_DANCE_LIST;

/* custom */


// The number of per-key LEDs on each side of a 5-column Corne.
#define NUM_LEDS_PER_SIDE 24

// keyboards/crkbd/rev1/rev1.c has a hard-coded g_led_config with 27 LEDs, so we
// have to work around this.
#define NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE 27


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
}

#define MAX_LEDS 46
typedef struct {
    bool set;
    hsv_t hsv;
} led_color_t;
static led_color_t color_table[MAX_LEDS] = {[0 ... MAX_LEDS-1] = {false, {HSV_BLACK}}};

void set_key_color(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    color_table[index] = (led_color_t){true, {h, s, v}};
}

bool rgb_matrix_indicators_user() {
  // Sens des leds : début moitité gauche, espace 0, puis serpentin vers la gauche. Les deux touches supplémentaires sont 21 (haut) et 22 (bas).
  // ajouter 23 pour avoir la touche correspondante à droite

  // NOTE IMPORTANTE : suite à bug ou mauvaise conf du firmware, les leds de la moitié gauche sont mirrorées à droite. Il faut
  // donc les réinitialiser après avoir déclaré la moitié gauche

  // NOTE : il faut flasher les deux moitiés du clavier pour que les leds fonctionnent correctement
/*
  Left half                     Right half
.----.----.----.----.----.----.           .----.----.----.----.----.----.
| 18 | 17 | 12 | 11 | 4  | 3  |----. .----| 26 | 27 | 34 | 35 | 40 | 41 |
+----+----+----+----+----+----+ 21 | | 44 +----+----+----+----+----+----+
| 19 | 16 | 13 | 10 | 5  | 2  |----+ +----| 25 | 28 | 33 | 36 | 39 | 42 |
+----+----+----+----+----+----+ 22 | | 45 +----+----+----+----+----+----+
| 20 | 15 | 14 | 9  | 6  | 1  |----+ +----| 24 | 29 | 32 | 37 | 38 | 43 |
'----'----'----'----+----+----+    | |    +----+----+----'----'----'----'
                    | 8  | 7  | 0  | | 23 | 30 | 31 |
                    +----+----+----’ ’----+----+----+
*/
  for (int i = 0; i < MAX_LEDS; i++)
  {
    color_table[i].set = false;
  }

  if (!host_keyboard_led_state().num_lock) {
    set_key_color(26, HSV_GREEN);
  } else {
     set_key_color(26, HSV_BLACK);
  }

    hsv_t caps_color = {0, 0, 0};
    if (is_caps_word_on()) {
        caps_color = host_keyboard_led_state().caps_lock ? (hsv_t){HSV_PURPLE} : (hsv_t){HSV_BLUE};
    } else if (host_keyboard_led_state().caps_lock) {
        caps_color = (hsv_t){HSV_RED};
    }
    if (caps_color.h || caps_color.s || caps_color.v) {
        set_key_color(22, caps_color.h, caps_color.s, caps_color.v);
    }
    if (is_swap_hands_on()) {
      set_key_color(22, HSV_YELLOW);
    }

    switch(get_highest_layer(layer_state)) {
            case GAMING:
                set_key_color(44, HSV_RED);
                break;
            case NUM:
              set_key_color(45, HSV_RED ); //numlock
              
              set_key_color(44, HSV_PURPLE); // layer lock

              break;
            case NAV:
              set_key_color(28, HSV_RED); // arrows
              set_key_color(33, HSV_RED);
              set_key_color(34, HSV_RED);
              set_key_color(36, HSV_RED );
              set_key_color(27, HSV_YELLOW ); // home
              set_key_color(29, HSV_YELLOW ); // end
              set_key_color(35, HSV_YELLOW ); // pgup
              set_key_color(37, HSV_YELLOW ); // pgdn
              set_key_color(25, HSV_CYAN); // backspace
              set_key_color(39, HSV_CYAN); // del

              //copy paste
              set_key_color(5, HSV_CYAN);
              set_key_color(10, HSV_CYAN);              

              //media
              set_key_color(1, HSV_GREEN);
              set_key_color(2, HSV_GREEN);
              set_key_color(3, HSV_GREEN);
              set_key_color(4, HSV_GREEN);
              set_key_color(11, HSV_GREEN);
              set_key_color(12, HSV_GREEN);

              set_key_color(22, HSV_RED); // caps lock
              break;
            case FN:
              // fn
              set_key_color(4, HSV_BLUE);
              set_key_color(5, HSV_BLUE);
              set_key_color(6, HSV_BLUE);
              set_key_color(9, HSV_BLUE);
              set_key_color(10, HSV_BLUE);
              set_key_color(11, HSV_BLUE);
              set_key_color(12, HSV_BLUE);
              set_key_color(13, HSV_BLUE);
              set_key_color(14, HSV_BLUE);
              set_key_color(15, HSV_BLUE);
              set_key_color(16, HSV_BLUE);
              set_key_color(17, HSV_BLUE);

              // macros
              set_key_color(26, HSV_RED);
              set_key_color(27, HSV_RED);
              set_key_color(34, HSV_ORANGE);
              set_key_color(35, HSV_GREEN);
              set_key_color(40, HSV_GREEN);
              break;
            case CONFIG:
               set_key_color(18, HSV_RED); // bootloader
               set_key_color(19, HSV_ORANGE); // debug

               // dynamic tap term
               //set_key_color(15, HSV_CYAN);
               //set_key_color(16, HSV_CYAN);
               //set_key_color(17, HSV_CYAN);

               // brightness
               set_key_color(1, HSV_YELLOW);
               set_key_color(2, HSV_YELLOW);
              break;
            case LOCK:
               set_key_color(21, HSV_YELLOW);
               break;
            default:
                break;
        }

  for (size_t i = 0; i < MAX_LEDS; i++) {
    if (!color_table[i].set) continue;
    hsv_t hsv = color_table[i].hsv;
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }

	return false;
}

// Gestion de l’état du caps_word, notamment la synchro des deux moitiés
void caps_word_set_user(bool active) {
      if (is_keyboard_master()) {
          // Synchroniser l'état vers l'autre moitié
          transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
      }
  }

bool process_record_brtcst(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_brtcst(keycode, record);
}
