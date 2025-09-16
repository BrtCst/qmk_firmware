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

// pour les dictionnaires de combos (combos.def)
#include "g/keymap_combo.h"

char chordal_hold_handedness(keypos_t key) {
    //if (key.col == 0 || key.col == MATRIX_COLS - 1) {
    //    return '*';  // Exempt the outer columns.
    //}
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R'; // vérifié en mode debug
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.
        //,-----------------------------------------------------.
        top_row[0], top_row[1], top_row[2], top_row[3], top_row[4], top_row[5], top_row[6],                top_row[7], top_row[8], top_row[9], top_row[10], top_row[11], top_row[12], top_row[13],
        //|--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------|
        mid_row[0], mid_row[1], mid_row[2], mid_row[3], mid_row[4], mid_row[5], mid_row[6],                mid_row[7], mid_row[8], mid_row[9], mid_row[10], mid_row[11], mid_row[12], mid_row[13],
        //|--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------|
        bot_row[0], bot_row[1], bot_row[2], bot_row[3], bot_row[4], bot_row[5],                                        bot_row[6], bot_row[7], bot_row[8], bot_row[9], bot_row[10], bot_row[11],
        //|--------+--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------+--------|
        thumb_row[0], thumb_row[1], thumb_row[2], thumb_row[3], thumb_row[4], thumb_row[5]
        //`--------------------------'  `--------------------------'
        ),
  [GAMING] = LAYOUT_split_3x6_3_ex2( // Gaming layer
    // Left Hand                                                                   // Right Hand
    BP_W, _______, _______, _______, _______, _______, BP_DCIR,              TD(D_4),  _______, _______, _______, _______, _______, _______,
    BP_CCED, BP_A,    BP_U,    BP_I,    BP_E,     _______, KC_ENTER,                      _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                     _______, _______, _______, _______, _______, _______,
    _______,    _______, _______, _______, _______,    _______
  ),
  [NUMPAD] = LAYOUT_split_3x6_3_ex2( // Numpad layer
    // Left Hand                                                                       // Right Hand
    DM_REC1,    DM_REC2,    DM_RSTP,   DM_PLY1,    DM_PLY2, XXXXXXX,   XXXXXXX,              QK_LLCK, KC_NUM, KC_KP_7, KC_KP_8, KC_KP_9, BP_EQL, BP_PERC,
    XXXXXXX,    KC_RALT,    KC_LALT,   KC_LCTL,    KC_LSFT, XXXXXXX,  XXXXXXX,                XXXXXXX, KC_PPLS, RSFT_T(KC_KP_4), RCTL_T(KC_KP_5), LALT_T(KC_KP_6), RALT_T(KC_PAST), BP_DLR,
    XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX, CMC_COLON, XXXXXXX,                              KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, BP_DOT, BP_COMM,
    XXXXXXX,   XXXXXXX , MO(CONFIG),                                                             XXXXXXX,     XXXXXXX,    KC_KP_0
  ),
  [FXARROWS] = LAYOUT_split_3x6_3_ex2( // Functions & Arrows layer
    // Left Hand                                                                       // Right Hand
    TD(D_F1_F13),   TD(D_F2_F14),   TD(D_F3_F15),   TD(D_F4_F16),XXXXXXX,    KC_MUTE,  TG(LOCK),                  XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_PGUP,    XXXXXXX,    XXXXXXX,
    TD(D_F5_F17),   TD(D_F6_F18),   TD(D_F7_F19),   TD(D_F8_F20),TD(D_COPY_CUT), KC_VOLU,  KC_CAPS,            XXXXXXX,    KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_DEL,     XXXXXXX,
    TD(D_F9_F21),   TD(D_F10_F22),  TD(D_F11_F23),  TD(D_F12_F24),LCTL(BP_V),    KC_VOLD,                       XXXXXXX,    KC_END,     XXXXXXX,    KC_PGDN,    XXXXXXX,    XXXXXXX,
    D_PREV_NEXT,    TD(D_PLAY_STOP), XXXXXXX,                                                                  MO(CONFIG), XXXXXXX,    KC_DEL
  ),
  [CONFIG] = LAYOUT_split_3x6_3_ex2( // CONFIG
    // Left Hand                                                                       // Right Hand
    QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    DB_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RM_VALU,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RM_VALD,                                      XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX
  ),
  [LOCK] = LAYOUT_split_3x6_3_ex2( // lock layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TD(D_UNLOCK),              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX
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
static hsv_t color_table[MAX_LEDS] = {[0 ... MAX_LEDS-1] = {HSV_BLACK}};

void set_key_color(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    color_table[index] = (hsv_t){h, s, v};
}

bool rgb_matrix_indicators_user() {
  // Sens des leds : début moitité gauche, espace 0, puis serpentin vers la gauche. Les deux touches supplémentaires sont 21 (haut) et 22 (bas).
  // ajouter 23 pour avoir la touche correspondante à droite

  // NOTE IMPORTANTE : suite à bug ou mauvaise conf du firmware, les leds de la moitié gauche sont mirrorées à droite. Il faut
  // donc les réinitialiser après avoir déclaré la moitié gauche

  // NOTE : il faut flasher les deux moitiés du clavier pour que les leds fonctionnent correctement
  
  for (int i = 0; i < MAX_LEDS; i++)
  {
    set_key_color(i, HSV_BLACK);
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
            case NUMPAD:
              set_key_color(27, HSV_GREEN); //numpad
              set_key_color(28, HSV_GREEN);
              set_key_color(29, HSV_GREEN);
              set_key_color(31, HSV_GREEN);
              set_key_color(32, HSV_GREEN);
              set_key_color(33, HSV_GREEN);
              set_key_color(34, HSV_GREEN);
              set_key_color(35, HSV_GREEN );
              set_key_color(36, HSV_GREEN);
              set_key_color(37, HSV_GREEN);
              set_key_color(26, HSV_RED ); //numlock
              
              set_key_color(44, HSV_PURPLE); // layer lock

              // macros
              set_key_color(18, HSV_RED);
              set_key_color(17, HSV_RED);
              set_key_color(12, HSV_ORANGE);
              set_key_color(11, HSV_GREEN);
              set_key_color(4, HSV_GREEN);
              break;
            case FXARROWS:
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

              // fn
              set_key_color(9, HSV_BLUE);
              set_key_color(10, HSV_BLUE);
              set_key_color(11, HSV_BLUE);
              set_key_color(12, HSV_BLUE);
              set_key_color(13, HSV_BLUE);
              set_key_color(14, HSV_BLUE);
              set_key_color(15, HSV_BLUE);
              set_key_color(16, HSV_BLUE);
              set_key_color(17, HSV_BLUE);
              set_key_color(18, HSV_BLUE);
              set_key_color(19, HSV_BLUE);
              set_key_color(20, HSV_BLUE);

              //copy paste
              set_key_color(5, HSV_CYAN);
              set_key_color(6, HSV_CYAN);              

              //media
              set_key_color(1, HSV_GREEN);
              set_key_color(2, HSV_GREEN);
              set_key_color(3, HSV_GREEN);
              set_key_color(7, HSV_GREEN);
              set_key_color(8, HSV_GREEN);

              set_key_color(22, HSV_RED); // caps lock
              break;
            case CONFIG:
               set_key_color(18, HSV_RED); // bootloader
               set_key_color(19, HSV_ORANGE); // debug

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
    hsv_t hsv = color_table[i];
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

void process_record_brtcst(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_brtcst(keycode, record);
  return true;
}
